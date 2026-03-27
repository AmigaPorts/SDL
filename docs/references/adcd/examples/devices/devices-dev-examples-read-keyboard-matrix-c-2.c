/* Source: ADCD 2.1
 * Section: devices-dev-examples-read-keyboard-matrix-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-read-keyboard-matrix-c.md
 */

    {
    if (!OpenDevice("keyboard.device",NULL,(struct IORequest *)KeyIO,NULL))
      {
      if (keyMatrix=AllocMem(MATRIX_SIZE,MEMF_PUBLIC|MEMF_CLEAR))
        {
         KeyIO->io_Command=KBD_READMATRIX;
         KeyIO->io_Data=(APTR)keyMatrix;
         KeyIO->io_Length= SysBase->lib_Version >= 36 ? MATRIX_SIZE : 13;
         DoIO((struct IORequest *)KeyIO);

        /* Check for CLI startup... */
        if (argc)
            Display_Matrix(keyMatrix);

        FreeMem(keyMatrix,MATRIX_SIZE);
        }
    else
          printf("Error: Could not allocate keymatrix memory\");

      CloseDevice((struct IORequest *)KeyIO);
      }
      else
        printf("Error: Could not open keyboard.device\n");

    DeleteExtIO((struct IORequest *)KeyIO);
    }
    else
      printf("Error: Could not create I/O request\n");
