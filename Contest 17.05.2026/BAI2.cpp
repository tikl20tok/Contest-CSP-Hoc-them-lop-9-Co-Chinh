#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
    while (x!=0&&y!=0)
    {
        if (x>y)
        {
            x=x%y;
        }
        else
        {
            y=y%x;
        }
    }
    if (x!=0)
    {
        return x;
    }
    else
    {
        return y;
    }


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    /*
    công thức tính điểm nguyên: 
    ∆1=abs(x1-x2);
    ∆2=abs(y1-y2);

    số điểm nguyên nằm trên đường thẳng = gcd(∆1,∆2)

    với lại bài này đã cho điểm theo thứ tự là cạnh đa giác nối liền rồi nên không phải lo việc
    tìm lại (sắp xếp) sao cho các đỉnh khớp tạo thành đa giác nữa
    */


    long long n;
    cin>>n;
    long long i,j;
    vector<pair<long long,long long>> a(n+5);
    for (i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    long long tong=0;
    for (i=2;i<=n;i++)
    {
        tong+=gcd(abs(a[i].first-a[i-1].first),abs(a[i].second-a[i-1].second));
    }
    tong+=gcd(abs(a[1].first-a[n].first),abs(a[1].second-a[n].second));

    cout<<tong;

    //full AC 100%




    return 0;
}
