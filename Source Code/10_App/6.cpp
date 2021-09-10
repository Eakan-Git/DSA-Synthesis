// 6.
// Problem: Make a diagram of an exam room with 28 seats (8 rows, 4 columns) according to the number of each student and in the direction from small to large so that the student with the smallest number is sitting in the left corner of the first row. and the next number is to the right of the student with the smallest number, and so on until the last place (sorted from left to right, top to bottom)
// Solution: Make a 2-dimensional array of 8 rows, 4 columns and implement the Selection Sort algorithm to select the student with the smallest number to be placed in the first element of the array, do the same until the last element.
// Code:
#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand((int)time(0));
    int n, a[28], k1 = 0, k2 = 0;
    int b[7][4];

    for (int i = 0; i < 28; i++) 
        a[i] = rand() % 9000 + 1000;

    for (int i = 0; i < 27; i++) {
        int minIndex = i;
        int minValue = a[i];
        for (int j = i + 1; j < 28; j++)
            if (a[j] < minValue) {
                minIndex = j;
                minValue = a[j];
            }
        a[minIndex] = a[i];
        a[i] = minValue;

        b[k1][k2] = minValue;
        k2++;
        if (k2 == 4) {
            k2 = 0;
            k1++;
        }
    }
    cout << "Class diagram (excluding the teacher's desk): " << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++)
            cout << b[i][j] << "   ";
        cout << endl;
    }

    return 0;
}
