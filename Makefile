all:
	@gcc -o test UnitTests/main.cpp UnitTests/cellsFactory.cpp braille.cpp 
	@./test
	@rm test
