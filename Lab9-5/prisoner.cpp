#include <iostream>
using namespace std;
int main() {
    int n;
    int prisoner_num;
    int i,j,k;
    int prisoner_not_present = 0;
    int jail[100] = {0};
    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> prisoner_num;
        jail[prisoner_num] = 1;
        if (prisoner_num > prisoner_not_present) {
            prisoner_not_present = prisoner_num;
        }
    }

    for(j = 1;j <= prisoner_not_present; j++) {
        if (j % 2 != 0) {
            if (jail[j] == 0) {
                cout << j << " ";
            }
        }
    }

    cout << endl;
    
    for(k = 1;k <= prisoner_not_present; k++) {
        if (k % 2 == 0) {
            if (jail[k] == 0) {
                cout << k << " ";
            }
        }
    }
    cout << endl;
    return 0;

}