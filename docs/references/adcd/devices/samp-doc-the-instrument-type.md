---
title: SAMP.doc / The Instrument Type
manual: devices
chapter: devices
section: samp-doc-the-instrument-type
functions: []
libraries: []
---

# SAMP.doc / The Instrument Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Many SMUS players search for certain instruments by name.  Not only is
this slow (comparing strings), but if the exact name can't be found, then
it is very difficult and time-consuming to search for a suitable
replacement.  For this reason, many SMUS players resort to "default"
instruments even if these are nothing like the desired instruments. The
InsType byte in each waveHeader is meant to be a numeric code which will
tell an SMUS player exactly what the instrument is.  In this way, the SMUS
player can search for the correct "type" of instrument if it can't find
the desired name. The type byte is divided into 2 nibbles (4 bits for you
C programmers) with the low 4 bits representing the instrument "family" as
follows:

  1 = STRING, 2 = WOODWIND, 3 = KEYBOARD, 4 = GUITAR, 5 = VOICE,
  6 = DRUM1, 7 = DRUM2,  8 = PERCUSSION1, 9 = BRASS1, A = BRASS2,
  B = CYMBAL, C = EFFECT1, D = EFFECT2, E = SYNTH,
  F is undefined at this time

Now, the high nibble describes the particular type within that family.

For the STRING family, the high nibble is as follows:

  1 = VIOLIN BOW, 2 = VIOLIN PLUCK, 3 = VIOLIN GLISSANDO,
  4 = VIOLIN TREMULO, 5 = VIOLA BOW, 6 = VIOLA PLUCK, 7 = VIOLA GLIS,
  8 = VIOLA TREM, 9 = CELLO BOW, A = CELLO PLUCK, B = CELLO GLIS,
  C = CELLO TREM, D = BASS BOW, E = BASS PLUCK (jazz bass), F = BASS TREM

For the BRASS1 family, the high nibble is as follows:

  1 = BARITONE SAX, 2 = BARI GROWL, 3 = TENOR SAX, 4 = TENOR GROWL,
  5 = ALTO SAX, 6 = ALTO GROWL, 7 = SOPRANO SAX, 8 = SOPRANO GROWL,
  9 = TRUMPET, A = MUTED TRUMPET, B = TRUMPET DROP, C = TROMBONE,
  D = TROMBONE SLIDE, E = TROMBONE MUTE

For the BRASS2 family, the high nibble is as follows:

  1 = FRENCH HORN, 2 = TUBA, 3 = FLUGAL HORN, 4 = ENGLISH HORN

For the WOODWIND family, the high nibble is as follows:

  1 = CLARINET, 2 = FLUTE, 3 = PAN FLUTE, 4 = OBOE, 5 = PICCOLO,
  6 = RECORDER, 7 = BASSOON, 8 = BASS CLARINET, 9 = HARMONICA

For the KEYBOARD family, the high nibble is as follows:

  1 = GRAND PIANO, 2 = ELEC. PIANO, 3 = HONKYTONK PIANO, 4 = TOY PIANO,
  5 = HARPSICHORD, 6 = CLAVINET, 7 = PIPE ORGAN, 8 = HAMMOND B-3,
  9 = FARFISA ORGAN, A = HARP

For the DRUM1 family, the high nibble is as follows:

  1 = KICK, 2 = SNARE, 3 = TOM, 4 = TIMBALES, 5 = CONGA HIT,
  6 = CONGA SLAP, 7 = BRUSH SNARE, 8 = ELEC SNARE, 9 = ELEC KICK,
  A = ELEC TOM, B = RIMSHOT, C = CROSS STICK, D = BONGO, E = STEEL DRUM,
  F = DOUBLE TOM

For the DRUM2 family, the high nibble is as follows:

  1 = TIMPANI, 2 = TIMPANI ROLL, 3 = LOG DRUM

For the PERCUSSION1 family, the high nibble is as follows:

  1 = BLOCK, 2 = COWBELL, 3 = TRIANGLE, 4 = TAMBOURINE, 5 = WHISTLE,
  6 = MARACAS, 7 = BELL, 8 = VIBES, 9 = MARIMBA, A = XYLOPHONE,
  B = TUBULAR BELLS, C = GLOCKENSPEIL

For the CYMBAL family, the high nibble is as follows:

  1 = CLOSED HIHAT, 2 = OPEN HIHAT, 3 = STEP HIHAT, 4 = RIDE,
  5 = BELL CYMBAL, 6 = CRASH, 7 = CHOKE CRASH, 8 = GONG, 9 = BELL TREE,
  A = CYMBAL ROLL

 For the GUITAR family, the high nibble is as follows:

  1 = ELECTRIC, 2 = MUTED ELECTRIC, 3 = DISTORTED, 4 = ACOUSTIC,
  5 = 12-STRING, 6 = NYLON STRING, 7 = POWER CHORD, 8 = HARMONICS,
  9 = CHORD STRUM, A = BANJO, B = ELEC. BASS, C = SLAPPED BASS,
  D = POPPED BASS, E = SITAR, F = MANDOLIN
  (Note that an acoustic picked bass is found in the STRINGS - Bass Pluck)

For the VOICE family, the high nibble is as follows:

  1 = MALE AHH, 2 = FEMALE AHH, 3 = MALE OOO, 4 = FEMALE OOO,
  5 = FEMALE BREATHY, 6 = LAUGH, 7 = WHISTLE

For the EFFECTS1 family, the high nibble is as follows:

  1 = EXPLOSION, 2 = GUNSHOT, 3 = CREAKING DOOR OPEN, 4 = DOOR SLAM,
  5 = DOOR CLOSE, 6 = SPACEGUN, 7 = JET ENGINE, 8 = PROPELLER,
  9 = HELOCOPTER, A = BROKEN GLASS, B = THUNDER, C = RAIN, D = BIRDS,
  E = JUNGLE NOISES, F = FOOTSTEP

For the EFFECTS2 family, the high nibble is as follows:

  1 = MACHINE GUN, 2 = TELEPHONE, 3 = DOG BARK, 4 = DOG GROWL,
  5 = BOAT WHISTLE, 6 = OCEAN, 7 = WIND, 8 = CROWD BOOS, 9 = APPLAUSE,
  A = ROARING CROWDS, B = SCREAM, C = SWORD CLASH, D = AVALANCE,
  E = BOUNCING BALL, F = BALL AGAINST BAT OR CLUB

For the SYNTH family, the high nibble is as follows:

  1 = STRINGS, 2 = SQUARE, 3 = SAWTOOTH, 4 = TRIANGLE, 5 = SINE, 6 = NOISE

So, for example if a wave's type byte was 0x26, this would be a SNARE
DRUM. If a wave's type byte is 0, then this means "UNKNOWN" instrument.

