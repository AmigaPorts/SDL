# layout_gc/LAYOUT_GetClass



  NAME

      LAYOUT_GetClass -- Gets the pointer to the layout class.
  SYNOPSIS

```c
      layout_class = LAYOUT_GetClass();
      D0

      Class * LAYOUT_GetClass(VOID);
```
  FUNCTION

```c
      Obtains the pointer to the layout gadget class for use with
      [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).  This function always returns a valid pointer so
      you do not need to check it.  The reason is that if the library
      opens fine, then the pointer returned is already setup.  (Of
      course this implies that if opening the library fails, you
      shouldn't be calling this.)

      Note that this function does not create the class, that is done
      when the class library is opened.
```
  INPUTS

      Nothing.
  RESULT

      LayoutClass - Pointer to the layout gadget class.
