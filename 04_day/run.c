#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 如果kill掉test.out的进程号，则会回到run.c的system函数之后的代码继续运行
// 如果kill掉run.c的进程号，system启动的进程就脱离了控制
// test.out运行的时候 run.c是挂起状态

int main() {
  printf("Sleep...\n");
  sleep(2);
  printf("Start! Current Process ID: %d\n", getpid());
  // 这样创建进程 不是很安全
  system("./test.out");
  sleep(5);
  printf("good bye~\n");
  return 0;
}