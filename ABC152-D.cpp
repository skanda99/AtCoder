
// problem: "https://atcoder.jp/contests/abc152/tasks/abc152_d"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll getNewNum(ll f,ll l,ll i)
{
    ll j;
    for(j=0;j!=i;j++)
        f = 10*f+9;

    f = 10*f + l;

    return f;
}

ll findP(ll p,ll n)
{
    ll d = 0,a,b;

    b = p%10;
    while(p)
    {
        d++;
        a = p%10;
        p /= 10;
    }

    //  a -> first, b -> last, d -> # digits

    ll d_ = 0,f,l,m;
    ll ncopy = n;
    l = n%10;
    while(ncopy)
    {
        d_++;
        f = ncopy%10;
        ncopy /= 10;
    }

    // f -> first, l -> last, d_ -> # digits

    string s = to_string(n);
    s.erase(0,1);

    if(s.empty())
        m = 0;
    else
        s.erase(s.size()-1,1);

    if(s.empty())
        m = 0;
    else
        m = stoi(s);

    ll count = 0;

    if(a == b)
        count++;

    ll i,j,New;
    for(i=0;i+2<=d_;i++)
    {
        New = getNewNum(b,a,i);     // define

        if(New <= n)
            count += pow(10,i);

        else
        {
            if(b == f)
            {
                if(a <= l)
                    count += m+1;
                else
                    count += m;
            }
        }
    }

    return count;
}

ll countP(ll n)
{
    ll count = 0;

    int i;
    for(i=1;i!=n+1;i++)
    {
        //cout<<i<<'\n';
        if(i%10)
        {
            count += findP(i,n);        // define
            //cout<<i<<' '<<findP(i,n)<<'\n';       // remove
        }
    }

    return count;
}

int main()
{
    int n;
    cin>>n;

    cout<<countP(n);        // define
    return 0;
}
