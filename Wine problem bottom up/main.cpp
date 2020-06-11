#include <iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<cstring>
using namespace std;
int dp[100][100];
int maxvalue(int *arr,int e,int s,int y,int t){
    if(s>e){
        return t;
    }
    int x1=arr[s]*y+maxvalue(arr,e,s+1,y+1,t);
    int x2=arr[e]*y+maxvalue(arr,e-1,s,y+1,t);
    t=max(x1,x2);
    return t;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    setw(3);
    cout<<maxvalue(a,n-1,0,1,0);
    return 0;
}
