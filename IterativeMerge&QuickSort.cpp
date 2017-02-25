#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int partition(int Arr[],int l,int r)
{
	int pivot=Arr[r];
	int i=l-1;
	for (int j=l;j<=r-1;j++)
	{
		if(Arr[j]<=pivot)
		{
			i++;
			swap(Arr[i],Arr[j]);
		}
	}
	swap(Arr[i+1],Arr[r]);
	return i+1;
}

void QuickSort_i(int Arr[],int l,int r)
{
	int top;
	int stack[r-l+1];
	top=-1;

	stack[++top]=r;
	stack[++top]=l;

	while(top>=0)
	{
		l=stack[top--];
		r=stack[top--];

		int p=partition(Arr,l,r);

		if(p+1<r)
		{
			stack[++top]=r;
			stack[++top]=p+1;
		}
		if(p-1>l)
		{
			stack[++top]=p-1;
			stack[++top]=l;
		}

	}
}

void merge(int Arr[],int left,int mid,int right)
{
	int n1=mid-left+1;
	int n2=right-mid;

	int A[n1];
	int B[n2];

	for(int i=0;i<n1;i++)
		A[i]=Arr[left+i];

	for(int i=0;i<n2;i++)
		B[i]=Arr[mid+1+i];

	int i=0,j=0,k=left;

	while(i<n1 && j<n2)
	{
		if(A[i]<=B[j])
		{
			Arr[k++]=A[i++];
		}
		else
		{
			Arr[k++]=B[j++];
		}
	}
	while(i<n1)
		Arr[k++]=A[i++];
	while(j<n2)
		Arr[k++]=B[j++];
}

void MergeSort_i(int Arr[],int n)
{
	int current_size;
	int left_index;

	for(current_size=1;current_size<n;current_size=2*current_size)
	{
		for(left_index=0;left_index<n-1;left_index=left_index+2*current_size)
		{
			int mid=left_index+current_size-1;
			if(mid>n-1)
			{
				mid=(left_index+n-1)/2;
			}
			int right_index=min(left_index+2*current_size-1,n-1);
			merge(Arr,left_index,mid,right_index);
		}
	}
}

main()
{
	int n;
	cout<<"Enter the number of elements you wish to sort: "<<endl;
	cin>>n;
	int Arr[n],Q[n],M[n];
	cout<<"Enter the elements you wish to sort :"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>Arr[i];
		Q[i]=Arr[i];
		M[i]=Arr[i];
	}

	cout<<endl<<"Iterative Quick Sort :"<<endl;
	QuickSort_i(Q,0,n-1);
	for(int i=0;i<n;i++)
		cout<<Q[i]<<" ";
	cout<<endl;

	cout<<endl<<"Iterative Merge Sort :"<<endl;
	MergeSort_i(M,n);
	for(int i=0;i<n;i++)
		cout<<M[i]<<" ";
	cout<<endl;

	return 0;
}
