#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	vector< vector<int> > arr;
	for (int i = 0; i < n; ++i) {
		vector<int> temp;
		for (int j = 0; j < n; ++j) {
			cin >> num;
			temp.push_back(num);
		}
		arr.push_back(temp);
	}
	cout << "n:" << n << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	
	int target;
	cin >> target;
	int indexI = 0;
	int indexJ = n - 1;
	while (indexI < n && indexJ >= 0) {
		cout << "here" << endl;
		cout << arr[indexI][indexJ];
		if (target == arr[indexI][indexJ]) {
			cout << "true" << endl;
			return 0;
		}
		else if (target > arr[indexI][indexJ]) {
			indexI++;
			cout << "bigger" << endl;	
		}
		else {
			indexJ--;
			cout << "samller" << endl; 
		}
	}
	
	cout << "false" << endl;
	return 0;
} 
