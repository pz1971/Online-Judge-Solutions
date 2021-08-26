#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>> s)
    {
        if(s.compare("0")==0)
            break;
        int l = s.size(), rem{};
        for(int i=0; i<l; i++)
        {
            rem = rem*10 + (s.at(i) - '0');
            if(rem >= 17)
                rem %= 17;
        }
        if(rem==0)
            cout<< "1"<< endl;
        else
            cout<< "0"<< endl;
    }
    return 0;
}
