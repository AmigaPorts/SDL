/* Source: ADCD 2.1
 * Section: parallel-device-cmd-read
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/parallel-device-cmd-read.md
 */

    This command causes a stream of characters to be read from the
    parallel I/O register. The number of characters is specified in
    io_Length. The EOF and EOL modes are supported, but be warned that
    using these modes can result in a buffer overflow if the proper
    EOL or EOF character is not received in time. These modes should
    be used only when the sender and receiver have been designed to
    cooperate. A safety guard can be implemented to EOF by setting
    io_Length to a maximum allowed value. That cannot be done with EOL
    since the EOL mode is identified by io_Length=-1.

    The parallel.device has no internal buffer; if no read request has
    been made, pending input (i.e. handshake request) is not
    acknowledged.
