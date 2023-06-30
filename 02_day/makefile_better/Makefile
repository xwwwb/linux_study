# 井号注释

math.out:main.o add.o sub.o
	gcc *.o -o $@

# main.o:main.c add.o:add.c sub.o:sub.c
%.o:%.c
	gcc -c $< -o $@

clean:
	rm -rf *.o math

build:
	make