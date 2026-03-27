/* Source: ADCD 2.1
 * Section: iv-77-optimrefresh-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-77-optimrefresh-c.md
 */

    NewList((struct List *)&document);
    numLines = 0;
    i        = 100;
    while (i--)
    {
        if (line = AllocVec(sizeof(struct Line)+91,MEMF_CLEAR|MEMF_PUBLIC))
        {
            line->ln_Text    = (STRPTR)((ULONG)line + sizeof(struct Line));
            line->ln_TextLen = 40;
            AddTail((struct List *)&document,(struct Node *)line);
            numLines++;

            j = 0;
            while (j < 90)
            {
                line->ln_Text[j] = (numLines % 96) + 32;
                j++;
            }
        }
    }
