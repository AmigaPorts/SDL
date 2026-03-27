/* Source: ADCD 2.1
 * Section: appendix-a-reference-syntax-definitions
 * Library: devices
 * ADCD reference: devices/appendix-a-reference-syntax-definitions.md
 */

    Chunk        ::= ID #{ UBYTE* } [0]

    Property     ::= Chunk

    FORM         ::= 'FORM' #{ FormType (LocalChunk | FORM | LIST | CAT)* }
    FormType     ::= ID
    LocalChunk   ::= Property | Chunk

    CAT          ::= 'CAT ' #{ ContentsType (FORM | LIST | CAT)* }
    ContentsType ::= ID     - a hint or an "abstract data type" ID

    LIST         ::= 'LIST' #{ ContentsType PROP* (FORM | LIST | CAT)* }
    PROP         ::= 'PROP' #{ FormType Property* }
