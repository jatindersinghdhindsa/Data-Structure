#include<iostream>
using namespace std;
class doubly
{
	struct node 
	{
		int data;
		struct node *next;
		struct node *prev;
		
	};
	struct node *start,*last;
	public:
		doubly()
		{
			start=NULL;
			last=NULL;
		}
		void create()
		{
			int n;
			cout<<"enter data\n";
			cin>>n;
			
			struct node *x,*p;
			p=start;
			while(n!=-1)
{
         	if(start==NULL)
			{
				x=new node;
				x->data=n;
				x->next=NULL;
				x->prev=NULL;
				start=x;
				last=x;
				
			}
			else
			{
				x=new node;
			x->data=n;
				x->next=start;
				x->prev=NULL;
				start->prev=x;
				start=x;	
			}
			cin>>n;
		}
		
	}
		void display()
		{
			struct node *ptr;
			ptr=start;
			do
			{
				cout<<ptr->data<<endl;
				ptr=ptr->next;
			
			}
			while(ptr!=NULL);
			
			
		}
			void display_reverse()
		{
			cout<<"reverse\n";
			struct node *ptr;
			ptr=last;
			do
			{
				cout<<ptr->data<<endl;
				ptr=ptr->prev;
			
			}
			while(ptr!=NULL);	
		}
		void insert_beg(int n)
		{
			struct node *x;
			x=new node;
		
			x->data=n;
			x->prev=start;
			x->next=start;
			start=x;
			
		}
		void insert_end(int n)
		{
			struct node *x;
			x=new node;
		
			x->data=n;
			x->prev=last;
			x->next=NULL;
			last->next=x;
			last=x;
		}
		void insert_pro()
		{
			struct node *x,*s,*nn;
			x=start;
			int n,f=0;
			cout<<"enter number to insert\n";
			cin>>n;
			while(x!=last)
			{
				if(x->data>n)
				{
					if(x==start)
					{
						f=1;
						insert_beg(n);
						break;
					}
					else
					{
						f=1;
						nn=new node;
						nn->data=n;
						nn->prev=s;
						nn->next=x;
						s->next=nn;
						x->prev=nn;
						break;
					}
				}
				s=x;
				x=x->next;
			}
			if(f==0)
			{
				insert_end(n);
			}
		}
		void search(int n)
		{
			struct node *p;
			p=start;
			int f=0;
			while(p!=last)
			{
				if(p->data==n)
				{
					f=1;
					cout<<"found\n";
					break;
				}
				p=p->next;
			}
			if(f==0)
			{
				cout<<"not found\n";
			}
		}
		void bubble()
		{
			int p,c;
			struct node *ptr,*ptr1,*q;
			ptr1=start;
			int count=0;
			while(ptr1->next!=NULL)
			{
					
				ptr1=ptr1->next;
				count++;
			
			}
			count=count+1;
			//ptr=start;
			for(p=1;p<=count-1;p++)
			{
				ptr=start;
				q=ptr->next;
				for(c=1;c<=count-1;c++)
				{
					if(ptr->data>=q->data)
					{
						int temp=ptr->data;
						ptr->data=q->data;
						q->data=temp;
					}
					else
					{
						
						ptr=ptr->next;
						q=q->next;
					}
				}
			}
		}
		void delete_beg()
		{
			start=start->next;
			start->prev=NULL;
			
			
		}
		void delete_end()
		{
			last=last->prev;
			last->next=NULL;
		}
};
main()
{
	doubly l1;
	int n;
	while(n!=-1){
	cout<<"enter 1 to create link list\n";
	cout<<"enter 2 to display\n";
	cout<<"enter 3 to insert at begining\n";
	cout<<"enter 4 to display reverse\n";
	cout<<"enter 5 to insert at end\n";
	cout<<"enter 6 to insert at proper position\n";
	cout<<"enter 7 to search\n";
	cout<<"enter 8 to bubble sort\n";
	cout<<"enter 9 to delete begin\n";
	cout<<"enter 10 to delete end\n";
	cout<<"enter choice\n";
	cin>>n;
	switch(n)
	{
		case 1:
			{
			  l1.create();
				break;
			}
			case 2:
				{
					l1.display();
					break;
				}
				case 3:
					{int d;
						cout<<"enter data\n";
						cin>>d;
					l1.insert_beg(d);
					break;	
					}
					case 4:
						{
							l1.display_reverse();
							break;
						}
						case 5:
							{
								int d;
						cout<<"enter data\n";
						cin>>d;
								l1.insert_end(d);
								break;
							}
							case 6:
								{
									l1.insert_pro();
									break;
								}
								case 7:
									{
										int n;
										cout<<"enter number to search\n";
										cin>>n;
										l1.search(n);
										break;
									}
									case 8:
										{
											l1.bubble();
											break;
										}
										case 9:
											{
												l1.delete_beg();
												break;
											}
											case 10:
												{
													l1.delete_end();
													break;
												}
									
										}

}

}
