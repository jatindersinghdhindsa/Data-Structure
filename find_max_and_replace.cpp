#include<iostream>
using namespace std;
class high
{
		struct node{
	int data;
	char data1;
	struct node *next;
};
struct node *start;
    public:
    	int size;
    
    	high()
    	{
    		start=NULL;
    		size=0;
		}
    	void create()                //create linklist
    	{
    		int n;
    		
    		cout<<"enter number\n";
    		cin>>n;
    		while(n!=-1){
			size++;
    		struct node * new_node;
    		if(start==NULL){
    		new_node=new node;
    		new_node->data=n;
    		new_node->next=NULL;
    		start=new_node;
    	}
    	else
    	{
    		struct node *t;
    		t=start;
    		new_node=new node;
    		new_node->data=n;
    		new_node->next=start;
    		start=new_node;
		}
		cin>>n;
	}
		}
		void display()              //display beggining
		{
			struct node *p;
			p=start;
			while(p!=NULL)
			{
				cout<<p->data<<endl;
				p=p->next;
			}
			cout<<"total number of element in link list is "<<size<<endl;
		}
		void find()
		{
			struct node *p,*q;
			p=start;
			
			int x,w=0;
			while(p!=NULL)
			{
			x=p->data;
			q=p->next;
				w=-1;
			while(q!=NULL)
			{
			
				if(w<q->data)
				{
					w=q->data;
				}
				q=q->next;
			}
			p->data=w;
			p=p->next;
			
			}
		}

};
main()
{
	high h1;
	h1.create();
	h1.display();
	h1.find();
	h1.display();
}
