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
//double const pi = acos(-1.0);
//void scanf(int &n)
//{
//     bool negative = false;
//     char c;
//     n = 0;
//     c = getchar();
//     if (c=='-')
//     {
//         negative = true;
//         c = getchar();
//     }
//     for (; (c>47 && c<58); c=getchar())
//         n = n*10 + c - 48;
//     if (negative)
//         n *= -1;
//}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    string s, s2;
    char ch;
    int hh{}, mm{}, ss{}, kmh{}, hh2{}, mm2{}, ss2{}, td{};
    double dis{0.0};
    cout<< fixed<< showpoint<<setprecision(2);
    while(getline(cin, s))
    {
        stringstream strs;
        strs << s;
        strs>> hh>>ch>> mm>>ch>> ss;

        hh2 = hh-hh2;
        mm2 = mm-mm2;
        ss2 = ss-ss2;
        if(mm2<0)
        {
            hh2--;
            mm2+=60;
        }
        if(ss2<0)
        {
            mm2--;
            ss2+=60;
        }

        td = ss2 + mm2*60 + hh2*3600;
        dis += td/3600.0*kmh;

        if(s.find(' ')!=string::npos)
        {
            strs>> kmh;
        }
        else
        {
            cout<<s<< " "<< dis<< " km\n";
        }
        hh2 = hh;
        mm2 = mm;
        ss2 = ss;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}