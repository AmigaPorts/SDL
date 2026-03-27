# 28 / / Double-Buffering / DBufPacket and Double-Buffering


For double-buffering, a place must be provided for the system to store the
extra information it needs.  The system maintains these data, and does not
expect the application to change them.  The [DBufPacket](../Includes_and_Autodocs_2._guide/node00C3.html#line231) structure consists
of the following members:

[BufY, BufX](../Includes_and_Autodocs_2._guide/node00C3.html#line236)  Lets the system keep track of where the object was located

```c
            in the last frame (as compared to the [Bob](../Libraries_Manual_guide/node0398.html) structure
            members called [OldY and OldX](../Includes_and_Autodocs_2._guide/node00C3.html#line87) that tell where the object
            was two frames ago).  BufY and BufX provide for correct
            restoration of the background within the currently active
            drawing buffer.
```
[BufPath](../Includes_and_Autodocs_2._guide/node00C3.html#line236)     Assures that the system restores the backgrounds in the

```c
            correct sequence; it relates to the [VSprite](../Libraries_Manual_guide/node0381.html) members
            [DrawPath](../Libraries_Manual_guide/node0382.html#line6) and [ClearPath](../Libraries_Manual_guide/node0382.html#line6).
```
[BufBuffer](../Includes_and_Autodocs_2._guide/node00C3.html#line239)   This field must be set to point to a buffer the same size

```c
            as the Bob's [SaveBuffer](../Libraries_Manual_guide/node0398.html#line5).  This buffer is used to store the
            background for later restoration when the system moves the
            object.  This buffer must be allocated from Chip memory.
```
To create a double-buffered Bob, execute a code sequence similar to the
following:


```c
    struct Bob        myBob = {0};
    struct DBufPacket myDBufPacket = {0};

    /* Allocate a DBufPacket for myBob same size as previous example */
    if (NULL != (myDBufPacket.BufBuffer = AllocRaster(48, 20 * 5)))
        {
        /* tell Bob about its double buff status */
        myBob.DBuffer = myDBufPacket;
        }
```
The example routines [makeBob()](../Libraries_Manual_guide/node059C.html#line129) and [freeBob()](../Libraries_Manual_guide/node059C.html#line302) in the [animtools.c](../Libraries_Manual_guide/node059C.html#line129) listing at
the end of this chapter show how to correctly allocate and free a
double-buffered Bob.

