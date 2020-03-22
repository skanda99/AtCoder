
// problem: "https://atcoder.jp/contests/abc156/tasks/abc156_b"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int c=0;

    while(n)
    {
        c++;
        n /= k;
    }

    cout<<c;

    return 0;
}
