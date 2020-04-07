#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;
void var3() {
    ofstream file;
    string str1, str2, str3;
    file.open("var3.txt", ios_base::app);
    int (*func1)(int* mass, int size);
    int (*func2)(int* mass, int size);
    void (*func3)(int* mass, int size);
    func1 = multEvenNumbers3;
    func2 = sumBetweenZeroes3;
    func3 = chngMsFirstPlus3;
    str1 = "Произведение элементов массива с нечетными номерами: ";
    str2 = "Сумма элементов массива, расположенных между первым и последним нулевыми элементами: ";
    str3 = "Преобразовать массив таким образом, чтобы сначала располагались все положительные элементы, а потом — все отрицательные (элементы, равные О, считать положительными). :";
    int n; // размер массива
    cout << "Введите размер массива: ";
    cin >> n;
    file << "Размер массива: " << n << endl;
    int* mass = new int[n];

    //Ввод в массив вручную
    cout << "Заполните массив. (целые числа)" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " элемент: ";
        cin >> mass[i];
        file << i + 1 << " элемент: " << mass[i] << endl;
    }

    cout << str1;
    cout << func1(mass, n);
    file << str1 << func1(mass, n) << endl;
    cout << endl << endl;

    cout << str2;
    file << str2;
    try {
        cout << func2(mass, n);
        file << str2 << func2(mass, n) << endl;
    }
    catch (funcException) {
        cout << "Sorry -_- Не смог найти нули.";
        file << "Sorry -_- Не смог найти нули." << endl;
    }
    cout << endl << endl;

    cout << str3 << endl;
    file << str3 << endl;
    func3(mass, n);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " элемент: ";
        cout << mass[i] << endl;
        file << i + 1 << " элемент: " << mass[i] << endl;
    }
    cout << endl << endl;

    file << endl << endl;
    delete[] mass;
    file.close();
}

void var18() {
    ofstream file;
    string str1, str2, str3;
    file.open("var18.txt", ios_base::app);
    str1 = "количество элементов массива, меньших С : ";
    str2 = "сумму целых частей элементов массива, расположенных после последнего отрицательного элемента.: ";
    str3 = "Преобразовать массив таким образом, чтобы сначала располагались все элементы, отличающиеся от максртмального не более чем на 20%, а потом — все остальные :";
    int n; // размер массива
    cout << "Введите размер массива: ";
    cin >> n;
    file << "Размер массива: " << n << endl;
    double* mass = new double[n];

    //Ввод в массив вручную
    cout << "Заполните массив. (вещественные числа)" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " элемент: ";
        cin >> mass[i];
        file << i + 1 << " элемент: " << mass[i] << endl;
    }

    cout << str1;
    cout << "";
    double c;
    cin >> c;
    cout << elLesThanC18(mass, n, c);
    file << str1 << elLesThanC18(mass, n, c) << endl;
    cout << endl << endl;

    cout << str2;
    file << str2;
    try {
        cout << sumAfterMinus18(mass, n);
        file << str2 << sumAfterMinus18(mass, n) << endl;
    }
    catch (funcException) {
        cout << "Sorry -_- Не смог найти отрицательные числа.";
        file << "Sorry -_- Не смог найти отрицательные числа." << endl;
    }
    cout << endl << endl;

    cout << str3 << endl;
    file << str3 << endl;
    chngMs18(mass, n);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " элемент: ";
        cout << mass[i] << endl;
        file << i + 1 << " элемент: " << mass[i] << endl;
    }
    cout << endl << endl;

    file << endl << endl;
    delete[] mass;
    file.close();
}



int main()
{
    setlocale(LC_ALL, "Russian");
    // int variant;
    // cout << "ВЫберите вариант (3 или 18): ";
    // cin >> variant;
    // if (variant == 3) {
    //     var3();
    // }
    // else
    //     if (variant == 18) {
    //         var18();
    //     }
    //     else
    //         return 0;
    string a = "аг";
    string b = "ббг";
    bool ans;
    ans = a > b;
    if (ans)
        cout << "true";
    else
        cout << "false";
}

