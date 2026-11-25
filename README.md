# FPC Source code repository

## Synopsis
This repository contains the sources of the [Free Pascal](https://www.freepascal.org/) compiler distribution.


It contains
* The compiler sources in the directory *compiler*.
* The run-time library in the directory *rtl*.
* The packages distributed with the compiler in the directory *packages*.
* Several utilities in the directory *utils*.
* The compiler testsuite in the directory *tests*.

## License
The compiler is licensed under GPL v2, the run-time files are licensed under modified LGPL. 
Both can be found in the LICENSE file, and the file rtl/COPYING.txt

## Documentation
Extensive documentation can be found on the [documentation website](https://docs.freepascal.org/). 

---

## Win16 (i8086-win16) Fork Modifications & Fixes

This fork contains compiler and RTL fixes required to build 16-bit Windows 3.1x applications — specifically the [**Calmira II (`calmira_fpc`)**](https://github.com/mztulip/calmira_fpc) desktop shell and the [**WUIL (`wuil_fpc`)**](https://github.com/mztulip/wuil_fpc) component library — targeted for 80486+ in 16-bit Protected Mode (`-WmHUGE`) with Open Watcom Linker (`wlink`) under [**win16Loader**](https://github.com/mztulip/win16Loader).

### 1. Compiler Fixes (`compiler/`)
* **`compiler/i8086/n8086ld.pas` (`8fce21ab`):**
  * Fixed `resourcestring` table access in the HUGE memory model (`-WmHUGE`). In the huge model, unit data segments differ from `DS`. Symbols of type `constresourcestring` / `constwresourcestring` now have their segment loaded explicitly via `cg.a_load_ref_reg` with `addr_seg`.
* **`compiler/link.pas` (`87a8c20f`):**
  * Fixed Open Watcom `wlib` page size calculation: `get_wlib_record_size` now returns `page_size` instead of `nb_pages`, preventing dictionary overflow when linking large Win16 units and static libraries.
* **`compiler/x86/hlcgx86.pas` (`87a8c20f`):**
  * Fixed DLL import trampolines for Win16: forces far jump (`S_FAR`) instead of near jump when target is `win16`.
* **`compiler/i8086/cpupara.pas` & `compiler/scandir.pas`:**
  * Fixed record parameter passing semantics on i8086 and directory scanning for Win16.
* **`compiler/x86/nx86inl.pas` (`1abd86d3`):**
  * Fixed compiler inlining issues on 16-bit x86 targets.
* **`compiler/pstatmnt.pas` (`238c6324`):**
  * Delphi-mode `assembler` routines now keep the default (stack) calling convention on `i8086-win16`.
* **`compiler/i8086/n8086add.pas` & `compiler/i8086/symcpu.pas` (`18129457`):**
  * Fixed `classref` comparisons on `i8086-win16`.

### 2. RTL Win16 & i8086 Extensions & Fixes (`rtl/win16/`, `rtl/i8086/`, `rtl/inc/`)
* **`rtl/win16/system.pp`, `rtl/win16/prt0comn.asm`, `rtl/win16/glbheap.inc` (`8fce21ab`, `87a8c20f`, `18129457`):**
  * Added `_FPC_ParamStrA` support (`ParamStrA(l: Integer): AnsiString`) with proper 16-bit `Integer` index for Win16/i8086.
  * Fixed Win16 startup code and global heap initialization.
* **`rtl/win16/winprocsh.inc`, `rtl/win16/wintypes.inc`, `rtl/win16/win31.pp` (`87a8c20f`, `1abd86d3`, `07bdaead`):**
  * Added missing Win16 API declarations (`CopyIcon`, `CopyCursor`, `GetFreeSystemResources`) and constants (e.g., `EW_REBOOTSYSTEM`).
  * Added Win16 ordinal indices to `winprocsh.inc` and `win31.pp` imports.
  * Fixed Win16 Windows procedure parameter types and calling conventions.
* **`rtl/i8086/setjump.inc` (`b0378a12`):**
  * `fpc_setjmp` now imports `KERNEL.Catch`, fixing `#GP` crashes on `raise` exceptions under Win16 Protected Mode.
* **`rtl/inc/objpas.inc` (`b490f462`):**
  * Fixed `TObject.Dispatch` on Win16 to read a 16-bit `Word` message ID instead of a 32-bit `DWord`.
* **`rtl/win16/dos.pp` & `rtl/win16/sysutils.pp` (`09c33459`):**
  * Fixed file attribute handling and directory searching under Win16 Protected Mode.
  * Tracked active `FindFirst` handles so `FindClose` on an uninitialized `TSearchRec` is safe.

### 3. Object Pascal RTL Fixes (`rtl/objpas/`)
* **`rtl/objpas/types.pp` (`87a8c20f`):**
  * Added complete 16-bit Win16 definitions for `TRect`, `TPoint`, `TSmallPoint`, and rectangle manipulation helpers.
* **`rtl/objpas/classes/` (`87a8c20f`, `18129457`):**
  * Compatibility adjustments for `Classes` unit under Win16, including DFM component name uniqueness fixes.
* **`rtl/objpas/typinfo.pp` (`b0378a12`):**
  * `SetOrdProp` now properly handles `Byte`/`Word` setter parameters on `i8086-win16`.
* **`rtl/objpas/sysutils/` (`1abd86d3`, `18129457`):**
  * Added `Exception.CreateRes(Integer)` with numeric resource IDs, `ShortString` support in `FmtStr`, Delphi `NullStr`, Date/Time formatting routines (`dati.inc`, `datih.inc`), and `OpenString` overloads for i8086.

### Building the `i8086-win16` Cross-Compiler & RTL

Requires a host Linux `fpc` compiler, GNU Make, and Open Watcom (`wlink`, `wlib`):

```bash
# 1. Build the i8086 cross-compiler (produces compiler/ppcross8086)
make -C compiler i8086

# 2. Build the Win16 RTL in HUGE memory model for i486 (produces rtl/units/win16)
make -C rtl/win16 \
    OS_TARGET=win16 CPU_TARGET=i8086 \
    PP="$PWD/compiler/ppcross8086" \
    OPT="-Cp80486 -Op80486 -Wh -WmHUGE -CX -XX"
```
 
