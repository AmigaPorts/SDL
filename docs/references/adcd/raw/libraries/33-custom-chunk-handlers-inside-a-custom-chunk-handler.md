# 33 / / Custom Chunk Handlers / Inside a Custom Chunk Handler


The mechanics of receiving parameters through the [Hook](../Libraries_Manual_guide/node04A3.html) are covered in the
"[Custom Stream Handlers](../Libraries_Manual_guide/node0454.html)" section, and are not duplicated here.  Refer to
the [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html) and [ExitHandler()](../Includes_and_Autodocs_2._guide/node01C0.html) Autodocs for the contents of the
registers upon entry.

Once inside your handler, you can call nearly all functions in the
iffparse.library, however, you should avoid calling [ParseIFF()](../Libraries_Manual_guide/node0432.html) from within
chunk handlers.

Your handler runs in the same environment as whoever called [ParseIFF()](../Libraries_Manual_guide/node0432.html).
The propagation sequence is:



```c
     __________            ____________            ________________
    |          |          |            |          |                |
    | mainline |--calls-->| ParseIFF() |--calls-->| your_handler() |
    |__________|          |____________|          |________________|
```
Thus, your handler runs on your mainline's stack, and can call any OS
functions the mainline code can.  (Your handler will have to set the
global base pointer if your code uses base-relative addressing.)

When leaving the handler, you must follow the standard register
preservation conventions (D0/D1/A0/A1 may be trashed, all others must be
preserved).  D0 contains your return code, which will affect the parser in
a number of ways:

If you return zero (a normal, uneventful return), [ParseIFF()](../Libraries_Manual_guide/node0432.html) will continue
normally.  If you return the value IFFERR_RETURN2CLIENT, ParseIFF() will
stop and return the value zero to the mainline code.

If you return any other value, [ParseIFF()](../Libraries_Manual_guide/node0432.html) will stop and return that value
to the mainline code.  This is how you should return error conditions to
the client code.

