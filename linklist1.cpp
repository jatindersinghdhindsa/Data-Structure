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
    	friend mergesort(link,link);
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
		
		void insert_beg()                  //insert at beginning
		{
			int n,i;
			cout<<"enter element to insert at beginning\n";
			cin>>n;
			struct node *new_node;
			new_node=new node;
			new_node->data=n;
			new_node->next=start;
			start=new_node;
		}
		void insert_end()                   //insert end
		{
			int n;
			struct node *new_node,*ptr,*save;
			ptr=start;
			new_node=new node;
			cout<<"enter data to insert at end\n";
			cin>>n;
			while(ptr!=NULL)
			{
				save=ptr;
				ptr=ptr->next;
			}
			new_node->data=n;
			new_node->next=save->next;
			save->next=new_node;
		}
			void display_reverse()             //display_reverse
		{
			struct node *p;
			p=start;
			int a[10],i=0;
			while(p!=NULL)
			{
				a[i]=p->data;
				p=p->next;
				cout<<a[i];
			i++;
			}
		}
		void insert_before()              //insert before
		{
			int item,n;
			cout<<"enter element before which u want to insert\n";
			cin>>item;
			cout<<"enter data\n";
			cin>>n;
			int count=0;
			struct node *ptr,*save;
			ptr=start;
			while(ptr->data!=item)
			{
				save=ptr;
				ptr=ptr->next;
				count++;
			}
			if(count==0)
			{
				insert_beg();
			}
			else{
		
			struct node *new_node;
			new_node=new node;
			new_node->data=n;
			new_node->next=save->next;
			save->next=new_node;
		}
		}
		void insert_after()                        //insert after given element
		{
		int item,n;
			cout<<"enter element after which u want to insert\n";
			cin>>item;
			cout<<"enter data\n";
			cin>>n;
			struct node *ptr,*save;
			ptr=start;
			while(ptr->data!=item)
			{
				save=ptr;
				ptr=ptr->next;
			}
			struct node *new_node;
			new_node=new node;
			new_node->data=n;
			new_node->next=ptr->next;
			ptr->next=new_node;	
		}
		void insert_at_position()
		{
			int n;
			cout<<"enter data\n";
			cin>>n;
			struct node *ptr,*save,*new_node;
			ptr=start;
			save=NULL;
		    int flag=0;
		    while(ptr!=NULL)
		    {
		    	if(ptr->data>n)
		    	{
		    		if(ptr==start)
		    		{
		    			new_node=new node;
		    			new_node->data=n;
		    			new_node->next=start;
		    			start=new_node;
		    			break;
					}
					else
					{
						new_node=new node;
						new_node->data=n;
						new_node->next=save->next;
						save->next=new_node;
						break;
					}
				}
				save=ptr;
				ptr=ptr->next;
			}
		  
}
		
		void delete_position()                  //delete position
		{
			int N;
			cout<<"enter data to delete\n";
			cin>>N;
			struct node *ptr,*save=NULL;
			ptr=start;
			while(ptr->data!=N)
			{
				save=ptr;
				ptr=ptr->next;
			}
			if(save==NULL)
			{
				start=ptr->next;
				delete ptr;
			}
			else
			{
				
			save->next=ptr->next;
			delete ptr;
		}
	}
	void search()                    //searching of element
	{
		struct node *t,*ptr;
		ptr=start;
		int n;
		cout<<"enter element to search\n";
		cin>>n;
		t=NULL;
		int count=0;
		while(ptr!=NULL)
		{
			t=ptr;
			if(ptr->data==n)
			{
			  	cout<<"element found\n"<<count;
			}
			count++;
			ptr=ptr->next;
		}
		
	}
	void delete_middle()                     //delete middle elememt
	{
	   int mid=size/2;
	   int x=0;
	   struct node *ptr,*save=NULL;
	   ptr=start;
	   while(x!=mid)
	   {
	   	x++;
	   	save=ptr;
	   	ptr=ptr->next;
		}
		save->next=ptr->next;
		delete ptr;
		   	
	}
	void reverse()                                //reverse of link list
	{
		struct node *ptr,*save=NULL,*temp=NULL;
		ptr=start;
		while(ptr!=NULL)
		{			
				
		temp=save;
		save=ptr;
		ptr=ptr->next;
		save->next=temp;	
				
			
			}
		start=save;
		}
		
		void merge(link l1,link l2)                        //merging of link list
		{
		 struct node *ptr,*t;
		 ptr=l1.start;
		 t=l2.start;
		 while(ptr->next!=NULL)
		 {
		 ptr=ptr->next;
		 }
		 ptr->next=l2.start;
		}
		void remove_duplicate()
{
    /* Pointer to traverse the linked list */
    struct node* current = start;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    struct node* next_next; 
   
    /* do nothing if the list is empty */
    if (current == NULL) 
       return; 
 
    /* Traverse the list till last node */
    while (current->next != NULL) 
    {
       /* Compare current node with next node */
       if (current->data == current->next->data) 
       {
           /* The sequence of steps is important*/              
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else /* This is tricky: only advance if no deletion */
       {
          current = current->next; 
       }
    }
}
		void remove_duplicate1()                         //remove duplicate
		
		{
  struct node *ptr1, *ptr2, *dup;
  ptr1 = start;
  while(ptr1 != NULL)
  {
     ptr2 = ptr1;
     while(ptr2->next != NULL)
     {
       if(ptr1->data == ptr2->next->data)
       {
         // dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          //free(dup);
       }
       else 
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}
/*{

    struct node *p, *q, *prev, *temp;
 
    p = q = prev = start;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->data == p->data)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
}
	/*	struct node *p,*q,*prev,*temp;
 
    p=start;
    q=start;
    prev=start;
    //q=q->next;
    while(p!= NULL)
    {
q=p->next;
        while(q!=NULL )//&& q->data != p->data)
        {
        	if (p->data==q->data)
        	{
        		prev->next = q->next;
        //    temp = q;
            //delete q;
           // q = prev->next;
			}
			else
			{
			
            prev=q;
            q=q->next;
        }
		}
/*        if (q==NUL     }
  
  p=p->next;
    }
    
	}*/
		void bubble()
		{
			struct node *ptr,*t;
			ptr=start;
			int count=0,p,c;
			while(ptr!=NULL)
			{
				count++;
				ptr=ptr->next;
			}
			ptr=start;
			t=start->next;
		//	count=count+1;
			cout<<count;
		//	cout<<ptr->data<<endl<<t->data;
			for(int p=1;p<=count-1;p++)
			{
				ptr=start;
				t=ptr->next;
				
				for(int c=1;c<=count-p;c++)
				{
					if(ptr->data>=t->data)
					{
						int temp=ptr->data;
						ptr->data=t->data;
						t->data=temp;
				
					}
					else
					{
							ptr=ptr->next;
						t=t->next;	
					}
				}
			}
		}
		void reverse_char()
		{
			char n;
    		
    		cout<<"enter number\n";
    		cin>>n;
    		while(n!='E'){
			size++;
    		struct node * new_node;
    		if(start==NULL){
    		new_node=new node;
    		new_node->data1=n;
    		new_node->next=NULL;
    		start=new_node;
    	}
    	else
    	{
    		struct node *t;
    		t=start;
    		new_node=new node;
    		new_node->data1=n;
    		new_node->next=start;
    		start=new_node;
		}
		cin>>n;
	}
	reverse();
	struct node *p;
			p=start;
			while(p!=NULL)
			{
				cout<<p->data1<<endl;
				p=p->next;
			}
			cout<<"total number of element in link list is "<<size<<endl;
		}
		void insert_even()
		{
			struct node *ptr,*t,*new_node;
			
			ptr=start;
			t=NULL;
			int n;
			cout<<"enter even number to insert \n";
			cin>>n;
			while(ptr!=NULL)
			{
				t=ptr;
				if(ptr->data%2!=0){
				if(ptr==NULL)
				{
					
					new_node=new node;
					new_node->data=n;
					new_node->next=start;
					start=new_node;
				}
				else
				{
			
					new_node=new node;
					new_node->data=n;
				  	new_node->next=t->next;
				  	t->next=new_node;
				}
				
			}
			t=ptr;
			ptr=ptr->next;
		}
		}
		/*node * mergesort(link a, link b){          //merge sort
    node *result = NULL;
    if(a.start ==  NULL)
        return b.start;
    else if(b.start == NULL)
        return a.start;
 

      if(a.start->data <= b.start->data){
         result = a.start;
         result->next = mergesort(a.start->next,b.start);
      }
      else {
        result = b.start;
        result->next = mergesort(a.start,b.start->next);
      }
      return result;
}*/
void inserted()
{
	int p,d;
	cout<<"enter position\n";
	cin>>p;
	cout<<"enter data\n";
	cin>>d;
	 struct node *ptr,*q,*save;
    ptr=start;
    int count=0;
    if(p==0)
            {
        q=new node;
            q->data=d;
            q->next=NULL;
            start=q;
        }
  else{
    while(ptr!=NULL)
        {
        count++;
        save=ptr;
        if(count==p)
            break;
        ptr=ptr->next;
    }
       q=new node;
      q->data=d;
      q->next=save->next;
      save->next=q;
  }
}
	
};
int main()
{
    link list1,list2,list3;
    list1.create();
   list2.create();
  //  list3.display();
    cout<<"enter choice\n";
    int n;
    cin>>n;
    while(n!=-1){
    cout<<"enter 1 to insert at beginning\n";
    cout<<"enter 2 to insert at end\n";
    cout<<"enter 3 to insert before any element\n";
	cout<<"enter 4 to insert after any element\n";
	cout<<"enter 6 to insert at position order\n";
	cout<<"enter 7 to delete given element\n";
	cout<<"enter 8 to search element\n";
	cout<<"enter 9 to delete middle\n";
	cout<<"enter 10 to reverse link list\n";
	cout<<"enter 11 to merge link list\n";
	cout<<"enter 12 to remove duplicate\n";
	cout<<"enter 13 to sort \n";
	cout<<"enter 14 to reverse character array\n";
	cout<<"enter 15 to insert even number before odd\n";
	cout<<"enter 5 to display\n";
	cout<<" enter 16 different insertion\n";

	cout<<"enter choice\n";
	cin>>n;
	switch(n)
	{
		case 1:
			{
				list1.insert_beg();
				break;
			}
			case 2:
				{
					list1.insert_end();
					break;
				}
				case 3:
					{
						list1.insert_before();
						break;
					}
					case 4:
						{
							list1.insert_after();
							break;
						}
						case 5:
							{
								list1.display();
								break;
							}
							case 6:
								{
									list1.insert_at_position();
									break;
								}
								case 7:
									{
										list1.delete_position();
										break;
									}
									case 8:
										{
											list1.search();
											break;
										}
										case 9:
											{
												list1.delete_middle();
												break;
											}
											case 10:
												{
													list1.reverse();
													break;
												}
												case 11:
													{
														list1.merge(list1,list2);
														//list3.display();
														break;
													}
													case 12:
														{
															list1.remove_duplicate1();
															break;
														}
														case 13:
															{
																list1.bubble();
																break;
															}
															case 14:
																{
																	list1.reverse_char();
																	break;
																}
																case 15:
																	{
																		list1.insert_even();
																		break;
																	}
																	case 16:
																		{
																			list1.inserted();
																			break;
																		}
	}
}
  
    return 0;
}
