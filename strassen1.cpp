#include<stdio.h>
void add(int n,int a[][n],int b[][n],int t[][n])
{
     int i,j;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
            t[i][j]=a[i][j]+b[i][j];
     }
}
void sub(int n,int a[][n],int b[][n],int t[][n])
{
     int i,j;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
            t[i][j]=a[i][j]-b[i][j];
     }
}
void mul(int n,int a[][n],int b[][n],int c[][n])
{
    int i,j,k;
    if(n<=2)
    {
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
         return;
     }

    int a11[n/2][n/2],a12[n/2][n/2],a21[n/2][n/2],a22[n/2][n/2];
    int b11[n/2][n/2],b12[n/2][n/2],b21[n/2][n/2],b22[n/2][n/2];
    int c11[n/2][n/2],c12[n/2][n/2],c21[n/2][n/2],c22[n/2][n/2];
    int p[n/2][n/2],q[n/2][n/2],r[n/2][n/2],s[n/2][n/2],t[n/2][n/2],u[n/2][n/2],v[n/2][n/2],t1[n/2][n/2],t2[n/2][n/2];
    for(i=0;i<n/2;i++)//divide
    {
        for(j=0;j<n/2;j++)
        {
            a11[i][j]=a[i][j];
            a12[i][j]=a[i][j+n/2];
            a21[i][j]=a[i+n/2][j];
            a22[i][j]=a[i+n/2][j+n/2];
            b11[i][j]=b[i][j];
            b12[i][j]=b[i][j+n/2];
            b21[i][j]=b[i+n/2][j];
            b22[i][j]=b[i+n/2][j+n/2];
        }
    }
    add(n/2,a11,a22,t1);
    add(n/2,b11,b22,t2);
    mul(n/2,t1,t2,p);//p
    add(n/2,a21,a22,t1);
    mul(n/2,t1,b11,q);//q
    sub(n/2,b12,b22,t1);
    mul(n/2,a11,t1,r);//r
    sub(n/2,b21,b11,t1);
    mul(n/2,a22,t1,s);//s
    add(n/2,a11,a12,t1);
    mul(n/2,t1,b22,t);//t
    sub(n/2,a21,a11,t2);
    add(n/2,b11,b12,t1);
    mul(n/2,t2,t1,u);//u
    sub(n/2,a12,a22,t2);
    add(n/2,b22,b21,t1);
    mul(n/2,t2,t1,v);

    add(n/2,p,s,t1);
    sub(n/2,v,t,t2);
    add(n/2,t1,t2,c11);//c11
    add(n/2,r,t,c12);//c12
    add(n/2,q,s,c21);//c21
    add(n/2,p,r,t1);
    sub(n/2,u,q,t2);
    add(n/2,t1,t2,c22);//c22

    for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        {
            c[i][j]=c11[i][j];
        }
    }
    for(i=0;i<n/2;i++)
    {
        for(j=n/2;j<n;j++)
        {
            c[i][j]=c12[i][j-n/2];
        }
    }
    for(i=n/2;i<n;i++)
    {
        for(j=0;j<n/2;j++)
        {
            c[i][j]=c21[i-n/2][j];
        }
    }
    for(i=n/2;i<n;i++)
    {
        for(j=n/2;j<n;j++)
        {
            c[i][j]=c22[i-n/2][j-n/2];
        }
    }
}

int main()
{
    int n=4,i,j;
    //scanf("%d",&n);
    int a[4][4];
    int b[4][4];
    //cout<<"Enter the first matrix "<<n<<" x "<<n<<" :"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //cout<<"Enter the second matrix "<<n<<" x "<<n<<" :"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int c[4][4];
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }*/
    mul(n,a,b,c);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

