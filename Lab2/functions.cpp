#include "functions.h"



int multEvenNumbers3(int* mass, int size) {
    int answer = 1;
    for (int i = 0; i < size; i += 2) {
        answer *= *(mass + i);
    }
    return answer;
}

int sumBetweenZeroes3(int* mass, int size) {
    int first = -1, last = -1;
    int answer = 0;
    for (int i = 0; i < size; i++) {
        if (*(mass + i) == 0) {
            if (first != -1)
                last = i;
            else
                first = i;
        }
    }
    if (first != -1 && last != -1) {
        for (int i = first; i <= last; i++) {
            answer += mass[i];
        }
        return answer;
    }
    else
        throw NotFoundZero;
}

void chngMsFirstPlus3(int* mass, int size) {
    int* buf = new int[size];
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (mass[i] >= 0) {
            buf[count] = mass[i];
            count++;
        }
    }
    for (int i = 0; i < size; i++) {
        if (mass[i] < 0) {
            buf[count] = mass[i];
            count++;
        }
    }
    for (int i = 0; i < size; i++) {
        mass[i] = buf[i];
    }

    delete[] buf;
}



int elLesThanC18(double* mass, int size, double c) {
    int answer = 0;
    for (int i = 0; i < size; i++) {
        if (mass[i] < c) answer++;
    }
    return answer;
}

double sumAfterMinus18(double* mass, int size) {
    int last = -1;
    double answer = 0;
    for (int i = 0; i < size; i ++) {
        if (mass[i] < 0) last = i;
    }
    if (last != -1 && last != size)
    {
        for (int i = last + 1; i < size; i++) {
            answer += trunc(mass[i]);
        }
    }
    else
        throw WrongValue;

    return answer;
}

void chngMs18(double* mass, int size) {
    double* buf = new double[size];
    int count = 0;
    double max = mass[0];
    for (int i = 1; i < size; i++) {
        if (mass[i] > max) {
            max = mass[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (abs(max - mass[i]) <= abs(max * 0.2))
        {
            buf[count] = mass[i];
            count++;
        }
    }
    for (int i = 0; i < size; i++) {
        if (abs(max - mass[i]) > abs(max * 0.2))
        {
            buf[count] = mass[i];
            count++;
        }
    }
    for (int i = 0; i < size; i++) {
        mass[i] = buf[i];
    }

    delete[] buf;
}