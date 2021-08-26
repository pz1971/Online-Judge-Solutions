#include<bits/stdc++.h>
using namespace std;
bool isvowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return true;
    else
        return false;
}
int main()
{
    int l, n;
    while(cin>> l>> n)
    {
        string s[21];
        getchar();
        for(int i=0; i<l; i++)
        {
            getline(cin, s[i]);
        }
        while(n--)
        {
            string input_str;
            cin>> input_str;
            bool regular{true};
            for(auto i: s)
            {
                if(i.find(input_str)!=string::npos)
                {
                    regular = false;
                    vector <char> output_str;
                    int l = i.size();
                    bool space_found{false};
                    for(int j=0; j<l; j++)
                    {
                        if(space_found)
                        {
                            output_str.push_back(i.at(j));
                        }
                        else
                        {
                            if(i.at(j)==' ')
                                space_found = true;
                        }
                    }
                    for(auto x: output_str)
                        cout<< x;
                    cout<< endl;
                    break;
                }
            }
            if(regular)
            {
                int l = input_str.size();
                if(input_str.at(l-1)=='y' && !isvowel(input_str.at(l-2)))
                {
                    for(int i=0; i<l-1; i++)
                        cout<< input_str.at(i);
                    cout<< "ies"<< endl;
                }
                else
                {
                    char ch1 = input_str.at(l-1), ch2 = input_str.at(l-2);;
                    if(ch1=='o' || ch1=='s' || ch1=='x' || (ch1=='h' && ch2=='c') || (ch1=='h' && ch2=='s'))
                    {
                        cout<< input_str<< "es"<< endl;
                    }
                    else
                    {
                        cout<< input_str<< "s"<< endl;
                    }
                }
            }
        }
    }
    return 0;
}
