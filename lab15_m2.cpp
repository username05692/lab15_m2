#include<stdio.h> //���������� �������
#include<math.h>
#include<locale.h>
//�������� �. ��� ���������� ���� ����
double cacul(double a, double b, double d, double (*f)(double));
// ��������� ��� �.1 �� �.2
double f1(double x);
double f2(double x);

int main() {
    //������������ ����������
    setlocale(LC_CTYPE, "ukr");
    //���� ��� ���
    double a, b, d;
    //���� ��� ���������� 
    double Y1, Y2;
    //�������� ������
    printf("����i�� ���� �: ");
    scanf_s("%lf", &a);
    printf("����i�� ���� b: ");
    scanf_s("%lf", &b);
    printf("����i�� ���� d: ");
    scanf_s("%lf", &d);
    printf("\n");
    //������������ �������
    Y1 = cacul(a, b, d, f1);
    Y2 = cacul(a, b, d, f2);
    //���� ���������� 
    printf("����������:\n");
    printf("Y1 = %.2lf\nY2 = %.2lf", Y1, Y2);

    return 0;
}
//���������� �. ��� ������ ���� ����
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
//���������� �.1
double f1(double x) {
    return atan(x);
}
//���������� �.2
double f2(double x) {
    return (pow(5, x) - 2 * x) / (5 * x);
}
