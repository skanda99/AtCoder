
// problem: "https://atcoder.jp/contests/abc150/tasks/abc150_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin>>n>>s;

    int i,c;
    c = 0;
    for(i=0;i!=n;i++)
    {
        if(s.substr(i,3) == "ABC")
            c++;
    }

    cout<<c;

    return 0;
}
