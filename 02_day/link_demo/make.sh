gcc -c main.c
gcc -c sub.c
gcc -c add.c
gcc main.o sub.o add.o -o main.out
echo "Done"