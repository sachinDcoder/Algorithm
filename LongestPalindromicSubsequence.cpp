#include<bits/stdc++.h>
using namespace std;

int longestPall(string str)
{
    int length=str.length();
    int table[length][length];
    memset(table,0,sizeof(table));
    for(int i=0;i<length;i++)
        table[i][i]=1;
    for(int l=2;l<=length;l++)
    {
        for(int i=0;i<length-l+1;i++)
        {
            int j=l+i-1;
            if(l == 2 && str[i] == str[j])
                    table[i][j] = 2;
            else if(str[i]==str[j])
                table[i][j]=table[i+1][j-1]+2;
            else
                table[i][j]=max(table[i][j-1],table[i+1][j]);

        }
    }
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
    return table[0][length-1];
}
int main()
{
    string str;
    cin>>str;
    cout<<longestPall(str)<<endl;
    return 0;
}

/*
agbdba
*/
