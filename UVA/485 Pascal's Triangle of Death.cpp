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

//void scanf(ll &n)
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
string add(string a, string b)
{
    reverse(a.begin(), a.end());    reverse(b.begin(), b.end());
    if(a.size()<b.size())
        swap(a, b);
    int l = a.size(), l2 = b.size();
    while(l2<l)
    {
        b.push_back('0');   l2++;
    }
    string sum{""};
    int i, rem{};
    for(i=0; i<l; i++)
    {
        rem += a.at(i)-'0' + b.at(i)-'0';
        sum.push_back(rem%10 + '0');
        rem /= 10;
    }
    while(rem)
    {
        sum.push_back(rem%10 + '0');
        rem/=10;
    }
    reverse(sum.begin(), sum.end());
    return sum;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    cout<< 1 << endl<< 1<<" " << 1<< endl;
    vector <string> vs{"1", "1"}, temp;
    bool cntnue{true};
    while(cntnue)
    {
        temp.push_back("1");
        auto i = vs.begin();
        while(i != vs.end()-1)
        {
            temp.push_back(add(*i, *(i+1)));
            if(temp.back().size()> 60)
            {
                cntnue = false;
            }
            i++;
        }
        temp.push_back("1");
        vs = temp;
        i = vs.begin()+1;
        cout<< 1;
        while(i!=vs.end())
        {
            cout<< " "<< *i;
            i++;
        }
        cout<< endl;
        temp.clear();
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}