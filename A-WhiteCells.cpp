
// problem: "https://atcoder.jp/contests/abc121/tasks/abc121_a"

#include<iostream>

using namespace std;

int main()
{
  int H,W,h,w;

  cin>>H>>W>>h>>w;

  cout<<H*W + h*w - h*W - H*w;

  return 0;
}
