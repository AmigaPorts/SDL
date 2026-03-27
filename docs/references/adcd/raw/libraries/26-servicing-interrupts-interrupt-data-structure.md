# 26 / Servicing Interrupts / Interrupt Data Structure


Interrupt handlers and servers are defined by the Exec [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23)
structure.  This structure specifies an interrupt routine entry point and
data pointer.  The C definition of this structure is as follows:


```c
    struct Interrupt
    {
        struct Node is_Node;
        APTR        is_Data;
        VOID      (*is_Code)();
    };
```
Once this structure has been properly initialized, it can be used for
either a handler or a server.

