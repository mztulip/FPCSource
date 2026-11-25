
function LOBYTE(w: Word): Byte; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function HIBYTE(w: Word): Byte; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function LOWORD(l: LongInt): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function HIWORD(l: LongInt): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELONG(low, high: Word): LONG; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELPARAM(low, high: Word): LPARAM; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function MAKELRESULT(low, high: Word): LRESULT; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function MAKELP(sel, off: Word): FarPointer; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function SELECTOROF(lp: FarPointer): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function OFFSETOF(lp: FarPointer): Word; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

// FIELDOFFSET

{ System Information }
function GetVersion: DWORD; external 'KERNEL' index 3;

function GetFreeSpace(Flag: UINT): DWORD; external 'KERNEL' index 169;
function GetCurrentPDB: UINT; external 'KERNEL' index 37;

function GetWindowsDirectory(Buffer: LPSTR; Size: UINT): UINT; external 'KERNEL' index 134;
function GetSystemDirectory(Buffer: LPSTR; Size: UINT): UINT; external 'KERNEL' index 135;

function GetWinFlags: DWORD; external 'KERNEL' index 132;

function GetDOSEnvironment: LPSTR; external 'KERNEL' index 131;

function GetCurrentTime: DWORD; external 'USER' index 15;
function GetTickCount: DWORD; external 'USER' index 13;
function GetTimerResolution: DWORD; external 'USER' index 14;

{ Error handling }
procedure FatalExit(Code: SmallInt); external 'KERNEL';
procedure FatalAppExit(Action: UINT; MessageText: LPCSTR); external 'KERNEL' index 137;

function ExitWindows(dwReturnCode: DWORD; wReserved: UINT): BOOL; external 'USER' index 7;
function ExitWindowsExec(Exe, Params: LPCSTR): BOOL; external 'USER' index 246;

procedure DebugBreak; external 'KERNEL' index 203;
procedure OutputDebugString(OutputString: LPCSTR); external 'KERNEL' index 115;

function SetErrorMode(Mode: UINT): UINT; external 'KERNEL' index 107;

{ Catch/Throw and stack management }

function Catch(CatchBuf: LPCATCHBUF): SmallInt; external 'KERNEL' index 55;
procedure Throw(CatchBuf: LPCATCHBUF; ThrowBack: SmallInt); external 'KERNEL' index 56;
{$ifdef VAR_PARAMS_ARE_FAR}
function Catch(var CatchBuf: TCatchBuf): SmallInt; external 'KERNEL' index 55;
procedure Throw(var CatchBuf: TCatchBuf; ThrowBack: SmallInt); external 'KERNEL' index 56;
{$endif}

procedure SwitchStackBack; external 'KERNEL' index 109;
procedure SwitchStackTo(StackSegment, StackPointer, StackTop: UINT); external 'KERNEL' index 108;

{ Module Management }

function LoadModule(ModuleName: LPCSTR; ParameterName: LPVOID): HINST; external 'KERNEL' index 45;
function FreeModule(Module: HINST): BOOL; external 'KERNEL' index 46;

function WinLoadLibrary(LibFileName: LPCSTR): HINST; external 'KERNEL' name 'LoadLibrary';
procedure WinFreeLibrary(LibModule: HINST); external 'KERNEL' name 'FreeLibrary';

function WinExec(CmdLine: LPCSTR; CmdShow: UINT): UINT; external 'KERNEL' index 166;

function GetModuleHandle(ModuleName: LPCSTR): HMODULE; external 'KERNEL' index 47;

function GetModuleUsage(Module: HINST): SmallInt; external 'KERNEL' index 48;
function GetModuleFileName(Module: HINST; FileName: LPSTR; Size: SmallInt): SmallInt; external 'KERNEL' index 49;

function WinGetProcAddress(Module: HINST; ProcName: LPCSTR): FARPROC; external 'KERNEL' name 'GetProcAddress';

function GetInstanceData(Instance: HINST; Data: PBYTE; Count: SmallInt): SmallInt; external 'KERNEL' index 54;

function GetCodeHandle(Proc: FARPROC): HGLOBAL; external 'KERNEL' index 93;

procedure GetCodeInfo(lpProc: FARPROC; lpSegInfo: LPSEGINFO); external 'KERNEL' index 104;

function MakeProcInstance(Proc: FARPROC; Instance: HINST): FARPROC; external 'KERNEL' index 51;
procedure FreeProcInstance(Proc: FARPROC); external 'KERNEL' index 52;

