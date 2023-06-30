gcc g++
	解释性语言  
		源代码    ------>     可执行程序文件 库(动态库，静态库)
				  编译器
		汇编  C  C++  java C#  objective-c

	脚本语言
		源代码就是可执行程序文件
		shell  javascript  python  

	linux：
		GNU  命令 

	windows：
		集成开发环境   vs系列  vc++6.0  devC++ QtCreator


	程序从源代码  到  可执行程序 中间经历哪些步骤：
		预处理：预处理指令执行   宏 展开
			#ifdef 0
			#else
			#endif

			gcc -E test.c 
			gcc -E test.c > test.txt

		预编译：
		编译：
			语法检查  程序优化
			生成目标程序  .o     二进制文件

			仅编译：
				gcc -c *.c -o *.o
			编译成汇编：
				gcc -S *.c -o *.s


		链接：
			多个目标程序 包括 库 链接成一个可执行程序文件

			gcc 1.o 2.o 3.o -o *.exe

多文档编译：
	每个部分  声明在.h中  定义在.c中
		main.c  
		add.c add.h
		sub.c sub.h
		cheng.c cheng.h 

	分开编译
		gcc -c main.c   生成   main.o
		gcc -c add.c    生成   add.o
		gcc -c sub.c    生成   sub.o
		gcc -c cheng.c  生成   cheng.o

	一起链接
		gcc main.o add.o sub.o cheng.o 
		生成 可执行程序  默认a.out

makefile
	$@   目标
	$<   代表依赖 并且   是一个个代表


C++:
	C语言的源程序文件  *.c  编译工具 gcc
	C++语言的源程序文件 *.cpp 编译工具 g++

shell脚本
	echo 输出
	数学运算  expr 

	*.sh

	shell脚本的参数
	$1 $2 $3 $4 ....     argv
	命令行的第n个参数

	$# 命令行参数个数     argc - 1 
	$* 所有的命令行参数

	shell脚本数学运算
		let "x+=10"

		expr $n + $m

		((y=$x+$m))


		y=`expr $n + $m`
		y=$(expr $n + $m)

	判定语句：
		if test 。。。。
		then
		else
		fi
	循环语句：
		for((i=0;i<10;i++))
		do

		done

		for a in {1 2 3 4 5 6}
		do

		done

		while循环 until循环
