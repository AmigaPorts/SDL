# 2.0 IncludeXREF: I


id_BytesPerBlock long int in struct InfoData +0x0014 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line124): *125
id_DiskState     long int in struct InfoData +0x0008 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line121): *122
id_DiskType      long int in struct InfoData +0x0018 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line125): *126
id_InUse         long int in struct InfoData +0x0020 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line127): *128
id_NumBlocks     long int in struct InfoData +0x000c [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line122): *123
id_NumBlocksUsed long int in struct InfoData +0x0010 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line123): *124
id_NumSoftErrors long int in struct InfoData +0x0000 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line119): *120
id_UnitNumber    long int in struct InfoData +0x0004 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line120): *121
id_VolumeNode    long int in struct InfoData +0x001c [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line126): *127
ie_Class         unsigned char in struct InputEvent
```c
         +0x0004 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line200): *201
```
ie_Code          unsigned short int in struct InputEvent
```c
         +0x0006 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line202): *203
```
ie_EventAddress  #define ie_position.ie_addr  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line222): *223
ie_NextEvent     pointer to struct InputEvent in struct InputEvent
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line199): *200
```
ie_Prev1DownCode #define ie_position.ie_dead.ie_prev1DownCode
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line223): *224
```
ie_Prev1DownQual #define ie_position.ie_dead.ie_prev1DownQual
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line224): *225
```
ie_Prev2DownCode #define ie_position.ie_dead.ie_prev2DownCode
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line225): *226
```
ie_Prev2DownQual #define ie_position.ie_dead.ie_prev2DownQual
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line226): *227
```
ie_Qualifier     unsigned short int in struct InputEvent
```c
         +0x0008 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line203): *204
```
ie_SubClass      unsigned char in struct InputEvent
```c
         +0x0005 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line201): *202
```
ie_TimeStamp     struct timeval(size 0x0008 bytes) in struct InputEvent
```c
         +0x000e [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line217): *218
```
ie_X             #define ie_position.ie_xy.ie_x  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line220): *221
ie_Y             #define ie_position.ie_xy.ie_y  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line221): *222
ie_addr          pointer to void in union (no tag)
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line209): *210
```
ie_dead          struct (no tag) (size 0x0004 bytes) in union (no tag)
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line215): *216
```
ie_position      union (no tag) (size 0x0004 bytes) in struct InputEvent
```c
         +0x000a [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line216): *217
```
ie_prev1DownCode unsigned char in struct (no tag)
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line211): *212
```
ie_prev1DownQual unsigned char in struct (no tag)
```c
         +0x0001 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line212): *213
```
ie_prev2DownCode unsigned char in struct (no tag)
```c
         +0x0002 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line213): *214
```
ie_prev2DownQual unsigned char in struct (no tag)
```c
         +0x0003 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line214): *215
```
ie_x             short int in struct (no tag)
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line206): *207
```
ie_xy            struct (no tag) (size 0x0004 bytes) in union (no tag)
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line208): *209
```
ie_y             short int in struct (no tag)
```c
         +0x0002 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line207): *208
```
iepp_Position    struct (no tag) (size 0x0004 bytes) in struct IEPointerPixel
```c
         +0x0004 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line92): *93
```
iepp_Screen      pointer to struct Screen in struct IEPointerPixel
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line88): *89
```
iept_Pressure    short int in struct IEPointerTablet
```c
         +0x0008 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line117): *118
```
iept_Range       struct (no tag) (size 0x0004 bytes) in struct IEPointerTablet
```c
         +0x0000 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line111): *112
```
iept_Value       struct (no tag) (size 0x0004 bytes) in struct IEPointerTablet
```c
         +0x0004 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line115): *116
```
iff_Depth        long int in struct IFFHandle +0x0008 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line37): *38
iff_Flags        unsigned long int in struct IFFHandle
```c
         +0x0004 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line36): *37
```
iff_Stream       unsigned long int in struct IFFHandle
```c
         +0x0000 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line35): *36
```
impDraw          structure tag size 0x0018 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line151): *152
impErase         structure tag (size 0x0010 bytes)in struct impErase
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line171): *172
```
impFrameBox      structure tag size 0x0014 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line138): *139
impHitTest       structure tag (size 0x000c bytes)in struct impHitTest
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line187): *188
```
imp_ContentsBox pointer to struct IBox in struct impFrameBox
```c
         +0x0004 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line140): *141
```
imp_Dimensions   struct (no tag) (size 0x0004 bytes) in struct impDraw
```c
         +0x0014 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line166): *167
```
imp_Dimensions   struct (no tag) (size 0x0004 bytes) in struct impErase
```c
         +0x000c [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line183): *184
```
imp_Dimensions   struct (no tag) (size 0x0004 bytes) in struct impHitTest
```c
         +0x0008 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line198): *199
```
imp_DrInfo       pointer to struct DrawInfo in struct impFrameBox
```c
         +0x000c [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line142): *143
```
imp_DrInfo       pointer to struct DrawInfo in struct impDraw
```c
         +0x0010 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line160): *161
```
imp_FrameBox     pointer to struct IBox in struct impFrameBox
```c
         +0x0008 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line141): *142
```
imp_FrameFlags   unsigned long int in struct impFrameBox
```c
         +0x0010 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line143): *144
```
imp_Offset       struct (no tag) (size 0x0004 bytes) in struct impDraw
```c
         +0x0008 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line157): *158
```
imp_Offset       struct (no tag) (size 0x0004 bytes) in struct impErase
```c
         +0x0008 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line177): *178
```
imp_Point        struct (no tag) (size 0x0004 bytes) in struct impHitTest
```c
         +0x0004 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line192): *193
```
imp_RPort        pointer to struct RastPort in struct impDraw
```c
         +0x0004 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line153): *154
```
imp_RPort        pointer to struct RastPort in struct impErase
```c
         +0x0004 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line173): *174
```
imp_State        unsigned long int in struct impDraw
```c
         +0x000c [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line159): *160
```
intena           unsigned short int in struct Custom
```c
         +0x009a [hardware/custom.h](../Includes_and_Autodocs_2._guide/node00CD.html#line93): *94
```
intenar          unsigned short int in struct Custom
```c
         +0x001c [hardware/custom.h](../Includes_and_Autodocs_2._guide/node00CD.html#line41): *42
```
intreq           unsigned short int in struct Custom
```c
         +0x009c [hardware/custom.h](../Includes_and_Autodocs_2._guide/node00CD.html#line94): *95
```
intreqr          unsigned short int in struct Custom
```c
         +0x001e [hardware/custom.h](../Includes_and_Autodocs_2._guide/node00CD.html#line42): *43
```
io_Actual        unsigned long int in struct IOStdReq +0x0020 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line35): *36
io_Actual        unsigned long int in struct IOClipReq
```c
         +0x0020 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line49): *50
```
io_Baud          unsigned long int in struct IOExtSer
```c
         +0x003c [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line64): *65
```
io_BrkTime       unsigned long int in struct IOExtSer
```c
         +0x0040 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line65): *66
```
io_ClipID        long int in struct IOClipReq +0x0030 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line53): *54
io_ColorMap      pointer to struct ColorMap in struct IODRPReq
```c
         +0x0024 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line163): *164
```
io_Command       unsigned short int in struct IORequest +0x001c [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line23): *24
io_Command       unsigned short int in struct IOStdReq +0x001c [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line32): *33
io_Command       unsigned short int in struct IOClipReq
```c
         +0x001c [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line46): *47
```
io_Command       unsigned short int in struct IOPrtCmdReq
```c
         +0x001c [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line145): *146
```
io_Command       unsigned short int in struct IODRPReq
```c
         +0x001c [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line159): *160
```
io_CtlChar       unsigned long int in struct IOExtSer
```c
         +0x0030 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line61): *62
```
io_Data          pointer to void in struct IOStdReq +0x0028 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line37): *38
io_Data          pointer to unsigned char in struct IOClipReq
```c
         +0x0028 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line51): *52
