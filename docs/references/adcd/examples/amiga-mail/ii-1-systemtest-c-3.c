/* Source: ADCD 2.1
 * Section: ii-1-systemtest-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-1-systemtest-c.md
 */

    {
    struct TagItem stags[4];

    stags[0].ti_Tag = SYS_Input;
    stags[0].ti_Data = other ? other : Input();
    stags[1].ti_Tag = SYS_Output;
    stags[1].ti_Data = other ? NULL: Output();
    stags[3].ti_Tag = TAG_DONE;
    return(System(command, stags));
    }
