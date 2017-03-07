#include<iostream>
using namespace std;
class array
{
	int a[100],x[100]={0},n;
	public:
		void get()
		{
			cout<<"enter size\n";
			cin>>n;
			cout<<"enter array\n";
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
		}
	
		void max_difference()
		{
			int k=0;
			for(int i=0;i<n;i++)
			{
				for(int j=n-1;j>=0;j--)
				{
					if(a[j]>a[i])
					{
						x[k]=a[j]-a[i];
						k++;
					}
				}
			}
			
		}
		void display()
		{
			int s=0;
			for(int d=0;d<n;d++)
			{
				
				if(x[d]>s)
				s=x[d];
			}
			cout<<s<<endl;
		}
};
main()
{
	array a1;
	a1.get();
	a1.max_difference();
	a1.display();
	
}
