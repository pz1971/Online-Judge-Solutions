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
vb stat(5001, 1);
vi primes{2};
bool is_prime(int n)
{
    if(n<4)
    {
        if(n==1)    return false;
        return true;
    }
    if(n<10002)
    {
        if(n%2 && stat.at(n>>1))   return true;
        return false;
    }
    for(auto i: primes)
    {
        if(n%i==0)  return false;
        if(i*i>n)   break;
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


    for(int i=3; i*i<10002; i+=2)
        if(stat.at(i>>1))
            for(int j=i*i; j<10002; j+=i+i)
                stat.at(j>>1) = 0;
    for(int i=3; i<10002; i+=2) if(stat.at(i>>1))   primes.push_back(i);

    int n, x;
    bool noSum;
    while(cin>> n)
    {
        cout<< n<< " ";
        if(n<5)
        {
            cout<< "is not the sum of two primes!\n";
            continue;
        }
        if(n%2)
        {
            if(is_prime(n-2))
                cout<< "is the sum of 2 and "<< n-2 << ".\n";
            else
                cout<< "is not the sum of two primes!\n";
            continue;
        }
        x = n/2;
        if(x%2==0)  x--;
        noSum = true;
        for( ; x>2 && noSum; x-=2)
        {
            if(is_prime(x) && n!=x+x && is_prime(n-x))
            {
                cout<< "is the sum of "<< x <<" and "<< n-x << ".\n";
                noSum = false;
            }
        }
        if(noSum)
            cout<< "is not the sum of two primes!\n";
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}