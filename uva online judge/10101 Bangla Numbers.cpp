#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;

// void scanf(int &n)
//  {
//      bool negative = false;
//      char c;
//      n = 0;
//      c = getchar();
//      if (c=='-')
//      {
//          negative = true;
//          c = getchar();
//      }
//      for (; (c>47 && c<58); c=getchar())
//          n = n*10 + c - 48;
//      if (negative)
//          n *= -1;
//  }

int main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int t{};
    llu n;
    while(cin>> n)
    {
        printf("%4d.", ++t);
        if(n==0)
            cout<< " 0";
        else
        {
            if(n>=10000000)
            {
                llu n2 = n/10000000;
                if(n2>=10000000)
                {
                    cout<< " " <<n2/10000000<< " kuti";
                    n2%=10000000;
                }
                if(n2>=100000)
                {
                    cout<< " " <<n2/100000<< " lakh";
                    n2%=100000;
                }
                if(n2>=1000)
                {
                    cout<< " " <<n2/1000<< " hajar";
                    n2%=1000;
                }
                if(n2>=100)
                {
                    cout<< " " <<n2/100<< " shata";
                    n2%=100;
                }
                if(n2)
                {
                    cout<< " "<< n2;
                }
                cout<< " kuti";
                n %= 10000000;
            }
            if(n>=100000)
            {
                cout<< " "<< n/100000<< " lakh";
                n %= 100000;
            }
            if(n>=1000)
            {
                cout<< " "<<n/1000<< " hajar";
                n %= 1000;
            }
            if(n>=100)
            {
                cout<< " "<<n/100<< " shata";
                n %= 100;
            }
            if(n)
            {
                cout<< " "<< n;
            }
        }
        cout<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
