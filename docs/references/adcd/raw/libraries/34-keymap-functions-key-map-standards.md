# 34 / Keymap Functions / Key Map Standards


Users and programs depend on certain predictable behaviors from all
keyboards and keymaps. With the exception of dead-class keys (see
"[Dead-Class](../Libraries_Manual_guide/node0477.html) Keys" section), mapping of keys in the low key map should
follow these general rules:


```c
    * When pressed alone, keys should transmit the ASCII equivalent of
      the unshifted letter or lower symbol on the keycap.

    * When Shifted, keys should transmit the ASCII equivalent of the
      shifted letter or upper symbol printed on the keycap.

    * When Alt'ed, keys should generally transmit the same character
      (or act as the same [deadkey](../Libraries_Manual_guide/node0477.html)) as the Alt'ed key in the usa1
      keymap.

    * When pressed with CTRL alone, alphabetic keys should generally
      transmit their unshifted value but with bits 5 and 6 cleared.
      This allows keyboard typing of "control characters."  For
      example, the C key (normally value $63) should transmit value
      $03 (Ctrl-C) when Ctrl and C are pressed together.
```
The keys in the high key map (keys with raw key values $40 and higher) are
generally non-alphanumeric keys such as those used for editing (backspace,
delete, cursor keys, etc.), and special Amiga keys such as the function
and help keys. Keymaps should translate these keys to the same values or
strings as those shown in [table 34-6](../Libraries_Manual_guide/node0479.html#line11), ROM Default Key Mapping.

In addition to their normal unshifted and shifted values, the following
translations are standard for particular qualified high keymap keys:


```c
                   Generates     If Used with Qualifier,
        Key        This Value    Generates This Value
        ---        ----------    -----------------------
        Space         $20        $A0 with qualifier [KCF_ALT](../Libraries_Manual_guide/node0472.html)
        Return        $0D        $0A with qualifier [KCF_CONTROL](../Libraries_Manual_guide/node0472.html)
        Esc           $1B        $9B with qualifier [KCF_ALT](../Libraries_Manual_guide/node0472.html)
```
