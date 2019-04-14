
// problem: "https://atcoder.jp/contests/abc124/tasks/abc124_a"

#include<iostream>

using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;

    int ans = max(2*A-1,2*B-1);
    ans = max(ans,A+B);

    cout<<ans;

    return 0;
}
