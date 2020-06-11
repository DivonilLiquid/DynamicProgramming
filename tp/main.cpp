#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int *a = new int [n];
    int m=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m=max(m,a[i]);
    }
    int map[m]={0};
    for(int i=0;i<n;i++){
        map[a[i]]++;// kitne elements hai total with repetation
    }
    int mflag=1;//yes
    for(int i=0;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(map[i]==map[j]){
                mflag=0;
            }
        }
    }
    if(mflag=0){
        cout<<"NO"<<endl;
    }
    else{
        vector<int>v;
        int i=0;
        while(i<n){
            int k=i;
            while(a[k]==a[k+1]){
                k++;
            }
            v.push_back(a[k]);
            i=k+1;
        }
        int map2[m]={0};
        int flag=1;//yes
        for(auto i: v){
            if(map2[i]!=0){
                flag=1;//no
            }
            else{
                map2[i]=1;
            }
        }
        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}

