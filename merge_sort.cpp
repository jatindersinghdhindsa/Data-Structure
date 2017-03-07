#include<iostream>
using namespace std;
class merge
{
	int a[100];
	public:
		void get(int n)
		{	
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
		}
		void sort(int bg,int m,int mi,int e)
		{
			int t[100],k=0;
			int b=bg,m1=mi;
			
			while(b<=m && m1<=e)
			{
				if(a[b]<a[m1])
				{
					t[k]=a[b];
					b++;
					k++;
				}
				else
				{
					t[k]=a[m1];
					m1++;
					k++;
				}
			}
			if(b>m)
			{
				for(int i=m1;i<=e;i++)
				{
					t[k]=a[i];
					k++;
				}
			}
			else
			{
			 for(int i=b;i<=m;i++)
				{
					t[k]=a[i];
					k++;
				}	
			}
			k=0;
			for(int i=bg;i<=e;i++)
			{
				a[i]=t[k];
				k++;
			}
		}
		void part(int b,int e)
		{
			int m;
			if(b<e)
			{
				m=(b+e)/2;
				part(b,m);
				part(m+1,e);
				sort(b,m,m+1,e);
			}
		}
		void show(int n)
		{
			cout<<"output\n";
			for(int i=0;i<n;i++)
			{
				cout<<a[i]<<endl;
			}
		}
	
};
main()
{
	merge m1;
	int n;
	
	cout<<"enter size of array\n";
	cin>>n;
	cout<<"enter array\n";
	m1.get(n);
	m1.part(0,n-1);
    m1.show(n);
}
