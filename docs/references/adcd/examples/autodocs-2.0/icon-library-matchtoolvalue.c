/* Source: ADCD 2.1
 * Section: icon-library-matchtoolvalue
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-matchtoolvalue.md
 */

    Assume there are two type strings:
        type1 = "text"
        type2 = "a|b|c"

    MatchToolValue( type1, "text" ) returns TRUE
    MatchToolValue( type1, "TEXT" ) returns TRUE
    MatchToolValue( type1, "data" ) returns FALSE
    MatchToolValue( type2, "a" ) returns TRUE
    MatchToolValue( type2, "b" ) returns TRUE
    MatchToolValue( type2, "d" ) returns FALSE
    MatchToolValue( type2, "a|b" ) returns FALSE