{#ifdef _LAX
#define MakeProcInstance(__F, __H) MakeProcInstance((FARPROC)__F, __H)
#define FreeProcInstance(__F)      FreeProcInstance((FARPROC)__F)
#endif /* _LAX */}

function SetSwapAreaSize(Size: UINT): LONG; external 'KERNEL' index 106;
procedure SwapRecording(Flag: UINT); external 'KERNEL';
procedure ValidateCodeSegments; external 'KERNEL' index 100;

{ Task Management }

function GetNumTasks: UINT; external 'KERNEL' index 152;
function GetCurrentTask: HTASK; external 'KERNEL' index 36;

procedure Yield; external 'KERNEL' index 29;
procedure DirectedYield(Task: HTASK); external 'KERNEL' index 150;

{ Global memory management }

function GlobalDiscard(h: HGLOBAL): HGLOBAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function GlobalAlloc(Flags: UINT; Bytes: DWORD): HGLOBAL; external 'KERNEL' index 15;
function GlobalReAlloc(Mem: HGLOBAL; Bytes: DWORD; Flags: UINT): HGLOBAL; external 'KERNEL' index 16;
function GlobalFree(Mem: HGLOBAL): HGLOBAL; external 'KERNEL' index 17;

function GlobalDosAlloc(Bytes: DWORD): DWORD; external 'KERNEL' index 184;
function GlobalDosFree(Selector: UINT): UINT; external 'KERNEL' index 185;

function GlobalLock(Mem: HGLOBAL): FarPointer; external 'KERNEL' index 18;
function GlobalUnlock(Mem: HGLOBAL): BOOL; external 'KERNEL' index 19;

function GlobalSize(Mem: HGLOBAL): DWORD; external 'KERNEL' index 20;
function GlobalHandle(Mem: UINT): DWORD; external 'KERNEL' index 21;

function GlobalFlags(Mem: HGLOBAL): UINT; external 'KERNEL' index 22;

function GlobalWire(Mem: HGLOBAL): FarPointer; external 'KERNEL' index 111;
function GlobalUnWire(Mem: HGLOBAL): BOOL; external 'KERNEL' index 112;

function GlobalPageLock(Selector: HGLOBAL): UINT; external 'KERNEL' index 191;
function GlobalPageUnlock(Selector: HGLOBAL): UINT; external 'KERNEL' index 192;

procedure GlobalFix(Mem: HGLOBAL); external 'KERNEL' index 197;
procedure GlobalUnfix(Mem: HGLOBAL); external 'KERNEL' index 198;

function GlobalLRUNewest(Mem: HGLOBAL): HGLOBAL; external 'KERNEL' index 164;
function GlobalLRUOldest(Mem: HGLOBAL): HGLOBAL; external 'KERNEL' index 163;

function GlobalCompact(MinFree: DWORD): DWORD; external 'KERNEL' index 25;

procedure GlobalNotify(NotifyProc: GNOTIFYPROC); external 'KERNEL' index 154;

function LockSegment(Segment: UINT): HGLOBAL; external 'KERNEL' index 23;
procedure UnlockSegment(Segment: UINT); external 'KERNEL' index 24;

function LockData(dummy: SmallInt): HGLOBAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
procedure UnlockData(dummy: SmallInt); {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function AllocSelector(Selector: UINT): UINT; external 'KERNEL' index 175;
function FreeSelector(Selector: UINT): UINT; external 'KERNEL' index 176;
function AllocDStoCSAlias(Selector: UINT): UINT; external 'KERNEL' index 171;
function PrestoChangoSelector(sourceSel, destSel: UINT): UINT; external 'KERNEL' index 177;
function GetSelectorBase(Selector: UINT): DWORD; external 'KERNEL' index 186;
function SetSelectorBase(Selector: UINT; Base: DWORD): UINT; external 'KERNEL' index 187;
function GetSelectorLimit(Selector: UINT): DWORD; external 'KERNEL' index 188;
function SetSelectorLimit(Selector: UINT; Base: DWORD): UINT; external 'KERNEL' index 189;

procedure LimitEmsPages(Kbytes: DWORD); external 'KERNEL' index 156;

procedure ValidateFreeSpaces; external 'KERNEL' index 200;
procedure DOS3Call; external 'KERNEL' name 'DOS3CALL';

{ Local Memory Management }

function LocalDiscard(h: HLOCAL): HLOCAL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function LocalAlloc(Flags, Bytes: UINT): HLOCAL; external 'KERNEL' index 5;
function LocalReAlloc(Mem: HLOCAL; Bytes, Flags: UINT): HLOCAL; external 'KERNEL' index 6;
function LocalFree(Mem: HLOCAL): HLOCAL; external 'KERNEL' index 7;

function LocalLock(Mem: HLOCAL): NearPointer; external 'KERNEL' index 8;
function LocalUnlock(Mem: HLOCAL): BOOL; external 'KERNEL' index 9;

function LocalSize(Mem: HLOCAL): UINT; external 'KERNEL' index 10;
function LocalHandle(Mem: NearPointer): HLOCAL; external 'KERNEL' index 11;

function LocalFlags(Mem: HLOCAL): UINT; external 'KERNEL' index 12;

function LocalInit(Segment, Start, EndPos: UINT): BOOL; external 'KERNEL' index 4;
function LocalCompact(MinFree: UINT): UINT; external 'KERNEL' index 13;
function LocalShrink(Seg: HLOCAL; Size: UINT): UINT; external 'KERNEL' index 121;

{ File I/O }

function OpenFile(FileName: LPCSTR; ReOpenBuff: LPOFSTRUCT; Style: UINT): HFILE; external 'KERNEL' index 74;
{$ifdef VAR_PARAMS_ARE_FAR}
function OpenFile(FileName: LPCSTR; var ReOpenBuff: TOFStruct; Style: UINT): HFILE; external 'KERNEL' index 74;
{$endif}

function _lopen(PathName: LPCSTR; ReadWrite: SmallInt): HFILE; external 'KERNEL' index 85;
function _lcreat(PathName: LPCSTR; Attribute: SmallInt): HFILE; external 'KERNEL' index 83;

function _lclose(FileHandle: HFILE): HFILE; external 'KERNEL' index 81;

function _llseek(FileHandle: HFILE; Offset: LONG; Origin: SmallInt): LONG; external 'KERNEL' index 84;

function _lread(FileHandle: HFILE; Buffer: HugePointer; Bytes: UINT): UINT; external 'KERNEL' index 82;
function _lread(FileHandle: HFILE; Buffer: FarPointer; Bytes: UINT): UINT; external 'KERNEL' index 82;
function _lwrite(FileHandle: HFILE; Buffer: HugePointer; Bytes: UINT): UINT; external 'KERNEL' index 86;
function _lwrite(FileHandle: HFILE; Buffer: FarPointer; Bytes: UINT): UINT; external 'KERNEL' index 86;

function GetTempFileName(DriveLetter: BYTE; PrefixString: LPCSTR; Unique: UINT; TempFileName: LPSTR): SmallInt; external 'KERNEL' index 97;
function GetTempFileName(DriveLetter: AnsiChar; PrefixString: LPCSTR; Unique: UINT; TempFileName: LPSTR): SmallInt; external 'KERNEL' index 97;
function GetTempDrive(DriveLetter: AnsiChar): BYTE; external 'KERNEL' index 92;

function GetDriveType(Drive: SmallInt): UINT; external 'KERNEL' index 136;

function SetHandleCount(Number: UINT): UINT; external 'KERNEL' index 199;

{ Network support }
function WNetAddConnection(lpszNetPath, lpszPassword, lpszLocalName: LPSTR): UINT; external 'USER' index 517;
function WNetGetConnection(lpszLocalName, lpszRemoteName: LPSTR; cbBufferSize: LPUINT): UINT; external 'USER' index 512;
function WNetCancelConnection(lpszName: LPSTR; tForce: BOOL): UINT; external 'USER' index 518;

{ Resource Management }

function FindResource(hInstance: HINST; lpName, lpType: LPCSTR): HRSRC; external 'KERNEL' index 60;
function LoadResource(hInstance: HINST; hResInfo: HRSRC): HGLOBAL; external 'KERNEL' index 61;
function FreeResource(hResData: HGLOBAL): BOOL; external 'KERNEL' index 63;

function LockResource(hResData: HGLOBAL): FarPointer; external 'KERNEL' index 62;
function UnlockResource(hResData: HGLOBAL): BOOL; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function SizeofResource(hInstance: HINST; hResInfo: HRSRC): DWORD; external 'KERNEL' index 65;

function AccessResource(hInstance: HINST; hResInfo: HRSRC): SmallInt; external 'KERNEL' index 64;

function AllocResource(hInstance: HINST; hResInfo: HRSRC; dwSize: DWORD): HGLOBAL; external 'KERNEL' index 66;

function SetResourceHandler(hInstance: HINST; lpType: LPCSTR; lpLoadFunc: RSRCHDLRPROC): RSRCHDLRPROC; external 'KERNEL' index 67;

{ Atom Management }

function InitAtomTable(cTableEntries: SmallInt): BOOL; external 'KERNEL' index 68;
function AddAtom(lpszName: LPCSTR): ATOM; external 'KERNEL' index 70;
function DeleteAtom(atm: ATOM): ATOM; external 'KERNEL' index 71;
function FindAtom(lpszString: LPCSTR): ATOM; external 'KERNEL' index 69;
function GetAtomName(atm: ATOM; lpszBuffer: LPSTR; cbBuffer: SmallInt): UINT; external 'KERNEL' index 72;
function GlobalAddAtom(lpszString: LPCSTR): ATOM; external 'USER' index 268;
function GlobalDeleteAtom(atm: ATOM): ATOM; external 'USER' index 269;
function GlobalFindAtom(lpszString: LPCSTR): ATOM; external 'USER' index 270;
function GlobalGetAtomName(atom: ATOM; lpszBuffer: LPSTR; cbBuffer: SmallInt): UINT; external 'USER' index 271;
function GetAtomHandle(atm: ATOM): HLOCAL; external 'KERNEL' index 73;

{ WIN.INI Support }

{ User Profile Routines }
  function GetProfileInt(lpszSection: LPCSTR; lpszEntry: LPCSTR; default: SmallInt): UINT; external 'KERNEL' index 57;
  function GetProfileString(lpszSection, lpszEntry, lpszDefault: LPCSTR; lpszReturnBuffer: LPSTR; cbReturnBuffer: SmallInt): SmallInt; external 'KERNEL' index 58;
  function WriteProfileString(lpszSection, lpszEntry, lpszString: LPCSTR): BOOL; external 'KERNEL' index 59;

  function GetPrivateProfileInt(lpszSection, lpszEntry: LPCSTR; default: SmallInt; lpszFilename: LPCSTR): UINT; external 'KERNEL' index 127;
  function GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault: LPCSTR; lpszReturnBuffer: LPSTR; cbReturnBuffer: SmallInt; lpszFilename: LPCSTR): SmallInt; external 'KERNEL' index 128;
  function WritePrivateProfileString(lpszSection, lpszEntry, lpszString, lpszFilename: LPCSTR): BOOL; external 'KERNEL' index 129;

{ International & AnsiChar Translation Support }

procedure AnsiToOem(hpszWindows, hpszOem: PHugeChar); external 'KEYBOARD' index 5;
procedure AnsiToOem(hpszWindows, hpszOem: PFarChar); external 'KEYBOARD' index 5;
procedure OemToAnsi(hpszOemStr, hpszWindowsStr: PHugeChar); external 'KEYBOARD' index 6;
procedure OemToAnsi(hpszOemStr, hpszWindowsStr: PFarChar); external 'KEYBOARD' index 6;

procedure AnsiToOemBuff(lpszWindowsStr: LPCSTR; lpszOemStr: LPSTR; cbWindowsStr: UINT); external 'KEYBOARD' index 134;
procedure OemToAnsiBuff(lpszOemStr: LPCSTR; lpszWindowsStr: LPSTR; cbOemStr: UINT); external 'KEYBOARD' index 135;

function AnsiNext(lpchCurrentChar: LPCSTR): LPSTR; external 'USER' index 472;
function AnsiPrev(lpchStart, lpchCurrentChar: LPCSTR): LPSTR; external 'USER' index 473;

function AnsiUpper(lpszString: LPSTR): LPSTR; external 'USER' index 431;
function AnsiLower(lpsz: LPSTR): LPSTR; external 'USER' index 432;

function AnsiUpperBuff(lpszString: LPSTR; cbString: UINT): UINT; external 'USER' index 437;
function AnsiLowerBuff(lpszString: LPSTR; cbString: UINT): UINT; external 'USER' index 438;


function IsCharAlpha(chTest: AnsiChar): BOOL; external 'USER' index 433;
function IsCharAlphaNumeric(chTest: AnsiChar): BOOL; external 'USER' index 434;
function IsCharUpper(chTest: AnsiChar): BOOL; external 'USER' index 435;
function IsCharLower(chTest: AnsiChar): BOOL; external 'USER' index 436;

function lstrcmp(lpszString1, lpszString2: LPCSTR): SmallInt; external 'USER' index 430;
function lstrcmpi(lpszString1, lpszString2: LPCSTR): SmallInt; external 'USER' index 471;
function lstrcpy(lpszString1: LPSTR; lpszString2: LPCSTR): LPSTR; external 'KERNEL' index 88;
function lstrcat(lpszString1: LPSTR; lpszString2: LPCSTR): LPSTR; external 'KERNEL' index 89;
function lstrlen(lpszString: LPCSTR): SmallInt; external 'KERNEL' index 90;

function LoadString(hints: HINST; idResrouce: UINT; lpszBuffer: LPSTR; cbBuffer: SmallInt): SmallInt; external 'USER' index 176;

{ Keyboard Driver Functions }

function OemKeyScan(uOemChar: UINT): DWORD; external 'KEYBOARD' index 128;
function VkKeyScan(uChar: UINT): UINT; external 'KEYBOARD' index 129;
function GetKeyboardType(fnKeybInfo: SmallInt): SmallInt; external 'KEYBOARD' index 130;
function MapVirtualKey(uKeyCode, fuMapType: UINT): UINT; external 'KEYBOARD' index 131;
function GetKBCodePage: SmallInt; external 'KEYBOARD' index 132;
function GetKeyNameText(lParam: LONG; lpszBuffer: LPSTR; cbMaxKey: SmallInt): SmallInt; external 'KEYBOARD' index 133;
function ToAscii(wVirtKey, wScanCode: UINT; lpKeyState: LPBYTE; lpChar: LPDWORD; wFlags: UINT): SmallInt; external 'KEYBOARD' index 4;

{ DC Management }

function CreateDC(lpszDriver, lpszDevice, lpszOutput: LPCSTR; lpvInitData: FarPointer): HDC; external 'GDI' index 53;
function CreateIC(lpszDriver, lpszDevice, lpszOutput: LPCSTR; lpvInitData: FarPointer): HDC; external 'GDI' index 153;
function CreateCompatibleDC(hdc: HDC): HDC; external 'GDI' index 52;

function DeleteDC(hdc: HDC): BOOL; external 'GDI' index 68;

function GetDCOrg(hdc: HDC): DWORD; external 'GDI' index 79;

function SaveDC(hdc: HDC): SmallInt; external 'GDI' index 30;
function RestoreDC(hdc: HDC; nSavedDC: SmallInt): BOOL; external 'GDI' index 39;

function SetEnvironment(lpPortName: LPCSTR; lpdev: FarPointer; nCount: UINT): SmallInt; external 'GDI' index 132;
function GetEnvironment(lpPortName: LPCSTR; lpdev: FarPointer; nMaxSize: UINT): SmallInt; external 'GDI' index 133;

function MulDiv(nMultiplicand, nMultiplier, nDivisor: SmallInt): SmallInt; external 'GDI' index 128;

{ Device Capabilities }

function GetDeviceCaps(hdc: HDC; iCapability: SmallInt): SmallInt; external 'GDI' index 80;

{ Coordinate transformation support }

function SetMapMode(hdc: HDC; fnMapMode: SmallInt): SmallInt; external 'GDI' index 3;
function GetMapMode(hdc: HDC): SmallInt; external 'GDI' index 81;

function SetWindowOrg(hdc: HDC; nXOrigin, nYOrigin: SmallInt): DWORD; external 'GDI' index 11;
function GetWindowOrg(hdc: HDC): DWORD; external 'GDI' index 97;

function SetWindowExt(hdc: HDC; nXExtent, nYExtent: SmallInt): DWORD; external 'GDI' index 12;
function GetWindowExt(hdc: HDC): DWORD; external 'GDI' index 96;

function OffsetWindowOrg(hdc: HDC; nXOffset, nYOffset: SmallInt): DWORD; external 'GDI' index 15;
function ScaleWindowExt(hdc: HDC; nXNum, nXDenom, nYNum, nYDenom: SmallInt): DWORD; external 'GDI' index 16;

function SetViewportOrg(hdc: HDC; nXOrigin, nYOrigin: SmallInt): DWORD; external 'GDI' index 13;
function GetViewportOrg(hdc: HDC): DWORD; external 'GDI' index 95;

function SetViewportExt(hdc: HDC; nXExtent, nYExtent: SmallInt): DWORD; external 'GDI' index 14;
function GetViewportExt(hdc: HDC): DWORD; external 'GDI' index 94;

function OffsetViewportOrg(hdc: HDC; nXOffset, nYOffset: SmallInt): DWORD; external 'GDI' index 17;
function ScaleViewportExt(hdc: HDC; nXNum, nXDenom, nYNum, nYDenom: SmallInt): DWORD; external 'GDI' index 18;

function DPtoLP(hdc: HDC; lppt: LPPOINT; cPoints: SmallInt): BOOL; external 'GDI' index 67;
function LPtoDP(hdc: HDC; lppt: LPPOINT; cPoints: SmallInt): BOOL; external 'GDI' index 99;
{$ifdef VAR_PARAMS_ARE_FAR}
function DPtoLP(hdc: HDC; var pt; cPoints: SmallInt): BOOL; external 'GDI' index 67;
function LPtoDP(hdc: HDC; var pt; cPoints: SmallInt): BOOL; external 'GDI' index 99;
{$endif}

{ Color support }

function RGB(cRed, cGreen, cBlue: BYTE): COLORREF; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function GetRValue(rgb: DWORD): BYTE; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function GetGValue(rgb: DWORD): BYTE; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function GetBValue(rgb: DWORD): BYTE; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function GetNearestColor(hdc: HDC; clrref: COLORREF): COLORREF; external 'GDI' index 154;

function GetSysColor(nDspElement: SmallInt): COLORREF; external 'USER' index 180;
procedure SetSysColors(cDspElements: SmallInt; lpnDspElements: LPINT; lpdwRgbValues: LPCOLORREF); external 'USER' index 181;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure SetSysColors(cDspElements: SmallInt; var DspElements; var RgbValues); external 'USER' index 181;
{$endif}

{ GDI Object Support }

function GetStockObject(fnObject: SmallInt): HGDIOBJ; external 'GDI' index 87;

function IsGDIObject(hgdiobj: HGDIOBJ): BOOL; external 'GDI' index 462;

function DeleteObject(hgdiobj: HGDIOBJ): BOOL; external 'GDI' index 69;
function SelectObject(hdc: HDC; hgdiobj: HGDIOBJ): HGDIOBJ; external 'GDI' index 45;
function GetObject(hgdiobj: HGDIOBJ; cbBuffer: SmallInt; lpvObject: FarPointer): SmallInt; external 'GDI' index 82;
function UnrealizeObject(hgdiobj: HGDIOBJ): BOOL; external 'GDI' index 150;

function EnumObjects(hdc: HDC; fnObjectType: SmallInt; goenmprc: GOBJENUMPROC; lParam: LPARAM): SmallInt; external 'GDI' index 71;
function EnumObjects(hdc: HDC; fnObjectType: SmallInt; goenmprc: FARPROC; lParam: LPARAM): SmallInt; external 'GDI' index 71;

{ Pen support }

function CreatePen(fnPenStyle, nWidth: SmallInt; clrref: COLORREF): HPEN; external 'GDI' index 61;
function CreatePenIndirect(lplgpn: LPLOGPEN): HPEN; external 'GDI' index 62;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePenIndirect(var lgpn: LOGPEN): HPEN; external 'GDI' index 62;
{$endif}

{ Brush support }

function CreateSolidBrush(clrref: COLORREF): HBRUSH; external 'GDI' index 66;
function CreateHatchBrush(fnStyle: SmallInt; clrref: COLORREF): HBRUSH; external 'GDI' index 58;
function CreatePatternBrush(hbmp: HBITMAP): HBRUSH; external 'GDI' index 60;
function CreateDIBPatternBrush(hglbDIBPacked: HGLOBAL; fnColorSpec: UINT): HBRUSH; external 'GDI' index 445;
function CreateBrushIndirect(lplb: LPLOGBRUSH): HBRUSH; external 'GDI' index 50;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateBrushIndirect(var lb: LOGBRUSH): HBRUSH; external 'GDI' index 50;
{$endif}

function SetBrushOrg(hdc: HDC; nXOrg, nYOrg: SmallInt): DWORD; external 'GDI' index 148;
function GetBrushOrg(hdc: HDC): DWORD; external 'GDI' index 149;

{ Region support }

function CreateRectRgn(nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): HRGN; external 'GDI' index 64;
function CreateRectRgnIndirect(lprc: LPRECT): HRGN; external 'GDI' index 65;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateRectRgnIndirect(const rc: RECT): HRGN; external 'GDI' index 65;
{$endif}
function CreateEllipticRgnIndirect(lprc: LPRECT): HRGN; external 'GDI' index 55;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateEllipticRgnIndirect(const rc: RECT): HRGN; external 'GDI' index 55;
{$endif}
function CreateEllipticRgn(nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): HRGN; external 'GDI' index 54;
function CreatePolygonRgn(lppt: LPPOINT; cPoints, fnPolyFillMode: SmallInt): HRGN; external 'GDI' index 63;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePolygonRgn(var pt; cPoints, fnPolyFillMode: SmallInt): HRGN; external 'GDI' index 63;
{$endif}
function CreatePolyPolygonRgn(lppt: LPPOINT; lpnPolyCount: LPINT; cIntegers, fnPolyFillMode: SmallInt): HRGN; external 'GDI' index 451;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePolyPolygonRgn(var pt; var nPolyCount; cIntegers, fnPolyFillMode: SmallInt): HRGN; external 'GDI' index 451;
{$endif}
function CreateRoundRectRgn(nLeftRect, nTopRect, nRightRect, nBottomRect, nWidthEllipse, nHeightEllipse: SmallInt): HRGN; external 'GDI' index 444;

procedure SetRectRgn(hrgn: HRGN; nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt); external 'GDI' index 172;

function CombineRgn(hrgnDest, hrgnSrc1, hrgnSrc2: HRGN; fCombineMode: SmallInt): SmallInt; external 'GDI' index 47;

function EqualRgn(hrgnSrc1, hrgnSrc2: HRGN): BOOL; external 'GDI' index 72;
function OffsetRgn(hrgn: HRGN; nXOffset, nYOffset: SmallInt): SmallInt; external 'GDI' index 101;

function GetRgnBox(hrgn: HRGN; lprc: LPRECT): SmallInt; external 'GDI' index 134;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetRgnBox(hrgn: HRGN; var rc: RECT): SmallInt; external 'GDI' index 134;
{$endif}

function RectInRegion(hrgn: HRGN; lprc: LPRECT): BOOL; external 'GDI' index 466;
{$ifdef VAR_PARAMS_ARE_FAR}
function RectInRegion(hrgn: HRGN; const rc: RECT): BOOL; external 'GDI' index 466;
{$endif}
function PtInRegion(hrgn: HRGN; nXPos, nYPos: SmallInt): BOOL; external 'GDI' index 161;

{ Color palette Support }

function PALETTERGB(cRed, cGreen, cBlue: BYTE): COLORREF; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}
function PALETTEINDEX(wPaletteIndex: WORD): COLORREF; {$ifdef SYSTEMUNIT}forward;{$else}inline;{$endif}

