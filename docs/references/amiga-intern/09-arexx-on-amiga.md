# ARexx on the Amiga

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

## 9.1 Commands

ARexx runs on any Amiga running Kickstart Vl.l or higher. It uses the 

IEEE math library on the Amiga and for double precision the 

"mathieeedoubbas.library", which must be on the logical device "LIBS:". 

The interpreter itself is in a  library named "rexxsysliblibrary", which must also be available there. ARexx programs can be named any way you want, but there are some rules meant to ensure a  clear overview of library contents. It is customary for ARexx programs that are started directly from the CLI with "rx" to end with the characters ".rexx". Macro programs that are to be started from certain application programs should end with a  set of characters specific to the application. For example,
ARexx programs that control CygnusEd normally end with ".ced". 

ARexx uses its own logical device: the ARexx directory. ARexx 

searches for programs first in the current directory, then in the REXX: directory, if that was defined with the CLI command "ASSIGN". After V2.X, ARexx is part of the Amiga operating system and the Rexx master procedure is started in the normal startup sequence it runs in the background.

Several CLI commands belong to ARexx and must be located in the c: 

directory or in the Arexxc: directory that is in the command path. There are various available control functions, all of which depend on sending the corresponding message to the Rexx master procedure. Equivalent functions could be provided by an application program that works with
ARexx. 

I HI (Haltlnterpretation)l 

Syntax: HI 

Sets the global "Halt" flag, so that all active ARexx 

programs receive an external "Halt" request. All programs are immediately interrupted, unless caught with SIGNAL ON HALT. Then a  subroutine branch would also eventually interrupt (possibly after some fRX~

IRXSET 

clean-up work). When all running programs have received the "Halt" command, the flag is reset.

(RexxeXecute)l 

Syntax: RX name [arguments] 

RX string [arguments] 

Starts an ARexx program. If "name" includes a  path 

name, ARexx only looks for the program there otherwise it searches the current directory and then the
REXX: directory. If the Rexx master procedure is not 

running, it's started first. Arguments are passed to the program and can be queried with ARG. The second form previously listed allows you to enter a  complete argument as a  string. Observe correct usage of string delimiters. If you want to define a  string with this program, you must use the appropriate other string delimiter, or enter the same delimiter twice.

RX can also be started with a  tool or project icon from 

the workbench. A  project icon for an ARexx program can be defined as the default tool. If you are using RX in a  tool icon you can enter an argument line under tool types with the flag "CMD=". In both cases
"CONSOLE=" can specify a  window. 

] 

Syntax: RXSET name [value] 

Adds a  name and a  corresponding string "value" to the 

clip list. If "name" already exists, the old contents is discarded and "value" becomes the new contents. If there is no second argument the corresponding entry on the clip list is deleted.

rexc

Syntax: 

(RexxClose)l 

RXC 

prcc

Ends the Rexx master procedure. The "REXX" port is 

immediately deleted from the list of active public message ports and the task is complete as soon as the last active program ends.

(TracingConsoleClose) | 

Syntax: 

TCC 

rrco rrE

Closes the global tracing window as soon as no active 

program is using it.

(TracingConsoleOpen) | 

Syntax: TCO 

Opens the global tracing window. All trace output is 

automatically routed to this window. It can be closed with TCC. Only one program should be in a  trace mode, since the output is otherwise very confusing.

(TraceEnd)"| 

Syntax: 

TE 

Its

Cancels the global "Trace" flag all active ARexx 

programs are switched to the trace mode "OFF".

(TraceStarl)! 

Syntax: 

TS 

Sets the global external "Trace" flag, putting all active 

ARexx programs into interactive trace mode. The 

programs then produce trace output and wait after the next clause. The command is useful if an ARexx program is out of control and needs to be brought back into line. The "Trace" flag remains set until it is deleted with the "TE" command, so programs that are called later also go into trace mode.

I WAITFORPORT 

Syntax: WAITFORPORT [-immediate] Portname 

This command waits up to 10 seconds for a  message port with the given name to appear. (Caution: Upper and lowercase spelling is observed here.)
WAITFORPORT returns a  0 if the port is available, 

otherwise a  5 (WARN). This is the best way to check for a  port to become available for use by an application you just started or by the Rexx master. The option
"-immediate" overrides the waiting interval and simply 

