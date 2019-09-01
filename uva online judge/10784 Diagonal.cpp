

formula:

ax^2 + bx + c = 0   >>>>>> x = (-b + sqrt(b^2 - 4*a*c))/2*a







#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long x;
    int t = 0;
    while(cin>> x && x!=0)
    {
        t++;
        long long n;
        
n = ceil(((3 + sqrt (9 + ( 8 * x)))/2));   /// adding 1 instead of ceil function will ocuur w/a in the case, the function is divisible by 2
        
	cout<<"Case "<< t<< ": "<< n<< endl;
    }
    return 0;
}
