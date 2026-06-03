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
/*
với những dự án lỗ thì cái tư duy nó ảo cực
trên thực tế trong các nhà tài chính,
-> dự án lỗ tiềm năng nhất ko phải là lỗ ít nhất mà là thu về nhiều nhất
-> priority:
1: thu nhiều nhất
2: chi ít nhất



*/
bool cmp2(thongtin a, thongtin b)
{
    if (a.loi!=b.loi)
        return a.thu > b.thu;//nếu a lỗ ít hơn thì đặt nó phía trước, cụ thể là số âm lớn hơn ấy
    //nếu như mà cùng lỗ thì đương nhiên chọn cái chi ít hơn rồi
    return a.chi < b.chi;//cho thằng a lên trước
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
    sort(lo.begin()+1,lo.end(),cmp2);
    //bắt đầu với thằng lời trước
    long long dem=0;
    for (i=1;i<loc.size();i++)
    {
        if (s>=loc[i].chi)
        {
            s+=loc[i].loi;//bản chất đây là s-chi rồi s+=thu
            dem++;
        }
    }
    //đến thằng lỗ
    priority_queue<long long,vector<long long>,greater<long long>> pq;//pq để lưu lại những dự án lỗ mà ta đã làm, ưu tiên là những dự án lỗ lớn nhất (tức là số âm nhỏ nhất)
    /*
    priority queue có cơ chế max heap, giờ để phù hợp thì ta sẽ chọn min heap cho vừa với lỗ lớn nhất
    
    ta đã sắp xếp theo thứ tự tiềm năng nhất rồi, phù hợp với bản chất của regret greedy
    -> duyệt xuôi
    */
    for (i=1;i<lo.size();i++)
    {
        if (s>=lo[i].chi)
        {
            s+=lo[i].loi;//lỗ nên là s-chi rồi s+=thu
            pq.push(lo[i].loi);//đẩy cái lỗ vào priority queue
        }
        else
        {
            if (!pq.empty()&&pq.top()<lo[i].loi)//nếu mà cái lỗ lớn nhất trong priority queue nhỏ hơn cái lỗ hiện tại (tức là lỗ nhiều hơn) thì ta thay thế nó đi
            {
                if (s-pq.top()>=lo[i].chi)//điều kiện để thay thế là sau khi bỏ cái lỗ lớn nhất đi thì vẫn đủ tiền để làm cái lỗ hiện tại
                {//điều kiện này kiên quyết đấy
                    s-=pq.top();//bỏ cái lỗ lớn nhất đi
                    pq.pop();
                    s+=lo[i].loi;//thêm cái lỗ hiện tại vào
                    pq.push(lo[i].loi);
                }
            }
        }
    }
    cout<<dem+pq.size();

    //xong bài
    //full ac







    return 0;
}
