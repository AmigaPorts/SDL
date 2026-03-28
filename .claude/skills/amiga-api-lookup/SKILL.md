---
name: amiga-api-lookup
description: Look up AmigaOS API documentation from ADCD reference before writing OS API code
user_invocable: true
---

# Amiga API Lookup

Load ADCD (Amiga Developer CD) reference documentation for AmigaOS system calls.

This skill is MANDATORY before writing any code that includes `<proto/*.h>`,
`<devices/*.h>`, `<exec/*.h>`, or references AmigaOS structs. The enforce-adcd-lookup
hook reminds you to invoke this skill.

## Instructions

When invoked with a function name, struct name, or library name:

1. Search `docs/references/adcd/FUNCTIONS.md` for the function name to find which
   ADCD pages reference it
2. Read the most relevant page(s) from `docs/references/adcd/` (autodocs, libraries,
   devices, or hardware subdirectories)
3. Present the function signature, parameters, return value, and usage notes
4. Cross-reference with `docs/references/adcd/TYPES.md` for struct definitions
5. Check `docs/references/crash-patterns.md` for known issues with this API

When invoked without arguments, remind the user of the available ADCD sections:

| Directory | Content |
|-----------|---------|
| `adcd/autodocs-3.5/` | OS 3.5 autodocs (function-level reference) |
| `adcd/autodocs-2.0/` | OS 2.0 autodocs |
| `adcd/libraries/` | Library programming guides (exec, dos, intuition, graphics) |
| `adcd/devices/` | Device programming guides (timer, audio, serial, gameport) |
| `adcd/hardware/` | Hardware reference (custom chips, memory map, DMA) |
| `adcd/FUNCTIONS.md` | Cross-reference: function name -> all pages mentioning it |
| `adcd/TYPES.md` | Struct and type definitions |
| `adcd/INCLUDES.json` | Header file index |

For APIs NOT in the ADCD (third-party):
- CyberGraphX: use `/rtg-api-lookup` or read `docs/references/cybergraphx-reference.md`
- AHI audio: read `docs/references/ahi-reference.md`

## Example Usage

```
/amiga-api-lookup OpenWindowTags
/amiga-api-lookup SignalSemaphore
/amiga-api-lookup timer.device
/amiga-api-lookup WritePixelArray   (-> redirects to /rtg-api-lookup)
```
