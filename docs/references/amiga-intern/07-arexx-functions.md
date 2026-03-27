# ARexx Functions

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

During a  call to an internal function, the interpreter creates a  new storage 

environment for various internal status data. The following settings are saved: the NUMERIC setting the TRACE setting the SIGNAL setting the current and previous environment address the current prompt string, defined with the OPTIONS prompt Although all previous variables remain accessible, this can be set to your needs with a  procedure call. If a  RETURN appears during the execution of the function, the function ends, all changes are discarded and the old settings are restored.

ARexx contains a  sizable library of functions that contribute to the 

scope of the language. They have been optimized and should be preferred in most situations, over an interpreted function.

External function libraries can be used to expand the scope of the 

ARexx language. A  function library contains one or several functions 

and a  special "QUERY" access point with which you determine whether the function is in a  library. Libraries have the same structure as normal
Amiga libraries (with the exception of their significance for ARexx). 

Before an external function can be used, the corresponding library must be placed in the list of available function libraries in the Rexx master process, with the built-in function ADDLIB(...).

You can also set a  search priority order in the function call if priority 

ratings are equal, the order of mention determines the search order.
During a  search procedure, the Rexx master procedure opens and loads 

each listed library, unless the library has already been called. The query function is called with the desired function names as arguments.
Normally, the entry point for this function is offset -30 other values can 

be set with ADDLIB(.„). (CAUTION: false values here lead to a  system crash.) If the function is not found, an error code is returned, the library is closed and the next library is searched. The offset of the function is returned if the search is successful. Then the function is accessed by the interpreter with the given arguments. It must return an error code (if successful, this is 0) and a  result string. The "rexxsupportlibrary" is included in ARexx and offers several
Amiga-specific functions. There are also several Public Domain libraries, 

such as a  math library, that makes more functions available.

External function environments are accessed by directing a  function 

message to the appropriate Public Message Port. The program can do whatever is internally necessary with the function call it must only answer the message at some time, sending back a  return code and a  result string. The resident ARexx process itself is an example of a  function environment it's always available via its message port "REXX", to which program calls can be sent. It's located in the library list of the Rexx master tasks and it takes a  priority of -60. If it receives a  function call, it looks for a file with the appropriate name, the search path is the same as for Rexx sub-programs: the current directory, then the REXX: device. Each directory is searched first with the current extension (see PARSE
SOURCE) and following that without the extension. By explicitly 

entering the search path within the function name, this process can be avoided. External programs are always started as separate processes. The calling program waits until its message is answered.

Built-in functions are internally set to DIGITS()=9 and FUZZ()=0 and are 

usually not influenced by settings in effect within the calling program.
Lengths must be entered as positive integers (including 0) and positions 

cannot be 0.

Many functions process both necessary and optional arguments. 

Optional arguments are printed in square parentheses in the syntax 

descriptions following. If you leave these arguments out, a  default setting is usually assumed. If a  function option can be selected with a  single key word, usually the first letter will suffice. (Upper or lowercase characters don't matter.) If an empty string appears in that place, a  default setting is used.

Some functions create and manipulate external DOS files. These files are 

called with a  logical filename that was determined when the file was opened. This name is sensitive to upper and lowercase spelling. An unlimited number of files can be open simultaneously. Luckily, they don't all have to be individually closed the interpreter handles the
"housekeeping" at the end of each program. 

I/O functions String functions 

CLOSE () ABBREVO 

EOF ( ) CENTER ( ) 

EXISTS ( ) CENTRE ( ) 

LINES ( ) COMPRESS ( ) 

OPEN ( ) COMPARE ( ) 

READCH ( ) COPIES ( ) 

READLN ( ) DATATYPE ( ) 

SEEK ( ) DELSTR ( ) 

WRITECH ( ) DELWORD ( ) 

WRITELN ( ) FIND ( ) 

INDEX ( ) 

INSERT ( ) 

LASTPOS ( ) 

LEFT ( ) 

LENGTH ( ) 

OVERLAY ( ) 

POSO 

REVERSE ( ) 

RIGHT ( ) 

SPACE ( ) 

STRIP ( ) 

SUBSTR ( ) 

SUBWORD ( ) 

TRANSLATE ( ) 

TRIM ( ) 

UPPER ( ) 

VERIFY ( ) 

WORD ( ) 

WORDINDEX ( ) 

WORDLENGTH ( ) 

WORDS ( ) 

XRANGE ( ) 

Bit manipulation 

BITAND ( ) 

BITCHG ( ) 

BITCLR ( ) 

BITCOMP ( ) 

BITOR ( ) 

BITSET ( ) 

BITTST ( ) 

BITXOR ( ) 

Numeric functions 

ABSO 

DIGITS ( ) 

FORMO 

FUZZ ( ) 

MAXO 

MINO 

RANDOM () 

RANDUO 

SIGNO 

TRUNC ( ) 

Conversions 

B2CO 

C2BO 

C2D() 

C2XO 

D2CO 

D2X() 

X2CO 

X2D() 

System functions 

ADDLIB ( ) 

ADDRESS ( ) 

ARGO 

DATE ( ) 

ERRORTEXT ( ) 

EXPORT ( ) 

FREESPACE ( ) 

GETCLIP ( ) 

GETSPACE ( ) 

HASHO 

IMPORT ( ) 

PRAGMA ( ) 

REMLIB ( ) 

SETCLIP ( ) 

SHOW ( ) 

SOURCELINE ( ) 

STORAGE ( ) 

SYMBOL ( ) 

TIME ( ) 

TRACE ( ) 

VALUE () 

ICLOSEQ 

Syntax: 

CLOSE (name) 

Closes the file with the given logical filename. The function 

returns 1  if the file close was successful otherwise (if the file was not open) a  0 is returned.

See also: 

Example: 

IEOFQ 

OPENO 

SAY CLOSE ( "Datadump " ) 

==> 1 

Syntax: EOF (name) 

Returns a  1 if the end of the given logical file has been 

reached otherwise a  0 is returned.

Example: if EOF ("Datadump") then CLOSE (" Datadump " ) 

IEXISTSQ 

Syntax: EXISTS (DOSf ilename) 

Determines if a  file with the given name exists. If successful, 

the function returns a  1 otherwise a  0 is returned. Path names can precede the filename.

Example: if EXISTS ("dhO:Trashcan/LoadWB") then say, 

"Look at the new Workbench 1.3, before you 

empty the trash .

ILINESQ 

Syntax: LINES (  [name] ) 

] 

Returns the number of lines listed in the entry buffer of the 

logical file "name" that mast belong to an interactive device like CON: or SER:. If "name" is omitted, the number of lines
"stdin" is returned. 

Example: say LINES ("Pipeline") 

say LINES 0

==> 3    (for example) 

==> 1    (for example) 

IQPENQ 

Syntax: OPEN(name, DOS-f ilename [ , "Append" I "Read" I "Write" ] ) 

Opens a  file for the given operation and gives it a  logical 

filename ("name") that can later be called. "DOSfilename" is the name of the file to be opened and this can include device and directory names.

APPEND Opens an existing file and sets the current 

position to the end of the file in order to add data.

See also: 

Example: 

READ Opens an existing file and sets the current 

position to the beginning of the file.

WRITE Opens a  new file if a  file of the same name 

exists, it is erased. To call these keywords, simply type the first letter. If nothing is entered, READ is assumed to be the function you are calling. When calling devices that do not support a
"seek" function, such as CON: or SER:, the method of file 

access does not matter. The result of the function is
Boolean. An unlimited number of files can be open 

simultaneously and they are all automatically closed when you leave the program.

CLOSEO, READxx(), WRITExx(), SEEK() 

Success =  OPENCDatastack" ,  "RAM:T/Testdata" ,  "W") 

Success =  OPEN ("Window", "CON:200/100/200/100/RexxConsole") 

IREADCHQ 

Syntax: 

READCH (name , number) 

Reads the "number" of characters in the open logical file 

"name". This function returns the characters it reads as the 

result string, or fewer than requested if the end of file is reached. If you are reading from an interactive device like
CON: or SER:, the function does not return anything until 

the necessary number of characters are in the buffer execution halts until then. Reading from non-interactive devices is useless and leads to a  false result.

Example: data =  READCH("Dataheap", 5) 

IREADLNQ 

Syntax: READLN ( Name ) 

