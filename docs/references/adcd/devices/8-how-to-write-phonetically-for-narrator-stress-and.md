---
title: 8 / How to Write Phonetically for Narrator / Stress And Intonation
manual: devices
chapter: devices
section: 8-how-to-write-phonetically-for-narrator-stress-and
functions: []
libraries: []
---

# 8 / How to Write Phonetically for Narrator / Stress And Intonation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It is not enough to tell narrator what you want said.  For the best
results you must also tell narrator how you want it said.  In this way you
can alter a sentence's meaning, stress important words, and specify the
proper accents in polysyllabic words.  These things improve the
naturalness and thus the intelligibility of the spoken output.

Stress and intonation are specified by the single digits 1-9 following a
vowel phoneme code.  Stress and intonation are two different things, but
are specified by a single number.

Stress is, among other things, the elongation of a syllable.  A syllable
is either stressed or not, so the presence of a number after the vowel in
a syllable indicates stress on that syllable.  The value of the number
indicates the intonation. These numbers are referred to here as stress
marks  but keep in mind that they also affect intonation.

Intonation here means the pitch pattern or contour of an utterance. The
higher the stress mark, the higher the potential for an accent in pitch.
A sentence's basic contour is comprised of a quickly rising pitch gesture
up to the first stressed syllable in the sentence, followed by a slowly
declining tone throughout the sentence, and finally, a quick fall to a low
pitch on the last syllable.  The presence of additional stressed syllables
causes the pitch to break its slow, declining pattern with rises and falls
around each stressed syllable.  Narrator uses a very sophisticated
procedure to generate natural pitch contours based on how you mark the
stressed syllables.

 [How and Where to Put the Stress Marks](devices/8-stress-and-intonation-how-and-where-to-put-the-stress.md) 
 [Which Stress Value Do I Use?](devices/8-stress-and-intonation-which-stress-value-do-i-use.md) 