function CreatePalette(lplgpl: LPLOGPALETTE): HPALETTE; external 'GDI' index 360;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreatePalette(var lgpl: LOGPALETTE): HPALETTE; external 'GDI' index 360;
{$endif}

function SelectPalette(hdc: HDC; hpal: HPALETTE; fPalBack: BOOL): HPALETTE; external 'USER' index 282;

function RealizePalette(hdc: HDC): UINT; external 'USER' index 283;

function UpdateColors(hdc: HDC): SmallInt; external 'GDI' index 366;
procedure AnimatePalette(hpal: HPALETTE; iStart, cEntries: UINT; lppe: LPPALETTEENTRY); external 'GDI' index 367;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure AnimatePalette(hpal: HPALETTE; iStart, cEntries: UINT; var pe); external 'GDI' index 367;
{$endif}

function SetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; lppe: LPPALETTEENTRY): UINT; external 'GDI' index 364;
function GetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; lppe: LPPALETTEENTRY): UINT; external 'GDI' index 363;
{$ifdef VAR_PARAMS_ARE_FAR}
function SetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; var pe): UINT; external 'GDI' index 364;
function GetPaletteEntries(hpal: HPALETTE; iStart, cEntries: UINT; var pe): UINT; external 'GDI' index 363;
{$endif}

function GetNearestPaletteIndex(hpal: HPALETTE; clrref: COLORREF): UINT; external 'GDI' index 370;

function ResizePalette(hpal: HPALETTE; cEntries: UINT): BOOL; external 'GDI' index 368;

function GetSystemPaletteEntries(hdc: HDC; iStart, cEntries: UINT; lppe: LPPALETTEENTRY): UINT; external 'GDI' index 375;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetSystemPaletteEntries(hdc: HDC; iStart, cEntries: UINT; var pe): UINT; external 'GDI' index 375;
{$endif}

function GetSystemPaletteUse(hdc: HDC): UINT; external 'GDI' index 374;
function SetSystemPaletteUse(hdc: HDC; fuStatic: UINT): UINT; external 'GDI' index 373;

{ Clipping support }

function SelectClipRgn(hdc: HDC; hrgn: HRGN): SmallInt; external 'GDI' index 44;
function GetClipBox(hdc: HDC; lprc: LPRECT): SmallInt; external 'GDI' index 77;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetClipBox(hdc: HDC; var rc: RECT): SmallInt; external 'GDI' index 77;
{$endif}

function IntersectClipRect(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): SmallInt; external 'GDI' index 22;
function OffsetClipRgn(hdc: HDC; nXOffset, nYOffset: SmallInt): SmallInt; external 'GDI' index 32;
function ExcludeClipRect(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): SmallInt; external 'GDI' index 21;

function PtVisible(hdc: HDC; nXPos, nYPos: SmallInt): BOOL; external 'GDI' index 103;
function RectVisible(hdc: HDC; lprc: LPRECT): BOOL; external 'GDI' index 465;
{$ifdef VAR_PARAMS_ARE_FAR}
function RectVisible(hdc: HDC; const rc: RECT): BOOL; external 'GDI' index 465;
{$endif}

{ General drawing support }

function MoveTo(hdc: HDC; x, y: SmallInt): DWORD; external 'GDI' index 20;
function GetCurrentPosition(hdc: HDC): DWORD; external 'GDI' index 78;

function LineTo(hdc: HDC; xEnd, yEnd: SmallInt): BOOL; external 'GDI' index 19;
function Polyline(hdc: HDC; lppt: LPPOINT; cPoints: SmallInt): BOOL; external 'GDI' index 37;

procedure LineDDA(nXStart, nYStart, nXEnd, nYEnd: SmallInt; lnddaprc: LINEDDAPROC; lParam: LPARAM); external 'GDI' index 100;
procedure LineDDA(nXStart, nYStart, nXEnd, nYEnd: SmallInt; lnddaprc: TFarProc; lParam: FarPointer); external 'GDI' index 100;

function Rectangle(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): BOOL; external 'GDI' index 27;
function RoundRect(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect, nEllipseWidth, nEllipseHeight: SmallInt): BOOL; external 'GDI' index 28;

function Ellipse(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect: SmallInt): BOOL; external 'GDI' index 24;
function Arc(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect, nXStartArc, nYStartArc, nXEndArc, nYEndArc: SmallInt): BOOL; external 'GDI' index 23;
function Chord(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect, nXStartLine, nYStartLine, nXEndLine, nYEndLine: SmallInt): BOOL; external 'GDI' index 348;
function Pie(hdc: HDC; nLeftRect, nTopRect, nRightRect, nBottomRect, nxStartArc, nyStartArc, nxEndArc, nyEndArc: SmallInt): BOOL; external 'GDI' index 26;

