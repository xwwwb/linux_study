#include <stdio.h>
#include <unistd.h>

int main() {
  wait();
  if (fork()) {
    printf("子进程被创建了\n");
  } else {
    for (int i = 0; i < 5; i++) {
      printf("子进程:%d\n", i);
      sleep(1);
    }
  }
  wait(0);

  printf("父进程结束\n");
  return 0;
}