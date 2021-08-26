#include<bits/stdc++.h>
using namespace std;
unsigned long long scew_bin(int n)
{
    return pow(2, n+1) - 1;
}
int main()
{
    string s;
    while(cin>> s && s.compare("0")!=0)
    {
        unsigned long long sum{};
        int l = s.size();
        reverse(s.begin(), s.end());

        for(int i= 0; i<l; i++)
        {
            int n = s.at(i) - '0';
            if(n!=0)
            {
                sum += n * scew_bin(i);
            }
        }
        cout<< sum<< endl;
    }
    return 0;
}
