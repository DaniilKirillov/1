// Напишите функцию находящую корень монотонной вещественной функции f бинарным поиском(бисекцией). Можно считать что корень обязательно существует. Корнем будем считать значение x, такое что |f(x)|<10^(-6).  В комментариях напишите, почему решение- эффективное


#include <iostream>
#include <cmath>
using namespace std;

// Функция, определяющая знак числа
int sign(int num) {
	if (num == 0)  return 0;
	if (num > 0)  return 1;
	else return -1;
}

int main() {
	double x1, x2, xc;
	double f(double x);
	if (abs(f(x1)) <= pow(10, -6)) cout << x1;
	if (abs(f(x2)) <= pow(10, -6)) cout << x2;
	double d = (x1 - x2) / 2;
	double i = x1 + d;
	while (abs(f(x1) - f(x2)) > pow(10, -6)) {
		double d = (x1 - x2) / 2;
		double i = x1 + d;
		if (sign(f(i)) == sign(f(x2))) {
			x2 = i;
		}
		else x1 = i;
	}
	cout << i;
		return 0;
}

//Для большей эффективности алгоритма было использование сравнение знаков чисел, а не сравнение с нулём их произведения.