```
io_DestCols      long int in struct IODRPReq +0x0034 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line169): *170
io_DestRows      long int in struct IODRPReq +0x0038 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line170): *171
io_Device        pointer to struct Device in struct IORequest
```c
         +0x0014 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line21): *22
```
io_Device        pointer to struct Device in struct IOStdReq
```c
         +0x0014 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line30): *31
```
io_Device        pointer to struct Device in struct IOClipReq
```c
         +0x0014 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line44): *45
```
io_Device        pointer to struct Device in struct IOPrtCmdReq
```c
         +0x0014 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line143): *144
```
io_Device        pointer to struct Device in struct IODRPReq
```c
         +0x0014 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line157): *158
```
io_Error         char in struct IORequest +0x001f [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line25): *26
io_Error         char in struct IOStdReq +0x001f [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line34): *35
io_Error         char in struct IOClipReq +0x001f [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line48): *49
io_Error         char in struct IOPrtCmdReq +0x001f [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line147): *148
io_Error         char in struct IODRPReq +0x001f [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line161): *162
io_ExtFlags      unsigned long int in struct IOExtSer
```c
         +0x0038 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line63): *64
```
io_Flags         unsigned char in struct IORequest +0x001e [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line24): *25
io_Flags         unsigned char in struct IOStdReq +0x001e [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line33): *34
io_Flags         unsigned char in struct IOClipReq
```c
         +0x001e [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line47): *48
```
io_Flags         unsigned char in struct IOPrtCmdReq
```c
         +0x001e [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line146): *147
```
io_Flags         unsigned char in struct IODRPReq
```c
         +0x001e [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line160): *161
```
io_Length        unsigned long int in struct IOStdReq +0x0024 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line36): *37
io_Length        unsigned long int in struct IOClipReq
```c
         +0x0024 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line50): *51
```
io_Message       struct Message(size 0x0014 bytes) in struct IORequest
```c
         +0x0000 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line20): *21
```
io_Message       struct Message(size 0x0014 bytes) in struct IOStdReq
```c
         +0x0000 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line29): *30
```
io_Message       struct Message(size 0x0014 bytes) in struct IOClipReq
```c
         +0x0000 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line43): *44
```
io_Message       struct Message(size 0x0014 bytes) in struct IOPrtCmdReq
```c
         +0x0000 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line142): *143
```
io_Message       struct Message(size 0x0014 bytes) in struct IODRPReq
```c
         +0x0000 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line156): *157
```
io_Modes         unsigned long int in struct IODRPReq
```c
         +0x0028 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line164): *165
```
io_Offset        unsigned long int in struct IOStdReq +0x002c [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line38): *39
io_Offset        unsigned long int in struct IOClipReq
```c
         +0x002c [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line52): *53
```
io_PExtFlags     unsigned long int in struct IOExtPar
```c
         +0x0030 [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line51): *52
```
io_PTermArray    struct IOPArray(size 0x0008 bytes) in struct IOExtPar
```c
         +0x0036 [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line54): *55
```
io_ParFlags      unsigned char in struct IOExtPar
```c
         +0x0035 [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line53): *54
```
io_Parm0         unsigned char in struct IOPrtCmdReq
```c
         +0x0022 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line149): *150
```
io_Parm1         unsigned char in struct IOPrtCmdReq
```c
         +0x0023 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line150): *151
```
io_Parm2         unsigned char in struct IOPrtCmdReq
```c
         +0x0024 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line151): *152
```
io_Parm3         unsigned char in struct IOPrtCmdReq
```c
         +0x0025 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line152): *153
```
io_PrtCommand    unsigned short int in struct IOPrtCmdReq
```c
         +0x0020 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line148): *149
```
io_RBufLen       unsigned long int in struct IOExtSer
```c
         +0x0034 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line62): *63
```
io_RastPort      pointer to struct RastPort in struct IODRPReq
```c
         +0x0020 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line162): *163
```
io_ReadLen       unsigned char in struct IOExtSer +0x004c [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line67): *68
io_SerFlags      unsigned char in struct IOExtSer +0x004f [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line70): *71
io_Special       unsigned short int in struct IODRPReq
```c
         +0x003c [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line171): *172
```
io_SrcHeight     unsigned short int in struct IODRPReq
```c
         +0x0032 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line168): *169
```
io_SrcWidth      unsigned short int in struct IODRPReq
```c
         +0x0030 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line167): *168
```
io_SrcX          unsigned short int in struct IODRPReq
```c
         +0x002c [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line165): *166
```
io_SrcY          unsigned short int in struct IODRPReq
```c
         +0x002e [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line166): *167
```
io_Status        unsigned char in struct IOExtPar
```c
         +0x0034 [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line52): *53
```
io_Status        unsigned short int in struct IOExtSer
```c
         +0x0050 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line71): *72
```
io_StopBits      unsigned char in struct IOExtSer +0x004e [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line69): *70
io_TermArray     struct IOTArray(size 0x0008 bytes) in struct IOExtSer
```c
         +0x0044 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line66): *67
```
io_Unit          pointer to struct Unit in struct IORequest
```c
         +0x0018 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line22): *23
```
io_Unit          pointer to struct Unit in struct IOStdReq
```c
         +0x0018 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line31): *32
```
io_Unit          pointer to struct ClipboardUnitPartial in struct IOClipReq
```c
         +0x0018 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line45): *46
```
io_Unit          pointer to struct Unit in struct IOPrtCmdReq
```c
         +0x0018 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line144): *145
```
io_Unit          pointer to struct Unit in struct IODRPReq
```c
         +0x0018 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line158): *159
```
io_WriteLen      unsigned char in struct IOExtSer +0x004d [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line68): *69
ioa_AllocKey     short int in struct IOAudio +0x0020 [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line48): *49
ioa_Cycles       unsigned short int in struct IOAudio
```c
         +0x002e [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line53): *54
```
ioa_Data         pointer to unsigned char in struct IOAudio
```c
         +0x0022 [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line49): *50
```
ioa_Length       unsigned long int in struct IOAudio
```c
         +0x0026 [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line50): *51
```
ioa_Period       unsigned short int in struct IOAudio
```c
         +0x002a [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line51): *52
```
ioa_Request      struct IORequest(size 0x0020 bytes) in struct IOAudio
```c
         +0x0000 [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line47): *48
```
ioa_Volume       unsigned short int in struct IOAudio
```c
         +0x002c [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line52): *53
```
ioa_WriteMsg     struct Message(size 0x0014 bytes) in struct IOAudio
```c
         +0x0030 [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line54): *55
```
iobArea          array [204] of char in struct IoBuff
```c
         +0x0034 [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line31): *32
```
iobBct           long int in struct IoBuff +0x0030 [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line30): *31
iobDFH           long int in struct IoBuff +0x0028 [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line28): *29
iobLock          pointer to void in struct IoBuff +0x002c [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line29): *30
iobNode          struct RexxRsrc(size 0x0020 bytes) in struct IoBuff
```c
         +0x0000 [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line25): *26
```
iobRct           long int in struct IoBuff +0x0024 [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line27): *28
iobRpt           pointer to void in struct IoBuff +0x0020 [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line26): *27
iotd_Count       unsigned long int in struct IOExtTD
```c
         +0x0030 [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line120): *121
```
iotd_Req         struct IOStdReq(size 0x0030 bytes) in struct IOExtTD
```c
         +0x0000 [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line119): *120
```
iotd_SecLabel    unsigned long int in struct IOExtTD
```c
         +0x0034 [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line121): *122
```
is_Code          pointer to function returning void in struct Interrupt
```c
         +0x0012 [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line26): *27
```
is_Data          pointer to void in struct Interrupt
```c
         +0x000e [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line25): *26
```
is_Node          struct Node(size 0x000e bytes) in struct Interrupt
```c
         +0x0000 [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line24): *25
