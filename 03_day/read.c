#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // 给close

struct student {
  int id;
  char name[20];
  int age;
  double score;
};

int main() {
  int fd = open("demo.txt", O_RDONLY);
  // if(-1 == fd){
  //     printf("打开文件失败：%m");
  //     exit(-1);
  // }

  if (-1 == fd)
    printf("打开文件失败：%m"), exit(-1);

  printf("打开文件成功\n");

  struct student s;
  for (int i = 0; i < 5; i++) {
    read(fd, &s, sizeof(struct student));
    printf("id:%d,name:%s,age:%d,score:%lf\n", s.id, s.name, s.age, s.score);
  }
}