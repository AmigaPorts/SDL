/* Source: ADCD 2.1
 * Section: ii-1-systemtest-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-1-systemtest-c.md
 */

    {
    extern struct Library *DOSBase;
    struct Screen *scr = NULL;
    struct Window *win = NULL;
    ULONG penspecterm = ~0;
    LONG result;
    BPTR file;
    UBYTE *command;
    UBYTE buf[128];

    if(DOSBase->lib_Version < 36)
        {
        printf("This example requires dos.library V36 or higher\n");
        exit(RETURN_FAIL);
        }
    if(!(IntuitionBase = OpenLibrary("intuition.library",36)))
        {
        printf("This example requires intuition.library V36 or higher\n");
        exit(RETURN_FAIL);
        }

    /* SYNCHRONOUS SYSTEM() WITH OUR INPUT/OUTPUT
     */
    printf("\n*** SystemTest: Synchronous System call 'dir libs:':\n");
    command = "dir libs:";
    result = doCommand(command,NULL);
    checkResult(command,result);
    printf("\n*** SystemTest: Synchronous System call of nonexistant command:\n");
    command = "badcommand";
    result = doCommand(command,NULL);
    checkResult(command,result);

    printf("\n*** SystemTest: Synchronous System call 'ask \"...Answer y now\"':\n");
    command =
        "ask \"Ready for CON: on a Custom Screen? Answer y now (should return 5):\"";
    result = doCommand(command,NULL);
    checkResult(command,result);
