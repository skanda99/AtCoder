
// problem: "https://atcoder.jp/contests/abc154/tasks/abc154_e"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll nCr(ll n,ll r)
{
    if(r == 0)
        return 1;
    else if(r == 1)
        return n;

    return n*(n-1)/2;
}

ll numPossib(ll n,ll k)
{
    ll ans = 0,i;
    for(i=k;i!=n+1;i++)
        ans += nCr(i-1,k-1);        // define

    if(k == 3)
        return ans*9*9*9;
    else if(k == 2)
        return ans*9*9;

    return ans*9;
}

ll lastPossib(ll n,ll k,string &num)
{
    ll p1 = stoi(num.substr(0,1));

    if(k == 1)
        return p1;

    else if(k == 2)
    {
        ll i,ans;
        ans = 0;
        for(i=1;i!=n;i++)
            if(num[i] != '0')
                break;

        if(i < n)
            ans = stoi(num.substr(i,1)) + nCr(n-i-1,1) * 9;

        return ans + (p1-1)*9*nCr(n-1,1);
    }

    else
    {
        ll i,j,ans;
        ans = 0;
        for(i=1;i!=n-1;i++)
        {
            if(num[i] == '0')
                continue;

            ans += (stoi(num.substr(i,1))-1) * nCr(n-1-i,1) * 9;

            for(j=i+1;j!=n;j++)
                if(num[j] != '0')
                    break;

            if(j < n)
                ans += stoi(num.substr(j,1)) + nCr(n-j-1,1) * 9;

            break;
        }

        if(i < n-2)
            ans += nCr(n-i-1,2)*9*9;

        return (p1-1)*9*9*nCr(n-1,2) + ans;
    }

    return 0;
}

int main()
{
    string num;
    cin>>num;

    ll n = num.size();

    ll k;
    cin>>k;

    if(n < k)
    {
        cout<<0;
        exit(0);
    }

    ll ans = numPossib(n-1,k);      // define

    ans += lastPossib(n,k,num);     // define

    cout<<ans;

    return 0;
}
