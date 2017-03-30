#include<iostream>
#include<string.h>
using namespace std;
class pq
{
	struct node
	{
	char data;
	int pr;
	struct node *next;
		
	};
	node *f,*r;
	public:
	pq()
	{
	f=r=NULL;	
	}
	void create()
	{
		int d=0,p;
	
		while(d!=-1)
		{
		cout<<"enter data\n";
		cin>>d;
		cout<<"enter pr\n";
		cin>>p;
		node *nn;
		if(f==NULL)
		{
			nn=new node;
			nn->data=d;
			nn->pr=p;
		    nn->next=NULL;
		    f=r=nn;
		}
		else
		{
			nn=new node;
			nn->data=d;
			nn->pr=p;
			nn->next=NULL;
			r->next=nn;
			r=nn;
		}
		cin>>d;
	}
	}
	void display()
	{
		node *p;
		p=f;
		while(p!=NULL)
		{
			cout<<p->data<<" "<<p->pr<<endl;
			p=p->next;
		}
	}
		void bubble()
		{
			int c=0;
			node *p,*r,*q;
			r=f;
			while(r!=NULL)
			{
				r=r->next;
				c++;
			}
			p=f;
			for(int i=1;i<=c;i++)
			{
				p=f;
				q=p->next;
				for(int j=i+1;j<=c;j++)
				{
					if(p->pr>q->pr)
					{
						 int t1;
						 char t2;
						t1=p->pr;
						t2,p->data;
						p->pr=q->pr;
						p->data=q->data;
						q->pr=t1;
						q->data=t2;
					}
					p=p->next;
				q=q->next;
				}
			
			}
		}
	
};
main()
{
	pq q1;
	q1.create();
	q1.display();
	cout<<"output \n";
	q1.bubble();
	q1.display();
	
}
