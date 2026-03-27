# D / Errors / Memory Loss--CLI Only


Make sure you are testing in a standard environment.  Some third-party
shells dynamically allocate history buffers, or cause other memory
fluctuations.  Also, if your program executes different code when started
from CLI, check that code and its cleanup.  And check your startup.asm if
you wrote your own.

