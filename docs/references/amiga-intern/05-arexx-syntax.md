# ARexx Syntax

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

## 5.1 Using Tokens

### 5.1.2 Character Strings in ARexx

Strings are character strings that begin and end with quotation marks ("). 

The quotation mark itself can be included by typing it twice (""). Single quotes can be used instead of quotation marks. Strings must be written on one line only. Empty character strings are called "null strings". A string followed by an open parenthesis "(" is assumed to be a  function name. An "x" or "b" immediately following indicate hexadecimal or binary evaluation of the string. In this case, only the characters (0..9 and a..f for "x" and 0  or 1  for "b") can be contained in the string. (Empty spaces can be used to make the program readable.) Such character strings are immediately converted into strings with the equivalent ASCII symbols. Enter control codes or memory addresses in this way. For example:

■ Is there a  grammar ' 

/* 

simple example */

"Is it possible...

/* 

=> Is it possible... 

n ii

/* 

Null-String*/ 

"Say ""It is true"" !

/* 

=> Say "It is true"! 

"49 42 4d"x 

/* 

big blue in hex*/

"00110000"b 

/* 

binary for ASCII 0*/

### 5.1.3 The ARexx Operators

Operators are the characters ~+-*/=x&lA. Empty spaces (even between 

them) make no difference to the ARexx interpreter. The space character itself, placed between symbols or strings, is an operator. The execution of operators has a  set order. Operators with equal priority are executed from left to right.

Operator 

Priority 

Meaning 

+ 

logical negation prefix: conversion

** 

* 

/ 

prefix: negation exponentiation multiplication division

% 

integer division remainder

+ 

addition

- 

subtraction concatenation

(space) 

> 

< 

concatenation with empty space exact equality exact inequality normal equality normal inequality greater than greater than or equal less than

& 

less than or equal logical AND logical OR logical exclusive OR

### 5.1.4 ARexx Special Characters

The special characters ",:()" also have meaning. For example: semicolonC) A  semicolon separates individual clauses. Normally, this is indicated by a  line feed. Semicolons are used to put several clauses on one line. commaO A  comma prevents the automatic semicolon, if a  clause extends over several lines. (Commas also separate the arguments of a  function call from one another.) colon(:) If there is a  symbol in front of a  colon, a  branching

(Label) is defined. A  colon also implies a  semicolon. 

parentheses(O) A  single open parenthesis, directly following a  symbol, forces interpretation of the clause as a  function name.
Closed parentheses also form expression groups. This is 

used to alter the regular operator priority.

## 5.2 Expressions

Expressions consist of one or several terms, with or without operators. 

They can be strings, symbols, or function calls, perhaps grouped with parentheses. Between a  pair of terms, there is always a  dyadic element. There can be one or several prefix operators affecting the term. Strings are always interpreted as character strings, as are constant symbols
(converted into capital letters). Variable symbols are replaced with their 

contents, or regarded as constant symbols. Function calls are recognized by an open parenthesis, followed by a  symbol.

Arguments contained in parentheses are evaluated and passed to the 

function in place of the arguments. The calculated value is returned. The value of an expression is determined in order by parentheses and operator priority. First the symbols that are contained in it are replaced. For example: fak(n) "is the factorial of" n This expression consists of the function call "fak(" with the argument expression "n", a  concatenation operator (concatenation with empty spaces), the string "is a  factorial of, a  further chain, and the variable symbol "n".

First, the interpreter determines the function argument and then calls the 

function. The function, if it's not defined as a  procedure, can assign a  new value to the variable "n". At the second occurrence of "n", another content is calculated. The order of evaluation does not affect the calculation here, only its position. In short, symbols are always evaluated from left to right and replaced by the resulting value. If there is a  function call, it's executed first, then the symbol value replacement process resumes. After this, the expression is evaluated under the priority rules. If the operator priority ranking is equal, an evaluation order is not defined.
So, the analysis moves from left to right, as the Rexx language definition 

implies (and algebraic rules state and programmers expect). Exceptions to the rule have not been observed.

Both sides of logical operators are always evaluated, even if the result is 

already clear:

(2=2) I     (120 =   fak(5)) 

For example, "fak(" is always fully executed, even if analysis has already determined that the result of the procedure is 1 .

Operators can be divided into four groups: arithmetic, concatenation, 

comparison, and logical operators.

### 5.2.1 Arithmetic Operators

Prefix conversion (+) 

This operator acts as a  prefix. The given number is converted to internal notation, rounded, and formatted according to the NUMERIC settings.

" 12.34 "  ==> '12. 34

"2.0009 ==> '2.001' (with DIGITS=3) 

Prefix negation (-) 

The single negation prefix changes the sign of the operand. It also has the same effects as the prefix for conversion (+).

-" 7.23 "  ==> '-7.23' 

-3E3 ==> '-3000' 

Exponentiation (**) 

The left operand (base) is evaluated as the exponent of the right operand (exponent). The exponent must be an integer. The number of decimal places (for positive exponents) is the product of the exponent and the number of places given after the decimal point in the base number.

2**8 ==> 256 

4**-l ==> 0.25 

0.1**3 ==> 0.001 

Multiplication (*) 

Calculates the product of the terms to the left and right 

of the operand. The number of decimal places is

determined by the sum of the decimal places in the two terms.

4*7 

0.5*1.50 

=> 49 

=> 0.750 

Division (/) 

Determines the quotient of the two numbers. The 

