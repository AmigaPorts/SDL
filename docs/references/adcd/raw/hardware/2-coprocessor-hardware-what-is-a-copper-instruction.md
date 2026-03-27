# 2 Coprocessor Hardware / What is a Copper Instruction?


As a coprocessor, the Copper adds its own instruction set to the
instructions already provided by the 680x0 CPU. The Copper has only three
instructions, but you can do a lot with them:

*   [WAIT](../Hardware_Manual_guide/node004B.html)  for aspecific screen position specified as x and y coordinates.

*   [MOVE](../Hardware_Manual_guide/node004A.html)  animmediate data value into one of the special-purpose
   registers.

*   [SKIP](../Hardware_Manual_guide/node0059.html) . the next instruction if the video beam has already reached
   a specified screen position.

All Copper instructions consist of two 16-bit words in sequential memory
locations. Each time the Copper fetches an instruction, it fetches both
words.

The  [MOVE](../Hardware_Manual_guide/node004A.html)  and  [SKIP](../Hardware_Manual_guide/node0059.html) . instructions require two memory cycles and two
instruction words each. Because only the odd memory cycles are requested by
the Copper, four memory cycle times are required per instruction.  The
 [WAIT](../Hardware_Manual_guide/node004B.html)  instruction requires three memory cycles and six memory cycle
times; it takes one extra memory cycle to wake up.

Although the Copper can directly affect only machine registers, it can also
affect memory indirectly by setting up a blitter operation.  More
information about how to use the Copper in controlling the blitter can be
found in the sections called  [Control Register](../Hardware_Manual_guide/node0052.html)  and
 [Using the Copper with the Blitter](../Hardware_Manual_guide/node005D.html) .

The  [WAIT](../Hardware_Manual_guide/node004B.html)  and  [MOVE](../Hardware_Manual_guide/node004A.html)  instructions are described below. The  [SKIP](../Hardware_Manual_guide/node0059.html) 
instruction is described in the "Advanced Topics" section.

