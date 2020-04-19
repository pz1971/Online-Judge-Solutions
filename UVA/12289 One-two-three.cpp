#include<bits/stdc++.h>
using namespace std;
int main()
{
    size_t t;
    while(cin>> t)
    {
        while(t--)
        {
            string s;
            cin>> s;
            if(s.size()==5)
                cout<< "3"<< endl;
            else
            {
                if((s.at(0)=='o' && s.at(1)=='n') || (s.at(1)=='n' && s.at(2)=='e') || (s.at(0)=='o' && s.at(2)=='e') )
                    cout<< "1"<< endl;
                else
                    cout<< "2"<< endl;
            }
        }
    }
    return 0;
}
