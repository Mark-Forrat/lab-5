#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int** change(int i, int j, int n, int** a)
{
	int* h = new int[n];
	
	for (int k = 0; k < n; ++k)
	{
		h[k] = a[i][k];
		a[i][k] = a[k][j];
		a[k][j] = h[k];
	}
	return(a);
}
void write(int n, int** a)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	int n = 5;
	int** a = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = rand() % 10;
		}
	}
	write(n, a);
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i][0] == a[0][j])
			{
				a = change(i, j, n, a);
			}
		}
	}
	write(n, a);
}