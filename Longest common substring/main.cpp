#include <iostream>
#include<cstring>
using namespace std;
int LongestcommonSubstring(string s) {
        int res=0;
        int r=s.length();
        int c=r;
        int dp[100][100];
        for(int i=0;i<=r+1;i++){
            for(int j=0;j<=c+1;j++){
                dp[i][j]=0;
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"****"<<endl;
        for(int i=0;i<=r+1;i++){
            for(int j=0;j<=c+1;j++){
                if(s[i]==s[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
            }
        }
        for(int i=0;i<=r+1;i++){
            for(int j=0;j<=c+1;j++){
                cout<<dp[i][j]<<" ";
                res=max(res,dp[i][j]);
            }
            cout<<endl;
        }
        return res;
    }
int main() {
    string s="pwwkew";
    cout<<LongestcommonSubstring(s);
}
