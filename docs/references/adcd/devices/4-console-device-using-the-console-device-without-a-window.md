---
title: 4 Console Device / Using the Console Device Without a Window
manual: devices
chapter: devices
section: 4-console-device-using-the-console-device-without-a-window
functions: [CDInputHandler, CreateMsgPort, OpenDevice, RawKeyConvert]
libraries: [console.device, exec.library]
---

# 4 Console Device / Using the Console Device Without a Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most console device processing involves a window, but there are functions
and special commands that may be used without a window.  To use the
console device without a window, you call [OpenDevice()](autodocs-2.0/console-device-opendevice.md) with the console
unit CONU_LIBRARY.

The console device functions are [CDInputHandler()](autodocs-2.0/console-device-cdinputhandler.md) and [RawKeyConvert()](autodocs-2.0/console-device-rawkeyconvert.md);
they may only be used with the CONU_LIBRARY console unit.  The console
device commands which do not require a window are [CD_ASKDEFAULTKEYMAP](autodocs-2.0/console-device-cd-askdefaultkeymap.md)
and [CD_SETDEFAULTKEYMAP](autodocs-2.0/console-device-cd-setdefaultkeymap.md); they be used with any console unit.  The
advantage of using the commands with the CONU_LIBRARY unit is the lack of
overhead required for CONU_LIBRARY because it doesn't require a window.

To use the functions requires the following steps:

   *  Declare the console device base address variable ConsoleDevice in the

      global data area.
   *  Declare storage for an I/O request of type [IOStdReq](devices/4-console-device-device-interface.md).

   *  Open the console device with CONU_LIBRARY set as the console unit.

   *  Set the console device base address variable to point to the device

      library vector which is returned in io_Device.
   *  Call the console device function(s).

   *  Close the console device when you are finished.


   #include <devices/conunit.h>
   struct ConsoleDevice *ConsoleDevice;  /* declare device base address */

   struct IOStdReq ConsIO= {0};          /* I/O request */

   main()


       /* Open the device with CONU_LIBRARY for function use */
   if (0 == OpenDevice("console.device",CONU_LIBRARY,

```c
                      (struct IORequest *)&ConsIO,0) )
       {
       /* Set the base address variable to the device library vector */
       ConsoleDevice = (struct ConsoleDevice *)ConsIO.io_Device;

                     .
                     .    (console device functions would be called here)
                     .

       CloseDevice(ConsIO);
       }
```
The code fragment shows only the steps outlined above, it is not complete
in any sense of the word.  For a complete example of using a console
device function, see the [rawkey.c](devices/lib-examples-rawkey-c.md) code example in the
"[Intuition: Mouse and Keyboard](libraries/10-intuition-mouse-and-keyboard.md)" chapter of the Amiga ROM Kernel Reference
Manual: Libraries.  The example uses the [RawKeyConvert()](autodocs-2.0/console-device-rawkeyconvert.md) function.

To use the commands with the CONU_LIBRARY console unit, you follow the
same steps that were outlined in the [Opening the Console Device](devices/4-device-interface-opening-the-console-device.md) section of
this chapter.

   struct MsgPort *ConsoleMP;       /* pointer to our message port */
   struct IOStdReq *ConsoleIO;      /* pointer to our I/O request */
   struct KeyMap  *keymap;          /* pointer to keymap */

       /* Create the message port */
   if (ConsoleMP=CreateMsgPort())

```c
       {
           /* Create the I/O request */
       if (ConsoleIO = CreateIORequest(ConsoleMP,sizeof(struct IOStdReq)))
           {
               /* Open the Console device */
           if (OpenDevice("console.device",CONU_LIBRARY,
                         (struct IORequest *)ConsoleIO,0L))

               /* Inform user that it could not be opened */
               printf("Error: console.device did not open\n");
           else
               {
                  /* Allocate memory for the keymap */
               if (keymap = (struct KeyMap *)
                  AllocMem(sizeof(struct KeyMap),MEMF_PUBLIC | MEMF_CLEAR))
                  {
                  /* device opened, send CD_ASKKEYMAP command to it */
                  ConsoleIO->io_Length = sizeof(struct KeyMap);
                  ConsoleIO->io_Data = (APTR)keymap; /* where to put it */
                  ConsoleIO->io_Command = CD_ASKKEYMAP;
                  DoIO((struct IORequest *)ConsoleIO))
                  }

               CloseDevice(ConsIO);
               }
```
Again, as in the previous code fragment, this is not complete (that's why
it's a fragment!) and you should only use it as a guide.

---

## See Also

- [CDInputHandler — console.device](../autodocs/console.device.md#cdinputhandler)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [RawKeyConvert — console.device](../autodocs/console.device.md#rawkeyconvert)
