#include<iostream>
#include<string.h>
#include<cstdlib>
#define MAX 100
using namespace std;
bool isSafe(const bool board[MAX][MAX],const int r,const int c,const int n)
{
    for(int i=0;i<c;i++)
        if(board[r][i])
            return false;
    /*for(int i=0;i<r;i++)
        if(board[i][r])
            return false;*/
    for(int i=r,j=c;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    /*for(int i=r,j=c;i>=0 && j<n;i--,j++)
    {
        if(board[i][j])
            return false;
    }*/
    for(int i=r,j=c;j>=0 && i<n;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    return true;
}
bool NQueen(bool board[MAX][MAX],const int n,int c)
{
    bool f;
    if(c>=n)
    {
        static int cnt=0;
        cnt++;
        cout<<"Solution Number "<<cnt<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,c,n))
        {
            board[i][c]=1;
            NQueen(board,n,c+1);
            board[i][c]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the size of size of the board :";
    cin>>n;
    bool board[MAX][MAX];
    memset(board,0,sizeof(board));
    if(!NQueen(board,n,0))
    {
        cout<<"No solution is possible";
        exit(0);
    }
    return 0;
}