See also: 

Example: 

ISEEKQ 

Reads characters from the logical file "name" until a  line 

feed (Hex OA) or the end of the file is encountered. The line feed itself is removed and the entire line is returned as the result. If you are reading an interactive device like CON: or
SER: the function does not return until a  complete line is in 

the buffer execution halts until then.

READCHO 

Entryline =  READLN ( "Window") 

] 

Syntax: SEEK(name, offset [ , "Begin" I "Current" I "End" ] ) 

Sets the current position for calls to the open logical file 

"name". "Offset" determines the distance in characters from 

the current position. Whole numbers (including negative numbers) are allowed. By entering the keyword "Begin the "offset" is set to the file beginning "End" sets it to file end. You can overstep the limits of the file, but this is not recommended, since it can lead to some confusion and sometimes to errors. The result of SEEK is the current position in reference to the beginning of the open file.
Using SEEK with interactive devices is senseless and has 

no effect.

Example: say SEEK("Datahaystack",5, "B") ==> 5 

filelength =  SEEK ("Datahay stack" , 0, "E")

IWRITECHQ ~l 

Syntax: WRITECH (name, string) 

Writes "string" to the logical file "name" and returns the 

number of characters written.

Example: say WRITECH ( "Datahaystack" , "needle" ) 

==> 6 

IWRITELNQ

Syntax: WRITELN (name , string) 

Writes "string" to the logical file "name" and adds a  line 

feed (Hex 0A). Returns the number of characters written, including the added line feed.

Example: 

say WRITELN ( "Window" , "The rose is red.")

=> 17 

7,5 ARexx String Functions 

IABBREVQ 

Syntax: ABBREV ( stringl , string2 [ , length] ) 

Returns a  1 if "string2" is a  permitted shorthand of "stringl
and is not shorter than "length". The default for "length" is the length of "string2". An empty character string is a  valid shorthand if nothing is specified in "length".

Example: say ABBREVC'Rosegarden", "Rose") ==> 1 

say ABBREV ( "Rosegarden" , "R" , 4 ) ==> 0 say ABBREVC'Rosegarden","") ==> 1

ICENTERQ or CENTREQ

Syntax: 

or:

CENTER (string, length [, pad] ) 

CENTRE (string, length [, pad] ) 

Returns a  character string of given length, in which the 

"string" is centered. Empty spaces to the left and right are 

replaced with spaces or pad (one character). If the "string is too long, each side is cut. To avoid errors, both American and English spelling is permitted.

Example: 

say CENTERf "Hello", 10) say CENTRE("0123456789",5) say CENTER ("TEST ",10, ">")

=> '    Hello 

=> '23456' 

=> '  »>TEST>» ' 

ICOMPRESSCT 

Syntax: 

Example: 

COMPRESS ( string [, list] ) 

If the second argument is omitted, this function removes all empty space from "string". In "list" one or several characters can be specified that are then removed instead of the spaces. say COMPRESS (  " Hey you ! " ) ==> ■  Heyyou ! ' say COMPRESS ("##AM++I#G+A++", •#+") ==> 'AMIGA'

ICOMPAREQ

Syntax: COMPARE ( stringl , string2 [ , pad] ) 

Returns the position of the first character of the two strings 

found not to be equivalent. If they agree, the result is 0. If necessary, a  shorter string is filled with empty space to the right or an end of file marker, if that's found in the other string.

Example: say compare ("Rose", "Ross") ==> 4 

say COMPARE ( "abc" , "abc+-", "+") ==> 5

ICOPIESQ 

Syntax: COPIES (string, number) 

Returns the "number" of repetitions of the "string
"Number" must be a  whole number or zero. 

Example: say copies ( " Rose " , 3 ) 

say COPIES (" Rose ",0)

=> 

=> 

' RoseRoseRose1 

IDATATYPEQ

Syntax: DATATYPE ( string [ , type ] ) 

If only one parameter is specified, the function tests whether the argument is a  valid ARexx number and returns
"NUM". Otherwise, the result is "CHAR". If one of the 

following keywords is entered for "type", a  test is executed and 1  is returned if "string" is that type otherwise a  0 is returned. A  null string only returns a  1 when tested for hexadecimal (X).

Available key words are: 

Alphanumeric 

A-Z, a-z and 0-9 

Binary 

valid binary string

Lowercase 

a-z

Mixed 

A-Z and a-z 

Numeric 

valid ARexx numbers

Symbol 

valid ARexx symbols

Upper 

A-

Whole 

whole numbers valid hexadecimal string

Example : s  ay datatype ("4711") = = > num 

say DATATYPE ( "Rose ", "L") ==> 0 say DATATYPEC52 6F 73 69"x,"X") ==> 1

IDELSTRQ | 

Syntax: DELSTR ( string, n  [ , length] ) 

Returns the "string", after "length" characters from position 

"n" have been removed. If "length" is omitted, the rest of 

the character string is removed.

Example: 

say DELSTR ("The Rose is red", 5, 5) ==> The is red

IDELWORDQ

H 

Syntax: DELWORD( string, n[ , length] ) 

Returns the "string", after "length" words have been 

removed from and including word number "n". If "length" is omitted, the rest of the string is removed. Empty space in front of the first word that is not deleted remains.

Example: 

say DELWORD("The Rose is red, 3,1) ==> The Rose red

IFINDQ 

Syntax: FIND (string, words) 

Searches for "words" in "string" and returns the word 

number of the first such agreement within "string". If
"words" is not in "string", the function returns a  0. 

Example: 

IINDEXQ 

say FINDC'The Rose is red", "Rose is")

==> 2 

Syntax: INDEX (string, pattern [, start] ) 

Searches for the first appearance of "pattern" in "string
from the beginning of the string or from the optional position "start". The function returns either the position number or 0, if "pattern" does not appear.

Example: 

Caution: 

See also: 

IINSERTQ 

say INDEXC'The Rose is a  Rose" , "Rose" ) ==> 5 say INDEX("The Rose is a  Rose" , "Rose" , 10) ==> 15 say INDEXC'The Rose is a  Rose" , "Carnation" ) ==> 0 This function is unique to ARexx and does not follow the typical order of arguments in Rexx syntax.

LASTPOS() is similar to POS(), except it has reversed 

arguments.

Syntax: INSERT ( sour ce.dest in [, [start] [, [length] [,pad] ] ] ) 

Adds "source" after the "start" position to the "destin
string. "Source" is expanded with the character "pad" to the given "length". The default value for "start" is 0, for
"length" the length of the "source", and the "pad" default is 

a space.

Example: say INSERT("123","abcde") ==> 123abcde 

say INSERT("123", "abcde",6,5, ".") ==> abode . 123 . .

ILASTPOSQ

Syntax: LASTPOS (pattern, string [, start] ) 

Searches "string" backward for the first appearance of 

"pattern" and returns the equivalent index (or 0, if no 

agreement occurs). Normally, the search begins at the last character. If you want the process to start somewhere else,
"start" indicates a  position counted from the beginning. 

Example: say LASTPOS (" Rose", "The Rose is a  Rose") ==> 15 

say LASTPOS ( "Rose" , "The Rose is a  Rose", 15) ==> 5 say LASTPOS ( "Carnation" , "The Rose is a  Rose") ==> 0

ILEFTQ 

Syntax: LEFT (string, length [ ,pad] ) 

Returns a  character string of the indicated "length", taken 

from the left side of the argument "string". If necessary,
"string" is cut off at the right end or lengthened with "pad". 

Default for "pad" is a  space character. 

Example: say LEFT ("The Rose is red", 8) 

say LEFT ("The Rose" , 10, " : " )

==> The Rose 

==> The Rose: : 

ILENGTHQ 

Syntax: LENGTH ( s t r ing ) 

Returns the length of "string". 

Example: say length ("The Rose") 

say LENGTHC")

==> 8 

==> 0 

IQVERLAYQ

Syntax: overlay (new, old [ , [ start ] t , [ length] [ , pad] ] ] ) 

Overlays the character string "old" with "new", beginning 

at the position "start". During the operation, "new" is cut to
"length" or lengthened with the "pad" character. The 

default value of "start" is 1, if the value is greater than the length of "old", the extra space is filled with "pad". The default setting for "length" is the length of "new". The standard pad character is a  space.

Example: 

