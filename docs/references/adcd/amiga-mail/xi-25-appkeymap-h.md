---
title: XI-25/AppKeyMap.h
manual: amiga-mail
chapter: amiga-mail
section: xi-25-appkeymap-h
functions: []
libraries: []
---

# XI-25/AppKeyMap.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#define UP_KEY      0x4C   /* Raw keys which are the same on all keyboards */
#define DOWN_KEY    0x4D
#define RIGHT_KEY   0x4E
#define LEFT_KEY    0x4F

#define F1_KEY      0x50
#define F2_KEY      0x51
#define F3_KEY      0x52
#define F4_KEY      0x53
#define F5_KEY      0x54
#define F6_KEY      0x55
#define F7_KEY      0x56
#define F8_KEY      0x57
#define F9_KEY      0x58
#define F10_KEY     0x59

#define N0_KEY      0x0F
#define N1_KEY      0x1D
#define N2_KEY      0x1E
#define N3_KEY      0x1F
#define N4_KEY      0x2D
#define N5_KEY      0x2E
#define N6_KEY      0x2F
#define N7_KEY      0x3D
#define N8_KEY      0x3E
#define N9_KEY      0x3F

#define NPERIOD_KEY 0x3C
#define NOPAREN_KEY 0x5A
#define NCPAREN_KEY 0x5B
#define NSLASH_KEY  0x5C
#define NASTER_KEY  0x5D
#define NMINUS_KEY  0x4A
#define NPLUS_KEY   0x5E
#define NENTER_KEY  0x43

/* Sizes of the "Lo" and "Hi" KeyMap tables */

#define LO_MAP_SIZE  64   /* Notice that the Lo and Hi tables are NOT the same */
#define HI_MAP_SIZE  56   /* size!  The Lo tables have eight more entries than */
#define LO_TYPE_SIZE 64   /* the Hi tables.  The RKM is incorrect in saying    */
#define HI_TYPE_SIZE 56   /* that the Lo and Hi tables are the same size.      */
#define LO_CAPS_SIZE 8		/* 8 bytes x 8 bits-per-byte = */
#define HI_CAPS_SIZE 7		/* 7 bytes x 8 bits-per-byte = */
#define LO_REPS_SIZE 8		/* 64 bit-wide entries.        */
#define HI_REPS_SIZE 7		/* 56 bit-wide entries.        */

void AlterAppKeyMap (struct KeyMap *,
		     struct MyKey *,
		     UWORD);
struct KeyMap *CreateAppKeyMap (struct KeyMap *);
void DeleteAppKeyMap (struct KeyMap *);
UBYTE FindMaxDeadKey(struct KeyMap *);

struct MyKey /* AlterAppKeyMap() expects an array of MyKey structures. */
             /* This structure contains all the information needed to  */
             /* redefine a key mapping.                                */
{
  UBYTE RawCode;
  UBYTE MapType;    /* Qualifier flags and key type. */
  UBYTE Capsable;   /* Is this key Capsable?         */
  UBYTE Repeatable; /* Is this key Repeatable?       */
  ULONG Map;        /* This field either points to some key data or */
};                  /* contains a four-byte table of ANSI values.   */

struct KeyMapArrays  /* We allocate each Lo and Hi table pair as a single array */
{
  ULONG LHKeyMap[LO_MAP_SIZE << 1];
  UBYTE LHKeyMapTypes[LO_TYPE_SIZE << 1];
  UBYTE LHCapsable[LO_CAPS_SIZE << 1];
  UBYTE LHRepeatable[LO_REPS_SIZE << 1];
};

