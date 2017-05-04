all:
	@gcc -o test testTarget.c cellsFactory.c
	@./test
	@rm test
