
// problem: "https://atcoder.jp/contests/abc125/tasks/abc125_b"

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int x,y;
    vector<int>V,C;

    int i;
    for(i=0;i!=n;i++)
    {
        cin>>x;
        V.push_back(x);
    }

    for(i=0;i!=n;i++)
    {
        cin>>x;
        C.push_back(x);
    }

    int ans=0;
    for(i=0;i!=n;i++)
    {
        if(V[i] > C[i])
            ans += V[i]-C[i];
    }

    cout<<ans;
    
    return 0;
}
