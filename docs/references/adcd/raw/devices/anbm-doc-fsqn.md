# ANBM.doc / FSQN


Chunk Description:

The FSQN chunk specifies the frame playback sequence

Chunk Spec:


#define FSQN    MakeID('F','S','Q','N')

/* Flags */
#define FSQN_CYCLE  0x0001 /* Ignore sequence, cycle a,b,..y,z,a,b,.. */
#define FSQN_TOFRO  0x0002 /* Ignore sequence, cycle a,b,..y,z,y,..a,b, */
/* Disk record */
typedef struct {

```c
    WORD numframes;      /* Number of frames in the sequence */
    LONG dt;             /* Nominal time between frames in jiffies */
    WORDBITS flags;      /* Bits modify behavior of the animation */
    UBYTE sequence[80];  /* string of 'a'..'z' specifying sequence */
    } FrameSeqn;
```
