#include<cstdio>
using namespace std;
int main()
{
    int t, i;
    double term1, term2, final, att, ct[3], sum;
    cin>> t;
    for(i=1; i<=t; i++)
    {
        cin>> term1>>term2>>final>> att>> ct[0]>>ct[1]>> ct[2];
        sort(ct, ct+3);

        sum = term1 + term2 + final + att + (ct[1]+ct[2]) / 2.0;
        ///cout<< sum<< endl;;
        cout<< "Case "<< i<< ": ";
        if(sum>=90)
            printf("A\n");
        else if(sum>=80 )
            printf("B\n");
        else if(sum>=70 )
            printf("C\n");
        else if(sum>=60 )
            printf("D\n");
        else
            printf("F\n");
    }
    return 0;
}