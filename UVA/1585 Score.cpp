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
            int l = s.size(), score{}, streak{};
            for(int i=0; i<l; i++)
            {
                if(s.at(i)=='X')
                    streak = 0;
                else
                {
                    streak++;
                    score += streak;
                }
            }
            cout<< score<< endl;
        }
    }
    return 0;
}
