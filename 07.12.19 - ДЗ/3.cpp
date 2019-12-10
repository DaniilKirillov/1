// Для чисел Фибоначчи известны некоторые тождества:
//Докажите эти тождества и напишите программу для вычисления ЧФ с помощью разделяй и властвуй.


#include <iostream>
using namespace std;

int Fib(int n) {
	if (n < 3) return 1;
	else return Fib(n - 1) + Fib(n - 2);
}

int main() {
	int n;
	cin >> n;
	cout << Fib(n);
	return 0;
}