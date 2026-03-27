/* Source: ADCD 2.1
 * Section: vii-17-camg-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vii-17-camg-c.md
 */

            screen = OpenScreenTags(NULL,
                                    SA_Width, wide,
                                    SA_Height, high,
                                    SA_Depth, deep,
                                    SA_DisplayID, modeid);
        }
    }


    if (!screen) /* not 2.0, or mode not
                  * available, or can't open */
    {
        /*
         * Try an old-style OpenScreen with modefallback() modeid
         */

        modeid = modefallback(modeid, wide, high, deep);

        ns.Width = wide;
        ns.Height = high;
        ns.Depth = deep;
        ns.ViewModes = modeid;
