// Find the next lexicographically
// greater permutation of a word

#include <algorithm>
#include <iostream>
#include<set>
#include<vector>
using namespace std;
void showpermu(string s,string b,set<string>&v){
    if(s==b){
        v.insert(s);
        return ;
    }
    v.insert(b);
    next_permutation(b.begin(),b.end());
    showpermu(s,b,v);
}
void findxor(string a,string b,set<string> &v,int i,string c,int n){
    if(i==n){
        string d;
        for(int k=0;k<=i;k++){
            d[k]=c[k];
        }
        v.insert(d);
        cout<<"Inserting "<<d<<endl;
        return ;
    }
    int x=a[i]-'0';
    int y=b[i]-'0';
    int z=x^y;
    c[i]=z+'0';
    cout<<c[i]<<endl;
    findxor(a,b,v,i+1,c,n);
}
int main()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    string a2(a);
    string b2(b);
	next_permutation(a2.begin(),a2.end());
	next_permutation(b2.begin(),b2.end());
	set<string>va;
    set <string>vb;
    showpermu(a,a2,va);
    showpermu(b,b2,vb);
    string c;
    set<string>final;
    for(string i :va){
        for(string j:vb){
            findxor(i,j,final,0,c,n);
            cout<<"Sending "<<i<<" and "<<j<<endl;
        }
    }
    cout<<"Final string has :"<<endl;
    for(string i : final){
        cout<<i<<" ";
    }
	return 0;
}
