//top-down approach
#include <iostream>
using namespace std;
int memopad[1000];
int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    if(memopad[n]!=-1){
        return memopad[n];
    }
    int ans=fib(n-1)+fib(n-2);
    memopad[n]=ans;
    return ans;
}
int main()
{
    int n=10;
    for(int i=0;i<=n;i++){
        memopad[i]=-1;
    }
    cout<<fib(n)<<endl;
    return 0;
}
