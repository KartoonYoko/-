
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>




using namespace std;

void toConsole(double *x1, double *y1, double* x2, double* y2, int num) {
    cout << "FirstPoint\tSecondPoint" << endl;
    cout << "x\ty\tx\ty" << endl;
    for (int i = 0; i < num; i++) {
        cout << x1[i] 
             << "\t" 
             << y1[i] 
             << "\t"
             << x2[i]
             << "\t"
             << y2[i]
             << endl;
    }
}



/* Решить СЛАУ, где коэфициенты передаются в двумерном векторе размера N x N+1 */
vector<double> solveEquations(vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<double> answer;
    double buf, buf2;

    // метод жордана-гаусса
    {
        for (int i = 0; i < n; i++) {
            buf = matrix[i][i];
            for (int j = i; j < n + 1; j++)
            {
                matrix[i][j] /= buf;
            }
            for (int k = i + 1; k < n; k++) {
                buf2 = matrix[k][i];
                for (int j = i; j < n + 1; j++)
                {
                    matrix[k][j] -= buf2 * matrix[i][j];
                }
            }
        }
        for (int i = n - 1; i > -1; i--) {
            for (int k = i - 1; k > -1; k--) {
                buf = matrix[k][i];
                for (int j = n; j > -1; j--)
                {
                    matrix[k][j] -= buf * matrix[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            answer.push_back(matrix[i][n]);
        }
        //*/
    }

    return answer;
}


/* Находит уравнение окружности, определяя координаты центра оркужности и ее радиус */
vector<double> findOutCircleEquation(const double &x1, const  double& y1, const  double& x2, const  double& y2, const  double& x3, const  double& y3) {
    vector<vector<double>> matrix;
    vector<double> bufVec;

    bufVec = { 2 * x1, 2 * y1, 1, -(pow(x1, 2) + pow(y1, 2)) };
    matrix.push_back(bufVec);
    bufVec = { 2 * x2, 2 * y2, 1, -(pow(x2, 2) + pow(y2, 2)) };
    matrix.push_back(bufVec);
    bufVec = { 2 * x3, 2 * y3, 1, -(pow(x3, 2) + pow(y3, 2)) };
    matrix.push_back(bufVec);

    return solveEquations(matrix);

   
}





/*
                        Вариант 3

        Даны два множества точек на плоскости.
        Выбрать три различные точки первого множества так, чтобы круг, ограниченный окружностью,
            проходящей через эти три точки, содержал все точки второго множества и имел минимальную площадь. 
*/
void var3() {
    double* x1, *y1;
    double* x2, * y2;
    int amountOfPoints = 10;
    
    x1 = new double[amountOfPoints];
    y1 = new double[amountOfPoints];
    x2 = new double[amountOfPoints];
    y2 = new double[amountOfPoints];
    
    for (int i = 0; i < amountOfPoints; i++) {
        x1[i] = rand() % 10;
        y1[i] = rand() % 10;
        x2[i] = rand() % 10;
        y2[i] = rand() % 10;
    }
    
    toConsole(x1, y1, x2, y2, amountOfPoints);

    // координаты центра круга
    double xc, yc;
    // радиус круга
    double r;
    // для координат оркужности и радиуса
    vector<double> circleEquation; 
    /* выражение, которое выясняет принадлежит ли точка (x, y) кругу с центром в точке (xc, yc) */ 
    bool (*doesItBelongToCircle)(double, double, double, double, double);
    doesItBelongToCircle = [](double x, double y, double xc, double yc, double r) -> bool {
        if ((pow(x - xc, 2) + pow(y - yc, 2)) <= r)
            return true;
        else
            return false;
    };

    /* Основной алгоритм */
    double minSquare = numeric_limits<double>::max(); // для поиска минимальной площади
    bool isAllPointsInCircle = false;
    double square;
    double _x_first = 0, _y_first = 0, _x_second = 0, _y_second = 0, _x_third = 0, _y_third = 0;  // будут содержать конечные точки


    for (int i1 = 0; i1 < amountOfPoints; i1++) {
        for (int i2 = i1 + 1; i2 < amountOfPoints; i2++)
            for (int i3 = i2 + 1; i3 < amountOfPoints; i3++) {
                circleEquation = findOutCircleEquation(x1[i1], y1[i1], x1[i2], y1[i2], x1[i3], y1[i3]);
                xc = -1 * circleEquation[0];
                yc = -1 * circleEquation[1];
                r = pow(xc, 2) + pow(yc, 2) - circleEquation[2];

                isAllPointsInCircle = true;
                for (int j = 0; j < amountOfPoints; j++) {
                    if (!doesItBelongToCircle(x2[j], y2[j], xc, yc, r)) {
                        isAllPointsInCircle = false;
                        break;
                    }
                }

                double square = 2 * 3.14 * r;
                if (square <= minSquare) {
                    minSquare = square;
                    _x_first = x1[i1];
                    _y_first = y1[i1];
                    _x_second = x1[i2];              
                    _y_second = y1[i2];
                    _x_third = x1[i3];
                    _y_third = y1[i3];
                }
            }
    }


    cout << _x_first << "; "
         << _y_first << "; "
         << _x_second << "; "
         << _y_second << "; "
         << _x_third << "; "
         << _y_third << "; ";

}

int main()
{
    var3();
}
