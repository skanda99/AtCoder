
// problem: "https://atcoder.jp/contests/abc121/tasks/abc121_b"

#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int n,m,c;

  cin>>n>>m>>c;
  vector<int>B(m);
  int i;
  for(i=0;i!=m;i++)
    cin>>B[i];
  int C = 0;
  for(i=0;i!=n;i++)
  {
    int j;
    int s = 0;
    for(j=0;j!=m;j++)
    {
      int x;
      cin>>x;
      s += x*B[j];
    }

    if(s+c>0)
      C++;
  }

  cout<<C;
  return 0;
}
