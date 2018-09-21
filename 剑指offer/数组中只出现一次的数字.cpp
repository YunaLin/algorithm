#include <iostream>
#include <vector>
#include <map>
using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    map<int, int> mymap;
    int n = data.size();
    for (int i = 0; i < n; ++i) {
        mymap[data[i]]++;
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (mymap[data[i]] == 1) {
            if (flag == false) {
                *num1 = data[i];
                flag = true;
            } else {
                *num2 = data[i];
                break;
            }
        }
    }
}

int main() {
    vector<int> data;
    int num, n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        data.push_back(num);
    }
    int* num1 = new int;
    int* num2 = new int;
    FindNumsAppearOnce(data, num1, num2);
    cout << *num1 << " " << *num2 << endl;
    return 0;
}