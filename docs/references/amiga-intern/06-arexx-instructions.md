# ARexx Instructions

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

rsRG

Represents 

section.

'PARSE UPPER ARG". For more information, see that 

IECHO 

An ARexx synonym for SAY. For more information, see that section.
| PARSE 

] 

Syntax: PARSE [UPPER] source [template] [.template. .. ] 

Function: In Rexx, PARSE is the main input instruction. It takes data 

from various sources and passes it on to one or several variables, efficiently parsing character strings. The effect of the input character string can be selected using the following sub-keywords:

ARG Character strings passed to the program at the call or 

function are parsed. Each program usually receives one string functions are capable of receiving up to 15, separated by commas, that are then parsed out according to templates.

EXTERNAL An entry is read into the function from "stderr". If "stderr" is 

not defined, the function returns the null string.

NUMERIC Current settings of NUMERIC are received as a  string in 

the following order: DIGITS, FUZZ and FORM, each separated by an empty space.

PULL Reads a  string from "stdin", that is usually input from the 

keyboard. If nothing is found in "stdin", program execution halts until something is entered. The function QUEUED can query how many lines have been saved in "stdin".

SOURCE Returns a  string of data on how the program was called, in 

the form "{COMMANDIFUNCTION} {011} Type Result

Called Resolved Ext Host". The first word signals whether 

the call is a  program or a  function. Then a  Boolean value indicates whether a  result string has been requested.
"Called" is the name with which the program was invoked, 

"resolved" is the full path and file extension of the program 

(usually ".rexx"). "Host" is the initial host address for 

external commands.

VALUE expression WITH 

An expression that calls for the sub-keyword WITH. An expression is evaluated and the result is used as the parse input string. The keyword "WITH" is used to separate the expression and the template.

VAR Variable 

The values of the given variables are used as the parse input sting. If several templates are entered, the current value of the variable is taken each time. (It can also change if the same variable appears in the template.)

VERSION Returns a  string in the form "ARexx Version CPU MPU 

Video Freq". The value of "Version" is the interpreter 

revision (i.e. "V1.21"), "CPU" is the processor type
("680x0"), and "MPU" is the math-coprocessor ("6888x", if 

present, otherwise "NONE"). "Video" returns to video system ("PAL" or "NTSC") and "Freq" returns the network frequency ("50HZ" or "60HZ"). The UPPER keyword forces a  translation of the source data into capital letters and it's used before the keyword, which indicates the source.

Templates can be assembled from symbols, strings, operators or 

parentheses. The function parses source strings into sub-strings that are assigned to the symbols in the template. The process ends when all variables have been assigned values. If a  source string is completely evaluated, before all listed variables obtain a  new value, the remaining variables are assigned the null string. There are three important template functions:

6. Instructions 

Parsing by words 

If the variable names follow directly after one another delimited only by an empty space, the source string is parsed (using the spaces) into words, each of which is assigned to the next available variable. The last variable receives the remainder of the string. A  period (.) can be used as a  "place- holder" in a  template, acting like a  variable, but not actually receiving the corresponding part of the string. For example:

/* VERSION returned: "ARexx VI. 15 68030 68882 PAL 50HZ" */ 

parse version .  Revision CPU MPU . say Revision CPU MPU In this example the first word "ARexx" is not informative it is to be deleted and so a  period appears. After the parse is executed, the variable
"Revision" contains "  VI. 15", CPU the value "68030" and MPU is 

"68882". The rest of the source string is uninteresting it is absorbed by 

the second period, same as the first word.

Parsing by position 

Absolute or relative positions of individual elements of the source strings 

can be specified using numeric values, between the symbols. Relative positions are differentiated from absolute positions by their prefixes
(monadic "+" or "-" operators). For example: 

Test =  "1234567890

parse var Test 3  a 5  b +3 4  c say a  b c  /* => 34 567 4567890 */

Parsing by pattern 

If elements of the source string are separated by keywords or other specific characters, these can be searched and the parsing will follow the
"pattern markers." The function also removes markers it finds from the 

