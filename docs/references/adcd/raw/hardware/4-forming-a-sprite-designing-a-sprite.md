# 4 / Forming a Sprite / Designing a Sprite


For design purposes, it is convenient to lay out the sprite on paper
first. You can show the desired colors as numbers from 0 to 3. For
example, the spaceship shown above might look like this:




                        0000122332210000
                        0001223333221000
                        0012223333222100
                        0001223333221000
                        0000122332210000
The next step is to convert the numbers 0-3 into binary numbers, which
will be used to build the  [color descriptor words](../Hardware_Manual_guide/node00BC.html)  of the sprite
 [data structure](../Hardware_Manual_guide/node00B9.html) . The next section shows how to do this.

