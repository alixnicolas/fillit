# fillit
42 School PROJECT

Fillit is a project which allows to discover and/or familiarize yourself with a recurring
problematic in programming : searching for the optimal solution among a huge set of possibilities.
In this particular project, it has been charged to create an algorithm which
fits some Tetriminos together into the smallest possible square.

The program uses an array of strings to contain all the set of Tetriminos and does not use recursion to solve the map.

include/utilities.h --> prototypes, static array of strings (= set of all the Tetriminos)

aa_main.c           --> the main (function calls + file reader)

aa_check_file       --> verifies the errors in the input file and gives the number of pieces in the input file.

aa_make_array       --> creates an array with all the input pieces by order of appearance t[0] = first piece 

aa_make_map.c       --> creates the map (which is a string of '.') and makes it bigger if the solver of aa_feel_map.c does not succeed 

aa_feel_map         --> the solver that calls aa_get_data.c, aa_check_place.c and aa_manip_map.c functions

aa_get_data.c       --> creates dynamic pieces according to the map size, checks space on a row, and gets data from the pieces

aa_check_place      --> tells if a piece can fit

aa_manip_map        --> assigns or removes '#' and letters in the map
