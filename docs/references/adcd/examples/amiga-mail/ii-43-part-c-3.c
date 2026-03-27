/* Source: ADCD 2.1
 * Section: ii-43-part-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-43-part-c.md
 */

    static UBYTE   *special = "#?*%([|";
    UBYTE          *tmp = string;
    COUNT           i;

    do
    {
        for (i = 0; special[i] != '\0'; i++)
        {
            if (*tmp == special[i])
                return (tmp);
        }
        tmp++;
    } while (*tmp);

    return (NULL);
