#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n{};
    while(cin>> n)
    {
        vector <int> num;
        int x{};
        while(n--)
        {
            cin>> x;
            num.push_back(x);
        }
        int l{num.size()};
        if(l==1)
            cout<< "Jolly"<< endl;
        else
        {
            vector <int> diff;
            for(int i=1; i<l; i++)
            {
                diff.push_back( abs( num.at(i)-num.at(i-1) ) );
            }
            sort(diff.begin(), diff.end());
            l = diff.size();
            bool jolly{true};
            for(int i=0, d=0; i<l; i++)
            {
                d++;
                if(diff.at(i)!=d)
                {
                    jolly = false;
                    break;
                }
            }
            if(jolly== true)
                cout<< "Jolly"<< endl;
            else
                cout<< "Not jolly"<< endl;
        }
    }
    return 0;
}
