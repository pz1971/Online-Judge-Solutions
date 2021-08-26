#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r;
    while(cin>> r && r!=-1)
    {
        getchar();
        string s1, s2;
        cin>> s1>> s2;
        int guess{0};
        int ar[26];
        for(int i=0; i<26; i++)
            ar[i] = {0};
        int l = s1.size();
        for(int i=0; i<l; i++)
        {
            int x = s1[i] - 97;
            if(ar[x] == 0)
            {
                ar[x] = 1;
                guess++;
            }
        }
        l = s2.size();
        int stroke{7};
        for(int i=0; i<l; i++)
        {
            int x = s2[i] - 97;
            if(ar[x] == 1)
            {
                guess--;
                ar[x] = 0;
            }
            else if(ar[x] == 0)
            {
                stroke--;
                ar[x] = 2;
            }
            if(stroke==0 || guess==0)
                break;
        }
        cout<< "Round "<< r<< endl;
        if(stroke==0)
            cout<< "You lose."<< endl;
        else
        {
            if(guess==0)
                cout<< "You win."<< endl;
            else
                cout<< "You chickened out."<< endl;
        }
    }
    return 0;
}