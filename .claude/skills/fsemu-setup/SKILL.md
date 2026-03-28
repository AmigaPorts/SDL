---
name: fsemu-setup
description: FS-UAE + Picasso96 RTG setup troubleshooting for SDL2 testing
user_invocable: true
---

# FS-UAE Setup for SDL2 RTG Testing

Quick reference for configuring FS-UAE with P96/CyberGraphX RTG support.

## Instructions

### Working Configuration

```
amiga_model = A4000/040
kickstart_file = $BASE/Kickstarts/kick3.1-a4000.rom
graphics_card = uaegfx
graphics_memory = 32768
chip_memory = 8192
zorro_iii_memory = 131072
joystick_port_1_mode = nothing
```

Config file: `toolchain/configs/sdl2-test.fs-uae`

### Required P96 Files on System Volume

```
Libs/Picasso96API.library          -- CyberGraphX-compatible API
Libs/Picasso96/rtg.library         -- P96 core
Libs/Picasso96/uaegfx.card         -- FS-UAE virtual card driver
Libs/Picasso96/emulation.library   -- chipset emulation layer
Libs/Picasso96/fastlayers.library  -- optimized layers
Devs/Monitors/uaegfx              -- monitor driver (NAME MUST MATCH BOARD)
Devs/Monitors/uaegfx.info         -- monitor driver icon
Devs/Picasso96Settings             -- board config (BDNM=uaegfx, STHD=uaegfx)
```

Source: P96 v2.0 from Aminet (aminet.net/driver/video/Picasso96).
Do NOT use P96 v1.33 -- incompatible with FS-UAE, causes Guru 8100 0008.

### Critical Rules

1. **Monitor driver name = board name**: `Devs:Monitors/uaegfx`, not `Picasso96`.
   iComp wiki: "only the name matters, the loader is identical for all P96 drivers"

2. **A4000/040 model**: Zorro III bus supports >8MB fast RAM and >8MB RTG.
   A1200 has Zorro II with 8MB total shared between fast RAM and RTG.

3. **Never pkill -f fs-uae**: Kills all sessions. Use PID-specific kill.

4. **WritePixelArray is a no-op on AGA bitmaps**: Check `GetCyberMapAttr(bm, CYBRMATTR_ISCYBERGFX)` before blitting.

### Common Failures

| Symptom | Cause | Fix |
|---------|-------|-----|
| "no RTG mode found" | P96 monitor driver not matching board | Rename to `Devs:Monitors/uaegfx` |
| "Too large Z2 RTG memory" | A1200 Z2 bus limit | Use A4000/040 |
| "error opening PicassoIV.resource" | Wrong board files installed | Remove PicassoIV.*, keep only uaegfx.* |
| Grey window, IsCyberGfx=0 | WB screen is AGA, not RTG | Open custom RTG screen or check P96 boot |
| Guru 8100 0008 | P96 v1.33 + FS-UAE incompatibility | Use P96 v2.0 from Aminet |
| FS-UAE dark grey screen | Wrong kickstart for model | A4000 needs kick3.1-a4000.rom |

### Launch

```bash
scripts/test-video.sh           # Build + launch
scripts/test-video.sh --no-build # Launch only
```

Or directly:
```bash
/opt/homebrew/bin/fs-uae toolchain/configs/sdl2-test.fs-uae
```