```
is_Node          struct Node(size 0x000e bytes) in struct Isrvstr
```c
         +0x0000 [graphics/graphint.h](../Includes_and_Autodocs_2._guide/node00C1.html#line21): *22
```
itof             macro (1 argument)   [libraries/mathffp.h](../Includes_and_Autodocs_2._guide/node00EF.html#line32): *33
```c
                 [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line32): *33
```
iv_Code          pointer to function returning void in struct IntVector
```c
         +0x0004 [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line32): *33
```
iv_Data          pointer to void in struct IntVector
```c
         +0x0000 [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line31): *32
```
iv_Node          pointer to struct Node in struct IntVector
```c
         +0x0008 [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line33): *34
```
ix_Class         unsigned char in struct InputXpression
```c
         +0x0001 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line174): *175
```
ix_Code          unsigned short int in struct InputXpression
```c
         +0x0002 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line176): *177
```
ix_CodeMask      unsigned short int in struct InputXpression
```c
         +0x0004 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line178): *179
```
ix_QualMask      unsigned short int in struct InputXpression
```c
         +0x0008 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line184): *185
```
ix_QualSame      unsigned short int in struct InputXpression
```c
         +0x000a [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line188): *189
```
ix_Qualifier     unsigned short int in struct InputXpression
```c
         +0x0006 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line182): *183
```
ix_Version       unsigned char in struct InputXpression
```c
         +0x0000 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line173): *174
```
IA_APATSIZE      #define IA_APatSize = 0x80020011  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line245): *246
IA_APATTERN      #define IA_APattern = 0x80020010  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line244): *245
IA_APatSize      #define (IA_Dummy + 0x11) = 0x80020011
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line62): *63
```
IA_APattern      #define (IA_Dummy + 0x10) = 0x80020010
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line61): *62
```
IA_BGPEN         #define IA_BGPen = 0x80020006  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line239): *240
IA_BGPen         #define (IA_Dummy + 0x06) = 0x80020006
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line40): *41
```
IA_DATA          #define IA_Data = 0x80020007  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line240): *241
IA_DOUBLEEMBOSS  #define IA_DoubleEmboss = 0x80020016
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line250): *251
```
IA_Data          #define (IA_Dummy + 0x07) = 0x80020007
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line42): *43
```
IA_DoubleEmboss  #define (IA_Dummy + 0x16) = 0x80020016
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line67): *68
```
IA_Dummy         #define (TAG_USER + 0x20000) = 0x80020000
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line33): *34
```
IA_EDGESONLY     #define IA_EdgesOnly = 0x80020017
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line251): *252
```
IA_EdgesOnly     #define (IA_Dummy + 0x17) = 0x80020017
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line68): *69
```
IA_FGPEN         #define IA_FGPen = 0x80020005  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line238): *239
IA_FGPen         #define (IA_Dummy + 0x05) = 0x80020005
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line38): *39
```
IA_FONT          #define IA_Font = 0x80020013  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line247): *248
IA_Font          #define (IA_Dummy + 0x13) = 0x80020013
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line64): *65
```
IA_HEIGHT        #define IA_Height = 0x80020004  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line237): *238
IA_HIGHLIGHTPEN  #define IA_HighlightPen = 0x8002000a
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line253): *254
```
IA_Height        #define (IA_Dummy + 0x04) = 0x80020004
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line37): *38
```
IA_HighlightPen  #define (IA_Dummy + 0x0A) = 0x8002000a
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line85): *86
```
IA_LEFT          #define IA_Left = 0x80020001  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line234): *235
IA_LINEWIDTH     #define IA_LineWidth = 0x80020008
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line241): *242
```
IA_Left          #define (IA_Dummy + 0x01) = 0x80020001
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line34): *35
```
IA_LineWidth     #define (IA_Dummy + 0x08) = 0x80020008
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line46): *47
```
IA_MODE          #define IA_Mode = 0x80020012  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line246): *247
IA_Mode          #define (IA_Dummy + 0x12) = 0x80020012
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line63): *64
```
IA_OUTLINE       #define IA_Outline = 0x80020014  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line248): *249
IA_Outline       #define (IA_Dummy + 0x14) = 0x80020014
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line65): *66
```
IA_PENS          #define IA_Pens = 0x8002000e  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line242): *243
IA_Pens          #define (IA_Dummy + 0x0E) = 0x8002000e
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line47): *48
```
IA_RECESSED      #define IA_Recessed = 0x80020015  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line249): *250
IA_RESOLUTION    #define IA_Resolution = 0x8002000f
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line243): *244
```
IA_Recessed      #define (IA_Dummy + 0x15) = 0x80020015
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line66): *67
```
IA_Resolution    #define (IA_Dummy + 0x0F) = 0x8002000f
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line54): *55
```
IA_SHADOWPEN     #define IA_ShadowPen = 0x80020009
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line252): *253
```
IA_ShadowPen     #define (IA_Dummy + 0x09) = 0x80020009
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line84): *85
```
IA_TOP           #define IA_Top = 0x80020002  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line235): *236
IA_Top           #define (IA_Dummy + 0x02) = 0x80020002
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line35): *36
```
IA_WIDTH         #define IA_Width = 0x80020003  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line236): *237
IA_Width         #define (IA_Dummy + 0x03) = 0x80020003
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line36): *37
```
IAddress         pointer to void in struct IntuiMessage
```c
         +0x001c [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line694): *695
```
IBox             structure tag size 0x0008 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line782): *783
```c
                 [intuition/cghooks.h](../Includes_and_Autodocs_2._guide/node00D2.html#line48): 49, 72, 73
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line140): 141, 142
```
ICA_Dummy        #define (TAG_USER+0x40000L) = 0x80040000
```c
                 [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line27): *28
```
ICA_MAP          #define (ICA_Dummy + 2) = 0x80040002
```c
                 [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line30): *31
```
ICA_TARGET       #define (ICA_Dummy + 1) = 0x80040001
```c
                 [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line28): *29
```
ICCLASS          #define "icclass"  [intuition/classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line52): *53
ICM_CHECKLOOP    #define (0x0404L) = 0x00000404  [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line22): *23
ICM_CLEARLOOP    #define (0x0403L) = 0x00000403  [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line21): *22
ICM_Dummy        #define (0x0401L) = 0x00000401  [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line19): *20
ICM_SETLOOP      #define (0x0402L) = 0x00000402  [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line20): *21
ICONNAME         #define "icon.library"  [workbench/icon.h](../Includes_and_Autodocs_2._guide/node0133.html#line14): *15
ICSPECIAL_CODE   #define (ICA_Dummy + 3) = 0x80040003
```c
                 [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line32): *33
```
ICTARGET_IDCMP   #define (~0L) = 0xffffffff  [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line47): *48
IClass           structure tag size 0x0034 [intuition/classes.h](../Includes_and_Autodocs_2._guide/node00DA.html#line27): *28, 31, 70
IDCMPFlags       unsigned long int in struct Window
```c
         +0x0052 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line854): *855
```
IDCMPFlags       unsigned long int in struct NewWindow
```c
         +0x000a [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line980): *981
```
IDCMPFlags       unsigned long int in struct ExtNewWindow
```c
         +0x000a [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line1049): *1050
```
IDCMPUPDATE      #define IDCMP_IDCMPUPDATE = 0x00800000
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line136): *137
```
IDCMPWindow      pointer to struct Window in struct IntuiMessage
```c
         +0x002c [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line712): *713
