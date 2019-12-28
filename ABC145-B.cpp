
// problem: "https://atcoder.jp/contests/abc145/tasks/abc145_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin>>n>>s;

    if(n%2)
    {
        cout<<"No";
        exit(0);
    }
    else
    {
        int i;
        for(i=n/2;i!=s.size();i++)
        {
            if(s[i-n/2] != s[i])
            {
                cout<<"No";
                exit(0);
            }
        }

        cout<<"Yes";
    }

    return 0;
}
