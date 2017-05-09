# NumbersToBraille
Lib which converts one array representing a braille cell into an alphanumeric char.

### Braille cell
The braille cell is composed of 6 points to be filled, allowing 63 arranges. Some of you could consider the empty cell as a symbol too, resulting in 64 arranges. It is enumerated top to bottom in both of your columns, like the image below:

![The braille cell](https://nfb.org/images/nfb/publications/books/wumf/WorldUnderPhotos/braille-cell-numbered.gif)

Here, we have the Portuguese braille alphabet:

![Portuguese braille alphabet](http://www.projetoacesso.org.br/site/images/Screen%20Shot%202012-12-06%20at%204.46.41%20PM.png)

### Usage
This lib provides a `braille.h` file with the function
```c
char decodeChar(int *array);
```
which expects one array with 6 positions representing the braille cell and returns the corresponding char in the Portuguese braille convention (pt-br).

##### Exemple
The following code
```c
int array[6] = {1,0,0,1,1,0};
printf("%c", decodeChar(array));
```
will print: `d`

### Unit tests
To run the unit tests, just go to the repo folder and run
```bash
$ make
```
it will print the Portuguese braille alphabet and the feedback of the unit tests.

### [WIP] Roadmap
:white_check_mark:&nbsp;&nbsp;&nbsp;&nbsp;**lowercase alphabet**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**uppercase alphabet**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**numbers** 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**accessory symbols**     
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**math symbols**   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**typographic variants**   
