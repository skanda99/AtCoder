
// problem: "https://atcoder.jp/contests/abc123/tasks/abc123_a"

#include<iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,k;
    cin>>a>>b>>c>>d>>e>>k;

    if(e-a<=k)
        cout<<"Yay!";
    else
        cout<<":(";

    return 0;
}