function Polygon(hdc: HDC; lppt: LPPOINT; cPoints: SmallInt): BOOL; external 'GDI' index 36;
function PolyPolygon(hdc: HDC; lppt: LPPOINT; lpnPolyCounts: LPINT; cPolygons: SmallInt): BOOL; external 'GDI' index 450;
{$ifdef VAR_PARAMS_ARE_FAR}
function Polygon(hdc: HDC; var pt; cPoints: SmallInt): BOOL; external 'GDI' index 36;
function PolyPolygon(hdc: HDC; var pt; var nPolyCounts; cPolygons: SmallInt): BOOL; external 'GDI' index 450;
{$endif}

function SetPolyFillMode(hdc: HDC; fnMode: SmallInt): SmallInt; external 'GDI' index 6;
function GetPolyFillMode(hdc: HDC): SmallInt; external 'GDI' index 84;

function FloodFill(hdc: HDC; nXStart, nYStart: SmallInt; clrref: COLORREF): BOOL; external 'GDI' index 25;
function ExtFloodFill(hdc: HDC; nXStart, nYStart: SmallInt; clrref: COLORREF; fuFillType: UINT): BOOL; external 'GDI' index 372;

function FillRgn(hdc: HDC; hrgn: HRGN; hbr: HBRUSH): BOOL; external 'GDI' index 40;
function FrameRgn(hdc: HDC; hrgn: HRGN; hbr: HBRUSH; nWidth, nHeight: SmallInt): BOOL; external 'GDI' index 41;
function InvertRgn(hdc: HDC; hrgn: HRGN): BOOL; external 'GDI' index 42;
function PaintRgn(hdc: HDC; hrgn: HRGN): BOOL; external 'GDI' index 43;

{ Rectangle output routines }
function FillRect(hdc: HDC; lprc: LPRECT; hbr: HBRUSH): SmallInt; external 'USER' index 81;
function FrameRect(hdc: HDC; lprc: LPRECT; hbr: HBRUSH): SmallInt; external 'USER' index 83;
procedure InvertRect(hdc: HDC; lprc: LPRECT); external 'USER' index 82;
{$ifdef VAR_PARAMS_ARE_FAR}
function FillRect(hdc: HDC; const rc: RECT; hbr: HBRUSH): SmallInt; external 'USER' index 81;
function FrameRect(hdc: HDC; const rc: RECT; hbr: HBRUSH): SmallInt; external 'USER' index 83;
procedure InvertRect(hdc: HDC; const rc: RECT); external 'USER' index 82;
{$endif}

procedure DrawFocusRect(hdc: HDC; lprc: LPRECT); external 'USER' index 466;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure DrawFocusRect(hdc: HDC; const rc: RECT); external 'USER' index 466;
{$endif}

{ Text support }

function TextOut(hdc: HDC; nXStart, nYStart: SmallInt; lpszString: LPCSTR; cbString: SmallInt): BOOL; external 'GDI' index 33;
function TabbedTextOut(hdc: HDC; xPosStart, yPosStart: SmallInt; lpszString: LPCSTR; cbString, cTabStops: SmallInt; lpnTabPositions: LPINT; nTabOrigin: SmallInt): LONG; external 'USER' index 196;
{$ifdef VAR_PARAMS_ARE_FAR}
function TabbedTextOut(hdc: HDC; xPosStart, yPosStart: SmallInt; lpszString: LPCSTR; cbString, cTabStops: SmallInt; var nTabPositions; nTabOrigin: SmallInt): LONG; external 'USER' index 196;
{$endif}
function ExtTextOut(hdc: HDC; nXStart, nYStart: SmallInt; fuOptions: UINT; lprc: LPRECT; lpszString: LPCSTR; cbString: UINT; lpDx: LPINT): BOOL; external 'GDI' index 351;

function GetTextExtent(hdc: HDC; lpszString: LPCSTR; cbString: SmallInt): DWORD; external 'GDI' index 91;
function GetTabbedTextExtent(hdc: HDC; lpszString: LPCSTR; cChars, cTabs: SmallInt; lpnTabs: LPINT): DWORD; external 'USER' index 197;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetTabbedTextExtent(hdc: HDC; lpszString: LPCSTR; cChars, cTabs: SmallInt; var nTabs): DWORD; external 'USER' index 197;
{$endif}

function DrawText(hdc: HDC; lpsz: LPCSTR; cb: SmallInt; lprc: LPRECT; fuFormat: UINT): SmallInt; external 'USER' index 85;
{$ifdef VAR_PARAMS_ARE_FAR}
function DrawText(hdc: HDC; lpsz: LPCSTR; cb: SmallInt; const rc: RECT; fuFormat: UINT): SmallInt; external 'USER' index 85;
{$endif}

function GrayString(hdc: HDC; hbr: HBRUSH; gsprc: GRAYSTRINGPROC; lParam: LPARAM; cch, x, y, cx, cy: SmallInt): BOOL; external 'USER' index 185;
function GrayString(hdc: HDC; hbr: HBRUSH; gsprc: TFarProc; lParam: LPARAM; cch, x, y, cx, cy: SmallInt): BOOL; external 'USER' index 185;

function GetCharWidth(hdc: HDC; uFirstChar, uLastChar: UINT; lpnWidths: LPINT): BOOL; external 'GDI' index 350;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetCharWidth(hdc: HDC; uFirstChar, uLastChar: UINT; var nWidths): BOOL; external 'GDI' index 350;
{$endif}

function SetTextColor(hdc: HDC; clrref: COLORREF): COLORREF; external 'GDI' index 9;
function GetTextColor(hdc: HDC): COLORREF; external 'GDI' index 90;

function SetBkColor(hdc: HDC; clrref: COLORREF): COLORREF; external 'GDI' index 1;
function GetBkColor(hdc: HDC): COLORREF; external 'GDI' index 75;

function SetBkMode(hdc: HDC; fnBkMode: SmallInt): SmallInt; external 'GDI' index 2;
function GetBkMode(hdc: HDC): SmallInt; external 'GDI' index 76;

function SetTextAlign(hdc: HDC; fuAlign: UINT): UINT; external 'GDI' index 346;
function GetTextAlign(hdc: HDC): UINT; external 'GDI' index 345;

function SetTextCharacterExtra(hdc: HDC; nExtraSpace: SmallInt): SmallInt; external 'GDI' index 8;
function GetTextCharacterExtra(hdc: HDC): SmallInt; external 'GDI' index 89;

function SetTextJustification(hdc: HDC; nExtraSpace, cBreakChars: SmallInt): SmallInt; external 'GDI' index 10;

{ Font support }

function CreateFont(nHeight, nWidth, nEscapement, nOrientation, fnWeight: SmallInt;
                    fbItalic, fbUnderline, fbStrikeOut, fbCharSet,
                    fbOutputPrecision, fbClipPrecision, fbQuality, fbPitchAndFamily: BYTE; lpszFace: LPCSTR): HFONT; external 'GDI' index 56;
function CreateFontIndirect(lplf: LPLOGFONT): HFONT; external 'GDI' index 57;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateFontIndirect(var lf: LOGFONT): HFONT; external 'GDI' index 57;
{$endif}

function SetMapperFlags(hdc: HDC; fdwMatch: DWORD): DWORD; external 'GDI' index 349;

function AddFontResource(lpszFilename: LPCSTR): SmallInt; external 'GDI' index 119;
function RemoveFontResource(lpszFile: LPCSTR): BOOL; external 'GDI' index 136;

function GetTextFace(hdc: HDC; cbBuffer: SmallInt; lpszFace: LPSTR): SmallInt; external 'GDI' index 92;

function GetAspectRatioFilter(hdc: HDC): DWORD; external 'GDI';

function GetTextMetrics(hdc: HDC; lptm: LPTEXTMETRIC): BOOL; external 'GDI' index 93;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetTextMetrics(hdc: HDC; var tm: TEXTMETRIC): BOOL; external 'GDI' index 93;
{$endif}

function EnumFonts(hdc: HDC; lpszFace: LPCSTR; fntenmprc: OLDFONTENUMPROC; lParam: LPARAM): SmallInt; external 'GDI' index 70;
function EnumFonts(hdc: HDC; lpszFace: LPCSTR; fntenmprc: TFarProc; lParam: LPARAM): SmallInt; external 'GDI' index 70;

{ Bitmap support }

function CreateBitmap(nWidth, nHeight: SmallInt; cbPlanes, cbBits: UINT; lpvBits: FarPointer): HBITMAP; external 'GDI' index 48;
function CreateBitmapIndirect(lpbm: LPBITMAP): HBITMAP; external 'GDI' index 49;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateBitmapIndirect(var bm: BITMAP): HBITMAP; external 'GDI' index 49;
{$endif}
function CreateCompatibleBitmap(hdc: HDC; nWidth, nHeight: SmallInt): HBITMAP; external 'GDI' index 51;
function CreateDiscardableBitmap(hdc: HDC; nWidth, nHeight: SmallInt): HBITMAP; external 'GDI' index 156;
function CreateDIBitmap(hdc: HDC; lpbmih: LPBITMAPINFOHEADER; dwInit: DWORD; lpvBits: FarPointer; lpbmi: LPBITMAPINFO; fnColorUse: UINT): HBITMAP; external 'GDI' index 442;
{$ifdef VAR_PARAMS_ARE_FAR}
function CreateDIBitmap(hdc: HDC; var bmih: BITMAPINFOHEADER; dwInit: DWORD; lpvBits: FarPointer; var bmi: BITMAPINFO; fnColorUse: UINT): HBITMAP; external 'GDI' index 442;
{$endif}

function LoadBitmap(hinst: HINST; lpszBitmap: LPCSTR): HBITMAP; external 'USER' index 175;

function BitBlt(hdcDest: HDC; nXDest, nYDest, nWidth, nHeight: SmallInt; hdcSrc: HDC; nXSrc, nYSrc: SmallInt; dwRop: DWORD): BOOL; external 'GDI' index 34;

function PatBlt(hdc: HDC; nLeftRect, nTopRect, nwidth, nheight: SmallInt; fdwRop: DWORD): BOOL; external 'GDI' index 29;

function StretchBlt(hdcDest: HDC; nXOriginDest, nYOriginDest, nWidthDest, nHeightDest: SmallInt; hdcSrc: HDC; nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc: SmallInt; fdwRop: DWORD): BOOL; external 'GDI' index 35;
function StretchDIBits(hdc: HDC; XDest, YDest, cxDest, cyDest, XSrc, YSrc, cxSrc, cySrc: SmallInt;
                       lpvBits: FarPointer; lpbmi: LPBITMAPINFO; fuColorUse: UINT; fdwRop: DWORD): SmallInt; external 'GDI' index 439;
{$ifdef VAR_PARAMS_ARE_FAR}
function StretchDIBits(hdc: HDC; XDest, YDest, cxDest, cyDest, XSrc, YSrc, cxSrc, cySrc: SmallInt;
                       lpvBits: FarPointer; var bmi: BITMAPINFO; fuColorUse: UINT; fdwRop: DWORD): SmallInt; external 'GDI' index 439;
{$endif}

function SetPixel(hdc: HDC; nXPos, nYPos: SmallInt; clrref: COLORREF): COLORREF; external 'GDI' index 31;
function GetPixel(hdc: HDC; nXPos, nYPos: SmallInt): COLORREF; external 'GDI' index 83;

