# ARexx Comprehensive Reference

A complete reference for the ARexx scripting language on AmigaOS, aimed at AI agents writing ARexx scripts for automation, testing, and inter-process communication.

## Table of Contents

1. [Language Overview](#1-language-overview)
2. [Script Structure and Execution](#2-script-structure-and-execution)
3. [Core Syntax](#3-core-syntax)
4. [Operators](#4-operators)
5. [Control Flow](#5-control-flow)
6. [Functions and Subroutines](#6-functions-and-subroutines)
7. [String Operations](#7-string-operations)
8. [Numeric Functions](#8-numeric-functions)
9. [Data Type and Conversion Functions](#9-data-type-and-conversion-functions)
10. [Bit Manipulation Functions](#10-bit-manipulation-functions)
11. [File I/O](#11-file-io)
12. [Parsing (PARSE Instruction)](#12-parsing-parse-instruction)
13. [Inter-Process Communication](#13-inter-process-communication)
14. [AmigaDOS Integration](#14-amigados-integration)
15. [External Function Libraries](#15-external-function-libraries)
16. [Special Variables](#16-special-variables)
17. [Error Handling](#17-error-handling)
18. [Common Patterns](#18-common-patterns)
19. [Gotchas and Quirks](#19-gotchas-and-quirks)
20. [Testing Patterns](#20-testing-patterns)
21. [Command Utilities](#21-command-utilities)
22. [Error Codes](#22-error-codes)

---

## 1. Language Overview

### What Is ARexx?

ARexx is the Amiga implementation of IBM's REXX (Restructured Extended Executor) language, created by **William Hawes** for the Amiga platform. It has been integrated into AmigaOS since **Workbench 2.0** (1990) and serves as the system's standard scripting and inter-process communication language.

ARexx is:
- **Interpreted** -- scripts are ASCII text files, no compilation needed
- **Typeless** -- all data is treated as character strings; numeric operations happen automatically when operands are valid numbers
- **Case-insensitive** -- variable names and keywords are uppercased internally
- **String-based** -- the fundamental data type is the string; there are no arrays, structs, or typed variables

### How It Fits into AmigaOS

ARexx exploits two core AmigaOS features:

1. **Multitasking** -- ARexx scripts run as separate tasks alongside other programs
2. **Inter-Process Communication (IPC)** -- Applications exchange commands and data through named message ports

The **RexxMast** resident process acts as the interpreter manager. It monitors a public message port named `REXX`, launches script execution, and handles error reporting. Applications that support ARexx create their own named ports and accept commands from ARexx scripts via the `ADDRESS` instruction.

### Key Characteristics

- No variable declarations needed -- uninitialized variables equal their own uppercased name
- Built-in tracing, trapping, and debugging facilities
- Automatic resource management
- External function libraries extend capabilities (rexxsupport.library, rexxmathlib.library)
- Every ARexx-aware application can be scripted and combined with others

---

## 2. Script Structure and Execution

### Script Requirements

Every ARexx program **must begin with a comment** on the first line. This is how RexxMast identifies the file as an ARexx script:

```rexx
/* My ARexx Script */
SAY "Hello, Amiga!"
EXIT
```

Without the opening `/* ... */`, RexxMast will refuse to execute the file.

### Running Scripts

**From Shell:**
```
RX scriptname.rexx
RX scriptname              ; .rexx extension optional if in REXX: path
RX "SAY 'inline code'"     ; inline execution
```

**From Workbench:** Create an icon with Default Tool set to `SYS:C/Rx`.

**Interactive mode:**
```
rx "do forever; parse pull input; interpret input; end"
```
Type ARexx commands and press Enter for immediate execution. Type `exit` to quit.

### Script Location

Scripts are typically stored in `REXX:` (which maps to `SYS:S/ARexx` by default). When stored there, the `.rexx` extension is optional.

### Passing Arguments

```
RX myscript.rexx arg1 arg2 "arg with spaces"
```

Inside the script, retrieve arguments with `ARG` or `PARSE ARG`:

```rexx
/* Get arguments */
ARG first second rest
SAY "First argument:" first
```

### RexxMast Setup

RexxMast must be running before scripts can execute. It typically starts at boot:

```
; In S:User-Startup
SYS:System/RexxMast >NIL:
```

Or launch manually from Shell: `RexxMast >NIL:`

---

## 3. Core Syntax

### Comments

```rexx
/* This is a comment */
/* Comments can be
   multi-line */
/* They can /* nest */ like this */
```

### Clauses (Statements)

ARexx programs consist of clauses. Each clause is one of:

| Type | Description | Example |
|------|-------------|---------|
| Null | Blank line or comment only | `/* nothing */` |
| Label | Symbol followed by colon | `start:` |
| Assignment | Variable = expression | `name = "Amiga"` |
| Instruction | ARexx keyword | `SAY "Hello"` |
| Command | Expression sent to host | `'delete myfile'` |

Clauses end at line breaks or semicolons. Use commas for line continuation:

```rexx
longstring = "This is a very",
             "long string"
```

### Variables

**Simple variables** -- start with a letter, case-insensitive:

```rexx
name = "Amiga"
count = 42
SAY name              /* Amiga */
SAY NAME              /* Amiga -- same variable */
```

**Uninitialized variables** default to their own uppercased name:

```rexx
SAY unset_var         /* prints: UNSET_VAR */
```

**Stem variables** -- end with a period, act as array initializers:

```rexx
data. = "empty"       /* Set default for all data.* */
data.1 = "first"
data.2 = "second"
SAY data.1            /* first */
SAY data.99           /* empty (default) */
```

**Compound variables** -- contain internal periods, enable associative arrays:

```rexx
/* Direct indexing */
item.1 = "Apple"
item.2 = "Banana"
item.count = 2

/* Variable substitution in tails */
key = "NAME"
record.key = "Duncan"     /* Stores as record.NAME */
SAY record.NAME           /* Duncan */

/* Multi-dimensional */
grid.1.1 = "X"
grid.1.2 = "O"
i = 1; j = 2
SAY grid.i.j              /* O -- expands to grid.1.2 */
```

**DROP** resets variables to uninitialized state:

```rexx
a = 123
DROP a
SAY a                     /* A */

/* Drop entire stem */
data.1 = "x"
DROP data.
SAY data.1                /* DATA.1 */
```

### Strings

```rexx
greeting = "Hello, world"
greeting = 'Hello, world'         /* single or double quotes */
apostrophe = "it''s"              /* doubled delimiter = literal */
hex_string = '48 65 6C 6C 6F'X   /* hex notation */
bin_string = '01001000'B          /* binary notation */
```

### Numbers

Valid formats: `33`, `12.3`, `0.321e12`, `+15.`, `-7`

Leading/trailing blanks are permitted. The `NUMERIC DIGITS` setting controls precision (default 9).

### Assignment

```rexx
x = 5
name = "Amiga" 1200       /* concatenation: "Amiga 1200" */
result = 3 + 4 * 2        /* arithmetic: 11 */
```

---

## 4. Operators

### Arithmetic Operators

| Operator | Description | Example | Result |
|----------|-------------|---------|--------|
| `+` | Addition | `3 + 4` | `7` |
| `-` | Subtraction | `10 - 3` | `7` |
| `*` | Multiplication | `3 * 4` | `12` |
| `/` | Division | `7 / 2` | `3.5` |
| `%` | Integer division | `7 % 2` | `3` |
| `//` | Remainder | `7 // 2` | `1` |
| `**` | Exponentiation | `2 ** 8` | `256` |
| `-` (prefix) | Negation | `-5` | `-5` |
| `+` (prefix) | Convert to number | `+"3"` | `3` |

### Concatenation Operators

| Operator | Description | Example | Result |
|----------|-------------|---------|--------|
| (space) | Concatenate with one space | `"good" "times"` | `"good times"` |
| `\|\|` | Concatenate with no space | `"good"\|\|"times"` | `"goodtimes"` |
| (abuttal) | Adjacent with no space | `"A"3` | `"A3"` |

### Comparison Operators

| Operator | Description |
|----------|-------------|
| `=` | Equal |
| `\=`, `~=`, `^=` | Not equal |
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal |
| `<=` | Less than or equal |
| `==` | Strictly equal (exact match, no padding) |
| `\==`, `~==` | Strictly not equal |

**Important:** If both operands are valid numbers, numeric comparison is performed. Otherwise, string comparison (padded with blanks to equal length). See [Gotchas](#19-gotchas-and-quirks).

### Logical Operators

| Operator | Description | Example |
|----------|-------------|---------|
| `&` | AND | `1 & 0` = `0` |
| `\|` | OR | `1 \| 0` = `1` |
| `&&` or `^` | XOR | `1 && 0` = `1` |
| `~` or `\` | NOT (prefix) | `~1` = `0` |

Logical values are `0` (false) and `1` (true). Using any other value in a boolean context raises error 46.

### Operator Precedence (highest to lowest)

1. `~` (NOT), `+` `-` (prefix)
2. `**` (exponentiation)
3. `*` `/` `%` `//` (multiplicative)
4. `+` `-` (additive)
5. `||` (concatenation), space, abuttal
6. `=` `>` `<` `>=` `<=` `==` etc. (comparison)
7. `&` (AND)
8. `|` `&&` `^` (OR, XOR)

---

## 5. Control Flow

### IF / THEN / ELSE

```rexx
IF count > 10 THEN SAY "Many"

IF count > 10 THEN
   SAY "Many"
ELSE
   SAY "Few"

/* Block form */
IF count > 10 THEN DO
   SAY "There are many items"
   SAY "Count:" count
END
ELSE DO
   SAY "There are few items"
END
```

ELSE always binds to the nearest preceding IF. Use NOP to control binding:

```rexx
IF i = j THEN
   IF j = k THEN a = 0
      ELSE NOP           /* binds to inner IF */
   ELSE a = a + 1        /* binds to outer IF */
```

### DO Loops

**Simple block:**
```rexx
DO
   SAY "Line 1"
   SAY "Line 2"
END
```

**Counted loop:**
```rexx
DO 5
   SAY "Hello!"
END
```

**Iterative loop with index:**
```rexx
DO i = 1 TO 10
   SAY i
END

DO i = 1 TO 10 BY 2
   SAY i              /* 1 3 5 7 9 */
END

DO i = 10 TO 1 BY -1
   SAY i              /* countdown */
END
```

**FOR limit:**
```rexx
DO i = 1 TO 100 FOR 5
   SAY i              /* 1 2 3 4 5 -- stops after 5 iterations */
END
```

**FOREVER:**
```rexx
DO FOREVER
   PULL line
   IF line = "QUIT" THEN LEAVE
   SAY "You said:" line
END
```

**WHILE and UNTIL:**
```rexx
DO WHILE running
   score = score + 1
   IF score > 21 THEN running = 0
END

DO UNTIL score > 21
   score = score + 1
END
```

**Combined forms:**
```rexx
DO i = 1 TO limit FOR 10 WHILE number < 20
   number = i * number
END
```

### ITERATE and LEAVE

```rexx
/* Skip iteration 3 */
DO i = 1 TO 5
   IF i = 3 THEN ITERATE
   SAY i                  /* 1 2 4 5 */
END

/* Exit loop early */
DO i = 1 TO 100
   IF i > 5 THEN LEAVE
   SAY i                  /* 1 2 3 4 5 */
END

/* Named LEAVE for nested loops */
DO hour = 0 TO 23
   DO minute = 0 TO 59
      IF (hour = 2) & (minute = 19) THEN LEAVE hour
   END
END
```

### BREAK

```rexx
DO
   IF i > 3 THEN BREAK
   a = a + 1
END
```

### SELECT / WHEN / OTHERWISE

```rexx
SELECT
   WHEN choice = 1 THEN SAY "Option one"
   WHEN choice = 2 THEN SAY "Option two"
   WHEN choice = 3 THEN DO
      SAY "Option three"
      CALL process_three
   END
   OTHERWISE SAY "Unknown option:" choice
END
```

**OTHERWISE is required** -- omitting it when no WHEN matches raises error 25.

---

## 6. Functions and Subroutines

### Internal Functions

```rexx
/* Define and call a function */
result = square(5)
SAY result                    /* 25 */
EXIT

square:
   ARG n
   RETURN n * n
```

### PROCEDURE (Local Variables)

Without PROCEDURE, functions share the caller's variable scope:

```rexx
factorial:
   PROCEDURE
   ARG n
   IF n <= 1 THEN RETURN 1
   RETURN n * factorial(n - 1)
```

**EXPOSE** selectively shares variables:

```rexx
counter:
   PROCEDURE EXPOSE total
   total = total + 1
   RETURN total
```

### CALL vs Function Invocation

```rexx
/* As function -- return value used in expression */
len = LENGTH("hello")

/* As subroutine -- return value goes to RESULT */
CALL LENGTH "hello"
SAY RESULT                    /* 5 */
```

### External Functions

Functions not found internally are searched in:
1. The built-in function library
2. Function libraries added with ADDLIB()
3. External .rexx files in REXX: path

---

## 7. String Operations

ARexx is fundamentally string-based. These built-in functions are available without any library:

### Extraction

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `LEFT(s, n [,pad])` | Left substring | `LEFT("Hello", 3)` | `"Hel"` |
| `RIGHT(s, n [,pad])` | Right substring | `RIGHT("Hello", 3)` | `"llo"` |
| `SUBSTR(s, start [,len] [,pad])` | Substring | `SUBSTR("Hello", 2, 3)` | `"ell"` |
| `WORD(s, n)` | Nth word | `WORD("one two three", 2)` | `"two"` |
| `SUBWORD(s, n [,len])` | Substring of words | `SUBWORD("a b c d", 2, 2)` | `"b c"` |

### Searching

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `POS(pattern, s [,start])` | Find pattern (forward) | `POS("ll", "Hello")` | `3` |
| `LASTPOS(pattern, s [,start])` | Find pattern (backward) | `LASTPOS("l", "Hello")` | `4` |
| `INDEX(s, pattern [,start])` | Find pattern (args reversed from POS) | `INDEX("Hello", "ll")` | `3` |
| `FIND(s, phrase)` | Find word phrase, return word number | `FIND("Now is the time", "is the")` | `2` |
| `WORDINDEX(s, n)` | Character position of nth word | `WORDINDEX("Now is the", 3)` | `8` |

### Measurement

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `LENGTH(s)` | String length | `LENGTH("Hello")` | `5` |
| `WORDS(s)` | Word count | `WORDS("one two three")` | `3` |
| `WORDLENGTH(s, n)` | Length of nth word | `WORDLENGTH("one two three", 3)` | `5` |

### Modification

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `CENTER(s, len [,pad])` | Center in field | `CENTER("hi", 6)` | `"  hi  "` |
| `COPIES(s, n)` | Repeat string | `COPIES("ab", 3)` | `"ababab"` |
| `INSERT(new, old [,pos] [,len] [,pad])` | Insert string | `INSERT("XX", "abcd", 2)` | `"abXXcd"` |
| `OVERLAY(new, old [,pos] [,len] [,pad])` | Overlay string | `OVERLAY("XX", "abcd", 2)` | `"aXXd"` |
| `DELSTR(s, n [,len])` | Delete characters | `DELSTR("abcdef", 3, 2)` | `"abef"` |
| `DELWORD(s, n [,len])` | Delete words | `DELWORD("a b c d", 2, 2)` | `"a d"` |
| `REVERSE(s)` | Reverse string | `REVERSE("abc")` | `"cba"` |
| `TRANSLATE(s [,out] [,in] [,pad])` | Character translation | `TRANSLATE("abc")` | `"ABC"` |
| `UPPER(s)` | Uppercase | `UPPER("hello")` | `"HELLO"` |

### Whitespace

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `STRIP(s [,opt] [,char])` | Strip characters (B/L/T) | `STRIP("  hi  ")` | `"hi"` |
| `TRIM(s)` | Remove trailing blanks | `TRIM("hi  ")` | `"hi"` |
| `SPACE(s, n [,pad])` | Reformat word spacing | `SPACE("a  b  c", 1)` | `"a b c"` |
| `COMPRESS(s [,chars])` | Remove characters | `COMPRESS("a b c")` | `"abc"` |

### Comparison and Validation

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `COMPARE(s1, s2 [,pad])` | First difference position | `COMPARE("abc", "abd")` | `3` |
| `ABBREV(full, abbr [,len])` | Test abbreviation | `ABBREV("PRINT", "PR")` | `1` |
| `VERIFY(s, list [,'M'])` | Verify characters against list | `VERIFY("123", "0123456789")` | `0` |
| `DATATYPE(s [,opt])` | Test data type | `DATATYPE("123")` | `"NUM"` |

### CENTRE Alias

`CENTRE()` is an accepted alias for `CENTER()` (British spelling).

---

## 8. Numeric Functions

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `ABS(n)` | Absolute value | `ABS(-5.3)` | `5.3` |
| `SIGN(n)` | Sign (-1, 0, or 1) | `SIGN(-42)` | `-1` |
| `MAX(n1, n2 [,...])` | Maximum (min 2 args) | `MAX(3, 1, 7)` | `7` |
| `MIN(n1, n2 [,...])` | Minimum (min 2 args) | `MIN(3, 1, 7)` | `1` |
| `TRUNC(n [,places])` | Truncate | `TRUNC(3.14159, 2)` | `3.14` |
| `RANDOM([min] [,max] [,seed])` | Random integer | `RANDOM(1, 6)` | `1-6` |
| `RANDU([seed])` | Random 0-1 | `RANDU()` | `0.371...` |
| `DIGITS()` | Current NUMERIC DIGITS | `DIGITS()` | `9` |
| `FUZZ()` | Current NUMERIC FUZZ | `FUZZ()` | `0` |
| `FORM()` | Current NUMERIC FORM | `FORM()` | `"SCIENTIFIC"` |

### NUMERIC Settings

```rexx
NUMERIC DIGITS 15          /* Precision: 15 significant digits */
NUMERIC FUZZ 2             /* Fuzzy comparison digits */
NUMERIC FORM SCIENTIFIC    /* or ENGINEERING */
```

---

## 9. Data Type and Conversion Functions

### Type Testing

```rexx
DATATYPE("123")            /* "NUM" */
DATATYPE("abc")            /* "CHAR" */
DATATYPE("123", "W")       /* 1 -- is whole number */
DATATYPE("FF", "X")        /* 1 -- is valid hex */
```

DATATYPE options: `A` (alphanumeric), `B` (binary), `L` (lowercase), `M` (mixed case), `N` (numeric), `S` (valid symbol), `U` (uppercase), `W` (whole number), `X` (hex).

### Conversion Functions

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `C2D(s [,n])` | Character to decimal | `C2D("A")` | `65` |
| `C2X(s)` | Character to hex | `C2X("AB")` | `4142` |
| `D2C(n)` | Decimal to character | `D2C(65)` | `"A"` |
| `D2X(n [,digits])` | Decimal to hex | `D2X(255)` | `"FF"` |
| `X2C(hex)` | Hex to character | `X2C("41")` | `"A"` |
| `X2D(hex [,digits])` | Hex to decimal | `X2D("1F")` | `31` |
| `B2C(bin)` | Binary to character | `B2C("01000001")` | `"A"` |
| `C2B(s)` | Character to binary | `C2B("A")` | `"01000001"` |
| `XRANGE([start] [,end])` | Character range | `XRANGE("a","f")` | `"abcdef"` |

---

## 10. Bit Manipulation Functions

| Function | Description | Example | Result |
|----------|-------------|---------|--------|
| `BITAND(s1, s2 [,pad])` | Bitwise AND | `BITAND('0F'x, 'F3'x)` | `'03'x` |
| `BITOR(s1, s2 [,pad])` | Bitwise OR | `BITOR('0F'x, 'F0'x)` | `'FF'x` |
| `BITXOR(s1, s2 [,pad])` | Bitwise XOR | `BITXOR('FF'x, '0F'x)` | `'F0'x` |
| `BITSET(s, bit)` | Set bit to 1 | | |
| `BITCLR(s, bit)` | Clear bit to 0 | | |
| `BITCHG(s, bit)` | Toggle bit | | |
| `BITTST(s, bit)` | Test bit (returns 0/1) | `BITTST('FF'x, 0)` | `1` |
| `BITCOMP(s1, s2 [,pad])` | Compare bits, return first diff | `BITCOMP('FF'x, 'FF'x)` | `-1` |

Bit numbering: bit 0 is the low-order bit of the rightmost byte.

---

## 11. File I/O

ARexx uses **logical file names** -- you assign a name when opening a file, then use that name for all operations.

### Opening and Closing

```rexx
/* Open for reading (default) */
IF ~OPEN('infile', 'RAM:data.txt', 'R') THEN DO
   SAY "Cannot open file"
   EXIT 10
END

/* Open for writing */
CALL OPEN 'outfile', 'RAM:output.txt', 'W'

/* Open for appending */
CALL OPEN 'logfile', 'T:log.txt', 'A'

/* Close */
CALL CLOSE 'infile'
```

Mode characters: `'R'` (read), `'W'` (write), `'A'` (append).

### Reading

```rexx
/* Read a line (without newline) */
line = READLN('infile')

/* Read specific number of characters */
chunk = READCH('infile', 256)

/* Check for end of file */
IF EOF('infile') THEN SAY "End reached"

/* Read entire file line by line */
IF OPEN('in', 'RAM:data.txt', 'R') THEN DO
   DO WHILE ~EOF('in')
      line = READLN('in')
      SAY line
   END
   CALL CLOSE 'in'
END
```

### Writing

```rexx
/* Write a line (appends newline) */
CALL WRITELN 'outfile', 'Hello, world!'
/* Returns number of characters written (including newline) */

/* Write without newline */
CALL WRITECH 'outfile', 'No newline here'
/* Returns number of characters written */
```

### Seeking

```rexx
/* Seek from beginning */
pos = SEEK('infile', 0, 'B')       /* Go to start */
pos = SEEK('infile', 100, 'B')     /* Go to byte 100 */

/* Seek relative to current position */
pos = SEEK('infile', 10, 'C')      /* Forward 10 bytes */
pos = SEEK('infile', -10, 'C')     /* Back 10 bytes */

/* Seek from end -- useful to get file size */
size = SEEK('infile', 0, 'E')      /* Returns file size */
```

### Console I/O

Use `STDIN` as the logical name for console:

```rexx
/* Read from console */
line = READLN(STDIN)

/* Write to console (alternative to SAY) */
CALL WRITELN STDIN, "Hello!"

/* Prompt without newline */
CALL WRITECH STDIN, "Enter name: "
name = READLN(STDIN)
```

### File Existence

```rexx
IF EXISTS('SYS:C/Dir') THEN SAY "File exists"
```

### Opening Console Windows

```rexx
/* Open a custom console window for output */
CALL OPEN 'con', 'CON:0/0/640/200/My Output/AUTO/CLOSE/WAIT'
CALL WRITELN 'con', 'This appears in a new window'
CALL CLOSE 'con'
```

---

## 12. Parsing (PARSE Instruction)

PARSE is one of ARexx's most powerful features -- it extracts substrings from strings and assigns them to variables efficiently.

### Syntax

```
PARSE [UPPER] source [template] [,template ...]
```

Sources: `ARG`, `EXTERNAL`, `NUMERIC`, `PULL`, `SOURCE`, `VALUE expr WITH`, `VAR varname`, `VERSION`.

### Tokenization (Word Splitting)

```rexx
/* Split into words */
mystring = "John Smith 42 London"
PARSE VAR mystring first last age city
SAY first              /* John */
SAY last               /* Smith */
SAY age                /* 42 */
SAY city               /* London */

/* Use period as placeholder (discard) */
PARSE VAR mystring . last . .
SAY last               /* Smith */

/* Last variable gets the remainder */
PARSE VAR mystring first rest
SAY rest               /* Smith 42 London */
```

### PARSE UPPER (Case Conversion)

```rexx
PARSE UPPER VAR input command args
/* command and args are uppercased */
```

`ARG` is shorthand for `PARSE UPPER ARG`. `PULL` is shorthand for `PARSE UPPER PULL`.

Use `PARSE ARG` (without UPPER) to preserve case.

### Pattern Matching

```rexx
/* Split on literal delimiter */
record = "Smith,John,42,London"
PARSE VAR record last ',' first ',' age ',' city
SAY first              /* John */
SAY city               /* London */

/* The delimiter is consumed (removed) */
```

### Positional Patterns

```rexx
/* Fixed column positions */
record = "John Smith        42  London"
PARSE VAR record 1 name 19 age 23 city
SAY name               /* John Smith       */
SAY age                /* 42  */
SAY city               /* London */

/* Relative positions */
PARSE VAR record 1 start +5 middle +5 rest
SAY start              /* John  */
SAY middle             /* Smith */
```

### Multiple Templates (Multiple Arguments)

Commas separate templates, each processing a different argument string:

```rexx
/* For ARG/PULL: each comma-separated template gets a separate argument */
myfunction:
   PARSE ARG filename, options, count
   /* filename = arg 1, options = arg 2, count = arg 3 */
```

### Common Parsing Idioms

```rexx
/* Extract first word and rest */
PARSE VAR input command rest

/* Split path and filename */
PARSE VAR fullpath path '/' filename

/* Extract key=value */
PARSE VAR setting key '=' value

/* Get just the filename from a path */
DO WHILE POS('/', fullpath) > 0
   PARSE VAR fullpath . '/' fullpath
END
/* fullpath now contains just the filename */
```

---

## 13. Inter-Process Communication

IPC is ARexx's killer feature -- it can send commands to any ARexx-aware application.

### ADDRESS Instruction

```rexx
/* Set default host for all subsequent commands */
ADDRESS 'TURBOTEXT'
'OPEN readme.txt'
'GOTO TOP'

/* Send single command to a host */
ADDRESS 'TURBOTEXT' 'OPEN readme.txt'

/* Send to AmigaDOS shell */
ADDRESS COMMAND 'dir RAM:'

/* Query current host */
host = ADDRESS()
```

### How IPC Works

1. ARexx-aware applications create a named **message port** (e.g., `TURBOTEXT`, `MULTIVIEW`)
2. ARexx scripts use `ADDRESS` to target that port
3. Commands (unrecognized clauses) are sent as messages to the target port
4. The application processes the command and returns a result code in `RC` and optionally a result string in `RESULT`

### OPTIONS RESULTS

To receive result strings from applications, you must enable results:

```rexx
OPTIONS RESULTS

ADDRESS 'TURBOTEXT'
'GETCURSORPOS'
SAY RESULT                /* e.g., "10 25" */
```

### Checking Port Existence

```rexx
/* Check if an application's port exists */
IF SHOW('P', 'TURBOTEXT') THEN DO
   ADDRESS 'TURBOTEXT'
   'OPEN myfile.txt'
END
ELSE
   SAY "TurboText is not running"
```

### Waiting for a Port

From the shell, use `WaitForPort`:
```
WaitForPort TURBOTEXT
```

In a script, poll:
```rexx
DO i = 1 TO 50           /* Wait up to 5 seconds */
   IF SHOW('P', 'MYAPP') THEN LEAVE
   CALL DELAY 10         /* 10 ticks = 0.1 seconds (needs rexxsupport.library) */
END
IF ~SHOW('P', 'MYAPP') THEN DO
   SAY "Application did not start"
   EXIT 10
END
```

### Creating Your Own Port

Using rexxsupport.library:

```rexx
CALL ADDLIB 'rexxsupport.library', 0, -30, 0

/* Create a port */
CALL OPENPORT 'MYPORT'

/* Wait for messages */
DO FOREVER
   CALL WAITPKT 'MYPORT'
   pkt = GETPKT('MYPORT')
   DO WHILE pkt ~= '00000000'x
      cmd = GETARG(pkt, 0)       /* Get the command string */
      SAY "Received:" cmd
      CALL REPLY pkt, 0          /* Reply with RC=0 */
      pkt = GETPKT('MYPORT')
   END
END

CALL CLOSEPORT 'MYPORT'
```

### The REXX Port

The default host address is `REXX`. Commands sent to the REXX port are executed as ARexx programs:

```rexx
ADDRESS REXX 'rx myscript.rexx'
```

---

## 14. AmigaDOS Integration

### Running Shell Commands

```rexx
/* ADDRESS COMMAND sends to AmigaDOS shell */
ADDRESS COMMAND 'dir RAM:'
ADDRESS COMMAND 'copy SYS:C/Dir RAM:Dir'
ADDRESS COMMAND 'delete T:tempfile'

/* Check return code */
ADDRESS COMMAND 'assign EXISTS Work:'
IF RC = 0 THEN SAY "Work: exists"
ELSE SAY "Work: not assigned"
```

### Capturing Command Output

ARexx cannot directly capture stdout from shell commands. Use temporary files:

```rexx
/* Redirect output to temp file, then read it */
ADDRESS COMMAND 'dir >T:dirlist RAM:'
IF OPEN('in', 'T:dirlist', 'R') THEN DO
   DO WHILE ~EOF('in')
      line = READLN('in')
      IF line ~= '' THEN SAY line
   END
   CALL CLOSE 'in'
END
ADDRESS COMMAND 'delete T:dirlist QUIET'
```

### Common Pitfalls with Shell Commands

#### No Shell Piping in ADDRESS COMMAND

`ADDRESS COMMAND 'echo "hello" | grep hello'` does **NOT** work. AmigaDOS pipe handling through ARexx's ADDRESS COMMAND is unreliable. Instead, write input to a temp file first, then run the command with the file as input:

```rexx
/* BAD — pipe will not work */
ADDRESS COMMAND 'echo "a:b:c" | cut -d: -f2 >T:out'

/* GOOD — use a temp file */
IF OPEN('tf', 'T:input.txt', 'W') THEN DO
    CALL WRITELN('tf', 'a:b:c')
    CALL CLOSE('tf')
END
ADDRESS COMMAND 'cut -d: -f2 T:input.txt >T:out'
```

#### No Command Chaining with && or ;

AmigaDOS does not support `&&` for conditional chaining. The `;` separator may work in some shells but not through ARexx's ADDRESS COMMAND. Run commands as separate ADDRESS COMMAND calls:

```rexx
/* BAD — chaining will not work */
ADDRESS COMMAND 'echo >T:f.txt "hi" && cut -c1-2 T:f.txt'

/* GOOD — separate calls */
ADDRESS COMMAND 'echo >T:f.txt "hi"'
ADDRESS COMMAND 'cut -c1-2 T:f.txt >T:out'
```

#### Output Capture with Non-Zero RC

When using `ADDRESS COMMAND cmd '>' outfile`, some ARexx implementations may not write the output file when the command returns non-zero RC. Use `OPTIONS FAILAT 21` to ensure output is always captured regardless of the command's return code.

#### Test Inputs Should Be Pre-Created Files

For FS-UAE test cases (`test-fsemu-cases.txt`), write test input data to separate files (e.g., `test-grep-input.txt`) that get copied to `WORK:` by the test infrastructure. Do not try to create files on-the-fly in the CMD field or via piping.

### FAILAT (Error Threshold)

```rexx
/* Set minimum RC that triggers an error condition */
OPTIONS FAILAT 20         /* Only RC >= 20 triggers ERROR */

/* Default FAILAT is 10 -- commands returning RC >= 10 trigger ERROR */
/* Use FAILAT 21 in test harnesses to capture output from all commands */
OPTIONS FAILAT 21
```

### PRAGMA (System Environment)

```rexx
/* Change current directory */
olddir = PRAGMA('D', 'RAM:')

/* Set task priority */
oldpri = PRAGMA('PRIORITY', -1)

/* Get process ID */
pid = PRAGMA('ID')

/* Set stack size */
PRAGMA('STACK', 32768)

/* Set console window */
PRAGMA('W', 'CON:0/0/640/200/ARexx Output')
```

### Common AmigaDOS Operations

```rexx
/* Check if file exists */
IF EXISTS('SYS:C/Dir') THEN SAY "Found"

/* List directory (with rexxsupport.library) */
CALL ADDLIB 'rexxsupport.library', 0, -30, 0
files = SHOWDIR('RAM:', 'F')      /* Files only */
dirs = SHOWDIR('RAM:', 'D')       /* Dirs only */
all = SHOWDIR('RAM:', 'A')        /* All entries */

/* Get file information */
info = STATEF('RAM:myfile')
PARSE VAR info type size blocks prot days mins ticks comment
SAY "Size:" size "bytes"
```

---

## 15. External Function Libraries

### Adding Libraries

```rexx
/* Syntax: ADDLIB(name, priority, offset, version) */
CALL ADDLIB 'rexxsupport.library', 0, -30, 0
CALL ADDLIB 'rexxmathlib.library', 0, -30, 0
```

- **priority**: -100 to 100, higher searched first
- **offset**: always `-30` for standard libraries
- **version**: minimum version, `0` for any

### Checking and Removing

```rexx
IF SHOW('L', 'rexxsupport.library') THEN SAY "Already loaded"
CALL REMLIB 'rexxsupport.library'
```

### rexxsupport.library Functions

This is the most commonly used external library:

| Function | Description |
|----------|-------------|
| `ALLOCMEM(len [,attr])` | Allocate system memory |
| `FREEMEM(addr, len)` | Free allocated memory |
| `DELAY(ticks)` | Pause execution (1 tick = 1/50 second) |
| `OPENPORT(name)` | Create a public message port |
| `CLOSEPORT(name)` | Close a message port |
| `WAITPKT(name)` | Wait for message at port |
| `GETPKT(name)` | Get message from port (non-blocking) |
| `GETARG(pkt [,n])` | Extract argument from message packet |
| `REPLY(pkt, rc)` | Reply to a message |
| `SHOWDIR(dir [,opt] [,pad])` | List directory contents |
| `SHOWLIST(opt [,name] [,pad])` | List system resources |
| `STATEF(filename)` | Get file information |

**SHOWDIR options:** `'A'` (all), `'F'` (files), `'D'` (directories)

**SHOWLIST options:** `'A'` (assigns), `'D'` (devices), `'H'` (handlers), `'I'` (interrupts), `'L'` (libraries), `'M'` (memory), `'P'` (ports), `'R'` (resources), `'S'` (semaphores), `'T'` (tasks), `'V'` (volumes), `'W'` (waiting tasks)

### rexxmathlib.library Functions

Provides transcendental math: `SIN`, `COS`, `TAN`, `ASIN`, `ACOS`, `ATAN`, `ATAN2`, `SINH`, `COSH`, `TANH`, `EXP`, `LN`/`LOG`, `LOG10`, `SQRT`/`SQR`, `POW`/`POWER`, `CEIL`, `FLOOR`, `FABS`, `FACT`, `PI`, `E`, `RAD`, `DEG`, `ROOT`, and more.

```rexx
CALL ADDLIB 'rexxmathlib.library', 0, -30, 0
SAY SIN(PI() / 2)         /* 1 */
SAY SQRT(144)              /* 12 */
SAY POW(2, 10)             /* 1024 */
```

### Clip List (Shared Data)

The Clip List provides inter-script shared storage without files:

```rexx
/* Set a value */
CALL SETCLIP 'mydata', 'Hello from script A'

/* Get a value (from any script) */
value = GETCLIP('mydata')

/* Remove a value */
CALL SETCLIP 'mydata'     /* empty value removes it */

/* List all clips */
IF SHOW('C') THEN SAY "Clips exist"
```

---

## 16. Special Variables

| Variable | Description | Set When |
|----------|-------------|----------|
| `RC` | Return code from last command | After every command clause |
| `RC2` | Secondary return code (error detail) | When RC > 0 after ERROR |
| `RESULT` | Return value from CALL or command | After CALL or command with OPTIONS RESULTS |
| `SIGL` | Line number that caused a jump to label | After SIGNAL or error trap |
| `STDIN` | Logical name for standard I/O stream | Always available |

```rexx
ADDRESS COMMAND 'dir RAM:'
SAY "Return code:" RC

OPTIONS RESULTS
ADDRESS 'MYAPP' 'GETVERSION'
SAY "Result:" RESULT
```

---

## 17. Error Handling

### SIGNAL ON/OFF

```rexx
/* Enable error trapping */
SIGNAL ON ERROR
SIGNAL ON SYNTAX
SIGNAL ON IOERR
SIGNAL ON HALT
SIGNAL ON BREAK_C
SIGNAL ON NOVALUE        /* Trap use of uninitialized variables */

/* Main program */
ADDRESS COMMAND 'nonexistent_command'
SAY "This line executes if RC < FAILAT"
EXIT 0

/* Error handlers -- jumped to via SIGNAL */
ERROR:
   SAY "Command error at line" SIGL "RC=" RC
   EXIT 10

SYNTAX:
   SAY "Syntax error" RC "at line" SIGL ":" ERRORTEXT(RC)
   EXIT 20

IOERR:
   SAY "I/O error at line" SIGL
   EXIT 10

HALT:
   SAY "Script halted by user"
   EXIT 5

BREAK_C:
   SAY "Ctrl-C detected"
   EXIT 5

NOVALUE:
   SAY "Uninitialized variable used at line" SIGL
   EXIT 10
```

### SIGNAL Conditions

| Condition | Triggered When |
|-----------|---------------|
| `BREAK_C` | Ctrl-C pressed |
| `BREAK_D` | Ctrl-D pressed |
| `ERROR` | Command returns RC >= FAILAT |
| `HALT` | External halt request (HI command) |
| `IOERR` | I/O error in READCH/READLN/WRITECH/WRITELN |
| `NOVALUE` | Uninitialized variable referenced |
| `SYNTAX` | ARexx syntax/runtime error |

**Important:** SIGNAL is a GOTO, not a structured exception handler. It cannot return to the point of error. Once a SIGNAL fires, it is automatically turned OFF -- you must re-enable it in the handler if you want to catch the next error.

### ERRORTEXT Function

```rexx
SAY ERRORTEXT(15)          /* "Function not found" */
```

### Defensive Error Checking

```rexx
/* Always check return codes from I/O */
IF ~OPEN('in', filename, 'R') THEN DO
   SAY "Error: Cannot open" filename
   EXIT 10
END

/* Check command success */
ADDRESS COMMAND 'copy' source dest
IF RC ~= 0 THEN DO
   SAY "Copy failed with RC" RC
   EXIT 10
END
```

---

## 18. Common Patterns

### Read a File Into a Stem

```rexx
/* Read file lines into stem variable */
readfile:
   PROCEDURE
   PARSE ARG filename
   IF ~OPEN('in', filename, 'R') THEN RETURN 0
   count = 0
   DO WHILE ~EOF('in')
      line = READLN('in')
      IF ~EOF('in') THEN DO
         count = count + 1
         line.count = line
      END
   END
   CALL CLOSE 'in'
   line.0 = count              /* Convention: stem.0 = count */
   RETURN count
```

### Write a Stem to a File

```rexx
/* Write stem variable to file */
writefile:
   PROCEDURE EXPOSE line.
   PARSE ARG filename
   IF ~OPEN('out', filename, 'W') THEN RETURN 0
   DO i = 1 TO line.0
      CALL WRITELN 'out', line.i
   END
   CALL CLOSE 'out'
   RETURN 1
```

### Process Command-Line Arguments

```rexx
/* myscript.rexx */
PARSE ARG args
IF args = '' THEN DO
   SAY "Usage: rx myscript.rexx <filename> [options]"
   EXIT 5
END
PARSE VAR args filename options
```

### Launch a Program and Wait

```rexx
/* Run a program via AmigaDOS */
ADDRESS COMMAND 'Run >NIL: MyApp'

/* Wait for its port to appear */
DO i = 1 TO 100
   IF SHOW('P', 'MYAPP') THEN LEAVE
   CALL DELAY 10
END
IF ~SHOW('P', 'MYAPP') THEN DO
   SAY "MyApp failed to start"
   EXIT 10
END

/* Now send it commands */
ADDRESS 'MYAPP'
OPTIONS RESULTS
'GETVERSION'
SAY "Version:" RESULT
```

### String Tokenizer

```rexx
/* Split string by custom delimiter */
split:
   PROCEDURE
   PARSE ARG string, delim
   count = 0
   DO WHILE string ~= ''
      p = POS(delim, string)
      IF p = 0 THEN DO
         count = count + 1
         token.count = string
         string = ''
      END
      ELSE DO
         count = count + 1
         token.count = LEFT(string, p - 1)
         string = SUBSTR(string, p + LENGTH(delim))
      END
   END
   token.0 = count
   RETURN count
```

### Formatted Output

```rexx
/* Right-aligned columns */
DO i = 1 TO 10
   SAY RIGHT(i, 4) LEFT(name.i, 20) RIGHT(score.i, 6)
END
```

### Temporary Files

```rexx
/* Use T: for temp files (maps to RAM:T/) */
tempfile = 'T:arexx_temp_' || PRAGMA('ID')
CALL OPEN 'tmp', tempfile, 'W'
CALL WRITELN 'tmp', 'temporary data'
CALL CLOSE 'tmp'
/* ... use the temp file ... */
ADDRESS COMMAND 'delete' tempfile 'QUIET'
```

---

## 19. Gotchas and Quirks

### 1. Scripts Must Start with a Comment

```rexx
/* This comment is REQUIRED */
SAY "Hello"
```

Without `/* ... */` on line 1, RexxMast will not recognize the file as ARexx.

### 2. Case Insensitivity Surprises

Variables are case-insensitive. `name`, `Name`, and `NAME` are all the same variable. Uninitialized variables return their own uppercased name:

```rexx
SAY hello                 /* prints: HELLO (not an error!) */
```

This means typos in variable names silently produce the wrong value instead of an error. Use `SIGNAL ON NOVALUE` to catch this:

```rexx
SIGNAL ON NOVALUE
SAY misspelled_var        /* Now this triggers an error */
```

### 3. Compound Variable Tail Substitution

Tails are resolved using current variable values:

```rexx
i = 3
data.i = "hello"         /* Stores as data.3 */
i = 4
SAY data.i                /* Prints DATA.4 (uninitialized!) not "hello" */
i = 3
SAY data.i                /* NOW prints "hello" */
```

### 4. There Are No Real Arrays

Compound variables simulate arrays, but there is no bounds checking, no LENGTH property, and no way to iterate "all elements." You must track the count yourself (convention: `stem.0`):

```rexx
items.0 = 3
items.1 = "Apple"
items.2 = "Banana"
items.3 = "Cherry"
DO i = 1 TO items.0
   SAY items.i
END
```

### 5. String vs Numeric Comparison

If both operands are valid numbers, comparison is numeric. Otherwise it is string:

```rexx
SAY ("2" > "10")          /* 0 -- numeric comparison (2 < 10) */
SAY ("2a" > "10a")        /* 1 -- string comparison ("2" > "1") */
SAY (" 2" = "2")          /* 1 -- numeric (leading blanks stripped) */
SAY (" 2" == "2")         /* 0 -- strict comparison (blanks matter) */
```

### 6. No Short-Circuit Evaluation

ARexx evaluates ALL operands in logical expressions:

```rexx
/* This will FAIL if x is not numeric, even though we check first */
IF DATATYPE(x, 'N') & (x > 5) THEN SAY "big"
/* Both sides are evaluated! Use nested IFs instead: */
IF DATATYPE(x, 'N') THEN
   IF x > 5 THEN SAY "big"
```

### 7. PARSE ARG vs ARG

`ARG` uppercases the input; `PARSE ARG` preserves case:

```rexx
/* If called with "Hello World" */
ARG a                     /* a = "HELLO WORLD" */
PARSE ARG b               /* b = "Hello World" */
```

### 8. PULL Reads from Stack First

`PULL` reads from the external data stack first; only if the stack is empty does it read from the console. This can cause confusion if something was pushed/queued earlier:

```rexx
PUSH "surprise"
PULL input                /* Gets "SURPRISE", not console input */
```

### 9. SIGNAL Destroys Control Flow

SIGNAL is a GOTO. It exits all DO loops and SELECT blocks. You cannot SIGNAL into a loop or use it as a try/catch:

```rexx
SIGNAL ON ERROR
DO i = 1 TO 10
   ADDRESS COMMAND 'somecommand'
   /* If ERROR triggers here, the DO loop is abandoned entirely */
END
```

### 10. Return Values from Commands

Applications only return `RESULT` if `OPTIONS RESULTS` is set:

```rexx
/* Without OPTIONS RESULTS: */
ADDRESS 'MYAPP' 'GETDATA'
SAY RESULT                /* RESULT is uninitialized! */

/* With OPTIONS RESULTS: */
OPTIONS RESULTS
ADDRESS 'MYAPP' 'GETDATA'
SAY RESULT                /* Now contains the return value */
```

### 11. Semicolons as Statement Separators

Multiple statements can go on one line:

```rexx
a = 1; b = 2; c = 3
IF a = 1 THEN DO; SAY "yes"; END
```

### 12. The INTERPRET Trap

`INTERPRET` executes strings as code. It is powerful but dangerous:

```rexx
INTERPRET "SAY 'hello'"   /* Works */
/* But user input could be malicious -- avoid with untrusted data */
```

### 13. String Quoting

Strings are delimited by matching quotes. To include the delimiter, double it:

```rexx
SAY "She said ""hello"""  /* She said "hello" */
SAY 'It''s fine'          /* It's fine */
```

Unquoted tokens that are not keywords or valid numbers are treated as variable references.

### 14. No Shell Piping in ADDRESS COMMAND

AmigaDOS pipe handling through ARexx's ADDRESS COMMAND is unreliable. `ADDRESS COMMAND 'echo "hello" | grep hello'` does NOT work. Write input to a temp file first, then run the command with the file as input. See [Section 14: Common Pitfalls with Shell Commands](#common-pitfalls-with-shell-commands) for details and examples.

### 15. No Command Chaining with && or ;

AmigaDOS does not support `&&` for conditional chaining through ADDRESS COMMAND. The `;` separator may work in some shells but not through ARexx. Run commands as separate ADDRESS COMMAND calls instead.

### 16. Default FAILAT Is 10

Commands returning RC >= 10 trigger ARexx's ERROR condition by default. Use `OPTIONS FAILAT 21` at the top of test harnesses to prevent premature abort and ensure output files are always written. See [Section 14: FAILAT](#failat-error-threshold).

### 17. ASCII Only -- No UTF-8

ARexx (1987) does not understand UTF-8. Any non-ASCII byte in a `.rexx` file -- **including inside comments** -- causes "Error 8: Unrecognized token" and crashes the script. This includes em dashes (U+2014), smart quotes, accented characters, and any other multi-byte UTF-8 characters. Use only ASCII (0x00-0x7F) in all `.rexx` files.

### 18. Use ~= for Not-Equal, Not \=

Both `\=` and `~=` mean "not equal" in the ARexx spec, but `\=` may not be recognized by all ARexx interpreters (including ARexx 1.15 on Workbench 3.1). Always use `~=` for portability. Same applies to `~==` (strictly not equal) vs `\==`.

### 19. Dollar Signs in Execute Scripts

When ARexx runs `ADDRESS COMMAND 'Execute scriptfile'`, the AmigaDOS shell processes the script. Dollar signs (`$`) in the script are interpreted as AmigaDOS variable substitution (e.g., `$RC` for return code). If a command argument contains a literal `$` (e.g., `sed -n '$p'`), it will be expanded or cause an error. Workaround: write the sed expression to a script file with `-f`, or use a different addressing syntax.

---

## 20. Testing Patterns

This is our primary use case for ARexx -- running ported programs, capturing output, and comparing results for automated testing.

### Basic Test Runner

```rexx
/* test_program.rexx -- Test a ported CLI program */
/* Run a program, capture output, compare with expected */

SIGNAL ON ERROR
SIGNAL ON IOERR

program = 'Ported:myprogram'
pass_count = 0
fail_count = 0
test_count = 0

/* --- Test 1: Basic invocation --- */
CALL test_output program, '', 'expected_output.txt', 'Basic invocation'

/* --- Test 2: With arguments --- */
CALL test_output program, '-v input.txt', 'expected_verbose.txt', 'Verbose mode'

/* --- Test 3: Exit code --- */
CALL test_rc program, 'nonexistent_file', 10, 'Error exit code'

/* --- Summary --- */
SAY ''
SAY '=== Test Results ==='
SAY 'Passed:' pass_count 'of' test_count
IF fail_count > 0 THEN DO
   SAY 'FAILED:' fail_count
   EXIT 10
END
SAY 'All tests passed.'
EXIT 0

/* ---- Test Subroutines ---- */

test_output:
   PROCEDURE EXPOSE pass_count fail_count test_count
   PARSE ARG cmd, args, expected_file, description
   test_count = test_count + 1

   /* Run program, capture output */
   actual_file = 'T:test_actual_' || test_count
   ADDRESS COMMAND cmd args '>' actual_file
   cmd_rc = RC

   /* Compare output */
   IF ~EXISTS(expected_file) THEN DO
      SAY 'FAIL:' description '(expected file missing:' expected_file')'
      fail_count = fail_count + 1
      RETURN
   END

   /* Diff the files */
   ADDRESS COMMAND 'diff' actual_file expected_file '>NIL:'
   IF RC = 0 THEN DO
      SAY 'PASS:' description
      pass_count = pass_count + 1
   END
   ELSE DO
      SAY 'FAIL:' description '(output mismatch)'
      fail_count = fail_count + 1
   END

   ADDRESS COMMAND 'delete' actual_file 'QUIET'
   RETURN

test_rc:
   PROCEDURE EXPOSE pass_count fail_count test_count
   PARSE ARG cmd, args, expected_rc, description
   test_count = test_count + 1

   ADDRESS COMMAND cmd args '>NIL:'
   IF RC = expected_rc THEN DO
      SAY 'PASS:' description '(RC=' || RC || ')'
      pass_count = pass_count + 1
   END
   ELSE DO
      SAY 'FAIL:' description '(expected RC=' || expected_rc || ', got RC=' || RC || ')'
      fail_count = fail_count + 1
   END
   RETURN

ERROR:
   SAY 'Command error at line' SIGL ': RC=' RC
   RETURN
IOERR:
   SAY 'I/O error at line' SIGL
   EXIT 20
```

### Testing with Inline Expected Output

```rexx
/* test_wc.rexx -- Test word count program */
/* Compare program output against inline expected values */

program = 'Ported:wc'
pass = 0
fail = 0

/* Create test input */
CALL create_test_file 'T:test_input.txt', 'Hello world' || '0a'x || 'Foo bar baz' || '0a'x

/* Test: line count */
CALL run_test program '-l T:test_input.txt', '2', 'Line count'

/* Test: word count */
CALL run_test program '-w T:test_input.txt', '5', 'Word count'

/* Cleanup */
ADDRESS COMMAND 'delete T:test_input.txt QUIET'

SAY 'Results:' pass 'passed,' fail 'failed'
IF fail > 0 THEN EXIT 10
EXIT 0

run_test:
   PROCEDURE EXPOSE pass fail
   PARSE ARG cmd, expected, desc
   ADDRESS COMMAND cmd '>T:test_out'
   IF OPEN('f', 'T:test_out', 'R') THEN DO
      actual = STRIP(READLN('f'))
      CALL CLOSE 'f'
   END
   ELSE actual = '(could not read output)'
   ADDRESS COMMAND 'delete T:test_out QUIET'

   IF actual = expected THEN DO
      SAY 'PASS:' desc
      pass = pass + 1
   END
   ELSE DO
      SAY 'FAIL:' desc '(expected="' || expected || '", got="' || actual || '")'
      fail = fail + 1
   END
   RETURN

create_test_file:
   PROCEDURE
   PARSE ARG filename, content
   IF OPEN('f', filename, 'W') THEN DO
      CALL WRITECH 'f', content
      CALL CLOSE 'f'
   END
   RETURN
```

### Structured Test Output (TAP-like)

```rexx
/* test_suite.rexx -- Produce machine-parseable test output */

CALL ADDLIB 'rexxsupport.library', 0, -30, 0

test_num = 0
pass_num = 0
fail_num = 0

/* Run tests */
CALL tap_test 'program starts', test_rc('Ported:myapp --version', 0)
CALL tap_test 'help flag works', test_rc('Ported:myapp --help', 0)
CALL tap_test 'bad flag returns error', test_rc('Ported:myapp --badarg', 10)
CALL tap_test 'output matches expected', test_diff('Ported:myapp input.txt', 'expected.txt')

/* TAP footer */
SAY ''
SAY '1..' || test_num
SAY '# passed' pass_num 'of' test_num
IF fail_num > 0 THEN EXIT 10
EXIT 0

/* TAP output */
tap_test:
   PROCEDURE EXPOSE test_num pass_num fail_num
   PARSE ARG description, result
   test_num = test_num + 1
   IF result THEN DO
      SAY 'ok' test_num '-' description
      pass_num = pass_num + 1
   END
   ELSE DO
      SAY 'not ok' test_num '-' description
      fail_num = fail_num + 1
   END
   RETURN

/* Test helpers */
test_rc:
   PROCEDURE
   PARSE ARG cmd, expected_rc
   ADDRESS COMMAND cmd '>NIL: 2>NIL:'
   RETURN (RC = expected_rc)

test_diff:
   PROCEDURE
   PARSE ARG cmd, expected_file
   ADDRESS COMMAND cmd '>T:tap_actual'
   ADDRESS COMMAND 'diff T:tap_actual' expected_file '>NIL:'
   result = (RC = 0)
   ADDRESS COMMAND 'delete T:tap_actual QUIET'
   RETURN result
```

### Testing Pattern: Input/Output Matrix

```rexx
/* Run multiple input/output test cases from a specification */

/* Define test cases as: input_file expected_output_file args */
cases.0 = 4
cases.1 = 'T:empty.txt    T:expect_empty.txt    ""'
cases.2 = 'T:one_line.txt T:expect_one.txt      ""'
cases.3 = 'T:multi.txt    T:expect_multi.txt    "-n"'
cases.4 = 'T:binary.dat   T:expect_binary.txt   "-c"'

DO i = 1 TO cases.0
   PARSE VAR cases.i input_file expected_file args
   actual_file = 'T:actual_' || i
   ADDRESS COMMAND 'Ported:myapp' args input_file '>' actual_file
   ADDRESS COMMAND 'diff' actual_file expected_file '>NIL:'
   IF RC = 0 THEN SAY 'PASS: case' i
   ELSE SAY 'FAIL: case' i
   ADDRESS COMMAND 'delete' actual_file 'QUIET'
END
```

---

## 21. Command Utilities

| Command | Syntax | Description |
|---------|--------|-------------|
| `RX` | `RX name [args]` | Execute an ARexx script |
| `RXLIB` | `RXLIB name [pri [off [ver]]]` | Add/remove/list function libraries |
| `RXSET` | `RXSET [name [[=] value]]` | Manage Clip List entries |
| `RXC` | `RXC` | Close the RexxMast resident process |
| `WaitForPort` | `WaitForPort portname` | Wait up to 10s for a port (RC=0 found, RC=5 timeout) |
| `HI` | `HI` | Halt all running ARexx programs |
| `TCO` | `TCO` | Open global tracing console |
| `TCC` | `TCC` | Close global tracing console |
| `TS` | `TS` | Start interactive tracing for all scripts |
| `TE` | `TE` | End tracing for all scripts |

---

## 22. Error Codes

| Code | Severity | Message |
|------|----------|---------|
| 1 | 5 | Program not found |
| 2 | 10 | Execution halted |
| 3 | 20 | Insufficient memory |
| 4 | 10 | Invalid character |
| 5 | 10 | Unmatched quote |
| 6 | 10 | Unterminated comment |
| 7 | 10 | Clause too long |
| 8 | 10 | Invalid token |
| 9 | 10 | Symbol or string too long |
| 10 | 10 | Invalid message packet |
| 11 | 10 | Command string error |
| 12 | 10 | Error return from function |
| 13 | 10 | Host environment not found |
| 14 | 10 | Requested library not found |
| 15 | 10 | Function not found |
| 16 | 10 | Function did not return a value |
| 17 | 10 | Wrong number of arguments |
| 18 | 10 | Invalid argument to function |
| 19 | 10 | Invalid PROCEDURE |
| 20 | 10 | Unexpected THEN or WHEN |
| 21 | 10 | Unexpected ELSE or OTHERWISE |
| 22 | 10 | Unexpected BREAK, LEAVE or ITERATE |
| 23 | 10 | Invalid statement in SELECT |
| 24 | 10 | Missing or multiple THEN |
| 25 | 10 | Missing OTHERWISE |
| 26 | 10 | Missing or unexpected END |
| 27 | 10 | Symbol mismatch |
| 28 | 10 | Invalid DO syntax |
| 29 | 10 | Incomplete IF or SELECT |
| 30 | 10 | Label not found |
| 31 | 10 | Symbol expected |
| 32 | 10 | Symbol or string expected |
| 33 | 10 | Invalid keyword |
| 34 | 10 | Required keyword missing |
| 35 | 10 | Extraneous characters |
| 36 | 10 | Keyword conflict |
| 37 | 10 | Invalid template |
| 38 | 10 | Invalid TRACE request |
| 39 | 10 | Uninitialized variable |
| 40 | 10 | Invalid variable |
| 41 | 10 | Invalid expression |
| 42 | 10 | Unbalanced parentheses |
| 43 | 10 | Nesting limit exceeded |
| 44 | 10 | Invalid expression result |
| 45 | 10 | Expression required |
| 46 | 10 | Boolean value not 0 or 1 |
| 47 | 10 | Arithmetic conversion error |
| 48 | 10 | Invalid operand |

Use `ERRORTEXT(code)` to retrieve the message string programmatically.

---

## Sources

- AmigaOS Wiki: AmigaOS Manual: ARexx (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx)
- AmigaOS Wiki: ARexx Instructions (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Instructions)
- AmigaOS Wiki: ARexx Functions (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Functions)
- AmigaOS Wiki: ARexx Elements of ARexx (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Elements_of_ARexx)
- AmigaOS Wiki: ARexx Parsing (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Parsing)
- AmigaOS Wiki: ARexx Input and Output (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Input_and_Output)
- AmigaOS Wiki: ARexx Special Variables (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Special_Variables)
- AmigaOS Wiki: ARexx Error Messages (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Error_Messages)
- AmigaOS Wiki: ARexx Command Utilities (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_ARexx_Command_Utilities)
- AmigaOS Wiki: External Function Libraries (https://wiki.amigaos.net/wiki/AmigaOS_Manual:_External_Function_Libraries)
