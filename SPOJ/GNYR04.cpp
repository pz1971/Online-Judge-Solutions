#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;

int point(double r)
{
    if(r<=3)    return 100;
    if(r<=6)    return 80;
    if(r<=9)    return 60;
    if(r<=12)    return 40;
    if(r<=15)    return 20;
    return 0;
}
 
int main()
{
 
    double x , y , r , yo{};
    int sum1, sum2;
 
    while( cin >> x >> y )  {
        yo = x;
        sum1 = 0;
        r = sqrt(x*x + y*y);
        sum1 += point(r);
        for(int i=1; i<=2; i++)
        {
            cin>> x>> y;
            r = sqrt(x*x + y*y);
            sum1 += point(r);
        }
        sum2 = 0;
        for(int i=1; i<=3; i++)
        {
            cin>> x>> y;
            r = sqrt(x*x + y*y);
            sum2 += point(r);
        }
        if(yo==-100)    break;
        cout<< "SCORE: "<< sum1<< " to "<< sum2<< ", ";
        if(sum1==sum2)  cout<< "TIE."<< endl;
        else
        {
            sum1>sum2 ? cout<< "PLAYER 1 WINS." : cout<< "PLAYER 2 WINS.";
            cout<< endl;
        }
    }
 
    return 0;
}
 