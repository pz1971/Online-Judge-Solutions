#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int arr[1005], x, n, i, sorted, count;
    while(scanf("%d", &n)!=EOF)
    {
        count = 0;
        for(i=0; i<n; i++)
            cin>> arr[i];
        while(1)
        {
            sorted = 1;
            for(i=0; i<n-1; i++)
            {
                if(arr[i]>arr[i+1])
                {
                    x = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = x;
                    sorted = 0;
                    count++;
                }
            }
            if(sorted == 1)
                break;
        }
        cout<< "Minimum exchange operations : " << count<< endl;
    }
    return 0;
}
