#include<bits/stdc++.h>
using namespace std;
bool checker(int num)
{
    while(num % 2 == 0)
        num/=2;
    while(num % 3 == 0)
        num/=3;
    while(num % 5 == 0)
        num/=5;
    return (num == 1) ? true : false;
}
int main()
{
//    int num = 0, cnt = 1;
//    for(int i = 1; cnt <= 1500; i++)
//    {
//        num++;
//        if(checker(num))
//        {
//            cnt++;
//            cout<< cnt <<" ";
//        }
//    }
//    cout<< endl;
    cout<<"The 1500'th ugly number is 859963392."<< endl;
    return 0;
}