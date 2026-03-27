/* Source: ADCD 2.1
 * Section: iv-91-wheelgrad-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-91-wheelgrad-c.md
 */

            /* Get rid of the gadgets */
            DisposeObject(colwheel);
            DisposeObject(gradslid);

            /* Always release the pens */
            while (numPens > 0)
            {
                numPens--;
                ReleasePen(Myscreen->ViewPort.ColorMap,penns[numPens]);
            }

            CloseScreen(Myscreen);