```
IDCMP_ACTIVEWINDOW #define 0x00040000 = 0x00040000
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line741): *742
```
IDCMP_CHANGEWINDOW #define 0x02000000 = 0x02000000
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line751): *752
```
IDCMP_CLOSEWINDOW #define 0x00000200 = 0x00000200  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line732): *733
IDCMP_DELTAMOVE  #define 0x00100000 = 0x00100000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line743): *744
IDCMP_DISKINSERTED #define 0x00008000 = 0x00008000
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line738): *739
```
IDCMP_DISKREMOVED #define 0x00010000 = 0x00010000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line739): *740
IDCMP_GADGETDOWN #define 0x00000020 = 0x00000020  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line728): *729
IDCMP_GADGETUP   #define 0x00000040 = 0x00000040  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line729): *730
IDCMP_IDCMPUPDATE #define 0x00800000 = 0x00800000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line747): *748
IDCMP_INACTIVEWINDOW #define 0x00080000 = 0x00080000
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line742): *743
```
IDCMP_INTUITICKS #define 0x00400000 = 0x00400000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line745): *746
IDCMP_LONELYMESSAGE #define 0x80000000 = 0x80000000
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line760): *761
```
IDCMP_MENUHELP   #define 0x01000000 = 0x01000000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line749): *750
IDCMP_MENUPICK   #define 0x00000100 = 0x00000100  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line731): *732
IDCMP_MENUVERIFY #define 0x00002000 = 0x00002000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line736): *737
IDCMP_MOUSEBUTTONS #define 0x00000008 = 0x00000008
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line726): *727
```
IDCMP_MOUSEMOVE  #define 0x00000010 = 0x00000010  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line727): *728
IDCMP_NEWPREFS   #define 0x00004000 = 0x00004000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line737): *738
IDCMP_NEWSIZE    #define 0x00000002 = 0x00000002  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line724): *725
IDCMP_RAWKEY     #define 0x00000400 = 0x00000400  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line733): *734
IDCMP_REFRESHWINDOW #define 0x00000004 = 0x00000004
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line725): *726
```
IDCMP_REQCLEAR   #define 0x00001000 = 0x00001000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line735): *736
IDCMP_REQSET     #define 0x00000080 = 0x00000080  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line730): *731
IDCMP_REQVERIFY  #define 0x00000800 = 0x00000800  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line734): *735
IDCMP_SIZEVERIFY #define 0x00000001 = 0x00000001  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line723): *724
IDCMP_VANILLAKEY #define 0x00200000 = 0x00200000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line744): *745
IDCMP_WBENCHMESSAGE #define 0x00020000 = 0x00020000
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line740): *741
```
IDNAME_BADBLOCK  #define 0x42414442 = 0x42414442  [devices/hardblocks.h](../Includes_and_Autodocs_2._guide/node0041.html#line124): *125
IDNAME_FILESYSHEADER #define 0x46534844 = 0x46534844
```c
                 [devices/hardblocks.h](../Includes_and_Autodocs_2._guide/node0041.html#line181): *182
```
IDNAME_LOADSEG   #define 0x4C534547 = 0x4c534547  [devices/hardblocks.h](../Includes_and_Autodocs_2._guide/node0041.html#line194): *195
IDNAME_PARTITION #define 0x50415254 = 0x50415254  [devices/hardblocks.h](../Includes_and_Autodocs_2._guide/node0041.html#line143): *144
IDNAME_RIGIDDISK #define 0x5244534B = 0x5244534b  [devices/hardblocks.h](../Includes_and_Autodocs_2._guide/node0041.html#line91): *92
IDNestCnt        char in struct ExecBase +0x0126 [exec/execbase.h](../Includes_and_Autodocs_2._guide/node009E.html#line69): *70
IDS_BUSY         #define (3L) = 0x00000003  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line128): *129
IDS_DISABLED     #define (2L) = 0x00000002  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line127): *128
IDS_INACTIVEDISABLED #define (7L) = 0x00000007  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line132): *133
IDS_INACTIVENORMAL #define (5L) = 0x00000005  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line130): *131
IDS_INACTIVESELECTED #define (6L) = 0x00000006  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line131): *132
IDS_INDETERMINANT #define IDS_INDETERMINATE = 0x00000004
```c
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line135): *136
```
IDS_INDETERMINATE #define (4L) = 0x00000004  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line129): *130
IDS_NORMAL       #define (0L) = 0x00000000  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line125): *126
IDS_SELECTED     #define (1L) = 0x00000001  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line126): *127
ID_CAT           #define MAKE_ID('C','A','T',' ') = 0x43415420
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line149): *150
```
ID_DOS_DISK      #define (0x444F5300L) = 0x444f5300  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line139): *140
ID_FFS_DISK      #define (0x444F5301L) = 0x444f5301  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line140): *141
ID_FORM          #define MAKE_ID('F','O','R','M') = 0x464f524d
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line147): *148
```
ID_KICKSTART_DISK #define (0x4B49434BL) = 0x4b49434b  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line142): *143
ID_LIST          #define MAKE_ID('L','I','S','T') = 0x4c495354
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line148): *149
```
ID_MSDOS_DISK    #define (0x4d534400L) = 0x4d534400  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line143): *144
ID_NOT_REALLY_DOS #define (0x4E444F53L) = 0x4e444f53  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line141): *142
ID_NO_DISK_PRESENT #define (-1) = 0xffffffff  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line137): *138
ID_NULL          #define MAKE_ID(' ',' ',' ',' ') = 0x20202020
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line151): *152
```
ID_PROP          #define MAKE_ID('P','R','O','P') = 0x50524f50
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line150): *151
```
ID_UNREADABLE_DISK #define (0x42414400L) = 0x42414400  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line138): *139
ID_VALIDATED     #define 82 = 0x00000052  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line134): *135
ID_VALIDATING    #define 81 = 0x00000051  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line133): *134
ID_WRITE_PROTECTED #define 80 = 0x00000050  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line132): *133
IECLASS_ACTIVEWINDOW #define 0x11 = 0x00000011  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line54): *55
IECLASS_CHANGEWINDOW #define 0x15 = 0x00000015  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line62): *63
IECLASS_CLOSEWINDOW #define 0x0B = 0x0000000b  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line42): *43
IECLASS_DISKINSERTED #define 0x10 = 0x00000010  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line52): *53
IECLASS_DISKREMOVED #define 0x0F = 0x0000000f  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line50): *51
IECLASS_EVENT    #define 0x03 = 0x00000003  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line28): *29
IECLASS_GADGETDOWN #define 0x07 = 0x00000007  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line34): *35
IECLASS_GADGETUP #define 0x08 = 0x00000008  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line36): *37
IECLASS_INACTIVEWINDOW #define 0x12 = 0x00000012  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line56): *57
IECLASS_MAX      #define 0x15 = 0x00000015  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line65): *66
```c
                 [devices/conunit.h](../Includes_and_Autodocs_2._guide/node0058.html#line98): 99
```
IECLASS_MENUHELP #define 0x14 = 0x00000014  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line60): *61
IECLASS_MENULIST #define 0x0A = 0x0000000a  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line40): *41
IECLASS_NEWPOINTERPOS #define 0x13 = 0x00000013  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line58): *59
IECLASS_NEWPREFS #define 0x0E = 0x0000000e  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line48): *49
IECLASS_NULL     #define 0x00 = 0x00000000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line22): *23
IECLASS_POINTERPOS #define 0x04 = 0x00000004  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line30): *31
IECLASS_RAWKEY   #define 0x01 = 0x00000001  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line24): *25
IECLASS_RAWMOUSE #define 0x02 = 0x00000002  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line26): *27
IECLASS_REFRESHWINDOW #define 0x0D = 0x0000000d  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line46): *47
IECLASS_REQUESTER #define 0x09 = 0x00000009  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line38): *39
IECLASS_SIZEWINDOW #define 0x0C = 0x0000000c  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line44): *45
IECLASS_TIMER    #define 0x06 = 0x00000006  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line32): *33
IECODE_ASCII_DEL #define 0x7F = 0x0000007f  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line135): *136
IECODE_ASCII_FIRST #define 0x20 = 0x00000020  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line133): *134
IECODE_ASCII_LAST #define 0x7E = 0x0000007e  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line134): *135
IECODE_C0_FIRST  #define 0x00 = 0x00000000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line131): *132
IECODE_C0_LAST   #define 0x1F = 0x0000001f  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line132): *133
IECODE_C1_FIRST  #define 0x80 = 0x00000080  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line136): *137
IECODE_C1_LAST   #define 0x9F = 0x0000009f  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line137): *138
IECODE_COMM_CODE_FIRST #define 0x78 = 0x00000078  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line127): *128
IECODE_COMM_CODE_LAST #define 0x7F = 0x0000007f  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line128): *129
IECODE_KEY_CODE_FIRST #define 0x00 = 0x00000000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line125): *126
IECODE_KEY_CODE_LAST #define 0x77 = 0x00000077  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line126): *127
IECODE_LATIN1_FIRST #define 0xA0 = 0x000000a0  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line138): *139
IECODE_LATIN1_LAST #define 0xFF = 0x000000ff  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line139): *140
IECODE_LBUTTON   #define 0x68 = 0x00000068  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line142): *143
IECODE_MBUTTON   #define 0x6A = 0x0000006a  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line144): *145
IECODE_NEWACTIVE #define 0x01 = 0x00000001  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line148): *149
IECODE_NEWSIZE   #define 0x02 = 0x00000002  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line149): *150
IECODE_NOBUTTON  #define 0xFF = 0x000000ff  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line145): *146
IECODE_RBUTTON   #define 0x69 = 0x00000069  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line143): *144
IECODE_REFRESH   #define 0x03 = 0x00000003  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line150): *151
IECODE_REQCLEAR  #define 0x00 = 0x00000000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line157): *158
IECODE_REQSET    #define 0x01 = 0x00000001  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line155): *156
IECODE_UP_PREFIX #define 0x80 = 0x00000080  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line124): *125
IEEEDPACos       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line56): *57
IEEEDPASin       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line57): *58
IEEEDPAbs        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line69): *70
IEEEDPAdd        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line71): *72
IEEEDPAtan       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line55): *56
IEEEDPCeil       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line76): *77
IEEEDPCos        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line56): *57
IEEEDPCosh       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line62): *63
IEEEDPDiv        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line74): *75
IEEEDPExp        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line58): *59
IEEEDPFieee      function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line64): *65
IEEEDPFloor      function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line75): *76
IEEEDPFlt        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line68): *69
IEEEDPLog        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line58): *59
IEEEDPLog10      function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line60): *61
IEEEDPMul        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line73): *74
IEEEDPNeg        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line70): *71
IEEEDPPow        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line60): *61
IEEEDPSin        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line57): *58
IEEEDPSincos     function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line61): *62
IEEEDPSinh       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line62): *63
IEEEDPSqrt       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line59): *60
IEEEDPSub        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line72): *73
IEEEDPTan        function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line55): *56
IEEEDPTanh       function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line62): *63
IEEEDPTieee      function returning "LONG"   [libraries/mathieeedp.h](../Includes_and_Autodocs_2._guide/node00F2.html#line63): *64
IEPointerPixel   structure tag size 0x0008 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line87): *88
IEPointerTablet structure tag (size 0x000a bytes)in struct IEPointerTablet
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line107): *108
```
IEQUALIFIERB_CAPSLOCK #define 2 = 0x00000002  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line181): *182
IEQUALIFIERB_CONTROL #define 3 = 0x00000003  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line182): *183
IEQUALIFIERB_INTERRUPT #define 10 = 0x0000000a  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line189): *190
IEQUALIFIERB_LALT #define 4 = 0x00000004  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line183): *184
IEQUALIFIERB_LCOMMAND #define 6 = 0x00000006  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line185): *186
IEQUALIFIERB_LEFTBUTTON #define 14 = 0x0000000e  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line193): *194
IEQUALIFIERB_LSHIFT #define 0 = 0x00000000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line179): *180
IEQUALIFIERB_MIDBUTTON #define 12 = 0x0000000c  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line191): *192
IEQUALIFIERB_MULTIBROADCAST #define 11 = 0x0000000b
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line190): *191
```
IEQUALIFIERB_NUMERICPAD #define 8 = 0x00000008  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line187): *188
IEQUALIFIERB_RALT #define 5 = 0x00000005  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line184): *185
IEQUALIFIERB_RBUTTON #define 13 = 0x0000000d  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line192): *193
IEQUALIFIERB_RCOMMAND #define 7 = 0x00000007  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line186): *187
IEQUALIFIERB_RELATIVEMOUSE #define 15 = 0x0000000f  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line194): *195
IEQUALIFIERB_REPEAT #define 9 = 0x00000009  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line188): *189
IEQUALIFIERB_RSHIFT #define 1 = 0x00000001  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line180): *181
IEQUALIFIER_CAPSLOCK #define 0x0004 = 0x00000004  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line164): *165
IEQUALIFIER_CONTROL #define 0x0008 = 0x00000008  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line165): *166
IEQUALIFIER_INTERRUPT #define 0x0400 = 0x00000400  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line172): *173
IEQUALIFIER_LALT #define 0x0010 = 0x00000010  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line166): *167
IEQUALIFIER_LCOMMAND #define 0x0040 = 0x00000040  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line168): *169
IEQUALIFIER_LEFTBUTTON #define 0x4000 = 0x00004000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line176): *177
IEQUALIFIER_LSHIFT #define 0x0001 = 0x00000001  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line162): *163
IEQUALIFIER_MIDBUTTON #define 0x1000 = 0x00001000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line174): *175
IEQUALIFIER_MULTIBROADCAST #define 0x0800 = 0x00000800
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line173): *174
```
IEQUALIFIER_NUMERICPAD #define 0x0100 = 0x00000100  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line170): *171
IEQUALIFIER_RALT #define 0x0020 = 0x00000020  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line167): *168
IEQUALIFIER_RBUTTON #define 0x2000 = 0x00002000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line175): *176
IEQUALIFIER_RCOMMAND #define 0x0080 = 0x00000080  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line169): *170
IEQUALIFIER_RELATIVEMOUSE #define 0x8000 = 0x00008000
```c
                 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line177): *178
