﻿// Напишите программу, находящую натуральные корни уравнения 2020X + 2021Y = 78487894 эффективным перебором.В комментариях напишите, почему перебор - эффективный

#include <iostream>
using namespace std;
int main() {
	int k;
	int x, y;
/* Надём минимальный натуральный y. y = 1683. x = 78487894 - 2020k, y = -78487894 + 2021k. k = 38837
Найдём минимальный натуральный x. x = 794 при k = 38854. Переберём каждый k от 38837 до 38854. */

	for (int k = 38854; k >= 38837; k--) {
		x = 78487894 - 2020 * k;
		y = -78487894 + 2021 * k;
			cout << "x = " << x << " " << "y = " << y << endl;
	}
	return 0;
}