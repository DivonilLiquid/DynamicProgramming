                                                    /*top down*/
/*
Given n wines in a row, with integers denoting the cost of each wine respectively.
Each year you can sale the first or the last wine in the row. The price of wines increases over time.
Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*Pi.
For each year, your task is to print start or end denoting whether first or last wine should be sold.
Also, calculate the maximum profit from all the wines.
If wine prices are {2, 4, 6, 2, 5} then output will be:
start end end start start
Maximum profit = 64
*/
#include <iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<iomanip>
using namespace std;
int dp[100][100];
int maxprofit(int *arr,int b,int e,int y){
    if(b>e){
        return 0;
    }
    if(dp[b][e]!=-1){
        return dp[b][e];
    }
    int a1=arr[b]*y+maxprofit(arr,b+1,e,y+1);
    int a2=arr[e]*y+maxprofit(arr,b,e-1,y+1);
    int ans=max(a1,a2);
    dp[b][e]=ans;
    return ans;
}
int main()
{
    int arr[]={2,4,6,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<maxprofit(arr,0,n-1,1)<<endl;
    setw(3);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
