# ARexx Introduction

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

ARexx -  by now it's a  buzzword in the Amiga community. ARexx is a 

logical evolution of CLI and CLI commands. As a  command language, it controls external applications. You can use ARexx to tell a  word processor to format text and then tell the desktop publishing program
(using ARexx) to import and print the text. ARexx was conceived as a 

commercial product. Starting with the AmigaOS 2.0, it is a  component of the Amiga operating system. Compared to simple CLI commands, variable manipulation is easier, and because variable manipulation is simple, ARexx is at least as powerful as BASIC. But can BASIC indirectly control application programs?

Author: Christian Kuhnert 

## 4.1 The ARexx Language

ARexx is not new. Since 1987, the Amiga version of Rexx by William S. 

Hawes has been commercially available. Since then, ARexx has become 

the de-facto standard for external program control on the Amiga. No serious commercial program can afford not to access the ARexx-Port as part of the Amiga multitasking operating system.

Including ARexx in the Amiga 2.0, as a  component of the operating 

system, was the next logical step for Commodore. This decision can also be interpreted as a  decision against other models of processor communication, like the IPC project in the PD field, an approach that is not as complex, but also not as flexible. This book is not intended to be a  complete guide to programming in
ARexx our focus is how an interrupt directed to ARexx can make 

application programs configurable, expandable and sometimes enable connection to other programs. An experienced user of structured programming languages like C,
Modula, or Pascal (or any BASIC dialect with structured form) will 

understand ARexx immediately.

Rexx is the name of a  programming language that was developed at two 

IBM research sites in England and the USA between 1979 and 1982. Its 

main characteristics are:

• Universal applicability: Rexx is not dedicated to a  certain 

application (or application type). Many programming languages make this claim and ARexx is actually better suited to applications that value higher running speed over programming speed.

"Type-less" data: all data are treated as character strings at first. No 

type classification takes place until a  specific operation is performed. Defined data types such as integers, floating decimals, bytes and words are not natural limits, but machine terms. These are limitations Rexx developers intended to avoid.

No declarations: variables must not, as in many programming 

languages, be declared before use in this sense, Rexx is like BASIC or APL. Even very large data fields do not have to be previously dimensioned.

Only a  few basic commands: about 10 commands are sufficiently 

powerful to create complex programs. There are a  total of about 30 commands.

Easy string manipulation: the scope of the language includes many 

functions that perform string manipulation, which makes this aspect more developed than in other languages.

Easy error trapping: the Rexx interpreter has a  powerful TRACE 

function. The trace function also enables interruptions during program execution.

"Human" Logic: instead of following firm syntax formalities, Rexx 

normally does what is intuitively right. This means that if you just think about the problem, you will usually come to the correct result without looking anything up.

## 4.2 The Functions ofARexx

## 4.2 The Functions of ARexx

Because it transmits input to the processor, Rexx is especially well-suited 

as a  script or batch language for automatic control of an operating system or as a  macro language. These operations are the same thing, but in the latter case, Rexx controls an application program.

Almost every operating system has a  shell or batch language each has its 

specific features and special functions. The same holds true for macro languages that are specially designed to configure and control an individual program, such as an editor or a  database manager.

Rexx was developed with an eye toward becoming a  universal command 

language. Rexx can pass commands to an external environment (or an operating system) and receive an answer in return.

Rexx is also capable of acting as a  universal programming language, 

because it enables the creation of function libraries. These effectively expand the scope of the language itself. Specifically, Rexx makes program development and testing quick and easy.

## 4.3 An Overview of ARexx

All Rexx programs begin with a  C-style comment. "/*" is expected at the beginning of the program by the interpreter. This convention encourages the programmer to document the purpose of the program with a  short comment. A  complete Rexx program would appear as follows:

/* A  simple example program */ 

SAY "I am.

SAY is a  Rexx command. It displays the following expression, which is a 

