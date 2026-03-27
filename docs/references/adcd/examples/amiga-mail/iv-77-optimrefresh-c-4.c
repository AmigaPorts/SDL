/* Source: ADCD 2.1
 * Section: iv-77-optimrefresh-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-77-optimrefresh-c.md
 */

    Move(&render,x,y);                  /* move the cursor to the position */

    if (len > columnsVisible)           /* is line is longer than allowed? */
        len = columnsVisible;           /* yes, so reduce its length       */

    Text(&render,text,len);             /* write to the window             */

    if (len < columnsVisible)
        RectFill(&clear,render.cp_x,y-render.TxBaseline,
                        x+w-1,y-render.TxBaseline+fontHeight-1);