```
IEQUALIFIER_REPEAT #define 0x0200 = 0x00000200  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line171): *172
IEQUALIFIER_RSHIFT #define 0x0002 = 0x00000002  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line163): *164
IESUBCLASS_COMPATIBLE #define 0x00 = 0x00000000  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line71): *72
IESUBCLASS_PIXEL #define 0x01 = 0x00000001  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line73): *74
IESUBCLASS_TABLET #define 0x02 = 0x00000002  [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line75): *76
IEvent           pointer to struct InputEvent in struct SGWork
```c
         +0x0014 [intuition/sghooks.h](../Includes_and_Autodocs_2._guide/node00E5.html#line41): *42
```
IFFCMD_CLEANUP   #define 1 = 0x00000001  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line188): *189
IFFCMD_ENTRY     #define 5 = 0x00000005  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line192): *193
IFFCMD_EXIT      #define 6 = 0x00000006  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line193): *194
IFFCMD_INIT      #define 0 = 0x00000000  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line187): *188
IFFCMD_PURGELCI  #define 7 = 0x00000007  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line194): *195
IFFCMD_READ      #define 2 = 0x00000002  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line189): *190
IFFCMD_SEEK      #define 4 = 0x00000004  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line191): *192
IFFCMD_WRITE     #define 3 = 0x00000003  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line190): *191
IFFERR_EOC       #define -2L = 0xfffffffe  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line129): *130
IFFERR_EOF       #define -1L = 0xffffffff  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line128): *129
IFFERR_MANGLED   #define -8L = 0xfffffff8  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line135): *136
IFFERR_NOHOOK    #define -11L = 0xfffffff5  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line138): *139
IFFERR_NOMEM     #define -4L = 0xfffffffc  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line131): *132
IFFERR_NOSCOPE   #define -3L = 0xfffffffd  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line130): *131
IFFERR_NOTIFF    #define -10L = 0xfffffff6  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line137): *138
IFFERR_READ      #define -5L = 0xfffffffb  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line132): *133
IFFERR_SEEK      #define -7L = 0xfffffff9  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line134): *135
IFFERR_SYNTAX    #define -9L = 0xfffffff7  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line136): *137
IFFERR_WRITE     #define -6L = 0xfffffffa  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line133): *134
IFFF_FSEEK       #define (1L<<1) = 0x00000002  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line47): *48
IFFF_READ        #define 0L = 0x00000000  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line44): *45
IFFF_RESERVED    #define 0xFFFF0000L = 0xffff0000  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line49): *50
IFFF_RSEEK       #define (1L<<2) = 0x00000004  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line48): *49
IFFF_RWBITS      #define (IFFF_READ | IFFF_WRITE) = 0x00000001
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line46): *47
```
IFFF_WRITE       #define 1L = 0x00000001  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line45): *46
IFFHandle        structure tag size 0x000c [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line34): *35
IFFLCI_COLLECTION #define MAKE_ID('c','o','l','l') = 0x636f6c6c
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line157): *158
```
IFFLCI_ENTRYHANDLER #define MAKE_ID('e','n','h','d') = 0x656e6864
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line158): *159
```
IFFLCI_EXITHANDLER #define MAKE_ID('e','x','h','d') = 0x65786864
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line159): *160
```
IFFLCI_PROP      #define MAKE_ID('p','r','o','p') = 0x70726f70
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line156): *157
```
IFFPARSE_RAWSTEP #define 2L = 0x00000002  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line166): *167
IFFPARSE_SCAN    #define 0L = 0x00000000  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line164): *165
IFFPARSE_STEP    #define 1L = 0x00000001  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line165): *166
IFFSCC_CLEANUP   #define IFFCMD_CLEANUP = 0x00000001
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line198): *199
```
IFFSCC_INIT      #define IFFCMD_INIT = 0x00000000  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line197): *198
IFFSCC_READ      #define IFFCMD_READ = 0x00000002  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line199): *200
IFFSCC_SEEK      #define IFFCMD_SEEK = 0x00000004  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line201): *202
IFFSCC_WRITE     #define IFFCMD_WRITE = 0x00000003  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line200): *201
IFFSIZE_UNKNOWN  #define -1L = 0xffffffff  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line181): *182
IFFSLI_PROP      #define 3L = 0x00000003  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line173): *174
IFFSLI_ROOT      #define 1L = 0x00000001  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line171): *172
IFFSLI_TOP       #define 2L = 0x00000002  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line172): *173
IFFStreamCmd     structure tag size 0x000c [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line55): *56
IFF_IFFPARSE_H   #define  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html): *2
IFF_RETURN2CLIENT #define -12L = 0xfffffff4  [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line139): *140
IFont            pointer to struct TextFont in struct Window
```c
         +0x0080 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line894): *895
