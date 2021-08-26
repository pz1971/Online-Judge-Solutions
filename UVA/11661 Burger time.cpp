#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n;
    while(cin>> n && n!=0)
    {
        getchar();
        string s;
        getline(cin, s);
        if(s.find('Z')!= string::npos)
            cout<< 0<< endl;
        else
        {
            vector <char> str;
            str.push_back(s.at(0));
            for(long int i=1; i<n; i++)
            {
                if(isalpha(s.at(i)))
                {
                    if(s.at(i)!= s.at(i-1))
                    {
                        str.push_back(s.at(i));
                    }
                }
                else
                    str.push_back(s.at(i));
            }

            long int i, l = str.size(), d{}, min_d{2001000};
            char ch{};
            for(i=0; i<l; i++)
            {
                if(isalpha(str.at(i)))
                {
                    ch = str.at(i);
                    break;
                }
            }
            for(++i; i<l; i++)
            {
                d++;
                if(isalpha(str.at(i)))
                {
                    if(str.at(i)==ch)
                    {
                        d = 0;
                    }
                    else
                    {
                        ch = str.at(i);
                        if(min_d > d)
                            min_d = d;
                        d = 0;
                    }
                }
            }
            cout<< min_d<< endl;
        }
    }
    return 0;
}
