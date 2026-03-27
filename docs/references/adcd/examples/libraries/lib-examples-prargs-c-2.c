/* Source: ADCD 2.1
 * Section: lib-examples-prargs-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-prargs-c.md
 */

    {
    /* using 'tinymain' from lattice c.
    ** define a place to send the output (originating CLI window = "*")
    ** Note - if you open "*" and your program is RUN, the user will not
    ** be able to close the CLI window until you close the "*" file.
    */
    if (NULL != (outFile = fopen("*","r+")))
        {
        fprintf(outFile, "Run from the CLI, %d args.\n", argc);

        for ( ktr = 0; ktr < argc; ktr++)
            {
            /* print an arg, and its number */
            fprintf(outFile, "\tArg %2.2ld: '%s'.\n", ktr, argv[ktr]);
            }
        fclose(outFile);
        }
    }
