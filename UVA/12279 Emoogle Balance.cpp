#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n{}, tc{};
    while(cin>> n && n!=0)
    {
        int zero{}, non_zero{};
        for(int i=0; i<n; i++)
        {
            int x;
            cin>> x;
            (x==0)? zero++ : non_zero++;
        }
        cout<< "Case "<< ++tc<< ": "<< non_zero - zero<< endl;
    }
    return 0;
}
