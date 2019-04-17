
// problem: "https://atcoder.jp/contests/abc123/tasks/abc123_b"

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>V(5);
    int i;

    for(i=0;i!=5;i++)
        cin>>V[i];

    int m = 10,s = 0;

    for(i=0;i!=5;i++)
    {
        if(V[i]%10==0)
        {
            s += V[i];
        }
        else
        {
            s += (V[i]+10-V[i]%10);
            m = min(m,V[i]%10);
        }
    }


    cout<<s-(-m+10);

    return 0;
}
