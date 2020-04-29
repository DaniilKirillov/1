#include <iostream>
#include <cmath>
using namespace std;

pair<long long, long long> GenOpenKey(long long e, long long multip)
{
	return pair<long long, long long>(e, multip);
}

pair <long long, long long> GenPrivateKey(long long d, long long multip)
{
	return pair <long long, long long>(d, multip);
}

long long encryptRSA(pair<long long, long long> p1, int m)
{
	long long temp = 1;
	for (long long i = 0; i < p1.first; i++)
	{
		temp *= m % p1.second;
		temp = temp % p1.second;
	}
	return temp;
}

long long decryptRSA(pair<long long, long long> p1, int encrypt)
{
	long long temp = 1;
	for (long long i = 0; i < p1.first; i++)
	{
		temp *= encrypt % p1.second;
		temp = temp % p1.second;
	}
	return temp;
}

int main()
{
	setlocale(LC_ALL, "ru");
	long long firstnum; 
	cout << "Введите первое простое число:\t"; cin >> firstnum;
	cout << endl;
	long long secondnum;
	cout << "Введите второе простое число:\t"; cin >> secondnum;
	cout << endl;
	long long multip = firstnum * secondnum;
	long long eulerfunc = (firstnum - 1) * (secondnum - 1);
	cout << "Выберите число e, взаминопростое с " << eulerfunc << ":\t";
	long long e; cin >> e;
	// Находим d такое, что d*e = 1(mod eulerfunc):
	long long d = 0;
	for (long long i = 0; i < eulerfunc * 1000; i++)
	{
		if ((i * e) % eulerfunc == 1) 
		{
			d = i;
			break;
		}
	}
	if (d == 0)
	{
		cout << "Ошибка, выберите другой e." << endl;
		return 0;
	}

	pair <long long, long long> OpenKey(GenOpenKey(e, multip));
	pair <long long, long long> PrivateKey(GenOpenKey(d, multip));
	int message;
	cout << endl;
	cout << "Введите ваше сообщение:\t";
	cin >> message;
	cout << endl;
	cout << "Зашифрованное сообщение:\t" << encryptRSA(OpenKey, message) << endl;
	cout << "Расшифрованное сообщение:\t" << decryptRSA(PrivateKey, encryptRSA(OpenKey, message)) << endl;
}