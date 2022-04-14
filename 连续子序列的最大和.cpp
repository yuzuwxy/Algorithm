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

/**
 * 子序列最大和
 * 老师上课讲的是分治（但是感觉有点强行分治
 * 用伪动规或者说贪心
*/
int main () {
	int array[MAXN + 7] = {0};
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) 
		cin >> array[i];

	int globalMax = array[1], localMax = 0;
	for(int i = 1; i <= n; i ++) {
		localMax += array[i];						// 包含当前值的局部最大值
		globalMax = max(localMax, globalMax);		// 更新子序列和的最大值
		localMax = max(0, localMax);				// 加到0就说明前面的序列不满足条件
	}

	cout << globalMax;
	return 0;
}