#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> result;
    int row = matrix.size();
    int col = matrix[0].size();
    // 圈数
    int circles = ((row < col ? row : col)-1)/2 + 1;
    for (int i = 0; i < circles; ++i) {
        // 四个方向
        for (int j = i; j < col - i; ++j)
            result.push_back(matrix[i][j]);
        for (int k = i +1; k < row - i; ++k)
            result.push_back(matrix[k][col - i - 1]);
        // 可能这一圈并没有两行或者两列
        for (int m = col - i - 2; m >= i && (row - i - 1 != i); --m)
            result.push_back(matrix[row - i - 1][m]);
        for (int n = row - i - 2; n > i && (col - i - 1 != i); --n)
            result.push_back(matrix[n][i]);
    }
    return result;
}

int main() {
    int n, m, num;
    cin >> n >> m;
    vector< vector<int> > data;
    vector<int> row;
    for (int i = 0; i < n; ++i) {
        row.clear();
        for (int j = 0; j < m; ++j) {
            cin >> num;
            row.push_back(num);
        }
        data.push_back(row);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> result = printMatrix(data);
    cout << result.size() << endl;
//    for (int i = 0; i < result.size(); ++i) {
//        cout << result[i] << " "; 
//    }
//    cout << endl; 
    return 0;
}
