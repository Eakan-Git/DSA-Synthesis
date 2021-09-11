7.
Problem: Given a 2-dimensional array of size n*n containing positive integers. Rearrange the elements of the matrix in the zigzag direction.
Solution: Implement the function to sort the matrix elements row by row: sort the elements on the even rows ascending from left to right and the elements on the odd rows ascending from right to left. Then, perform the function to sort the elements on each column: in ascending order from top to bottom. Repeat the above 2 functions consecutively n times, we will get the required matrix.
Code: 
#include <iostream>
#include <ctime>

using namespace std;

void swap(int* a, int* b) {
	int* c;

	c = new int;

	*c = *a;
	*a = *b;
	*b = *c;

	delete c;
}

void bubbleSort(int a[], int n) {
	for (int i = 1; i < n; i++)
		for (int j = n - 1; j >= i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

void sortColumn(int** a, int n) {
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			p[j] = a[j][i];
		bubbleSort(p, n);
		for (int j = 0; j < n; j++)
			a[j][i] = p[j];
	}
	delete[]p;
}

void sortRow(int **a, int n) {
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++)
				p[j] = a[i][j];
			bubbleSort(p, n);
			for (int j = 0; j < n; j++)
				a[i][j] = p[j];
		}
		else {
			for (int j = 0; j < n; j++)
				p[j] = a[i][n - j - 1];
			bubbleSort(p, n);
			for (int j = 0; j < n; j++)
				a[i][n - j - 1] = p[j];
		}
	}
	delete[]p;
}

int main() {
	srand((int)time(0));
	int n, x;
	cout << "n= ";
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	cout << "Initial: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 1000;
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		sortRow(a, n);
		sortColumn(a, n);
	}
	cout << "After:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}

	return 0;
}
