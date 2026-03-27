# window_cl/WM_RETHINK



   NAME

       WM_RETHINK -- Re-evaluate an open window's size requirement
   SYNOPSIS

```c
       window = DoMethod( winobj, WM_RETHINK );
```
   FUNCTION

       This function re-evaluates the layout group's minimum size
       and adjusts the window size to contain it if needed.
   RESULTS

       Non-Zero if implemented.
