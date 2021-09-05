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
// {
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
// }

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    string s;
    int from, to;
    int n, x, p;
    while(cin>> s>> from >> to)
    {
        cout<< setw(7);
        n = 0;  p = 0;
        auto i = s.rbegin();
        while(i!=s.rend())
        {
            if(!isalnum(*i))    break;
            if(isalpha(*i))     x = *i - 'A' + 10;
            else                x = *i - '0';
            n += x * floor(pow(from*1.0, p*1.0));
            //cout<< x<< " x "<< pow(from, p)<< " = "<< x*pow(from, p)<<"   :::::::   n = "<< n<< endl;
            p++;    i++;
        }

        s.clear();
        if(!n)  s = "0";
        while(n)
        {
            x = n % to;
            if(x<10)    s.push_back(x + '0');
            else        s.push_back(x - 10 + 'A');
            n /= to;
        }
        if(s.size()>7)
        {
            cout<< "ERROR"<< endl;
            continue;
        }
        reverse(s.begin(), s.end());
        cout<< s<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
