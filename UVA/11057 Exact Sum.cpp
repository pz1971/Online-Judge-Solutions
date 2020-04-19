#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>> n)
    {
        int ar[10005];
        for(int i=0; i<n; i++)
            cin>> ar[i];
        int m{}, diff{1000002}, x{}, y{}, indx{n};
        cin>> m;
        sort(ar, ar+n);
        for(int i=0; i<n; i++)
        {
            if(ar[i]>=m)
                break;
            if(i >= indx)
                break;
            for(int j=indx-1; j>i; j--)
            {
                if(ar[i]+ar[j]<m)
                    break;
                if(ar[i]+ar[j]==m)
                {
                    if(ar[j]-ar[i]<diff)
                    {
                        x = ar[i];
                        y = ar[j];
                        diff = ar[j] - ar[i];
                    }
                    indx = j;
                    break;
                }
            }
        }
        cout<< "Peter should buy books whose prices are "<< x<< " and "<< y<< "."<< endl<< endl;
    }
    return 0;
}
