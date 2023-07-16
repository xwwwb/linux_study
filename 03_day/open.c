#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // 给close

struct student {
  int id;
  char name[20];
  int age;
  double score;
};

int main() {
  // 如果算O_RDONLY 无法写入文件，但是貌似也不报错
  int fd = open("demo.txt", O_WRONLY);
  if (fd == -1) {
    // perror 是系统调用的错误提示函数
    // perror("打开文件失败");
    // %m是错误信息的占位符
    // printf("打开文件失败：%m\n");

    // 上面两种写法效果一致
    // return -1;

    // 创建文件
    fd = open("demo.txt", O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
      perror("创建文件失败");
      exit(-1);
    }
    printf("创建文件成功\n");
  }
  printf("打开文件成功\n");

  struct student stu[5] = {{1, "关羽", 50, 100.1},
                           {2, "张飞", 40, 99.2},
                           {3, "赵云", 30, 98.3},
                           {4, "马超", 20, 97},
                           {5, "黄忠", 10, 96}};

  // 下面写法和循环一样
  // write(fd, stu, sizeof(struct student) * 5);

  for (int i = 0; i < 5; i++) {
    write(fd, &stu[i], sizeof(struct student));
  }

  close(fd);
}