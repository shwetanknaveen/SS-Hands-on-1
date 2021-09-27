#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


//Oracle man page for select() https://docs.oracle.com/cd/E36784_01/html/E36874/fd-set-3c.html
int main(void)
{
  fd_set rfds;//set of file descriptors
  struct timeval tv;
  int retval;
  FD_ZERO(&rfds);//Initializes the file descriptor set fdset to have zero bits for all file descriptors.
  FD_SET(0, &rfds);//FD_SET(fd, &fdset)  	Sets the bit for the file descriptor fd in the file descriptor set fdset.
  tv.tv_sec = 10;//seconds
  tv.tv_usec = 0;//micro seconds
  retval = select(1, &rfds, NULL, NULL, &tv);//check 1 fd from rfds set as readfds and NULL,NULL for writefds and errorfds, for time tv
  if (retval == -1)
    perror("select()");
  else if (retval)
          printf("Data is available now.\n");
        else
          printf("No data within ten seconds.\n");
  exit(EXIT_SUCCESS);
}

/*
select()  and pselect() allow a program to monitor multiple file descriptors, waiting until one or more of the file descriptors be‐
       come "ready" for some class of I/O operation (e.g., input possible).  A file descriptor is considered ready if it  is  possible  to
       perform a corresponding I/O operation (e.g., read(2), or a sufficiently small write(2)) without blocking.

       select() can monitor only file descriptors numbers that are less than FD_SETSIZE; poll(2) does not have this limitation.  See BUGS.

       The operation of select() and pselect() is identical, other than these three differences:

       (i)    select()  uses  a  timeout  that is a struct timeval (with seconds and microseconds), while pselect() uses a struct timespec
              (with seconds and nanoseconds).

       (ii)   select() may update the timeout argument to indicate how much time was left.  pselect() does not change this argument.

       (iii)  select() has no sigmask argument, and behaves as pselect() called with NULL sigmask.
*/
