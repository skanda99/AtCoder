
// problem: "https://atcoder.jp/contests/abc152/tasks/abc152_e"

#include<bits/stdc++.h>
#define ll long long
#define p (ll)(1e9+7)

using namespace std;

ll power(ll a,ll n)
{
    if(!n)
        return 1;

    ll b = 1;
    if(n%2)
        b = a;

    ll ans = power(a,n/2);
    ans = ((ans*ans)%p * b)%p;

    return ans;
}

void findPrimes(vector<ll>&P,ll n)
{
    vector<bool>Prime(n+1,1);
    Prime[0] = Prime[1] = 0;

    ll i,j;
    i = 2;
    while(i <= n)
    {
        P.push_back(i);

        j = 2*i;

        while(j <= n)
        {
            Prime[j] = 0;
            j += i;
        }

        i++;
        while(!Prime[i])
            i++;
    }
}

void findFactors(vector<ll>&V,vector<ll>&factors,vector<ll>&P)
{
    unordered_map<ll,ll>M;
    ll i;
    for(i=0;i!=V.size();i++)
    {
        ll n = V[i],j;
        for(j=0;j!=P.size();j++)
        {
            ll c = 0;
            while(n%P[j] == 0)
            {
                n /= P[j];
                c++;
            }

            if(M.count(P[j]))
                M[P[j]] = max(M[P[j]],c);

            else
                M[P[j]] = c;
        }

        if(n != 1)
            M[n] = 1;
    }

    for(auto it=M.begin();it!=M.end();it++)
    {
        ll a,b;
        a = it->first;
        b = it->second;

        factors.push_back(power(a,b));
    }
}

int main()
{
    ll n;
    cin>>n;

    vector<ll>V(n);
    ll i;
    for(i=0;i!=n;i++)
        cin>>V[i];

    vector<ll>P;
    findPrimes(P,1000);     // define

    vector<ll>factors;
    findFactors(V,factors,P);       // define

    ll lcm = 1;
    for(i=0;i!=factors.size();i++)
        lcm = (lcm*factors[i])%p;

    ll sum = 0;
    for(i=0;i!=n;i++)
        sum = (sum + (lcm*power(V[i],p-2))%p)%p;        // define

    cout<<sum;

    return 0;
}
