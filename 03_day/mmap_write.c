#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h> // 给close

struct student {
  int id;
  char name[20];
  int age;
  double score;
};

int main() {
  int fd = open("stu.dat", O_CREAT | O_RDWR);
  if (fd == -1)
    printf("打开文件失败:%m\n"), exit(-1);
  printf("打开文件成功\n");

  ftruncate(fd, 3 * sizeof(struct student));

  // 映射虚拟内存
  struct student *pp = mmap(NULL, 3 * sizeof(struct student),
                            PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
  if (NULL == pp)
    printf("映射虚拟内存失败:%m"), close(fd), exit(-1);

  printf("映射虚拟内存成功\n");

  struct student *ppp = pp;
  ppp->id = 1;
  strcpy(ppp->name, "张三");
  ppp->age = 33;
  ppp->score = 1.3;

  ppp++;

  ppp->id = 2;
  strcpy(ppp->name, "李四");
  ppp->age = 44;
  ppp->score = 1.4;

  ppp++;

  ppp->id = 3;
  strcpy(ppp->name, "王五");
  ppp->age = 55;
  ppp->score = 1.5;

  int ret = munmap(pp, 3 * sizeof(struct student));
  if (ret)
    printf("munmmap");

  close(fd);
  return 0;
}