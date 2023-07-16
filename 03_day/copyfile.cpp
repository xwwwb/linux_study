#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
#if 0
    char buff[256] = {0};
    sprintf(buff,"cp %s %s",argv[1],argv[2]);
    system(buff);
#else
  int fdSrc, fdDst;
  fdSrc = open(argv[1], O_RDONLY);
  fdDst = open(argv[2], O_WRONLY | O_CREAT, 0666);
  int result;
  char buff[2048];
  while (1) {
    result = read(fdSrc, buff, 2048);
    if (result > 0) {
      write(fdDst, buff, result);
    } else {
      break;
    }
  }
  close(fdSrc);
  close(fdDst);
#endif
  return 0;
}