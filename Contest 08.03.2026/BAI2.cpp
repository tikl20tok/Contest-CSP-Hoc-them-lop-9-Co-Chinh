#include <bits/stdc++.h>
using namespace std;
/*
phân tích giải thuật:
trâu là mxn, với mỗi k, tính abs từng giá trị

giải thuật tối ưu:
biến thành m*log2(n)

sort mảng a
lấy prefixsum
với mỗi k
chặt nhị phân
phần tử <k, thì số lượng thêm vào là k*sl-prefixsum[vt]

phần tử >=k thì số lượng thêm vào là prefixsum[n]-prefixsum[vt] - k*sl

***sl là số lượng

*/
vector<long long> a,prefixsum;
long long m,n;

//nếu là >=x thì sẽ rất khó để quản lí vị trí -> nên chia hẳn ra 2 phe: <x hoặc >x, trường hợp bằng là biên, ko lo
long long Binary(long long x)//tìm giá trị gần nhất thỏa mãn > x
//cái này trả luôn kết quả là khoảng cách nhỏ nhất, không còn là vị trí nữa
{
    long long start=1,en=n,mid;
    long long vt=0;
    while (start<=en)
    {
        mid=start+(en-start)/2;
        if (a[mid]>x)
        {
            vt=mid;
            en=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return vt;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING,INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    cin>>n>>m;
    a.resize(n+5);
    prefixsum.resize(n+5);
    prefixsum[0]=0;
    a[0]=0;
    long long i,j;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin()+1,a.begin()+1+n);
    for (i=1;i<=n;i++)
    {
        prefixsum[i]=prefixsum[i-1]+a[i];
    }
    long long k;
    long long vitri;
    long long t1,t2,tong;
    for (i=1;i<=m;i++)
    {
        cin>>k;
        vitri=Binary(k);
        //tượng trưng cho tổng t1+t2, tổng bù <=k, tổng bù >k
        tong=0;t1=0;t2=0;
        if (vitri==0)
        {
            //tức là ko có số nào >k
            t1=k*n-prefixsum[n];
        }
        else
        {
            t1=k*(vitri-1)-prefixsum[vitri-1];
            t2=prefixsum[n]-prefixsum[vitri-1]-k*(n-(vitri-1));
        }
        tong=t1+t2;
        cout<<tong<<"\n";
    }

    //FULL ac







    return 0;
}
