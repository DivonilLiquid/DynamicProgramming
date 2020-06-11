//bottom up approach
#include <iostream>
using namespace std;
int fib(int n){
    int memopad[1000]={};
    memopad[0]=0;
    memopad[1]=1;
    for(int i=2;i<=n;i++){
        memopad[i]=memopad[i-1]+memopad[i-2];
    }
    return memopad[n];
}
int main()
{
    int n=44;
    cout<<fib(n)<<endl;
    return 0;
}
