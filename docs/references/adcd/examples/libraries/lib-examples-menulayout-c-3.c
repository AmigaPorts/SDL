/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    flags = ((struct MenuItem *)ItemAddress(FirstMenu,(LONG)selection))->Flags;
    if (flags & CHECKED)
        printf("(Checked) ");
    }
