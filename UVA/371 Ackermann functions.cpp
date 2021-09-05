#include<bits/stdc++.h>
using namespace std;
int main()
{
    typedef long long ul;
    ul l, h;
    while(cin>>l>>h)
    {
        if(l==0 && h==0)
            break;
        if(l>h)
            swap(l, h);
        ul num = l;
        int max_cnt{0};
        for(ul i=l; i<=h; i++)
        {
            ul x = i;
            if(x%2==0)
                x /= 2;
            else
                x = 3*x + 1;
            int cnt{1};
            while(x!=1)
            {
                if(x%2==0)
                {
                    x /= 2;
                    cnt++;
                }
                else
                {
                    x = 3*x +1;
                    cnt++;
                }
            }
            if(cnt > max_cnt)
            {
                max_cnt = cnt;
                num = i;
            }
        }
        cout<< "Between "<< l<< " and "<< h<< ", "<< num<< " generates the longest sequence of "<< max_cnt << " values."<< endl;
    }
    return 0;
}