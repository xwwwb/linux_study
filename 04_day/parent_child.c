#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
int main() {
  char userName[20] = "xwwwb";
  char passWord[20] = "xwwwb";
  char user[25];
  char pass[25];
  while (1) {
    printf("请输入用户名:");
    scanf("%s", user);
    printf("请输入密码:");
    scanf("%s", pass);
    if (0 == strcmp(user, userName) && 0 == strcmp(pass, passWord)) {
      printf("登陆成功\n");
      break;
    } else {
      printf("登陆失败\n");
      sleep(2);
      system("clear");
    }
  }

  if (fork()) {
    // 父进程
    // 打印当前时间
    struct tm *pt;
    while (1) {
      time_t tt = time(0);
      pt = localtime(&tt);
      printf("Time:%02d:%02d:%02d\n", pt->tm_hour, pt->tm_min, pt->tm_sec);
      sleep(1);
    }
  } else {
    srand(time(0));
    while (1) {
      printf("====%07d====\n", rand() % 10000000);
      usleep(500000);
    }
  }
}