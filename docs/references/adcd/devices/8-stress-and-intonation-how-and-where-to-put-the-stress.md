---
title: 8 / / Stress And Intonation / How and Where to Put the Stress Marks
manual: devices
chapter: devices
section: 8-stress-and-intonation-how-and-where-to-put-the-stress
functions: []
libraries: []
---

# 8 / / Stress And Intonation / How and Where to Put the Stress Marks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The stress marks go immediately to the right of vowel phoneme codes. The
word cat has its stress marked after the AE, e.g., KAE5T. You generally
have no choice about the location of a number; there is definitely a right
and wrong location.  A number should either go after a vowel or it should
not.  Narrator will not flag an error if you forget to put a stress mark
in or if you place it on the wrong vowel. It will only tell you if a
stress mark has been put after a non-vowel, i.e., consonant or punctuation.

The rules for placing stress marks are as follows:


   *  Always place a stress mark in a content  word.  A content word is one

      that contains some meaning.  Nouns, verbs, and adjectives are all
      content words, they tell the listener what you are talking about.
      Words like but, if, and the are not content words. They do not convey
      any real world meaning, but are required to make the sentence
      function, so they are given the name function words.
   *  Always place a stress mark on the accented syllable(s) of


```c
      polysyllabic words, whether they are content or function words.  A
      polysyllabic word is any word of more than one syllable.  Commodore
      has its stress (often called accent) on the first syllable and would
      be spelled KAA5MAXDOHR, while computer is stressed on the second
      syllable: KUMPYUW5TER.
```
If you are in doubt about which syllable gets the stress, look up the word
in a dictionary and you will find an accent mark over the stressed
syllable.  If more than one syllable in a word receives stress, they
usually are not of equal value.  These are referred to as primary and
secondary stresses.  The word understand has its first and last syllables
stressed, with the syllable stand getting the primary stress and the
syllable un getting the secondary stress. This produces the phonetic
representation AH1NDERSTAE4ND.  Syllables with secondary stress should be
marked with a value of only 1 or 2.

Compound words (words with more than one root) such as baseball, software,
and lunchwagon can be written as one word, but should be thought of as
separate words when marking stress.  Thus, lunchwagon would be spelled
LAH5NCHWAE2GIN.  Notice that the lunch got a higher stress mark than the
wagon.   This is common in compound words, the first word usually receives
the primary stress.

