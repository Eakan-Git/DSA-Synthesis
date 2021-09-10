// 3.
// Problem: Load n bullets into a shotgun, firing m consecutively (m<=n). Is the gun still ammo?
// Solution: Each loaded bullet will be pushed to the bottom and the first loaded bullet must be the last to be fired. Therefore, we number each bullet and make a stack with 3 main operations: add an element to the top, get an element from the top of the stack and check if the stack is empty or not.
// Code:
#include <iostream>

using namespace std;

struct node {
    int data;
	node* next;
};

node* createNode(int x) {
    node* temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

bool isEmpty(node* S) {
    if (S == NULL) {
        cout << "No more bullet" << endl;
        return true;
    }
    cout << "Gun with ammo" << endl;
    return false;
}

void push(node*& S, int x) {
    node* p = createNode(x);
    p->next = S;
    S = p;
}

node* pop(node*& S) {
    node* p = S;
    S = S->next;
    p->next = NULL;
    return p;
}

int main(){
    node* S{};
    int n, x, m;
    cout << "n= ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Number you want to mark: ";
        cin >> x;
        push(S, x);
    }
    cout << "m= ";
    cin >> m;
    for (int i = 0; i < m; i++)
        pop(S);
    bool flag = isEmpty(S);

    return 0;
}
