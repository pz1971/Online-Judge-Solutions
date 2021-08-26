#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, i, l;
    bool cont;
    while(getline(cin, s))
    {
        l = s.size();
        cont = false;
        n = 0;
        for(i=0; i<l; i++)
        {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            {
                if(cont == false)
                {
                    n++;
                    cont = true;
                }
            }
            else
                cont = false;
        }
        cout<< n<< endl;
    }
    return 0;
}
