all:
	@gcc -o test UnitTests/main.c UnitTests/cellsFactory.c braille.c 
	@./test
	@rm test
