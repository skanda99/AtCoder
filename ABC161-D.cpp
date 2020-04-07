
// problem: "https://atcoder.jp/contests/abc161/tasks/abc161_d"

#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool reqNum(ll n)
{
    if(n < 10)
        return true;

    ll p = n%10;
    while(n)
    {
        if(abs(p-(n%10)) > 1)
            return false;

        p = n%10;
        n /= 10;
    }

    return true;
}

ll genNext(ll n)
{
    string s = to_string(n);

    ll i;
    for(i=1;i!=s.size();i++)
    {
        if(abs(s[i]-s[i-1]) > 1)
        {
            if(s[i-1] == '9')
            {
                while(i < s.size())
                {
                    s[i] = max(s[i-1]-1,(int)'0');
                    i++;
                }
            }
            else
            {
                s[i-1] = s[i-1]+1;
                while(i < s.size())
                {
                    s[i] = max(s[i-1]-1,(int)'0');
                    i++;
                }
            }

            break;
        }
    }

    return stol(s);
}

ll genNum(ll k)
{
    ll i = 0;
    ll n = 1;

    while(i != k)
    {
        if(reqNum(n))       // define
        {
            n++;
            i++;
        }
        else
            n = genNext(n);
    }

    return n-1;
}

int main()
{
    ll k;
    cin>>k;

    cout<<genNum(k);        // define

    return 0;
}
