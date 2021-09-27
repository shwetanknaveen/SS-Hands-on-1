#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
clock_t startm, stopm;
#define START if ( (startm = clock()) == -1) {printf("Error calling clock");exit(1);}
#define STOP if ( (stopm = clock()) == -1) {printf("Error calling clock");exit(1);}
int main() {
  START;
  int pid = getpid();
  STOP;
  printf( "%f seconds used by the processor for getpid().\n", ((double)stopm-startm)/CLOCKS_PER_SEC);
}