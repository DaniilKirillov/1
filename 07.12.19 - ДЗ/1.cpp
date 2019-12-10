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

// Ввод произвольной функции
double func(double x) {
	return (pow(x, 2) - 99);
}

int main() {
	double x1, x2;
	cin >> x1 >> x2;
	if (abs(func(x1)) <= pow(10, -6)) cout << x1;
	if (abs(func(x2)) <= pow(10, -6)) cout << x2;
	double i;
	while (abs(x2 - x1) > pow(10, -6)) {
		double d = (x2 - x1) / 2;
		i = x1 + d;
		if (sign(func(i)) != sign(func(x1))) {
			x2 = i;
		}
		else x1 = i;
	}
	cout << i;
	return 0;
}

//Для большей эффективности алгоритма было использование сравнение знаков чисел, а не сравнение с нулём их произведения.