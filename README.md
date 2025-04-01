# C-Exercises

A collection of C programming exercises I've solved. Easiest to hardest.

## Files

- `binary.c`  
  Reads a binary number from standard input and outputs its decimal equivalent.

- `caesar.c`  
  Implements the Caesar cipher encryption technique.  
  Reads an integer `N` (shift key) and a line of plaintext from input, then prints the encoded result by shifting each alphabetic character by `N` positions.

- `hamster_decode.c`  
  Decodes data in the format `[alphabet][indices]`. The program reads input until EOF and reconstructs a message using the alphabet and index list.  

  **Example Input:**
HELOWRD0122343526

  **Decoded Output:**
HELLOWORLD

- `program.c`  
Prints only characters from standard input that match any characters provided as command-line arguments.  
Continues processing until EOF.

- `reverse.c`  
Reads input line by line and prints each line reversed.  
Handles newline characters properly and continues until EOF.

- `manhatten.c`  
  This C program visualizes how far a character can move on a 2D grid using Manhattan distance (up, down, left, right) from a starting position.  
  The grid is printed to the terminal, showing remaining walk points at each reachable position.  
  It then generates a board of the given width and height, placing the character `'C'` at the coordinate `(x, y)`.  
  Using the specified `walk_limit`, it calculates how many moves remain for each position the character can reach,  
  assuming one move per grid space and no diagonal movement.  
  Unreachable spaces are shown as empty (`| |`).  
  Reachable spaces show how many moves would be left if the character were standing there (`|2|`, `|1|`, etc).

  The program takes five command-line arguments:

  ```bash
  ./manhatten <width> <height> <x> <y> <walk_limit>
  ```

- `tr.c` 
   A simple C program that mimics basic functionality of the Unix tr command.
   It reads from standard input, replaces specified characters with their corresponding replacements, and prints the result to standard output. 
   Input is processed line by line until EOF is reached.