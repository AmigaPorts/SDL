/* Source: ADCD 2.1
 * Section: 36-translator-library-using-the-translate-function
 * Library: libraries
 * ADCD reference: libraries/36-translator-library-using-the-translate-function.md
 */

    #define BUFLEN 500

    STRPTR EnglStr;                 /* pointer to sample input string */
    LONG EnglLen;                   /* input length */
    UBYTE PhonBuffer[BUFLEN];       /* place to put the translation */
    LONG rtnCode;                   /* return code from function */

    EnglStr = "This is Amiga speaking.";    /* a test string */
    EnglLen = strlen(EnglStr);
    rtnCode = Translate(EnglStr, EnglLen, (STRPTR)&PhonBuffer[0], BUFLEN);
