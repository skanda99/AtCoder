
// problem: "https://atcoder.jp/contests/abc141/tasks/abc141_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int i;
    for(i=0;i!=s.size();i++)
    {
        if(i%2)
        {
            if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D')
            {
                cout<<"No";
                exit(0);
            }
        }

        else
        {
            if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D')
            {
                cout<<"No";
                exit(0);
            }
        }
    }

    cout<<"Yes";

    return 0;
}
