#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    long long n;
    cin>>n;
    vector<pair<long long, long long>> a(n+5);
    long long i,j;
    long long tong=0;
    long long ht=0;
    long long best=0;
    for (i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        tong+=a[i].second;

        ht=max((long long)0,ht-a[i].first);
        ht+=a[i].second;
        best=max(best,ht);
    }
    cout<<tong<<"\n"<<best;

    //full AC 100%



    return 0;
}
