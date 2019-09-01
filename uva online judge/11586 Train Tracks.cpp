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

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int t{};
    cin>> t;
    cin.ignore();
    while(t--)
    {
        vector <char> str;
        char ch{};
        int cnt{};
        int x{};
        while(1)
        {
            ch = getchar();
            if(ch=='\n')
                break;
            else if(isalpha(ch))
            {
                x++;
                if(ch=='M')
                    cnt++;
                else
                    cnt--;
            }
        }
        if(cnt || x<4)
            cout<< "NO ";
        cout<< "LOOP"<< endl;
    }


///   ///   ///   ///   ///   ///   ///
return 0;
}
