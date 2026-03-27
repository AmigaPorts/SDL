# page_gc/PAGE_GetClass



  NAME

      PAGE_GetClass -- Gets the pointer to the Page class.
  SYNOPSIS

```c
      page_class = PAGE_GetClass();
      D0

      Class * PAGE_GetClass(VOID);
```
  FUNCTION

```c
      Obtains the pointer to the page gadget class for use with
      [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).  This function always returns a valid pointer so
      you do not need to check it.  The reason is that if the library
      opens fine, then the pointer returned is already setup.  (Of course
      this implies that if opening the library fails, you shouldn't be
      calling this.)

      Note that this function does not create the class, that is done
      when the class library is opened.
```
  INPUTS

      Nothing.
  NOTES

```c
      PAGE_GetClass() is contained in layout.gadget. There is no PageBase,
      just LayoutBase.
```
  RESULT

      page_class - Pointer to the page gadget class.
