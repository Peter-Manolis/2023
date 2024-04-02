EXECNAME	=	myexec
  
all:	$(EXECNAME)

$(EXECNAME)	:	ImageEditor.o input.o manipulation.o output.o
	gcc -o $(EXECNAME) ImageEditor.o input.o manipulation.o output.o
ImageEditor.o	:	ImageEditor.c

manipulation.o	:	manipulation.c

output.o	:	output.c

input.o		:	input.c

clean:
	rm ImageEditor.o $(EXECNAME)
