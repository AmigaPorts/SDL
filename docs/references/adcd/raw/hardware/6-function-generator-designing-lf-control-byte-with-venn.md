# 6 / Function Generator / Designing LF Control Byte with Venn Diagrams


Another way to arrive at a particular function is through the use of Venn
diagrams:


                         ______  0 ______
                        /      \  /      \
                       /        \/        \
                      /         /\         \
                     /   A     /  \     B   \
                    |    -    |    |    -    |
                    |         |  6 |         |
                    |         |    |         |
                    |       4 |____| 2       |
                    |        /|    |\        |
                    |       / |  7 | \       |
                     \     /   \  /   \     /
                      \   /  5  \/  3  \   /
                       \ |      /\      | /
                        \|_____/  \_____|/
                         |              |
                         |       1      |
                         |              |
                         |              |
                          \            /
                           \     C    /
                            \    -   /
                             \______/

             Figure 6-3: Blitter Minterm Venn Diagram
1. To select a function D=A (that is, destination = A source only),
   select only the  [minterms](../Hardware_Manual_guide/node011D.html)  that are totally enclosed by the A-circle in
   the Figure above.  This is the set of  [minterms](../Hardware_Manual_guide/node011D.html)  7, 6, 5, and 4. When
   written as a set of 1s for the selected  [minterms](../Hardware_Manual_guide/node011D.html)  and 0s for those not
   selected, the value becomes:


               Minterm Number      7 6 5 4 3 2 1 0
               Selected Minterms   1 1 1 1 0 0 0 0
                                  -----------------
                                        F   0       equals $F0
2. To select a function that is a combination of two sources, look for
   the  [minterms](../Hardware_Manual_guide/node011D.html)  by both of the circles (their intersection).  For
   example, the combination AB (A "and" B) is represented by the area
   common to both the A and B circles, or  [minterms](../Hardware_Manual_guide/node011D.html)  7 and 6.


               Minterm Numbers     7 6 5 4 3 2 1 0
               Selected Minterms   1 1 0 0 0 0 0 0
                                  -----------------
                                        C   0       equals $C0
3. To use a function that is the inverse, or "not", of one of the sources,
           _
   such as A,

   take all of the  [minterms](../Hardware_Manual_guide/node011D.html)  not enclosed by
   the circle represented by A on the above Figure.  In this case, we
   have  [minterms](../Hardware_Manual_guide/node011D.html)  0, 1, 2, and 3.


               Minterm Numbers     7 6 5 4 3 2 1 0
               Selected Minterms   0 0 0 0 1 1 1 1
                                  -----------------
                                        0   F       equals $0F
4. To combine  [minterms](../Hardware_Manual_guide/node011D.html) , or "or" them,  "or" the values together. For
   example, the equation AB+BC becomes


               Minterm Numbers     7 6 5 4 3 2 1 0
               AB                  1 1 0 0 0 0 0 0
               BC                  1 0 0 0 1 0 0 0
              -------------------------------------
               AB+BC               1 1 0 0 1 0 0 0
                                        C   8       equals $C8
