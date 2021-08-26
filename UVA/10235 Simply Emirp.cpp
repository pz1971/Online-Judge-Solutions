#include<bits/stdc++.h>
using namespace std;
vector <int> primes{3, 5, 7};
bool isprime(int n)
{
    if(n==2 || n==1)
        return true;
    int u = primes.size();
    u--;
    int l{};
    while(l<=u)
    {
        int m = (l+u)/2;
        if(n==primes.at(m))
            return true;
        else if(n>primes.at(m))
            l = m+1;
        else
            u = m-1;
    }
    return false;
}
int main()
{
    for(int i=11; i<1000010; i+=2)
    {
        bool prime{true};
        for(auto j: primes)
        {
            if(i%j==0)
            {
                prime = false;
                break;
            }
            if(j>sqrt(i))
                break;
        }
        if(prime)
            primes.push_back(i);
    }
    int n;
    while(cin>> n)
    {
        cout<< n <<" ";

        if(isprime(n))
        {
            int n2{}, n3{n};
            while(n3)
            {
                n2 = n2*10 + n3%10;
                n3 /= 10;
            }
            if(n2==n)
                cout<< "is prime."<< endl;
            else
            {
                if(isprime(n2))
                    cout<< "is emirp."<< endl;
                else
                    cout<< "is prime."<< endl;
            }
        }
        else
            cout<< "is not prime."<< endl;
    }
    return 0;
}
