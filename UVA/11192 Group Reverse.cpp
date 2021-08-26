#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>> n && n!=0)
    {
        getchar();

        vector <char> str;
        char ch;
        while(1)
        {
            ch = getchar();
            if(ch != '\n')
                str.push_back(ch);
            else
                break;
        }

        int l = str.size();
        int gl = l/n;
        int k = gl/2;
        for(int i=0; i<l; i += gl)
        {
            for(int j = 0; j <  k; j++)
                swap(str[i+j],str[i+gl-j-1]);
        }

        for(int i=0; i<l; i++)
            cout<< str.at(i);
        cout<< endl;
    }
    return 0;
}
