# 5 / / Custom String Editing / Actions Definitions


These are the actions to be taken by Intuition after the hook returns.
Set or clear these bits in [SGWork](../Libraries_Manual_guide/node016F.html) structure Actions field.  A number of
these flags may already be set when the hook is called.


  Actions Flag    Purpose
  ------------    -------
  SGA_USE         If set, use contents of [SGWork](../Libraries_Manual_guide/node016F.html).
  SGA_END         Terminate gadget, Code field is sent to application
```c
                  in [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) event code field.
```
  SGA_BEEP        Beep (i.e., flash) the screen.
  SGA_REUSE       Reuse the input event.  Only valid with SGA_END.
  SGA_REDISPLAY   Gadget visuals have changed, update on screen.
  SGA_NEXTACTIVE  Make next possible gadget active (new for V37).
  SGA_PREVACTIVE  Make previous possible gadget active (new for V37).

