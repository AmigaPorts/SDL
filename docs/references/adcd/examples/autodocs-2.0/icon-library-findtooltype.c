/* Source: ADCD 2.1
 * Section: icon-library-findtooltype
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-findtooltype.md
 */

    Assume the tool type array has two strings in it:
        "FILETYPE=text"
        "TEMPDIR=:t"

    FindToolType( toolTypeArray, "FILETYPE" ) returns "text"
    FindToolType( toolTypeArray, "filetype" ) returns "text"
    FindToolType( toolTypeArray, "TEMPDIR" )  returns ":t"
    FindToolType( toolTypeArray, "MAXSIZE" )  returns NULL
