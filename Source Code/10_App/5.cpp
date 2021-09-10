// 5.
// Problem: Put n people in a row in order from highest to lowest by the 2 people in front swap with the person behind if taller and repeat until the row is complete. Count the number of items needed to complete the order as required.
// Solution: Implement bubble sort algorithm in order from smallest to largest for n arrays containing height information of each person.
// Code:
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

int main(){
    srand((int)time(0));
    int n, a[100], k = 0;

    cout << "n= ";
    cin >> n;
    cout << "At first: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 200 + 1;
        cout << a[i] << " ";
    }

    cout << "\nAfter: ";
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                k++;
            }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\nNumber of times to change places: " << k << endl;

    return 0;
}
