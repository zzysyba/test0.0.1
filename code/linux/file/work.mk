src = $(wildcard *.c)
name = $(patsubst %.c, %, $(src))

maArgs = -Wall -g

ALL:$(name)

inc_path = ./

$(name):%:%.c
	gcc $< -I $(inc_path) -o $@ $(maArgs)

clean:
	-rm -rf $(name) 

.PHONY: clean ALL

