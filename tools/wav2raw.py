#!/usr/bin/env python3
"""Convert a WAV file to headerless signed 8-bit mono PCM.

That is the format the AmigaOS 3 audio path wants: AUDIO_S8, one
channel. Paula is an 8-bit signed DMA device, so anything else costs a
conversion pass at runtime.

Usage:
    python tools/wav2raw.py in.wav out.raw [--rate N]

Without --rate the source rate is kept, which is almost always what you
want -- resampling invents samples and gains nothing. Pass --rate only
when the source rate is one the target cannot play.

Prints the AudioSpec the result needs, so it can be copied straight into
the calling program.

Part of SDL2.Library-Amiga-m68K. Copyright (c) 2026 JennaScvl.
This software is provided 'as-is', without any express or implied
warranty. See LICENCE.MD (zlib License) for the full terms.
"""
import argparse
import struct
import sys
import wave


def read_frames(path):
    """Return (samples, rate) with samples as a list of floats in
    [-1, 1), already mixed down to mono."""
    w = wave.open(path, 'rb')
    try:
        if w.getcomptype() != 'NONE':
            sys.exit('%s is compressed (%s); only PCM is supported'
                     % (path, w.getcompname()))
        ch, width, rate, n = (w.getnchannels(), w.getsampwidth(),
                              w.getframerate(), w.getnframes())
        raw = w.readframes(n)
    finally:
        w.close()

    if width == 1:
        # 8-bit WAV is UNSIGNED by definition -- centre it.
        vals = [(b - 128) / 128.0 for b in raw]
    elif width == 2:
        vals = [v / 32768.0
                for v in struct.unpack('<%dh' % (len(raw) // 2), raw)]
    elif width == 4:
        vals = [v / 2147483648.0
                for v in struct.unpack('<%di' % (len(raw) // 4), raw)]
    else:
        sys.exit('unsupported sample width: %d bytes' % width)

    if ch > 1:
        # Average the channels rather than dropping one, so nothing
        # panned hard to one side disappears.
        mono = [sum(vals[i:i + ch]) / ch for i in range(0, len(vals), ch)]
    else:
        mono = vals
    return mono, rate, ch, width


def resample(samples, src_rate, dst_rate):
    """Linear interpolation. Good enough for sound effects; this is not
    a mastering tool."""
    if src_rate == dst_rate:
        return samples
    n = int(len(samples) * dst_rate / float(src_rate))
    step = (len(samples) - 1) / float(n - 1) if n > 1 else 0.0
    out = []
    for i in range(n):
        pos = i * step
        j = int(pos)
        frac = pos - j
        a = samples[j]
        b = samples[j + 1] if j + 1 < len(samples) else a
        out.append(a + (b - a) * frac)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('infile')
    ap.add_argument('outfile')
    ap.add_argument('--rate', type=int, default=None,
                    help='resample to this rate (default: keep source rate)')
    args = ap.parse_args()

    mono, rate, ch, width = read_frames(args.infile)
    print('in : %s -- %d Hz, %d channel(s), %d-bit, %.2f s'
          % (args.infile, rate, ch, width * 8, len(mono) / float(rate)))

    out_rate = args.rate or rate
    if out_rate != rate:
        mono = resample(mono, rate, out_rate)
        print('     resampled %d -> %d Hz' % (rate, out_rate))

    # Float to signed 8-bit, clamped. 127 not 128, so +1.0 does not wrap
    # to -128.
    data = bytearray()
    clipped = 0
    for s in mono:
        v = int(round(s * 127.0))
        if v > 127:
            v, clipped = 127, clipped + 1
        elif v < -128:
            v, clipped = -128, clipped + 1
        data.append(v & 0xFF)

    open(args.outfile, 'wb').write(bytes(data))
    print('out: %s -- %d bytes, signed 8-bit mono @ %d Hz, %.2f s'
          % (args.outfile, len(data), out_rate, len(data) / float(out_rate)))
    if clipped:
        print('     %d samples clipped' % clipped)
    print()
    print('SDL_AudioSpec for this file:')
    print('    want.freq     = %d;' % out_rate)
    print('    want.format   = AUDIO_S8;')
    print('    want.channels = 1;')


if __name__ == '__main__':
    main()
