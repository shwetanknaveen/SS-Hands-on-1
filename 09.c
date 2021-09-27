#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>  
int main()
{
	struct stat sb;
	int n=stat("file9.txt",&sb);
	printf("I-node number:                 \t%ld\n", (long) sb.st_ino);
	printf("Link count:                    \t%ld\n", (long) sb.st_nlink);
	printf("Ownership:                     \tUID=%ld   GID=%ld\n", (long) sb.st_uid, (long) sb.st_gid);
	printf("File size:                     \t%lld Bytes\n", (long long) sb.st_size);
	printf("Block size:                    \t%ld Bytes\n", (long) sb.st_blksize);
    	printf("Number of blocks:              \t%lld\n", (long long) sb.st_blocks);
    	printf("Time of last file access:      \t%s", ctime(&sb.st_atime));
    	printf("Time of last file modification:\t%s", ctime(&sb.st_mtime));
    	printf("Time of last change:           \t%s", ctime(&sb.st_ctime));
}
