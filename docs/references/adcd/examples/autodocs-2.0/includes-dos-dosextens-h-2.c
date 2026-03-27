/* Source: ADCD 2.1
 * Section: includes-dos-dosextens-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-dos-dosextens-h.md
 */

    LONG   cli_Result2;	       /* Value of IoErr from last command	  */
    BSTR   cli_SetName;	       /* Name of current directory		  */
    BPTR   cli_CommandDir;     /* Head of the path locklist		  */
    LONG   cli_ReturnCode;     /* Return code from last command		  */
    BSTR   cli_CommandName;    /* Name of current command		  */
    LONG   cli_FailLevel;      /* Fail level (set by FAILAT)		  */
    BSTR   cli_Prompt;	       /* Current prompt (set by PROMPT)	  */
    BPTR   cli_StandardInput;  /* Default (terminal) CLI input		  */
    BPTR   cli_CurrentInput;   /* Current CLI input			  */
    BSTR   cli_CommandFile;    /* Name of EXECUTE command file		  */
    LONG   cli_Interactive;    /* Boolean; True if prompts required	  */
    LONG   cli_Background;     /* Boolean; True if CLI created by RUN	  */
    BPTR   cli_CurrentOutput;  /* Current CLI output			  */
    LONG   cli_DefaultStack;   /* Stack size to be obtained in long words */
    BPTR   cli_StandardOutput; /* Default (terminal) CLI output		  */
    BPTR   cli_Module;	       /* SegList of currently loaded command	  */
