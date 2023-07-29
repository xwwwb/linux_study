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
  struct student *p =
      mmap(NULL, 3 * sizeof(struct student), PROT_READ, MAP_SHARED, fd, 0);

  struct student *pp = p;
  for (int i = 0; i < 3; i++) {
    printf("%d:%s:%d:%lf", pp->id, pp->name, pp->age, pp->score);
    pp++;
  }

  munmap(p, 3 * sizeof(struct student));
  close(fd);
  return 0;
}