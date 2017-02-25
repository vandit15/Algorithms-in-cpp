#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef vector<int> vect;
typedef vector<vector<int> > matrix;

matrix Add(matrix a, matrix b,int n)
{
    matrix c(n,vect(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j]=a[i][j]+b[i][j];

    return c;
}

matrix Sub(matrix a, matrix b,int n)
{
    matrix c(n,vect(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j]=a[i][j]-b[i][j];

    return c;
}

matrix BruteMul(matrix a,matrix b,int n)
{
    matrix c(n,vect(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];

    return c;
}

matrix DnC_Mul(matrix A,matrix B, int n)
{
    if(n<=2)
    {
        return BruteMul(A,B,n);
    }

    matrix a(n/2,vect(n/2,0));
    matrix b(n/2,vect(n/2,0));
    matrix c(n/2,vect(n/2,0));
    matrix d(n/2,vect(n/2,0));
    matrix e(n/2,vect(n/2,0));
    matrix f(n/2,vect(n/2,0));
    matrix g(n/2,vect(n/2,0));
    matrix h(n/2,vect(n/2,0));

    for(int i=0;i<n/2;i++)
        for(int j=0;j<n/2;j++)
        {
           a[i][j]=A[i][j];
           b[i][j]=A[i][j+n/2];
           c[i][j]=A[i+n/2][j];
           d[i][j]=A[i+n/2][j+n/2];
           e[i][j]=B[i][j];
           f[i][j]=B[i][j+n/2];
           g[i][j]=B[i+n/2][j];
           h[i][j]=B[i+n/2][j+n/2];
        }
    matrix p1=DnC_Mul(a,Sub(f,h,n/2),n/2);
    matrix p2=DnC_Mul(Add(a,b,n/2),h,n/2);
    matrix p3=DnC_Mul(Add(c,d,n/2),e,n/2);
    matrix p4=DnC_Mul(d,Sub(g,e,n/2),n/2);
    matrix p5=DnC_Mul(Add(a,d,n/2),Add(e,h,n/2),n/2);
    matrix p6=DnC_Mul(Sub(b,d,n/2),Add(g,h,n/2),n/2);
    matrix p7=DnC_Mul(Sub(a,c,n/2),Add(e,f,n/2),n/2);

    matrix ca=Sub(Add(p5,Add(p4,p6,n/2),n/2),p2,n/2);
    matrix cb=Add(p1,p2,n/2);
    matrix cc=Add(p3,p4,n/2);
    matrix cd=Sub(Add(p1,p5,n/2),Add(p3,p7,n/2),n/2);

    matrix C(n,vect(n,0));

    for(int i=0;i<n/2;i++)
        for(int j=0;j<n/2;j++){
            C[i][j]=ca[i][j];
            C[i][j+n/2]=cb[i][j];
            C[i+n/2][j]=cc[i][j];
            C[i+n/2][j+n/2]=cd[i][j];
        }
    return C;
}

int main()
{
    int n;
    cout<<"Enter the Dimensions of the square matrix"<<endl;
    cin>>n;

    if(!n>0){
		cout<<"\nWrong Input.";
		return 0;
	}
	int N= pow(2,ceil(log2(n)));

    matrix a(N,vect(N,0));
    matrix b(N,vect(N,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cout<<"Enter element A["<<i<<"]["<<j<<"] : ";
			cin>>a[i][j];
		}
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
			cout<<"Enter element B["<<i<<"]["<<j<<"] : ";
			cin>>b[i][j];
		}

	matrix c_brute=BruteMul(a,b,n);
	cout<<"Matrix A*B (brute method) : "<<endl;
	for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<"\t"<<c_brute[i][j];
        }
        cout<<endl;
    }

    matrix c_DnC=DnC_Mul(a,b,N);
	cout<<"Matrix A*B (Divide and Conquer) : "<<endl;
	for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<"\t"<<c_DnC[i][j];
        }
        cout<<endl;
    }
    return 0;
}
