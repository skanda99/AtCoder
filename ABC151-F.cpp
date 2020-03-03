
// problem: "https://atcoder.jp/contests/abc151/tasks/abc151_f"

#include<bits/stdc++.h>
#define Pair pair<double,double>

using namespace std;

Pair centerOf(vector<int>&X,vector<int>&Y,int i,int j,int k)
{
    int a1,b1,c1,a2,b2,c2;
    a1 = 2*(X[j]-X[i]);
    b1 = 2*(Y[j]-Y[i]);
    c1 = X[j]*X[j] + Y[j]*Y[j] - X[i]*X[i] - Y[i]*Y[i];
    a2 = 2*(X[j]-X[k]);
    b2 = 2*(Y[j]-Y[k]);
    c2 = X[j]*X[j] + Y[j]*Y[j] - X[k]*X[k] - Y[k]*Y[k];


    if(a1*b2 - a2*b1 == 0)
        return Pair(-10000.0,-10000.0);

    double x,y;
    x = (double)(c1*b2 - c2*b1)/(a1*b2 - a2*b1);
    y = (double)(a1*c2 - a2*c1)/(a1*b2 - a2*b1);

    return Pair(x,y);
}

bool validCand(Pair cand,double rad,vector<int>&X,vector<int>&Y,int n)
{
    int i;
    for(i=0;i!=n;i++)
    {
        double dist = sqrt((cand.first-X[i])*(cand.first-X[i]) + (cand.second-Y[i])*(cand.second-Y[i]));
        if(dist > rad)
            return false;

    }

    return true;
}

double minRadius(vector<int>&X,vector<int>&Y,int n)
{
    if(n == 2)
        return sqrt((X[0]-X[1])*(X[0]-X[1]) + (Y[0]-Y[1])*(Y[0]-Y[1]))/2.0;

    int i,j,k;

    double Min = 100000.0;
    for(i=0;i!=n-1;i++)
        for(j=i+1;j!=n;j++)
        {
            double rad = sqrt((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]))/2.0;
            Pair cand((X[i]+X[j])/2.0,(Y[i]+Y[j])/2.0);

            if(validCand(cand,rad,X,Y,n))
                Min = min(Min,rad);
        }



    for(i=0;i!=n-2;i++)
        for(j=i+1;j!=n-1;j++)
            for(k=j+1;k!=n;k++)
            {
                Pair cand = centerOf(X,Y,i,j,k);      // define

                if(cand.first == -10000.0 && cand.second == -10000.0)
                    continue;

                double rad = sqrt((cand.first-X[i])*(cand.first-X[i]) + (cand.second-Y[i])*(cand.second-Y[i]));

                if(validCand(cand,rad,X,Y,n))       // define
                    Min = min(Min,rad);
            }


    return Min;
}

int main()
{
    int n;
    cin>>n;

    int t1,t2;
    vector<int>X,Y;

    int i;
    for(i=0;i!=n;i++)
    {
        cin>>t1>>t2;

        X.push_back(t1);
        Y.push_back(t2);
    }

    cout<<setprecision(18)<<fixed<<minRadius(X,Y,n);     // define

    return 0;
}
