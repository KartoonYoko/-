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

    // статическая матрица
    const unsigned int rows = 3;
    const unsigned int cols = 2;
    int stat_arr[rows][cols] = {
        {0, 0},
        {3, 3},
        {0, 3},
    };


    cout << "количество столбцов, содержащих хотя бы один нулевой элемент: " << amount_of_zero_cells_static(stat_arr) << endl;
    cout << "номер строки, в которой находится самая длинная серия одинаковых элементов: " << num_of_longest_line_static(stat_arr) << endl;
       


    int rows_dinam_arr;
    int cols_dinam_arr;
    cout << "Введите кол-во строк: ";
    cin >> rows_dinam_arr;
    cout << endl;
    cout << "Введите кол-ва столбцов: ";
    cin >> cols_dinam_arr;
    cout << endl;
    // динамическая матрица
    int** dinam_arr = new int* [rows_dinam_arr];
    for (int i = 0; i < rows_dinam_arr; i++) {
        dinam_arr[i] = new int[cols_dinam_arr];
    }
    //cout << "Матрица: " << endl;
    //for (int i = 0; i < rows_dinam_arr; i++) {
    //    for (int j = 0; j < cols_dinam_arr; j++) {
    //        //cout << dinam_arr[i][j];
    //        cin >> dinam_arr[i][j];
    //    }
    //}
    // удаление динамического массива
    for (int i = 0; i < rows_dinam_arr; i++) {
        delete[] dinam_arr[i];
    }
    ofstream file;
    file.open("var3.txt", ios_base::app);
    
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
