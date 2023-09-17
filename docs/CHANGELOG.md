v0.3.2
======
* Better syscall handling
* Fixed some wrapped functions, added some others
* Introduced another wrapper helper
* Added some more opcodes
* Added a cosimulation mode (to compare the behaviour of the dynarec against the interpreter)
* Added support of FASTNAN for some more opcodes
* Reduced memory footprint
* Added BOX86_NOSANDBOX (adds an argument to the command line)
* Added an ukrainian translation
=> Mostly a stability update with improved elfloader, fixed opcodes and refined profiles

v0.3.0
======
* Added rcfile handling: box86 now read `/etc/box86.box86rc` and `~/.box86rc` and apply per process parameters
    => Every program can be finetuned, for speed or just to make them work
* Added BOX86_DYNAREC_FORWARD to allow bigger Dynarec block to be build
* Refactored Strong Memory Model emulation (faster and more accurate)
* Box86 now return a custom name for the CPU instal of P4, build with Box86 and the cpu name it's running on
* Improved memory protection tracking and signal handling, again
* More wrapped libs (especially on the gtk familly)
* More wrapped functions
* Added support for CreateDeviceEx in d3dadapter9, for better gallium nine support
* Improved dladdr/dladdr1 wrapped function
* Some fixes to flags handling in the Dynarec on some special cases
* Added specific suppport for RK3588 board (needed some hack in signal handling, probably due to the use of a non mainlined kernel)
* Lots of improvment in the Rounding of float & double (Dynarec and Interpretor), and proper handling of denormals when converting to/from 80 bits long double
* Added specific suppport for RK3588 board (needed some hack in signal handling, probably due to the use of a non mainlined kernel)


v0.2.8
======
* Wrapped more vulkan function, dxvk 2.0 now works
* Added support for overriden malloc/free functions
* Improved elf loader
* Improved dlsym handling with RTLD_NEXT
* Added BOX86_DYNAREC_SAFEFLAGS to allow finetuning Dynarec generated code handling of flags accross function calls and returns.
* Added BOX86_BASH to setup x86 bash binary, so shell script can be run in x86 world 
* Added BOX86_ROLLING_LOG to have details log only on crash
* Improved TLS Size handling (Unity3D games now works)
* Improved `execv` family of function to have better box86 integration
* Added a few more wrapped libs, like FAudio
* Improved gtk, SDL2, GL, vulkan (and more) wrapping
* Improved Signal Handling and memory protection traking
* Added some basic support for statically linked program. Thread are not working yet, but memory allocation and file access does.
=> with the use of the new SafeFlags, some C# Windows program now runs fine (it's forced when the Vara family of software is detected)
=> With the basic support of statcaly linked program, old emulator like modeler for linux works. Program with threads like mugen for linux still doesn't
=> The bash integration is usefull for device with no binfmt integration or for script that check the machine it's running on

v0.2.6
======
* Added an option to get generated -NAN on SSE2 operation
* Many small fixes and improvement to get steam and SteamPlay working (along with box64)
* Added some workaround for program calling uname to mimic x86 system
* Added some more Vulkan extensions
* Added some granularity to mmap64, and generic memory protection tracking improvment, to mimic x86 system (for wine stagging and proton)
* Better clone syscall and libc implementation
* Improved wrapping of GTK libs
* More wrapped libs (more gtk libs, like gstreamer-1.0 among other non-gtk libs too)
* More wrapped functions(with some tricky one, like dladdr1)
* Some fixes and improvment to some wrapped functions
* Refactor Dynarec:
    * better handling of SSE/x87 registers
    * optimisation to limit float/double conversion
    * better handling of "internal" jump inside a dynablock
* Improved elfloader
* Improved some tests
* A few fixes in some Dynarec opcodes
* Don't quit on unsupported syscall, return -1 / ENOSYS error
* A bit more optimisation in some Dynarec opcodes

