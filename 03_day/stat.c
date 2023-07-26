#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  struct stat st = {0};
  // struct timespec st_atim;
  int result = stat(argv[1], &st);
  if (!result) {
    printf("获取%s成功\n", argv[1]);
  } else {
    printf("获取%s类型失败\n", argv[1]);
    return 0;
  }
  // 这里注意使用括号括着位运算
  if ((st.st_mode & __S_IFMT) == __S_IFDIR) {
    printf("是个目录文件\n");
  } else {
    printf("是个普通文件\n");
  }
}