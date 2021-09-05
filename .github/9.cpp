9.
Problem: Given a matrix of numbers n*n (n<=6) containing numbers from 1 to 100. Looking at it once, can you win by entering perfectly n*n numbers in the matrix?
Solution: Make a matrix n*n, use the search algorithm to see if the input matches the array to look for
Code:
#include <iostream>
#include <ctime>

using namespace std;

bool linearSearch(int a[], int x,int n) {
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return true;
	return false;
}


int main() {
	srand((int)time(0));
	int n, x, choice;
	cout << "n= ";
	cin >> n;
	
	int a[6][6];
	int b[36] = { 0 }, k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100 + 1;
			b[k] = a[i][j];
			k++;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	k = 0;
	cout << "You are ready press 0.";
	cin >> choice;
	if (choice == 0) {
		system("cls");
		for (int i = 0; i < n * n; i++) {
			cout << "Number you remember: ";
			cin >> x;
			bool flag = linearSearch(b, x, (n * n));
			if (flag == false) {
				cout << "Wrong number! You lose!" << endl;
				break;
			}
			else {
				cout << "Enter correctly! Try your best!" << endl;
				k++;
			}
		}
	}
	if (k == (n * n))
		cout << "You win!!!";
	return 0;
}
