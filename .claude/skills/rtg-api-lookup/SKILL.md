---
name: rtg-api-lookup
description: Look up CyberGraphX or Picasso96 RTG API documentation
user_invocable: true
---

# RTG API Lookup

Load the RTG (Retargetable Graphics) API reference documentation for CyberGraphX V4.

## What This Does

Reads and presents the relevant section of `docs/references/cybergraphx-reference.md` for the
requested function or concept. Use this before writing any code that calls CyberGraphX or
Picasso96 functions.

## Instructions

When invoked, read `docs/references/cybergraphx-reference.md` and find the section relevant
to the user's query. If no specific query, present a summary of available functions grouped
by category:

- Screen mode enumeration (IsCyberModeID, GetCyberIDAttr, BestCModeIDTags)
- Pixel operations (WritePixelArray, ReadPixelArray, MovePixelArray)
- Bitmap locking (LockBitMapTags, UnLockBitMap)
- Bitmap info (GetCyberMapAttr)
- Allocation (AllocCModeListTags, FreeCModeList)

Cross-reference with `docs/references/crash-patterns.md` for alignment (#15) and
struct return (#16) issues that affect graphics code.
