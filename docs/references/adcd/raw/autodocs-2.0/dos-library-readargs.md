# dos.library/ReadArgs



NAME

```c
    ReadArgs - Parse the command line input (V36)
```
SYNOPSIS

```c
    result = ReadArgs(template, array, rdargs)
    D0                   D1      D2      D3

    struct [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) * ReadArgs(STRPTR, LONG *, struct [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) *)
```
FUNCTION

```c
    Parses and argument string according to a template.  Normally gets
    the arguments by reading buffered IO from [Input()](../Includes_and_Autodocs_2._guide/node02BF.html), but also can be
    made to parse a string.  MUST be matched by a call to [FreeArgs()](../Includes_and_Autodocs_2._guide/node02AF.html).

    ReadArgs() parses the commandline according to a template that is
    passed to it.  This specifies the different command-line options and
    their types.  A template consists of a list of options.  Options are
    named in "full" names where possible (for example, "Quick" instead of
    "Q").  Abbreviations can also be specified by using "abbrev=option"
    (for example, "Q=Quick").

    Options in the template are separated by commas.  To get the results
    of ReadArgs(), you examine the array of longwords you passed to it
    (one entry per option in the template).  This array should be cleared
    (or initialized to your default values) before passing to ReadArgs().
    Exactly what is put in a given entry by ReadArgs() depends on the type
    of option.  The default is a string (a sequence of non-whitespace
    characters, or delimited by quotes, which will be stripped by
    ReadArgs()), in which case the entry will be a pointer.

    Options can be followed by modifiers, which specify things such as
    the type of the option.  Modifiers are specified by following the
    option with a '/' and a single character modifier.  Multiple modifiers
    can be specified by using multiple '/'s.  Valid modifiers are:

    /S - Switch.  This is considered a boolean variable, and will be
         set if the option name appears in the command-line.  The entry
         is the boolean (0 for not set, non-zero for set).

    /K - Keyword.  This means that the option will not be filled unless
         the keyword appears.  For example if the template is "Name/K",
         then unless "Name=<string>" or "Name <string>" appears in the
         command line, Name will not be filled.

    /N - Number.  This parameter is considered a decimal number, and will
         be converted by ReadArgs.  If an invalid number is specified,
         an error will be returned.  The entry will be a pointer to the
         longword number (this is how you know if a number was specified).

    /T - Toggle.  This is similar to a switch, but when specified causes
         the boolean value to "toggle".  Similar to /S.

    /A - Required.  This keyword must be given a value during command-line
         processing, or an error is returned.

    /F - Rest of line.  If this is specified, the entire rest of the line
         is taken as the parameter for the option, even if other option
         keywords appear in it.

    /M - Multiple strings.  This means the argument will take any number
         of strings, returning them as an array of strings.  Any arguments
         not considered to be part of another option will be added to this
         option.  Only one /M should be specified in a template.  Example:
         for a template "Dir/M,All/S" the command-line "foo bar all qwe"
         will set the boolean "all", and return an array consisting of
         "foo", "bar", and "qwe".  The entry in the array will be a pointer
         to an array of string pointers, the last of which will be NULL.

         There is an interaction between /M parameters and /A parameters.
         If there are unfilled /A parameters after parsing, it will grab
         strings from the end of a previous /M parameter list to fill the
         /A's.  This is used for things like Copy ("From/A/M,To/A").

    ReadArgs() returns a struct [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) if it succeeds.  This serves as an
    "anchor" to allow [FreeArgs()](../Includes_and_Autodocs_2._guide/node02AF.html) to free the associated memory.  You can
    also pass in a struct [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) to control the operation of ReadArgs()
    (normally you pass NULL for the parameter, and ReadArgs() allocates
    one for you).  This allows providing different sources for the
    arguments, providing your own string buffer space for temporary
    storage, and extended help text.  See [<dos/rdargs.h>](../Includes_and_Autodocs_2._guide/node0076.html) for more
    information on this.  Note: if you pass in a struct [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96), you must
    still call [FreeArgs()](../Includes_and_Autodocs_2._guide/node02AF.html) to release storage that gets attached to it,
    but you are responsible for freeing the [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) yourself.

    See BUGS regarding passing in strings.
```
INPUTS

```c
    template - formatting string
    array    - array of longwords for results, 1 per template entry
    rdargs   - optional rdargs structure for options.  [AllocDosObject](../Includes_and_Autodocs_2._guide/node027F.html)
               should be used for allocating them if you pass one in.
```
RESULT

```c
    result   - a struct [RDArgs](../Includes_and_Autodocs_2._guide/node0076.html#line96) or NULL for failure.
```
BUGS

```c
    In V36, there were a couple of minor bugs with certain argument
    combinations (/M/N returned strings, /T didn't work, and /K and
    /F interacted).  Also, a template with a /K before any non-switch
    parameter will require the argument name to be given in order for
    line to be accepted (i.e. "parm/K,xyzzy/A" would require
    "xyzzy=xxxxx" in order to work - "xxxxx" would not work).  If you
    need to avoid this for V36, put /K parameters after all non-switch
    parameters.  These problems should be fixed for V37.

    Currently (V37 and before) it requires any strings passed in to have
    newlines at the end of the string.  This may or may not be fixed in
    the future.
```
SEE ALSO

```c
    [FindArg()](../Includes_and_Autodocs_2._guide/node02A5.html), [ReadItem()](../Includes_and_Autodocs_2._guide/node02E2.html), [FreeArgs()](../Includes_and_Autodocs_2._guide/node02AF.html), [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html)
```