searches for the port once.

## 9.2 Exchanging Data with the Clip List

The "clip list" contains character strings and a  corresponding name for each. This is useful for data exchange between different ARexx programs with the functions SETCLIP() and GETCLIP(). To avoid name conflicts, clip names should be specific to a  certain program, perhaps by using a  specific name that is related to the program name. There is no limit to the number of clips that can be saved, except for system storage capacity. Beyond data exchange, clips can also be used in other ways. Since ARexx does not support Includes, as other high level languages do, the clip list can be used to emulate this feature, for more flexibly and can be applied simultaneously to several programs. For example, flags that control several running programs could be filed in the clip list. A  line named "Presets" with the following contents, for example: quiet=l speed=5 prompt="Hi > could with the command:

INTERPRET GETCLIP ( " Presets " ) 

be called by each program and used as a  series of commands, simple assignments in this example. The Rexx master procedure manages the clip list and makes sure that a name only appears once in it. In searching for an entry, upper and lowercase letters are distinguished the name must always be spelled exactly the same way. Entries remain available until a  SETCLIP() without the second argument deletes them. When the Rexx master procedure ends, the clip list is discarded.

## 9.3 The rexxsupport.library

An external function library named "rexxsupportlibrary", contains several functions specifically intended for the Amiga. It has the same format as the EXEC function libraries, but contains additional code that is used by the interpreter to determine whether a  function is in the library and then its offset. This is the QUERY function. If you want to access one of these functions, you must first add the library to the list of libraries. The function ADDLIB("rexxsupport.library",0,-30,34) performs this task the corresponding file must be in the LIBS: directory. The priority can be set to another value, but this does not make sense unless there are several external libraries. -30 is the customary offset for the query function and a  version number (not the revision number, only the whole number portion) must also be specified in order to make sure that the function is in the library. The following documentation refers to
Version 34.9. 

9.3.1 

EXEC Functions 

ALLOCMEM() 

CLOSEPORT0 

DELAYO 

FORBID() 

FORWARD() 

FREEMEMO 

GETARGO 

GETPKTO 

NEXTO 

NULLO 

OFFSETO 

OPENPORT() 

EXEC Functions 

PERMITO 

REPLY() 

SHOWLIST() 

TYPEPKTO 

WAITPKTO 

DOS Functions 

BADDR() 

DELETE() 

MAKEDIR() 

RENAME() 

SHOWDIRO 

IALLOCMEMQ

Syntax: 

ALLOCMEM ( Length [ , Flags ] ) 

Reserves a  memory area of the indicated length from the 

list of free blocks managed by EXEC and returns the beginning address as a  four byte string. "Length" is

## 9.3 The rexxsupport. library

rounded up to the next multiple of 8. In addition, a  4 byte string can specify attributes of the memory area as follows:

ANY 

"00000000"x 

any memory area

PUBLIC 

"00000001 "x 

hard disk, freely accessible

CHIP 

"00000002"x 

ChipRAM 

FAST 

"00000004"x 

FastRAM 

CLEAR 

"00010000"x 

deleted memory

See also: 

If necessary, several flags can be combined by adding the values, for example, "00010003"x for PUBLIC,
CHIP and CLEAR. The default is "PUBLIC". If the call 

fails (e.g., if there is no space) an error message is generated.

FREEMEMQ 

Example: 

say C2X(ALLOCMEM(256, "00000003"))

=> 0001DE48 

ICLOSEPORTQ 

Syntax: CLOSEPORT ( Name ) 

Closes the message port of the given name. The port 

must have been initialized with a  call to OPENPORT() by the same ARexx program before CLOSEPORT has effect. If result messages have arrived and have not been handled yet, they are automatically answered with a return code 10. The result is boolean.

See also: OPENPORTQ 

Example: say CLOSEPORT ("Delaware") 

==> 1 

IDELAYQ 

Syntax: DELAY (Ticks) 

Waits the given number of 50ths of a  second (ticks) and 

then returns. You should always use this function when an ARexx program should wait a  specific length of time.

Until the length of time is passed, the procedure is 

moved to a  status of "waiting" and does not use the processor. Timed loops are generally not seen as useful for this purpose.

