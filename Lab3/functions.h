#include <iostream>
#include <fstream>

enum ExceptionLab { WRONG_VALUE, NO_REPEATING };

int amount_of_zero_cells_static(int(&arr)[3][2]);
int num_of_longest_line_static(int(&arr)[3][2]);

void writeMatrixToFile(int(&arr)[3][2], std::ofstream& file);