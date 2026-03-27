---
title: 8 Narrator Device / A More Technical Explanation
manual: devices
chapter: devices
section: 8-narrator-device-a-more-technical-explanation
functions: []
libraries: []
---

# 8 Narrator Device / A More Technical Explanation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The narrator speech synthesizer is a computer model of the human speech
production process.  It attempts to produce accurately spoken utterances
of any English sentence, given only a phonetic representation as input.
Another program in the Amiga speech system, the translator device, derives
the required phonetic spelling from English text. Timing and pitch
contours are produced automatically by the synthesizer software.

In humans, the physical act of producing speech sounds begins in the
lungs.  To create a voiced sound, the lungs force air through the vocal
folds (commonly called the vocal cords), which are held under tension and
which periodically interrupt the flow of air, thus creating a buzz-like
sound.  This buzz, which has a spectrum rich in harmonics, then passes
through the vocal tract and out the lips and nose, which alters its
spectrum drastically.  This is because the vocal tract acts as a frequency
filter, selectively reinforcing some harmonics and suppressing others.  It
is this filtering that gives a speech sound its identity.  The amplitude
versus frequency graph of the filtering action is called the vocal tract
transfer function.  Changing the shape of the throat, tongue, and mouth
retunes the filter system to accentuate different frequencies.

The sound travels as a pressure wave through the air, and it causes the
listener's eardrum to vibrate.  The ear and brain of the listener decode
the incoming frequency pattern.  From this the listener can subconsciously
make a judgement about what physical actions were performed by the speaker
to make the sound.  Thus the speech chain is completed, the speaker having
encoded his physical actions on a buzz via selective filtering and the
listener having turned the sound into guesses about physical actions by
frequency decoding.


Now that we know how humans produce speech, how does the Amiga do it? It
turns out that the vocal tract transfer function is not random, but tends
to accentuate energy in narrow bands called formants.  The formant
positions move fairly smoothly as we speak, and it is the formant
frequencies to which our ears are sensitive.  So, luckily, we do not have
to model throat, tongue, teeth and lips with our computer, we can imitate
formant actions instead.

A good representation of speech requires up to five formants, but only the
lowest three are required for intelligibility.  The pre-V37 Narrator had
only three formants, while the V37 Narrator has five formants for a more
natural sounding voice.  We begin with an oscillator that produces a
waveform similar to that which is produced by the vocal folds, and we pass
it through a series of resonators, each tuned to a different formant
frequency.  By controlling the volume and pitch of the oscillator and the
frequencies of the resonators, we can produce highly intelligible and
natural-sounding speech.  Of course the better the model the better the
speech; but more importantly, experience has shown that the better the
control of the model's parameters, the better the speech.

Oscillators, volume controls, and resonators can all be simulated
mathematically in software, and it is by this method that the narrator
system operates.  The input phonetic string is converted into a series of
target values for the various parameters.  A system of rules then operates
on the string to determine things such as the duration of each phoneme and
the pitch contour.  Transitions between target values are created and
smoothed to produce natural, continuous changes from one sound to the next.

New values are computed for each parameter for every 8 milliseconds of
speech, which produces about 120 acoustic changes per second.  These
values drive a mathematical model of the speech synthesizer.  The accuracy
of this simulation is quite good.  Human speech has more formants that the
narrator model, but they are high in frequency and low in energy content.

The human speech production mechanism is a complex and wonderful thing.
The more we learn about it, the better we can make our computer
simulations.  Meanwhile, we can use synthetic speech as yet another
computer output device to enhance the man/machine dialogue.

