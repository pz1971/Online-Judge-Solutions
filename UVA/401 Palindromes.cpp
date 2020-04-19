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
const string rev_list{"E3EJLJS2SZ5ZAAHHIIMMOO00TTUUVVWWXXYY1188"};
const int len = rev_list.size();
bool is_palin(string s)
{
    auto i = s.begin();
    auto j = s.end()-1;
    while(i<j)
    {
        if(*i != *j)    return false;
        i++;    j--;
    }
    return true;
}
bool is_mirror(string s)
{
    auto i = s.begin();
    auto j = s.end()-1;
    int k;
    while(i < j)
    {
        for(k=0; k<len; k++)
        {
            if(*i == rev_list.at(k))
            {
                if(*j != rev_list.at(k+1))
                    return false;
                break;
            }
        }
        if(k==len)  return false;
        i++;    j--;
    }
    if(i==j)
    {
        for(k=12; k<len; k+=2)
            if(rev_list.at(k)==*i)  return true;
        return false;
    }
    return true;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    string s;
    bool x, y;
    while(cin>> s)
    {
        cout<< s<< " -- ";
        x = is_palin(s);
        y = is_mirror(s);
        if(x && y)  cout<< "is a mirrored palindrome.";
        else if(x)  cout<< "is a regular palindrome.";
        else if(y)  cout<< "is a mirrored string.";
        else        cout<< "is not a palindrome.";
        cout<< endl<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
