#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

// ��������Ҫ�ı�ԭ�����ַ����������ܹ�ֱ�Ӵ�ӡ������������´����µ��ַ��� 
void replaceSpace(char *str,int length) {
	if (str == NULL || length < 0) return;
	int initialLen = 0;
	int newLen = 0;
	int spaceNum = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		initialLen++;
		if (str[i] == ' ') spaceNum++;
	}  
	newLen = initialLen + spaceNum*2;
	if (newLen > length) return;
	for (int i = initialLen; i >= 0; --i) {
		if (str[i] == ' ') {
			str[newLen--] = '0';
			str[newLen--] = '2';
			str[newLen--] = '%';
		} else {
			str[newLen--] = str[i];
		}
	}
}

int main() {
	char *str;
	string temp;
	getline(cin, temp);
	str = const_cast<char*>(temp.c_str());
	replaceSpace(str, 100); 
	cout << str << endl;
	return 0;
} 
