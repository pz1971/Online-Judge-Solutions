#include<bits/stdc++.h>
using namespace std;
int main()
{
    size_t t;
    while(cin>> t)
    {
        getchar();
        while(t--)
        {
            string s;
            cin>> s;
            double sum{};
            int l = s.size();
            for(int i=0; i<l; i++)
            {
                if(isalpha(s.at(i)))
                {
                    int n{};
                    if(i + 1 < l && isdigit(s.at(i+1)))
                    {
                        n = s.at(i+1) - '0';
                        if(i + 2 < l && isdigit(s.at(i+2)))
                            n = n*10 + s.at(i+2) - '0';
                    }
                    else
                        n = 1;
                    if(s.at(i)== 'C')
                        sum += n * 12.01;
                    else if(s.at(i)== 'H')
                        sum += n * 1.008;
                    else if(s.at(i)== 'O')
                        sum += n * 16.00;
                    else if(s.at(i)== 'N')
                        sum += n * 14.01;
                }
            }
            cout<< fixed << showpoint<< setprecision(3);
            cout<< sum<< endl;
        }
    }
    return 0;
}
