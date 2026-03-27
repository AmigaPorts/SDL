# 34 / / Details Of Keymap Structure / LoKeyMapTypes and HiKeyMapTypes


The tables named [km_LoKeyMapTypes](../Libraries_Manual_guide/node046F.html) and [km_HiKeyMapTypes](../Libraries_Manual_guide/node046F.html) each contain one
byte per raw key code. Each byte defines the type of entry that is found
in the keymap table for that raw key code.

Possible key types are:


```c
    * Any of the qualifier groupings [noted below](../Libraries_Manual_guide/node0472.html)

    * [KCF_STRING](../Libraries_Manual_guide/node0472.html) + any combination of [KCF_SHIFT](../Libraries_Manual_guide/node0472.html), [KCF_ALT](../Libraries_Manual_guide/node0472.html), [KCF_CONTROL](../Libraries_Manual_guide/node0472.html)
      (or [KC_NOQUAL](../Libraries_Manual_guide/node0472.html)) if the result of pressing the key is to be a
      stream of bytes (and key-with-one-or-more-qualifiers is to be
      one or more alternate streams of bytes).

      Any key can be made to output up to eight unique byte streams if
      [KCF_STRING](../Libraries_Manual_guide/node0472.html) is set in its keytype. The only limitation is that
      the total length of all of the strings assigned to a key must be
      within the "jump range" of a single byte increment. See the
      "[String Output Keys](../Libraries_Manual_guide/node0473.html)" section below for more information.

    * [KCF_DEAD](../Libraries_Manual_guide/node0477.html#line14) + any combination of [KCF_SHIFT](../Libraries_Manual_guide/node0472.html), [KCF_ALT](../Libraries_Manual_guide/node0472.html), [KCF_CONTROL](../Libraries_Manual_guide/node0472.html)
      (or [KC_NOQUAL](../Libraries_Manual_guide/node0472.html)) if the key is a dead-class key and can thus
      modify or be modified by another dead-class key. See the
      "[Dead-Class Keys](../Libraries_Manual_guide/node0477.html)" section below for more information.
```
The low keytype table covers the raw key codes from hex 00-3F and contains
one byte per key code. Therefore this table contains 64 (decimal) bytes.
The high keytype table covers the raw key codes from hex 40-7F and
contains 64 (decimal) bytes.