Example: 

IFORBIDQ 

say DELAY (200)

==> 1  (4 seconds later) 

Syntax: 

See also: 

Example: 

FORBID () 

Toggles task switching off and returns the current 

nesting level in the previous call to FORBID() -1 (0 after the first FORBID(), 1  after the second, etc). Since FORBID() only refers to the running task, it doesn't matter if a  program ends before task switching is enabled with the PERMIT() function. Before manually calling STORAGEO, EXPORT() and IMPORT() to the
EXEC list or to data areas of other programs from 

ARexx programs, you should always execute 

FORBID(), especially if you access the task several 

times. Following these operations, immediately execute
PERMITO. 

PERMIT() 

Say FORBID () 

=> 0 

IFORWARDQ

Syntax: FORWARD ( Addr e  s s , n ) 

Not documented. 

IFREEMEMQ

Syntax: FREEMEM (Address, Length) 

Releases a  storage area previously reserved with 

ALLOCMEM(). "Address" is normally the 4  byte string 

passed by the equivalent call. "Length" determines the

Caution: 

Example: 

IGETARGQ

IGETPKTQ

Syntax: 

size of the released area. The command FREEMEM() cannot be used to release memory space that was reserved with the internal function GETSPACE() through the Rexx master procedure. The function returns a  boolean result.

False arguments immediately lead to program crash. 

say FREEMEM("000lDE48"x,256) ==> 1

Syntax: GET ARG ( Me s  s age [ , Ent ry ]  ) 

Reads a  command or function name from a  message at a 

4 byte address located with GETPKT(), given as 

"Message". The optional "Entry" can be used with a 

function message to read individual argument strings
(max. 15). 

Example: command =  GETARG ( Packet ) 

function =  GETARG ( Packet , 0 )
Argl =  GETARG (Packet, 1) 

Example: 

GETPKT ( PortName ) 

Checks if the message port with the given PortName 

has received a  report and returns the address of the oldest message or "0000 0000"x, if nothing has arrived. The port must first have been opened by the same program with OPENPORT(). The function immediately returns a  value, even if there is no report. If a  program doesn't have anything to do, it's not good to keep "running to the mailbox", which keeps the processor working overtime. Use WAITPKT() and let the program sleep until EXEC hears the mailbox opening.

Packet =  GETPKT ("Delaware") 

INEXTQ 

Syntax: NEXT (Address [  ,0f f  set] ) 

Returns the 4  byte value, found at the given address, 

after adding "Offset" (a positive integer). Use
NEXT(Address) to move forward though a  chained 

EXEC list, or NEXT(Address,4) to move in the opposite 

direction.

Example: 

INULLQ 

Example: 

IQFFSETQ 

ExecBase =  NEXT (" 00000004 "x) 

WaitingList =  NEXT (ExecBase, 420) 

Syntax: NULL ( ) 

Returns a  4 byte Amiga pointer with the value "0000 

0000"x. 

say C2X (NULL ( ) )

==> 00000000 

Syntax: OFFSET (Address, Amount) 

Calculates, from a  4 byte Address and a  (prefixed) 

whole number Amount, a  new address. A convenient method of calculating the address of a particular entry in a  structure this function avoids doing various type conversions.

Example: WaitListPtr =  OFFSET (ExecBase, 420) 

IQPENPORTQ ~| 

Syntax: OPENPORT ( Name ) 

Creates a  public message port with the given name. The 

result is boolean. The function fails (except in the case of immediate lack of disk space) if a  port of the same

name has already been named or no further signal bit could be reserved. (16 are available, one is for communication with the master procedure.) The port created is bound to the global data structure of the program. When a  program ends, all open ports are automatically closed and outstanding messages are answered with a  return code of 10.

See also: CLOSEPORTQ 

Example: say openport( "Delaware") 

==> 1 

IPERMITQ 

Syntax: PERMIT ( ) 

Toggles task switching back on. The result code is the 

current nesting level of the previous FORBID() call -1, after executing the function. It returns -1, if task switching is actually permitted again.

Example: 

1REPLYQ 

say PERMIT ()

Syntax: 

REPLY ( Mes sage , Returncode ) 

Answers a  message at a  4 byte address with 

