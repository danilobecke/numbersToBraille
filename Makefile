all:
	@gcc -o test UnitTests/testTarget.c UnitTests/cellsFactory.c
	@./test
	@rm test
