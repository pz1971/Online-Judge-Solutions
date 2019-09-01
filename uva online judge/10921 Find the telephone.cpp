#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i;
    char str[32];
    while(cin>>s)
    {
        int l = s.size();
        for(i=0; i<l ; i++)
        {
            if(s[i]>='A' && s[i]<='C')
                str[i] = '2';
            else if(s[i]>='D' && s[i]<='F')
                str[i] = '3';
            else if(s[i]>='G' && s[i]<='I')
                str[i] = '4';
            else if(s[i]>='J' && s[i]<='L')
                str[i] = '5';
            else if(s[i]>='M' && s[i]<='O')
                str[i] = '6';
            else if(s[i]>='P' && s[i]<='S')
                str[i] = '7';
            else if(s[i]>='T' && s[i]<='V')
                str[i] = '8';
            else if(s[i]>='W' && s[i]<='Z')
                str[i] = '9';
            else
                str[i] = s[i];
        }
        str[l] = '\0';
        puts(str);
    }
    return 0;
}