v0.2.4
======
* Some work on Dynarec to limit the number of mutex use, and also allow smaller block to be built (for JIT'd programs)
* Introduce BOX86_DYNAREC_STRONGMEM, like with box64 (not found any program that needs that yet)
* More vulkan wrapped function (so dkvk works, at least with RX550)
* Reworked Elfloader part, with better handling of versionned symbols
* Improve speed for x87 code (by avoiding many float<->double conversion)
* Improve speed of the custom allocator used by dynarec and Hash (speedup loading)
* Added a detection of box64 in uname call, to expose an x86_64 system instead of i386 one
* Added a fix for linking box86 on system using glibc 2.34+
* A few more wrapped libs
* More ARM hardware option in CMake (Phytium, SD845)
* Changed a bit struture of Dynarec, switching some operations from Pass1 to Pass0
* Small fixes to elfloader
* Some fixes and improvments on wrapped libs (mainly gtk2, gtk3 and d3dadpter)
* Better VSyscall implementation
* Fixed the "Alternate" handling (address shadowing on x86 side)
* A few opcodes border case fixes
* Improved wrapper helpers (from rajdakin)
* Added a mecanism to cancel a Dynarec block construction if it triggers a segfault (instead of a crash)
* Improvment to the handling of longjmp inside signal handlers

v0.2.2
======
* Reworked some elfloader relocation mecanism
* Removed old "smart linker" and replace with a simple "jump table"
* Also removed CALL/RET optomisation from Dynarec, simple Jump Table is faster
* Reworked all memory protection tracking
* A few more wrapped libs and wrapped functions
* A few more opcodes
* A few more dynarec opcodes
* Some optimisation in Dynarec around ZF and CF flags handlings, and LL/GE/LE/G conditionnal opcodes
* Some changes to the "cancel threads" handling
* Some changes to the "thread once" handling

v0.2.0
======
* Improvements on x86 Flags handling.
* A few more opcode has been added.
* A few potential BusError are now fixed.
* Added the BOX86_NOVULKAN en. var. . This is used to disable the wrapping of vulkan libraries.
* Improvments on libc O_XXXX flags handling.
* Box86 now uses a custom allocator for Dynarec and Hash tables.
* Improved the wrapping of pulse audio.
* Optimisation to a few Dynarec opcode (like SHRD/SHLD).
* Improved the tracking of memory protection.
* A few more wrapping of libraries (like libgssapi_krb5).
* More function wrapping on libturbojpeg
* Preliminary support for POWER9 (ppcle) build
* Many contributions to remove typos and rephrase the README, COMPILE and USAGE documents

v0.1.8
======
* Fixes on some float to int x86 convertions opcodes.
* Reworked all callback mecanisms.
* Added libturbojpeg wrapping (and a hack for zoom to force using native one).
* Added the BOX86_SAFEMMAP env. var.
* Reworked Dynarec's memory manager.
* Added a few opcodes.
* Improve elfloader to not force PltResolver all the time (fixing SuperHexagon and maybe other)
* Reworked Exet and Cancel Thread mecanism.
* Added wrapped libldap_r and liblber library (used by wine)
* Reworked Dynarec block handling, and remove the "AddMark" mecanism that wasn't efficient enough
* Added TokiTori 2+ detection and runtime patch on the Raspberry Pi platform
* Fixes on elfloader with TLS object.

v0.1.6
======
* Changes in Dynarec to make flags optimizations before CALL and RET opcode less aggressive.
* Added a Vulkan wrapper.
* Improved wrapping of SDL_mixer/ SDL2_mixer libraries.
* Improved wrapping of some GTK structures.
* Added a quick and dirty wrapping of GTK3 (based on current GTK2).
* Improved the signal handling, should be more stable now (the signal handler from syscall still need some works).
* Added the RK3399 profile, and some hints to build 32bits box86 on 64bits OS.
* Fixed some wrapped printf formating not handled correctly.
* Fixed some buserror with the new LOCK mecanism handling.
* A few more Dynarec opcodes added.
* If winedbg is tried to be launched, exit without launching it (it doesn't work anyways).

v0.1.4
======
* Change in Dynarec's memory handling, to simplify it (and hopefully optimized it).
* Even more opcodes added.
* And some more Dynarec opcodes.
* Fixed some issue were PltResolver was injected but should not be.
* Fixed many Dynarec and non dynarec opcodes.
* Improved Signal handling.
* Added a few more wrapped libraries (like curl).
* Gallium9 is now wrapped (thx @icecream95).
* Fixed and simplied many wrapped functions (especialy the one where a callback is involved).
* Fixed Dynarec "freeing" a Dynablock sometimes causing a corruption of the heap (generally happens in case of JIT code).
* Optimized the way LOCK prefix work when using Dynarec on ARM.
* improvements to the ARM opcode Printer (for dumping Dynarec blocks) improvement (thx @rajdakin).

v0.1.2
======
* The Dynarec now handle JIT code
* Added support for Unity games (not perfect yet).
* Added support for Wine (not perfect yet). You need an x86 build of Wine to use it.
* Added support for Steam (not perfect yet). Note that Steam have limited functionalities on 32bits (only mini-mode is available).
* More wrapped libs
* Added support for the "PltResolver". This makes the order of libraries less important and many symbols are now resolved at runtime.
* Added an option to build Box86 as a library (to wrap dynamic library).
* Better Signal handling (not perfect yet).
* More opcodes added, more opcode fixes.
* More Dynarec opcodes.
* Added support for FS:, and creating custom selector (needed by Wine).
* There is now 1 x86emu_t structure per thread (simplifying/optimising many callback handling).
* Box86 now has a logo!
* Added options handling (only version and help for now). Now it's much usefull exept for version printing.


v0.1.0
=======
* Dynarec!!! Only for ARM (note that Dynarec doesn't support JITed code for now).
* Added real support for getcontext/set/context/makecontext/swapcontext.
* Preliminary signal handling.
* Fixes to SDL(1/2) Image and SDL1 Mixer, and to SDL1.2 RWops usage.
* Fixed numerous issues in opcodes (both interpretor and dynarec). FTL works fine now, among many others.
* Added wrapped GTK support (still ongoing, many libraries involved).
* Make loading of libraries more configurable.
* If a wrapped native library is not found, try to use an emulated one.
* Added an env. var. to force the use of emulated libraries for certain libraries.
* Added an env. var. to precise which libGL to use.
* Added Install / Uninstall target (using systemd binfmt).
* Added more hardware targets (RPis, GameShell...).
* Wrapped more libraries (including FreeType, smpeg, ncurses, sndfile...).

v0.0.4
=======
* Improved the initialisation of dependent libraries. More things work now.
* Added a lot of wrapped functions.
* Added a few wrapped libraries (like libz or some other x11 related library).
* For trace enabled build, Trace can be enabled only after a certain amount of opcodes (still, a debugger would be better).
* Some fixes in a few opcodes, and implemented x87 rounding (SuperMeatBoy behaves better now).
* FTL 1.6.9 still has corrupted music, but older 1.5.13 seems fine (different set of libraries).

v0.0.2
=======
* A full commercial games runs fine on the Pandora platform: Airline Tycoon Deluxe.
* Implemented all planned subparts of Box86 except JIT support.
* CPU Emulation is at roughly 75%. This includes x87 and SSE/SSE2. MMX is barely implemented (but barely used anyway).
* x87 emulation is simplified, no real x87 State handling (but should not be mandatory, as the native libm library is used)
* No Signal handling yet
* ELF Loader is crude and probably full of bugs. Also, the initialisation of libraries are defered after all symbols are resolved for now.
* Wrapped libraries include libc, libm, rt, pthread, libdl, dllinux, libasound, GL, GLU, SDL1/mixer/image, SDL2/mixer/image/smpeg, OpenAL/ALUT, libz, libpng16, vorbisfile, x11/xrandr/xxf86vm.
* Most wrapped libraries are still partially implemented ( the SDL1 & GL  libraries should be complete).
* Implemented specific mecanism for SDL(1/2) RWops, to be able to used them both in Native and x86 world.
* WorldOfGoo works, but is painfully slow on the Pandora platform (there is too much double math, and lack of JIT).
* FTL works, but sound is broken (issue with thread? asound? or CPU core?)
* Limbo launches but crashes before main menu.

