#include <vector>
#include <algorithm>
using namespace std;

bool IsContinuous( vector<int> numbers ) {
    sort(numbers.begin(), numbers.end());
    int n = numbers.size();
    if (n < 5) return false;
    int begin = 0;
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        if (numbers[i] != 0) {
            begin = numbers[i];
            count = i;
            break;
        }
    }
    // 0 0 1 3 5
    int end = numbers[4];
    if (end == 0) return true;
    // 连续的几个非0的数字不能重复,非0数字的距离不能大于4,否则有0也无法填充
    if (end - begin >= (5-count-1) && (end-begin)<=4) return true;
    return false;
}