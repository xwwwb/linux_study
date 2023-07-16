// 实现每三个字节读取一个字符
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  int fd = open("./seek.txt", O_RDONLY);
  if (fd == -1) {
    perror("打开文件失败");
  }
  char c;
  int result;
  while (1) {
    result = read(fd, &c, 1);
    if (result > 0) {
      printf("%c\n", c);
    } else {
      break;
    }
    lseek(fd, 2, SEEK_CUR);
  }
}