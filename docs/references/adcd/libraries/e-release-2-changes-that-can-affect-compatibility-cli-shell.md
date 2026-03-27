---
title: E / Release 2 Changes That Can Affect Compatibility / CLI/Shell
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-cli-shell
functions: [Lock, Open]
libraries: [dos.library]
---

# E / Release 2 Changes That Can Affect Compatibility / CLI/Shell

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Many more commands are now built-in (no longer in C:).  This can

```c
    break installation scripts that copy C:commandname, and programs that
    try to [Lock()](autodocs-2.0/dos-library-lock.md) or [Open()](autodocs-2.0/dos-library-open.md) C:commandname to check for the command's
    existence.
```
  * The limit of 20 CLI processes is gone and the DOSBase CLI table has

    changed to accommodate this.  Under V36 and higher, you should use
    new 2.0 functions rather than accessing the CLI table directly.
  * Shell windows now have close gadgets.  The EOF character is passed

```c
    for the close gadget of a Shell.  This is -1L with CON: getchar(),
    and the Close Gadget raw event ESC seq with RAW:.
```
  * Shells now use the simple-refresh character-mapped console.

  * By default, CON: now opens [SIMPLE_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) windows using the V36/V37

```c
    console character mapped mode.  Because of some differences between
    character mapped consoles, and [SMART_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) non-mapped consoles,
    this may cause incompatibilities with some applications.  For
    example, the Amiga private sequences to set left/top offset, and set
    line/page length behave differently in character mapped console
    windows.  The only known work-around is to recompile asking for a
    CON: (or RAW:) window using the SMART flag.
```
  * Simple refresh/character mapped console windows now support

    highlighting and copying text with the mouse.  This feature, as well
    as pasting text should be transparent to programs which use CON: for
    console input, and output.  Pasted text will appear in your input
    stream as if the user had typed it.
  * While CONCLIP (see s:startup-sequence) is running, programs may

```c
    receive "<CSI>0 v" in their input stream indicating the user wants to
    paste text from the clipboard.  This shouldn't cause any problems for
    programs which parse correctly (however we know that it does; the
    most common problems are outputting the sequence, or confusing it
    with another sequence like that for FKEY 1 which is "<CSI>0~").
```
  * The console.device now renders a ghosted cursor in inactive console

```c
    windows (both [SMART_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md), and [SIMPLE_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) with character maps).
    Therefore, rendering over the console's cursor with graphics.library
    calls can trash the cursor; if you must do this, first turn off the
    cursor.
```
  * Some degree of unofficial support has been put in for programs which

```c
    use [SMART_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) console windows, and use graphics.library calls
    mixed with console.device sequences to scroll, draw text, clear, etc.
    This is not supported in [SIMPLE_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) windows with character maps,
    and is strongly discouraged in all cases.
```
  * Closing an Intuition window before closing the attached

    console.device will now crash or hang the machine.
  * Under 1.2 and 1.3, vacated portions of a console window (e.g., areas

```c
    vacated because of a clear, or a scroll) were filled in with the
    character cell color.  As of V36 this is no longer true, vacated
    areas are filled in with the global background color which can be set
    using the SGR sequence "<ESC>[>##m" where ## is a value between 0-7.
    In order to set the background color under Release 2, send the SGR to
    set background color, and a form feed to clear the screen.
```
  * Note that [SIMPLE_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) character mapped consoles are immediately

```c
    redrawn with the global background color when changed--this is not
    possible with [SMART_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) windows.
```

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