"Returncode", an integer error code as Resultl. Result2 

(the result value) is deleted. The result is boolean. 

Example: 

ISHOWLISTQ

say REPLY (Packet ,10)

==> 1 

Syntax: SHOWLIST(Option [ , [Name] [ , [Pad] [ , "Address" ] ] ] ) 

Shows entries in various system lists selected by 

options. Options are:

Assign: 

DOS list of logical devices 

Devices: 

EXEC list of physical devices 

Handlers: 

DOS list of device drivers 

Interrupts: 

EXEC list of interrupts 

Libraries: 

EXEC list of open libraries 

Memory: 

EXEC list of free storage areas 

Ports: 

EXEC list of public message ports 

TaskReady: 

TaskReady list in EXEC 

Resources: 

EXEC list of resources 

Semaphores: 

EXEC list of semaphores 

Waiting: 

TaskWait list in EXEC 

Volumes: 

DOS list of storage media 

If the first argument is given, the names of the nodes of that list are calculated and returned in a  string delimited by an empty space. If the second argument specifies a name, the function returns a  boolean result, showing whether the name is in the list. Upper and lowercase writing are distinguished in this search. The "Pad argument can specify another character, instead of a space, to separate the entries in the result string. The key word "Address", in combination with a  name, causes the address of the specific node to be returned, as a  4 byte pointer. If the name is not found, the pointer reads "0000 0000"x. The addresses of DOS nodes are calculated in machine addresses (APTR's), so you do not have to deal with BCPL pointers here.

Example: say SHOWLISTCP") 

say SHOWLISTCP", "REXX") say C2X (SHOWLISTCP", "REXX", , "A") ) say SHOWLISTCP",,"*")

==> rexx ARexx IDCMP 

==> 1 

==> 0023485A 

==> REXX*AREXX* IDCMP 

ITYPEPKTQ

Zl 

Syntax: 

TYPEPKT (Message) 

Returns the 4  byte address of the pointer of a  message 

sender to the global task structure. "Message" is the address of the message, calculated with GETPKTQ.

Example: 

say C2X(TYPEPKT (Packet) ) ==> 0026542E ?

IWAITPKTQ 

] 

Syntax: 

WAITPKT(Name) 

Waits for a  message to arrive at the given message port 

name. The port itself must first have been created in the same program with the command OPENPORT(). The boolean result shows whether a  report was actually received normally the result is 1, since the function does not return otherwise. The message must then be retrieved with GETPKT() and should be answered with
REPLY(), so that the sender can resume control over 

the storage area.

9.3.2 

Example: 

call WAITPKT "Delaware

DOS Functions 

1BADDRQ 

Syntax: BADDR ( BPTR ) 

Re-calculates the BCPL pointer "BPTR" from a  normal 

4 byte machine address (APTR) by multiplying it with 4. 

Example: say C2X(BADDR("0000 0002"x)) ==> 00000008 

IDELETEQ 

] 

Syntax: DELETE (Filename) 

Deletes a  file or directory. "Filename" is a  complete DOS 

path. The boolean result shows if the entry was found and deleted. Only one file at a  time and only empty directories are deleted wildcard characters (* or &) are not permitted.

Example: 

say DELETE ( " T : Rose . bak " )

==> 1  ? 

IMAKEDIRQ

Syntax: 

MAKEDIR ( DirName ) 

Example: 

IRENAMEQ

Syntax: 

Creates a  directory. "DirName" is a  complete DOS path. 

A boolean result shows whether the processor was able to create the directory. say MAKEDIR ( "RAMtRosegarden" )

==> 1 

RENAME ( Al t erName , NewName ) 

Renames a  file or directory and/or moves it within the 

same medium and returns a  boolean result.

Example: 

say RENAME ("DFO: Rose", "DFO :Tulip" )

==> 1 

ISHOWDIRQ

Syntax: 

Example: 

SHOWDIR( DirName [, [{"All" I "File" | "Dir")] [,Pad] ] ) 

Returns a  string with the entries contained in the 

directory "DirName", delimited by an empty space. The second argument is the keyword, used to show all entries, only files, or only directories. The "Pad" can be used to put a  different character between the entries. say SHOWDIR("DF0:C")

