#include<iostream>
using namespace std;
int **divideMatrix(int **a,int n,int is,int ie,int js,int je)
{
    //cout<<"divide start"<<endl;
    int **ax;
    ax=new int*[n];
    for(int i=0;i<n;i++)
    {
        ax[i]=new int[n];
    }
    for(int i=0,x=is;i<n && x<ie;i++,x++)
    {
        for(int j=0,y=js;j<n && y<je;j++,y++)
        {
            ax[i][j]=a[x][y];
        }
    }
    //cout<<"divide end"<<endl;
    return ax;
}
int** addSub(int **a,int **b,int n,const bool f)
{
    int **ax;
    ax=new int*[n];
    for(int i=0;i<n;i++)
    {
        ax[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(f==true)
                ax[i][j]=a[i][j]+b[i][j];
            else
                ax[i][j]=a[i][j]-b[i][j];
        }
    }
    return ax;
}
int** strassen(int **a,int **b,int n)
{
    if(n>2)
    {
        /*if(n%2==0)
        {*/
            int **a11,**a12,**a21,**a22;
            a11=new int*[n/2];
            a12=new int*[n/2];
            a21=new int*[n/2];
            a22=new int*[n/2];
            for(int i=0;i<n/2;i++)
            {
                a11[i]=new int[n/2];
                a12[i]=new int[n/2];
                a21[i]=new int[n/2];
                a22[i]=new int[n/2];
            }
            a11=divideMatrix(a,n/2,0,n/2,0,n/2);
            a12=divideMatrix(a,n/2,0,n/2,n/2,n);
            a21=divideMatrix(a,n/2,n/2,n,0,n/2);
            a22=divideMatrix(a,n/2,n/2,n,n/2,n);
            int **b11,**b12,**b21,**b22;
            b11=new int*[n/2];
            b12=new int*[n/2];
            b21=new int*[n/2];
            b22=new int*[n/2];
            for(int i=0;i<n/2;i++)
            {
                b11[i]=new int[n/2];
                b12[i]=new int[n/2];
                b21[i]=new int[n/2];
                b22[i]=new int[n/2];
            }
            b11=divideMatrix(b,n/2,0,n/2,0,n/2);
            b12=divideMatrix(b,n/2,0,n/2,n/2,n);
            b21=divideMatrix(b,n/2,n/2,n,0,n/2);
            b22=divideMatrix(b,n/2,n/2,n,n/2,n);
            int **p,**q,**r,**s,**t,**u,**v,**c11,**c12,**c21,**c22;
            p=strassen(addSub(a11,a22,n/2,true),addSub(b11,b22,n/2,true),n/2);
            q=strassen(addSub(a21,a22,n/2,true),b11,n/2);
            r=strassen(a11,addSub(b12,b22,n/2,false),n/2);
            s=strassen(a22,addSub(b21,b11,n/2,false),n/2);
            t=strassen(addSub(a11,a12,n/2,true),b22,n/2);
            u=strassen(addSub(a21,a11,n/2,false),addSub(b11,b12,n/2,true),n/2);
            v=strassen(addSub(a12,a22,n/2,false),addSub(b22,b21,n/2,true),n/2);
            c11=addSub(addSub(addSub(p,s,n/2,true),t,n/2,false),v,n/2,true);
            c12=addSub(r,t,n/2,true);
            c21=addSub(q,s,n/2,true);
            c22=addSub(addSub(addSub(p,r,n/2,true),q,n/2,false),u,n/2,true);
            int **c;
            c=new int*[n];
            for(int i=0;i<n;i++)
                c[i]=new int[n];

            for(int i=0;i<n/2;i++)
                for(int j=0;j<n/2;j++)
                    c[i][j]=c11[i][j];

            for(int i=0;i<n/2;i++)
                for(int j=n/2;j<n;j++)
                    c[i][j]=c12[i][j-n/2];

            for(int i=n/2;i<n;i++)
                for(int j=0;j<n/2;j++)
                    c[i][j]=c21[i-n/2][j];

            for(int i=n/2;i<n;i++)
                for(int j=n/2;j<n;j++)
                    c[i][j]=c22[i-n/2][j-n/2];

            return c;
        //}
    }
    else
    {
        int **c;
        c=new int*[2];
        for(int i=0;i<2;i++)
        {
            c[i]=new int[2];
        }
        int p,q,r,s,t,u,v;
        p=(a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
        q=(a[1][0] + a[1][1])*b[0][0];
        r=a[0][0]*(b[0][1] - b[1][1]);
        s=a[1][1]*(b[1][0] - b[0][0]);
        t=(a[0][0] + a[0][1])*b[1][1];
        u=(a[1][0] - a[0][0])*(b[0][0] + b[0][1]);
        v=(a[0][1] - a[1][1])*(b[1][0] + b[1][1]);
        c[0][0]=p+s-t+v;
        c[0][1]=r+t;
        c[1][0]=q+s;
        c[1][1]=p+r-q+u;
        return c;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of matrix:";
    cin>>n;
    int **a,**b;
    a=new int*[n];
    b=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
        b[i]=new int[n];
    }
    cout<<"Enter the first matrix "<<n<<" x "<<n<<" :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter the second matrix "<<n<<" x "<<n<<" :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>b[i][j];
        }
    }
    int **c;
    c=new int*[n];
    for(int i=0;i<n;i++)
        c[i]=new int[n];
    c=strassen(a,b,n);
    cout<<"Strassen matrix : "<<n<<" x "<<n<<" :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        delete []a[i];
        delete []b[i];
        delete []c[i];
    }
    delete []a;
    delete []b;
    delete []c;
    return 0;
}
/*
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4
*/
/*
2 3 4 5
3 2 1 4
2 3 4 1
1 2 3 4

4 5 6 2
3 4 5 2
7 7 5 4
7 8 4 3

80 90 67 41
53 62 49 26
52 58 51 29
59 66 47 30

37 44 51 54
30 36 42 44
49 58 67 84
49 55 61 83
*/
