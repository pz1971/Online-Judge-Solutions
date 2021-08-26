#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double n, s, u , v, a, t, tc=0;
    while(1)
    {
        tc++;
        cin>>n;
        if(n==0)
            break;

        else if(n==1)
        {
            cin>> u >> v>> t;
            a = (v-u)/t;
            s = u*t + a*pow(t,2)/2;
            cout<< "Case "<< tc<<": ";
            printf("%.3lf %.3lf\n", s, a);
        }
        else if(n==2)
        {
            cin>> u>> v >> a;
            t = (v-u)/a;
            s = u*t + a*pow(t,2)/2;
            cout<< "Case "<< tc<<": ";
            printf("%.3lf %.3lf\n", s, t);
        }
        else if(n==3)
        {
            cin>> u>> a>> s;
            v = sqrt(pow(u,2)+ 2*a*s);
            t = (v-u)/a;
            cout<< "Case "<< tc<<": ";
            printf("%.3lf %.3lf\n", v, t);
        }
        else if(n==4)
        {
            cin>> v>> a>> s;
            u = sqrt(pow(v,2)- 2*a*s);
            t = (v-u)/a;
            cout<< "Case "<< tc<<": ";
            printf("%.3lf %.3lf\n", u, t);
        }
    }
    return 0;
}

