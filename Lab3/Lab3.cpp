#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

    /*
        Вариант 3 Дана целочисленная прямоугольная матрица.Определить: 
         1) количество столбцов, содержащих хотя бы один нулевой элемент; 
         2) номер строки, в которой находится самая длинная серия одинаковых элементов.
    */
void var3() {

    ofstream file;
    file.open("var3.txt", ios_base::app);

    // статическая матрица
    const unsigned int rows = 3;
    const unsigned int cols = 2;
    int stat_arr[rows][cols] = {
        {1, 1},
        {3, 2},
        {0, 1},
    };

    while (1){

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2; j++) {
                cout << "введите элемент на " << i << " строке и " << j << " столбце";
                cin >> stat_arr[i][j];
                cout << endl;
            }

        cout << "количество столбцов, содержащих хотя бы один нулевой элемент: " << amount_of_zero_cells_static(stat_arr) << endl;
        try
        {
            cout << "номер строки, в которой находится самая длинная серия одинаковых элементов: " << num_of_longest_line_static(stat_arr) << endl;
        }
        catch (ExceptionLab e)
        {
            cout << "такой строки не найдено";
        }

        writeMatrixToFile(stat_arr, file);
    }

    file.close();
}



/*
Вариант 18 Дана целочисленная прямоугольная матрица.Определить: 
1) количество строк, содержащих хотя бы один нулевой элемент; 
2) номер столбца, в которой находится самая длинная серия одинаковых элементов.
*/
void var18() {}



int main()
{
    setlocale(LC_ALL, "Russian");
    var3();
}