source string this means the string is changed during a  pattern parse. An example:

/* The program was called with the argument "DRIVE dhO: name Bingo".*/ 

parse arg "DRIVE" Drive "NAME" Name say Drive name

/* => dhO: Bingo*/ 

See also: ARG, PULL, UPPER 

I PULL 

PULL is short for "PARSE UPPER PULL". For further information, see 

that section.

I PUSH 

Syntax: push [expression] 

Function: PUSH prepares input lines for another program that expects 

entry from "stdin". During the function, a  "Return" (ASCII
13) is attached to "expression" and the result is stored in 

the "stdin" channel along the "LDFO principle" (Last In First
Out). The last line stored with PUSH is the first read from 

"stdin". The number of lines waiting in "stdin" can be 

queried with the function QUEUED.

Caution: This instruction should only be used with interactive DOS 

devices that are driven by a  DOS handler that supports the
"ACTION_STACK" instruction (or CON:, PIPE:, and similar 

input). This is especially important if you are attempting data redirection.

See also: 

IQUEUE 

QUEUE, QUEUEDO 

Syntax: queue [expression] 

Function: QUEUE prepares input lines for another program that 

expects entry from "stdin". The value of "expression" is a single "Return" (ASCII 13) the result is stored in the "stdin channel along the "FIFO principle" (First In First Out). The first line stored with QUEUE is also the first read from
"stdin". The number of previously stored lines in "stdin" can 

be queried with the function QUEUED.

Caution: This instruction should only be used with interactive DOS 

devices that are driven by a  DOS handler with an
"ACTION_QUEUE" instruction (or CON:, PIPE:, and others 

6. Instructions 

like them). This is important for scripts involving input redirection.

See also: PUSH, QUEUED() 

^AY 

Syntax: say [expression] 

Function: The value of "expression" receives a  single "Return" (ASCII 

13) and is written to "stdout", which is usually the monitor, 

and displayed there.

[BREAK I 

BREAK is only allowed within DO instructions. For more information see 

that section.

IPO I 

Syntax: do [Iteration] [Condition] 

[Instructions] 

END [Symbol] 

DO is used to group instructions together and possibly execute them 

again. The iteration takes the form:

[Symbol=ExprI] [TO ExprT] [BY ExprB] ]     [FOR ExprF] 

or : ExprR or : forever All expressions that appear in the instruction must result in a  number.
ExprR and ExprF must be positive integers. The key words BY, TO, and 

FOR can appear with a  matched expression (that is analyzed once at the 

beginning) in any order.

• The formal element "Symbol=ExprI" defines a  run-time variable and 

supplies an initial value to it. It must follow the key word DO.

• BY ExprB: Determines the increment added to running variables 

with each iteration. If BY is not specified, it is assumed to be 1.

• TO ExprT: Sets the upper limit (or lower limit, depending on the 

increment) of the run-time variable. If this limit is overstepped during an iteration, the loop terminates and the program continues at the corresponding END.

• FOR ExprF: Specifies the maximum number of repetitions. When 

this value is reached, the DO loop terminates, regardless of the value of a  run-time variable. If all you need is to specify the number of repetitions, you can use the ExprR form.

• FOREVER: If you do not need an index variable, this key word 

ensures repetition. This kind of loop ends with a  LEAVE or
BREAK. For example, the condition can read: 

6. Instructions 

WHILE ExprW 

or: UNTIL ExprU

ExprW and ExprU must return "0" or "1". 

WHILE ExprW: This expression is evaluated at the beginning of 

each iteration. If it returns a  "1", the loop continues a  "0" terminates it.

• UNTIL ExprU: Has the same function as WHILE, but with reverse 

logic. If it's a  "0", the loop is terminated if it's a  "1", the loop continues. The DO group is closed with the END instruction, after which a  counting variable can be specified. This is helpful for debugging, since nesting errors during DO loops can be recognized by the interpreter. It also improves program readability.

Structural instructions in DO groups 

BREAK, LEAVE [Symbol], ITERATE [Symbol]. 

