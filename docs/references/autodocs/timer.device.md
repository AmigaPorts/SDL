# timer.device — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 10

## Function Index

- **--background--** — 
- **AbortIO** — Remove an existing timer request.
- **AddTime** — Add one time request to another.
- **CmpTime** — Compare two TimeVal structures.
- **GetSysTime** (V36) — Get the system time.
- **ReadEClock** (V36) — Get the current value of the E-Clock.
- **SubTime** — Subtract one time request from another.
- **TR_ADDREQUEST** — Submit a request to wait a period of time.
- **TR_GETSYSTIME** — get the system time.
- **TR_SETSYSTIME** — Set the system time.

## Functions

### timer.device/--background--

**Bugs:**
In the V1.2/V1.3 release, the timer device has problems with
very short time requests.  When one of these is made, other
timer requests may be finished inaccurately.  A side effect
is that AmigaDOS requests such as "Delay(0);" or
"WaitForChar(x,0);" are unreliable.

---

### timer.device/AbortIO

**Remove an existing timer request.**

**Synopsis:**
```c
error = AbortIO( TimeRequest )

LONG AbortIO( struct TimeRequest * );
```

**Description:**
This is an exec.library call.

This routine removes a TimeRequest from the timer.  It runs in
the context of the caller.

**Inputs:**
TimeRequest - the timer request to be aborted

**Result:**
0  If the request was aborted, io_Error will also be set to
    IOERR_ABORTED.
-1  Otherwise

**Notes:**
This function may be called from interrupts.

**See also:** exec.library/AbortIO()

---

### timer.device/AddTime

**Add one time request to another.**

**Synopsis:**
```c
AddTime( Dest, Source )

void AddTime( struct TimeVal *, struct TimeVal *);
```

**Description:**
This routine adds one TimeVal structure to another.  The
results are stored in the destination (Dest + Source -> Dest).

The emulated A0 and A1 registers of 68k software will be left
unchanged for backwards compatibility.

**Inputs:**
Dest, Source -- pointers to TimeVal structures.

**Notes:**
This function may be called from interrupts.

Both TimeVal parameters must be normalized or the result will
incorrect.

**See also:** timer.device/CmpTime(),
timer.device/SubTime()

---

### timer.device/CmpTime

**Compare two TimeVal structures.**

**Synopsis:**
```c
result = CmpTime( Dest, Source )

LONG CmpTime( struct TimeVal *, struct TimeVal *);
```

**Description:**
This routine compares TimeVal structures.

The emulated A0 and A1 registers of 68k software will be left
unchanged for backwards compatibility.

**Inputs:**
Dest, Source -- pointers to TimeVal structures.

**Result:**
Result will be   0 if Dest has same time as source (dest == source)
         -1 if Dest has more time than source (dest > source)
         +1 if Dest has less time than source (dest < source)

**Notes:**
This function may be called from interrupts.

**Bugs:**
Older version of this document had the sense of the return
codes wrong; the code hasn't changed but the document has.

**See also:** timer.device/AddTime(),
timer.device/SubTime()

---

### timer.device/GetSysTime (V36)

**Get the system time.**

**Synopsis:**
```c
GetSysTime( Dest )

void GetSysTime( struct TimeVal * );
```

**Description:**
Ask the system what time it is.  The system time starts off at
zero at power on, but may be initialized via the TR_SETSYSTIME
timer.device command.

System time is monotonocally increasing and guarenteed to be
unique (except when the system time is set back).

The emulated A0 register of 68k software will be left
unchanged for backwards compatibility.

This function is less expensive to use than the TR_GETSYSTIME
IORequest.

**Inputs:**
Dest -- pointer to a TimeVal structure to hold the system time.

**Result:**
Dest -- the TimeVal structure will contain the system time.

**Notes:**
This function may be called from interrupts.

**See also:** timer.device/TR_GETSYSTIME,
timer.device/TR_SETSYSTIME

---

### timer.device/ReadEClock (V36)

**Get the current value of the E-Clock.**

**Synopsis:**
```c
E_Freq = ReadEClock( Dest )

ULONG ReadEClock ( struct EClockVal * );
```

**Description:**
This routine calculates the current 64 bit value of the E-Clock
and stores it in the destination EClockVal structure. The count
rate of the E-Clock is also returned.

The emulated A0 register of 68k software will be left
unchanged for backwards compatibility.

This is a low overhead function designed so that very short
intervals may be timed.

**Inputs:**
Dest -- pointer to an EClockVal structure.

**Result:**
Dest -- the EClockVal structure will contain the E-Clock time
E_Freq -- The count rate of the E-Clock (tics/sec).

**Notes:**
This function may be called from interrupts.

---

### timer.device/SubTime

**Subtract one time request from another.**

**Synopsis:**
```c
SubTime( Dest, Source )

void SubTime( struct TimeVal *, struct TimeVal *);
```

**Description:**
This routine subtracts one TimeVal structure from another.  The
results are stored in the destination (Dest - Source -> Dest).

The emulated A0 and A1 registers of 68k software will be left
unchanged for backwards compatibility.

**Inputs:**
Dest, Source -- pointers to TimeVal structures.

**Notes:**
This function may be called from interrupts.

Both TimeVal parameters must be normalized or the result will
incorrect.

**See also:** timer.device/AddTime(),
timer.device/CmpTime()

---

### timer.device/TR_ADDREQUEST

**Submit a request to wait a period of time.**

**Description:**
Ask the timer to wait a specified amount of time before
replying the TimeRequest.

The message may be forced to finish early with an
AbortIO()/WaitIO() pair.

   TIMER REQUEST
io_Message      mn_ReplyPort initialized
io_Device       preset by timer in OpenDevice
io_Unit         preset by timer in OpenDevice
io_Command      TR_ADDREQUEST
io_Flags        IOF_QUICK permitted (but ignored)
Time            a TimeVal structure specifying how long the
         device will wait before replying

**Result:**
Time            will be zeroed

**Notes:**
This function may be called from interrupts.

Previous to 2.0, the tr_time field was documented as containing
junk when the TimeRequest was returned.

**See also:** timer.device/AbortIO()

---

### timer.device/TR_GETSYSTIME

**get the system time.**

**Description:**
Ask the system what time it is.  The system time starts off at
zero at power on, but may be initialized via the TR_SETSYSTIME
call.

System time is monotonically increasing, and guaranteed to be
unique (except when the system time is set backwards).

   TIMER REQUEST
io_Message      mn_ReplyPort initialized
io_Device       preset by timer in OpenDevice
io_Unit         preset by timer in OpenDevice
io_Command      TR_GETSYSTIME
io_Flags        IOF_QUICK permitted

**Result:**
Time            a TimeVal structure with the current system time

**Notes:**
This function may be called from interrupts.

**See also:** timer.device/TR_SETSYSTIME,
timer.device/GetSysTime()

---

### timer.device/TR_SETSYSTIME

**Set the system time.**

**Description:**
Set the system idea of what time it is.  The system starts out
at time "zero" so it is safe to set it forward to the real
time.  However, care should be taken when setting the time
backwards.  System time is generally expected to monotonically
increasing.

   TIMER REQUEST
io_Message      mn_ReplyPort initialized
io_Device       preset by timer in OpenDevice
io_Unit         preset by timer in OpenDevice
io_Command      TR_GETSYSTIME
io_Flags        IOF_QUICK permitted
Time            a TimeVal structure with the current system time

**Result:**
Time            will contain junk

**Notes:**
This function may be called from interrupts.

**See also:** timer.device/TR_GETSYSTIME,
timer.device/GetSysTime()

---
