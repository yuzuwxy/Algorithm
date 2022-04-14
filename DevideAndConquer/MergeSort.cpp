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

int n;
int Array[MAXN + 7] = {0};
int temp[MAXN];
int ans=0;

void MergeSort(int s,int t)
{
    if(s==t) return;
    int mid=(s+t)>>1;
    MergeSort(s,mid);
    MergeSort(mid+1,t);
    int i=s,j=mid+1,k=s;
    while(i<=mid&&j<=t){
         if(Array[i]<=Array[j]){
              temp[k]=Array[i];
              k++;
              i++;
         }
         else{
              temp[k]=Array[j];
              j++;
              k++;
              ans+=mid-i+1; 		// 这个应该是计算的交换次数？？
         }
    }
    while(i<=mid){
        temp[k]=Array[i];
        k++;
        i++;
    }
    while(j<=t){
        temp[k]=Array[j];
        k++;
        j++;
    }
    for(int i=s;i<=t;i++){ 
        Array[i]=temp[i];
    }
}

/**
 * 归并排序
*/              
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> Array[i];

    MergeSort(1,n);

    for(int i=1;i<=n;i++)
         printf("%d ",Array[i]);
    printf("\n");

    return 0;
}