BREAK terminates the inside DO group. Program execution continues 

after moving to the corresponding END. This is also the action an
INTERPRET instruction forces in implicit DO groups. 

In contrast, LEAVE is only allowed in DO loops. LEAVE terminates the inside DO group and execution continues after the corresponding END. A variable can be set here to terminate several embedded DO loops simultaneously, if your run-time variable is controlled in one of the outer loops.

ITERATE does not terminate the DO loop, but rather jumps back to the 

top of it. The value determined with BY is added to the run-time variable, all conditions are evaluated and, if appropriate, the next iteration starts. The variable specified after ITERATE acts analogously to the variable function in LEAVE.

| ELSE ~~| 

ELSE is only valid within an IF instruction. For further information, see 

that instruction. ffiND

] 

END is an element of DO and SELECT groups. For more information, see 

that section.

I EXIT 

See also: 

EE 

] 

Syntax: exit [expression] 

Function: This instruction terminates the program where it is read and 

passes (if indicated) a  return value to the calling program. If a return string is requested, the result of "expression", a character string, is stored in the allocated storage block and a pointer to that block is set to RESULT_2. If no string was requested and the program was running as an instruction,
EXIT tries to evaluate the result of "expression" with INT 

and report it as the return code. The EXIT instruction
(without a  return value) is also implied by the end of a 

program.

RETURN 

Syntax: if expression 

THEN command 

[ELSE command] 

Function: The IF instruction conditionally executes instructions. The 

expression after IF must return a  Boolean result, a  "0" or
"1". If it's a  "1", the instruction (or DO group) named after it 

is executed. If the expression is "0", the instruction behind
ELSE is executed, if ELSE was specified. 

An ELSE clause always refers to the last IF. Nested IF instructions make it impossible to use one of these branches. In this case, a  dummy instruction (NOP) restores access to the next higher IF instruction. Just indicating an empty clause by typing two semicolons is not enough in
Rexx, as it is for other programming languages. For example: 

if 1+1=2 then if 2+2=4 then

/* outer IF */ 

/* inner IF */ 

6. Instructions 

say "The world is still alright. else NOP /* belongs to the inner IF */ else say "Nothing is happening anymore!" /* belongs to the outer IF */

See also: NOP 

I ITERATE I 

ITERATE is only applicable within DO loops. For more information, see 

that description.

I LEAVE 

LEAVE is only applicable within DO loops. For more information, see 

that section.

I NOP ~l 

Syntax: nop 

Function: Basically, "No OPeration" is a  dummy instruction that does 

nothing. The instruction takes on meaning during IF instructions it has no other function.

I OTHERWISE ~i 

OTHERWISE is part of the SELECT instruction. For more information, 

see that section.

I RETURN 

Syntax: return [expression] 

Function: Used to end one function and continue program execution 

where it was called. "Expression" is analyzed and the result is the returned value of the function. Functions called from within an expression must return a  result, or an error message appears. Placing a  RETURN in the main program is not an error, it is equivalent to EXIT.

See also: EXIT 

I SELECT 

Syntax: select 

WHEN expression [  ] then [  ] command 

[OTHERWISE [] [Instructions]] 

END 

Function: The SELECT instruction is used to make a  choice among 

several different possibilities. After it, a  series of WHEN constructions can follow, each of which must contain an expression that returns a  Boolean result, and a  instruction
(or DO group) that is to be executed if the result of the 

expression is "1". But only the first WHEN group whose
Boolean expression returns a  1 is executed. If none of the 

expressions are true, instructions behind the key word
OTHERWISE are executed. This can comprise an entire list 

of instructions. OTHERWISE and END shape a  simple DO group in this respect. The OTHERWISE construction is not required in a
SELECT instruction. If no WHEN construction is executed, 

it's either called or an error message appears.

I SIGNAL 

] 

Syntax: 

Function: 

SIGNAL {ON I  OFF} Condition 

or: SIGNAL {  [VALUE] expression

Label } 

