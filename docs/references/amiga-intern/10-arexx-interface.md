# The ARexx Interface

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

## 10.1 Essential Data Structures

In most applications, the programmer uses two structures with ARexx. The ARexx "arg structure" is used for all strings handled by the interpreter. Normally, they are passed as arg strings, with pointers that indicate the string. The Rexx "msg structure" is used for all communication with external programs and is structurally an expansion of the EXEC message form.

Arg strings: all strings in ARexx are stored as Rexx arg structures, 

created for each string in an equivalent length. Strings are passed as arg strings (i.e., a  pointer to the area where data is located in the Rexx arg structure). The data always ends with a  zero in order to allow treatment as normal C  strings in other programs. Additional data such as length, hash value etc. can then be accessed with negative offset of the arg string pointer. struct RexxArg {
LONG ra_Size 

UWORD ra_Length 

UBYTE ra_Flags 

UBYTE ra_Hash 

BYTE ra_Buff [8]  

} 

/* reserved total length of the structure */ 

/* length of the string */ 

/* attribute of a  string */ 

/* hash value */ 

/* data area (where the arg string points) */ 

/* minimum size: 16 bytes*/ 

There are library functions used to create arg strings (CreateArgstringO) and to delete them (DeleteArgstringO), as well as converting from whole numbers into this format.

Message Packets 

All communication between ARexx and external programs takes place with RexxMsg structures. There is a  function in the ARexx system library that lets you create them (CreateRexxMsgO) and one to delete them (DeleteRexxMsgO).

Messages sent by ARexx, for example, to pass a  command to an 

application program, have the same form as those that move in another direction to start a  macro program. You can distinguish one from the other because all messages that are sent by ARexx contain a  pointer to the string "REXX" in the name slot of the node. This can be useful in distinguishing messages when a  port receives them from several sources.

struct RexxMsg {

STRUCT Message rra_Node /* 

APTR rm_TaskBlock /* 

APTR rm_LibBase /* 

LONG rm_Action /* 

LONG rm_Resultl /* 

LONG rm_Result2 /* 

STRPTR rm_Args [16] / * 

/* 

STRUCT MsgPort *rm_PassPort  /* 

STRPTR rm_CommAddr  /* 

STRPTR rm_FileExt /* 

LONG rm_Stdin /* 

LONG rm_Stdout /* 

LONG rm_avail /* 

} /* 

and EXEC message structure */ pointer to the sender's task structure */ pointer to RexxSysBase */ action codes */ primary result (Returncode) */ secondary result */ pointers to arguments 0-15*/ the expanded area */ pointer to the next port*/ name of its own port */ file name extension */ file handle of the input data-flow*/ file handle of the output data-flow */ for future expansion */ size: 128 bytes*/

Resource Nodes 

A further useful structure is often used by ARexx to set up resource lists: the Rexx "rsrc structure". It has a  variable length, that is entered in the structure, along with the address of the function used to remove the structure. This means that heterogeneous lists can be set free by calling
RemRsrcList(). 

## 10.2 Requirements for a  Command

Interface 

An application program that wants to communicate with ARexx only needs a  public message port and a  program input that can process the commands received there. Usually this isn't too much to manage, since many programs often already have several message ports receiving keyboard and menu operations. For a  program that's directed by commands, it processes the incoming commands easily and reacts accordingly. With menu-driven programs, more work is necessary once commands do more than just activate individual menu options. Which commands are recognized, and the syntactic form of each, depends on the programmer. An application program sends a  command call message to the Rexx master procedure, usually in direct response to user entry. As soon as the report is received, a  new DOS procedure starts, that examines the command line, takes the first word, and searches for an equivalent macro program file (possibly with an application-specific extension that was passed with the filename). When a  file of the same name is found, the program is executed. Usually the program sends back one or more commands to the public port of the calling program. While one is being executed, the macro program waits until it receives a  return code from the command. If an error is encountered, it should be able to handle it logically. Finally, the macro program should end and pass the command call message back to the application program with an appropriate return code.

Error trapping in macro programs is an important feature of 

communication. Macro programs must be able to recognize whether a command was executed correctly, or if something went wrong in the process in order to react intelligently to whatever happens.

Normally, a  command call message is not answered if the error status that 

followed the command is known. Programs that receive commands from a message port, from user input and handle both with the same routines, must be able to differentiate between the two input modes. A  flag indicates what happens in case of an error. In the first case, an appropriate error code can be returned and in the second case, with direct input, an error message should also display on the screen.

## 10.2 Requirements for a  Command Interface

Return codes that appear in the result slot of the message should also 

report the severity of the error. Small whole numbers would indicate relatively harmless errors, and large numbers would appear with major errors. This enables a  programmer to set a  "failure level" in order to ignore small errors and report those that exceed it. Other than this convention, a programmer has free choice of error codes. Every program meant to support the command interface must open a public message port. If a  command is to be sent to the program, it receives a Rexx message with the rm_Action entry "RXCOMM" and an arg string pointer to the command line in ARGO, at this port. The other ARG entries are not used with commands. There are two pointer entries that could be interesting for the program: rm_TaskBlock points to the sender's task structure and rmJLibBase points to the base address of the ARexx system library. With the exception of the result code in rm_Resultl and possibly also rm_Result2, the program should not change the message. These appear when the corresponding command has been completed. rm_Resultl receives an error code, 0  if the command was carried out with no errors. This long word is later assigned to the variable RC in the macro program. If the macro program expects a  result string (indicated with the
RXFB_RESULT bit in the command code), the corresponding arg string 

pointer in rm_Result2 should be returned. A  result string should only be returned when it's requested and if rm_Resultl is zero otherwise a  zero must be entered in rm_Result2. If this convention is not followed, a  loss of memory capacity results. An unexpected result string can lead to a program crash if memory areas become free without being assigned (or at least not with an arg string).

Many application programs support simultaneous work on several data 

files: most word processors let users open windows with separate files in them. If an ARexx macro program is called by the editor, it must be clear to which file the returned commands apply.

ARexx supports this distinction with the entry rm_CommAddr, in which 

the opening ADDRESS setting for a  (new) macro can be entered. The word processor can then assign a  separate message port (for example,
"xyEditl", "xyEdit2", etc.) for each file, and report the appropriate name 

when macro calls are encountered.

Application programs can open several ARexx ports that can also be 

used to differentiate command classes, each of which is then sent to the correct port with the ADDRESS command.

ARexx program calls are made by sending a  corresponding report to the 

Rexx master procedure. Programs can be called as commands or as 

functions the command mode is generally easier and more free, since only a  few fields of the message must be completed. When an ARexx message structure is created, all entries are first set to 0.
Entries that are filled by the sending program are never changed by 

ARexx so that this structure can be re-used after the initial message is 

answered. For this reason, only one structure is necessary, which must then only be partially changed for new calls. In the rm_Action slot of the message, the mode of the call is determined. For command mode, RXCOMM is entered for function mode, RXFUNC. In addition, certain flags can be set, to enable options that are described later.

Command strings, function names, and arguments must be entered as arg 

strings. Normal strings can be comfortably created with the
CreateArgstringO function. Returned arg strings can usually be treated 

as normal strings, since the pointer refers to the data area (a string that ends with a  0). Because the corresponding strings are not changed in the course of an ARexx program, a  program may have to build up many of these structures. The pointer that is returned by CreateArgstringO is placed in the equivalent slot of the message: ARGO for the command string or function name, ARG1 to ARG15 for function arguments. When the message is answered, extra arg strings can be deleted with
Delete Argstring(). 

