#include<stdio.h> //підключення бібліотек
#include<math.h>
#include<locale.h>
//прототип ф. для обчислення суми ряду
double cacul(double a, double b, double d, double (*f)(double));
// прототипи для ф.1 та ф.2
double f1(double x);
double f2(double x);

int main() {
    //встановлення локалізації
    setlocale(LC_CTYPE, "ukr");
    //змінні для меж
    double a, b, d;
    //змінні для результату 
    double Y1, Y2;
    //введення данних
    printf("Введiть межу а: ");
    scanf_s("%lf", &a);
    printf("Введiть межу b: ");
    scanf_s("%lf", &b);
    printf("Введiть крок d: ");
    scanf_s("%lf", &d);
    printf("\n");
    //використання функції
    Y1 = cacul(a, b, d, f1);
    Y2 = cacul(a, b, d, f2);
    //вивід результатів 
    printf("Результати:\n");
    printf("Y1 = %.2lf\nY2 = %.2lf", Y1, Y2);

    return 0;
}
//визначення ф. для пошуку суми ряду
double cacul(double a, double b, double d, double (*f)(double)) {
    double s = 0;
    for (double x = a; x <= b; x += d) {
        double Y = f(x);
        if (Y > 0) {
            s += Y;
        }
    }
    return s;
}
//визначення ф.1
double f1(double x) {
    return atan(x);
}
//визначення ф.2
double f2(double x) {
    return (pow(5, x) - 2 * x) / (5 * x);
}
