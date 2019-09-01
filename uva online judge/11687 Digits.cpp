#include <bits/stdc++.h>
#define vi vector<int>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
//void scanf(li &n)
//{
//    bool negative = false;
//    char c;
//    n = 0;
//    c = getchar();
//    if (c=='-')
//    {
//        negative = true;
//        c = getchar();
//    }
//    for (; (c>47 && c<58); c=getchar())
//        n = n*10 + c - 48;
//    if (negative)
//        n *= -1;
//}
int digC(int n)
{
    int d{};
    while(n)
    {
        n/=10;
        d++;
    }
    return d;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    string s;
    while(cin>> s)
    {
        if(s=="END")
            break;
        else if(s=="1")
            cout<< "1"<< endl;
        else
        {
            int l{s.size()};
            if(l==1)
                cout<< "2"<< endl;
            else if(l<=9)
            {
                cout<< "3"<< endl;
            }
            else
                cout<< "4"<< endl;
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