When all the necessary fields are filled, the report is sent to the public
Port "REXX" using the EXEC function, PutMsg(). Its address must first 

be determined with the function FindPort(), but this value should not be saved by the program because the port can be closed at any time. To ensure against program crash, you must bracket the calls to FindPort() and PutMsgQ with Forbid() and Permit().

After sending the message, the application program can resume its own tasks and the macro program runs as a  separate task. It's often useful to prevent further user input for the duration of the ARexx macro so that data accessed by the macro is not changed by the user.

### 10.2.1 Command Calls

Command mode returns a  command string to the calling program. The 

string consists of a  macro name, an empty space and arguments in whatever form necessary. ARexx takes the name, usually the name of the executing program, and tries to start it. Normally the rest of the command string is a  single argument the program uses. The RXFB_TOKEN flag can adjust behavior: if it's set, then the rest of the string is parsed into several arguments. In this process, words are separated as they would be with
PARSE. The number of arguments is not limited in this case, since they 

don't have to fit into the 15 available message slots. In order to prevent spaces that represent arguments from being divided, they can be enclosed in quotation marks [" "]. If such a  section contains quotation marks, use single quotes the two types of quotation symbols can be used alternately. Double entry of one of the symbols doesn't work here. At the end of the string, no quotation mark is necessary. For example, the call: test.rexx "The first argument" second "'one more' would mean that the command: parse arg A1,A2,A3 say Al say A2 say A3 would output as follows: The first argument second

' one more ' 

If the first element of a  command string is already in quotation marks, it's assumed not to be a  program name, but rather as a  single word. This is an easy method for starting very short ARexx programs (its length is not limited in any way). If RXFB_TOKEN wasn't specified, only the first section that appears in quotation marks is examined, and the rest is discarded. The rxfb_string flag defines the entire command string as an

ARexx program text. In this case, no parsing takes place and the program 

is immediately executed. Calls usually don't expect a  result string. The flag RXFB_RESULT can request it. The calling program must delete the string, which is hierarchically higher than itself, when it's no longer necessary.

### 10.2.2 Function Calls

Function calls pass a  function name and up to IS arguments as strings to 

the application program. The function name is used for access. The actual number of arguments (not counting the name) must be written to the lowest value byte of the command code. This form is normally used when a  result is expected (but this does not require the use of a  function call) or when several argument strings are already available. A  result is again requested with the RXFB_RESULT flag. After the function is completed, if no error took place, and Resultl is zero, the pointer in Result2 should be set to the equivalent string.

### 10.2.3 ARexx Program Search Order

Again, ARGO can contain a  complete program instead of a  filename. It's 

signaled with the rxfb_string flag.

Searching for program files is a  two-step process, in which the current 

name extension (".rexx", if nothing else is specified in the message) is attached to the filename, if not previously specified. If the search is unsuccessful, the un-expanded name is used for a  new search. If the name contains a  path, the program only looks there otherwise the current directory is searched first (possible with both name variations) and then the REXX: directory. A  command call with "RAM:t/examples would be searched for in RAM:t under the names "examples.rexx" and then "examples". Without the path name, the search order would be
"examples.rexx", "examples", "REXX:examples.rexx" and 

"REXX:examples". 

If a  program is still not found, one more possibility exists: If the message path rm_PassPort was filled in, the message is simply passed to the port specified there. This means that one command can be passed to several

programs, until one of them can do something with it. If there is a  0 the message is answered with an error code 1  ("program not found").

### 10.2.4 Expanded RexxMsg Structure Areas

Entries in this area of the message can adjust various default settings. If 

no settings are being changed, these can be left at zero.

Application programs should enter values for the appropriate name 

extension and the name of their own ports. The name extension is useful to identify macro programs for specific applications from other program files and should be specific to each program. Entering the port for the program is done so the addressed port is already set at the beginning of the macro. Since one program can have several ports and the macro must know where it should direct its commands, this is very important. Use the application program name or an abbreviation of it.

PassPort 

In the rm_PassPort slot, a  further message port address can be entered. The report is sent to this port if no corresponding program file is found. This port should be a  secured resource so that it cannot be removed until the message has been passed. It does not have to be a  public port for this reason it's not possible to make sure it's available before the message is passed on.

Host address 

An entry in the rm_CommAddr slot can indicate the ADDRESS setting for an ARexx program that is to be started. The entry includes a  pointer to a  string that closes with a  zero and contains the name of the public message port to which commands are to be directed. This option is very important for application programs that allow work on several files simultaneously and open a  separate message port for each file. The name of the correct ports are then passed to a  macro when it's called. If such an entry is not found, "REXX" is the default setting.

File Extension 

The entry for rm_FileExt changes the default value of ".rexx" for file name extensions. Application programs should enter a  specific extension here, common to all its macro programs. If it is a  pointer to a  string it is terminated with a  zero.

Input and output data flow 

Default values for data input and output of an ARexx program are 

directly taken from the procedure structure of the calling application program, as it's a  DOS procedure. One or both data streams can be diverted by entering corresponding DOS file handles in the rm_Stdin and rm_Stdout slots. The data flow cannot be closed as long as the program is running. Both values are entered directly in the procedure structure of the calling program. The output stream is simultaneously the pre-set target for trace output by the program. If interactive tracing is used, the output stream should always be defined to an interactive device like CON:, since user entry is also expected. If an ARexx program is called by an EXEC task, these entries are the only way to control input and output.

### 10.2.5 Result Entries

A message that is started by an ARexx program is answered as soon as it's completed. Two result entries then contain either error codes or a possible result string. If the primary result in rm_Resultl is zero, the program ran without errors and the pointer in rm_Result2 indicates a  result string, if requested. If the primary result is not zero, two things may have happened: either the secondary result is zero, meaning that the return code was passed with
"EXIT re", or it's "RETURN re". This can be an error code or a  result how 

this return code is handled depends on the calling program. If the secondary result is not zero, then the primary result is an error level indicating the severity of the error and Result2 is an ARexx error code. This should be reported to the user. In order to translate the error code to an equivalent text, the function ErrorMsgO is provided.

Result strings are the responsibility of the calling program and must be 

deleted with the DeleteArgstringO function when they are no longer needed.

## 10.3 The Rexx Master Procedure

All communication with the Rexx master procedure takes place using the message structure previously described. It contains a  command entry that indicates which operation is to be carried out and entries for the appropriate or necessary parameters. Messages received are immediately handled, either being answered or, in the case of program calls, passed on. The structure contains two result entries with which error codes or result strings are transmitted. In the parameter portion of the structure, either whole numbers of the "long" type or pointers to arg strings can be entered.

### 10.3.1 Action Codes

Valid command codes are described here. The commands are listed in 

order of their mnemonics, followed by the permitted flags. The resulting code is formed by a  logical OR of the action code and all necessary flags. This code is entered in the rm_Action slot.

IRXADDCON [RXFB NONRET] | 

Adds an entry to the cliplist. ARGO points to the name, ARG1 points to 

the data and ARG2 contains the length of the data. This is not required to be an arg string. The name should be a  string that closes with a  2ero, but the data itself can contain null bytes its length is explicitly indicated.

IRXADDFH [RXFB NONRET] | 

