#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t, i, j, n;
    double avg, ans, x[1005], count;
    while(scanf("%d", &t)!=EOF)
    {
        for(j=1; j<=t; j++)
        {
            cin >> n;
            for(i=0, avg=0; i<n; i++)
            {
                cin>> x[i];
                avg += x[i];
            }
            avg /= n;
            for(i=0, count=0; i<n; i++)
            {
                if(x[i] > avg)
                    count++;
            }
            ans = count/n*100;
            printf("%.3lf%%\n", ans);
        }
    }
    return 0;
}
