#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n{};
    while(cin>> n && n!=0)
    {
        int sum{1};
        for(int i=2; i<=n; i++)
            sum += i*i;
        cout<< sum<< endl;
    }
    return 0;
}
