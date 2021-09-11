10.
Problem: From a graph with n vertices and only clear paths between connected vertices, create an adjacency matrix with n*n elements representing the graph and enter any two vertices, ask if those two vertices are related. communicate with each other or not?
Solution: Make a matrix n*n. Set element value (i,j)= 0 when there is no connecting path from (i+1) to (j+1) and vice versa equal to 1 if there is a direct path from (i+1) to (j) +1). From the matrix, traverse the position of the two entered vertices and check if they are connected (the input value (i,j) is 0 or 1)
Code:
#include <iostream>

using namespace std;

struct graph {
	int matrix[50][50];
	int n;
};

void addPath(graph& g, int x, int y) {
	g.matrix[x - 1][y - 1] = 1;
	g.matrix[y - 1][x - 1] = 1;
}

bool test(graph G, int x, int y) {
	return (G.matrix[x - 1][y - 1] != 0);
}

int main() {
	graph G;
	int choice = 1, x, y;

	cout << "n= ";
	cin >> G.n;
	for (int i = 0; i < G.n; i++)
		for (int j = 0; j < G.n; j++)
			G.matrix[i][j] = 0;
	do {
		cout << "Add the path from x to y to the graph: " << endl;
		cout << "x= ";
		cin >> x;
		cout << "y= ";
		cin >> y;
		addPath(G, x, y);
		cout << "Enter any number to continue, want to stop entering 0: ";
		cin >> choice;
	} while (choice != 0);
	cout << "Graph representation matrix:" << endl;
	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++)
			cout << G.matrix[i][j] << "   ";
		cout << endl;
	}

	cout << "Check the connection between vertices x and y:";
	cout << "\nx= ";
	cin >> x;
	cout << "y= ";
	cin >> y;
	bool flag = test(G, x, y);
	if (flag == true)
		cout << "There is a direct path from vertex " << x << " to " << y;
	else cout << "Trackless";

	return 0;
}
