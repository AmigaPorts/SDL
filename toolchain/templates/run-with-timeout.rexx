/* run-with-timeout.rexx -- Run a command with a timeout, then break it
 *
 * Usage: rx WORK:run-with-timeout.rexx <seconds> <command> [args...]
 *
 * For programs that run forever (yes, tail -f, event loops).
 * Backgrounds the command via AmigaDOS Run, waits N seconds for
 * output to accumulate, then sends Break C to stop it cleanly.
 * Outputs the captured stdout via SAY.
 *
 * KEY INSIGHT: AmigaDOS parses ALL > redirections at the top level.
 * "Run >file1 cmd >file2" applies BOTH redirects to Run, and cmd
 * gets NO redirect -- flooding the console. To fix this, we write
 * cmd + redirect into a temp Execute script. Run only sees ONE
 * redirect (for its own "[CLI N]" output).
 *
 * Deployed to WORK: by test-fsemu.sh alongside test-runner.rexx.
 */
OPTIONS FAILAT 21

/* Parse arguments: first word is timeout, rest is command */
PARSE ARG seconds rest
seconds = STRIP(seconds)
rest = STRIP(rest)

IF rest = '' THEN DO
    SAY 'Usage: rx run-with-timeout.rexx <seconds> <command> [args]'
    EXIT 10
END

outfile = 'T:rwt_out.txt'
clinumfile = 'T:rwt_cli.txt'
cmdscript = 'T:rwt_cmd.txt'

/* Write a temp AmigaDOS script with the command + output redirect.
 * This isolates the command's > from Run's >. */
IF OPEN('sf', cmdscript, 'W') THEN DO
    CALL WRITELN('sf', rest '>' outfile)
    CALL CLOSE('sf')
END

/* Start the script in background via Run.
 * Only ONE > redirect here -- for Run's own "[CLI N]" output. */
ADDRESS COMMAND 'Run >' || clinumfile || ' Execute' cmdscript

/* Wait for output to accumulate */
ADDRESS COMMAND 'Wait' seconds

/* Parse CLI number from Run's "[CLI N]" output and break it */
IF OPEN('cf', clinumfile, 'R') THEN DO
    cliline = READLN('cf')
    CALL CLOSE('cf')
    PARSE VAR cliline '[CLI' clinum ']'
    clinum = STRIP(clinum)
    IF DATATYPE(clinum, 'W') THEN
        ADDRESS COMMAND 'Break' clinum 'C'
END

/* Wait for clean exit after break */
ADDRESS COMMAND 'Wait 1'

/* Read and output the captured content */
IF OPEN('of', outfile, 'R') THEN DO
    DO WHILE ~EOF('of')
        line = READLN('of')
        IF line ~= '' THEN SAY line
    END
    CALL CLOSE('of')
END

/* Cleanup */
ADDRESS COMMAND 'Delete >NIL:' outfile
ADDRESS COMMAND 'Delete >NIL:' clinumfile
ADDRESS COMMAND 'Delete >NIL:' cmdscript

EXIT 0