say OVERLAY ("xx", "The Rose") say OVERLAY ("Rose", "The", 7, 6, "*")

==> xxe Rose 

==> The***Rose** 

fPOSQ

Syntax: POS (pattern, string! , start] ) 

Searches for the first appearance of "pattern" in "string
from the optional position "start". If no "start" is specified, it searches from the beginning of the file. It returns either the position at which the pattern is found or 0, if "pattern" does not occur at all.

Example: say POS(" Rose", "The Rose is a  Rose") ==> 5 

say POS ( "Rose" , "The Rose is a  Rose", 10) ==> 15 say POS ( "Carnation", "The Rose is a  Rose") ==> 0

IREVERSEQ

Syntax: REVERSE ( string) 

Reverses the order of characters in "string". 

Example: say reverse ( "esoR" ) ==> Rose 

| RIGHTQ I 

Syntax: RIGHT (string, length [ ,pad] ) 

Returns a  character string of "length" containing "string", 

starting from the right. "String" is cut off at the left side if necessary, or lengthened with the "pad" character. The default character for "pad" is a  space.

Example: say RIGHT ("The Rose is red", 3) ==> red 

say RIGHT("The Rose" ,10, " : ") ==> : :The Rose

ISPACEQ 

Syntax: SPACE ( string, n [  ,pad] ) 

If "string" contains words separated by spaces, SPACE returns a  character string with "n" spaces between the words. Empty spaces on the left and right are removed. The
"pad" character can define another character to use instead 

of the space character.

Example: say SPACE ("The Rose is red",l) 

say SPACE!" The Rose is red", 2) say SPACE(" The Rose is red", 1, " I ■)

==> The Rose is red 

==> The Rose is red 

==> The I  Rose I  is I  red 

Caution: This function does not work correctly if the second 

argument is omitted. The default value for "n" is 0  (it should be 1). Omitting the second argument of this feature has not been documented it cannot be recommended. Eventually this error will be corrected.

ISTRIPQ 

] 

Syntax: STRIP (string [ , [{"B" I "L" I "T"}] [.character] ] ) 

If an argument is given, the function removes preceding and trailing spaces from "string". If "L" (for "leading") or "T
(for trailing) is indicated, only one or the other is removed. 

The third argument is used to specify the character to be removed.

Example: say STRIP (" The Rose ") ==> 'The Rose' 

say STRIP (" The Rose ",*T") ==> '  The Rose' say STRIP("--The-Rose--",, "--) ==> 'The-Rose'

ISUBSTRQ 

Syntax: SUBSTR (string, start [, [length] [  ,pad] ]) 

Returns a  sub-string of "string", from the position "start", for 

"length" and filled at the right side with the character 

"pad". Default for "length" is the remaining length of 

"string", the default pad character is a  space. 

Example: say SUBSTR ( " abcde " , 3 ) ==> cde 

say SUBSTR ("123 45", 3, 2) ==> 34 say SUBSTR ( "abcde", 3, 5, "#") ==> cde##

ISUBWORDpT 

Syntax: SUBWORD ( string, start [ , length] ) 

Returns a  sub-string of "string", starting with the word at 

"start" and containing the number of words set in "length". 

The default setting is the remainder of "string". The result contains no leading or trailing spaces, only the space between the selected words is preserved.

Example: say SUBWORD("The Rose is red", 3) => is red 

say SUBWORD ("The Rose is red", 2, 2) => Rose is

ITRANSLATEQ

Syntax: 

TRANSLATE (string [, [output] [, [input] [,pad]]]) 

Replaces the characters in one string with the characters in 

the other and returns the new character string.
TRANSLATEO has the same effect as UPPER() with a 

single argument. Default for "input" is a  string with all characters from "00"x to "FF'x. Every character that occurs in "input" is replaced with the corresponding character in
"output". If there is no such character in "output" (if 

"output" is shorter than "input"), an empty space or the 

"pad" character is returned. Characters that do not occur in 

"input" remain the same the length of the "string" does not 

change. The tables can be as long as you want, but longer than 256 characters hardly makes sense, since within
"input" only the first appearance of a  character is noted. 

The final example shows the use of TRANSLATEO to rearrange a  character string in any order. "String determines the order and the second argument gives the specific working character string.

Example: 

say TRANSLATE ("The Rose") say TRANSLATE ( "xyz " , " wvu " " , " zyx" ) say TRANSLATE ("12345", "ab», "123", "-")

==> THE ROSE 

==> uvw 

==> ab-45 

