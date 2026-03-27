---
title: 34 / / Details Of the Keymap Structure / More About Qualifiers
manual: libraries
chapter: libraries
section: 34-details-of-the-keymap-structure-more-about-qualifiers
functions: []
libraries: []
---

# 34 / / Details Of the Keymap Structure / More About Qualifiers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For keys such as the Return key or Esc key, the qualifiers specified in
the keytypes table (up to two) are the qualifiers used to establish the
response to the key.  This is done as follows.  In the keytypes table, the
values listed for the key types are those listed for the qualifiers in
<devices/[keymap.h](autodocs-2.0/includes-devices-keymap-h.md)> and <devices/[keymap.i](autodocs-2.0/includes-devices-keymap-i.md)>. Specifically, these qualifier
equates are:


                    KC_NOQUAL    0x00
                    KCF_SHIFT    0x01
                    KCF_ALT      0x02
                    KCF_CONTROL  0x04
                    KC_VANILLA   0x07
                    KCF_DOWNUP   0x08
                    KCF_STRING   0x40
As shown above, the qualifiers for the various types of keys occupy
specific bit positions in the key types control byte. As you may have
noticed, there are three possible qualifiers, but only a 4-byte space in
the table for each key. This does not allow space to describe what the
computer should output for all possible combinations of qualifiers. A
solution exists, however, for "vanilla" keys, such as the alphabetic keys.
Here is how that works.

Keys of type KC_VANILLA use the 4 bytes to represent the data output for
the key alone, Shifted key, Alt'ed key, and Shifted-and-Alt'ed key. Then
for the Ctrl-key-plus-vanilla-key, use the code for the key alone with
bits 6 and 5 set to 0.


    The Vanilla Qualifier Does Not Mean Plain.
    ------------------------------------------
    The qualifier KC_VANILLA is equivalent to
    KCF_SHIFT+KCF_ALT+KCF_CONTROL.
This table shows how to interpret the keymap for various combinations of
the qualifier bits:



                    Table 34-4: Keymap Qualifier Bits


                           Then data at this position in the keytable is
    If Keytype is:         output when the key is pressed along with:
    --------------         ---------------------------------------------
    KC_NOQUAL                    -           -     -      alone
    KCF_SHIFT                    -           -     Shift  alone
    KCF_ALT                      -           -     Alt    alone
    KCF_CONTROL                  -           -     Ctrl   alone
    KCF_ALT+KCF_SHIFT            Shift+Alt   Alt   Shift  alone
    KCF_CONTROL+KCF_ALT          Ctrl+Alt    Ctrl  Alt    alone
    KCF_CONTROL+KCF_SHIFT        Ctrl+Shift  Ctrl  Shift  alone
    KC_VANILLA                   Shift+Alt   Alt   Shift  alone*

    *Special case--Ctrl key, when pressed with one of the alphabet keys
    and certain others, is to output key-alone value with the bits 6 and
    5 set to zero.
