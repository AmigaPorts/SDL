/* Source: ADCD 2.1
 * Section: tool-types
 * Library: amiga-mail
 * ADCD reference: amiga-mail/tool-types.md
 */

    tooltypearray = char **ArgArrayInit(int argc, char **argv);
    void ArgArrayDone(void);
    tooltypevalue = char *ArgString(char **tooltypearray,
                                char *tooltype, char *defaultvalue);
    tooltypevalue = LONG *ArgInt(char **tooltypearray,
                                char *tooltype, LONG defaultvalue);
