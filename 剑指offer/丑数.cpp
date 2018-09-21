// 把只包含质因子2、3和5的数称作丑数（Ugly Number）
// 习惯上将1作为第一个丑数
int Min(int a, int b, int c) {
    int temp = a < b ? a:b;
    return temp < c?temp:c;
}
int GetUglyNumber_Solution(int index) {
    int* data = new int[index];
    int *p2 = data;
    int *p3 = data;
    int *p5 = data;
    data[0] = 1;
    int count = 1;
    int min = 0;
    while (count < index) {
        min = Min(*p2*2, *p3*3, *p5*5);
        data[count++] = min;
        while (*p2*2 <= min) p2++;
        while (*p3*3 <= min) p3++;
        while (*p5*5 <= min) p5++;
    }
    return data[count - 1];
}