Adds a  function environment to the library list. The first argument, ARGO, 

points to a  name string closed with a  zero along with a  port. The argument ARG1 contains the search priority. A  priority can be specified as an integer ranging from -100 to 100. If a  previous entry of the same value exists, the message is returned with a  warning and the appropriate error code. No check is made to verify existence of the port.

103 The Rexx Master Procedure 

IRXADDLIB [RXFB NONRET] 1 

Adds an entry to the library list. The argument ARGO points to a  name 

string that ends with a  zero, with the name of the function library or of the function environment port. The search priority is set with ARG1, a whole number between -100 and 100 the remaining area is reserved for later expansion. The offset for the "query" function, specified in ARG2 and ARG3, contains the version number. If a  previous entry of the same name exists, the message is returned with a  warning and the error code.
Otherwise, the new entry is accepted and the library or function 

environment is available to ARexx programs. There is no check for actual availability of the library, nor whether it can be opened.

RXCOMM [RXFBTOKEN] [RXFBSTRING] [RXFBRESULT] 

[RXFB NOIO] 

Calls an ARexx program in command mode. ARGO must contain an arg 

string pointer to the command string. The flag RXFB_TOKEN specifies how the command string is to be parsed into several arguments. Or
RXFB_STRING indicates that the command string itself contains the 

program. This call usually does not deliver a  result string
RXFB_RESULT can be used to request one, but the calling program 

must then make sure this string is deleted after use. The argument
RXFB_NOIO prevents the input and output of the called program from 

being used by the caller.

RXFUNC [RXFB_RESULT] [RXFB_STRING] [RXFB_NOIO] 

Number args 

Calls to a  function. A  pointer in ARGO refers to the function name. ARG1 

to ARG 15 point to arguments. All of them must be arg strings. The lowest value byte of the action code is the number of arguments (not counting the function name). For function calls, RXFB_RESULT is used to request a result string, but this is not required. RXFB_STRING shows whether the entire command string contains the program. Finally, RXFB_NOIO prevents the input and output of the called program from being used by the caller.

|RXREMCON[RXFB NONRET] 

Removes an entry from the cliplist. ARGO is a  string that closes with a 

zero and points to the name to be removed. The cliplist is searched for an entry with the desired name. If it's found, the entry is removed from the list and the storage area it occupied is released. If the name is not found, the message is returned with an error code.

IRXREMLIB [RXFB NONRET] 

Removes an entry from the library list. ARGO is a  string that closes with a 

zero and points to the name to be removed. The library list is searched for an entry with the desired name, whether it's a  function environment or a system library. If it's found, the entry is removed from the list and the storage area it occupied is released. If the name is not found, the message is returned with an error code. The entry is not removed if an ARexx program is in the process of calling it.

1RXTCCLS [RXFB NONRET] | 

Closes the global Trace window. If no ARexx program is waiting for 

entry from the Trace window, it's immediately closed otherwise the program waits until the active programs are no longer using it.

IRXTCOPN [RXFB NONRET] | 

Opens the global Trace window. After this instruction, the Trace output 

from all active ARexx programs is redirected to the Trace window. User entry, for interactive tracing, is also expected there. There can only be one open Trace window at a  time if it's already open, the message is returned with a  warning.

### 10.3.2 Action Code Control Flags

In addition to the command codes, individual bits can be inserted in the action code to activate special functions. In the individual commands, only certain flags are accepted, all others are ignored.

RXFB_NOIO With the command code RXCOMM or RXFUNC, this 

flag prevents automatic transfer of input and output data to the calling program.

10 J  The Rexx Master Procedure 

RXFB_NONRET 

Determines that the recipient will not respond to the 

report. This also means that it doesn't matter to the sender whether or not the operation was successful, since there is no other way to inform it about success or failure. The message is transferred of the receiver and must be released by it with DeleteRexxMsg().

RXFB_RESULT 

With RXCOMM or RXFUNC, this flag controls the transfer of a  result string. If the program or the function ends with EXIT (or RETURN) and passes on an expression, the calling program receives this expression as an arg string. If this result is no longer needed, the calling program must remove it with DeleteArgstringQ.

RXFB STRING 

With RXCOMM or RXFUNC, this flag indicates that
ARGO does not contain a  filename, but that a  complete 

ARexx program was passed (which then does not have 

to be within a  set of quotation marks).

RXFB TOKEN 

Demands, in connection with the command code 

RXCOMM, that the data following the program name 

not be passed as a  complete argument, but instead parsed into words and transformed into several arguments. Areas enclosed in quotation marks are not parsed, so that spaces are possible. At the end of the command strings, no additional quotation marks are necessary.

### 10.3.3 Managing the Results

The Rexx master procedure conforms to Amiga code conventions for the result that's passed in rm_Resultl . This is an error level set for "warning at 5  (WARN) and, for more serious errors, reads as 10 (ERROR) or 20
(FAIL). The value in rm_Result2 is then either zero or an ARexx error 

number, if an appropriate one is available.

## 10.4 Functions in rexxsyslib. library

The ARexx interpreter is part of the Amiga operating system library
"rexxsyslib.library". Many of the functions in it are only used by the 

interpreter and are not documented. Others can be of use to other programs that use ARexx.

System library functions are meant to be called from assembly language 

programs and generally only affect registers A0 and Al, as well as DO and Dl. Many functions return values in several registers in order to reduce code. In addition, the functions control the status register CCR, if appropriate. Usually CCR refers to the value returned in DO. The function offsets are defined in the file rexx/rxslib.i, included after
Kickstart 2.0 and should be linked in matching assembler source code. It 

can also be called from C  programs, if appropriate code is included in the link.

Overview of available functions 

IIO Functions 

There are two groups of I/O functions: the low level uses DOS file handles directly, while the higher level works with lists of I/O buffer structures and supports logical filenames.

CloseFO 

close file buffer

CreateDOSPktO 

create a  DOS standard packet structure and initialize it

DeleteDOSPkt() 

delete a  DOS standard packet structure

DOSRead() 

read from a  DOS file

DOSWrite() 

write to a  DOS file

ExistF() 

test whether a  file exists

FindDevice() 

test whether a  DOS device exists

OpenF() 

open a  file buffer

QueueF() 

queue a  line in a  file buffer

ReadF() 

read a  character from a  file buffer

ReadStr() 

read a  string from a  file buffer

SeekF() 

moves the access pointer to a  specific position

StackF() 

adds a  line to the file buffer

WriteFO 

writes characters to a  file buffer

## 10.4 Functions in rexxsyslib.library

String Manipulation 

ARexx treats all data as strings. These functions perform common string 

operations.

CmpStringO 

compare string structures

LengthArgstringO 

calculate the length of an argument string

StcToken() 

select a  token

StrcmpN() 

compare strings

StrcpyA() 

copy a  string and convert to ASCII

StrcpyN() 

copy a  string

StrcpyU() 

copy a  string, converted to capital letters

StrflipN() 

transpose a  string

StrlenO 

determine the length of a  string

Conversions 

CVa2i() 

convert ASCII to INT

CVc2x() 

convert CHAR to HEX or BIN

CVi2a() 

convert INT to ASCII

CVi2arg() 

convert INT to an ASCII arg string

CVi2az() 

convert INT to ASCII with leading zeros

CVs2i() 

convert string structure to INT

CVx2c() 

convert HEX or BIN to CHAR

ErrorMsgO 

calculate error number from an error message

