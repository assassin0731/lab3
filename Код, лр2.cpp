#include <iostream>
#include <random> 
#include <cmath>  
#include <numeric>
#include <algorithm>

using namespace std;

int GCD(int u, int v) {
	while (v != 0) {
		int r = u % v;
		u = v;
		v = r;
	}
	return u;
}

int FindC(int p)
{
	int b,z=1,a=0;
	b = rand() % 50 + 2;
	while (z) 
	{
		if ((GCD(b, p - 1) == 1) && (b != 1))
		{
			z = 0;
			
		}
		else if (b == 1)
			b = rand() % 100 + 2;
		else 
			b = b - 1;
	}
	return b;
}

int FindD(int Ca, int p)
{
	int b,z=1,a=0;
	b = rand() % 150+2;
	while (z)
	{
		if (((Ca * b) % p == 1) && (b != 1))
		{
			z = 0;
		}
		else if (b == 1)
			b = rand() % 150 + 2;
		else 
			b = b - 1;
	}
	return b;
}

int chislo_p(int m)
{
	int p;
	static time_t tval = time(0);
	tval += 10;
	srand(tval);
	do
	{
		while (1)
		{
			int z = 0, kol = 0;
			p = 1 + rand() % 150;
			for (int i = 2; i < p; i++)
			{
				if (p % i == 1)
					continue;
				if (p % i == 0)
				{
					z = 1;
					break;
				}
			}
			if (z == 0)
			{
				break;
			}
		}
	} 	while (p <= m);
	return p;
}

long long int degree(int a, int x, int p)
{
	long long int r = 1;
	while (x != 0)
	{
		if (x % 2 == 0)
		{
			a = (a * a) % p;
			x = x / 2;
		}
		else
		{
			x--;
			r = (r * a) % p;
		}
	}
	return r;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int m, p,Ca,Da,Cb,Db,x1,x2,x3,x4,i;
	char word[20] = {}, wordX1[20] = {}, wordX2[20] = {}, wordX3[20] = {}, wordX4[20] = {};
	cout << "*Шифр Шамира*" << endl << endl;
	cout << "Введите передаваемое слово на английском:" << endl;
	cin >> word;
	for (i = 0; i < strlen(word); i++)
	{
		m = word[i];
		p = chislo_p(m);
		cout << "Случайное простое число p:" << endl << p << endl << endl;
		Ca = FindC(p);
		cout << "Ca=" << Ca << endl;
		Da = FindD(Ca, p - 1);
		cout << "Da=" << Da << endl;
		cout << Ca << "*" << Da << " mod " << p - 1 << "=" << (Ca * Da) % (p - 1) << endl << endl;

		

		Cb = FindC(p);
		cout << "Cb=" << Cb << endl;
		Db = FindD(Cb, p - 1);
		cout << "Db=" << Db << endl;
		cout << Cb << "*" << Db << " mod " << p - 1 << "=" << (Ca * Da) % (p - 1) << endl << endl;
		x1 = degree(m, Ca, p);
		wordX1[i] = char(x1);
		cout << "A->B: " << x1 << "=" << char(x1) << endl;
		x2 = degree(x1, Cb, p);
		wordX2[i] = char(x2);
		cout << "B->A: " << x2 << "=" << char(x2) << endl;
		x3 = degree(x2, Da, p);
		wordX3[i] = char(x3);
		cout << "A->B: " << x3 << "=" << char(x3) << endl;
		x4 = degree(x3, Db, p);
		wordX4[i] = char(x4);
		cout << "B: " << x4<<"="<<char(x4) << endl;
		system("pause");
	}
	cout << endl;
	cout << "A->B: " << wordX1 << endl;
	cout << "B->A: " << wordX2 << endl;
	cout << "A->B: " << wordX3 << endl;
	cout << "B: " << wordX4 << endl;
	return 0;
}