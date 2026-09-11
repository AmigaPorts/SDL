/* SDL2 AmigaOS3 Automated Test Harness
 *
 * Runs each test binary sequentially, captures exit code and stdout,
 * writes per-test results and a final summary to WORK:.
 * Calls WORK:UAEQuit after all tests complete.
 *
 * Pure ASCII only -- no UTF-8, no smart quotes, no em-dashes.
 * Use ~= for not-equal (not backslash-equals).
 *
 * Volume layout:
 *   WORK: = build/amiga/ (shared host/Amiga directory)
 *   Results go to WORK:results/<testname>.txt
 *   Summary goes to WORK:test_summary.txt
 *   Sentinel written to WORK:tests_done when complete
 *
 * Structure: CALL main at top, subroutines below, EXIT before subroutines.
 */

/* Allow non-zero RC from ADDRESS COMMAND without ARexx ERROR.
 * Only truly catastrophic failures (RC >= 21) raise an error. */
OPTIONS FAILAT 21

CALL main
EXIT

/* ============================================================
 * main: top-level test sequence
 * ============================================================ */
main:
    /* Make sure results directory exists */
    ADDRESS COMMAND 'MakeDir >NIL: WORK:results'

    /* Initialize counters (global to all procedures via EXPOSE) */
    total_tests  = 0
    passed_tests = 0
    failed_tests = 0

    SAY 'SDL2 AmigaOS3 Test Harness starting'

    /* Wait for Workbench and P96 to fully initialize */
    ADDRESS COMMAND 'Wait 3'

    /* Create fresh summary file (OPEN 'A' fails if file does not exist) */
    ADDRESS COMMAND 'Delete >NIL: WORK:test_summary.txt'
    IF OPEN('sf', 'WORK:test_summary.txt', 'W') THEN
        CALL CLOSE('sf')

    /* ---- Test 1: test_bare (SMOKE) ---- */
    CALL run_one_test 'test_bare', 'SMOKE'

    /* ---- Test 2: test_init (SMOKE) ---- */
    CALL run_one_test 'test_init', 'SMOKE'

    /* ---- Test 3: test_spinlock (UNIT) ---- */
    CALL run_one_test 'test_spinlock', 'UNIT'

    /* ---- Test 4: test_video (VIDEO, needs RTG) ---- */
    CALL run_one_test 'test_video', 'VIDEO'

    /* ---- Test 5: test_events (INPUT, needs RTG) ---- */
    CALL run_one_test 'test_events', 'INPUT'

    /* Write final summary footer */
    footer_line = 'SUMMARY total=' || total_tests || ' passed=' || passed_tests || ' failed=' || failed_tests
    IF OPEN('sf', 'WORK:test_summary.txt', 'A') THEN DO
        CALL WRITELN('sf', footer_line)
        CALL CLOSE('sf')
    END

    SAY footer_line

    IF failed_tests = 0 THEN
        SAY 'ALL TESTS PASSED'
    ELSE
        SAY 'SOME TESTS FAILED'

    /* Write sentinel so the host knows tests are done before UAEQuit */
    IF OPEN('dn', 'WORK:tests_done', 'W') THEN DO
        CALL WRITELN('dn', 'done')
        CALL CLOSE('dn')
    END

    /* Brief pause to let the filesystem flush to the host-mounted volume */
    ADDRESS COMMAND 'Wait 1'

    /* Quit the emulator */
    ADDRESS COMMAND 'WORK:UAEQuit'
    RETURN

/* ============================================================
 * run_one_test: run one test binary and record result
 *
 * Arguments:
 *   testname  - short name, e.g. test_bare
 *   category  - SMOKE, UNIT, or VIDEO
 * ============================================================ */
run_one_test: PROCEDURE EXPOSE total_tests passed_tests failed_tests
    PARSE ARG testname, category

    total_tests = total_tests + 1

    result_file = 'WORK:results/' || testname || '.txt'
    binary      = 'WORK:' || testname
    script_file = 'T:sdl2_run_' || testname
    rc_file     = 'T:sdl2_rc_' || testname

    /* Remove any previous result/temp files */
    ADDRESS COMMAND 'Delete >NIL: ' || result_file
    ADDRESS COMMAND 'Delete >NIL: ' || script_file
    ADDRESS COMMAND 'Delete >NIL: ' || rc_file

    /* Write Execute script via ARexx OPEN/WRITELN (proven pattern).
     * Using Echo with embedded > is fragile on AmigaDOS.
     * The script runs the binary with stdout redirect, then writes
     * the return code to a separate file via $RC. */
    IF OPEN('scr', script_file, 'W') THEN DO
        CALL WRITELN('scr', 'FailAt 21')
        CALL WRITELN('scr', binary '>' result_file)
        CALL WRITELN('scr', 'Echo >' || rc_file || ' $RC')
        CALL CLOSE('scr')
    END
    ELSE DO
        SAY 'ERROR: Cannot create script file' script_file
        failed_tests = failed_tests + 1
        RETURN
    END

    /* Execute the script */
    ADDRESS COMMAND 'Execute ' || script_file
    /* Note: Execute's RC reflects whether Execute itself succeeded,
     * not the inner command's RC. We read the real RC from rc_file. */

    /* Read the actual command return code */
    test_rc = 0
    IF OPEN('rcf', rc_file, 'R') THEN DO
        rcline = READLN('rcf')
        CALL CLOSE('rcf')
        IF DATATYPE(STRIP(rcline), 'W') THEN test_rc = STRIP(rcline)
    END
    ELSE DO
        /* rc_file not created means the binary was not found or crashed
         * before $RC could be written */
        test_rc = 20
    END

    /* Clean up temp files */
    ADDRESS COMMAND 'Delete >NIL: ' || script_file
    ADDRESS COMMAND 'Delete >NIL: ' || rc_file

    /* If result file was not created, write a placeholder */
    IF ~EXISTS(result_file) THEN DO
        IF OPEN('rf2', result_file, 'W') THEN DO
            CALL WRITELN('rf2', 'TEST BINARY NOT FOUND OR CRASHED')
            CALL CLOSE('rf2')
        END
        test_rc = 20
    END

    /* Determine pass/fail */
    IF test_rc = 0 THEN DO
        outcome = 'PASS'
        passed_tests = passed_tests + 1
    END
    ELSE DO
        outcome = 'FAIL'
        failed_tests = failed_tests + 1
    END

    /* Write result line to both per-test file and summary */
    line = outcome || ' ' || testname || ' RC=' || test_rc || ' [' || category || ']'

    IF OPEN('rf3', result_file, 'A') THEN DO
        CALL WRITELN('rf3', line)
        CALL CLOSE('rf3')
    END

    IF OPEN('sf', 'WORK:test_summary.txt', 'A') THEN DO
        CALL WRITELN('sf', line)
        CALL CLOSE('sf')
    END

    SAY line
    RETURN
