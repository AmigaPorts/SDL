/* Source: ADCD 2.1
 * Section: exec-library-setsignal
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-setsignal.md
 */

    Get the current state of all signals:
        SetSignal(0L,0L);
    Clear the CTRL-C signal:
        SetSignal(0L,SIGBREAKF_CTRL_C);


    Check if the CTRL-C signal was pressed:

        #include [<libraries/dos.h>](../Includes_and_Autodocs_2._guide/node0108.html)

        /* Check & clear CTRL_C signal */
        if(SetSignal(0L,SIGBREAKF_CTRL_C) & SIGBREAKF_CTRL_C)
            {
            printf("CTRL-C pressed!n");
            }
