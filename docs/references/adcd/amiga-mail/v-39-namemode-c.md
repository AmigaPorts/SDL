---
title: V-39/NameMode.c
manual: amiga-mail
chapter: amiga-mail
section: v-39-namemode-c
functions: []
libraries: []
---

# V-39/NameMode.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include <exec/types.h>
#include <graphics/displayinfo.h>
#include <stdio.h>
#include <string.h>

#include <clib/graphics_protos.h>
#include <clib/utility_protos.h>

/*****************************************************************************/

#define MONITOR_PART(id) ((id) & MONITOR_ID_MASK)

/*****************************************************************************/

BOOL NameMode (ULONG modeID, STRPTR result)
{
  struct NameInfo nameInfo;
  struct DisplayInfo dispInfo;
  struct DimensionInfo dimInfo;
  struct MonitorInfo monInfo;
  char buffer[DISPLAYNAMELEN + 1];
  UWORD len;
  DisplayInfoHandle dh;

  result[0] = 0;

  dh = FindDisplayInfo (modeID);
  if (GetDisplayInfoData (dh, (APTR) & dispInfo, sizeof (struct DisplayInfo),
```c
                          DTAG_DISP, INVALID_ID), INVALID_ID)
```
  {
```c
    if (!dispInfo.NotAvailable)
    {
      if (GetDisplayInfoData (dh, (APTR) & dimInfo, sizeof (struct DimensionInfo),
                              DTAG_DIMS, INVALID_ID))
      {
```
	/* Get name or make one if no name available */
	if (GetDisplayInfoData (dh, (APTR) & nameInfo, sizeof (struct NameInfo),
	                        DTAG_NAME, INVALID_ID))
	{
	  strcpy (result, nameInfo.Name);
	  return (TRUE);
	}
	else
	{
	  if (GetDisplayInfoData (dh, (APTR) & monInfo, sizeof (struct MonitorInfo),
	                          DTAG_MNTR, INVALID_ID))
	  {
	    if ((monInfo.Mspc) && (monInfo.Mspc->ms_Node.xln_Name))
	    {
	      strcpy (buffer, monInfo.Mspc->ms_Node.xln_Name);
	      len = strlen (buffer);
	      if ((len > 8) && (Strnicmp (&buffer[len - 8], ".monitor", len - 8)
	                                                                     == 0))
	      {
		buffer[len - 8] = 0;
		len -= 8;
	      }

	      while (len > 0)
		buffer[--len] = ToUpper (buffer[len]);
	    }
	  }

	  sprintf (result, "%s:%lu x %lu %s%s%s",
		   buffer,
		   (dimInfo.Nominal.MaxX - dimInfo.Nominal.MinX + 1),
		   (dimInfo.Nominal.MaxY - dimInfo.Nominal.MinY + 1),
		   (dispInfo.PropertyFlags & DIPF_IS_HAM) ? "HAM " :
		   (dispInfo.PropertyFlags & DIPF_IS_EXTRAHALFBRITE) ? "EHB " : "",
		   (dispInfo.PropertyFlags & DIPF_IS_PF2PRI) ? "DPF2 " :
		   (dispInfo.PropertyFlags & DIPF_IS_DUALPF) ? "DPF " : "",
		   (dispInfo.PropertyFlags & DIPF_IS_LACE) ? "Laced " : "", "");

	  return (TRUE);
	}
```c
      }
    }
```
  }

  return (FALSE);
}

/*****************************************************************************/

void main (void)
{
  ULONG modeID;
  char name[64];

  modeID = INVALID_ID;
  while ((modeID = NextDisplayInfo (modeID)) != INVALID_ID)
  {
```c
    if (MONITOR_PART (modeID))	/* ignore "default" monitor */
    {
      if (NameMode (modeID, name))
      {
```
	printf ("%s\n", name);
```c
      }
    }
```
  }
}

