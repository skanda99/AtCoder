
// problem: "https://atcoder.jp/contests/abc147/tasks/abc147_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int i,j,c;
    c = 0;
    i = 0;
    j = s.size()-1;

    while(i < j)
    {
        if(s[i] != s[j])
            c++;

        i++;
        j--;
    }

    cout<<c;

    return 0;
}
