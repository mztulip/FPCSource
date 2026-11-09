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

This branch contains specific compiler and RTL fixes required to build 16-bit Windows 3.1x applications (specifically the **Calmira II** desktop shell and the **WUIL** component library) targeted for 80486+ in 16-bit Protected Mode with Open Watcom Linker (`wlink`) under `win16Loader`:

### 1. Compiler Fixes (`compiler/`)
* **`compiler/i8086/n8086ld.pas` (`7b0d5d4a`):**
  * Fixed `resourcestring` table access in the HUGE memory model (`-WmHUGE`). In the huge model, unit data segments differ from `DS`. Symbols of type `constresourcestring` / `constwresourcestring` now have their segment loaded explicitly via `cg.a_load_ref_reg` with `addr_seg`.
* **`compiler/link.pas` (`0677764a`):**
  * Fixed Open Watcom `wlib` page size calculation: `get_wlib_record_size` now returns `page_size` instead of `nb_pages`. This prevents dictionary overflow when linking very large Win16 units and static libraries.
* **`compiler/x86/hlcgx86.pas` (`0677764a`):**
  * Fixed DLL import trampolines for Win16: forces far jump (`S_FAR`) instead of near jump when target is `win16`.
* **`compiler/i8086/cpupara.pas` & `compiler/scandir.pas` (`cca94642`):**
  * Fixed record parameter passing semantics on i8086 and directory scanning for Win16.
* **`compiler/x86/nx86inl.pas` (`6ca8e185`):**
  * Fixed compiler inlining issues on 16-bit x86 targets.

### 2. RTL Win16 Extensions & Fixes (`rtl/win16/`)
* **`rtl/win16/system.pp` (`7b0d5d4a`, `0677764a`):**
  * Added `_FPC_ParamStrA` support (`ParamStrA(l: Integer): AnsiString`) with proper 16-bit `Integer` index for Win16/i8086.
* **`rtl/win16/winprocsh.inc` & `rtl/win16/wintypes.inc` (`0677764a`, `6ca8e185`, `cca94642`):**
  * Added missing Win16 API declarations: `CopyIcon`, `CopyCursor`, `GetFreeSystemResources`.
  * Added missing Windows constants and flags (e.g., `EW_REBOOTSYSTEM`).
  * Fixed Win16 Windows procedure parameter types and calling conventions.
* **`rtl/win16/dos.pp` (`cca94642`):**
  * Fixed file attribute handling and directory searching under Win16 Protected Mode.

### 3. Object Pascal RTL Fixes (`rtl/objpas/`)
* **`rtl/objpas/types.pp` (`0677764a`):**
  * Added complete 16-bit Win16 definitions for `TRect`, `TPoint`, `TSmallPoint`, and rectangle manipulation helpers.
* **`rtl/objpas/classes/` (`0677764a`):**
  * Compatibility adjustments for `Classes` unit under Win16.
* **`rtl/objpas/sysutils/` (`6ca8e185`, `cca94642`):**
  * Added support for `Exception.CreateRes(Integer)` with numeric resource identifiers.
  * Added `ShortString` support in `FmtStr`.
  * Added Date/Time formatting routines (`dati.inc`, `datih.inc`) and `OpenString` overloads for i8086.
 
