#include<iostream>
using namespace std;
main()
{
	cout<<"enter number of vertices\n";
	int n;
	cin>>n;
	cout<<"enter number of edges\n";
	int m;
	cin>>m;
	int Z[30][30]={0};
	int que[50];
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		Z[a][b]=1;
	}
	
	int v;
	cout<<"enter first vertices\n";v
	cin>>v;
	cout<<"vertices\n";
	int s=1;
	int l=1;
	que[s++]=v;
	while(l<=m)
	{
	for(int i=1;i<=n;i++)
	{
	if(Z[l][i]==1)
	{
		for(int f=1;f<=s;f++)
		{
			if(que[f]==i)
			goto w;
		}
	que[s++]=i;
	}
    }
    	w:	
    l++;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<que[i]<<endl;
	}
}
