/* Source: ADCD 2.1
 * Section: ii-49-dircomp-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-dircomp-c.md
 */

    /*
     * There seems to be only one component. Copy it if it is not wild. Caller will
     * have to check whether if it exists and if it is a file or directory.
     */
    if (!(ItsWild(pathpart)))
      pathpart = NULL;
