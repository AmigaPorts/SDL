# A Register Summary / BLTDDAT


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BLTDDAT    ---      -      ----  Blitter destination data register


                 This register holds the data resulting from each
                 word of blitter operation until it is sent to a
                 RAM destination.  This is a dummy address and
                 cannot be read by the micro.  The transfer is
                 automatic during blitter operation.