ToUpperQ 

convert ASCII to capital letters

ARexx Resource Handling 

AddClipNodeO 

assign a  clip node

AddRsrcNode() 

assign a  resource node

ClearMemO 

delete a  storage area

ClearRexxMsgO 

delete arg strings from a  message

ClosePublicPortO 

release a  port resource node

Create ArgStringO 

create an arg string structure

CreateRexxMessage() 

create an ARexx message structure

CurrentEnv() 

determine pointer position in the current storage environment

Delete ArgstringO 

release an arg string structure

DeleteRexxMsg() 

release an ARexx message structure

FillRexxMsgO 

fill arg strings in a  Rexx message

FindRsrcNode() 

find a  resource node

FreePort() 

close a  message port

FreeSpaceO 

release internal storage

GetSpaceO 

reserve internal storage

InitListQ 

initialize a  list header structure

10.4.1 

InitPortO 

IsRexxMsgO 

LengthArgstringO 

ListNames() 

LockRexxBase() 

initialize a  message port check a  message calculate the length of an arg string list node names in an arg string protect a  global resource from data write calls

OpenPublicPortO 

RemClipNode() 

RemRsrcListO 

RemRsrcNodeO 

UnlockRexxBase() 

create a  port resource node release a  clip node release a  resource list remove a  resource node release a  resource

I/O Functions 

ICloseFQ 

Closes file buffer! 

Syntax: 

success =  CloseFdoBuf f )
DO AO 

Releases the IoBuff structure and closes the matching 

DOS file. An entire list of IoBuff structures can be 

deleted with a  single call to RemRsrcListO each individual structure is then processed with an automatic
CloseF(). 

CreateDOSPkt 0 

Creates and initializes a  DOS standard 

packet structure

Syntax: 

See also: 

packet =  CreateDOSPkt ( )
DO AO 

(CCR) 

Reserves a  storage area for a  DOS standard packet 

structure and initializes it by linking it to the EXEC message and DOS packet sub-structures. A  ReplyPort is not automatically added, since entries are normally filled in immediately before sending the message.

DeleteDOSPktO 

IDeleteDOSPktQ 

Syntax: 

Releases a  DOS standard packet structure] 

DeleteDOSPkt (message) 

AO 

Releases a  DOS standard packet structure, that has 

normally been created earlier with a  call to
CreateDOSPkt(). 

See also: 

| DOS Read () 

CreateDOSPktQ 

Reads from a  DOS file | 

Syntax: count =  DOSRead( filehandle, buffer, length) 

DO AO Al DO 

(CCR) 

Reads characters from the DOS "filehandle" into the 

"buffer". "Length" is the maximum number of characters 

to be read, "count" returns the actual number of characters read after the call, or -1, if an error was encountered.

IDOSWriteQ

Writes to a  DOS file | 

Syntax: count =  DOSWrite (filehandle, buffer, length) 

DO AO Al DO 

(CCR) 

Writes characters from "buffer" to the given DOS 

filehandle. "Length" is the maximum number of characters to be written, "count" returns the number of characters actually written, or -1 if an error was encountered.

|ExistF() 

Tests whether a  file exists I 

Syntax: 

success =  ExistF (filename)
DO AO 

(CCR) 

IFindDeviceQ 

Verifies whether a  file exists by trying to receive a 

Read-Lock for the file. The result determines whether 

the operation was successful and the lock is released.

Tests whether a  DOS device exists | 

Syntax: 

device

= FindDevice (devicename, type) 

DO 

AO DO 

AO 

(CCR) 

IQpenFQ 

Searches in the DOS DeviceList for a  device node of 

equivalent type, whose name equals "devicename".
Available "types" are the constants DLT_DEVICE, 

DLT_DIRECTORY or DLT.VOLUME, that are defined 

in DOS includes. The name is converted to capital letters before the comparison. The argument "device" is a pointer to the device node, or 0  if nothing was found.

Opens a  file buffer] 

Syntax: 

IoBuff =  OpenF (list, filename, mode /logical) 

DO AO Al DO Dl 

AO 

(CCR) 

See also: 

Attempts to open a  DOS file. The parameter "mode" is 

one of the constants RXIO_READ, RXIO_WRITE or
RXIO_APPEND, that are defined in ARexx Includes. If 

it's successful, an IoBuff structure is created and added to the "list". The "list" must be a  pointer to a  regular
EXEC list header. The argument "logical" is a  pointer to 

the logical filename, or 0  if such a  value is not needed.

CloseFQ 

IQueueFQ 

Syntax: 

See also: 

Adds a  line to a  file buffer I 

count =  QueueFdOBuff , buffer, length)
DO AO Al DO 

Adds a  line to a  data stream that belongs to the given 

IoBuff structure. This data stream must be directed by a 

driver that recognizes the ACTION_QUEUE command. The parameter "buffer" is a  pointer to the data to be added and "length" indicates the number of bytes to be added. The "count" indicates how many characters were actually transferred, or shows -1 if an error was encountered.

StackFQ 

Reads characters from a  file buffer | 

IReadFQ 

Syntax: count =  ReadFdoBuff , buffer, length) 

DO AO Al DO 

(CCR) 

Reads characters from a  file that belongs to the IoBuff 

structure. The value in "buffer" is a  pointer to the target for the data to be read and "length" indicates the number of characters to be read. The "count" reports how many characters were actually transferred.

IReadStrQ 

Reads a  string from a  file buffer] 

Syntax: 

(count, pointer) =  ReadStr (IoBuff .buffer, length) 

DO Al AO Al DO 

Reads characters from a  file that belongs to the IoBuff 

structure until a  line-feed (ASCII 10) occurs. The line- feed characters are discarded. "Buffer" is a  pointer to the target of the data read and "length" is the maximum number of data to be read. The "count" relays how many characters are actually taken, or -1 if an error was encountered.

ISeekFQ 

Syntax: 

IStackFQ 

IWriteFQ 

Moves the access pointer to a  specific location | 

position =  SeekF(IoBuff , offset, anchor)
DO AO DO DO 

Moves the access pointer to a  specific location, 

indicated by "offset", a  relative byte position, given in reference to the "anchor" point. It can be set using
"anchor" to the beginning (-1), the current position (0) 

or to the end of the file (1). The "position" returned is the new position in reference to the beginning of the file.

Adds a  line to the file buffer | 

Syntax: count =  StackF( IoBuff, buffer, length) 

DO AO Al DO 

Adds a  line to the data stream belonging to the given 

IoBuff structure. This data stream must be controlled by 

a driver that can process an ACTION_STACK command. The "buffer" points to the data location, and
"length" is the number of bytes to be added. "Count
reports how many characters were actually transferred or appears as -1 if an error was encountered.

Writes characters into a  file buffer | 

Syntax: count =  WriteFdoBuff , buffer, length) 

DO AO Al DO 

(CCR) 

Writes characters to the file that belongs to the IoBuff 

structure. "Buffer" is a  pointer to the source for the data to be written and "length" is the number of data. The
"count" indicates how many characters were actually 

transferred or reads as -1 in the case of an error.

### 10.4.2 String Manipulation

ARexx treats all data as strings. These functions fulfill the more common 

string operations.

ICmpStringQ

Compares string structures! 

Syntax: 

test =  CmpString(ssl,ss2)
DO AO Al 

(CCR) 

Compares two ARexx string structures whose pointers 

