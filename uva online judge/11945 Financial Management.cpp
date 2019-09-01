#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        for(int tc=1; tc<=t; tc++)
        {
            double sum{0.0};
            for(int i=0; i<12 ;i++)
            {
                double x;
                cin>> x;
                sum += x;
            }
            sum /= 12.0;

            cout<< tc<< " $";
            if(sum>999.0)
            {
                int bc = (int)sum/1000;
                sum -= (bc*1000.0);
                cout<< bc <<",";
                printf("%.2lf\n", sum);
            }
            else
            {
                printf("%.2lf\n", sum);
            }
        }
    }
    return 0;
}
