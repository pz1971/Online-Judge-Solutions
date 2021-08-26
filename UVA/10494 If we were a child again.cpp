#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        vector <char> n1;
        vector <int> d;
        unsigned long long n2{0}, rem{0};
        char ch;
        int l{s.size()}, i;
        for(i=0; i<l; i++)
        {
            if(s.at(i)!=' ')
            {
                int x = s.at(i) - '0';
                n1.push_back(x);
            }
            else
                break;
        }
        for(++i; i<l; i++)
        {
            if(s.at(i)!= ' ')
            {
                ch = s.at(i);
                break;
            }
        }
        for(++i; i<l; i++)
        {
            if(s.at(i)!= ' ')
            {
                break;
            }
        }

        for(; i<l; i++)
        {
            int x = s.at(i) - '0';
            n2 = n2*10 + x;
        }

        l = n1.size();
        for(i=0; i<l; i++)
        {
            rem = rem*10 + n1.at(i);
            if(rem >= n2)
            {
                d.push_back(rem/n2);
                rem %= n2;
            }
            else
            {
                d.push_back(0);
            }
        }
        if(ch == '%')
            cout<< rem<< endl;
        else if(ch =='/')
        {
            l = d.size();
            if(l==0)
                cout<< "0";
            else if(l==1)
                cout<< d.at(0);
            else
            {
                bool zeros {false};
                for(i=0; i<l; i++)
                {
                    if(zeros == false)
                    {
                        if(d.at(i) != 0)
                        {
                            zeros = true;
                            cout<< d.at(i);
                        }
                    }
                    else
                    {
                        cout<< d.at(i);
                    }
                }
            }
            cout<< endl;
        }
    }
    return 0;
}
