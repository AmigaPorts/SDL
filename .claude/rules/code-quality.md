Paths: src/**/*.c, src/**/*.h, examples/**/*.c, ports/**/*.c

# Code Quality Rules -- AI-Native Engineering

Adapted from NASA/JPL's "Power of 10" for AI-assisted Amiga development.
These rules exist because AI agents make specific categories of mistakes.

## 1. No Function Over 60 Lines

If a function exceeds 60 lines, split it. Long functions hide bugs and
make it impossible to reason about behavior. AI agents lose track of
state in long functions and introduce subtle errors.

## 2. No Dead Code

No commented-out code blocks. No #if 0 sections left from debugging.
No unused variables or functions. Dead code misleads the next agent
(or human) reading the file. Delete it; git has history.

## 3. Every Resource Has One Owner

malloc -> free. OpenLibrary -> CloseLibrary. OpenScreen -> CloseScreen.
The open and close must be in the same function or the same struct's
lifecycle. If you can't point to the free, there's a leak. AmigaOS
has no memory protection -- leaked resources persist until reboot.

## 4. No Logging in Hot Paths

SDL_Log writes to disk on AmigaOS. A single SDL_Log in a per-frame
function (PumpEvents, UpdateFramebuffer, RenderFillRect) costs 3+ ms.
At 30fps that's 100ms/frame just in logging -- instant slideshow.

Rule: After a feature works, grep for SDL_Log/DLOG in the call path
from SDL_RenderPresent back to the game loop. Remove them all.

## 5. Verify Before Claiming

Never say "this should work" or "this will fix it" without evidence.
Add a one-time SDL_Log with the actual values, run it, read the log.
The log is truth. Your mental model is a hypothesis.

This applies to: window sizes, pixel formats, function return values,
struct field contents, screen resolutions.

## 6. One Change Per Test Cycle

Change one thing. Build. Test. Read the log. Then change the next thing.
AI agents batch multiple changes and can't tell which one helped or hurt.
If a fix requires three changes, make three commits.

## 7. No Magic Numbers in API Calls

Every constant passed to an AmigaOS function must be a named constant
from the SDK headers. No bare integers. `MEMF_CHIP | MEMF_CLEAR` not `0x10002`.
`SA_Depth` not `0x80000022`. The named constants are self-documenting
and catch copy-paste errors.

## 8. Stack Budget: 512 Bytes Per Function

AmigaOS default stack is 4KB. SDL2 programs set their own __stack but
library functions shouldn't assume it's large. No local arrays > 512 bytes.
Use static, heap, or SDL_small_alloc for larger buffers.

## 9. Check Every Return Value at System Boundaries

OpenLibrary, OpenScreen, OpenWindow, AllocMem, CreateMsgPort -- all can
return NULL. Check and handle it. Internal SDL2 calls between trusted
functions don't need checks for impossible cases, but every AmigaOS
API call is a system boundary.

## 10. Measure, Don't Model

"640x480 should be fast enough" is a model. "frame delta=3232ms" is a
measurement. When performance matters, add timing (SDL_GetTicks before
and after), run it, read the numbers. Remove the timing after.

AI agents are especially bad at performance intuition because they
have no concept of wall-clock time on target hardware.
