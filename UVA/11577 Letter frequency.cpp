#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        getchar();
        while(t--)
        {
            string s;
            getline(cin, s);
            int ar[26];
            for(int i=0; i<26; i++)
                ar[i] = 0;
            int l = s.size();
            for(int i=0; i<l; i++)
            {
                if(isalpha(s.at(i)))
                {
                    if(isupper(s.at(i)))
                        s.at(i) = s.at(i) - 'A' + 'a';
                    ar[s.at(i)-'a']++;
                }
            }
            int f{ar[0]};
            for(int i=1; i<26; i++)
            {
                if(ar[i]>f)
                    f = ar[i];
            }
            for(int i=0; i<26; i++)
            {
                if(ar[i]==f)
                    cout<< (char)(i+'a');
            }
            cout<< endl;
        }
    }
    return 0;
}
