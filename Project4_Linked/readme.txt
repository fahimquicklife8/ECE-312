Fahim Imtiaz
fmi89
06/30/2023


Flood fill: The "Flood Fill" program reads a file that contains a matrix of colored squares that represents a two-dimensional image. 


characters made of pixels. A "flood fill" effect is created when the user selects a pixel and replaces it with the color of their choice, along with all adjacent pixels that are the same color.


The user enters a new color and the row and column indices of the first pixel. The pixel at the given index is changed to the new color, along with all directly and indirectly related pixels that share the same original color. By entering -1 for either row or column, the flood fill procedure can be carried out as many times as the user pleases until the program is terminated.




The chosen pixel is added to the stack when a user command is received. After that, the top pixel is popped, its color is changed, and its valid neighboring pixels are repeatedly added into the stack until the stack is empty.
 This ensures that the new color will eventually fill any nearby pixels that share the same hue.