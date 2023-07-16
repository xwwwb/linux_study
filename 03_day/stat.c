#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
  struct stat st = {0};
  // struct timespec st_atim;
  int result = stat(argv[1], &st);
  if (result) {
    printf("获取文件成功\n");
  } else {
    printf("获取文件类型失败\n");
    return 0;
  }
  if (st.st_mode | S_IFMT == S_IFDIR) {
    printf("是个目录文件");
  } else {
    printf("是个普通文件");
  }
}