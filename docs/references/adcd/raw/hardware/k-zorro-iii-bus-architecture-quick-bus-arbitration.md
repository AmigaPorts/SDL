# K / Zorro III Bus Architecture / Quick Bus Arbitration


The Zorro II bus does an adequate job of supporting multiple bus masters,
and the Zorro III bus extends this somewhat by introducing
 [fair arbitration](../Hardware_Manual_guide/node0296.html)  to Zorro II cards.  However, some desirable features
cannot be added directly to the Zorro II arbitration protocol.
Specifically, Zorro III bus arbitration is much faster than the Zorro II
style, it prohibits bus hogging that's possible under the Zorro II
protocol, and it supports intelligent bus load balancing.

Load balancing requires a bit of explanation.  A good analogy is to that
of software multitasking; there, an operating system attempts to slice up
CPU time between all tasks that need such time; here, a bus controller
attempts to slice up bus time between all masters that need such time.
With preemptive multitasking such as in the Amiga and UNIX OSs,  equal CPU
time can be granted to every task (possibly modified by priority levels),
and such scheduling is completely under control of the OS; no task can hog
the CPU time at the expense of all others.  An alternate multitasking
scheme is a popular add-on to some originally non-multitasking operating
systems lately. In this scheme, each task has the CPU until it decides to
give up the CPU, basically making the effectiveness of the CPU sharing at
the mercy of each task.  This is exactly the same situation with masters
on the Zorro II bus. The Zorro III arbitration mechanism attempts to make
bus scheduling under the control of the bus controller, with masters each
being scheduled on a cycle-by-cycle basis.

When a Zorro III PIC wants to master the bus, it registers with the bus
controller.  This tells the bus controller to include that PIC in its
scheduling of the expansion bus.  There may be any number of other PICs
registered with the bus controller at any given time.  The CPU is always
scheduled expansion bus time, and other local bus devices, such as a hard
disk controller, may be registered from time to time.

Once registered, a PIC sits idle until it receives a grant from the bus
controller.  A grant is permission from the bus controller that allows the
PIC to master the Zorro III bus for one full cycle.  A PIC always gets one
full cycle of bus time when given a grant, and assuming it stays
registered, it may receive additional full cycles.  Within the full cycle,
the PIC may run any number of  [Multiple Transfer Cycles](../Hardware_Manual_guide/node02AA.html) , assuming of
course the responding slave supports such cycles.  For multiprocessor
support, a PIC will be granted multiple atomic full cycles if it locks the
bus.  This feature is only for support of hardware semaphores and other
such multiprocessor needs; it is not intended as a means of bus hogging!

        ___     ___     ___     ___     ___     ___     ___     ___     __
   C7M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
       |   |___|   |___|   |___|   |___|   |___|   |___|   |___|   |___|

                Register                       Unregister
       ________         _______________________         __________________
  /BRn         |       |                       |       |
               |_______|                       |_______|
       __________________________        _________________________________
  /BGn                           |      |
                                 |______|
       ______________________________                      _______________
  /FCS                               |                    |
                                     |____________________|
       _____________________                                ______________
  /OWN                      |                              |
                            |______________________________|
       _______________________                                ____________
/BGACK                        |                              |


                              |______________________________|


                  Figure K-7: Zorro III Bus Arbitration
Figure K-7 shows the basics of Zorro III bus arbitration. While it uses
some of the same signals as the  [680x0 inspired Zorro II bus](../Hardware_Manual_guide/node029B.html)  arbitration
mechanism, it has nothing to do with 680x0 bus arbitration; the  [/BRn](../Hardware_Manual_guide/node02B3.html#line12)  and
 [/BGn](../Hardware_Manual_guide/node02B3.html#line12)  signals should be thought of as completely new signals.  In order
to register with the bus controller as a bus master, a PIC asserts its
private  [/BRn](../Hardware_Manual_guide/node02B3.html#line12)  strobe on the rising edge of the  [7M](../Hardware_Manual_guide/node02B0.html#line23)  clock, and negates it
on the next rising edge.  The bus controller will indicate mastership to a
registered bus master by asserting its  [/BGn](../Hardware_Manual_guide/node02B3.html#line12) .

Once granted the bus, the PIC drives only the standard cycle signals:
addresses,  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) , /EDSn, data, etc. in a full cycle. The bus controller
manages the assertion of  [/OWN](../Hardware_Manual_guide/node02B3.html#line4)  and  [/BGACK](../Hardware_Manual_guide/node02B3.html#line22) , which are important only for
bus management and Zorro II support.  While a scheduling scheme isn't part
of this bus specification, the bus master will only be guaranteed one bus
cycle at a time. The  [/BGn](../Hardware_Manual_guide/node02B3.html#line12)  line is negated shortly after the master
asserts  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  unless the bus controller is planning to grant multiple
full cycles to the master. A locked bus will force the controller to grant
multiple full cycles. Any master that works better with multiple cycles,
such as devices with buffers to empty into memory, should run a
 [Multiple Transfer Cycle](../Hardware_Manual_guide/node02AA.html)  to transfer several longwords during the same
full cycle.  For this reason, slave cards are encouraged to support
 [Multiple Transfer Cycles](../Hardware_Manual_guide/node02AA.html) , even if they don't necessarily run any faster
during them.

Once a registered bus master has no more work to do, it unregisters with
the bus controller. This works just like registering -- the PIC asserts
 [/BRn](../Hardware_Manual_guide/node02B3.html#line12)  on the rise of  [7M](../Hardware_Manual_guide/node02B0.html#line23) , then negates it on next rising  [7M](../Hardware_Manual_guide/node02B0.html#line23) .  This is
best done during the last cycle the bus master requires on the bus.  If a
registered master gets a grant before unregistering and has no work to do,
it can unregister without asserting  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) , to give back the bus without
runing a cycle. It's always far better to make sure that the master
unregisters as quickly as possible.  Bus timeout causes an automatic
unregistering of the registered master that was granted that timed-out
cycle; this guarantees that an inactive registered master can't drag down
the system. If a master sees a  [/BERR](../Hardware_Manual_guide/node02B1.html#line4)  during a cycle, it should terminate
that cycle immediately and re-try the same cycle.  If the retried cycle
results in a  [/BERR](../Hardware_Manual_guide/node02B1.html#line4)  as well, nothing more can be done in hardware;
notification of the driver program is the usual recourse.

The bus controller may have to mix Zorro II style bus arbitration in with
Zorro III arbitration, as Zorro II and Zorro III cards can be freely mixed
in a backplane.  Because of this,  [Multiple Transfer Cycles](../Hardware_Manual_guide/node02AA.html) , and the
self-timed nature of Zorro III cards, there's no way to guarantee the
latency between bus grants for a Zorro III card.  The bus controller does,
however, make sure that all masters are  [fairly](../Hardware_Manual_guide/node0296.html)  scheduled so that no
starvation occurs, if at all possible.  Zorro III cards must use Zorro III
style bus arbitration; although current Zorro III backplanes can't
differentiate between Zorro II and Zorro III cards when they request
(other than by the request mechanism), it can't be assumed that a
backplane will support Zorro III cycles with Zorro II mastering, or
visa-versa.

