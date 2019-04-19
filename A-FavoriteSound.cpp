#include<iostream>

using namespace std;

int main()
{
  int a,b,c;
  cin>>a>>b>>c;

  int ans=min(b/a,c);

  cout<<ans;

  return 0;
}
