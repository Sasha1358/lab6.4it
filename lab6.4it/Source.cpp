#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h> 
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
}

int FindMinAbs(int* a, const int size)
{
	if (size == 0) {
		return 0; // Повернути 0 в разі пустого масиву.
	}

	int minAbs = abs(a[0]); // Початкове значення мінімального за модулем.

	for (int i = 1; i < size; i++) {
		int absValue = abs(a[i]);
		if (absValue < minAbs) {
			minAbs = absValue; // Оновити мінімальне за модулем значення, якщо знайдено менше.
		}
	}

	return minAbs;
}

int SumAbsAfterFirstZero(int* a, const int size)
{
	int sum = 0;
	bool foundFirstZero = false;

	for (int i = 0; i < size; i++) {
		if (foundFirstZero) {
			sum += abs(a[i]);
		}

		if (a[i] == 0) {
			foundFirstZero = true;
		}
	}

	return sum;
}

void TransformArray(int* a, const int size)
{
	int* result = new int[size];
	int evenIndex = 0;
	int oddIndex = size / 2;

	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			result[evenIndex] = a[i];
			evenIndex++;
		}
		else {
			result[oddIndex] = a[i];
			oddIndex++;
		}
	}

	for (int i = 0; i < size; i++) {
		a[i] = result[i];
	}

	delete[] result;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
    int n;
	cout << "n = ";cin >> n;
	

	int* a = new int[n];
	int Low = -10;
	int High = 10;

	Create(a, n, Low, High, 0);
	cout << "Початковий масив  = [";  Print(a, n);cout << "  ]" << endl;
	
	int minAbs = FindMinAbs(a, n);
	cout << "Мінімальний за модулем елемент масиву: " << minAbs << endl;

	int sumAfterFirstZero = SumAbsAfterFirstZero(a, n);
	cout << "Сума модулів елементів після першого нульового елемента: " << sumAfterFirstZero << endl;

	TransformArray(a, n);

	cout << "Масив після перетворення = [";Print(a, n);cout << "  ]" << endl;

	delete[] a; // Звільнити виділену пам'ять для масиву.

	return 0;
}
