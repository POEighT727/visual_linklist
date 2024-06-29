main:*.o
		gcc *.o -l ncurses -o main
*.o:*.c
		gcc -c *.c
clean:
		sudo rm main *.o *.a *.so
install:*.c
		gcc -c randomseq.c select_sort.c
		ar -r libtool.a randomseq.o select_sort.o
		gcc linklist.c visual.c -fPIC -shared -o libdatastd.so
		sudo cp *.a *.so /usr/lib64
installtest:*.a *.so
		gcc main.c -ldatastd -lncurses -ltool -o main

