文件:
	文件内容操作:
		创建,打开文件
		读写文件
		文件内容指针操作
		关闭保存文件

		C:  FILE* fopen fread fwrite  fscanf fprintf fseek fclose
		C++: fstream   .open .read .write ....
		windows: HFILE  CreateFile   ReadFile  WriteFile

		int fd;//文件描述符

		int open(					//失败返回 -1 成功返回fd
			const char* filename,	//文件名
			int flags,				//创建或者打开方式
			mode_t mode);			//文件权限


	文件操作:
		拷贝文件,删除文件,移动文件,获取文件信息

	文件映射:
		文件  --->  硬盘

		硬盘  容量大  访问速度慢  价格便宜  掉电不流失
		内存  容量小  访问速度快  价格贵	  掉电流失

							  写				读
		io操作  读写文件  内存 -> 硬盘   硬盘 -> 内存

		把文件映射到内存中    :操作内存段就是操作文件

		文件映射虚拟内存编程模型
		1. 打开文件  			open
		2. 修改文件大小			ftruncate
		3. 挂载映射 				mmap
		4. 使用虚拟内存(文件)   	指针方式
		5. 卸载映射    			munmap
		6. 关闭文件 				close

作业:
	创建一个非常大的文件   文件里有几万个结构体的数据
	用文件io的方式读写
	和用映射虚拟内存的方式读写 

	比较访问速度!!!

	文件夹遍历:
		看公开课   勒索病毒原理解析

