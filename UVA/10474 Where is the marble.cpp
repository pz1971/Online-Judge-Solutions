#include<bits/stdc++.h>
using namespace std;
int main()
{
    size_t t{};
    int n_num, q_num;
    while(cin>> n_num>> q_num)
    {
        if(n_num==0 && q_num==0)
            break;
        t++;

        int x, qur[10005];
        vector <int> ar(10005, 0);
        for(int i=0; i<n_num; i++)
        {
            cin>> x;
            ar[x]++;
        }
        for(int i=0; i<q_num; i++)
            cin>> qur[i];

        cout<< "CASE# "<< t<< ":"<< endl;

        for(int i=0; i<q_num; i++)
        {
            x = qur[i];
            if(ar[x]==0)
                cout<< x<< " not found"<< endl;
            else
            {
                int indx{1};
                for(int j=0; j<x; j++)
                {
                    if(ar[j]!=0)
                        indx += ar[j];
                }
                cout<< x<< " found at "<< indx<< endl;
            }
        }
    }
    return 0;
}