```
IGNORE_DIMENSIONS #define 0x0000 = 0x00000000  [intuition/preferences.h](../Includes_and_Autodocs_2._guide/node00D5.html#line246): *247
IMAGECLASS       #define "imageclass"  [intuition/classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line42): *43
IMAGE_ATTRIBUTES #define (IA_Dummy) = 0x80020000  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line233): *234
IMAGE_NEGATIVE   #define 0x01 = 0x00000001  [intuition/preferences.h](../Includes_and_Autodocs_2._guide/node00D5.html#line172): *173
IMAGE_POSITIVE   #define 0x00 = 0x00000000  [intuition/preferences.h](../Includes_and_Autodocs_2._guide/node00D5.html#line171): *172
IMPORT           #define extern  [exec/types.h](../Includes_and_Autodocs_2._guide/node0096.html#line20): *21
IM_BGPEN         macro (1 argument)   [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line30): *31
IM_BOX           macro (1 argument)   [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line28): *29
IM_DRAW          #define 0x202L = 0x00000202  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line114): *115
IM_DRAWFRAME     #define 0x206L = 0x00000206  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line119): *120
IM_ERASE         #define 0x204L = 0x00000204  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line116): *117
IM_ERASEFRAME    #define 0x209L = 0x00000209  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line122): *123
IM_FGPEN         macro (1 argument)   [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line29): *30
IM_FRAMEBOX      #define 0x207L = 0x00000207  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line120): *121
IM_HITFRAME      #define 0x208L = 0x00000208  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line121): *122
IM_HITTEST       #define 0x203L = 0x00000203  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line115): *116
IM_ITEM          #define (NM_ITEM | MENU_IMAGE) = 0x00000082
```c
                 [libraries/gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line139): *140
```
IM_MOVE          #define 0x205L = 0x00000205  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line117): *118
IM_SUB           #define (NM_SUB | MENU_IMAGE) = 0x00000083
```c
                 [libraries/gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line140): *141
