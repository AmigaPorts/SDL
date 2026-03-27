#!/usr/bin/env python3
"""serial-capture.py — Capture Amiga Enforcer serial output via TCP.

FS-UAE listens on a TCP port for serial connections when configured with:
    serial_port = tcp://127.0.0.1:PORT/wait

This script connects to that port as a TCP client and streams all received
serial data (Enforcer hits, Mungwall output) to a log file.

# Lifecycle:
#   connect(host:port) → stream to file → EOF → exit

Usage:
    python3 scripts/serial-capture.py <host:port> <log-file> [--ready-file FILE]

Arguments:
    host:port    FS-UAE serial TCP address (e.g., 127.0.0.1:1234)
    log-file     Path to write captured serial data (e.g., enforcer.log)
    --ready-file Write this file after successful connection (signals caller)

Exit codes:
    0   Clean shutdown (connection closed by FS-UAE)
    1   Usage error or fatal failure
    2   Connection timeout (could not connect within timeout)
"""

import os
import signal
import socket
import sys
import time

# -- Constants ---------------------------------------------------------------

CONNECT_TIMEOUT_SECS = 60  # FS-UAE may take time to boot and listen
CONNECT_RETRY_INTERVAL = 0.5  # Retry every 500ms
RECV_BUFFER_SIZE = 4096

# -- Global state for signal handler cleanup ---------------------------------

_sock = None
_log_fp = None
_ready_path = None


def _cleanup(signum=None, frame=None):
    """Close socket, flush and close log, then exit."""
    if _sock:
        try:
            _sock.close()
        except OSError:
            pass
    if _log_fp and not _log_fp.closed:
        try:
            _log_fp.flush()
            _log_fp.close()
        except OSError:
            pass
    if signum is not None:
        sys.exit(1)


def main():
    global _sock, _log_fp, _ready_path

    # Parse arguments
    ready_file = None
    args = sys.argv[1:]
    filtered = []
    i = 0
    while i < len(args):
        if args[i] == "--ready-file" and i + 1 < len(args):
            ready_file = args[i + 1]
            i += 2
        else:
            filtered.append(args[i])
            i += 1

    if len(filtered) != 2:
        print(
            "Usage: serial-capture.py <host:port> <log-file> [--ready-file FILE]",
            file=sys.stderr,
        )
        sys.exit(1)

    host_port = filtered[0]
    log_path = filtered[1]
    _ready_path = ready_file

    # Parse host:port
    try:
        host, port_str = host_port.rsplit(":", 1)
        port = int(port_str)
    except (ValueError, IndexError):
        print(
            f"serial-capture: invalid host:port '{host_port}'",
            file=sys.stderr,
        )
        sys.exit(1)

    # Install signal handlers for graceful shutdown
    signal.signal(signal.SIGTERM, _cleanup)
    signal.signal(signal.SIGINT, _cleanup)

    # -- Connect to FS-UAE's serial TCP port (retry loop) --------------------
    # FS-UAE starts listening on the port, then blocks boot with /wait until
    # we connect. We retry because FS-UAE may not have started listening yet.
    _sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    deadline = time.monotonic() + CONNECT_TIMEOUT_SECS
    connected = False

    while time.monotonic() < deadline:
        try:
            _sock.connect((host, port))
            connected = True
            break
        except ConnectionRefusedError:
            time.sleep(CONNECT_RETRY_INTERVAL)
        except OSError as e:
            # Socket may be in bad state after failed connect, recreate
            try:
                _sock.close()
            except OSError:
                pass
            _sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            time.sleep(CONNECT_RETRY_INTERVAL)

    if not connected:
        print(
            f"serial-capture: could not connect to {host}:{port} within "
            f"{CONNECT_TIMEOUT_SECS}s",
            file=sys.stderr,
        )
        _cleanup()
        sys.exit(2)

    print(
        f"serial-capture: connected to {host}:{port}",
        file=sys.stderr,
    )

    # -- Write ready file to signal caller -----------------------------------
    if _ready_path:
        try:
            tmp = _ready_path + ".tmp"
            with open(tmp, "w") as f:
                f.write("connected")
            os.rename(tmp, _ready_path)
        except OSError as e:
            print(
                f"serial-capture: failed to write ready file: {e}",
                file=sys.stderr,
            )

    # -- Open log file -------------------------------------------------------
    try:
        _log_fp = open(log_path, "wb")
    except OSError as e:
        print(
            f"serial-capture: failed to open log file: {e}",
            file=sys.stderr,
        )
        _cleanup()
        sys.exit(1)

    # -- Stream data until EOF -----------------------------------------------
    try:
        while True:
            data = _sock.recv(RECV_BUFFER_SIZE)
            if not data:
                break
            try:
                _log_fp.write(data)
                _log_fp.flush()
            except OSError as e:
                print(
                    f"serial-capture: log write error: {e}",
                    file=sys.stderr,
                )
                break
    except ConnectionResetError:
        # FS-UAE closed the connection abruptly — not an error
        pass
    except OSError as e:
        print(
            f"serial-capture: recv error: {e}",
            file=sys.stderr,
        )

    # -- Clean shutdown ------------------------------------------------------
    _cleanup()
    print("serial-capture: done", file=sys.stderr)
    sys.exit(0)


if __name__ == "__main__":
    main()
