/* Source: ADCD 2.1
 * Section: ix-1-4play-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ix-1-4play-c.md
 */

    if(return_code==0) freeport();  /* Assembly routine to
                                       de-allocate parallel port */

    printf("%s\n",whytext);

    exit(return_code);              /* returning non-zero
                                       terminates the program */
