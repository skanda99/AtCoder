
// problem: "https://atcoder.jp/contests/abc147/tasks/abc147_a"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    if(a+b+c < 22)
        cout<<"win";

    else
        cout<<"bust";

    return 0;
}
