# window_cl/WM_OPEN



   NAME

```c
       WM_OPEN -- [Open](../Includes_and_Autodocs_3._guide/node0196.html) a window
```
   SYNOPSIS

```c
       window = DoMethod( winobj, WM_OPEN );
```
   FUNCTION

       This function opens the window the object should be handling.
       If the window is already open, it does nothing. If no shared
       message port is set, a message port will be created for this
       window.
   RESULTS

```c
       window -- a pointer to the struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) for this window, or
               NULL if the window could not be opened.
```
