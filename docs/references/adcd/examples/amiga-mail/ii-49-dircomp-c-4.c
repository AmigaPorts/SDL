/* Source: ADCD 2.1
 * Section: ii-49-dircomp-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-dircomp-c.md
 */

    for (i = 0; special[i] != '\0'; i++)
    {
      if (*tmp == special[i])
        return (tmp);
    }
    tmp++;
