/* Source: ADCD 2.1
 * Section: includes-dos-dosextens-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-dos-dosextens-h.md
 */

    struct  Task    pr_Task;
    struct  MsgPort pr_MsgPort; /* This is BPTR address from DOS functions  */
    WORD    pr_Pad;		/* Remaining variables on 4 byte boundaries */
    BPTR    pr_SegList;		/* Array of seg lists used by this process  */
    LONG    pr_StackSize;	/* Size of process stack in bytes	    */
    APTR    pr_GlobVec;		/* Global vector for this process (BCPL)    */
    LONG    pr_TaskNum;		/* CLI task number of zero if not a CLI	    */
    BPTR    pr_StackBase;	/* Ptr to high memory end of process stack  */
    LONG    pr_Result2;		/* Value of secondary result from last call */
    BPTR    pr_CurrentDir;	/* Lock associated with current directory   */
    BPTR    pr_CIS;		/* Current CLI Input Stream		    */
    BPTR    pr_COS;		/* Current CLI Output Stream		    */
    APTR    pr_ConsoleTask;	/* Console handler process for current window*/
    APTR    pr_FileSystemTask;	/* File handler process for current drive   */
    BPTR    pr_CLI;		/* pointer to CommandLineInterface	    */
    APTR    pr_ReturnAddr;	/* pointer to previous stack frame	    */
    APTR    pr_PktWait;		/* Function to be called when awaiting msg  */
    APTR    pr_WindowPtr;	/* Window for error printing		    */

    /* following definitions are new with 2.0 */
    BPTR    pr_HomeDir;		/* Home directory of executing program	    */
    LONG    pr_Flags;		/* flags telling dos about process	    */
    void    (*pr_ExitCode)();	/* code to call on exit of program or NULL  */
    LONG    pr_ExitData;	/* Passed as an argument to pr_ExitCode.    */
    UBYTE   *pr_Arguments;	/* Arguments passed to the process at start */
    struct MinList pr_LocalVars; /* Local environment variables		    */
    ULONG   pr_ShellPrivate;	/* for the use of the current shell	    */
    BPTR    pr_CES;		/* Error stream - if NULL, use pr_COS	    */
