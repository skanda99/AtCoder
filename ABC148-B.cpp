
// problem: "https://atcoder.jp/contests/abc148/tasks/abc148_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    int N;
    cin>>N;
    cin>>s>>t;

    int i,k;
    i = k = 0;
    string n;
    while(i < N)
    {
        n.append(s.substr(i,1));
        k++;

        n.append(t.substr(i,1));
        k++;

        i++;
    }

    cout<<n;

    return 0;
}
