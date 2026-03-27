---
title: 34 / Keymap Functions / Dead-Class Keys
manual: libraries
chapter: libraries
section: 34-keymap-functions-dead-class-keys
functions: []
libraries: []
---

# 34 / Keymap Functions / Dead-Class Keys

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All of the national keymaps, including USA, contain dead-class keys. This
term refers to keys that either modify or can themselves be modified by
other dead-class keys.  There are two types of dead-class keys: dead and
deadable.  A dead key is one which can modify certain keys pressed
immediately following.  For example, on the German keyboard there is a
dead key marked with the grave accent (`). The dead key produces no
console output, but when followed by (for instance) the A key, the
combination will produce the a-grave  (à) character (National Character
Code $E0).  On the U.S. keyboard, Alt-G is the deadkey used to add the
grave accent (`) to the next appropriate character typed. A deadable key
is one that can be prefixed by a dead key.  The A key in the previous
example is a deadable key.  Thus, a dead key can only affect the output of
a deadable key.

For any key that is to have a dead-class function, whether dead or
deadable, the qualifier [KCF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) flag must be included in the entry for
the key in the KeyMapTypes table.  The KCF_DEAD type may also be used in
conjunction with the other qualifiers.  Furthermore, the key's keymap
table entry must contain the longword address of the key's dead-key
descriptor data area in place of the usual 4 ASCII character mapping.

Below is an excerpt from the Amiga 1000 German key map which is referred
to in the following discussion.


```c
    KMLowMapType:
        DC.B    KCF_DEAD+KC_VANILLA     ; aA (Key 20)
                    ...                 ; (more...)
        DC.B    KCF_DEAD+KC_VANILLA     ; hH (Key 25)
                    ...                 ; (more...)
    KMLowMap:
        DC.L    key20                   ; a, A, ae, AE
                    ...                 ; (more...)
        DC.L    key25                   ; h, H, dead ^
                    ...                 ; (more...)
    ;------ possible dead keys
    key25:
        DC.B    0,'h',0,'H'             ; h, H
        DC.B    DPF_DEAD,3,DPF_DEAD,3   ; dead ^, dead ^
        DC.B    0,$08,0,$08,0,$88,0,$88 ; control translation
                    ...                 ; (more...)
    ;------ deadable keys (modified by dead keys)
    key20:              ; a, A, ae, AE
        DC.B    DPF_MOD,key20u-key20    ; deadable flag, number of
                                        ; bytes from start of key20
                                        ; descriptor to start of un-
                                        ; shifted data
        DC.B    DPF_MOD,key20s-key20    ; deadable flag, number of
                                        ; bytes from start of key20
                                        ; descriptor to start of shift-
                                        ; ed data
        DC.B    0,$E6,0,$C6             ; null flags followed by rest
        DC.B    0,$01,0,$01,0,$81,0,$81 ; of values (ALT, CTRL...)
    key20u:
        DC.B    'a',$E1,$E0,$E2,$E3,$E4 ; 'a' alone and characters to
                                        ; output when key alone is
                                        ; prefixed by a dead key
        DC.B    $E1,$E1,$E2,$E1,$E1,$E1 ; most recent is '
        DC.B    $E0,$E2,$E0,$E0,$E0,$E0 ; most recent is `
    key20s:
        DC.B    'A',$C1,$C0,$C2,$C3,$C4 ; SHIFTed 'a' and characters to
                                        ; output when SHIFTed key is
                                        ; prefixed by a dead key
        DC.B    $C1,$C1,$C2,$C1,$C1,$C1 ; most recent is '
        DC.B    $C0,$C2,$C0,$C0,$C0,$C0 ; most recent is `
```
In the example, key 25 (the H key) is a dead key and key 20 (the A key) is
a deadable key.  Both keys use the addresses of their descriptor data
areas as entries in the [LoKeyMap](libraries/34-details-of-the-keymap-structure-lokeymap-and-highkeymap.md) table.  The [LoKeyMapTypes](libraries/34-details-of-keymap-structure-lokeymaptypes-and.md) table says that
there are four qualifiers for both: the requisite [KCF_DEAD](autodocs-2.0/includes-devices-keymap-h.md), as well as
[KCF_SHIFT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), [KCF_ALT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), and [KCF_CONTROL](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md).  The number of qualifiers determine
length and arrangement of the descriptor data areas for each key.  The
next table shows how to interpret the KeyMapTypes for various combinations
of the qualifier bits.  For each possible position a pair of bytes is
needed.  The first byte in each pair tells how to interpret the second
byte (more about this below).




