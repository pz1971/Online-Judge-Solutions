#include<bits/stdc++.h>
using namespace std;
int func(int x, int y)
{
    return (x*x*x) - (y*y*y);
}
int main()
{
    int n;
    while(cin>> n && n!=0)
    {
        int n2 = sqrt(n);
        bool found{false};
        for(int j=1; j<=n2; j++)
        {
            for(int i=n2; i>0; i--)
            {
                if(n == func(i, j))
                {
                    cout<< i<< " "<< j<< endl;
                    found = true;
                    break;
                }
            }
            if(found == true)
                break;
        }
        if(found==false)
            cout<< "No solution"<< endl;
    }
    return 0;
}
