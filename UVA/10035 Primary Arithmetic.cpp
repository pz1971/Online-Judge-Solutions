#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long int n1, n2, n;
    int ccount, carry;
    while(cin>>n1>>n2)
    {
        if(n1==0 && n2==0)
            break;
        n = n1 + n2;
        carry = ccount = 0;
        while(n)
        {
            int x = (n1%10) + (n2%10) + carry;
            if(x>9)
            {
                ccount++;
                carry = x/10;
            }
            else
                carry = 0;
            n1/=10;
            n2/=10;
            n/=10;
        }
        if(ccount == 0)
            cout<< "No carry operation."<< endl;
        else if(ccount == 1)
            cout<< "1 carry operation."<< endl;
        else
            cout<< ccount <<" carry operations."<< endl;

    }
    return 0;
}
