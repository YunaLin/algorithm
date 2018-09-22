// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
#include <vector>
#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
    vector<int> data(length, 0);
    // 对输入进行判断
    if (length <= 0 || numbers == NULL) return false;
    for (int i = 0; i < length; i++) {
        data[numbers[i]]++;
    }
    int index = 0;
    for (int i = 0; i < length; ++i) {
        // 只要找到一个就可以
        if (data[numbers[i]] > 1) {
            duplication[index++] = numbers[i];
            return true;
        }
    }
    return false;
}

int main() {
    int numbers[5] =  {2,1,3,1,4};
    int* dup = NULL;
    cout << duplicate(numbers, 5, dup);
    while (dup != NULL) {
        cout << *dup << " ";
        dup++;
    }
    cout << endl;
    return 0;
}