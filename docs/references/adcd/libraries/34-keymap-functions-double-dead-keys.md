---
title: 34 / Keymap Functions / Double-Dead Keys
manual: libraries
chapter: libraries
section: 34-keymap-functions-double-dead-keys
functions: []
libraries: []
---

# 34 / Keymap Functions / Double-Dead Keys

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Double-dead keys are an extension of the [dead-class keys](libraries/34-keymap-functions-dead-class-keys.md) explained above.
Unlike normal dead keys wherein one dead key of type [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) can modify a
second of type [DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md), double-dead keys employ two consecutive keys of
type DPF_DEAD to together modify a third of type DPF_MOD.

For example, the key on the German keyboard labeled with single quotes (
`' ) is a double-dead key.  When this key is pressed alone and then
pressed again shifted, there is no output.  But when followed by an
appropriate third key, for example the A key, the three keypresses combine
to produce an `a' with a circumflex (^) accent (character code $E2). Thus
the double-dead pair qualify the output of the A key.

The system always keeps the last two down key codes for possible further
translation.  If they are both of type [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) and the key immediately
following is [DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md) then the two are used to form an index into the
(third) key's translation table as follows:

In addition to the index found after the [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) qualifier in a normal
dead key, a second factor is included in the high nibble of double-dead
keys (it is shifted into place with DP_2DFACSHIFT).  Its value equals the
total number of dead key types + 1 in the keymap.  This second index also
serves as an identifying flag to the system that two dead keys can be
significant.

When a key of type [DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md) is pressed, the system checks the two key codes
which preceded the current one.  If they were both [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) then the most
recent of the two is checked for the double-dead index/flag.  If it is
found then a new index is formed by multiplying the value in lower nibble
with that in the upper.  Then, the lower nibble of the least recent
DPF_DEAD key is added in to form the final offset.

Finally, this last value is used as an index into the translation table of
the current, [DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md), key.

The translation table of all deadable ([DPF_MOD](autodocs-2.0/includes-devices-keymap-h.md)) keys has [number of dead
key types + 1] * [number of double dead key types + 1] entries, arranged
in [number of double dead key types + 1] rows of [number of dead key types
+ 1] entries. This is because as indices are assigned for dead keys in the
keymap, those that are double dead keys are assigned the lower numbers.

Following is a code fragment from the German (d) keymap source:


```c
    key0C:
        DC.B    DPF_DEAD,1+(6<<DP_2DFACSHIFT)   ; dead '
        DC.B    DPF_DEAD,2+(6<<DP_2DFACSHIFT)   ; dead `
        DC.B    0,'=',0,'+'                     ; =, +
    key20:                  ; a, A, ae, AE
        DC.B    DPF_MOD,key20u-key20,DPF_MOD,key20s-key20
        DC.B    0,$E6,0,$C6
        DC.B    0,$01,0,$01,0,$81,0,$81 ; control translation
    key20u:
        DC.B    'a',$E1,$E0,$E2,$E3,$E4
        DC.B    $E1,$E1,$E2,$E1,$E1,$E1 ; most recent is '
        DC.B    $E0,$E2,$E0,$E0,$E0,$E0 ; most recent is `
    key20s:
        DC.B    'A',$C1,$C0,$C2,$C3,$C4
        DC.B    $C1,$C1,$C2,$C1,$C1,$C1 ; most recent is '
        DC.B    $C0,$C2,$C0,$C0,$C0,$C0 ; most recent is `
```
Raw key0C, the German single quotes ( `' ) key, is a double dead key.
Pressing this key alone, then again while the shift key is down will
produce no output but will form a double-dead qualifier. The output of
key20 (A), a deadable key, will consequently be modified, producing an "a"
with a circumflex (^) accent. The mechanics are as follows:

  * When key0C is pressed alone the [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) of the first byte pair in

    the key's table indicates that the key as dead. The second byte is
    then held by the system.
  * Next, when key0C is pressed again, this time with the Shift key down,

```c
    the [DPF_DEAD](autodocs-2.0/includes-devices-keymap-h.md) of the second byte pair (recall that the second pair is
    used because of the SHIFT qualifier) again indicates the key is a
    dead key.  The second byte of this pair is also held by the system.
```
  * Finally, when the A key is pressed the system recalls the latter of

```c
    the two bytes it has saved. The upper nibble, $6, is multiplied by
    the lower nibble, $2. The result, $0C, is then added to the lower
    nibble of the earlier of the two saved bytes, $1. This new value,
    $0D, is used as an index into the (unshifted) translation table of
    key20. The character at position $0D is character $E2, an `a' with a
    circumflex (^) accent.

    Note About Double Dead Keys.
    ----------------------------
    If only one double-dead key is pressed before a deadable key then the
    output is the same as if the double-dead were a normal dead key. If
    shifted key0C is pressed on the German keyboard and then immediately
    followed by key20, the output produced is character $E0, ` à '.  As
    before, the upper nibble is multiplied with the lower, resulting in
    $0C. But because there was no second dead-key, this product is used
    as the final index.
```
