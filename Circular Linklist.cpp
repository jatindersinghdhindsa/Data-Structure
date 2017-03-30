#include<iostream>
#include<malloc.h>
using namespace std;
class link
{
	struct node{
	int data;
	char data1;
	struct node *next;
};
struct node *start;
    public:
    	int size;
    	link()
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
    		struct node * new_node,*ptr;
    		ptr=start;
    		if(start==NULL){
    		new_node=new node;
    		new_node->data=n;
    		new_node->next=new_node;
    		start=new_node;
    	}
    	else
    	{
    		//ptr=start;
    		while(ptr->next!=start)
    		{
    			ptr=ptr->next;
			}
    		struct node *t;
    		t=start;
    		new_node=new node;
    		new_node->data=n;
    		new_node->next=start;
    		start=new_node;
    		ptr->next=new_node;
		}
		cin>>n;
	}
		}
		void display()              //display beggining
		{
			struct node *p;
			p=start;
			do
			{
		    	cout<<p->data<<endl;
				p=p->next;
			}
			while(p!=start);
			
			
			cout<<"total number of element in link list is "<<size<<endl;
		}
		void insert_beg(int n)
		{
			int i;
			//cout<<"enter element to insert at beginning\n";
			//cin>>n;
			struct node *new_node,*p;
			p=start;
			do
			{
				p=p->next;
			}
			while(p!=start);
			
			new_node=new node;
			new_node->data=n;
			new_node->next=start;
		start=new_node;
		p->next=new_node;
		}
		void insert_end(int n)
		{
			
			struct node *new_node,*ptr,*save;
			ptr=start;
			new_node=new node;
			//cout<<"enter data to insert at end\n";
			//3cin>>n;
			while(ptr->next!=start)
			{
				save=ptr;
				ptr=ptr->next;
			}
			new_node->data=n;
			new_node->next=ptr->next;
			ptr->next=new_node;
		}
		void search(int n)
		{
			int count=0,flag=0;
			node *ptr,*q;
			ptr=start;
		
			//cout<<"enter element\n";
			//cin>>n;
		/*	if(ptr==start && ptr->data==n)
				{
					cout<<"element found  \n";
				}
			while(ptr->next!=start)
			{
				
				if(ptr->next==start && ptr->data==n )
				cout<<"element found\n";
				if(ptr->data==n)
				{
					flag=1;
					cout<<"element found "<<endl;
					break;
				}
				ptr=ptr->next;
				count++;
			}
			if(flag==0)
			cout<<"not found\n";*/
			do{
				if(ptr->data==n){
				
				flag=1;
				break;
			}
				else{
				
			
			}
				ptr=ptr->next;
			}
			while(ptr!=start);
			if(flag==1)
			{
				cout<<"found\n";
				
			}
			else
			{
				cout<<"not\n";
			}
		}
		void insert_pos()
		{
			int po,n,count=1;
			cout<<"enter data\n";
			cin>>n;
			int flag=0;
			//ptr=t;
			node *ptr,*t,*new_node,*s;
			ptr=start;
			s=NULL;
			do{
				if(ptr->data>n)
				{
					if(ptr==NULL)
					{
						flag=1;
						insert_beg(n);
						break;
					}
	            	else
	            	{
	            		flag=1;
	            		new_node=new node;
	            		new_node->data=n;
	            		new_node->next=s->next;
	            		s->next=new_node;
	            		break;
					}
				}
					else
					{
						s=ptr;
			ptr=ptr->next;
					
			}
			
			}
			while(ptr!=start);
		if(flag==0)
		{
			insert_end(n);
		}
		}
		void insert_before()
		{
			struct node *new_node,*p,*t;
			p=start;
			int n,x;
			cout<<"enter data before whick yo want to insert\n";
			cin>>n;
			cout<<"enter data\n";
			cin>>x;
			while(p->data!=n)
			{
				t=p;
				p=p->next;
			}
			new_node =new node;
			new_node->data=x;
			new_node->next=t->next;
			t->next=new_node;
		}
		void reverse()
		{
			struct node *p1,*p2,*p3,*t;
			p1=start;
			p2=NULL;
		
			while(p1->next!=NULL)
			{
				p3=p1->next;
				p1->next=p2;
				p2=p1;
			  p1=p3;	
			}
		start=p2;
		}
		void delete_first()
		{
			struct node *ptr,*s,*t;
			ptr=start;
			start=ptr->next;
			 // delete ptr;
			 // ptr=start;
			 s=start;
			while(s->next!=start)
			{
				t=s;
				s=s->next;
			}
		t->next=start;    //because we update start to ptr->next
		 
		}
		void delete_end()
		{
			node *p,*t;
			p=start;
		
			while(p->next!=start)
			{
				t=p;
				p=p->next;
			}
			t->next=start;
		    delete p;
		}
		void delete_element(int n)
		{
			struct node *p,*s,*t;
			p=start;
			s=NULL;
			do
			{
				
				if(p->data==n)
				{
					if(p==start)
					{
						delete_first();
						break;
					}
					else
					{
						s->next=p->next;
						//s=p->next;
						//p=p->next;
						delete p;
						break;
						
					}
				}
				else
				{
						s=p;
				p=p->next;
				}
			
			}
			while(p!=start);
		}
	};
	main()
	{
          link l1;
		  l1.create();
		  int n;
    cin>>n;
    while(n!=-1){
    cout<<"enter 1 to insert at beginning\n";
    cout<<"enter 2 to display\n";
    cout<<"enter 3 to search element\n";
	cout<<"enter 4 to insert at end\n";
	cout<<"enter 5 to insert at position\n";
	cout<<"enter 6 to before any element\n";
	cout<<"enter 7 to reverse the list\n";
	cout<<"enter 8 to delete 1st node\n";
	cout<<"enter 9 to delete end\n";
	cout<<"enter 10 to delete element\n";
	cout<<"enter choice\n";
	cin>>n;
	switch(n)
	{
		case 1:
			{
				int n;
				cout<<"enter number to insert at beg\n";
				cin>>n;
				l1.insert_beg(n);
				break;
			}
			case 2:
				{
					
					l1.display();
					break;
				}
				case 3:
					{
						int n;
						cout<<"enter no to search\n";
						cin>>n;
						l1.search(n);
						break;
					}
					case 4:
						{
							int n;
							cout<<"enter element insert at end\n";
							cin>>n;
							l1.insert_end(n);
							break;
						}
						case 5:
							{
								l1.insert_pos();
								break;
							}
							case 6:
								{
									l1.insert_before();
									break;
								}
								case 7:
									{
										l1.reverse();
										break;
									}
									case 8:
										{
											l1.delete_first();
											break;
										}
										case 9:
											{
												l1.delete_end();
												break;
											}
											case 10:
												{
													int n;
													cout<<"enter data to delete\n";
													cin>>n;
													l1.delete_element(n);
													break;
												}
	}
		  			
		}
	}   //end 5290
