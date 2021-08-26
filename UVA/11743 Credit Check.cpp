#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, s2, s3, s4;
    int i, l, t, sum;
    while(cin>> t)
    {
        getchar();
        while(t--)
        {
            cin>> s>> s2>> s3>> s4;
            s += s2 += s3 += s4;
            l = s.size();
            sum = 0;
            for(i = l-1; i>=0; i-=2)
            {
                sum += static_cast<int>(s[i])-48;
            }
            for(i = l-2; i>=0; i-=2)
            {
                int x = static_cast<int>(s[i]) - 48;
                x *= 2;
                while(x!=0)
                {
                    sum += x%10;
                    x /= 10;
                }
            }
            if(sum % 10 ==0)
                cout<< "Valid"<< endl;
            else
                cout<< "Invalid"<< endl;
        }
    }
    return 0;
}
