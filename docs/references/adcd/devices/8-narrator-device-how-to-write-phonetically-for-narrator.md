---
title: 8 Narrator Device / How to Write Phonetically for Narrator
manual: devices
chapter: devices
section: 8-narrator-device-how-to-write-phonetically-for-narrator
functions: []
libraries: []
---

# 8 Narrator Device / How to Write Phonetically for Narrator

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section describes in detail the procedure used to specify phonetic
strings to the narrator speech synthesizer. No previous experience with
phonetics is required. The only thing you may need is a good pronunciation
dictionary for those times when you doubt your own ears. You do not have
to learn a foreign language or computer language. You are just going to
learn how to write down the English that comes out of your own mouth. In
writing phonetically you do not have to know how a word is spelled, just
how it is said.

                            TABLE OF PHONEMES

                                  Vowels

          Phoneme      Example              Phoneme     Example
          -------      -------              -------     --------
          IY           beet, eat            IH          bit, in
          EH           bet, end             AE          bat, ad
          AA           bottle, on           AH          but, up
          AO           ball, awl            UH          book, soot
          ER           bird, early          OH          border
          AX*          about, calibrate     IX*         solid, infinite

         * AX and IX should never be used in stressed syllables.


                                Diphthongs

          Phoneme      Example              Phoneme     Example
	  -------      -------		    -------     --------
          EY           bay,aid              AY          bide,I
          OY           boy,oil              AW          bound,owl
          OW           boat,own             UW          brew,boolean


                                Consonants

          Phoneme      Example              Phoneme    Example
	  -------      -------   	    -------    -------

```c
          R            red                  L           long
          W            wag                  Y           yellow,comp(Y)uter
          M            men                  N           no
          NX           sing                 SH          shy
          S            soon                 TH          thin
          F            fed                  ZH          pleasure
          Z            has,zoo              DH          then
          V            very                 WH          when
          CH           check                J           judge
          /H           hole                 /C          loch
          B            but                  P           put
          D            dog                  T           toy
          K            keg,copy             G           guest


                             Special Symbol

          Phoneme               Example             Explanation
          -------               -------             -----------
          DX                    pity                tongue flap
          Q                     kitt(Q)en           glottal stop
          QX                                        silent vowel


                         Contractions (see text)

                               UL = AXL
                               IL = IXL
                               UM = AXM
                               IM = IXM
                               UN = AXN
                               IN = IXN


                          Digits and Punctuation

    Digits 1-9    Syllabic stress, ranging from secondary through emphatic
    .             Period - sentence final character.
    ?             Question mark - sentence final character
    -             Dash - phrase delimiter
    ,             Comma - clause delimiter
    ()            Parentheses - noun phrase delimiters (see text)
```
The narrator device  works on utterances at the sentence level.  Even if
you want to say only one word, it will treat it as a complete sentence.
Therefore, narrator wants one of two punctuation marks to appear at the
end of every sentence - a period or a question mark.  The period is used
for almost all utterances and will cause a final fall in pitch to occur at
the end of a sentence.  The question mark is used at the end of yes/no
questions only, and results in a final rise in pitch.

For example, the question, Do you enjoy using your Amiga? would take a
question mark at the end, while the question, What is your favorite color?
should be followed (in the phonetic transcription) with a period.  If no
punctuation appears at the end of a string, narrator will append a dash to
it, which will result in a short pause.  Narrator recognizes other
punctuation marks as well, but these are left for later discussion.

 [Phonetic Spelling](devices/8-how-to-write-phonetically-for-narrator-phonetic-spelling.md) 	      [Hints For Intelligibility](devices/8-how-to-write-phonetically-hints-for-intelligibility.md) 
 [Stress And Intonation](devices/8-how-to-write-phonetically-for-narrator-stress-and.md)        [Example Of English And Phonetic Texts](devices/8-writing-phonetically-english-and-phonetic-text-example.md) 
 [Punctuation](devices/8-how-to-write-phonetically-for-narrator-punctuation.md) 		      [Concluding Remarks](devices/8-how-to-write-phonetically-for-narrator-concluding-remarks.md) 

