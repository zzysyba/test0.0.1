src = $(wildcard ./src/*.c) # add.c sub.c dic1.c hello.c
obj = $(patsubst ./src/%.c, ./obj/%.o, $(src)) #add.o sub.o div.o hello.o

myArgs = -Wall -g

ALL:a.out

inc_path=./inc

a.out:$(obj)
	gcc $(obj) $(myArgs)

$(obj):./obj/%.o:./src/%.c
	gcc -c $< -o $@	$(myArgs) -I $(inc_path)

clean:
	-rm -rf $(obj) a.out 

.PHONY: clean ALL
