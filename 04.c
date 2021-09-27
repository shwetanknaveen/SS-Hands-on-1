#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define size 50

int main(){
	int fd;
	char buff[size];

	fd = open("fileForCode4.txt",O_RDWR | O_EXCL | O_CREAT, 0744);

	printf("fd=%d\n",fd);
	
	//Since here O_EXCL flag is set hence if file already exist, fd will hava -1 value
	return 0;

}

/*
O_RDONLY
open for reading only.
O_WRONLY
open for writing only.
O_RDWR
open for reading and writing.
O_APPEND
open for update at the end of the file.
O_CREAT
if O_RDWR is set, this causes the file to be created if it does not exist and truncated if it does. Without this flag, O_RDWR would expect the file to exist.
O_EXCL
if O_EXCL and O_CREAT are set, "open" will fail if the file exists and "errno" will be set to EEXIST. If the file does not exist, "open" will fail and "errno" will be set to EACCESS.
Exclusive would be a correct word here, since the flag is exclusive to the O_CREAT flag and makes the function fail if the file exists. (If the O_CREAT flag is not set the behavior is undefined.
O_TRUNC
opens the file for writing. If the O_RDWR flag is set, the file is truncated to 0 or created if necessary.
*/


