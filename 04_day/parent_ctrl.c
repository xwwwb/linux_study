// 作业 父进程控制子进程的结束
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main() {
  // 首先打开文件
  int fd = open("share_mm.dat", O_CREAT | O_RDWR);
  if (fd == -1) {
    system("rm -f share_mm.dat");
    fd = open("share_mm.dat", O_CREAT | O_RDWR);
  }
  // 分配大小
  ftruncate(fd, 4);
  int *flag = mmap(NULL, 4, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
  *flag = 0;

  int ret = fork();
  if (ret) {
    // 父进程
    int input;
    printf("输入1启动子进程，输入2暂停子进程，输入3停止程序\n");
    while (scanf("%d", &input) != -1) {
      if (input == 1) {
        // 启动子进程
        *flag = 1;
        printf("子进程启动\n");
      } else if (input == 2) {
        *flag = 0;
        printf("子进程暂停\n");
      } else {
        *flag = 3;
        while (1) {
          if (*flag == 4) {
            munmap(flag, 4);
            close(fd);
            system("rm -f share_mm.dat");
            printf("父进程结束\n");
            exit(0);
          }
        }
      }
    }
  } else {
    // 子进程
    while (1) {
      if (*flag == 1) {
        srand(time(0));
        printf("%07d\n", rand() % 10000000);
        sleep(1);
      } else if (*flag == 3) {
        break;
      }
    }
    printf("子进程结束\n");
    *flag = 4;
  }
}