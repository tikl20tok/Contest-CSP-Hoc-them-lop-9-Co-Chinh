#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a,b;
long long Binary(long long x)//tìm giá trị gần nhất thỏa mãn >= x
//cái này trả luôn kết quả là khoảng cách nhỏ nhất, không còn là vị trí nữa
{
    long long start=1,en=n,mid;
    long long vt=0;
    while (start<=en)//vd có 4 4 4, luôn chọn cái phần tử số 1, tức là phù hợp để -1 index ở dưới
    {
        mid=start+(en-start)/2;
        if (a[mid]>=x)
        {
            if (a[mid]==x)//đây là phương án tối ưu rồi
                return 0;
            vt=mid;
            en=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    
    if (vt==0)//nếu không có giá trị nào >=x thì cái tốt nhất là a[1]
    {
        return abs(a[1]-x);
    }
    long long best=2e18;
    best=min(best,abs(a[vt]-x));
    if (vt>1)//xét trường hợp 2
    {
        best=min(best,abs(a[vt-1]-x));
    }
    return best;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    /*
    bản chất abs(abs(ai+bj) = abs(ai - (-bi) )
    -> ta thấy bài toán khoảng cách quen thuộc rồi
    -> mỗi lần nhập bi, đảo dấu là được

    giá trị nhỏ nhất của biểu thức theo đề bài yêu cầu abs(ai - (-bi) ) nhỏ nhất
    -> để ý chỉ cần chặt nhị phân lấy giá trị là được
    tức là chặt nhị phân lấy giá trị >= cái hiện tại, nếu có bằng thì 0 luôn
    còn nếu > thì lấy abs thử, rồi index -=1 (index>1) để thử tiếp 
    (tóm gọn là thử 2 giá trị có khoảng cách gần nhất trên trục số)
    */


    cin>>n;
    //cái bước resize này cần hay không cần cũng chẳng ảnh hưởng đến thuật toán
    a.resize(n+5);
    b.resize(n+5);

    long long i,j;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=n;i++)
    {
        cin>>b[i];
        b[i]=-b[i];//đổi dấu
    }
    sort(a.begin()+1,a.begin()+n+1);

    long long gt;
    long long totnhat=2e18;
    for (i=1;i<=n;i++)//chạy theo b, chặt nhị phân trên a
    {
        gt=Binary(b[i]);
        totnhat=min(totnhat,gt);
    }
    cout<<totnhat;


    //FULL AC




    return 0;
}