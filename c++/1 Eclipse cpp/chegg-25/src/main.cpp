/*
 * main.cpp
 *
 *  Created on: 17-Jul-2020
 *      Author:
 */

#include <iostream>
#include "p025.h"
using namespace std;

int main() {
    int n, k, val;
    cin >> n;
    MyList list;
    for (int i=0;i<n;i++) {
        cin >> k >> val;
        if (k==0){
            list.prepend(val);
        } else if (k==1) {
            list.append(val);
        } else if (k==2) {
            cout << list.get(val) << endl;
        } else {
            int op;
            cin >> op;
            cout << list.give(val, op) << endl;
        }
    }
    return 0;
}