There are two basic forms of the SIGNAL instruction. The first is used to switch error trapping flags on and off. The second is an expression used to transfer control this one is evaluated. A  control transfer should be used sparingly. It is primarily useful for resuming the program at a  defined location after an error condition.

Error interrupts make it possible to recognize error 

conditions that would otherwise lead to program termination, and perhaps to catch them before they do. If
"SIGNAL ON condition" is used to activate a  specific error 

interruption, the program is not stopped, instead it branches

6. Instructions 

ITHEN 

to a  label indicated by the key word of the corresponding condition. The following key words are available:

BREAK.C fctriWcl: Break has occurred. 

BREAK_D [ctrlhfDl: Break has occurred. 

BREAK_E |ctri|4H: Break has occurred. 

BREAK.F [ctnl+fFl: Break has occurred. 

ERRORS The return code passed by an external 

program was not "0".

FAILURE The return code was greater than the 

FAILAT setting. 

HALT A  HALT was encountered (after "hi", for 

example).

IOERR DOS has reported an I/O operation error. 

NOVALUE An undefined variable was called. 

SYNTAX There have been syntax or execution errors. 

This is only used within IF and SELECT instructions. For more information, see that section.

| WHEN 

] 

WHEN is also only used within a  SELECT instruction. For more 

information, see that section.

[ADDRESS | 

Syntax: ADDRESS {Symbol I  string} expression 

ADDRESS {Symbol I  String} 

ADDRESS [VALUE] expression 

ADDRESS 

Function: ADDRESS defines the target of an external command. Its 

argument must provide the name of an ARexx message port, listed in the Public Port List of "exec". The first form shown does not change the current setting, it only sends a command to a  certain ARexx port. The name of the port is specified as a  symbol (that can be variable) or a  string. Then the command character string to be passed to the external message port follows. The next two forms of ADDRESS set a new target command host. In the third form, the name of the target is an expression that must first be analyzed.

VALUE is only necessary if the expression starts with a 

symbol or character string. The interpreter also stores the indicated target the last form of the examples shown
(without parameters) toggles between two addresses. 

The default setting is "REXX". The "COMMANDS" host is a special target address (it represents DOS). To query the current setting, use the internal function ADDRESS(). Any clause that only contains a  single expression that the interpreter cannot manipulate in any way, is assumed to be an external command and passed to the appropriate port.

See also: SHELL, ADDRESS() 

fCALL |

Syntax: CALL {Symbol I  String} [Exp. ]  [,Exp.,...] 

Function: Calls an internal, built-in, or external function. The function 

name (as a  string) can be a  symbol that in turn can be a variable or a  character string. Entering a  character string

6. Instructions 

bypasses the internal function search of the program. This instruction controls functions internal to the interpreter, or external functions, which are protected from re-definition in the running program. Following CALL, if necessary, one or several expressions, separated by commas, can present arguments for the function (for external functions, the maximum number is 15) that can then be accessed with
ARC 

In contrast to the usage of the direct function call "Symbol
(Arg,Arg, ...)", which is analyzed to return a  value 

immediately, CALL returns its result to the system variable
RESULT. If no value results, RESULT remains un- 

initialized after the call.

IDROP 

Syntax: DROP symbol [Symbol . . . ] 

Function: Variables are deleted with DROP. They are placed in an un- 

initialized state, in which the value of the variable is the variable name itself. It is not a  mistake to use DROP on a previously un-initialized variable. If a  stem (a symbol ending with a  period) is specified as the variable to be dropped, all variables that use this stem are re-set.

| INTERPRET 1 

Syntax: INTERPRET expression 

Function: The result of "expression" is interpreted as an ARexx 

program. By using this instruction, entire sections of the program can be evaluated only when the program is actually run. The result of "Expression" is executed as if it were surrounded by an implied DO ... END" group.
LEAVE or ITERATE instructions can only refer to DO 

loops also defined here. BREAK makes it possible to leave the INTERPRET instruction and continue the program.
Branching instructions in the expression are ignored by the 

interpreter and you cannot define a  function using
INTERPRET. 

I NUMERIC 

Syntax: NUMERIC {DIGITS I  FUZZ} [Expression] 

NUMERIC FORM {SCIENTIFIC I  ENGINEERING} 

Function: NUMERIC sets the form of number representation and the 

precision of numeric operations.

DIGIT [Expression] 

Sets significant places in arithmetic operations. 

"Expression" must be an integer between 1  and 14, larger 

than the current NUMERIC FUZZ setting. Small adjustments here should be made with care, since all operations, including run-time variables, are affected. If
"Expression" is not included in the clause, the default 

setting is 9. The current setting can be queried with the function DIGITS().

NUMERIC FUZZ [Expression] 

Returns the number of places (from the right) to be 

disregarded during numeric comparison and rounding operations. "Expression" must evaluate to an integer from 0 to 13 that is smaller than the current NUMERIC DIGITS setting. If it's omitted, 0  is the default setting. The current setting can be queried with the function FUZZ().

NUMERIC FORM (SCIENTIFIC I  ENGINEERING} 

Determines the type of display for results in exponential 

notation. Choices are the academic style (with numbers between 1  and 10 in front of the decimal point), the
SCIENTIFIC (default) setting, or engineer's display in 

which the exponent is always a  multiple of 3. The current setting can be called with the function FORM(). These
NUMERIC settings are protected during a  call to a 

function and set back after completing it.

See also: PARSE NUMERIC, OPTIONS 

6. Instructions 

| OPTIONS 

Syntax: options failat expression 

OPTIONS PROMPT expression 

OPTIONS [NO ] CACHE 

OPTIONS [NO ] RESULTS 

OPTIONS 

Function: OPTIONS is the general instruction to set various default 

settings in the interpreter.

FAILAT Expression: Sets the limit after which return codes lead to a 

FAILURE report. The default setting is the FAILAT setting 

in the calling program (normally 10). "Expression" must return a  positive integer value.

PROMPT Expression 

Sets a  character string to be used with PARSE PULL or 

PULL instructions as a  user entry prompt. Normally, there is 

no prompt.

[NO ]CACHE 

Switches the internal instruction cache (in the interpreter) 

on or off. This switch, which increases function speed, is normally on.

[NO 1RESULTS 

Tells the interpreter whether or not it should request a 

result string when it executes an external instruction.

Use OPTIONS without any parameters to reset the default 

settings. The settings you make with OPTIONS are (such as
NUMERIC settings) secured for the duration of function 

calls.

| PROCEDURE ~| 

Syntax: PROCEDURE [EXPOSE VSymbol [VSymbol . . . ] ] 

Function: Used within an internal function to define its variables (up 

to RETURN) as local variables. The function then has no access to the main program variables unless indicated with

I SHELL 

the (optional) key word EXPOSE. In the list that's placed after the EXPOSE variable stems or concatenated variables indicate variables that remain accessible. In this case, the order of exposure is important. For example, the variable Q has the value 45 in the main program. After "PROCEDURE expose Q  RS.Q", the variables Q  and RS.45 are still available to the function. If the instruction had been given as "PROCEDURE EXPOSE RS.Q Q", then RS.Q and Q would be exposed. Concatenated variables are evaluated from left to right.

J 

SHELL is an ARexx synonym for ADDRESS. For more information, see 

that section.

ITRACE 

Syntax: TRACE [Symbol I  String I  [VALUE] Expression] 

Function: The TRACE instruction controls running ARexx programs 

and is most often used for error analysis. Since you usually have to enter this instruction by hand, the syntax is kept short (the first letter suffices to name the key words). They are ALL, BACKGROUND,
COMMANDS, ERRORS, INTERMEDIATES, LABELS, 

NORMAL, RESULTS, SCAN and OFF. If the result of the 

expression you enter does not display one of these sub-key words, the interpreter attempts to convert it into an integer value. If this is not possible, an error message occurs.

Two special characters precede the key words: "?" controls 

interactive tracing and "!" toggles execution of external commands.

Positive numeric entry forces a  certain number of lines in 

the TRACE to elapse before the next display. Negative values indicate the number of lines to be skipped by the trace function. Negative values are only considered during interactive tracing.

6. Instructions 

See also: TRACE() 

1 UPPER 

Syntax: upper vsymbol [vsymbol . . . ] 

Function: The content of the variables following UPPER are 

converted to capital letters. If a  stem is specified, all variables with this stem are affected. Entering an undefined variable is not an error, instead it leads (if active) to a
NOVALUE interrupt. Although you can use the built-in 

functions TRANSLATE() or UPPER(), the UPPER instruction is faster and easier, especially if several variables are to be converted.

See also: TRANSLATEQ, UPPERQ 

## 6.4 Commands

The special quality of the Rexx language is that there is an entire class of syntactic units that are not evaluated by the interpreter. Instead, they are passed to an external environment. Each clause that contains an expression unknown to the interpreter is seen as a  command meant for an external environment and passed on. These instructions are directed with ADDRESS. You can send a  DOS (COMMAND) or an application program call using the ARexx interface. The expression is analyzed and passed on to the external environment as a  character string. Then the external program executes your entry and passes back a  return code that indicates whether or not the execution was successful. The result can also be a  character string. The advantage to this characteristic is that macro programs can easily be created to control and expand application programs. As indicated, a  command is any expression that has no meaning for the interpreter. The command structure you type is entirely dependent on the external program for which it is intended.
Often that is an alphanumeric name, followed by parameters. Commands 

can be written as strings or symbols. If you do not intend to pass the name as a  variable parameter, it is safer to enter it as a  literal (string), since then it will not be mistakenly read as an ARexx key word or redefined in a variable assignment. For example: jumpto L+3 C

"select disk font" "ruby. font" 12 

"end of file

are all valid commands for "CygnusEd Professional 2". They can be executed by CygnusEd if "ADDRESS rexx_ced" indicates that the
CygnusEd ARexx port is the target for the commands. 

The basic idea of function definition is to indicate a  program or a  group of directions should always be carried out when the function name appears in an expression. In ARexx, a  function can be part of a  program
(internal function), a  built-in interpreter function, in an external function 

library, or a  stand-alone program. The interpreter recognizes function calls when a  symbol or string is followed directly by a  left open parenthesis "(". The symbol or string indicates the function name and a list of arguments begins after the open parenthesis. There can be several expressions (that can contain functions) separated by commas to form arguments or none at all. The expression is analyzed from left to right and passed to the function. The following are valid function calls:

DIGITS ( ) 

"XRANGETA", »Z") 

showdir (  °dhO :  fonts ■ There is no limitation on the number of arguments passed to internal functions the maximum arguments that can be passed to external functions is 15. The result is a  string that's used in place of the function call. Functions are also retrieved with CALL (see Chapter 6). Use CALL when no result string is needed.

During a  function ARexx searches for the function in a  specific function 

order:

1. Internally: If the function name appears as a  label in the script, the 

current state of interpretation is secured (including status information such as TRACE and NUMERIC settings). At the location where the function is found, execution continues. When it ends, with a  RETURN clause, there must be a  final argument. In other words, a  function must return a  value. If the function name was specified as a  string, this step of the search is omitted.

2. Built-in: The built-in function library is searched for the given 

function. All names in the library are spelled with capital letters they are described in the following sub-sections of this book.

3. External function libraries and environments: All available function 

libraries are stored in a  list that simultaneously sets priorities for the search order. Each function library is searched with a  separate offset

"QUERY" to check whether or not the given name is in the library. 

External function environments are called using a  message protocol 

similar to a  command syntax.

4. External ARexx programs: Finally, the interpreter tries to start an 

ARexx program with this name. The current directory is searched 

first, then the logical device "REXX:". Upper or lowercase spelling do not matter.

Internal and built-in functions do apply capitalization. For external 

functions it depends on the comparison algorithm being used in the
QUERY routine. If you must use lowercase letters in a  function name, the 

call to the function must be a  written as a  string, since symbols are always converted to uppercase and the lowercase distinctions are lost.