form the arguments. The structures also contain the length and hash value of the strings if there is no agreement in these, the comparison ends. The function returns -1 (TRUE) if they agree or otherwise a  0
(FALSE). 

lengthargstringO

Calculates the length of an 

ARexx arg string 

Syntax: 

length =  LengthArgstring(argptr)

DO AO 

Determines the length of the argument string at the 

given address.

IStcTokenQ

Pulls out one token | 

Syntax: 

(quote, length, scan, token) =  StcToken( string) 

DO Dl AO Al AO 

Searches a  string for the next token, delimited by an 

empty space, and returns a  pointer to the first character of this token. The value "quote" contains the quotation mark character (" or ') or 0 spaces found within quotation marks are not located with this function.
"Length" is the length of the token found, including 

quotation marks, if applicable. "Scan" is a  pointer to the position after the token that was found, which prepares the following call.

IStrcmpNQ 

Syntax: 

IStrcpyAQ 

IStrcpyNQ 

Compares strings | 

test =  StrcmpN(stringl,string2, length)
DO AO Al DO 

(CCR) 

The strings at addresses "  string 1" and "string2" are compared character by character, until "length" is reached or a  deviation is recognized. "Test" is -1 if the first string was shorter, 1  if it was larger, or 0  if the two strings were exactly equal.

Copies a  string and converts to ASClT] 

Syntax: hash =     StrcpyA (destination, source, length) 

DO AO Al DO 

Copies the string at the location "source" to 

"destination". In the process, the data's MSB is deleted 

and projected onto the lower 128 characters in the
ASCII table. The string can contain "00"x, which is why 

"length" is necessary (USHORT). The result is the hash 

byte of the copied string.

Copies a  string | 

Syntax: hash =  StrcpyN (destination, source, length) 

DO AO Al DO 

Copies the string found at "source" to "destination". 

The string can contain zeros "00"x, so "length" is necessary (USHORT). The result is the hash byte of the copied string.

| StrcpyUQ Copies a  string and converts to capital letters | 

Syntax: hash =  StrcpyU (destination, source, length) 

DO AO Al DO 

Copies the string found at "source" to "destination". 

The string can contain zeros "00"x, so "length" is necessary (USHORT). The result is the hash byte of the copied string.

IStrflipNQ 

Reverses a  string | 

Syntax: StrflipN(string, length) 

AO DO 

Transposes the order of characters in a  string at the 

given storage location.

IStrlenQ 

Determines the length of a  string | 

Syntax: length =  Strlen( string) 

DO AO 

(CCR) 

Determines the number the characters in the string 

(closed with "00"x )  at the given storage location. 

### 10.4.3 Conversion Functions in ARexx

|CVa2i() 

Converts ASCII to INT | 

Syntax: 

(digits, value) 

Dl DO 

CVa2i (buffer) 

AO 

Converts from ASCII symbols at the given storage 

location to an equivalent 4-byte integer value (LONG). The function reads ASCII characters until a  character appears that is not a  number or until an overflow occurs. The function returns the integer value and the number of ASCII characters read.

|CVc2xQ 

|CVi2a() 

Syntax: 

Converts CHAR to HEX or BINI 

Syntax: error =  CVc2x(outbuff, string, length, mode) 

DO AO Al Dl DO 

Changes "length" number of bytes from the storage 

location "string" to a  string of equivalent hexadecimal or binary characters. The "mode" is either -1 for hex conversion or 0  for binary conversion.

Converts INT to ASCII | 

( length, pointer ) 

DO AO 

CVi2a (buff er, value, digits ) 

AO DO Dl 

|CVi2arg() 

Changes the prefixed integer value in DO to the 

corresponding decimal number. The "buffer" is the target for the resulting string and "digits" is the maximum number of characters to be written. The function returns "length", the actual number of characters copied, and "pointer" the new "buffer pointer.

Converts INT to ASCII arg stfiiigl 

Syntax: 

argstring =  CVi2arg (value)
DO DO 

AO 

(CCR) 

Changes the "LONG" value in DO to a  string and 

creates a  Rexx arg structure. The return value is a pointer to the arg string structure or 0  if an error occurred. The structure created with this manipulation can be released with DeleteArgstring().

|CVi2az() 

Syntax: 

lCVs2i()

|CVx2c() 

Converts INT with leading zeros to ASCII| 

( length , pointer ) 

DO AO 

CVi2az (buffer, value, digits) 

AO DO Dl 

Changes the prefixed integer value in DO to the 

corresponding decimal number. The "buffer" is the target for the resulting string and "digits" is the maximum number of characters to be written. If necessary, zeros are added to the left in order to reach the number of characters to be written. The function returns "length", the actual number of characters copied, and "pointer" the new "buffer" pointer.

Converts string structure to INT| 

Syntax: (error, value) =  CVs2i(ss) 

DO Dl AO 

"ss" is a  pointer to a  string structure. The function 

returns the value of the string as "LONG" in Dl. "Error is 47 if an error occurs this is the code for "arithmetic conversion error".

Converts HEX or BIN to CHAR| 

Syntax: 

error =  CVx2c (outbuff, string, length,mode)
DO AO Al DO Dl 

Changes "string", which must be a  valid hexadecimal or 

binary number to the corresponding character. If
"mode" is -1, hex is to be expected or, if it's 0, binary 

numbers. There can be spaces, but only at the byte limits. "Length" indicates the number of bytes to be written to "outbuff. "Error" is 47 if an error occurs this is the error code for "arithmetic conversion error".

ErrorMsgQ 

Calculates the error message from 

the error number

Syntax: (bool,ss) =  ErrorMsg ( code ) 

DO AO DO 

Returns an English error message for the given error 

code as a  pointer to a  string structure. "Bool" is -1 if
"code" is not a  valid ARexx error code otherwise it's a 

0. Undefined error codes return the ominous 

"undiagnosed internal error". 

