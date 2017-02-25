#include<bits/stdc++.h>
using namespace std;
/*#define debug(a)    			cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define show1(a,n) 			cout<<endl;for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define show2(a,n,m) 			cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<" ";}cout<<endl;}

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define pb(i) 				push_back(i)
#define mp(i,j) 			make_pair(i,j)
#define mod 				1000000007
#define F           			first
#define S           			second*/
#define endl        			'\n'
#define ll 				long long
clock_t start;

bool a[90][90],b[90][90];

void functn(int n){
	for(int i=0;i<n;i++){
		//pass
	}
}

void functn1(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++);//pass
	}
}
 void merge(int* arr1,int start,int mid,int end)
{
	int i=start,k=start,j=mid+1,arr2[1000],h;
		for(h=start;h<=end;h++) arr2[h]=arr1[h];
	while(i<=mid&&j<=end)
	{
		if(arr2[i]<=arr2[j])
       {
		 arr1[k]=arr2[i];
		 i++;
		 k++;
		 }
		 else
		 {
		 	arr1[k]=arr2[j];
		 	j++;
			k++;
		 }
	}
	while(i<=mid)
	{
		arr1[k]=arr2[i];
		i++;
		k++;
	}
	while(j<=end)
	{
		arr1[k]=arr2[j];
		j++;
		k++;
	}

}
void mergesort(int* arr1,int start,int end)
{
	if(start>=end)
	return;
    int	mid=(start+end)/2;
	mergesort(arr1,start,mid);
	mergesort(arr1,mid+1,end);
	merge(arr1,start,mid,end);
}

int main(){
//	start=clock();
//	freopen("input.txt","r+",stdin);
	ios_base::sync_with_stdio(false);cin.tie(false);cout.tie(false);
	for(int j=1;j<=90;j++){
		int n=j;
		start=clock();
		
		functn(n*1000000);
		
		int time=( (clock() - start) / 1.0 / CLOCKS_PER_SEC )*100;
		a[time][j-1]=1;
	}
	for(int i=89;i>=0;i--){
		cout<<" |";
		for(int j=0;j<90;j++){
			if(a[i][j])cout<<'0';
			else cout<<' ';
		}
		cout<<endl;
	}
	cout<<" |";
	for(int i=0;i<=90;i++){
		cout<<"-";
	}
	
cout<<"next/n/n/n";

	

	for(int j=1;j<=90;j++){
		int n=j;
		start=clock();
		
		functn1(n*100);
		
		int time=( (clock() - start) / 1.0 / CLOCKS_PER_SEC )*100;
	
		b[time][j-1]=1;
	}
	for(int i=89;i>=0;i--){
		cout<<" |";
		for(int j=0;j<90;j++){
			if(b[i][j])cout<<'0';
			else cout<<' ';
		}
		cout<<endl;
	}
	cout<<" |";
	for(int i=0;i<=90;i++){
		cout<<"-";
	}
	
	
	cout<<"Y-axis: time in micro seconds\n";
	
for(int j=1;j<=90;j++){
		int n=j;
		start=clock();
		int a[n*10];
		for(ll s=0;s<n*10-1;n++) a[s]=8;
	    a[n*10-1]=3;
	    
		mergesort(a,0,n*10-1);
		
		int time=( (clock() - start) / 1.0 / CLOCKS_PER_SEC )*100;
	
		b[time][j-1]=1;
	}
	for(int i=89;i>=0;i--){
		cout<<" |";
		for(int j=0;j<90;j++){
			if(b[i][j])cout<<'0';
			else cout<<' ';
		}
		cout<<endl;
	}
	cout<<" |";
	for(int i=0;i<=90;i++){
		cout<<"-";
	}
	

//	cerr<<"\n\ntime: "<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<endl;
	return 0;
}




