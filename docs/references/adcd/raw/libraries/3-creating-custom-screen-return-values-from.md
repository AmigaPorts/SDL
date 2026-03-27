# 3 / / Creating Custom Screen / Return Values from OpenScreenTagList()


[OpenScreenTagList()](../Libraries_Manual_guide/node00DF.html#line6) and its variants return a pointer to a [Screen](../Libraries_Manual_guide/node00DE.html#line6)
structure on the successful creation of a new screen and NULL on failure.
With V36, the call now supports extended error codes on failure.  The
error returns provide information on the type of failure, giving the
application a greater chance of recovery.  To get the extended error code,
you need to use the [SA_ErrorCode](../Libraries_Manual_guide/node00E5.html#line14) tag; the code itself will be placed into
the LONG pointed to by the [TagItem.ti_Data](../Libraries_Manual_guide/node0497.html#line9) field.  Here are the codes:

OSERR_NOMONITOR

    The monitor needed to display the requested mode is not available. An
    example of this error would be opening a Productivity mode screen on
    a system without a VGA or multisync monitor.
OSERR_NOCHIPS

```c
    Newer custom chips are required for this screen mode.  For instance,
    the ECS Denise is required for the [productivity modes](../Libraries_Manual_guide/node031B.html).
```
OSERR_NOMEM

    Could not allocate enough memory.
OSERR_NOCHIPMEM

    Could not allocate enough Chip memory.
OSERR_PUBNOTUNIQUE

```c
    Could not create [public screen](../Libraries_Manual_guide/node00E9.html)--name already used.  The system
    requires that public screen names be unique.
```
OSERR_UNKNOWNMODE

```c
    Display mode requested was not recognized.  The system does not
    understand the value specified with the [SA_DisplayID](../Libraries_Manual_guide/node00E5.html#line74) tag.
```