[ToUpperO Converts ASCII to capital letters! 

Syntax: upper =  ToUpper ( char ) 

DO DO 

Converts ASCII symbols to capital letters, working only with DO. 

### 10.4.4 ARexx Resource Handling

[AddClipNodeQ Sets up a  clip node I 

Syntax: node =  AddClipNode( list .name, length, value) 

DO A0 Al DO Dl 

AO 

(CCR) 

Creates a  clip node and binds it to the list specified with 

the header "list". "Name" is a  pointer to a  name string that ends with zero "value" is a  pointer to the storage area. The result is a  pointer to the newly created node, or zero if something went wrong. The RemClipNodeO function deletes a  node created with this function. Clip nodes can be held in a  resource list, mixed with other nodes that are all dissolved with
RemRsrcList(). 

[AddRsrcNodeQ Adds a  resource node| 

Syntax: node =  AddRsrcNode (list, name, length) 

AO AO Al DO 

AO 

(CCR) 

Creates an ARexxRsrc structure and binds it to the list 

indicated by the header "list". "Name" is a  pointer to a

string closed with a  zero, which is set up as a  copy of the NodeName slot in the structure. The "length" is the size of the entire node entered into the structure so that it can be removed later with RemRsrcNode(). The result is a  pointer to the newly created node, or zero if an error occurred.

IClearMemQ Deletes a  storage area| 

Syntax: ciearMem (address , length) 

AO DO 

Deletes a  storage area from "address" and "length" is 

number of bytes. The value for "address" must be even and "length" must be a  multiple of four. AO is preserved.

IClearRexxMsgQ Deletes arg strings from a  message! 

Syntax: clearRexxMsg (msgptr , count ) 

AO DO 

Releases one or several arg strings from a  Rexx message 

and deletes their entries. "Count" is the number of entries to be released and can be set to values smaller than 16 in order to save some entries for your own use.

IClosePublicPortQ Releases a  port resource node| 

Syntax: closePublicPort (node) 

AO 

Closes a  message port and releases its resource node 

that must have been created with OpenPublicPort().

I Create ArgStringQ Creates an arg string structure | 

Syntax: argstring =  CreateArgString (string, length) 

DO AO DO 

AO 

(CCR) 

Generates an ARexx arg structure and copies the given 

string into it. The "argstring" is a  pointer to the string buffer of the structure and can be treated like a  normal string pointer, since it also contains information about string length, structure length, and the hash value with negative offsets in front of the string.

| CreateRexxMessageQ 

Creates an ARexx message structure | 

Syntax: 

msgptr =  CreateRexxMessage (replyport, extension, host)
DO AO Al DO 

AO 

(CCR) 

Generates an ARexx message structure that is a  normal 

EXEC message structure with additional entries for 

function arguments and return values. The "replyport" is a pointer to a  public or private message port and must be specified so the message can be answered. The
"extension" and "host" are pointers to strings, values for 

file recognition and the address of the external environment.

Additional entries in the structure can be inserted later. 

The interpreter only alters the entries for resultl and result2.

CurrentEnvQ 

Calculates a  pointer to the current 

active environment entl ent|

Syntax: envptr =  CurrentEnv(rxtptr) 

DO AO 

Returns a  pointer to the current storage environment 

that belongs to the given ARexx program. The value
"rxptr" is a  pointer to the Rexx task structure of the 

corresponding program and can, for example, be calculated from a  message that was sent by this program.

I Delete ArgstringQ Releases an arg string structure | 

Syntax: DeleteArgstring (argstring) 

AO 

Deletes an ARexx arg structure. The structure contains 

its own length with a  negative offset arg string pointer.

IDeleteRexxMsgQ Deletes an ARexx message structure | 

Syntax: DeleteRexxMsg (packet ) 

AO 

Releases an ARexx message structure. The value 

contained in the structure is used to determine its size. All arg strings in it must already have been released before the call to this function.

IFillRexxMsgQ Fills in arg strings in a  Rexx message | 

Syntax: bool =  FillRexxMsg(msgptr,count,mask) 

DO AO DO Dl 

(CCR) 

Converts up to 16 arguments and fills them into the 

Rexx message "msgptr". The structure must already be 

initialized and the argument slots must either be pointers to strings closed with zeros or integer values. The
"count" indicates the number of argument slots to be 

converted (usually all of them, except special purpose slots) the bits, 0-15, in "mask" determine if a  pointer (0) or an integer (1) is in the slot. The result is -1 if all arguments were successfully converted. If an error occurred, all previously installed arg strings are released and 0  is returned. iFindRsrcNodeQ Finds a  resource nodel

Syntax: node =  FindRsrcNode (list, name, type) 

DO AO Al DO 

AO 

(CCR) 

IKreePortQ' 

Searches in the given "list" for the first node with the 

desired "name". The value of "list" must be a  pointer to an EXEC list header and "name" must be a  string that ends with a  zero. If "type" is 0, not all nodes are examined, only those of the given type. The result is a pointer to the node, or 0  if the name was not found.

Closes a  message port 

Syntax: FreePort (port ) 

A0 

|FreeSpaceQ 

Releases all signal bits that belong to a  port and closes 

it. A  port must be closed by the same task that opened it, since the arrangement of signal bits is task specific and only available in the task control block. The storage area that belongs to the port is not released.

Releases internal storage area] 

Syntax: 

FreeSpace ( envptr , block , length) 

A0 Al DO 

KietSpaceQ

Syntax: 

Returns storage areas reserved with GetSpace() to the 

interpreter. The "envptr" points to the current disk storage environment and can be queried with
CurrentEnv(). 

Reserves internal storage area] 

block =  GetSpace (envptr, length)
DO A0 DO 

A0 

(CCR) 

Reserves a  storage area of the interpreter. This storage 

area is managed by the interpreter and returned to the operating system at the end of the program. "Envptr points to the current disk storage environment for the program.

Unit List 0 

Syntax: 

See also: 

This function is also used by the interpreter to obtain small storage areas for string contents it's always useful for small storage areas that are only needed until the end of the program. The programmer does not have to worry about releasing these storage areas until they get too large.

Builds a  list header structure] 

Syntax: initList (list) 

AO 

Initializes an EXEC list header structure. 

|InitPort() Initializes a  message port| 

(signal, port) =  InitPort (port, name) 

DO Al AO Al 

Initializes a  message port structure that was previously 

created. The task ID of the calling program is used in the
MP_SIGTASK slot and a  signal bit is used. "Signal" is 

the used bit, or -1 if none were free. The "port" is a pointer to the message port structure and "name" is a pointer to a  string that is to be used in the MP_NAME slot. The port address is after the call to Al, which is practical if you want to execute the EXEC function
AddPort() in order to make the port public. 

FreePortO 

|IsRexxMsg() 

Tests a  message | 

Syntax: bool =  IsRexxMsg(msgptr) 

DO AO 

Determines if the message that "msgptr" is pointing to is 

actually a  Rexx message. This is determined by its name:
Rexxmessages have a  pointer to a  hard-coded string 

containing "REXX" in the LN_NAME slot. The returned value is -1 if it's a  Rexx message, otherwise 0.

UsSymbolQ

Is the string a  valid symbol? | 

Syntax: 

(code, length) 

DO Dl 

IsSymbol (string) 

AO 

Investigates the given string. If it's a  valid ARexx 

symbol, the corresponding code is returned in DO, or 0  is returned if the string began with an invalid character. The value "length" returns the length of the symbols found.

| Length A  rgstringQ

Calculates the length of an arg string | 

Syntax: 

length
DO 

LengthArgstring (argptr) 

AO 

IListNamesQ 

This is the recommended method to determine the length of an arg string. "Argptr" points to the arg string structure "length" is the length of the strings in it.

Lists node names in an arg string] 

Syntax: argstring =  ListNames (list, separator) 

DO AO DO 

AO 

(CCR) 

Goes through the given list and copies all nodes in it to 

an arg string structure. The "list" must point to an EXEC list header. The "separator" is an ASCII character inserted between the individual names. While the list is investigated, task switching is shut off with Forbid(). This ensures control of the structures, even for global and system lists. Arg string structures can be released with DeleteArgstringO.

LockRexxBaseQ 

Protects a  global resource from 

data write calls

Syntax: 

LockRexxBase (resource) 

DO 

Protects the given resource from any data write access. 

"Resource" is a  constant that shows what lock is 

requested:

RRT ANY 

An 

RRT_LIB 

Function libraries 

RRT.PORT 

Public ports 

RRT_FILE 

File 10 Buffer (IOBuff) 

RRT HOST 

External function environment 

RRT_CLIP 

The Clip list

Writing access to global resources are normally handled 

via the Rexx master procedure which runs with higher priority in order to ensure complete control. This is another reason not to run ARexx programs with higher priority than the Rexx master procedure.

See also: UnlockRexxBase() 

IQpenPublicPortQ 

Creates a  port resource node] 

