#include<bits/stdc++.h>
using namespace std;
/*
bài này là 1 bài greedy thuần tí kết hợp định lí toán học dirichlet
ta vẫn đi theo thứ tự từ điển thông thường
-> tuy nhiên luôn phải check ISVALID:
mỗi kí tự còn lại khi chọn kí tự nào đó chả hạn
luôn phải thỏa mãn ít hơn số lượng kí tự còn lại cho phép
số lượng kí tự hiện tại <= (số lượng kí tự còn lại + 1)(cả index 1 và 0 vì đây là lượng kí tự còn lại) / 2

với lại duyệt theo thứ tự từ điển thì toán học đã chứng minh:
giả sử có a và b đều thỏa mãn
nhiều người sẽ lo sợ rằng là cái a tuy ít hơn nhưng lỡ làm kết quả sau cùng bị no valid thì sao
điều này ko thể xảy ra, cơ bản là do nếu a và b thỏa mãn thì chắc chắn nếu chọn b thì sau cũng ko thỏa mãn nếu thử a ko thỏa mãn
(xem kĩ hơn trên mạng hoặc trong solution)
*/


string s;
vector<long long> kitu(30,0);

bool isValid (long long vitri, long long cuoicung)
{
    long long i;
    long long remain=cuoicung-vitri+1;//lượng phần tử còn lại (ko bao gồm chính nó) +1
    long long toida=0;
    for (i=1;i<=26;i++)
    {
        toida=max(toida,kitu[i]);
    }
    return toida<=remain/2;//trả lại true nếu thỏa mãn điều kiện này và ngược lại
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>s;
    long long i,j;
    long long n=s.size()-1;
    for (i=0;i<=n;i++)
    {
        kitu[s[i]-96]+=1;//đếm lượng kí tự
    }

    if (isValid(0,n+1)==false)
    {
        cout<<-1;
        return 0;
    }

    string t;
    bool found;
    t.reserve(n+5);
    for (i=0;i<=n;i++)
    {
        found=false;
        for (j=1;j<=26;j++)
        {
            if (kitu[j]>=1)//kiểm tra còn số lượng không và có giống kí tự trước đó không
            {
                kitu[j]-=1;
                if (isValid(i,n))
                {
                    if (t.size()==0)
                    {
                        found=true;
                        t+=char(j+96);
                    }
                    else
                    {
                        if (char(j+96)!=t[i-1])
                        {
                            found=true;
                            t+=char(j+96);
                        }
                        else
                        {
                            kitu[j]+=1;
                        }
                    }
                }
                else
                {
                    kitu[j]+=1;
                    continue;
                }
            }
            if (found==true)
            {
                break;
            }
        }
        if (found==false)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<t;


    //full AC 100%







    return 0;
}
