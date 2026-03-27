# window_cl/WM_CLOSE



   NAME

```c
       WM_CLOSE -- [Close](../Includes_and_Autodocs_3._guide/node0149.html) a window
```
   SYNOPSIS

```c
       DoMethod( winobj, WM_CLOSE );
```
   FUNCTION

```c
       [Close](../Includes_and_Autodocs_3._guide/node0149.html) the window of this object. The gadgets are not disposed,
       only detached of a window. If the window is sharing a message
       port with another window, the port will be cleaned of message
       intended for this window. If the window was iconified, the icon
       will be removed.
```
