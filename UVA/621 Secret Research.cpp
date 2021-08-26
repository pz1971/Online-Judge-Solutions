#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>> n)
    {
        while(n--)
        {
            string s;
            cin>> s;
            if(s.compare("1")==0 || s.compare("4")==0 || s.compare("78")==0)
                cout<< "+";
            else
            {
                int l = s.size();
                if(s.at(l-1)=='5' && s.at(l-2)=='3')
                    cout<< "-";
                else if(s.at(0)=='9' && s.at(l-1)=='4')
                    cout<< "*";
                else if(s.at(0)=='1' && s.at(1)=='9' && s.at(2)=='0')
                    cout<< "?";
            }
            cout<< endl;
        }
    }
    return 0;
}
