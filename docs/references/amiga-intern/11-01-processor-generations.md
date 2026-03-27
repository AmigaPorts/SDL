# Processor Generations

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

The heart of the A3000, the 68030 microprocessor, is the product of a continuing development process that began with the 68000 in 1979. So far this process has culminated in the 68040 and further advances are sure to come. Motorola has succeeded (or nearly so, at least) in maintaining software compatibility across this entire line of processors. The performance of the new models isn't significantly affected when running old programs. This is definitely a  worthwhile accomplishment.
Motorola's competitor, Intel, hasn't been able to do the same with the 86 

processor series for the PC. The Forefather: MC 68000 When it was introduced, the MC 68000 was a  pioneering product. With astounding foresight, its developers gave it attributes that would make it the forefather of an entire processor family. Specifically, these attributes are: A universal register structure The entire 68000 family has eight data registers and eight address registers, all with a  width of 32 bits. Except for the distinction between address and data registers, there is no connection between a  register and the functions for which it may be used. This differs many other processors, where, for example, an accumulator is designated specifically for computation results, or an index register specifically for table addressing. With such a  design, moving data from one register to another is largely eliminated. The greater register size also makes it unnecessary, in computations with integers, to divide a  value over more than one register. Almost all computations can be executed in a  single instruction. This structure was retained with the 68020, since it is fully adequate for a true 32-bit processor also.

Large linear address space 

Although the address space of the 68000 is only 16 Megabytes, all its address registers are 32 bits wide. There is no addressing limitation, so that accommodating the 68020's address space of four Gigabytes (an amount still generous by today's standards) was a  simple matter of bringing in eight more address lines. A  data field can be quickly accessed by loading any address register with the desired base address and referencing the data by means of a  16-bit displacement value added to the base. This saves time because only 16 bits, not 32, must be loaded from memory. This scheme combines the advantages of a  large linear
(non-segmented) address space and quick access to contiguous data. 

Many types of addressing 

Besides the "normal" types of addressing, such as absolute, indirect or 

immediate, handled by almost all processors, the 68000 is capable of indirect addressing with displacement as well as PC-relative addressing, in which data is referenced relative to an instruction address. This also saves time, since again not all 32 address bits are required. Another type of addressing that distinguishes the 68000 from its competitors is postincrement/predecrement addressing. In this method, automatic increasing or decreasing of addresses with each data access allows any address register to function as a  stack. When processing sequential data fields with postincrement or predecrement addressing, you save an instruction by not having to compute the next address.

Other types of addressing were also introduced with the 68020. These 

are primarily capable of speeding up programs written, for example, in C, with its improved compilers. A  list of all the types of addressing is located in Section 11.2.

Team performance: 68020, FPU &  MMU 

Besides the widening of the address and data buses to their current 32 

bits, another improvement in the 68020 was the addition of a  universal coprocessor interface and the accompanying coprocessor, the FPU
(Floating Point Unit) 68881. The 68020 completely takes over the 

addressing of instructions and data for its coprocessor. Machine- language instructions for the FPU are simply mixed with those of the main processor. From a  software standpoint, the 68020 forms a  closed unit with its coprocessor. The exact design and programming of this chip are described in more detail later in this chapter. The 68020/30 +  FPU team is adept at screen processing and other computation-intensive tasks. The 68020 system has another coprocessor in the form of the Paged
Memory Management Unit (PMMU). This unit is responsible for 

controlling memory access of the various processes by creating a  virtual address space for each one. You're probably already familiar with the
GURU. Your experiences should help demonstrate the usefulness of this 

concept. Taking C  as an example, suppose an uninitialized pointer is used to assign a  value to a  variable. It will erroneously point to an address in memory determined by the value in the stack where it was initially set by the compiler. If this is an area of memory being used by the operating system, the GURU will come to call. The only protection the 68000 offers against such encroachment is the differentiation between supervisor and user mode. Memory can be divided by hardware means into two parts, one of which can be accessed only in supervisor mode. This technique, though, has two serious disadvantages. First, while the operating system is now safe, user programs can still be clobbered, which makes a  multitasking, and obviously a  multiuser system, impossible.

Secondly, such a  technique requires a  fixed and permanent dividing of 

memory, in which expensive RAM cannot be used to its fullest advantage. The maximum amount needed by the operating system must always be reserved for it in the supervisor area. Though part of this is used only occasionally, it is never available to user programs. In short, flexible memory management adapted to changing requirements is not possible. For these reasons, little use has been made of this capability of the
68000. Even in the Amiga, supervisor and user memory are identical, 

with the disadvantage that any task can crash the system. In the 68020 and 68030, this problem is solved by the PMMU.
Switching between processor and memory, it checks every access, 

providing protection to all areas from even the most ill-mannered task.

Actual computing functions are also faster in the 68020. A  barrel shifter 

was integrated for shift operations, making them equally fast, whether a register is shifted by a  single bit or by 15 bits. Since the 68020 functions at a  clock frequency of 20 MHz and is internally faster, it processes significantly more data and instructions from main memory than the 68000. RAM must be very fast in order for the processor to work at maximum speed. You would also like RAM to be as large as possible. Unfortunately these two requirements can add up to considerable expense. For this reason, the 68020 includes a  cache memory. This is a  small, fast storage area (64 long words or 256 bytes) in which the most recently used instruction is saved. With a  second reference to this instruction, for example another execution of a  loop, the
68020 can fetch the instruction directly from the cache without having 

to access memory. This caching enables the processor to utilize less expensive memory chips with almost the same speed as would be attained with fast RAM.
