
#include <iostream>
#include <fstream>



using namespace std;


//функция из варианта №3
double f3(double &a, double &b, double &c, double &x){
    if ((a < c) && (c != 0)) {
        return a * pow(x, 2) + b * x + c;
    }
    else
        if ((a > c) && (c == 0)) {
            return -a / (x - c);
        }
        else
            return a * (x + c);
}




//функция из варианта №18
double f18(double& a, double& b, double& c, double& x) {
    if ((x < 0) && (b != 0)) {
        return a * pow(x, 3) + b * pow(x, 2);
    }
    else
        if ((x > 0) && (b == 0)) {
            return (x - a) / (x - c);
        }
        else
            return (x + 5) / (c * (x - 10));
}


// условие для проверки X 
// 3 вариант
// вернет true, если условие не равно нулю => функция должна принимать действительное значение
bool condition3(double &a, double &b, double &c) {
    int a_buf = static_cast<int>(trunc(a));
    int b_buf = static_cast<int>(trunc(b));
    int c_buf = static_cast<int>(trunc(c));
    if ((a_buf & (b_buf | c_buf)) != 0) {
        return true;
    }
    return false;

}

bool condition18(double& a, double& b, double& c) {
    int a_buf = static_cast<int>(trunc(a));
    int b_buf = static_cast<int>(trunc(b));
    int c_buf = static_cast<int>(trunc(c));
    if (!(a_buf & b_buf & c_buf) != 0) {
        return true;
    }
    return false;

}

int main()
{
    setlocale(LC_ALL, "Russian");

    double x_begin, x_end, step, a, b, c;
    ofstream file;
    


    double (*func)(double&, double&, double&, double&);
    bool (*cond)(double&, double&, double&);
    int variant;
    cout << "ВЫберите вариант (3 или 18): ";
    cin >> variant;
    if (variant == 3) {
        func = f3;
        cond = condition3;
        file.open("var3.txt", ios_base::app);
    }
    else
        if (variant == 18) {
            func = f18;
            cond = condition18;
            file.open("var18.txt", ios_base::app);
        }
        else
            return 0;

    

    /*
        Ввод Xнач. и Xкон. 
        Задать шаг dX
    */

    cout << "Введите начало отрезка: ";
    cin >> x_begin;
    file << "Введите начало отрезка: " << x_begin << endl;

    cout << endl << "Введите конец отрезка: ";
    cin >> x_end;
    file << "Введите конец отрезка: " << x_begin << endl;

    cout << endl << "Введите шаг: ";
    cin >> step;
    file << "Введите шаг:" << x_begin << endl;

    cout << endl << "Введите a: ";
    cin >> a;
    file << "Введите a: " << x_begin << endl;

    cout << endl << "Введите b: ";
    cin >> b;
    file << "Введите b: " << x_begin << endl;

    cout << endl << "Введите c: ";
    cin >> c;
    file << "Введите c: " << x_begin << endl;

    cout << endl;
    

    do {
        double x = x_begin;
        if (!cond(a, b, c))
            x = trunc(x);
        cout << "X: " << x_begin << "; X после проверки: " << x << "; F: " << func(a, b, c, x) << endl;

        // запись в файл
        file << "X: " << x_begin << "; X после проверки: " << x << "; F: " << func(a, b, c, x) << ";" << endl; 
        x_begin += step;
    } while (x_begin <= x_end);

    file << endl << endl;
    file.close();
}

