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


    vi primes{2};
    vb stat(20000, 1);
    for(int i=3; i*i<40000; i+=2)
    {
        if(stat.at(i>>1))
        {
            for(int j=i*i; j<40000; j+= i+i)
                stat.at(j>>1) = 0;
        }
    }
    for(int i=3; i<40000; i+=2)
        if(stat.at(i>>1))
            primes.push_back(i);
    stat.clear();

    int n, m;
    vi divisors, cnts;
    while(cin>> n>> m)
    {
        cout<< m<< " ";
        if(m<=n || m==1)    cout<< "divides "<< n<< "!\n";
        else if(m==0)       cout<< "does not divide "<< n<< "!\n";
        else
        {
            for(auto i: primes)
            {
                if(m%i==0)
                {
                    divisors.push_back(i);
                    cnts.push_back(0);
                    while(m%i==0)
                    {
                        m/=i;
                        cnts.back()++;
                    }
                }
                if(m==1)    break;
            }
            if(m>1)
            {
                divisors.push_back(m);
                cnts.push_back(1);
            }

            int l = cnts.size();
            bool yeah{true};
            for(int i=0; i<l; i++)
            {
                if(divisors.at(i)>n)
                {
                    yeah = false;
                    break;
                }
                int cnt = n/divisors.at(i);
                llu product{divisors.at(i)};
                for(int p=2; p<33; p++)
                {
                    product *= divisors.at(i);
                    if(product>n)   break;
                    cnt += p - 1;
                }
                if(cnt<cnts.at(i))
                {
                    yeah = false;
                    break;
                }
            }

            if(yeah)    cout<< "divides "<< n<< "!\n";
            else        cout<< "does not divide "<< n<< "!\n";
            divisors.clear();
            cnts.clear();
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}