number of decimal places is as large as necessary, and can be limited by the setting of NUMERIC DIGITS.

8/4 

8/3 

==> 2 

==> 2.667 (with DIGITS=3) 

Integer division (%) 

Calculates the quotient of two numbers. The integer 

portion of the result is returned.

8%3 

==> 2 

Remainder (//) Returns the remainder of an integer division of the 

dividend terms. To determine the remainder of "a//b",
"a-(a%b)*b" is calculated. 

8//5 

-7//3 

3.7//0.2 

==> 3 

==> -1 

==> 1 

Addition (+) 

Calculates the sum of two terms. The number of decimal 

places in the result is determined by the higher number of decimal places in one of the terms.

3 +  15 

==> 18 

2.7+2.04 

==> 4.74 

Subtraction (-) 

Calculates the difference between two terms. As in 

addition, the number of decimal places is determined by the higher number of places in one of the two.

### 5.2.2 Concatenation Operators in ARexx

These operators combine two strings into a  new string. There are three such operators: The explicit concatenation operator (II) connects two strings without an empty space.

-BE" I  I "TA" ==> BETA 

• The direct concatenation operator, for example, a  symbol and a 

string, specified right after one another. This results in a  chain without an empty space. be"TA" ==> BETA

• The null concatenation operator is when two strings are specified 

with one or more spaces between them an empty space is inserted between them in the concatenation.

"with" "empty" "space" ==> with empty space 

### 5.2.3 Comparison Operators in ARexx

The are three different comparison modes:

• Exact includes empty spaces strings of different length are never 

equal in exact comparison.

• String comparison disregards leading spaces and adds trailing 

spaces to fill a  shorter string to equivalent length.

• Numeric transforms the operands to numeric notation, using the 

setting of NUMERIC DIGITS to determine the number of decimal places. Then an arithmetic comparison is made and NUMERIC
FUZZ sets the specificity of that calculation. 

With the exception of the exact equality and inequality operators, all comparison operators automatically differentiate between numeric and string comparisons. If both terms are valid numbers, a  numeric comparison is made otherwise it is assumed to be a  string comparison.

All comparison operators output a  Boolean truth value: 0  for false or 1 for true. The comparisons ">", "<", ">=" and "<=" are used for strings, as defined in the ASCII code. This means:

"A"<"B" ==> 1 

■A'<'a' ==> 1 

### 5.2.4 Using Logical Operators

All four logical operators require two Boolean operators (a 0  or 1) and return a  Boolean result. These operators cannot be used for bit-level logical combinations. (For such purposes, use the built-in BITxxx() functions.)

Logical NOT (~) 

Inversion: 0  becomes 1  and 1  becomes 0. 

Logical AND (&) 

Returns a  1 if both operators are true. 

Logical inclusive OR (I) 

Returns a  1 if one of the operators is true. 

Logical exclusive OR (A or &&) 

Returns a  1 if one of the operators (not both) is true. 

## 5.3 ARexx Clauses

Clauses are the smallest executable units of the Rexx language. They can 

be divided into five groups:

### 5.3.1 Null Clauses

Lines that consist of empty space or comments are null clauses. They are 

also formed if two semicolons follow one another. These clauses are ignored by Rexx.

Comments are character strings of one or more lines that are contained in 

"/*" and "*/" they can be set inside one another, but must appear in pairs 

(which, in ARexx, do not have to appear on one line). They hardly affect 

execution speed and can be used liberally. A  first run through the interpreter removes them and their function is taken by an empty space.

### 5.3.2 ARexx Label Markers

A symbol immediately followed by a  colon is a  label marker. (The colon also implies a  semicolon here.) Such markers serve as targets for CALL and SIGNAL commands and internal function calls. Several markers can follow one another. If the same label marker appears twice in a  program, only the first is located.

### 5.3.3 Assignments in ARexx

A variable symbol followed by an equal sign (=) is an assignment clause. In this case, the operator does not have its normal comparison function, instead it becomes an assignment operator. The terms to the right of the equal sign are analyzed as an expression and the result becomes the content of the variable symbol on the left.

### 5.3.4 ARexx Commands

A clause that starts with a  command keyword is a  command clause. Often a single command represents an executable action, or several commands
(for example, SELECT groups) are combined to form clauses. They are 

not syntactically complete until all necessary commands are available.

### 5.3.5 Commands

An expression that cannot be assigned to any other type of clause is assumed to be external commands. The expression is then analyzed and the result is passed to the specified external environment. The address can be an external application (for example, an editor) or DOS
("COMMAND"). 

6. Instructions 

6. Instructions 

Instructions consist of one or more words that are recognized as a  key 

word. The keyword must appear as the first token in the clause. It cannot be preceded by a  colon (:), it would then be a  label, or an equal sign (=), which indicates a  variable. Some key words call for further parameters of sub-keywords. We don't recommend that you define a  variable "SAY" or a function "NUMERIC" because the readability of your program can suffer.

I/O Instructions Control Instructions 

ARG ADDRESS 

ECHO CALL 

PARSE DROP 

PULL INTERPRET 

PUSH NUMERIC 

QUEUE OPTIONS 

SAY PROCEDURE 

SHELL 

Structural trace 

Instructions upper 

BREAK 

DO 

ELSE 

END 

EXIT 

IF 

ITERATE 

LEAVE 

NOP 

OTHERWISE 

RETURN 

SELECT 

SIGNAL 

THEN 

WHEN 

6. Instructions 

