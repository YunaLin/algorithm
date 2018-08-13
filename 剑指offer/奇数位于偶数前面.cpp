// 这是最简单的解决方法，思考其他思路
void reOrderArray(vector<int> &array) {
    int len = array.size();
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < len; ++i) {
        if (array[i] % 2 == 0) even.push_back(array[i]);
        else odd.push_back(array[i]);
    }
    int odd_len = odd.size();
    int even_len = even.size();
    for (int i = 0; i < odd_len; ++i)
        array[i] = odd[i];
    for (int i = 0; i < even_len; ++i)
        array[i + odd_len] = even[i];
}