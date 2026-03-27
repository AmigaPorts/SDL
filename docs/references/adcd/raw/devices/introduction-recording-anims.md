# Introduction / Recording ANIMs


To record an ANIM will require three bitmaps - one for creation of the
next frame, and two more for a "history" of the previous two frames for
performing the compression calculations (e.g. the delta mode calculations).

There are five frame-to-frame compression methods currently defined. The
first three are mainly for historical interest.  The product Aegis
VideoScape 3D utilizes the third method in version 1.0, but switched to
method 5 on 2.0.  This is the only instance known of a commercial product
generating ANIMs of any of the first three methods.  The fourth method is
a general short or long word compression scheme which has several options
including whether the compression is horizontal or vertical, and whether
or not it is XOR format.  This offers a choice to the user for the
optimization of file size and/or playback speed.  The fifth method is the
byte vertical run length encoding as designed by Jim Kent.  Do not confuse
this with Jim's RIFF file format which is different than ANIM.  Here we
utilized his compression/ decompression routines within the ANIM file
structure.

The following paragraphs give a general outline of each of the methods of
compression currently included in this spec.

 [XOR Mode](../Devices_Manual_guide/node023E.html) 
 [Long Delta Mode](../Devices_Manual_guide/node023F.html) 
 [Short Delta Mode](../Devices_Manual_guide/node0240.html) 
 [General Delta Mode](../Devices_Manual_guide/node0241.html) 
 [Byte Vertical Compression](../Devices_Manual_guide/node0242.html) 