say TRANSLATE ("312°, "abc", "123")

==> cab 

ITRIMQ 

Syntax: 

Example: 

IUPPERQ 

TRIM (string) 

Removes trailing spaces from "string". Equivalent to the 

STRIP(string,"T") function. 

say TRIM(" Rose ")

Rose' 

Syntax: UPPER (string) 

Converts "string" to capital letters. Equivalent to the 

TRANSLATE(string) function but a  little bit faster with 

short character strings.

Example: say UPPER ( " Rose " ) 

==> ROSE 

IVERIFYQ 

Syntax: VERIFY (string, table [ , [{MIN}] [, start] ]  ) 

Checks if "string" only contains characters in "table". If so a 

0 is returned otherwise the position of the first character 

that does not appear in "table" is returned. The third argument can be "match" (default is "nomatch") to reverse the logic of the verification. The VERIFY() function in
"match" mode returns the position of the first character that 

is contained in "table". Normally the search begins at the first character, but "start" can be used to define another entry point. If "string" is empty, or "start" is greater than the length of "string", the function always returns 0, regardless of the third argument.

Example: say VERIFY( "427" , "0123456789") ==> 0 

say VERIFY ("4p7ql", "0123456789") ==> 2 say VERIFY ("xx7 31", "0123456789", "M") ==> 3 say VERIFY ("4p7ql", "0123456789", ,3) ==> 4

IWORDQ 

Syntax: WORD ( s t  r ing , n ) 

Returns the "n"-th word in "string", or an empty string if 

"string" does not contain sufficient words. Equivalent to 

the SUBWORD(string,n,l) function.

Example: say WORD ("The Rose is red", 2) ==> Rose 

IWORDINDEXQ ~| 

Syntax: WORDINDEX( string, n) 

Returns the position of the first character of the "n"-th 

word in the "string", or 0  if there are insufficient words.

Example: say WORDlNDEXC'The Rose is red", 2) ==> 5 

IWORDLENGTHQ 1 

Syntax: WORDLENGTH( string, n) 

Returns the length of the "n"-th word in "string", or 0  if 

there are insufficient words in "string".

Example: say WORDLENGTHC'The Rose is red", 2) ==> 4 

IWORDSQ | 

Syntax: WORDS (string) 

Returns the number of words in "string". 

Example: say WORDS ("The Rose is red") ==> 4 

IXRANGEQ 1 

Syntax: XRANGE (  [start ] [ , end] ) 

Returns a  character string containing all characters with 

ASCII codes ranging from the "start" to the "end

character. Default for "start" is "00"x and for "end" it is
"FF'x. The order is always from high to low if "start" is 

higher than "end", the order begins again after "FF'x at
"00"x and continues until the "end" value. 

Example: say c2x(xrange() ) ==> 000102 ... fdfeff 

say XRANGEC'A", "F" ) ==> ABCDEF say C2X(XRANGE(, "05"x) )   ==> 000102030405

## 7.6 Bit Manipulation in ARexx

[BITANDQ 

Syntax: 

BITAND ( stringl [ , [ string2 ] [ , pad] ] ) 

A logical AND function is performed with the two strings. The result has the length of the longer operand. Instead of breaking off the operation at the end of the shorter operand and appending the rest of the longer operand unchanged, the shorter operand is filled up to the right with
"20"x (the space character) and the concatenation AND 

performed on the entire length of the string. The behavior described in the documentation can only be guaranteed if
"pad" is always specified as "FF'x. The shorter operand is 

then filled with this value before the operation begins. If the second operand is omitted, "20"x is always filled in or the end of file marker is added.

Example: 

IBITCHGQ 

say C2B(BITAND("00001111nb, "01010101"b))==> 00000101 say C2x ( BITAND ("FF"x, "FFFF"x) ==> FF20 say C2x(BITAND("00"x, "AAAA"x, "FF"x) ==> 00AA say BITAND ("Rose", , "11011111"b) ==> ROSE

Syntax: 

BITCHG ( string , bi t ) 

Inverts the given bit in "string". Bit 0  is the lowest value bit 

of the characters on the right side of "string".

Example: 

IBITCLRQ 

say C2B (BITCHG ("00001111"b, 5)) ==> 00101111

Syntax: 

BITCLR ( string , bi t ) 

Deletes the given bit in "string". Bit 0  is the lowest value bit 

on the right side of "string".

Example: say C2B(BITCLR("00001111"b,2) ) ==> 00001101 

IBITCOMPQ

Syntax: BITCOMP(stringl, string2 [  ,pad] ) 

Compares the bit patterns of the two strings, from bit 

number 0  going from right to left. The result is the number of first bits in which the strings are different, or -1 if they are equal. The shorter string is filled, before the operation at the left side with the "pad" character (the default "pad" is a space).

Example: say BlTCOMP( "FF" , "FFFF"x) ==> 8 

say BITCOMPC'FF", "20FF"x) ==> -1

1BITORQ 

Syntax: BITOR( string 1 [ , [string2] [,pad]]) 

A logical OR operation is performed on the two strings. The result is the length of the longer operand. Instead of breaking off the operation at the end of the shorter operand and adding the rest of the longer operand unchanged, the shorter operand is filled with "20"x (the space character) and the OR connection is carried out over the entire length of the string. The behavior that is described in the documentation is only possible if the "pad is always specified as "00"x. The shorter operand is then filled up with this value before the logical operation takes place. If the second operand is omitted, it's filled with "20"x or the end of file marker.

Example: say C2B(BITORC,00001111"b, "OlOlOlOl-b) ) ==> 01011111 

say C2x(BITOR("FF"x, °0000"x) ==> FF20 say C2x(BITOR("00"x, "AAAA"x, "FF"x) ==> AAFF say BITOR("Rose°, , "00100000"b) ==> rose

IBITSETQ 

Z3 

Syntax: BITSET (string, bit) 

Sets a  marker for the given bit in "string". Bit 0  is the lowest 

value bit of the characters from the right end of the "string".

Example: say C2B(BITSET("00001111"b, 5) ) 

=> 00101111 

IBITTSTQ 

Syntax: BITTST (string, bit) 

Returns the given bit of "string". Bit 0  is the lowest value 

bit of the characters from the right end of the "string".

Example: say BITTST (" 00001111 "b, 5) 

IBITXORQ 

==> 0 

Syntax: BlTXOR(stringl [ , [string2] [  ,pad] ] ) 

Performs a  logical exclusive OR operation on the two 

strings. The result is the length of the longer operand.
Instead of breaking off the operation at the end of the 

shorter operand and adding the rest of the longer operand unchanged, the shorter operand is filled with "20"x (the space character) on the right side, and the XOR operation is performed on the entire length. The documented behavior can only be achieved if the "pad" is always "00"x. The shorter operand is then filled with this value before the operation starts. If the second operand is omitted, it is always filled with "20"x or the end of file marker.

Example: say C2B(BITXOR("00001111"b, "01010101"b))==> 01011010 

say C2x(BITXOR("FF°x, "0000"x) ==> FF20 say C2x(BITXOR("FF"x, "0000"x, "00"x) ==> FF00 say BITXOR("Rose", , "OOlOOOOO-b) ==> rOSE

## 7.7 Numeric Functions

[ABSQ

Syntax: 

Example: 

IDIGITSQ 

Syntax: 

Example: 

IFORMQ 

Syntax: 

Example: 

IFUZZQ 

Syntax: 

Example: 

IMAXQ 

ABS 

( number ) 

Returns the absolute value of 

"number". 

say

ABS (-345) 

==> 345 

say

ABS (4.32) 

==> 4.32 

DIGITS () 

Returns the current NUMERIC DIGITS setting. 

say DIGITS () ==> 9

FORM ( ) 

Returns the current NUMERIC FORM setting. 

say FORMO ==> SCIENTIFIC

FUZZ() 

Returns the current NUMERIC FUZZ setting. 

say FUZZO ==> 0

Syntax: MAX (number , number [ , number] .  . .  ) 

Returns the largest of the given numbers. 

Example: say MAX (3, 2, 7, 5) 

say MAX(-3, -1,-8,-1)

==> 7 

==> -1 

IMINQ 

Syntax: 

Example: 

MIN (number, number [ , number] . . . ) 

Returns the smallest of the given numbers. 

say MIN (3 ,2, 7, 5) say MIN(-3, -1,-8,-1)

==> 2 

==> -8 

IRANDOMQ

Syntax: RANDOM (  [min] [ , [max] [ , [startvalue] ]  ] ) 

Returns pseudo-random integer values between "min" and 

"max". Default values are 0  and 999. The interval between 

"min" and "max" cannot be larger than 1000. The third 

value can be a  different start value, in order to achieve a repetitive sequence. This start value should be specified at the first call and can be any number. The results of later calls to RANDOM() (without a  start value) are repeated, if the random number generator is initialized to the same start value again. If no start value is specified, the random number generator is initialized with the system time at the first call. The start value is not secured for all routine calls, but rather globally, for an entire program.

Example: say random (1,49) 

say RANDOM (, ,4711)

=> 17 ? 

=> 365 ? 

| RAN DUO 

Syntax: RANDU (  [ startvalue ] ) 

Returns evenly distributed pseudo-random numbers 

between 0  and 1. The number of places after the decimal point depends on the current NUMERIC DIGITS setting.
Normally, the random number generator is initialized with 

the system time at the first call. By entering the optional
"start value", the random number generator can be moved 

to a  defined starting condition, in order to achieve repetitive pseudo-random sequences.

Example: 

ISIGNQ 

say RANDUO

==> 0.018327461 ? 

Syntax: S I GN ( numbe r ) 

Resembles the mathematic "sign" function. If "number" is 

negative, SIGN returns a  -1, if the number is a  0, it returns a
0, and if "number" is positive, it returns a  1. 

Example: 

Caution: 

say SIGN (0.1) say SIGN (0.0) say SIGN (-5)

==> 1 

==> 0 

==> -1 

ITRUNCQ 

The SIGN() function should round the number according to the evaluation of the NUMERIC DIGITS setting. This is not implemented, so insignificant fractions are never reported as
"0". 

J 

Syntax: TRUNC (number [ , places ]  ) 

Returns the whole number portion of "number", followed 

by the desired number of places after the decimal, which is usually none. It does not round to the whole number. If needed, the number is filled with zeros. The result is never an exponential notation, so that "number" cannot require more places than are set in NUMERIC DIGITS. If necessary, the number is rounded according to the number of decimal places first.

Example: say trunc (564. 73294) 

say TRUNC (564. 73294, 3) say TRUNC (564. 7, 3)

==> 564 

==> 564.732 

==> 564.700 

## 7.8 Conversion Functions in ARexx

[B2UQ

Syntax: B2C (string) 

Converts a  string of binary symbols (0 and l's) to the 

corresponding ASCII character string. Empty spaces are allowed in "string" but only at the byte limits, every 8th digit.

Example: 

IC2BQ 

IC2DQ 

say B2C( "01000001")

=> A 

Syntax: C2B (string) 

Converts an ASCII symbol string to an equivalent binary 

string.

Example: say C2B("Rose")==>01010010011011110111001101100101 

] 

Syntax: C2D ( string [  ,n] ) 

Converts "string" from a  symbolic representation to the 

corresponding decimal number. The maximum "string length is 4  bytes (32 bits). If "n" is given, the binary value of "string" is treated as a  pair of length "n" bytes and transformed into a  corresponding whole number (with a prefix if necessary). The "string" is cut off at the left side or filled with zeros if it's not the right length. No prefix evaluation takes place.

Example: say C2D("0A"x) 

say C2D("Rose") say C2D("FFFF"x,2)

==> 10 

==> 1383035749 

==> -1 

|C2X?T 

Syntax: 

C2X (string) 

Converts "string" from symbolic representation to the 

corresponding hexadecimal number. The result contains capital letters for the numbers A-F and no empty spaces.

Example: 

say C2X("Rose") say C2x("0A"x)

==> 526F7365 

==> OA 

ID2C0 

Syntax: 

D2C (numberl [ , bytes] ) 

Converts decimal numbers into equivalent ASCII 

characters. If "bytes" is specified, the result takes that length it's cut off at the left side or filled with "00"x on the right if necessary. Negative values, not otherwise permitted, can be expressed as a  pair.

Example: 

say D2C(65) say C2X(D2C(-1,4) )

==> A 

==> FFFFFFFF 

ID2X0 | 

Syntax: D2X (numberl [ , nibbles ] ) 

Converts whole decimal numbers to the corresponding 

hexadecimal notation. If "nibbles" is specified, negative numbers are converted into a  number pair. The result has the corresponding number of places and, if necessary, is cut off at the left side or filled in with O's at the right. For the numbers A-F it uses capital letters and no empty space is added.

Example: 

say D2X(10)

==> A 

say D2X(10,2)

==> OA 

say D2X(-1,5)

==> FFFFF 

1X2CQ 

Syntax: X2C(Xstring) 

Converts a  string from hexadecimal notation to equivalent 

ASCII string. If necessary, a  0 is added to the left, in order 

to arrive at an even number of nibbles. At the byte limits, empty spaces can be added to improve readability. They are ignored by the program.

Example: 

IX2DQ 

say X2CC4D 4E")

==> MN 

Syntax: X2D(Xstring[ , nibbles ] ) 

Converts a  string from hexadecimal notation to the 

corresponding decimal number. If necessary, a  single 0  is added on the left side, in order to arrive at an even number of nibbles. Empty spaces can be added at the byte limits to improve readability. They are ignored by the program. A maximum of 4  bytes (8 nibbles) are allowed. The
NUMERIC DIGITS setting has no influence on this 

function.

Normally, X2D() returns positive numbers. If any value is 

entered for "nibbles", "Xstring" is assumed to be a  pair and numbers with prefix signs are returned. If the number of nibbles in "Xstring" is not correct, it is simply filled with
"0"x to the left or cut off, so that no prefix expansion takes 

place.

Example: say x2D("0D" ) 

say X2D("FFFF") say X2D("FFFF° ,4) say X2D("FFFF",6)

==> 13 

==> 65535 

==> -1 

==> 65535 

IADDLIBQ 

] 

Syntax: ADDLIB (name, priority [ , of f  set, version] ) 

Adds a  function library or an external function 

environment to the library list that is managed by the Rexx
Master process. "Name" is either the full name of a  function 

library that is located on the logical device LIBS:, or the name of a  Public Message Port that belongs to a  function environment. "Priority" determines the search order for called functions and must be an integer between -100 and
100. Usually 0  is useful. 

The arguments "offset" and "version" refer only to libraries and are necessary to open one. "Offset" indicates the entry point for the query function of the library (usually -30) and
"version" takes a  certain version number the library must 

minimally achieve (usually 0). The function returns a  Boolean result if everything is in order. This does not mean that the library is available and the program does not try to load it until the first command occurs. An equivalent Message Port is also not located until later.

Example: if ADDLIB ("rexxsupport. library " ,0, -30,0) then 

say "OK!

IADDRESSQ

J 

Syntax: ADDRESS ( ) 

Returns the name of the message port to which external 

commands can be sent. The function SHOW() can test if the port is available.

Example: say address () 

=> rexx 

IARGQ 

Syntax: ARG (  [ number [ , { " E " I  " O " } ]  ] ) 

Without arguments, ARG() returns the number of arguments that were passed to a  program or a  sub-routine. If a  "number" is entered, the argument string is returned or, if that is not available, a  null string. If one of the options for "Exists" or "Omitted" is left out, the argument is tested for the other and a  Boolean result is returned.

Example: I* Arguments given: ("Rose",, -5) */ 

say ARG() ==> 3 say ARG (3) ==> -5 say ARG (2, "E") ==> 0

IDATEQ 

Syntax: DATE ( option [ , date [ , { 1 1 S } ]  ] ) 

Returns the current system date in the desired form. (A 

"normal" format is used if the function is called without an 

argument.) Supported options are:

Base date: 

Century: 

Days: 

European: 

Internal: 

Julian: 

Month: 

Normal: 

Ordered: 

Sorted: 

USA: 

Weekday: 

Days since January 1, 0001 

Days since the beginning of the century 

Days since the beginning of the year 

Date in the form DD/MM/YY 

System days (since January 1, 1978) 

Date in the form YYDDD 

Month in English (upper and lowercase letters) 

Date in the form DD MMM YYYY 

Date in the form YY/MM/DD 

Date in the form YYYYMMDD 

Date in the form MM/DD/YY 

The weekday in English (upper and lowercase) A specific date can be requested. To do this, the argument
"date" is given as system days or as a  "sorted date" in the 

form YYYYMMDD in the latter case a  third argument "S
(for "sorted") must be supplied. 

Example: 

say DATE ( ) say DATEC'W") say DATE ( " W " , DATE ( " I " ) +3 ) say DATE ("J", 19800517, "S")

==> 22 Jan 1991 

==> Tuesday 

==> Friday 

Caution: 

In VI. 14 no date before system date 0, January 1  1978 can be entered in this manner.

IerrortexTq

Syntax: ERRORTEXT (number) 

Returns an error message for the given ARexx error 

number. If "number" is not a  valid error number, the message "Undiagnosed internal error" is returned.
Unfortunately, ARexx doesn't maintain the Rexx standard 

for error messages, but uses its own numbers.

Example: say ERR0RTEXT(15) ==> Function not found 

IEXPORTQ 

Syntax: EXPORT(address[, [string] [, [length] [ ,padpattern] ] ) ) 

Copies the given data from "string" to the 4-byte "address
in the storage space that must have previously been reserved with GETSPACE(). "Length" determines the maximum number of characters to be copied, "padpattern
(one byte) is used to fill up the string if it isn't long enough. 

The default value is "00"x. You can use this function to enter an address and length in order to delete from the storage area, or to initialize with "padpattern". The returned value is the number of characters actually copied.

Caution: This function can be used to overwrite any storage areas, 

which can lead to fatal error. Never use EXPORT() with a reserved stack unless you know exactly what you are doing. Secure your program scripts against the common error of overstepping reserved space. Also, during copy operations, task-switching is interrupted. With large amounts of data (if possible) copy several sub-strings, so multitasking operations aren't interrupted for too long.

Example: say EXPORT("0024 DDB0"x, "The Rose is red") ==> 15 

say EXPORT("0006 0000"x, , 640, *FF"x) ==> 640

IFREESPACEQ 1 

Syntax: FREESPACE (  [address , length] ) 

Returns the storage area of the Rexx master procedure. If 

you specify the 4-byte address with which the block was designated using GETSPACE() earlier, its length (a multiple of 16) is returned. The function FREESPACE() with false entries (and sometimes, in VI. 14, even correct ones) quickly allows the computer to get caught on the problem or run through endless loops. The returned value is not a  Boolean result, as the documentation states, instead it's the size of the free space under the control of the Rexx master procedure (and that result often contains errors). A  call without arguments returns the true size of the storage space being managed by the Rexx master procedure. Since the storage area is automatically returned after the program ends, calling FREESPACE() is only necessary when you may run out of space.

Example: say FREESPACE("0002fa44"x,32) ==> 848 ? 

IGETCLIPQ 1 

Syntax: GETCLlP(name) 

Searches the Clip list for "name" and returns the 

corresponding character string. Upper and lowercase spelling are differentiated. If there is no entry, an empty string is returned.

See also: SETCLIP() 

Example: I* "DaData" contains "The Rose is flighty" */ 

say GETCLIPC DaData") ==> The Rose is flighty

IgetspaCeQ

Syntax: GETSPACE ( length) 

IHASHQ 

Syntax: 

Example: 

Reserves a  stack of "length", managed by the Rexx master 

procedure. It returns a  4-byte address, indicating the beginning of the reserved storage area, which is not deleted. "Length" is rounded up to the next multiple of 16.

Stacks reserved with GETSPACE() are automatically 

returned to the Rexx master procedure at the end of the program, so external programs should not access this storage area. In the "rexxsupportlibrary", a  function called
ALLOCMEM() requests storage space directly from the 

system it can be necessary in such cases.

Example: say C2X (getspace (64)) 

==> 002937F8 ? 

HASH (string) 

Returns the hash value of "string" as a  decimal number. The 

hash value is the lowest byte of the sum of all ASCII values contained in the string. say HASH ("A") say HASHC'AAAA")

==> 65 

==> 4 

IIMPORTQ 

: 

Syntax: IMPORT (address [ , length] ) 

Reads data from the given 4-byte storage address. If no 

length is specified, the process ends at the first "00"x, which is practical for reading C  strings.

Example: 

! practical for reading C  strings. 

say IMPORT ("00FC0038"x, 9) ==> Amiga ROM jPRAGMAQ

Syntax: PRAGMA ( opt i on [ , va lue ]  ) 

Various system-specific parameters of your own program 

can be determined. The options are:

Directory: A  new current directory can be set for the running 

procedure. The function returns the full path name of the previously current directory it can be saved in order to restore the old settings later. "Value" must be a  valid Amiga
DOS path name or be omitted. In the latter case, only the 

current setting is returned. If the path is not valid or not given, a  null string is returned.

Id: Returns the 4-byte pointer to the Task Control Block 

structure of the current program as an 8-byte hexadecimal string. Using this address, you can create independent file or port names specific to the appropriate program call.

Priority: A  new task priority can be given to the procedure with this 

option. The function then returns the previous priority setting. Its "value" must be a  whole number between -128 and 127 no ARexx program should run with a  higher priority than the ARexx main program, which is usually set at 4. "Value" must always be specified, which means that a priority cannot be queried without possibly changing it. If no area check is taking place, the lowest byte of the given number is used.

Window: This option changes the window pointer of the task control 

block in the running program. For "value", valid keywords are "Work Bench" and "Null". By entering "null", you can prevent requests from being sent the Workbench by DOS calls (such as Insert Volume ... etc.). At this point, only
"null" is recognized all others (including an omitted second 

argument) lead to the default setting "WorkBench". The function also always returns a  1 to indicate successful completion.

"*". 

Defines the given logical name "value" as the current ("*") 

console handler. This means you can open two data strings in one window. The result is a  Boolean result.

Example: 

say PRAGMA ("P", -2) say PRAGMAC'D") say PRAGMAC'D" , "dfO:c) say PRAGMA ("I") say PRAGMA ( " W" , "Null " ) say PRAGMA (»*«," STDIN" )

=> 0 

=> Boot_2.X: ? 

=> ARexxl.14: ? 

=> 0028FE08 ? 

=> 1 

=> 1 

IREMLIBQ 

Syntax: REML I B ( name ) 

Removes an entry with the given name from the library list 

managed by the ARexx master procedure. The function returns a  1 if the name is found and removed otherwise it returns a  0. It does not differentiate between libraries and external function environments.

See also: ADDLEB() 

Example: REMLlBC'rexxsupport. library") ==> 1 

ISETCLIPQ 1 

Syntax: 

Example: 

SETCLIP (name [ , value ] ) 

Adds a  "value" (any string) "name" to the Clip list being 

managed by the ARexx master procedure. If an entry already exists under that name, the contents are updated to the new value or, if no "value" is given, the entire entry is deleted. The result is a  Boolean result. say SETCLIP ("Textl", "No, no roses") ==> 1 say SETCLIP ("Textl") ==> \

ISHOWQ 

Syntax: SHOW(option[ , [name] [, divider] ]  ) 

Returns the contents of various lists being managed or 

used by the ARexx master procedure. "Option" refers to one of the following key words:

Clip: Names in the Clip list. 

Files: List of open logical filenames. 

Internal: Internal port list. 

Libraries: External library and function environment list. 

Ports: List of Public Message Ports, managed by EXEC. An 

unnamed port is indicated by a  question mark. If no "name" is specified, the function returns a  string with entries in the given list, separated by a  space or the optional
"divider". If "name" is specified, the corresponding list is 

searched for the entry and a  Boolean result shows if it was found.

Example : say show (" p  ",,"" ) 

say SHOW ( " C " , " Text 1 " )

==>REXX  DMouse  Workbench 

==> 1 

ISOURCELINEQ 

Syntax: SOURCELINE (  [ 1  ine ]  ) 

Returns a  string representing the given line of the current 

program. If "line" is omitted, the number of lines in the program is returned. The function can be used to display comment line", used as a  help feature.

Example: say sourceline ( ) ==> 35 ? 

say SOURCELINE ( 1 ) ==> /* A  test program */ ?

ISTORAGEft 

] 

Syntax: STORAGE ( [address] [ , [string] [ , length [ , pad] ] ] ) 

Writes "string", starting at the given address, directly to the 

main storage area. If "length" is specified, the actual length of the string is disregarded and only that number of bytes written in this case the "string" is either shortened on the right or padded with empty space (or the given "pad"). The result string is the previous contents of the affected stack that can be saved and restored later.

Example: 

If the function is entered without arguments, it returns the total available storage space. say STORAGE () ==>1846536 ? before =  STORAGE( "00040000"x, after)

ISYMBOLQ 

Syntax: 

SYMBOL (name) 

Checks if the argument is a  valid ARexx symbol. If not, it 

returns the string "BAD". If it is a  valid but un-initialized symbol, the result is "LIT", and if the symbol has already been assigned a  value, the answer is "VAR".

Example: 

say SYMBOL ("$%&") say SYMBOL ("before") say SYMBOL ( "when" )

==> BAD 

==> VAR 

==> LIT 

ITIMEQ 

Syntax: TIME ( [option] ) 

Without an optional keyword, TIME returns the current system time in 24-hour format, in the form "hh:mm:ss".
Possible options are: 

Civil: American 12-hour format in the form"[h]h:mmxx", where 

"xx" is either "am" or "pm". The hour does not receive a 

Elapsed: 

Hours: 

Minutes: 

leading zero, and the minute is the current minute, not (as is usually the case) the next minute. The number of seconds and hundredths of a  second that have passed since an initial call to the internal timer with
"Elapsed" or "Reset". 

The number of hours since midnight without a  leading zero. The number of minutes since midnight without a  leading zero.

Normal: Returns the default setting (the same result as calling the 

function without an argument).

Reset: Returns the number of seconds and hundredths of a 

second since an initial query to the internal timer using
"Elapsed" or the last "Reset", and simultaneously resets the 

timer.

Seconds: The number of seconds since midnight without leading 

zeros.

Example: 

say TIMEO say TIMEC'R") say TIME("E")

=> 18:35:22 ? 

=> 0    ? 

=> 2.12 ? 

ITRACEQ 

Syntax: TRACE (option) 

With no argument, this function returns the current TRACE setting. All valid TRACE keywords can be specified as options (numbers are not allowed, but "?" and "!" are). The
TRACE() function changes the TRACE mode, even during 

interactive tracings, when all other TRACE commands are ignored. The result is always the last setting that can thereby be saved and restored later.

Example: say trace 0 

==> N 

IVALUEQ 

Syntax: VALUE ( name ) 

Returns the contents of the given ARexx symbol, which 

must be a  valid symbol. This function is used when the variable name itself is a  variable, as a  whole or partially.

Example: /* Situation: DROP q5, 155=8 n=5 Rose="n"*/ 

say VALUE ("Rose") ==> n say VALUE (Rose) ==> 5 say VALUE ("q"n) ==> Q5 say VALUE("l"n| In) ==> 8

## 8.1 Parsing Strings with Templates

8. Special Features 

Rexx contains several powerful special features that may be unfamiliar to 

users of other programming languages. The most important ones, parsing data and tracing programs, are discussed here.

The ARexx instruction PARSE (and its two abbreviations ARG and
PULL) split an entry according to a  "template" and direct the results to 

variables. This feature is especially useful when you are using ARexx as a script language on the Amiga, since many commands that were not conceived for automatic processing deliver cryptic return values that do not conform to any formatting standards. The CLI script language offers some help in parsing argument lines (with ".") and some command line syntheses (using "CLIs LFORMAT"), but both of them fail difficult parsing tasks. The previous description of PARSE is a  short explanation of its most important capabilities. The following is a  complete process description: A template consists of two elements, symbols which are assigned values during the operation, and markers to indicate a  position within the source string. Valid markers are: strings, operators such as "+","-" and "=", closed parentheses, and commas. Using the template, a  beginning and end position is determined within the source string for every target symbol. The corresponding portion of the string is then assigned to the symbol. There are three types of markers: "absolute", which indicate an exact position in the source string, "relative", which indicate a  positive or negative offset from the present position, and "pattern" which indicates a position by comparing the given pattern to the source string. In a template, the target of the sub-string is a  variable symbol or a  specific goal (or a  period) the corresponding value is not assigned to the target.
Variables in a  template always receive a  new value, even if the source 

data do not contain enough words. Any remaining variables are set to 0.

8. Special Features 

Valid template elements 

symbols: A  symbol may be a  target or a  marker. If it immediately follows one of the valid operators ("+","-" or "="), its value (which in this case must be an integer) is interpreted as a  relative or an absolute position. If a symbol appears in parentheses, its value is a  comparison pattern. If neither condition is true, it must be a  variable, to which a  value is assigned. strings: A  string is always a  comparison pattern. parentheses: If a  symbol appears in parentheses, it is a  comparison pattern. Normally, a  variable symbol is used a  constant value is easier to display within a  string. operators: The characters "+","-" and "=", followed by a  symbol

(which must represent an integer), indicate index 

positions in the source string. "+" and "-" indicate relative positions, "=" indicates an absolute position. commas: A  comma separates multiple templates. If several templates follow one another, the interpreter looks for a new source string. In some source options, it's identical to the last. With the options ARG, EXTERNAL and
PULL, a  new string is created the same is true for the 

option VAR, if the contents of the variables has changed. periods: A  period serves as a  dummy value and operates as a target for a  sub-string which is to be discarded. Each character in the source string has an index number, from 1, for the first character, to the length of the string plus 1  (the end of the string). If the limit is exceeded, the current position is set at the limit. A  sub-string, defined by two indices, always contains the character of the first index and continues up to the second. The indices 3  and 8  would define a  sub- string of the characters 3  to 7. If both indices are equal, or the second is smaller, the remainder of the source string is defined by the pair. The command:

PARSE value "bla bla bla" WITH 1  all 1  Wordl Word2 Word3 

assigns the entire string to the variable "all", after which each word is parsed into equivalent variables. When a  pattern is compared to the source string, the position of the first character matching the pattern is the new index and the pattern is removed from the source string. This means that the source string is altered in the process of this operation. The evaluation goes from left to right in the template. At the beginning, the source string index is set to 1. Whenever a  marker appears in the template, its position becomes the current one. Whenever a  target is found, the program searches for the next object in order to determine the length of the sub-string the target expects. If the next object is a  target, the source string is divided into words. The process does not end until the template has been completely evaluated. If the source string is fully parsed, remaining targets receive null strings.

### 8.1.1 Examples of Parsing

All of the following examples were given the source string.

"One believes, one knows, but know: one believes.

Please notice the double space after the first comma and after "but". 

Comparison patterns 

If there is a  string in the template, the source string is scanned from left to right (after the first appearance of the sequence of characters). If it's found, it's removed from the source, and the index is placed on the first character after the sequence. If there is no matching string, the index is placed behind the last character of the source. Given the following template:

Tl " , " T2 " , " REST 

the source string would be parsed as follows:

Tl =  "One believes

T2 =  " one knows

REST =  " but know: one believes.

The following template shows what happens if there is no agreement:

8. Special Features 

Tl " , "    T2 " , " T3 " ," REST 

because no third comma is found, T3 receives the rest of the string and
REST receives nothing. 

Tl =  "One believes

T2 =  " one knows

T3 =  ■ but know: one believes.

REST =

If REST previously contained another value, it's now lost, since the variable received an empty string. Comparison patterns may be variable. In this case, the corresponding symbol must be indicated with closed parentheses. (In ARexx, this method always forces an analysis of a symbol, which makes the key word "VALUE" unnecessary in some situations, but not with the PARSE command). The corresponding variable can be previously defined (further to the left) in the same template. This is a  possible application: command =  "\SEARCH\Typignmistake\CW parse var command divid 2  instruction (divid) string (divid) option In this case, the first character of "command" is the separator used to parse the rest of the string.

Parsing into words 

If several targets follow, the source string is parsed into words. (Or it could be a  sub-string of the source, if it appears before or after the target patterns have been specified). Each target from left to right is assigned a word. Empty space between words is dropped. If several words are left over, the last target receives the remainder, including the empty space contained in it. For example:

Wl W2 W3 REST " :

leads to the result:

Wl =  "One

W2 =  "believes,

W3 =  "one

REST =  " knows, but know

As you can see, the remainder of the string contains the leading space in the source. (ARexx does not behave entirely according to Rexx specifications here: the space should be removed.) Please note that a template of the form:

Wl -    " W2 "    " W3 "    " REST ■ :

which refers to the empty space as a  comparison pattern, leads to a different result:

Wl =  "One

W2 =  "believes,

W3 =  ■• 

REST =  "one knows, but know

As expected, Wl received the first word, W2 the second word, between the first two spaces, but what about W3? In this example, it's assigned the entire string between the second and third empty spaces. A  null string was correctly assigned, since they immediately follow one another. Since the comparison removes the empty space in front of "one", "REST no longer contains a  leading space. A period has special meaning in parsing words: it works as a  target, just as a  variable symbol, but the value assigned to it is discarded. The period is used to ignore unnecessary words in the source string. The template:

. .     . W4 . 

would extract only the fourth word from the source string, in this case,
"knows," and assign it to the variable W4. 

Parsing by position 

In this process, the source string is cut up at certain character positions. The appropriate index values are entered as whole numbers:

Tl 10 T2 20 T3 

returns from the original example string:

8. Special Features 

Tl =  "One believ

T2 =  "es, one

T3 =  "knows, but know: one believes.

The target Tl receives the characters 1  to 9, T2 the characters from 10 to
19 and T3 is assigned the rest. 

This example used absolute positions. Use prefix operators, ("+" or "-") to move the index position relative to the last position. For example: numbers =  "1234567890 parse var numbers 2  Zl +4 -1 Z2 -2 Z3 +5 leads to the following result:

Zl 

= "2345

Z2 

= "567890

Z3 

= "34567

First, Zl receives four characters of input, starting from the second place. 

Then, the index is moved back by one character ("-1"), and the digit "5 reappears in Z2. From "-2", the absolute position 3  is calculated. The second index for Z2 is smaller than the first. This means that the rest of the source string is assigned to Z2. Finally, the Z3 target receives five characters ("+5") starting from the last position (3).

Using numeric position indicators, whether they are relative or absolute, 

you can read parts of the source string several times, if necessary. The following command string is also possible: parse var numbers Zl 1  Z2 1  Z3 This command assigns the full contents of "numbers" to each of the three different variables. A numeric position indicator can be a  variable: for a  relative position, add a "+" or "-" in front of the variable symbol. To indicate an absolute position place an equal sign "=" in the same place this differentiates them from target symbols.

Combined parsing methods 

If a  comparison pattern is directly followed by a  relative position indicator, you achieve a  special effect. The pattern, if found, is not removed from the source string. The current position remains set at the first character of the pattern string.

## 8.2 Error Trapping with TRACE

What would be the advantage of using an interpreted language if there 

were no TRACE? A  programmer can investigate the events during program execution it makes the often difficult search for errors much easier, since even well-hidden, minor, logical, program errors become apparent. Rexx offers substantial support for this function. During
TRACE, the interpreter displays certain program parts during their 

execution. A  line number, the source text and additional information is displayed. Interpreter behavior is set with trace options, that determine which program parts should be displayed. Two flags control command suppression (!) and interactive tracing (?).

Because it uses "signals", the ARexx program can recognize certain 

synchronic events (i.e., a  "syntax error") or asynchronic events (such as a
"halt" request). Using these features, most error conditions can be 

handled by the program and program aborts can often be prevented.

### 8.2.1 Trace Options

The following modes are available:

ALL Displays all clauses before execution. 

BACKGROUND 

Similar to OFF, except the tracing cannot be externally 

enabled with the "TS" command.

COMMANDS Displays all command clauses before they are passed to 

the external environment. Also, displays return codes not equal to 0.

ERRORS Displays commands that pass a  return code not equal to 

0 after execution. 

INTERMEDIATES 

Displays all clauses, sub-totals (including variable 

contents), a  final form of concatenated symbols, and results of function calls.

8. Special Features 

LABELS 

NORMAL 

OFF 

RESULTS 

SCAN 

Displays all jump markers. 

Displays commands with return codes that exceed the 

current failure level after their execution, and presents an error message. This is the default setting.

Switches all tracing off. 

Displays all clauses before their execution and presents 

the result of every expression. Values assigned to variables with ARG, PARSE or PULL are also displayed.

Displays all clauses and checks them for errors, but does 

not actually execute them. This mode can be set on with the TRACE command or the internal function TRACE(). It can be engaged at appropriate spots in the program, so that previously tested parts are not re-tested. The
RESULT option is usually effective for most error 

trapping situations.

### 8.2.2 TRACE Output

Each line is indented on the screen to represent the level of nesting applicable to the clause. At the beginning, there is the line number in which the clause appears in the program and then a  three character marker, which shows the meaning of the displayed line. Sub-totals or expressions appear in quotation marks so prefixes and spaces are easily recognized.

Code 

Meaning of code 

program text of a  clause

+++ 

command or syntax error

>C> 

expanded form of a  compound symbol

>F> 

result of a  function call

>L> 

jump marker (literal or constant value)

>0> 

result of a  dyadic operation

>P> 

result of a  prefix operation

>U> 

uninitialized variable

>v> 

value of a  variable

»> 

result of an expression

» 

value of the place holder

If the data stream is defined, TRACE output is directed by the interpreter to "STDERR" otherwise it goes to STDOUT, in addition to the display and normal program output. In some cases "STDOUT" is not defined, for example, if a  macro program is started without opening an I/O window. To enable tracing for such programs, a  global trace window can be opened in the Rexx master procedure. For every program in which the "STDERR" is not defined, this window becomes the output target for "STDERR". With the commands TCO and TCC, a  global tracing window is opened and closed. Before it's closed, all output of all programs must be returned to its beginning status. The tracing window can also be directed with messages from application programs. During interactive tracing, this window is used for keyboard entry. Since all active programs share one window for trace output, following more than one simultaneous executing program is not recommended, since the result might be confusing.

### 8.2.3 Command Suppression in ARexx

Programs 

Suppressing commands is useful when an ARexx program should not 

pass commands to external environments without prior testing. If one uncontrolled program starts sending unnecessary commands to DOS (for example, to delete files), there may be disastrous results.

ARexx includes a  trace mode in which these commands are only 

displayed. The return code is zero (which would usually be returned if the command was successful) and the program continues. Commands entered during interactive tracing are always executed, but they do not affect the value of the return code.

Command suppression is controlled using exclamation marks, either 

alone or in front of a  trace option, to toggle these functions on and off. If the trace option "OFF" or "BACKGROUND" has been selected, then command suppression is disabled.

8. Special Features 

### 8.2.4 Interactive Tracing

During interactive tracing you may enter single clauses during program 

execution in order to test variable contents, to change them to enter commands or to direct branching and loops. You can enter as many commands as you want with the same limitations as interpreter commands, for example, DO-END constructions must appear in one line.

Any trace mode can be used interactively. The interpreter waits after 

each displayed clause and requests information with the message ">+>". As a  programmer you have three options:

• Press [Enter!, entering an empty line, and the program proceeds to 

the next trace output. The "ALL" mode executes the program step by step by pressing the [Enterl key.

• Enter an equal sign (=) and the last clause is repeated. This is only 

useful if a  change has been made, a  correction of variables otherwise the result will always remain the same.

• Another command, which will be immediately executed if it's ARexx 

code. Where the program is interrupted depends on the trace mode you have chosen the interpreter only stops after the clauses it's asked to display. There are some commands that cannot be executed a  second time, at which the interpreter will not stop. They are: CALL, DO, ELSE, IF, THEN and OTHERWISE. Also, the interpreter will not stop after a  clause that causes an error.

Interactive tracing is controlled with the question mark, which can occur 

alone or in front of a  trace option. Each appearance of the question mark toggles interactive tracing on or off. For example, the command "TRACE
?I", to activate interactive tracing and set "INTERMEDIATES" tracing 

on, begins a  sub-total display. During interactive tracing further instructions that call trace are ignored, so you cannot accidentally exit trace mode.

Errors in the execution of lines entered interactively are displayed but do 

not lead to a  program stop. Also, during interactive tracing, SIGNAL interrupts are blocked. This is to avoid a  command error or prevent another SIGNAL condition from immediately branching out to an equivalent label. Such a  jump cannot be un-done and would normally prevent a  programmer from taking interactive measures when an error

occurs, thus creating an uninterruptable infinite loop. If a  command with the form "SIGNAL Label" is interactively entered, the jump is executed, and further interactive entries are discarded.

Individual interrupt flags can still be set using the SIGNAL command, or 

they can be deleted they will not work until normal program execution resumes. The trace mode you enter last is retained through sub-routines that you are unable to see. At the beginning of an uninteresting sub-routine tracing with "RESULTS", enter "TRACE OFF". When the sub-routine ends, the old setting is automatically restored. The Rexx master procedure manages the "external" trace flag, with which running programs can be externally set to interactive tracing. This flag is set with the CLI command "TS". All running programs not set to interactive tracing immediately start to trace, even programs that start after the command. The trace option defaults to "RESULTS" if the modes
"INTERMEDIATES" or "SCAN" were not previously set otherwise they 

remain unchanged. This flag can control programs that have run out of control, are caught in endless loops, or will not accept any entry. Set the display to interactive mode from the outside and perhaps you can recognize the problem and fix it more quickly. The disadvantage to this arrangement is that this flag influences all ARexx programs. If other programs do not have their own 10 channels, and the global tracing window is used to do the trace, the output to this window is hard to interpret. The tracing flag is set off with the CLI command TE. When individual programs notice that the trace mode is no longer on, they also change the trace mode to "OFF". Programs whose trace mode has been set to "BACKGROUND" do not respond to the global tracing flag at all.

### 8.2.5 SIGNAL Interrupts and Error Handling

ARexx offers a  mechanism which makes it easy to recognize errors and 

special program situations during execution, and to react to them without halting the program. If an interrupt is enabled and the condition occurs, program execution continues at the appropriate label. Deciding factors can be synchronic (for example, syntax errors) or asynchronic (for example, pressing fctril+fcY). These are called "interrupts" and are handled by ARexx they have nothing to do with microprocessor
"interrupt" channels. 

8. Special Features 

The following events are handled by ARexx: the description of the event is the name of the label to which the program branches if the event occurs. A  "BREAK_C" interrupt branches to a  label of the form
"BREAK_C:". An interrupt can be toggled on or off with the command 

SIGNAL. If the corresponding label is not defined and the condition that 

has been enabled occurs, the program will still interrupt and display an error message.

BREAK_C fctril+fc") break detected by DOS. If the interrupt is off, 

the program immediately ends, with the message
"Execution halted" and a  return code of 2. 

BREAK.D fctrQ+fp) break detected by DOS. This is ignored if the 

appropriate interrupt is switched off.

BREAK.E (ct7Q+(D break detected by DOS. This is ignored if the 

appropriate interrupt is switched off.

BREAK.F (ctrj}+{F) break detected by DOS. This is ignored if the 

appropriate interrupt is switched off.

ERROR The return code of an external program is not "0". 

FAILURE The return code is greater than the FAITAT setting. 

HALT A  HALT command appeared (for example, after "hi"). If 

the interrupt is switched off, the program ends immediately displaying the message "Execution halted and a  return code of 2.

IOERR DOS has detected an error in an I/O operation. 

NOVALUE An attempt was made to access an un-initialized 

variable.

SYNTAX A  syntax or execution error has been encountered. Not 

all such errors can be caught. Certain errors, occurring before a  program begins to execute commands, and errors that are not recognized by the external ARexx interface, belong to this group.

When the corresponding jump occurs as a  result of the interrupt condition, all active command areas, (DO groups, loops etc.) are dissolved, and the corresponding interrupt is switched off again. This is necessary to avoid endless interrupt loops. Interrupts within a  function or a  sub-program do not effect the main program. The interpreter also sets special variables when an interrupt appears. The variable SIGL contains the current line number at the moment the interrupt appeared. The variable RC is set to the appropriate error code during an "ERROR" or "SYNTAX" interrupt On an "ERROR", a  command code is returned, which can usually be read as an error level. For "SYNTAX", the appropriate ARexx error code appears, which the internal function ERRORTEXT() translates into
English. 

The main purpose of interrupts is to make error handling easier. After an error, you can branch, to give more information, or get to the root of the condition. Error handling is often very important with the INTERPRET command.
