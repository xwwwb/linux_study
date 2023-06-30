#define PI 3.14
#include <stdio.h>
int main(){
	// 可以看到PI被替换了 注释也没了
	PI*PI;
	#ifdef PI
	printf("PI is defined\n");
	#endif
	return 0;	
}
