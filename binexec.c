/*
to execute raw shellcode created from nasm -f bin directly laced in binary.bin file
no cleaning since shellcode will exi the program always if properly made.
*/
#include<stdio.h>
#include<windows.h>
int main()
{
	FILE *fptr;
	fptr=fopen("binary.bin","rb");
	fseek(fptr,0,SEEK_END);
	long int len=ftell(fptr);
	BYTE *ptr=(BYTE*)malloc(len);
	fseek(fptr,0,SEEK_SET);
	fread(ptr,len,1,fptr);
	fclose(fptr);
	int i=0;
	for(i=0;i<len;i++)
	printf("\\x%0.2x",ptr[i]);
	FARPROC shellcode=(FARPROC)ptr;
	shellcode();
getch();	
}

/*
example shellcode
\xe8\xcc\x00\x00\x00\x68\x8e\x4e\x0e\xec\x50\xe8\x2a\x00\x00\x00\x83\xc4\x08\xe8
\x07\x00\x00\x00\x75\x73\x65\x72\x33\x32\x00\xff\xd0\x68\xa8\xa2\x4d\xbc\x50\xe8
\x0e\x00\x00\x00\x83\xc4\x08\x6a\x00\x6a\x00\x6a\x00\x6a\x00\xff\xd0\xc3\x31\xff
\x8b\x44\x24\x04\x31\xdb\x66\x03\x58\x3c\x01\xd8\x66\x31\xdb\x83\xc0\x78\x8b\x00
\x03\x44\x24\x04\x3b\x7c\x24\x08\x74\x39\x8b\x58\x20\x03\x5c\x24\x04\x8b\x48\x18
\x31\xd2\x31\xc0\x83\xeb\x04\x85\xc9\x74\x50\x83\xc3\x04\x83\xc2\x02\x8b\x33\x03
\x74\x24\x04\x31\xff\x31\xc0\xac\x84\xc0\x74\x07\xc1\xcf\x0d\x01\xc7\xeb\xf2\x3b
\x7c\x24\x08\x75\x29\xeb\xa9\x8b\x58\x24\x03\x5c\x24\x04\x01\xd3\x31\xc9\x66\x8b
\x0b\x8b\x58\x1c\x03\x5c\x24\x04\x01\xc9\x01\xc9\x01\xcb\x83\xeb\x04\x8b\x1b\x8b
\x44\x24\x04\x01\xd8\xc3\x31\xc0\x49\xeb\xac\xc3\x31\xc0\xb0\x30\x64\x8b\x00\x8b
\x40\x0c\x8b\x40\x1c\x8b\x40\x08\xc3\x31\xc0\xb0\x30\x64\x8b\x00\x8b\x40\x0c\x8b
\x40\x1c\x8b\x00\x8b\x00\x8b\x40\x08\xc3*/