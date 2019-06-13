
// problem: "https://atcoder.jp/contests/abc128/tasks/abc128_d"

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;

    vector<int>V(N);
    int i;
    for(i=0;i!=N;i++)
        cin>>V[i];

    int R,P,M;
    M = 0;
    for(R=0;R<=min(N,K);R++)
    {
        P = min(K-R,R);
        int l,r;
        for(l=0;l<=R;l++)
        {
            r = R-l;

            int m = 0;
            vector<int>Q;
            for(i=0;i<l;i++)
            {
                 Q.push_back(V[i]);
                 m += V[i];
            }
            for(i=N-1;i>=N-r;i--)
            {
                Q.push_back(V[i]);
                m += V[i];
            }

            sort(Q.begin(),Q.end());
            for(i=0;i<P && Q[i]<0;i++)
                m -= Q[i];

            M = max(m,M);
        }
    }

    cout<<M;

    return 0;
}
