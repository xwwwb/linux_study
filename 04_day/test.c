#include <stdio.h>
#include <unistd.h>
int main() {
  int n = 0;
  while (1) {
    printf("%d:%d\n", getpid(), n++);
    sleep(1);
  }
}