#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int>& A) {
    int multi = 1;
    int n = A.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        multi = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j)
                multi *= A[j];
        }
        res.push_back(multi);
    }
    return res;
}