```c
                   Table 34-5: Dead Key Qualifier Bits
     _______________________________________________________________
    |                 |                                             |
    |                 | Then the pair of bytes in this position     |
    |                 | in the dead-class key descriptor data is    |
    | If type is:     | output when the key is pressed along with:  |
    |_________________|_____________________________________________|
    |                 |       |   |   |     |   |     |     |       |
    | NOQUAL          | alone | - | - |  -  | - |  -  |  -  |   -   |
    |-----------------|-------|---|---|-----|---|-----|-----|-------|
    | A               | alone | A | - |  -  | - |  -  |  -  |   -   |
    |-----------------|-------|---|---|-----|---|-----|-----|-------|
    | C               | alone | C | - |  -  | - |  -  |  -  |   -   |
    |-----------------|-------|---|---|-----|---|-----|-----|-------|
    | S               | alone | S | - |  -  | - |  -  |  -  |   -   |
    |-----------------|-------|---|---|-----|---|-----|-----|-------|
    | A+C             | alone | A | C | A+C | - |  -  |  -  |   -   |
    |-----------------|-------|---|---|-----|---|-----|-----|-------|
    | A+S             | alone | S | A | A+S | - |  -  |  -  |   -   |
    |-----------------|-------|---|---|-----|---|-----|-----|-------|
    | C+S             | alone | S | C | C+S | - |  -  |  -  |   -   |
    |-----------------|-------|---|---|-----|---|-----|-----|-------|
    | S+A+C (VANILLA) | alone | S | A | S+A | C | C+S | C+A | C+S+A |
    |_________________|_______|___|___|_____|___|_____|_____|_______|
    |                                                               |
    | The abbreviations A, C, S stand for [KCF_ALT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), [KCF_CONTROL](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), and |
    | [KCF_SHIFT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md), respectively.  Also note that the ordering is      |
    | reversed from that in the normal [KeyMap](libraries/34-keymap-functions-details-of-the-keymap-structure.md) table.                |
    |_______________________________________________________________|
```
Because keys 20 and 25 each use three qualifier bits (not including
[KCF_DEAD](autodocs-2.0/includes-devices-keymap-h.md)), according to the table there must be 8 pairs of data, arranged
as shown. Had only [KCF_ALT](libraries/34-details-of-the-keymap-structure-more-about-qualifiers.md) been set, for instance, (not including
KCF_DEAD), just two pairs would have been needed.

As mentioned earlier, the first byte of each data pair in the descriptor
data area specifies how to interpret the second byte.  There are three
possible values: 0, [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) and [DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md).  In the Amiga 1000 German keymap
listed above, DPF_DEAD appears in the data for key 25,  while DPF_MOD is
used for key 20.  It is the use of these flags that determines whether a
dead-class key has dead or deadable function.  A value of zero causes the
unrestricted output of the following byte.

If the flag byte is [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md), then that particular key combination
(determined by the placement of the pair of bytes in the data table) is
dead and will modify the output of the next key pressed (if deadable). How
it modifies is controlled by the second byte of the pair which is used as
an index into part(s) of the data area for ALL the deadable ([DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md) set)
keys.

Before going further, an understanding of the structure of a descriptor
data area wherein [DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md) is set for one (or more) of its members is
necessary. Referring to the example, we see that DPF_MOD is set for the
first and second pairs of bytes.  According to its [LoKeyMapTypes](libraries/34-details-of-keymap-structure-lokeymaptypes-and.md) entry,
and using table 34-5 (Dead Key Qualifier Bits) as a guide, these pairs
represent the alone and SHIFTed values for the key.  When DPF_MOD is set,
the byte immediately following the flag must be the offset from the start
of the key's descriptor data area to the start of a table of bytes
describing the characters to output when this key combination is preceded
by any dead keys.  This is where the index mentioned above comes in.  The
value of the index from a prefixing dead key is used to determine which of
the bytes from the deadable keys special table to output.  The byte in the
index+1 position is sent out.  (The very first byte is the value to output
if the key was not prefixed by a dead key.)  Thus, if Alt-H is pressed
(dead) and then Shift-A, an `a' with a circumflex (^) accent will be
output. This is because:


```c
    * The byte pair for the ALT position of the H key (key 25) is
      [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md),3 so the index is 3.

    * The byte pair for the SHIFT position of the A key (key 20) is
      [DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md), key20s-key20, so we refer to the table-of-bytes at
      key20s.

    * The third+1 byte of the table-of-bytes is $C2, an `a' character.

    A Note About Table Size.
    ------------------------
    The number of bytes in the table-of-bytes for all deadable keys
    must be equal to the highest index value of all dead keys plus 1.
```
