
// problem: "https://atcoder.jp/contests/abc121/tasks/abc121_d"

#include<iostream>
#define ll long long int

using namespace std;

ll oddcnt(ll A,ll B)
{
    ll n = B-A+1;
    ll ans;

    if(n%4 == 0)
    {
        ans = A^(B-2);
        ans = ans^(B-1);
        ans = ans^B;
    }
    else if(n%4 == 1)
    {
        ans = A;
    }
    else if(n%4 == 2)
    {
        ans = A^B;
    }
    else
    {
        ans = A^(B-1);
        ans = ans^B;
    }

    return ans;
}

ll evencnt(ll A,ll B)
{
    ll n = B-A+1;
    ll ans;

    if(n%4 == 0)
    {
        ans = 0;
    }
    else if(n%4 == 1)
    {
        ans  = B;
    }
    else if(n%4 == 2)
    {
        ans = 1;
    }
    else
    {
        ans = 1^B;
    }

    return ans;
}


int main()
{
    ll A,B;

    cin>>A>>B;

    if(A%2)
        cout<<oddcnt(A,B);
    else
        cout<<evencnt(A,B);

    return 0;
}
