#include<bits/stdc++.h>
using namespace std;
struct thongtin
{
    long long chi;
    long long thu;
    long long loi;
};
bool cmp1(thongtin a, thongtin b)
{
    if (a.chi!=b.chi)
        return a.chi < b.chi;//nếu a chi ít hơn thì đặt nó phía trước, vì ta ưu tiên làm những dự án có chi phí nhỏ hơn trước
    //nếu như mà cùng chi thì đương nhiên chọn cái lãi nhiều hơn rồi
    return a.loi > b.loi;//cho thằng a lên trước
    /*
    ta không quan trọng dự án lời bao nhiêu, quan trọng là cái chi của nó càng ít càng tốt
    */
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    long long n,s;
    cin>>n>>s;
    long long i,j,k;
    vector<thongtin> loc,lo;//loc là lộc(ko vt lợi đc vì trên có rồi damn), lo là lỗ
    loc.reserve(n+5);
    lo.reserve(n+5);
    loc.push_back({0,0,0});
    lo.push_back({0,0,0});
    
    for (i=1;i<=n;i++)
    {
        cin>>j>>k;
        if (k-j>=0)
        {
            loc.push_back({j,k,k-j});
        }
        else
        {
            lo.push_back({j,k,k-j});
        }
    }
    /*
    với những dự án sinh lời, ta chắc chắn là có lời rồi
    -> ưu tiên lấy dự án làm giá nhỏ nhất, giải thích:
    Với các dự án lại ta ưu tiên làm các dự án có ai nhỏ hơn trước, điều này vẫn đảm bảo số lượng dự án tối đa của chúng ta do: 
    Giả sử có 2 dự án lãi i và j có ai < aj:
    Nếu Scũ > aj (> ai) thì ta làm ai trước thì Smới = Scũ - ai + bi > Scũ > aj nên hoàn toàn có thể làm được aj
    Nếu Scũ < aj thì rõ ràng ta phải đi làm i trước và mong đợi rằng Smới có thể lớn hơn aj

    => Ở bước này, ta duyệt qua từng dự án có lãi (tăng dần theo ai) và đếm số lượng dự án làm được

    */
    sort(loc.begin()+1,loc.end(),cmp1);










    return 0;
}