Syntax: node =  OpenPublicPort (list, name) 

DO AO Al 

Al 

(CCR) 

Opens a  public message port with the name given in 

"name" and binds it to the list shown by the header in 

"list". The message port is also added to the system list 

of ports. See also: ClosePublicPortQ.

IRemClipNodeQ

Releases a  clip node) 

Syntax: RemClipNode ( node ) 

AO 

Cuts the given clip node from the clip list and releases 

the storage area assigned to it. This function is automatically carried out by RemRsrcNode() and
RemRsrcListO for a  clip node. 

See also: AddClipNodeQ, RemRsrcNodeQ, RemRsrcListO 

I RemRsrcListQ Releases a  resource listl 

Syntax: RemRsrcList ( list ) 

AO 

Releases all nodes in the given list, all of which must be 

RexxRsrc structures. For each node, the "auto-delete
function is called.

IRemRsrcNodeQ Removes a  resource node| 

Syntax: RemRsr cNode ( node ) 

AO 

Removes the given node from its list. If an "auto-delete
function is specified, it's executed first. The name string in it is also released.

|UnlockRexxbase() Releases a  global resource! 

Syntax: UnlockRexxBase (resource) 

DO 

Releases the given resource. Each call to 

LockRexxBase() should be followed by this 

counterpart. The definition of the resource constants is explained in the section on LockRexxBase().

## 10.5 The RexxBase Lists

All structures managed by the Rexx master procedure are noted in the basic structure of the ARexx system library and can be found by other programs. The task list in RexxBase contains a  pointer to the global structures for all currently running ARexx programs. Individual task structures are linked by the message ports in them. The Rexx task structure is the global data structure for an ARexx program and its initial storage environment. All other storage areas are added to the lists contained here. By doing this, the internal data of each
ARexx program can be reached using the RexxBase pointer. 

There are two functions of the ARexx system library, LockRexxBase() and UnlockRexxBase(). The base structure should always be protected from access with a  lock before looking at a  list and reading data.

Usually, it's not necessary to access these structures directly, since there 

are corresponding functions in the ARexx system library for all necessary operations which should be used for that purpose. Direct control is not recommended.

## 10.6 ARexx Error Messages

If the ARexx interpreter discovers a  program error, an error code is returned indicating the nature of the problem. Normally an error code displays the program line in which it was encountered, and a  short descriptive error message. If the SYNTAX interrupt was not enabled, the program ends. The SYNTAX interrupt can catch most errors so that the program itself can take counter-measures. Some errors still develop in areas outside of the ARexx jurisdiction and cannot be caught. There is a  value attached to each error code showing the error level that's returned as the primary result. The error code itself appears as the secondary result.

Error code: 1  Error level: 5  Message: Program not 

found The given program could not be found or is not an ARexx program.
ARexx programs must always start with "/*". This cannot be trapped 

with the SYNTAX interrupt.

Error code: 2            Error level: 10 Message: Execution 

halted The program ended because a  Ictnl +(£) break or an external HALT request was given. This error can be caught with the HALT interrupt.

Error code: 3  Error level: 20 Message: Insufficient 

memory The interpreter was unable to receive enough memory space for an operation. Since all operations of the interpreter usually need some storage access, this error cannot usually be caught with the SYNTAX interrupt.

## 70.6 ARexx Error Messages

Error code: 4  Error level: 10 Message: Invalid 

character

Invalid characters were located in the source code. Control codes and 

other special characters can only be used in hexadecimal or binary strings within a  program. This error cannot be caught with the SYNTAX interrupt.

Error code: 5  Error level: 10 Message: Unmatched 