character string. You do not have to type commands in capital letters the interpreter only differentiates between large and small letters within character strings. Double quotation marks (") or simple quotations (') define a  character string. The simplest counterpart to "say" is "pull":

/* Calculate body weight in engl. stones */ 

say "Please enter your body weight in Kg! pull weight say "That equals" weight/ 6. 3 48 "stones.

PULL waits for a  user entry and assigns it to the variable ("weight"). As 

you can see, the variable name did not need to be specified. Even an error in user entry (like typing a  letter) would have no consequences in the "Pull" line, since variables always contain character strings. Once the string is divided in the last line, the input must be interpreted as a  number with a  floating decimal. An error message does not appear until the division in the last line is impossible then the program stops. Numbers can be written with a  decimal point or in exponential notation. By using the NUMERIC setting, the number of decimal places can be set. Although it doesn't appear to mean anything, the space character between the two expressions is also an operator for the SAY command. The space indicates that it should concatenate with a  space inserted in the program. The empty space can also be inserted within the two strings. Then the individual expressions are directly concatenated this too forces concatenation, but without additional empty spaces.

## 4.3 An Overview ofARexx

An explicit concatenation operator also exists: "II" -  it directly connects the contents of two variables, without an empty space.

Rexx has all the usual commands for program control. The most 

important and complex of these is the DO ...END group, which (like
BEGIN...END in Pascal, or {...} in C) is a  simple command grouping. It's 

used to control the formation of program loops: a  sub-keyword
FOREVER sets up unlimited repetition, a  run-time variable can increment 

to a  maximum value, or a  BY can issue a  step width. A  FOR sets a maximum number of loops. Program termination conditions are WHILE or UNTIL. These commands can be combined in a  meaningful manner with other commands that iterate and leave, go to the next step, or exit from loops. There is also an IF...THEN...ELSE construction and a  process like
"switch" in C, called SELECT...WHEN...OTHERWISE...END. There is no 

"Goto" command. The SIGNAL command jumps to labels within a 

calculation, but not within command groups or loops. These always terminate with the SIGNAL command. Together, all of these lead to clearly structured programming.

/* Calculate factor */ 

ARG number /* read in argument */ 

result=l /* result (-ing) variable initialized */ if number<0 /* For negative entry */ then return /* cancel */ do n=l to number /* Loop with run-time variable n  */ result=result*n end n  /* the entry 'n' is optional */ say number"! =" result

Along with the use of a  "do" loop, this example shows another possible 

method of data entry: ARG reads arguments listed after the Rexx command into variables. If this program is started by entering RX FACULTY 7, the "number receives the value "7". If the "if query receives a  negative number, it cancels the program with the RETURN command. If the input is over 171, the result is not correct. 1. 797693 14E+308 is the upper limit for the program. An error message "Arithmetic overflow" is not implemented in ARexx 1.14.

ARexx requires a  certain amount of care when dealing with very large or 

very small numbers, since false results do occur. The reason for such limitations may be ARexx's use of the mathieeedoubbas.library for all arithmetic calculations. Perhaps this will be changed in future versions. In the next example, the program is defined as an internal function. For
Rexx, functions are a  part of the language, defined in programs or 

externally accessed in libraries.

/* example for function definition and call */ 

do n=l to 9 say n"! =" fak(n) /* call fak */ end n return /* program end */ fak: procedure /* function name local variable */
ARG number /* read argument */ 

result=l if number<0 then return " Error ! do n=l to number result =result*n end n return result /* end the function with value output*/ The function "fak" is defined in the lines after the label "fak:". The key word PROCEDURE is necessary because the main program uses the same run-time variable ('n') as this function. A  separate variable environment is defined for the function, so the program works with local variables.

ARG reads arguments (given in the parentheses) at the function call and 

ends the function with a  return. It outputs the background expression and replaces the call with that value.

## 4.4 ARexx -  Rexx on the Amiga

ARexx is a  version of Rexx that's used on the Amiga as a  command and 

macro language. Rexx's rather unusual mathematic capabilities are considered less important than its program control features. ARexx is easy to use and many operating tasks can be automatically handled by the interpreter. Compared to the standard version, this version is slightly expanded. Unfortunately, because of changes in file operations, porting data is more difficult However, the expansions are used to adapt the Rexx language to the qualities of the Amiga. Although this makes the language easier to use, it also decreases its speed. Amiga BASIC is about six times faster than
ARexx (Version 1.12). Although the running speed can be increased 

slightly, ARexx isn't suitable for large-scale programming.

Because all data are handled as strings, which require frequent internal 

conversions, and functions are called by runtime linking, this language offers limited programming possibilities. In the future, a  compiler for
ARexx may be available. If this happens, further applications may be 

possible. However, even compiled code would barely reach the speeds of
C-compiled applications. 

The core of the ARexx system is the Rexx master procedure, which manages function libraries and common data structures. This procedure waits in the background for the start of an ARexx program, which is often performed using the CLI program "rx". Any program can use the
Rexx port to call a  Rexx program. Rexx searches the current directory 

and then a  logical device named Rexx: (if it is installed) for the desired program. Every ARexx program starts a  separate task that reads and executes the source code with the Rexxsyslib.library, which contains the actual interpreter. In this way, an unlimited number of ARexx programs can be run simultaneously, even with limited storage capacity.

## 4.5 A  Sample Application

The following program can be used to experiment with the Rexx language. A  simple line interpreter can be used to execute ARexx commands directly and interactively. It can also be expanded to become a complete and easy-to-use shell, fully replacing the CLI. A Rexx program can be created using any editor. If you want to run it from CLI, give it the tag .Rexx and store it in the "Rexx:" directory. Call it from CLI by typing "rx program_name". If the Rexx master procedure is not already running, "rx" starts it and then executes the Rexx program.

/* interactive Rexx interface */ 

address command /* command destination is the CLI */ options prompt "Rexx> "        /* A  prompt for pull */ start: /* entry point at error */ signal on syntax /* At error moves to the equivalent */ signal on error /* label branching instead cancel */ do forever /* endless loop */ parse pull input /* Wait for entry */ interpret input /* execute entry as an ARexx line */ end /* next loop */ syntax: /* at syntax error output message */ say "Error" re "in line" sigl":" errortext (re) signal start /* . . .and so forth*/ error: /* at command error ...*/ say "Returncode: " re /* ...output Returncode */ signal start /* ...and so forth*/ The ADDRESS sets the destination for the external command. Rexx views all free-standing expressions (those that are not used by a  Rexx command) as expressions that are to be transmitted to an external environment. To specify DOS as the recipient, use the COMMAND address otherwise the name of the Rexx Message Port would be the called program. The OPTIONS prompt is a  specific command for Rexx that results in an output of the strings defined as a  user entry prompt when PULL is executed.

SIGNAL ON indicates that the error condition listed after it should not 

lead to a  program stop, but to an equivalent label in the program. By doing this, errors can be trapped. When this is executed, all running "do groups end and the corresponding Signal flag is turned off, as they are in the direct jump command using "SIGNAL Label". After error handling you are unable to continue the program, instead you must address a defined entry point. Special system variables contain the line number
(SIGL) after interrupt conditions, or in this case the error code or the 

return code. The use of these variables becomes clear in the two blocks at the end of the program. ERRORTEXT() is a  built-in Rexx function that outputs an appropriate (English) text for a  given Rexx error number.

PARSE transmits character strings to variables. It also offers a  powerful 

and simple procedure for string manipulation and cutting. Although PARSE PULL waits for an entry from the console, there is no capitalization of the entry, as in the PULL command.

INTERPRET is a  very simple but powerful command. The expression that 

follows is simply executed as a  Rexx command.

Experiment with this program it quickly gives you an understanding of 

how Rexx works.

## 5.1 Using Tokens

ARexx programs can contain all ASCII symbols. Either uppercase or 

lowercase letters can be used, since all symbols are automatically converted to capital letters. An ARexx program must begin with a  comment. The interpreter then searches for a  clause, usually a  single line, that is delimited by a  semicolon
(), keywords or a  colon (after an individual character). The tokens 

contained in the clause are then evaluated from left to right.

Tokens are the smallest, self-contained units in the language, such as 

words in a  sentence. They are separated by empty spaces (or, for operators, by their parameters). The interpreter differentiates among comments, symbols, strings, operators, and special characters.

### 5.1.1 ARexx Symbols

Symbols are characters (A, a..z, 0..9), .!?$#@ and _  (Underscore). 

Alphabetical characters that appear in a  symbol are converted to capital 

etters. There are four types of symbols:

Constants begin with a  number or a  decimal point. 

Simple variables do not begin with a  number and do not contain a 

period.

Stem are like simple variables, but have a  period at the end. 

Compound variables begin with a  stem, followed by one or several 

constants or simple variables, each delimited by a  period. The value of a  constant symbol (that is not necessarily a  number) is the name of the symbol, in capital letters. Other symbols are variables. They can be assigned a  value during the program run. If a  variable has not been given a  value, it is an uninitialized variable and acts as a constant its value is then its capitalized name. For example:

## 47.11 /* a  constant */

7NewYorkers /* a  constant, but not a  number. 

=> 7NEWY0RKERS */ 

Field. /* a  stem symbol */ 

Field. 3 .Where?/* a  compound variable */ 

Stems and compound variables have special qualities that enable unusual 

programming techniques. The structure of a  compound variable is
"stem.nl. n2....ni". The name before the first period is the stem symbol and 

every other element, from "nl" to "ni", is either a  constant or a  simple variable. Whenever the interpreter finds a  compound variable, the elements in it are evaluated. These strings can contain any characters, even spaces, and are not converted to capital letters. A  new variable name is created and its contents are then calculated. For example, if "X has the value 5  and "Y" has the value 2, then "a.x.y" creates the new name "A.5.2". By using the stem you can call or initialize an entire group of variables. If a  stem is assigned a  value, all combined variables that contain the stem also receive the same value.

Compound variables can also be used as addressable arrays or stacks. 

For example, if you wanted to show the area code of a  city with the city name, you could create two fields "CITY" and "AREACODE". Paired values would be stored with the same index. The field "CITY" would be searched for the desired entry and "San Francisco" would be found with the index "415". In this case, "AREACODE.415" would contain the appropriate area code. In Rexx you can take another approach: the variable "CITY" could contain the name of the desired place and
"AREACODE.CITY" would evaluate into "AREACODE.SanFrancisco", 

which would lead directly to the desired number. Although this process offers faster access to the data, it's not reversible. You cannot use the same field to look for the city name by area code, which is possible with the first method.
