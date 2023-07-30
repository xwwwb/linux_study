#include <stdio.h>
#include <unistd.h>

int main() {
  printf("This is parent:%d\n", getpid());
  sleep(2);
  printf("Create child process!\n");

  int ret = fork();
  if (ret) {
    printf("这里是父进程:%d,%d\n", getpid(), ret);
    int n = 0;
    while (1) {
      printf("n:%d\n", n++);
      sleep(1);
    }
  } else {
    printf("这里是子进程:%d,%d\n", getpid(), ret);
    int m = 0;
    while (1) {
      printf("m:%d\n", m++);
      sleep(1);
    }
  }
}