```
INACTIVEWINDOW   #define IDCMP_INACTIVEWINDOW = 0x00080000
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line132): *133
```
INCLUDE_VERSION  #define 36 = 0x00000024  [exec/types.h](../Includes_and_Autodocs_2._guide/node0096.html#line16): *17
IND_ADDHANDLER   #define (CMD_NONSTD+0) = 0x00000009  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line18): *19
IND_REMHANDLER   #define (CMD_NONSTD+1) = 0x0000000a  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line19): *20
IND_SETMPORT     #define (CMD_NONSTD+5) = 0x0000000e  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line23): *24
IND_SETMTRIG     #define (CMD_NONSTD+7) = 0x00000010  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line25): *26
IND_SETMTYPE     #define (CMD_NONSTD+6) = 0x0000000f  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line24): *25
IND_SETPERIOD    #define (CMD_NONSTD+4) = 0x0000000d  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line22): *23
IND_SETTHRESH    #define (CMD_NONSTD+3) = 0x0000000c  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line21): *22
IND_WRITEEVENT   #define (CMD_NONSTD+2) = 0x0000000b  [devices/input.h](../Includes_and_Autodocs_2._guide/node0049.html#line20): *21
INITBYTE         macro (2 arguments)   [exec/initializers.h](../Includes_and_Autodocs_2._guide/node0084.html#line16): *17
INITLONG         macro (2 arguments)   [exec/initializers.h](../Includes_and_Autodocs_2._guide/node0084.html#line20): *21
INITSTRUCT       macro (4 arguments)   [exec/initializers.h](../Includes_and_Autodocs_2._guide/node0084.html#line24): *25
INITWORD         macro (2 arguments)   [exec/initializers.h](../Includes_and_Autodocs_2._guide/node0084.html#line17): *18
INREQUEST        #define WFLG_INREQUEST = 0x00004000
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line161): *162
```
INST_DATA        macro (2 arguments)   [intuition/classes.h](../Includes_and_Autodocs_2._guide/node00DA.html#line47): *48
INTB_AUD0        #define (7) = 0x00000007  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line24): *25
INTB_AUD1        #define (8) = 0x00000008  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line23): *24
INTB_AUD2        #define (9) = 0x00000009  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line22): *23
INTB_AUD3        #define (10) = 0x0000000a  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line21): *22
INTB_BLIT        #define (6) = 0x00000006  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line25): *26
INTB_COPER       #define (4) = 0x00000004  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line27): *28
INTB_DSKBLK      #define (1) = 0x00000001  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line30): *31
INTB_DSKSYNC     #define (12) = 0x0000000c  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line19): *20
INTB_EXTER       #define (13) = 0x0000000d  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line18): *19
INTB_INTEN       #define (14) = 0x0000000e  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line17): *18
INTB_NMI         #define 15 = 0x0000000f  [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line45): *46
INTB_PORTS       #define (3) = 0x00000003  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line28): *29
INTB_RBF         #define (11) = 0x0000000b  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line20): *21
INTB_SETCLR      #define (15) = 0x0000000f  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line14): *15
INTB_SOFTINT     #define (2) = 0x00000002  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line29): *30
INTB_TBE         #define (0) = 0x00000000  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line31): *32
INTB_VERTB       #define (5) = 0x00000005  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line26): *27
INTEGERIDCMP     #define (IDCMP_GADGETUP) = 0x00000040
```c
                 [libraries/gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line67): *68
```
INTEGER_KIND     #define 3 = 0x00000003  [libraries/gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line36): *37
INTEGER_SCALING  #define 0x0100 = 0x00000100  [intuition/preferences.h](../Includes_and_Autodocs_2._guide/node00D5.html#line252): *253
INTERHEIGHT      #define 4 = 0x00000004  [libraries/gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line87): *88
INTERLACE        #define 4 = 0x00000004  [graphics/display.h](../Includes_and_Autodocs_2._guide/node00B5.html#line23): *24
INTERWIDTH       #define 8 = 0x00000008  [libraries/gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line86): *87
INTF_AUD0        #define (1<<7) = 0x00000080  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line43): *44
INTF_AUD1        #define (1<<8) = 0x00000100  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line42): *43
INTF_AUD2        #define (1<<9) = 0x00000200  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line41): *42
INTF_AUD3        #define (1<<10) = 0x00000400  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line40): *41
INTF_BLIT        #define (1<<6) = 0x00000040  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line44): *45
INTF_COPER       #define (1<<4) = 0x00000010  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line46): *47
INTF_DSKBLK      #define (1<<1) = 0x00000002  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line49): *50
INTF_DSKSYNC     #define (1<<12) = 0x00001000  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line38): *39
INTF_EXTER       #define (1<<13) = 0x00002000  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line37): *38
INTF_INTEN       #define (1<<14) = 0x00004000  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line36): *37
INTF_NMI         #define (1<<15) = 0x00008000  [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line46): *47
INTF_PORTS       #define (1<<3) = 0x00000008  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line47): *48
INTF_RBF         #define (1<<11) = 0x00000800  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line39): *40
INTF_SETCLR      #define (1<<15) = 0x00008000  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line35): *36
INTF_SOFTINT     #define (1<<2) = 0x00000004  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line48): *49
INTF_TBE         #define (1<<0) = 0x00000001  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line50): *51
INTF_VERTB       #define (1<<5) = 0x00000020  [hardware/intbits.h](../Includes_and_Autodocs_2._guide/node00CE.html#line45): *46
INTUITICKS       #define IDCMP_INTUITICKS = 0x00400000
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line135): *136
```
INTUITION_CGHOOKS_H #define 1 = 0x00000001  [intuition/cghooks.h](../Includes_and_Autodocs_2._guide/node00D2.html): *2
INTUITION_CLASSES_H #define 1 = 0x00000001  [intuition/classes.h](../Includes_and_Autodocs_2._guide/node00DA.html): *2
INTUITION_CLASSUSR_H #define 1 = 0x00000001  [intuition/classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html): *2, 1
INTUITION_GADGETCLASS_H #define 1 = 0x00000001  [intuition/gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html): *2
INTUITION_ICCLASS_H #define  [intuition/icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html): *2
INTUITION_IMAGECLASS_H #define TRUE = 0x00000001  [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html): *2
INTUITION_INTUITIONBASE_H #define 1 = 0x00000001
```c
                 [intuition/intuitionbase.h](../Includes_and_Autodocs_2._guide/node00DC.html): *2
```
INTUITION_INTUITION_H #define TRUE = 0x00000001  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html): *2, 1
```c
                 [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html#line37): 38
                 [intuition/cghooks.h](../Includes_and_Autodocs_2._guide/node00D2.html#line18): 19
                 [intuition/gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line18): 19
                 [intuition/intuitionbase.h](../Includes_and_Autodocs_2._guide/node00DC.html#line22): 23
                 [libraries/gadtools.h](../Includes_and_Autodocs_2._guide/node0106.html#line24): 25
                 [workbench/workbench.h](../Includes_and_Autodocs_2._guide/node0135.html#line30): 31
```
INTUITION_IOBSOLETE_H #define  [intuition/iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html): *2, 1
```c
                 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line1356): 1357
                 [intuition/gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line243): 244
                 [intuition/imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line202): 203
```
INTUITION_PREFERENCES_H #define TRUE = 0x00000001
```c
                 [intuition/preferences.h](../Includes_and_Autodocs_2._guide/node00D5.html): *2, 1
```
INTUITION_SCREENS_H #define TRUE = 0x00000001  [intuition/screens.h](../Includes_and_Autodocs_2._guide/node00DD.html): *2, 1
INTUITION_SGHOOKS_H #define TRUE = 0x00000001  [intuition/sghooks.h](../Includes_and_Autodocs_2._guide/node00E5.html): *2
INVALID_ID       #define ~0 = 0xffffffff  [graphics/displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html#line140): *141
INVERSVID        #define 4 = 0x00000004  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html#line96): *97
IOAudio          structure tag size 0x0044 [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line46): *47
IOB_QUICK        #define 0 = 0x00000000  [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line46): *47
IOClipReq        structure tag size 0x0034 [devices/clipboard.h](../Includes_and_Autodocs_2._guide/node0048.html#line42): *43
```c
                 [libraries/iffparse.h](../Includes_and_Autodocs_2._guide/node010B.html#line116): 117
```
IODRPReq         structure tag size 0x003e [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line155): *156
IOERR_ABORTED    #define (-2) = 0xfffffffe  [exec/errors.h](../Includes_and_Autodocs_2._guide/node008F.html#line15): *16
IOERR_BADADDRESS #define (-5) = 0xfffffffb  [exec/errors.h](../Includes_and_Autodocs_2._guide/node008F.html#line18): *19
IOERR_BADLENGTH  #define (-4) = 0xfffffffc  [exec/errors.h](../Includes_and_Autodocs_2._guide/node008F.html#line17): *18
IOERR_NOCMD      #define (-3) = 0xfffffffd  [exec/errors.h](../Includes_and_Autodocs_2._guide/node008F.html#line16): *17
IOERR_OPENFAIL   #define (-1) = 0xffffffff  [exec/errors.h](../Includes_and_Autodocs_2._guide/node008F.html#line14): *15
IOERR_SELFTEST   #define (-7) = 0xfffffff9  [exec/errors.h](../Includes_and_Autodocs_2._guide/node008F.html#line20): *21
IOERR_UNITBUSY   #define (-6) = 0xfffffffa  [exec/errors.h](../Includes_and_Autodocs_2._guide/node008F.html#line19): *20
IOExtPar         structure tag size 0x003e [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line28): *29
```c
                 [devices/prtbase.h](../Includes_and_Autodocs_2._guide/node005A.html#line75): 76, 84
```
IOExtSer         structure tag size 0x0052 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line37): *38
```c
                 [devices/prtbase.h](../Includes_and_Autodocs_2._guide/node005A.html#line76): 77, 85
```
IOExtTD          structure tag size 0x0038 [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line118): *119
IOF_QUICK        #define (1<<0) = 0x00000001  [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line47): *48
IOPARB_ABORT     #define 5 = 0x00000005  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line74): *75
IOPARB_ACTIVE    #define 4 = 0x00000004  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line76): *77
IOPARB_QUEUED    #define 6 = 0x00000006  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line72): *73
IOPARF_ABORT     #define (1<<5) = 0x00000020  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line75): *76
IOPARF_ACTIVE    #define (1<<4) = 0x00000010  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line77): *78
IOPARF_QUEUED    #define (1<<6) = 0x00000040  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line73): *74
IOPArray         structure tag size 0x0008 [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line18): *19, 55
IOPTB_PAPEROUT   #define 1 = 0x00000001  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line84): *85
IOPTB_PARBUSY    #define 0 = 0x00000000  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line86): *87
IOPTB_PARSEL     #define 2 = 0x00000002  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line80): *81
IOPTB_RWDIR      #define 3 = 0x00000003  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line78): *79
IOPTF_PAPEROUT   #define (1<<1) = 0x00000002  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line85): *86
IOPTF_PARBUSY    #define (1<<0) = 0x00000001  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line87): *88
IOPTF_PARSEL     #define (1<<2) = 0x00000004  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line83): *84
IOPTF_RWDIR      #define (1<<3) = 0x00000008  [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line79): *80
IOPar            struct IOStdReq(size 0x0030 bytes) in struct IOExtPar
```c
         +0x0000 [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line29): *30
```
IOPrtCmdReq      structure tag size 0x0026 [devices/printer.h](../Includes_and_Autodocs_2._guide/node0052.html#line141): *142
IORequest        structure tag size 0x0020 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line19): *20
```c
                 [devices/audio.h](../Includes_and_Autodocs_2._guide/node0038.html#line47): 48
                 [devices/timer.h](../Includes_and_Autodocs_2._guide/node0053.html#line37): 38
```
IOSer            struct IOStdReq(size 0x0030 bytes) in struct IOExtSer
```c
         +0x0000 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line38): *39
```
IOStdReq         structure tag size 0x0030 [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html#line28): *29
```c
                 [devices/narrator.h](../Includes_and_Autodocs_2._guide/node0042.html#line93): 94
                 [devices/parallel.h](../Includes_and_Autodocs_2._guide/node004A.html#line29): 30
                 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line38): 39
                 [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line119): 120
```
IOTArray         structure tag size 0x0008 [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line21): *22, 67
IOTDB_INDEXSYNC  #define 4 = 0x00000004  [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line172): *173
IOTDB_WORDSYNC   #define 5 = 0x00000005  [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line178): *179
IOTDF_INDEXSYNC  #define (1<<4) = 0x00000010  [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line173): *174
IOTDF_WORDSYNC   #define (1<<5) = 0x00000020  [devices/trackdisk.h](../Includes_and_Autodocs_2._guide/node005B.html#line179): *180
IO_STATB_OVERRUN #define 8 = 0x00000008  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line125): *126
IO_STATB_READBREAK #define 10 = 0x0000000a  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line121): *122
IO_STATB_WROTEBREAK #define 9 = 0x00000009  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line123): *124
IO_STATB_XOFFREAD #define 12 = 0x0000000c  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line117): *118
IO_STATB_XOFFWRITE #define 11 = 0x0000000b  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line119): *120
IO_STATF_OVERRUN #define (1<<8) = 0x00000100  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line126): *127
IO_STATF_READBREAK #define (1<<10) = 0x00000400  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line122): *123
IO_STATF_WROTEBREAK #define (1<<9) = 0x00000200  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line124): *125
IO_STATF_XOFFREAD #define (1<<12) = 0x00001000  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line118): *119
IO_STATF_XOFFWRITE #define (1<<11) = 0x00000800  [devices/serial.h](../Includes_and_Autodocs_2._guide/node004B.html#line120): *121
ISDRAWN          #define 0x1000 = 0x00001000  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line134): *135
ISGRTRX          #define 4 = 0x00000004  [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html#line84): *85
ISGRTRY          #define 8 = 0x00000008  [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html#line85): *86
ISLESSX          #define 1 = 0x00000001  [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html#line82): *83
ISLESSY          #define 2 = 0x00000002  [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html#line83): *84
ITEMENABLED      #define 0x0010 = 0x00000010  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line121): *122
ITEMNUM          macro (1 argument)   [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line1266): *1267
ITEMTEXT         #define 0x0002 = 0x00000002  [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line118): *119
ITEM_EQUAL       #define -2 = 0xfffffffe  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line229): *230
ITEM_ERROR       #define -1 = 0xffffffff  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line230): *231
ITEM_NOTHING     #define 0 = 0x00000000  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line231): *232
ITEM_QUOTED      #define 2 = 0x00000002  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line233): *234
ITEM_UNQUOTED    #define 1 = 0x00000001  [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line232): *233
IText            pointer to unsigned char in struct IntuiText
```c
         +0x000c [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line576): *577
```
ITextFont        pointer to struct TextAttr in struct IntuiText
```c
         +0x0008 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line575): *576
```
IVALUE           macro (1 argument)   [rexx/storage.h](../Includes_and_Autodocs_2._guide/node0127.html#line50): *51
IX               "LONG"  [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line191): *192
IXSYM_ALT        #define 4 = 0x00000004  [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line196): *197
IXSYM_ALTMASK    #define (IEQUALIFIER_LALT | IEQUALIFIER_RALT) = 0x00000030
```c
                 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html): *202
```
IXSYM_CAPS       #define 2 = 0x00000002  [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line195): *196
IXSYM_CAPSMASK   #define (IXSYM_SHIFTMASK | IEQUALIFIER_CAPSLOCK) = 0x00000007
```c
                 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line200): *201
```
IXSYM_SHIFT      #define 1 = 0x00000001  [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line194): *195
IXSYM_SHIFTMASK  #define (IEQUALIFIER_LSHIFT | IEQUALIFIER_RSHIFT) = 0x00000003
```c
                 [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line199): *200
```
IX_NORMALQUALS   #define 0x7FFF;  [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html): *204
IX_VERSION       #define 2 = 0x00000002  [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line170): *171
IdleCount        unsigned long int in struct ExecBase
```c
         +0x0118 [exec/execbase.h](../Includes_and_Autodocs_2._guide/node009E.html#line64): *65
```
Image            structure tag
```c
     size 0x0014 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line173): *174, 619, 666, 865, 996,
                             1054
```
ImageBMap        pointer to struct BitMap in struct Requester
```c
         +0x0044 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line170): *171
```
ImageData        pointer to unsigned short int in struct Image
```c
         +0x000a [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line625): *626
```
ImageData        pointer to short int in struct VSprite
```c
         +0x0024 [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html#line104): *105
```
ImageShadow      pointer to short int in struct Bob
```c
         +0x0006 [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html#line147): *148
```
InfoData         structure tag size 0x0024 [dos/dos.h](../Includes_and_Autodocs_2._guide/node0068.html#line118): *119
InitAnimate      macro (1 argument)   [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html#line245): *246
InitialModes     unsigned long int in struct StringExtend
```c
         +0x0008 [intuition/sghooks.h](../Includes_and_Autodocs_2._guide/node00E5.html#line25): *26
```
InputEvent       structure tag size 0x0016 [devices/inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html#line198): *199, 200
```c
                 [intuition/gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line203): 204
                 [intuition/sghooks.h](../Includes_and_Autodocs_2._guide/node00E5.html#line41): 42
```
InputXpression   structure tag size 0x000c [libraries/commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line172): *173, 192
IntVector        structure tag size 0x000c [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line30): *31
```c
                 [exec/execbase.h](../Includes_and_Autodocs_2._guide/node009E.html#line58): 59
```
IntVects         array [16] of struct IntVector(size 0x000c bytes) in struct
```c
                 ExecBase
         +0x0054 [exec/execbase.h](../Includes_and_Autodocs_2._guide/node009E.html#line58): *59
```
Interrupt        structure tag size 0x0016 [exec/interrupts.h](../Includes_and_Autodocs_2._guide/node008C.html#line23): *24
```c
                 [graphics/gfxbase.h](../Includes_and_Autodocs_2._guide/node00AE.html#line35): 36
                 [resources/disk.h](../Includes_and_Autodocs_2._guide/node0119.html#line44): 45, 46, 47, 59, 60, 61
```
IntrList         struct List(size 0x000e bytes) in struct ExecBase
```c
         +0x016c [exec/execbase.h](../Includes_and_Autodocs_2._guide/node009E.html#line88): *89
```
IntuiMessage     structure tag
```c
     size 0x0034 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line676): *677, 716, 857
```
IntuiText        structure tag
```c
     size 0x0014 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line154): *155, 240, 570, 578
```
IntuitionBase    structure tag size 0x0050 [intuition/intuitionbase.h](../Includes_and_Autodocs_2._guide/node00DC.html#line67): *68
IoBuff           structure tag size 0x0100 [rexx/rexxio.h](../Includes_and_Autodocs_2._guide/node0125.html#line24): *25
Iptr             pointer to struct Isrvstr in struct Isrvstr
```c
         +0x000e [graphics/graphint.h](../Includes_and_Autodocs_2._guide/node00C1.html#line22): *23
```
IsListEmpty      macro (1 argument)   [exec/lists.h](../Includes_and_Autodocs_2._guide/node007D.html#line52): *53
IsMsgPortEmpty   macro (1 argument)   [exec/lists.h](../Includes_and_Autodocs_2._guide/node007D.html#line55): *56
Isrvstr          structure tag size 0x001e [graphics/graphint.h](../Includes_and_Autodocs_2._guide/node00C1.html#line19): *20, 23
ItemFill         pointer to void in struct MenuItem

```c
         +0x0012 [intuition/intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line98): *99
```
