
// problem: "https://atcoder.jp/contests/abc121/tasks/abc121_c"

#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#define ll long long int

using namespace std;

int main()
{
  ll n,m;
  cin>>n>>m;

  vector<pair<ll,ll>>V;
  ll i;

  for(i=0;i!=n;i++)
  {
    ll a,b;
    cin>>a>>b;

    pair<ll,ll>p(a,b);
    V.push_back(p);
  }

  sort(V.begin(),V.end());
  ll c = 0,cn = 0;
  for(i=0;i!=n;i++)
  {
    if(cn+V[i].second<=m)
    {
      cn += V[i].second;
      c += (V[i].first) * (V[i].second);
    }
    else
      break;
  }

  if(cn!=m)
    c += (m-cn)*V[i].first;

  cout<<c;
  return 0;
}
