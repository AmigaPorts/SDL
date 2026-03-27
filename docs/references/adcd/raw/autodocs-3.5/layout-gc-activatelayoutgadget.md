# layout_gc/ActivateLayoutGadget



  NAME

      ActivateLayoutGadget -- Activate a gadget within a layout window.
  SYNOPSIS

```c
      Success = ActivateLayoutGadget( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Request](../Includes_and_Autodocs_3._guide/node03E5.html), [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) )
      d0                              a0      a1      a2       d0

      [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ActivateLayoutGadget( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
              struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, ULONG );
```
  FUNCTION

```c
      The equivalent of intuition.library [ActivateGadget()](../Includes_and_Autodocs_3._guide/node038F.html) for a
      window controlled by layout.gadget. If successful, this means
      that the user does not need to click in the gadget before
      typing.

      The gadget parameter MUST point to the root layout gadget in
      the window, and the object parameter to the gagdet you wish
      to activate. This works by calling the private
      LAYOUT_ACTIVATEOBJECT method to search the layout hierarchy for
      the specified gadget, and set the handleinput path to that
      gadget, and finally calling [ActivateGadget](../Includes_and_Autodocs_3._guide/node038F.html) for the root object.

      The rules of calling [ActivateGadget()](../Includes_and_Autodocs_3._guide/node038F.html) apply to
      ActivateLayoutGadget() also.
```
  INPUTS

```c
      [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) = pointer to the root layout obejct for the window.
      [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window the gadget is in.
      [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) = pointer to a requester (may be NULL)
      [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) = pointer to the BOOPSI object you wish to activate.
```
  RESULT

```c
      If the conditions above (and those of [ActivateGadget()](../Includes_and_Autodocs_3._guide/node038F.html)) are
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
      [intuition.library/ActivateGadget()](../Includes_and_Autodocs_3._guide/node038F.html)
```
