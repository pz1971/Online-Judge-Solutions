#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<< "PERFECTION OUTPUT"<< endl;
    while(cin>> n)
    {
        if(n==0)
            break;
        //int i{sqrt(n)};
        int sum {0};
//        if(i*i == n)
//        {
//            sum += i;
//            i--;
//        }
        for(int j=1; j<=n/2; j++)
        {
            if(n%j==0)
            {
                sum += j;
            }
        }
        if(sum == n)
            printf("%5d  PERFECT\n", n);
        else if(sum < n)
            printf("%5d  DEFICIENT\n", n);
        else
            printf("%5d  ABUNDANT\n", n);
    }
    cout<< "END OF OUTPUT"<< endl;
    return 0;
}
