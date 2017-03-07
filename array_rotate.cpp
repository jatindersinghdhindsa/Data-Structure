#include<iostream>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     int i,j,k,l,n,arr[1000],r;
    cin>>n>>r;
    for(i=1;i<=n;i++)
       cin>>arr[i];
   while(r--)
   {
   	int x=arr[n];
   	for(i=n;i>=1;i--)
   	{
   		arr[i]=arr[i-1];
	   }
	   arr[1]=x;
   }
   for(i=1;i<=n;i++)
   cout<<arr[i]<"  ";
	
   
    return 0;
}
