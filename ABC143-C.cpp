
// problem: "https://atcoder.jp/contests/abc143/tasks/abc143_c"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    stack<char>Q;
    int i;
    char c;

    for(i=0;i!=n;i++)
    {
        cin>>c;

        if(Q.empty())
            Q.push(c);

        else if(Q.top() != c)
            Q.push(c);
    }

    cout<<Q.size();

    return 0;
}
