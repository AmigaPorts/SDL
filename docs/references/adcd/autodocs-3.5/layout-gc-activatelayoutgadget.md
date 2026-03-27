---
title: layout_gc/ActivateLayoutGadget
manual: autodocs-3.5
chapter: autodocs-3.5
section: layout-gc-activatelayoutgadget
functions: [ActivateGadget]
libraries: [intuition.library]
---

# layout_gc/ActivateLayoutGadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  NAME

      ActivateLayoutGadget -- Activate a gadget within a layout window.
  SYNOPSIS

```c
      Success = ActivateLayoutGadget( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Request](autodocs-3.5/intuition-library-request-2.md), [Object](autodocs-3.5/include-intuition-classusr-h.md) )
      d0                              a0      a1      a2       d0

      [BOOL](autodocs-3.5/include-exec-types-h.md) ActivateLayoutGadget( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
              struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG );
```
  FUNCTION

```c
      The equivalent of intuition.library [ActivateGadget()](autodocs-3.5/intuition-library-activategadget-2.md) for a
      window controlled by layout.gadget. If successful, this means
      that the user does not need to click in the gadget before
      typing.

      The gadget parameter MUST point to the root layout gadget in
      the window, and the object parameter to the gagdet you wish
      to activate. This works by calling the private
      LAYOUT_ACTIVATEOBJECT method to search the layout hierarchy for
      the specified gadget, and set the handleinput path to that
      gadget, and finally calling [ActivateGadget](autodocs-3.5/intuition-library-activategadget-2.md) for the root object.

      The rules of calling [ActivateGadget()](autodocs-3.5/intuition-library-activategadget-2.md) apply to
      ActivateLayoutGadget() also.
```
  INPUTS

```c
      [Gadget](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the root layout obejct for the window.
      [Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window the gadget is in.
      [Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a requester (may be NULL)
      [Object](autodocs-3.5/include-intuition-classusr-h.md) = pointer to the BOOPSI object you wish to activate.
```
  RESULT

```c
      If the conditions above (and those of [ActivateGadget()](autodocs-3.5/intuition-library-activategadget-2.md)) are
      met, the function will return TRUE, else FALSE.
```
  NOTES

```c
      Not only string gadgets can be activated this way. Many
      ReAction gadget classes, such as the button.gadget, also
      support keyboard control, and thus may be activated this way.

      An attempt to activate a gadget that is not currently visible
      (as on a hidden page) will fail.
```
  SEE ALSO

```c
      [intuition.library/ActivateGadget()](autodocs-3.5/intuition-library-activategadget-2.md)
```

---

## See Also

- [ActivateGadget — intuition.library](../autodocs/intuition.library.md#activategadget)