quote A string delimiter (' or ") is omitted. Each string must be enclosed with the same character with which it began. This error cannot be caught with the
SYNTAX interrupt. 

Error code: 6            Error level: 10 Message: Unterminated 

comment The characters ("*/") that indicate the end of a  comment, were not found.
Please note that comments can be nested, so every "/*" must be followed 

by a  "*/". This error cannot be caught with the SYNTAX interrupt.

Error code: 7            Error level: 10 Message: Clause too 

long A clause was too long to be written to the interpreter's internal interim storage area. The maximum length (without multiple spaces and commentaries) is 800 characters. The questionable clause should be divided into two or more parts. This error cannot be caught with the
SYNTAX interrupt. 

| Error code: 8  Error level: 10 Message: Invalid token | 

An invalid token was encountered or a  clause could not be classified. This error cannot be caught with the SYNTAX interrupt.

Error code: 9            Error level: 10 Message: Symbol or 

string too long An attempt was made to generate a  string with more than 65,535 characters.

Error code: 10 Error level: 10 Message: Invalid message 

packet In a  message received by the Rexx master procedure, an invalid action code was encountered. It was returned with no changes. This error is externally created and cannot be caught with the SYNTAX interrupt.

Error code: 11 Error level: 10 Message: Command 

string error A command string was incorrect. This error is externally created and cannot be caught with the SYNTAX interrupt.

Error code: 12 Error level: 10 Message: Error return 

from function An external function returned an error code not equal to zero. It's possible that the parameters were not correctly passed.

Error code: 13 Error level: 10 Message: Host 

environment not found The message port indicated by an address was not found. If the name is correctly written (including capitalization), is the desired function environment active?

Error code: 14 Error level: 10 Message: Requested 

library not found The program was not able to open a  library entered in the library list. If
ADDLIBO was called with the correct name, was the correct version 

number called? Is the library in the LIBS: directory?

Error code: 15 Error level: 10 ~~ Message: Function not 

found A function was called that was not in any of the libraries added with
ADDLIB() and also not found as an external program. Is the spelling 

correct? Was the library bound with ADDLIB() to the list?

Error code: 16 Error level: 10 Message: Function did 

not return value A function was completed without delivering a  result string and without encountering an error. Was the function correctly programmed? If it was accessed with CALL this can be avoided.

Error code: 17 Error level: 10 Message: Wrong number 

of arguments A function expecting more or fewer arguments was called. This error also occurs if a  built-in or an external function is called with more arguments than the message can contain (max. 15).

Error code: 18 Error level: 10 Message: Invalid 

argument to function An argument that does not agree with the function was passed, or a necessary argument was omitted.

Error code: 19 Error level: 10 Message: Invalid 

procedure A procedure call occurred at the wrong location. Either it was not in an internal function, or it occurred twice in a  function.

Error code: 20 Error level: 10 Message: Unexpected 

THEN or WHEN 

A THEN or WHEN command occurred at the wrong location. The
WHEN command is only valid within the area of a  SELECT command 

and THEN must directly follow an IF or WHEN.

Error code: 21 Error level: 10 Message: Unexpected 

ELSE or OTHERWISE 

An ELSE or OTHERWISE command occurred at the wrong location. An
OTHERWISE command is only valid within the area of a  SELECT 

command. ELSE is only available after a  THEN branch of an IF command.

Error code: 22 Error level: 10 Message: Unexpected 

BREAK, LEAVE, or ITERATE 

The BREAK command is only valid in a  DO group or in commands that are executed with INTERPRET. Commands to LEAVE or ITERATE are only valid in a  DO loop.

Error code: 23 Error level: 10 Message: Invalid 

statement in SELECT In the area of a  SELECT command, an illegal construction was encountered. Only WHEN-THEN and OTHERWISE constructions are valid.

Error code: 24 Error level: 10 Message: Missing or 

multiple THEN A THEN clause was expected, but not found, or a  THEN appeared without IF or WHEN.

Error code: 25 Error level: 10 Message: Missing 

OTHERWISE 

No WHEN clause in the area of a  SELECT command was successful and 

no OTHERWISE was found.

Error code: 26 Error level: 10 Message: Missing or 

unexpected END The source text ended without closing a  DO or SELECT group with
END, or an END clause was found outside such a  group. 

Error code: 27 Error level: 10 Message: Symbol 

mismatch The symbol specified with an END, ITERATE, or LEAVE command did not agree with the index variable of the appropriate DO group.

Error code: 28 Error level: 10 Message: Invalid DO 

syntax The interpreter found an error in a  DO command: If TO or BY are specified, the index variable must be initialized and the expression after
FOR must evaluate to a  positive integer. 

Error code: 29 Error level: 10 Message: Incomplete IF 

or SELECT An IF or SELECT group ended before all of the necessary constructions were encountered. Perhaps a  THEN, ELSE, or OTHERWISE construction is omitted.

Error code: 30 Error level: 10 Message: Label not 

found A jump marker specified in a  SIGNAL command or searched for with a
SIGNAL interrupt, could not be found in the source code. Interactive 

commands or marks established in an interpreter command are usually not found.

Error code: 31 Error level: 10 Message: Symbol 

expected At a  location where only a  symbol is appropriate, an invalid token was found. The commands DROP, END, LEAVE, ITERATE and UPPER can only be followed by symbols and create this message if anything but a symbol is found or a  necessary symbol is omitted.

Error code: 32 Error level: 10 Message: Symbol or 

string expected At a  location where only a  symbol or string is permitted, an invalid token was found.

Error code: 33 Error level: 10 Message: Invalid 

keyword A symbol in a  command was recognized as a  key word but is not valid at this location.

Error code: 34 Error level: 10 

Message: Required 

keyword missing A certain keyword was expected by a  command and was not found. This message occurs if none of the keywords for the individual interrupts
(such as SYNTAX) follows a  SIGNAL ON command. 

Error code: 35 Error level: 10 

Message: Extraneous 

characters A seemingly correct command was executed but further characters were found following it.

Error code: 36 

Error level: 10 

Message: Keyword 

conflict

Two mutually exclusive keywords occurred in the same command or a 

key word was encountered twice.

Error code: 37 

Error level: 10 

Message: Invalid 

template The template specified in an ARG, PARSE, or PULL command was invalid.

Error code: 38 Error level: 10 Message: Invalid TRACE 

request The keyword for a  TRACE command or an argument for the TRACE() function was not valid.

Error code: 39 

Error level: 10 

Message: Uninitialized 

variable An attempt was made to read an uninitialized variable. This message appears only when the NO VALUE interrupt is enabled.

Error code: 40 

Error level: 10 

Message: Invalid 

variable name An attempt was made to assign a  value to a  constant.

Error code: 41 Error level: 10 Message: Invalid 

expression

During an evaluation of an expression, an error occurred. Possibly an 

operator was not used correctly or invalid characters appeared. This error only appears when an expression is analyzed expressions that are jumped over are not checked.

Error code: 42 Error level: 10 Message: Unbalanced 

parentheses An expression was encountered that did not have the same number of open and close parentheses marks.

Error code: 43 Error level: 10 Message: Nesting limit 

exceeded The number of nested sub-expressions was higher than 32. The expression should be divided into several partial expressions.

Error code: 44 Error level: 10 Message: Invalid 

expression result The result of an expression was not valid. This error is created if an expression in a  DO command does not lead to a  numeric result.

Error code: 45 Error level: 10 Message: Expression 

required An expression is omitted in a  necessary location. An example is that after
SIGNAL an expression must follow, unless ON or OFF was specified. 

Error code: 46 Error level: 10 Message: Boolean value 

not 0  or 1 The result of an expression should be a  Boolean result, but a  value that is not 0  or 1  occurred.

Error code: 47 Error level: 10 Message: Arithmetic 

conversion error

During an operation that requires numeric operands, a  non-numeric 

operand was encountered. A  hex or binary string with errors also leads to this error message.

Error code: 48 Error level: 10 Message: Invalid 

operand An operation was attempted with an invalid operand. This error occurs when dividing by 0  or when trying to display fractional Exponents (that are not supported by ARexx).

A3000 Intern 

1 1 . The A3000 Hardware 

The Amiga 3000 is the first completely new model Commodore has introduced since the Amiga 1000. Unlike the A500 and A2000, which hardly differed from their predecessor technologically, the A3000 is a truly new development, capable of holding its own against the Intel
80386-based IBM-compatible personal computers in some areas it even 

surpasses them. The most important innovation is the departure from the 68000 as central processor. Powerful as this chip was in comparison to its counterpart,
Intel's 80286, a  databus width of 32 bits has since become the standard. 

In fact, the first 64-bit microprocessor has already appeared —  the 80860 introduced in 1989 by Intel. By its decision to base the new Amiga on the 68030 processor,
Commodore has achieved the best possible compromise between price, 

performance and, perhaps most importantly, compatibility. Commodore's software developers don't have to worry about compatibility problems between the 68000 and the 68030. It is safe to assume that the majority of existing software will run on the new machine. Any problems are more likely to be related to the new
Kickstart 2.0 operating system than to the new hardware, and 

fortunately the A3000 will also run Kickstart 1.3.

"Dirty" programs unable to cope with the 6- to 8-fold increase in 

computing speed can always turn to the GURU generator. This same problem presented itself earlier, however, with the widespread use of
68020 and 68030 cards in the A2000. So programmers had enough time, 

before the A3000 was introduced, to correct bad programming habits learned on the C64 and adapt their software to the new generation of computers.

Linked with the new processor are the FPU 68881 and 68882 (in the 16 

and 25 MHz models, respectively). These floating point processors speed mathematical routines and give the A3000 a  "computing" power (in the truest sense of the word) that's suitable for a  scientific workstation.

Another important improvement over the A2000 is the built-in hard disk 

and its SCSI bus, which also enables the addition of CD-ROM or tape drives. The 32-bit SCSI chip, developed by Commodore specifically for this purpose, offers adequate speed required for the operation of modern storage media. The hard disk itself comes from Quantum. This company has succeeded in producing a  drive that is not only fast and reliable, but also quiet. Any user who has dealt with the grinding, screeching or whistling of less adeptly engineered examples of mass storage technology will certainly appreciate this. (Unfortunately, the A3000 still has the old vacuum cleaner noise, although it does run at a  whisper compared to the A2000.)

Technically speaking, little has changed in the area of graphics. However, 

there is one exception so crucial that it could be considered the A3000's single most important innovation. This is the flicker fixer, which alleviates the flickering that may occur when a  screen is displayed in interlace mode by temporarily storing the individual half-pictures (frames). Many
A2000 owners have purchased such a  flicker fixer because it 

significantly improves the display quality.

Moreover, integration of the Enhanced Chip Set (ECS), which consists 

of a  substantially improved Agnus chip and a  new Denise, produces, even without the flicker fixer, a  640 *  480 screen with a  refresh rate of
60 Hz, although this is with a  maximum of only four colors. 

All the new features mentioned above are explained in detail in the following sections, both from a  hardware standpoint and from the programmer's point of view. The familiar A2000 features that have not changed in the A3000 are also discussed in detail.
