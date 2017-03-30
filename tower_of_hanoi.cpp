#include<iostream>
//#include<conio.h>
using namespace std;
void fun(int ,char ,char ,char);
main()
{
int i,n;
cin>>n;
fun(n,'s','d','t');
return 0;
}
void fun(int n,char s,char d,char t)
{
if(n==1)
{
cout<<"move "<<s<<" to "<< d <<endl;

return;}

fun(n-1,s,t,d);
cout<<"move from "<<s<<" to "<<d<<endl;
fun(n-1,t,d,s);
}
