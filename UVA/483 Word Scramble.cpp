#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin, s))
    {
        int l = s.size(), b{};
        for(int i=0; i<l; i++)
        {
            if(s.at(i)==' ')
            {
                reverse( s.begin() + b, s.begin()+i);
                b = i+1;
            }
        }
        reverse(s.begin() + b , s.end());
        cout<< s<< endl;
    }
    return 0;
}
