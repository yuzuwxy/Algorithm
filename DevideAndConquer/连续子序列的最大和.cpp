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
 * 伪动态规划/贪心
*/
int main () {
	int array[MAXN + 7] = {0};
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) 
		cin >> array[i];

	int globalMax = array[1], localMax = 0;
	for(int i = 1; i <= n; i ++) {
		localMax += array[i];
		globalMax = max(localMax, globalMax);
		localMax = max(0, localMax);
	}

	cout << globalMax;
	return 0;
}