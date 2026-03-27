---
title: 25 / / The Signal Semaphore / Releasing a SignalSemaphore
manual: libraries
chapter: libraries
section: 25-the-signal-semaphore-releasing-a-signalsemaphore
functions: [AttemptSemaphore, ObtainSemaphore, ObtainSemaphoreShared, ReleaseSemaphore]
libraries: [exec.library]
---

# 25 / / The Signal Semaphore / Releasing a SignalSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once you have obtained the semaphore and completed any operations on the
semaphore protected object, you should release the semaphore.  The
[ReleaseSemaphore()](autodocs-2.0/exec-library-releasesemaphore.md) function does this.  For each successful
[ObtainSemaphore()](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md), [ObtainSemaphoreShared()](libraries/25-the-signal-semaphore-obtaining-a-shared-signalsemaphore.md) and [AttemptSemaphore()](libraries/25-the-signal-semaphore-checking-a-signalsemaphore.md) call you
make, you must have a matching ReleaseSemaphore() call.

---

## See Also

- [AttemptSemaphore — exec.library](../autodocs/exec.library.md#attemptsemaphore)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [ObtainSemaphoreShared — exec.library](../autodocs/exec.library.md#obtainsemaphoreshared)
- [ReleaseSemaphore — exec.library](../autodocs/exec.library.md#releasesemaphore)
