#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i;
    while(cin>> t)
    {
        getchar();
        for(i=1; i<=t; i++)
        {
            vector <char> str;
            vector <int> num;
            int n = 0;
            while(1)
            {
                char ch = getchar();
                if(ch>='A' && ch<='Z')
                {
                    str.push_back(ch);
                    num.push_back(n);
                    n = 0;
                }
                else if(ch != '\n')
                {
                    n = (n * 10) + (ch - 48);
                }
                else
                {
                    num.push_back(n);
                    break;
                }
            }
            cout<< "Case "<< i<< ": ";
            int l = str.size();
            for(int j=0; j<l; j++)
            {
                for(int k=0; k < num[j+1]; k++)
                    cout<< str[j];
            }
            cout<< endl;
        }
    }
    return 0;
}
