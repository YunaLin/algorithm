#include <vector>
#include <iostream>
using namespace std;
vector<char> data;
// 如果下面这种初始化无法通过的话,就使用if (mymap.size() == 0) mymap.resize(200,0)
vector<int> mymap(200, 0);
//Insert one char from stringstream
void Insert(char ch)
{
    mymap[ch - '0'] += 1;
    data.push_back(ch);
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    int n = mymap.size();
    for (int i = 0; i < n; ++i) {
        if (mymap[data[i] - '0'] == 1)
            return data[i];
    }
    return '#';
}
int main() {
    return 0;
}
