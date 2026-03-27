# Appendix A. Reference / Syntax Definitions


Here's a collection of the syntax definitions in this document.


```c
    Chunk        ::= ID #{ UBYTE* } [0]

    Property     ::= Chunk

    FORM         ::= 'FORM' #{ FormType (LocalChunk | FORM | LIST | CAT)* }
    FormType     ::= ID
    LocalChunk   ::= Property | Chunk

    CAT          ::= 'CAT ' #{ ContentsType (FORM | LIST | CAT)* }
    ContentsType ::= ID     - a hint or an "abstract data type" ID

    LIST         ::= 'LIST' #{ ContentsType PROP* (FORM | LIST | CAT)* }
    PROP         ::= 'PROP' #{ FormType Property* }
```
In this extended regular expression notation, the token '#' represents a
count of the following {braced} data bytes.  Literal items are shown in
"quotes", [square bracketed items] are optional, and "*" means 0 or more
instances.  A sometimes-needed pad byte is shown as "[0]".

