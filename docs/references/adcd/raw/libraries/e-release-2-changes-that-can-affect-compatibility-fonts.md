# E / Release 2 Changes That Can Affect Compatibility / Fonts


  * Some font format changes (old format supported).

  * Private format of .font files has changed (use FixFonts to create).

  * Default fonts may be larger, proportional.

  * Topaz is now sans-serif.

  * Any size font will be created via scaling as long as [TextAttr.Flags](../Libraries_Manual_guide/node03D6.html#line56)

```c
    [FPF_DESIGNED](../Libraries_Manual_guide/node03D6.html#line70) bit is not set.  If you were asking for an extreme size,
    like size 1 to get smallest available, or 999 to get largest
    available, you will get a big (or very very small) surprise now.
```
  * Do not use -1 for [TextAttr.Flags](../Libraries_Manual_guide/node03D6.html#line56) or [Styles](../Libraries_Manual_guide/node03D6.html#line47), nor as the flags for

```c
    [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) (one high bit now causes AvailFonts to return different
    structures).  Only set what you know you want.  A kludge has been
    added to the OS to protect applications which currently pass -1 for
    AvailFonts flags.
```
