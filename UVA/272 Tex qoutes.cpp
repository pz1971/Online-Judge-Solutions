#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    vector<char> out;
    bool dbl{false};
    while(getline(cin, str))
    {
        int j= str.size();
        for(int i=0; i<j; i++)
        {
            char ch = str.at(i);
            if(ch=='"')
            {
                if(dbl==false)
                {
                    out.push_back('`');
                    out.push_back('`');
                    dbl = true;
                }
                else
                {
                    out.push_back('\'');
                    out.push_back('\'');
                    dbl = false;
                }
            }
            else
            {
                out.push_back(ch);
            }
        }
        out.push_back('\n');
    }
    int l=out.size();
    for(int i=0; i<l; i++)
        cout<< out.at(i);
    return 0;
}