function SetStretchBltMode(hdc: HDC; fnStretchMode: SmallInt): SmallInt; external 'GDI' index 7;
function GetStretchBltMode(hdc: HDC): SmallInt; external 'GDI' index 88;

function SetBitmapDimension(hbmp: HBITMAP; nWidth, nHeight: SmallInt): DWORD; external 'GDI' index 163;
function GetBitmapDimension(hbm: HBITMAP): DWORD; external 'GDI' index 162;

function SetROP2(hdc: HDC; fnDrawMode: SmallInt): SmallInt; external 'GDI' index 4;
function GetROP2(hdc: HDC): SmallInt; external 'GDI' index 85;

function SetBitmapBits(hbmp: HBITMAP; cBits: DWORD; lpvBits: FarPointer): LONG; external 'GDI' index 106;
function GetBitmapBits(hbm: HBITMAP; cbBuffer: LONG; lpvBits: FarPointer): LONG; external 'GDI' index 74;

function SetDIBits(hdc: HDC; hbmp: HBITMAP; uStartScan, cScanLines: UINT; lpvBits: FarPointer; lpbmi: LPBITMAPINFO; fuColorUse: UINT): SmallInt; external 'GDI' index 440;
function GetDIBits(hdc: HDC; hbmp: HBITMAP; nStartScan, cScanLines: UINT; lpvBits: FarPointer; lpbmi: LPBITMAPINFO; fuColorUse: UINT): SmallInt; external 'GDI' index 441;
{$ifdef VAR_PARAMS_ARE_FAR}
function SetDIBits(hdc: HDC; hbmp: HBITMAP; uStartScan, cScanLines: UINT; lpvBits: FarPointer; var bmi: BITMAPINFO; fuColorUse: UINT): SmallInt; external 'GDI' index 440;
function GetDIBits(hdc: HDC; hbmp: HBITMAP; nStartScan, cScanLines: UINT; lpvBits: FarPointer; var bmi: BITMAPINFO; fuColorUse: UINT): SmallInt; external 'GDI' index 441;
{$endif}

function SetDIBitsToDevice(hdc: HDC; XDest, YDest, cx, cy, XSrc, YSrc: SmallInt; uStartScan, cScanLines: UINT;
                    lpvBits: FarPointer; lpbmi: LPBITMAPINFO; fuColorUse: UINT): SmallInt; external 'GDI' index 443;
{$ifdef VAR_PARAMS_ARE_FAR}
function SetDIBitsToDevice(hdc: HDC; XDest, YDest, cx, cy, XSrc, YSrc: SmallInt; uStartScan, cScanLines: UINT;
                    lpvBits: FarPointer; var bmi: BITMAPINFO; fuColorUse: UINT): SmallInt; external 'GDI' index 443;
{$endif}

{ Metafile support }

function CreateMetaFile(lpszFile: LPCSTR): HDC; external 'GDI' index 125;
function CloseMetaFile(hdc: HDC): HMETAFILE; external 'GDI' index 126;

function GetMetaFile(lpszFile: LPCSTR): HMETAFILE; external 'GDI' index 124;
function DeleteMetaFile(hmf: HMETAFILE): BOOL; external 'GDI' index 127;
function CopyMetaFile(hmfSrc: HMETAFILE; lpszFile: LPCSTR): HMETAFILE; external 'GDI' index 151;

function PlayMetaFile(hdc: HDC; hmf: HMETAFILE): BOOL; external 'GDI' index 123;

function GetMetaFileBits(hmf: HMETAFILE): HGLOBAL; external 'GDI' index 159;
function SetMetaFileBits(hmf: HGLOBAL): HMETAFILE; external 'GDI' index 160;

procedure PlayMetaFileRecord(hdc: HDC; lpht: LPHANDLETABLE; lpmr: LPMETARECORD; cHandles: UINT); external 'GDI' index 176;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure PlayMetaFileRecord(hdc: HDC; var ht: HANDLETABLE; var mr: METARECORD; cHandles: UINT); external 'GDI' index 176;
{$endif}

function EnumMetaFile(hdc: HDC; hmf: HMETAFILE; mfenmprc: MFENUMPROC; lParam: LPARAM): BOOL; external 'GDI' index 175;
function EnumMetaFile(hdc: HDC; hmf: HMETAFILE; mfenmprc: TFarProc; lParam: LPARAM): BOOL; external 'GDI' index 175;

{ Printing support }

function QueryAbort(hdc: HDC; reserved: SmallInt): BOOL; external 'GDI' index 155;

{ GDI Escape support }

function Escape(hdc: HDC; nEscape, cbInput: SmallInt; lpszInData: LPCSTR; lpvOutData: FarPointer): SmallInt; external 'GDI' index 38;

{ System Metrics }

function GetSystemMetrics(nIndex: SmallInt): SmallInt; external 'USER' index 179;
function GetFreeSystemResources(SysResource: UINT): UINT; external 'USER' index 284;

function GetDoubleClickTime: UINT; external 'USER' index 21;
procedure SetDoubleClickTime(uInterval: UINT); external 'USER' index 20;

{ Rectangle support }

procedure SetRect(lprc: LPRECT; nLeft, nTop, nRight, nBottom: SmallInt); external 'USER' index 72;
procedure SetRectEmpty(lprc: LPRECT); external 'USER' index 73;

procedure CopyRect(lprcDst: LPRECT; lprcSrc: LPRECT); external 'USER' index 74;

function IsRectEmpty(lprc: LPRECT): BOOL; external 'USER' index 75;

function EqualRect(lprc1, lprc2: LPRECT): BOOL; external 'USER' index 244;

function IntersectRect(lprcDest: LPRECT; lprcSrc1, lprcSrc2: LPRECT): SmallInt; external 'USER' index 79;
function UnionRect(lprcDest: LPRECT; lprcSrc1, lprcSrc2: LPRECT): SmallInt; external 'USER' index 80;

procedure OffsetRect(lprc: LPRECT; x, y: SmallInt); external 'USER' index 77;
procedure InflateRect(lprc: LPRECT; xAmt, yAmt: SmallInt); external 'USER' index 78;

function PtInRect(lprc: LPRECT; pt: POINT): BOOL; external 'USER' index 76;

{$ifdef VAR_PARAMS_ARE_FAR}
procedure SetRect(var rc: RECT; nLeft, nTop, nRight, nBottom: SmallInt); external 'USER' index 72;
procedure SetRectEmpty(var rc: RECT); external 'USER' index 73;

procedure CopyRect(var rcDst: RECT; const rcSrc: RECT); external 'USER' index 74;

function IsRectEmpty(const rc: RECT): BOOL; external 'USER' index 75;

function EqualRect(const rc1, rc2: RECT): BOOL; external 'USER' index 244;

function IntersectRect(var rcDest: RECT; const rcSrc1, rcSrc2: RECT): SmallInt; external 'USER' index 79;
function UnionRect(var rcDest: RECT; const rcSrc1, rcSrc2: RECT): SmallInt; external 'USER' index 80;

procedure OffsetRect(var rc: RECT; x, y: SmallInt); external 'USER' index 77;
procedure InflateRect(var rc: RECT; xAmt, yAmt: SmallInt); external 'USER' index 78;

function PtInRect(const rc: RECT; pt: POINT): BOOL; external 'USER' index 76;
{$endif}

{ Window message support }

function RegisterWindowMessage(lpsz: LPCSTR): UINT; external 'USER' index 118;

function GetMessage(lpmsg: LPMSG; hwnd: HWND; uMsgFilterMin, uMsgFilterMax: UINT): BOOL; external 'USER' index 108;
function PeekMessage(lpmsg: LPMSG; hwnd: HWND; uFilterFirst, uFilterLast, fuRemove: UINT): BOOL; external 'USER' index 109;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetMessage(var msg: MSG; hwnd: HWND; uMsgFilterMin, uMsgFilterMax: UINT): BOOL; external 'USER' index 108;
function PeekMessage(var msg: MSG; hwnd: HWND; uFilterFirst, uFilterLast, fuRemove: UINT): BOOL; external 'USER' index 109;
{$endif}

procedure WaitMessage; external 'USER' index 112;

function GetMessagePos: DWORD; external 'USER' index 119;
function GetMessageTime: LONG; external 'USER' index 120;

function TranslateMessage(lpmsg: LPMSG): BOOL; external 'USER' index 113;
function DispatchMessage(lpmsg: LPMSG): LONG; external 'USER' index 114;
{$ifdef VAR_PARAMS_ARE_FAR}
function TranslateMessage(var msg: MSG): BOOL; external 'USER' index 113;
function DispatchMessage(var msg: MSG): LONG; external 'USER' index 114;
{$endif}

function SetMessageQueue(cMsg: SmallInt): BOOL; external 'USER' index 266;

function GetInputState: BOOL; external 'USER' index 335;

