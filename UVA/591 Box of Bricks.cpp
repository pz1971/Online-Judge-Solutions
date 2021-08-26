#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, s{};

    while(cin>> n && n!=0)
    {
        s++;
        int ar[52], h{};
        for(int i=0; i<n; i++)
        {
            cin>> ar[i];
            h += ar[i];
        }

        h /= n;
        int k{};
        for(int i=0; i<n; i++)
        {
            if(ar[i] < h)
            {
                k += h - ar[i];
            }
        }
        cout<< "Set #"<< s<< endl;
        cout<< "The minimum number of moves is "<< k<< "."<< endl<< endl;
    }
    return 0;
}
