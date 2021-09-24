# Windows/x86 Dynamic WinExec PopCalcs PEB & Export Directory Table
 
## Description: 

This is a shellcode (PIC) that
pop a calc.exe, in order to accomplish this task the shellcode uses
the PEB method to locate the baseAddress of the required module and the Export Directory Table
to locate symbols. Also the shellcode uses a hash function to gather dynamically the required 
symbols without worry about the length. Finally the shellcode pop the calc.exe using WinExec 
and exits gracefully using TerminateProcess. 


- Author: h4pp1n3ss
- Date: Wed 09/22/2021
- Tested on: Microsoft Windows [Version 10.0.19042.1237]

# Windows API 

This shellcode uses two Windows API

### WinExec

[WinExec Function Prototype](https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winexec)
```c
 UINT WinExec(
  LPCSTR lpCmdLine, -> EBX
  UINT   uCmdShow 	 -> EAX
 );
```

and 

### TerminateProcess

[TerminateProcess Function Prototype](https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-terminateprocess)

```c
 BOOL TerminateProcess(
  HANDLE hProcess,	 -> 0xffffffff
  UINT   uExitCode	 -> EAX
 );
```


# Resources

- [Corelan - Exploit writing tutorial part 9](https://www.corelan.be/index.php/2010/02/25/exploit-writing-tutorial-part-9-introduction-to-win32-shellcoding/)
- [Shell-storm](http://shell-storm.org/shellcode/)
- [Phrack - History and Advances in Windows Shellcode](http://www.phrack.org/issues/62/7.html#article)
- [Skape - Understanding Windows Shellcode ](http://www.hick.org/code/skape/papers/win32-shellcode.pdf)