function PostMessage(hwnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): BOOL; external 'USER' index 110;
function SendMessage(hwnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 111;

function PostAppMessage(htask: HTASK; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): BOOL; external 'USER' index 116;

procedure ReplyMessage(lResult: LRESULT); external 'USER' index 115;
function InSendMessage: BOOL; external 'USER' index 192;

function CallMsgFilter(lpmsg: LPMSG; nCode: SmallInt): BOOL; external 'USER' index 123;
{$ifdef VAR_PARAMS_ARE_FAR}
function CallMsgFilter(var msg: MSG; nCode: SmallInt): BOOL; external 'USER' index 123;
{$endif}

{ Application termination }

procedure PostQuitMessage(nExitCode: SmallInt); external 'USER' index 6;

{ Window class management }

{ in Windows 3.1+, RegisterClass returns an ATOM that uniquely identifies the
  class. In Windows 3.0 and earlier, the return value is BOOL. That's why we
  redefine this function in the win31 unit. }
function RegisterClass(lpwc: LPWNDCLASS): BOOL; external 'USER' index 57;
{$ifdef VAR_PARAMS_ARE_FAR}
function RegisterClass(var wc: WNDCLASS): BOOL; external 'USER' index 57;
{$endif}
function UnregisterClass(lpszClassName: LPCSTR; hinst: HINST): BOOL; external 'USER' index 403;

function GetClassInfo(hinst: HINST; lpszClassName: LPCSTR; lpwc: LPWNDCLASS): BOOL; external 'USER' index 404;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetClassInfo(hinst: HINST; lpszClassName: LPCSTR; var wc: WNDCLASS): BOOL; external 'USER' index 404;
{$endif}
function GetClassName(hwnd: HWND; lpszClassName: LPSTR; cchClassName: SmallInt): SmallInt; external 'USER' index 58;

function GetClassWord(hwnd: HWND; offset: SmallInt): WORD; external 'USER' index 129;
function SetClassWord(hwnd: HWND; nIndex: SmallInt; wNewWord: WORD): WORD; external 'USER' index 130;
function GetClassLong(hwnd: HWND; offset: SmallInt): LONG; external 'USER' index 131;
function SetClassLong(hwnd: HWND; nIndex: SmallInt; nVal: LONG): LONG; external 'USER' index 132;

{ Window creation/destroy }

function IsWindow(hwnd: HWND): BOOL; external 'USER' index 47;

function CreateWindowEx(dwExStyle: DWORD; lpszClassName, lpszWindowName: LPCSTR; dwStyle: DWORD; x, y, nWidth, nHeight: SmallInt; hwndParent: HWND; hmenu: HMENU; hinst: HINST; lpvCreateParams: FarPointer): HWND; external 'USER' index 452;
function CreateWindow(lpszClassName, lpszWindowName: LPCSTR; dwStyle: DWORD; x, y, nWidth, nHeight: SmallInt; hwndParent: HWND; hmenu: HMENU; hinst: HINST; lpvParam: FarPointer): HWND; external 'USER' index 41;

function DestroyWindow(hwnd: HWND): BOOL; external 'USER' index 53;

{ Basic window attributes }

function GetWindowTask(hwnd: HWND): HTASK; external 'USER' index 224;

function IsChild(hwndParent, hwndChild: HWND): BOOL; external 'USER' index 48;

function GetParent(hwnd: HWND): HWND; external 'USER' index 46;
function SetParent(hwndChild, hwndNewParent: HWND): HWND; external 'USER' index 233;

function IsWindowVisible(hwnd: HWND): BOOL; external 'USER' index 49;

function ShowWindow(hwnd: HWND; nCmdShow: SmallInt): BOOL; external 'USER' index 42;

{ Enabled state }
function EnableWindow(hwnd: HWND; fEnable: BOOL): BOOL; external 'USER' index 34;
function IsWindowEnabled(hwnd: HWND): BOOL; external 'USER' index 35;

{ Window text }
procedure SetWindowText(hwnd: HWND; lpsz: LPCSTR); external 'USER' index 37;
function GetWindowText(hwnd: HWND; lpsz: LPSTR; cbMax: SmallInt): SmallInt; external 'USER' index 36;
function GetWindowTextLength(hwnd: HWND): SmallInt; external 'USER' index 38;

{ Window words }
function GetWindowWord(hwnd: HWND; nOffset: SmallInt): WORD; external 'USER' index 133;
function SetWindowWord(hwnd: HWND; nOffset: SmallInt; nVal: WORD): WORD; external 'USER' index 134;
function GetWindowLong(hwnd: HWND; nOffset: SmallInt): LONG; external 'USER' index 135;
function SetWindowLong(hwnd: HWND; nOffset: SmallInt; nVal: LONG): LONG; external 'USER' index 136;

{ Window size, position, Z-order, and visibility }

procedure GetClientRect(hwnd: HWND; lprc: LPRECT); external 'USER' index 33;
procedure GetWindowRect(hwnd: HWND; lprc: LPRECT); external 'USER' index 32;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure GetClientRect(hwnd: HWND; var rc: RECT); external 'USER' index 33;
procedure GetWindowRect(hwnd: HWND; var rc: RECT); external 'USER' index 32;
{$endif}

function SetWindowPos(hwnd, hwndInsertAfter: HWND; x, y, cx, cy: SmallInt; fuFlags: UINT): BOOL; external 'USER' index 232;

function BeginDeferWindowPos(cWindows: SmallInt): HDWP; external 'USER' index 259;
function DeferWindowPos(hdwp: HDWP; hwnd, hwndInsertAfter: HWND; x, y, cx, cy: SmallInt; flags: UINT): HDWP; external 'USER' index 260;
function EndDeferWindowPos(hdwp: HDWP): BOOL; external 'USER' index 261;

function MoveWindow(hwnd: HWND; nLeft, nTop, nWidth, nHeight: SmallInt; fRepaint: BOOL): BOOL; external 'USER' index 56;
function BringWindowToTop(hwnd: HWND): BOOL; external 'USER' index 45;

{ Window proc implementation & subclassing support }

function DefWindowProc(hwnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 107;

function CallWindowProc(wndprcPrev: WNDPROC; hwnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 122;
function CallWindowProc(wndprcPrev: TFarProc; hwnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 122;

{ Main window support }

procedure AdjustWindowRect(lprc: LPRECT; dwStyle: DWORD; fMenu: BOOL); external 'USER' index 102;
procedure AdjustWindowRectEx(lprc: LPRECT; dwStyle: DWORD; fMenu: BOOL; dwExStyle: DWORD); external 'USER' index 454;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure AdjustWindowRect(var rc: RECT; dwStyle: DWORD; fMenu: BOOL); external 'USER' index 102;
procedure AdjustWindowRectEx(var rc: RECT; dwStyle: DWORD; fMenu: BOOL; dwExStyle: DWORD); external 'USER' index 454;
{$endif}

function FlashWindow(hwnd: HWND; fInvert: BOOL): BOOL; external 'USER' index 105;

procedure ShowOwnedPopups(hwnd: HWND; fShow: BOOL); external 'USER' index 265;

{ Obsolete functions }
function OpenIcon(hwnd: HWND): BOOL; external 'USER' index 44;
procedure CloseWindow(hwnd: HWND); external 'USER' index 43;
function AnyPopup: BOOL; external 'USER' index 52;
function IsIconic(hwnd: HWND): BOOL; external 'USER' index 31;
function IsZoomed(hwnd: HWND): BOOL; external 'USER' index 272;

{ Window coordinate mapping and hit-testing }

procedure ClientToScreen(hwnd: HWND; lppt: LPPOINT); external 'USER' index 28;
procedure ScreenToClient(hwnd: HWND; lppt: LPPOINT); external 'USER' index 29;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure ClientToScreen(hwnd: HWND; var pt: POINT); external 'USER' index 28;
procedure ScreenToClient(hwnd: HWND; var pt: POINT); external 'USER' index 29;
{$endif}

function WindowFromPoint(pt: POINT): HWND; external 'USER' index 30;
function ChildWindowFromPoint(hwndParent: HWND; pt: POINT): HWND; external 'USER' index 191;

{ Window query and enumeration }

function GetDesktopWindow: HWND; external 'USER' index 286;

function FindWindow(lpszClassName, lpszWindow: LPCSTR): HWND; external 'USER' index 50;

function EnumWindows(wndenmprc: WNDENUMPROC; lParam: LPARAM): BOOL; external 'USER' index 54;
function EnumWindows(wndenmprc: TFarProc; lParam: LPARAM): BOOL; external 'USER' index 54;
function EnumChildWindows(hwndParent: HWND; wndenmprc: WNDENUMPROC; lParam: LPARAM): BOOL; external 'USER' index 55;
function EnumChildWindows(hwndParent: HWND; wndenmprc: TFarProc; lParam: LPARAM): BOOL; external 'USER' index 55;
function EnumTaskWindows(htask: HTASK; wndenmprc: WNDENUMPROC; lParam: LPARAM): BOOL; external 'USER' index 225;
function EnumTaskWindows(htask: HTASK; wndenmprc: TFarProc; lParam: LPARAM): BOOL; external 'USER' index 225;

function GetTopWindow(hwnd: HWND): HWND; external 'USER' index 229;

function GetWindow(hwnd: HWND; fuRel: UINT): HWND; external 'USER' index 262;
function GetNextWindow(hwnd: HWND; uFlag: UINT): HWND; external 'USER' index 230;

{ Window property support }

function SetProp(hwnd: HWND; lpsz: LPCSTR; hData: HANDLE): BOOL; external 'USER' index 26;
function GetProp(hwnd: HWND; lpsz: LPCSTR): HANDLE; external 'USER' index 25;
function RemoveProp(hwnd: HWND; lpsz: LPCSTR): HANDLE; external 'USER' index 24;

function EnumProps(hwnd: HWND; prpenmprc: PROPENUMPROC): SmallInt; external 'USER' index 27;
function EnumProps(hwnd: HWND; prpenmprc: TFarProc): SmallInt; external 'USER' index 27;

{ Window drawing support }

function GetDC(hwnd: HWND): HDC; external 'USER' index 66;
function ReleaseDC(hwnd: HWND; hdc: HDC): SmallInt; external 'USER' index 68;

function GetWindowDC(hwnd: HWND): HDC; external 'USER' index 67;

{ Window repainting }

function BeginPaint(hwnd: HWND; lpps: LPPAINTSTRUCT): HDC; external 'USER' index 39;
procedure EndPaint(hwnd: HWND; lpps: LPPAINTSTRUCT); external 'USER' index 40;
{$ifdef VAR_PARAMS_ARE_FAR}
function BeginPaint(hwnd: HWND; var ps: PAINTSTRUCT): HDC; external 'USER' index 39;
procedure EndPaint(hwnd: HWND; var ps: PAINTSTRUCT); external 'USER' index 40;
{$endif}

procedure UpdateWindow(hwnd: HWND); external 'USER' index 124;

function ExcludeUpdateRgn(hdc: HDC; hwnd: HWND): SmallInt; external 'USER' index 238;

function GetUpdateRect(hwnd: HWND; lprc: LPRECT; fErase: BOOL): BOOL; external 'USER' index 190;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetUpdateRect(hwnd: HWND; var rc: RECT; fErase: BOOL): BOOL; external 'USER' index 190;
{$endif}
function GetUpdateRgn(hwnd: HWND; hrgn: HRGN; fErase: BOOL): SmallInt; external 'USER' index 237;

procedure InvalidateRect(hwnd: HWND; lprc: LPRECT; fErase: BOOL); external 'USER' index 125;
procedure ValidateRect(hwnd: HWND; lprc: LPRECT); external 'USER' index 127;
function RedrawWindow(hwnd: HWND; lprcUpdate: LPRECT; hrgnUpdate: HRGN; flags: UINT): BOOL; external 'USER' index 290;
function LockWindowUpdate(hwndLock: HWND): BOOL; external 'USER' index 294;

procedure InvalidateRgn(hwnd: HWND; hrgn: HRGN; fErase: BOOL); external 'USER' index 126;
procedure ValidateRgn(hwnd: HWND; hrgn: HRGN); external 'USER' index 128;

{ Window scrolling }

procedure ScrollWindow(hwnd: HWND; dx, dy: SmallInt; lprcScroll, lprcClip: LPRECT); external 'USER' index 61;
function ScrollDC(hdc: HDC; dx, dy: SmallInt; lprcScroll, lprcClip: LPRECT; hrgnUpdate: HRGN; lprcUpdate: LPRECT): BOOL; external 'USER' index 221;
{$ifdef VAR_PARAMS_ARE_FAR}
function ScrollDC(hdc: HDC; dx, dy: SmallInt; var rcScroll, rcClip: RECT; hrgnUpdate: HRGN; lprcUpdate: LPRECT): BOOL; external 'USER' index 221;
{$endif}

{ Window activation }

function SetActiveWindow(hwnd: HWND): HWND; external 'USER' index 59;
function GetActiveWindow: HWND; external 'USER' index 60;

function GetLastActivePopup(hwndOwner: HWND): HWND; external 'USER' index 287;

{ Keyboard input support }

function SetFocus(hwnd: HWND): HWND; external 'USER' index 22;
function GetFocus: HWND; external 'USER' index 23;

function GetKeyState(vkey: SmallInt): SmallInt; external 'USER' index 106;
function GetAsyncKeyState(vkey: SmallInt): SmallInt; external 'USER' index 249;

procedure GetKeyboardState(lpbKeyState: LPBYTE); external 'USER' index 222;
procedure SetKeyboardState(lpbKeyState: LPBYTE); external 'USER' index 223;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure GetKeyboardState(var bKeyState: TKeyboardState); external 'USER' index 222;
procedure SetKeyboardState(var bKeyState: TKeyboardState); external 'USER' index 223;
{$endif}

{ Mouse input support }

function SetCapture(hwnd: HWND): HWND; external 'USER' index 18;
procedure ReleaseCapture; external 'USER' index 19;
function GetCapture: HWND; external 'USER' index 236;

function SwapMouseButton(fSwap: BOOL): BOOL; external 'USER' index 186;

{ System modal window support }

function GetSysModalWindow: HWND; external 'USER' index 189;
function SetSysModalWindow(hwnd: HWND): HWND; external 'USER' index 188;

{ Timer support }
function SetTimer(hwnd: HWND; idTimer, uTimeout: UINT; tmprc: TIMERPROC): UINT; external 'USER' index 10;
function SetTimer(hwnd: HWND; idTimer, uTimeout: UINT; tmprc: TFarProc): UINT; external 'USER' index 10;
function KillTimer(hwnd: HWND; idTimer: UINT): BOOL; external 'USER' index 12;

{ Accelerator support }
function LoadAccelerators(hinst: HINST; lpszTableName: LPCSTR): HACCEL; external 'USER' index 177;
function TranslateAccelerator(hwnd: HWND; haccl: HACCEL; lpmsg: LPMSG): SmallInt; external 'USER' index 178;
{$ifdef VAR_PARAMS_ARE_FAR}
function TranslateAccelerator(hwnd: HWND; haccl: HACCEL; var msg: MSG): SmallInt; external 'USER' index 178;
{$endif}

{ Menu support }

function CreateMenu: HMENU; external 'USER' index 151;
function CreatePopupMenu: HMENU; external 'USER' index 415;
function LoadMenu(hinst: HINST; lpszMenuName: LPCSTR): HMENU; external 'USER' index 150;
function LoadMenuIndirect(lpmith: LPVOID): HMENU; external 'USER' index 220;

function DestroyMenu(hmenu: HMENU): BOOL; external 'USER' index 152;

function GetMenu(hwnd: HWND): HMENU; external 'USER' index 157;
function SetMenu(hwnd: HWND; hmenu: HMENU): BOOL; external 'USER' index 158;

function GetSystemMenu(hwnd: HWND; fRevert: BOOL): HMENU; external 'USER' index 156;

procedure DrawMenuBar(hwnd: HWND); external 'USER' index 160;

function HiliteMenuItem(hwnd: HWND; hmenu: HMENU; idHiliteItem, fuHilite: UINT): BOOL; external 'USER' index 162;

function InsertMenu(hmenu: HMENU; idItem, fuFlags, idNewItem: UINT; lpNewItem: LPCSTR): BOOL; external 'USER' index 410;
function AppendMenu(hmenu: HMENU; fuFlags, idNewItem: UINT; lpNewItem: LPCSTR): BOOL; external 'USER' index 411;
function ModifyMenu(hmenu: HMENU; idItem, fuFlags, idNewItem: UINT; lpNewItem: LPCSTR): BOOL; external 'USER' index 414;
function RemoveMenu(hmenu: HMENU; idItem, fuFlags: UINT): BOOL; external 'USER' index 412;
function DeleteMenu(hmenu: HMENU; idItem, fuFlags: UINT): BOOL; external 'USER' index 413;

function ChangeMenu(hmenu: HMENU; uPosition: UINT; lpNewItem: LPCSTR; idNewItem, fuFlags: UINT): BOOL; external 'USER' index 153;

function EnableMenuItem(hmenu: HMENU; idEnableItem, uEnable: UINT): BOOL; external 'USER' index 155;
function CheckMenuItem(hmenu: HMENU; idCheckItem, uCheck: UINT): BOOL; external 'USER' index 154;

function GetSubMenu(hmenu: HMENU; nPos: SmallInt): HMENU; external 'USER' index 159;

function GetMenuItemCount(hmenu: HMENU): SmallInt; external 'USER' index 263;
function GetMenuItemID(hmenu: HMENU; pos: SmallInt): UINT; external 'USER' index 264;

function GetMenuString(hmenu: HMENU; idItem: UINT; lpsz: LPSTR; cbMax: SmallInt; fwFlags: UINT): SmallInt; external 'USER' index 161;
function GetMenuState(hmenu: HMENU; idItem, fuFlags: UINT): UINT; external 'USER' index 250;

function SetMenuItemBitmaps(hmenu: HMENU; idItem, fuFlags: UINT; hbmUnchecked, hbmChecked: HBITMAP): BOOL; external 'USER' index 418;
function GetMenuCheckMarkDimensions: DWORD; external 'USER' index 417;

function TrackPopupMenu(hmenu: HMENU; fuFlags: UINT; x, y, nReserved: SmallInt; hwnd: HWND; lprc: LPRECT): BOOL; external 'USER' index 416;

{ Scroll bar support }

function SetScrollPos(hwnd: HWND; fnBar, nPos: SmallInt; fRepaint: BOOL): SmallInt; external 'USER' index 62;
function GetScrollPos(hwnd: HWND; fnBar: SmallInt): SmallInt; external 'USER' index 63;
procedure SetScrollRange(hwnd: HWND; fnBar, nMin, nMax: SmallInt; fRedraw: BOOL); external 'USER' index 64;
procedure GetScrollRange(hwnd: HWND; fnBar: SmallInt; lpnMinPos, lpnMaxPos: LPINT); external 'USER' index 65;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure GetScrollRange(hwnd: HWND; fnBar: SmallInt; var nMinPos, nMaxPos: SmallInt); external 'USER' index 65;
{$endif}
procedure ShowScrollBar(hwnd: HWND; fnBar: SmallInt; fShow: BOOL); external 'USER' index 267;

{ Clipboard manager }

{ Clipboard Manager Functions }
function OpenClipboard(hwnd: HWND): BOOL; external 'USER' index 137;
function CloseClipboard: BOOL; external 'USER' index 138;
function EmptyClipboard: BOOL; external 'USER' index 139;

function GetClipboardOwner: HWND; external 'USER' index 140;

function SetClipboardViewer(hwnd: HWND): HWND; external 'USER' index 147;
function GetClipboardViewer: HWND; external 'USER' index 148;

function SetClipboardData(uFormat: UINT; hData: HANDLE): HANDLE; external 'USER' index 141;
function GetClipboardData(uFormat: UINT): HANDLE; external 'USER' index 142;

function IsClipboardFormatAvailable(uFormat: UINT): BOOL; external 'USER' index 193;
function GetPriorityClipboardFormat(lpuPriorityList: LPUINT; cEntries: SmallInt): SmallInt; external 'USER' index 402;
{$ifdef VAR_PARAMS_ARE_FAR}
function GetPriorityClipboardFormat(var uPriorityList; cEntries: SmallInt): SmallInt; external 'USER' index 402;
{$endif}

function RegisterClipboardFormat(lpszFormatName: LPCSTR): UINT; external 'USER' index 145;
function CountClipboardFormats: SmallInt; external 'USER' index 143;
function EnumClipboardFormats(uFormat: UINT): UINT; external 'USER' index 144;
function GetClipboardFormatName(uFormat: UINT; lpszFormatName: LPSTR; cbMax: SmallInt): SmallInt; external 'USER' index 146;

function ChangeClipboardChain(hwnd, hwndNext: HWND): BOOL; external 'USER' index 149;

{ Mouse cursor support }

function LoadCursor(hinst: HINST; pszCursor: LPCSTR): HCURSOR; external 'USER' index 173;
function CopyCursor(hinst: HINST; hcur: HCURSOR): HCURSOR; external 'USER' index 369;
function CreateCursor(hinst: HINST; xHotSpot, yHotSpot, nWidth, nHeight: SmallInt; lpvANDplane, lpvXORplane: LPVOID): HCURSOR; external 'USER' index 406;
function DestroyCursor(hcur: HCURSOR): BOOL; external 'USER' index 458;

function ShowCursor(fShow: BOOL): SmallInt; external 'USER' index 71;

procedure SetCursorPos(x, y: SmallInt); external 'USER' index 70;
procedure GetCursorPos(lppt: LPPOINT); external 'USER' index 17;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure GetCursorPos(var pt: POINT); external 'USER' index 17;
{$endif}

function SetCursor(hcur: HCURSOR): HCURSOR; external 'USER' index 69;

procedure ClipCursor(lprc: LPRECT); external 'USER' index 16;

{ Icon support }

function LoadIcon(hinst: HINST; pszIcon: LPCSTR): HICON; external 'USER' index 174;
function CopyIcon(hinst: HINST; hicon: HICON): HICON; external 'USER' index 368;
function CreateIcon(hinst: HINST; nWidth, nHeight: SmallInt; bPlanes, bBitsPerPixel: BYTE; lpvANDbits, lpvXORbits: LPVOID): HICON; external 'USER' index 407;
function DestroyIcon(hicon: HICON): BOOL; external 'USER' index 457;

function DrawIcon(hdc: HDC; x, y: SmallInt; hicon: HICON): BOOL; external 'USER' index 84;

{ Message Box support }

function MessageBox(hwndParent: HWND; lpszText, lpszTitle: LPCSTR; fuStyle: UINT): SmallInt; external 'USER' index 1;
procedure MessageBeep(uAlert: UINT); external 'USER' index 104;

{ Caret support }

procedure CreateCaret(hwnd: HWND; hbmp: HBITMAP; nWidth, nHeight: SmallInt); external 'USER' index 163;
procedure DestroyCaret; external 'USER' index 164;

procedure SetCaretPos(x, y: SmallInt); external 'USER' index 165;
procedure GetCaretPos(lppt: LPPOINT); external 'USER' index 183;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure GetCaretPos(var pt: POINT); external 'USER' index 183;
{$endif}

procedure HideCaret(hwnd: HWND); external 'USER' index 166;
procedure ShowCaret(hwnd: HWND); external 'USER' index 167;

function GetCaretBlinkTime: UINT; external 'USER' index 169;
procedure SetCaretBlinkTime(uMSeconds: UINT); external 'USER' index 168;

{ MDI Support }

function DefFrameProc(hwnd, hwndMDIClient: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 445;
function DefMDIChildProc(hwnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 447;

function TranslateMDISysAccel(hwndClient: HWND; lpmsg: LPMSG): BOOL; external 'USER' index 451;
{$ifdef VAR_PARAMS_ARE_FAR}
function TranslateMDISysAccel(hwndClient: HWND; var msg: MSG): BOOL; external 'USER' index 451;
{$endif}

function ArrangeIconicWindows(hwnd: HWND): UINT; external 'USER' index 170;

{ Dialog and Control Management }

function IsDialogMessage(hwndDlg: HWND; lpmsg: LPMSG): BOOL; external 'USER' index 90;
{$ifdef VAR_PARAMS_ARE_FAR}
function IsDialogMessage(hwndDlg: HWND; var msg: MSG): BOOL; external 'USER' index 90;
{$endif}

function DefDlgProc(hwndDlg: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 308;

function CreateDialog(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: DLGPROC): HWND; external 'USER' index 89;
function CreateDialog(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: TFarProc): HWND; external 'USER' index 89;
function CreateDialogIndirect(hinst: HINST; lpvDlgTmp: FarPointer; hwndOwner: HWND; dlgprc: DLGPROC): HWND; external 'USER' index 219;
function CreateDialogIndirect(hinst: HINST; lpvDlgTmp: FarPointer; hwndOwner: HWND; dlgprc: TFarProc): HWND; external 'USER' index 219;
function CreateDialogParam(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: DLGPROC; lParamInit: LPARAM): HWND; external 'USER' index 241;
function CreateDialogParam(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: TFarProc; lParamInit: LPARAM): HWND; external 'USER' index 241;
function CreateDialogIndirectParam(hinst: HINST; lpvDlgTmp: FarPointer; hwndOwner: HWND; dlgprc: DLGPROC; lParamInit: LPARAM): HWND; external 'USER' index 242;
function CreateDialogIndirectParam(hinst: HINST; lpvDlgTmp: FarPointer; hwndOwner: HWND; dlgprc: TFarProc; lParamInit: LPARAM): HWND; external 'USER' index 242;

function DialogBox(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: DLGPROC): SmallInt; external 'USER' index 87;
function DialogBox(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: TFarProc): SmallInt; external 'USER' index 87;
function DialogBoxIndirect(hinst: HINST; hglbDlgTemp: HGLOBAL; hwndOwner: HWND; dlgprc: DLGPROC): SmallInt; external 'USER' index 218;
function DialogBoxIndirect(hinst: HINST; hglbDlgTemp: HGLOBAL; hwndOwner: HWND; dlgprc: TFarProc): SmallInt; external 'USER' index 218;
function DialogBoxParam(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: DLGPROC; lParamInit: LPARAM): SmallInt; external 'USER' index 239;
function DialogBoxParam(hinst: HINST; lpszDlgTemp: LPCSTR; hwndOwner: HWND; dlgprc: TFarProc; lParamInit: LPARAM): SmallInt; external 'USER' index 239;
function DialogBoxIndirectParam(hinst: HINST; hglbDlgTemp: HGLOBAL; hwndOwner: HWND; dlgprc: DLGPROC; lParamInit: LPARAM): SmallInt; external 'USER' index 240;
function DialogBoxIndirectParam(hinst: HINST; hglbDlgTemp: HGLOBAL; hwndOwner: HWND; dlgprc: TFarProc; lParamInit: LPARAM): SmallInt; external 'USER' index 240;

procedure EndDialog(hwndDlg: HWND; nResult: SmallInt); external 'USER' index 88;

function GetDlgCtrlID(hwnd: HWND): SmallInt; external 'USER' index 277;
function GetDlgItem(hwndDlg: HWND; idControl: SmallInt): HWND; external 'USER' index 91;
function SendDlgItemMessage(hwndDlg: HWND; idDlgItem: SmallInt; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT; external 'USER' index 101;

procedure SetDlgItemInt(hwndDlg: HWND; idControl: SmallInt; uValue: UINT; fSigned: BOOL); external 'USER' index 94;
function GetDlgItemInt(hwndDlg: HWND; idControl: SmallInt; lpfTranslated: LPBOOL; fSigned: BOOL): UINT; external 'USER' index 95;

procedure SetDlgItemText(hwndDlg: HWND; idControl: SmallInt; lpsz: LPCSTR); external 'USER' index 92;
function GetDlgItemText(hwndDlg: HWND; idControl: SmallInt; lpsz: LPSTR; cbMax: SmallInt): SmallInt; external 'USER' index 93;

procedure CheckDlgButton(hwndDlg: HWND; idButton: SmallInt; uCheck: UINT); external 'USER' index 97;
procedure CheckRadioButton(hwndDlg: HWND; idFirstButton, idLastButton, idCheckButton: SmallInt); external 'USER' index 96;
function IsDlgButtonChecked(hwndDlg: HWND; idButton: SmallInt): UINT; external 'USER' index 98;

function GetNextDlgGroupItem(hwndDlg, hwndCtrl: HWND; fPrevious: BOOL): HWND; external 'USER' index 227;
function GetNextDlgTabItem(hwndDlg, hwndCtrl: HWND; fPrevious: BOOL): HWND; external 'USER' index 228;

procedure MapDialogRect(hwndDlg: HWND; lprc: LPRECT); external 'USER' index 103;
{$ifdef VAR_PARAMS_ARE_FAR}
procedure MapDialogRect(hwndDlg: HWND; var rc: RECT); external 'USER' index 103;
{$endif}
function GetDialogBaseUnits: DWORD; external 'USER' index 243;

{ Dialog directory support }

function DlgDirList(hwndDlg: HWND; lpszPath: LPSTR; idListBox, idStaticPath: SmallInt; uFileType: UINT): SmallInt; external 'USER' index 100;
function DlgDirSelect(hwndDlg: HWND; lpszPath: LPSTR; idListBox: SmallInt): BOOL; external 'USER' index 99;

function DlgDirListComboBox(hwndDlg: HWND; lpszPath: LPSTR; idComboBox, idStaticPath: SmallInt; uFileType: UINT): SmallInt; external 'USER' index 195;
function DlgDirSelectComboBox(hwndDlg: HWND; lpszPath: LPSTR; idComboBox: SmallInt): BOOL; external 'USER' index 194;

{ Windows hook support }

function SetWindowsHook(idHook: SmallInt; hkprc: HOOKPROC): HHOOK; external 'USER' index 121;
function SetWindowsHook(idHook: SmallInt; hkprc: TFarProc): TFarProc; external 'USER' index 121;
function DefHookProc(nCode: SmallInt; uParam: WPARAM; dwParam: LPARAM; lphhook: LPHHOOK): LRESULT; external 'USER' index 235;
function DefHookProc(nCode: SmallInt; uParam: WPARAM; dwParam: LPARAM; lphhook: TFarProc): LRESULT; external 'USER' index 235;
function UnhookWindowsHook(idHook: SmallInt; hkprc: HOOKPROC): BOOL; external 'USER' index 234;
function UnhookWindowsHook(idHook: SmallInt; hkprc: TFarProc): BOOL; external 'USER' index 234;

{ Journalling support }

function EnableHardwareInput(fEnableInput: BOOL): BOOL; external 'USER' index 331;

{ Help support }

function WinHelp(hwndMain: HWND; lpszHelp: LPCSTR; usCommand: UINT; ulData: DWORD): BOOL; external 'USER' index 171;

{ Sound support }

function OpenSound: SmallInt; external 'SOUND' index 1;
procedure CloseSound; external 'SOUND' index 2;

function StartSound: SmallInt; external 'SOUND' index 9;
function StopSound: SmallInt; external 'SOUND' index 10;

function SetVoiceQueueSize(nVoice, cbQueue: SmallInt): SmallInt; external 'SOUND' index 3;
function SetVoiceNote(voice, value, length, cdots: SmallInt): SmallInt; external 'SOUND' index 4;
function SetVoiceAccent(nVoice, nTempo, nVolume, fnMode, nPitch: SmallInt): SmallInt; external 'SOUND' index 5;
function SetVoiceEnvelope(nVoice, nShape, nRepeat: SmallInt): SmallInt; external 'SOUND' index 6;
function SetVoiceSound(nVoice: SmallInt; dwFrequency: DWORD; nDuration: SmallInt): SmallInt; external 'SOUND' index 8;

function SetVoiceThreshold(voice, cNotesThreshold: SmallInt): SmallInt; external 'SOUND' index 16;
function GetThresholdEvent: LPINT; external 'SOUND' index 14;
function GetThresholdStatus: SmallInt; external 'SOUND' index 15;

function SetSoundNoise(fnSource, nDuration: SmallInt): SmallInt; external 'SOUND' index 7;

function WaitSoundState(fnState: SmallInt): SmallInt; external 'SOUND' index 11;

function SyncAllVoices: SmallInt; external 'SOUND' index 12;
function CountVoiceNotes(nvoice: SmallInt): SmallInt; external 'SOUND' index 13;

{ Comm support }

function BuildCommDCB(lpszDef: LPCSTR; lpdcb: LPDCB): SmallInt; external 'USER' index 213;
{$ifdef VAR_PARAMS_ARE_FAR}
function BuildCommDCB(lpszDef: LPCSTR; var dcb: DCB): SmallInt; external 'USER' index 213;
{$endif}

function OpenComm(lpszDevControl: LPCSTR; cbInQueue, cbOutQueue: UINT): SmallInt; external 'USER' index 200;
function CloseComm(idComDev: SmallInt): SmallInt; external 'USER' index 207;

function ReadComm(idComDev: SmallInt; lpvBuf: FarPointer; cbRead: SmallInt): SmallInt; external 'USER' index 204;
function ReadComm(idComDev: SmallInt; lpvBuf: PFarChar; cbRead: SmallInt): SmallInt; external 'USER' index 204;
function WriteComm(idComDev: SmallInt; lpvBuf: FarPointer; cbWrite: SmallInt): SmallInt; external 'USER' index 205;
function WriteComm(idComDev: SmallInt; lpvBuf: PFarChar; cbWrite: SmallInt): SmallInt; external 'USER' index 205;
function UngetCommChar(idComDev: SmallInt; chUnget: AnsiChar): SmallInt; external 'USER' index 212;
function FlushComm(idComDev, fnQueue: SmallInt): SmallInt; external 'USER' index 215;
function TransmitCommChar(idComDev: SmallInt; chTransmit: AnsiChar): SmallInt; external 'USER' index 206;

function SetCommState(lpdcb: LPDCB): SmallInt; external 'USER' index 201;
function GetCommState(idComDev: SmallInt; lpdcb: LPDCB): SmallInt; external 'USER' index 202;
function GetCommError(idComDev: SmallInt; lpStat: LPCOMSTAT): SmallInt; external 'USER' index 203;
{$ifdef VAR_PARAMS_ARE_FAR}
function SetCommState(var dcb: DCB): SmallInt; external 'USER' index 201;
function GetCommState(idComDev: SmallInt; var dcb: DCB): SmallInt; external 'USER' index 202;
function GetCommError(idComDev: SmallInt; var Stat: COMSTAT): SmallInt; external 'USER' index 203;
{$endif}

function SetCommBreak(idComDev: SmallInt): SmallInt; external 'USER' index 210;
function ClearCommBreak(idComDev: SmallInt): SmallInt; external 'USER' index 211;

function SetCommEventMask(idComDev: SmallInt; fuEvtMask: UINT): LPUINT; external 'USER' index 208;
function GetCommEventMask(idComDev, fnEvtClear: SmallInt): UINT; external 'USER' index 209;

function EscapeCommFunction(idComDev, nFunction: SmallInt): LONG; external 'USER' index 214;

{ String formatting support }

function wvsprintf(lpszOut: LPSTR; lpszFmt: LPCSTR; lpParams: FarPointer): SmallInt; external 'USER' index 421;
{$ifdef VAR_PARAMS_ARE_FAR}
function wvsprintf(lpszOut: LPSTR; lpszFmt: LPCSTR; var Params): SmallInt; external 'USER' index 421;
{$endif}

{$ifndef SYSTEMUNIT}
function wsprintf(lpszOut: LPSTR; lpszFmt: LPCSTR; etc: array of const): SmallInt; cdecl; external 'USER' name '_wsprintf';
{$endif not SYSTEMUNIT}

