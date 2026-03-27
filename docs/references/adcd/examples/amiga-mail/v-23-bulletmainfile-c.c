/* Source: ADCD 2.1
 * Section: v-23-bulletmainfile-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-23-bulletmainfile-c.md
 */

    if (IntuitionBase = OpenLibrary("intuition.library", 37L))
    {
      if (myrda = ReadArgs(readargsstring, args, NULL))
      {
        if (args[XDPI] && args[YDPI]) /* If the user sets the DPI from the command  */
        {            /* line, make sure the environment variable also gets changed. */
          *(ULONG *)xydpi = ( (*(LONG *)args[XDPI]) << 16 | (*(ULONG *)args[YDPI]) );
          SetVar(dpivarname, xydpi, 5,
              GVF_GLOBAL_ONLY | GVF_BINARY_VAR | GVF_DONT_NULL_TERM);
        }
        else                           /* If the user did NOT set the X OR Y DPI... */
        {
          args[XDPI] = (LONG) &defxdpi;/* ...set to default values and see if there */
          args[YDPI] = (LONG) &defydpi;/* there is an environment variable "XYDPI". */
                                                  /* Read the environment variable, */
          if ((GetVar(dpivarname, xydpi, 5,       /* XYDPI, if it exists.           */
              GVF_GLOBAL_ONLY | GVF_BINARY_VAR | GVF_DONT_NULL_TERM)) != -1)