==> rx ts te 

## 9.4 Creating ARexx Function Libraries

You can always enlarge the scope of ARexx with supplementary 

function libraries. There are several good reasons to do this. In the simplest case, you could have a  desire to take advantage of the mathematical or Amiga-specific options in ARexx with new functions you put together in a  library. A  function library created for this purpose could contain all the necessary code, or open other Amiga libraries to perform functions. Or you could write a  library that works closely with a specific application program, enabling certain program operations to avoid reference to commands and work only with functions. This has its advantages, because the application program doesn't have to interpret commands or receive and answer messages. A  library can contain more than entry points for entire and specific operations it can contain code that is used directly by the application program. As indicated, function libraries can act as bridges to other system libraries or application libraries. If an ARexx program controls "Intuition", a corresponding function library could recognize appropriate function names, calculate the needed offset, if necessary, convert individual parameters, and then call the corresponding function in the intuition.library. Also, ARexx can be applied as a  test platform for new functions it's easier to manage than a  C program, which must be re- compiled after each change and offers no tracing functions.

Whatever the task, function libraries all have the same structure. They 

contain a  portion of the normal EXEC system library with the basic functions OPEN, CLOSE and EXPUNGE as well as a  reserved vector. There must also be a  QUERY function that can compare the name delivered by ARexx with the names of the functions it contains and then call the correct one. Normally this is the first function after the system functions and has an offset of -30. Function libraries should be fully re- enterable, since many ARexx programs can run simultaneously and use the same functions. If this is not possible because of other constraints, the query function must contain a  mechanism that prevents the function from being called more than once.

Function calls 

The QUERY function is accessed by the interpreter with the address of a message in AO and a  LIBRARYBASE in A6. The message has the same structure as all Rexx messages, and is not passed by a  message port yet. In ARGO, a  pointer indicates the function name it's searching for in the table. If this name is not found, an error code of 1  ("program not found") must be returned in DO. The library is then closed and the search continues. The message itself should not be changed, since it must be passed from one library to the next until the function is found.

Parameter conversion 

If the called function is found, sometimes the hierarchically higher parameters must be converted to the form the function is expecting.
Depending on the structure of the functions, it could be enough to move 

the pointer but sometimes parameters or pointers must be supplied in specific registers. Arguments are always passed as ARG strings that can be treated as normal strings supplied with O's. Other attributes of strings have a  negative pointer offset that can be useful.

Numeric values are passed as strings of ASCII symbols and must be 

converted into integers or variable decimal format in order to perform arithmetic calculations. The ARexx system library contains several functions that are useful for these purposes. The number of arguments can be determined with the lowest value bytes of the action code. The function name in ARGO is not counted here, but it's counted for arguments that are set to zero and are used as default values. The parameter block of the message (with ARGO to ARG 15) is structured just like the argument array (argcargv) function of a  C program. This makes it easy to incorporate a  C program into a  function library: the query function simply calculates the address of the function you want, the address of the parameter block and the number of arguments that must be placed on the program stack before the function is started.

Returned values 

Each function in a  library must return an error code and a  result string. The error code must be located in DO if it's 0, Al must contain an ARG string pointer. The routine that creates the correct returned values can be part of the query function, so that all functions return via this path.

10, The ARexx Interface 

Using ARexx, there are two methods of communication with 

independent external programs: The command interface With message system commands, sent to the address of an initialized message port corresponding to an application program, from which answering messages are in turn expected. The external function environment

Messages are exchanged with another task a  call to a  function name still 

follows, accessed from a  specified library list and function environments.
Both argument and returned values must conform to ARexx 

conventions. The Rexx master procedure is the common communications carrier for
ARexx and external applications. It opens the public message port 

"REXX" and handles many administrative tasks, and also acts as a  "host". 

As a  host, it starts ARexx programs and manages global resources. The task structures of all running ARexx programs are maintained in a  list, the contents of this list is available to external programs. The interpreter is located in an operating system library and offers many entry points that are useful for the implementation of ARexx interfaces in other programs. It contains functions that are able to create ARexx structures, such as a  RexxMessage or arg string, to manipulate and delete them. These functions should always be used, since future expansions can cause problems. Available functions are documented in more detail later.
