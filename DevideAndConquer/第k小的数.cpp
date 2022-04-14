#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>

#define ll long long
#define Endl endl
#define MAXN (int)1e5

using namespace std;

int Array[MAXN + 7] = {0};
int n, k;

int Partition(int left, int right) {
	int i = left, j = right;
	int tmp = Array[left];
	while(i < j) {
		while(i < j && Array[j] >= tmp) j --;
		Array[i] = Array[j];
		while(i < j && Array[i] <= tmp) i ++;
		Array[j] = Array[i];
	}
	Array[i] = tmp;
	return i;
}

int Func(int left, int right) {
	int pos = Partition(left, right);
	if(pos == k) return Array[pos];

	if(pos < k) return Func(pos + 1, right);
	else return Func(left, pos);
}

/**
 * 寻找序列中第k小的数
 * 运用快速排序的思想
*/
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) 
		cin >> Array[i];

	int ans = Func(1, n);
	cout << ans << endl;

	return 0;
}