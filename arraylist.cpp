/*
 * arraylist.cpp
 * 
 * Copyright 2012 LIJIN C <lij@ubuntu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <iostream>
#include <stdlib.h>

using namespace std;
class ArrayList
{
	int *data,*temp,size,num;
	public:
	ArrayList();
	int Insert(int item);
	int Delete();
	int AccessElement(int pos);
    void Display(); 
};

ArrayList::ArrayList()
{ 
	num=0;
	size=0;
	data=NULL;
}

int ArrayList::Insert(int item)
{
	if(size==0)
	{
		data=new int[1];
		data[0]=item;
		num=1;
		size=1;
		return 0;
	}
	if(size==num)
	{
		size*=2;
		temp=new int[size];
		for(int i=0;i<num;i++)
		{
			temp[i]=data[i];
		}
		temp[num]=item;
		data=temp;
		num+=1;
    	return 0;
	}
	else
	{
		data[num]=item;
		num+=1;
		return 0;
	}
	return -1;
}	
	
int ArrayList::Delete()			
{
	if(size==0)
	{
		return -1;
	}
	if(size==1)
	{
		data=NULL;
		size=0;
	    return 0;
	}
	num-=1;
	if(num==size/2)
	{
		for(int i=0;i<num;i++)
	    {
			temp[i]=data[i];
		}
		data=temp;
		size/=2;
		return 0;
	}
	else
	{
		data[num]=-1;
	    return 0;
	}
return -1;
}
			
int ArrayList::AccessElement(int pos)
{
	if(pos<num)
	{
		return data[pos];
	}
	else		
	{
		return -1;
	}
}	

void ArrayList::Display()
{
	for(int i=0;i<num;i++)
	{
		cout<<data[i]<<",";
	}
	cout<<endl;
}


void Helper()
{
	cout<<"Insert : i <element> "<<endl;
	cout<<"Remove : r "<<endl;
	cout<<"Search : s <position> "<<endl;
	cout<<"Display: d"<<endl;
	cout<<"Quit   : q"<<endl;
}

int main (void) 
{   
	ArrayList Table;
	int element;
	char ch;
	int val;
	Helper();
	while(1)
	{   
		cout<<">";
		cin>>ch;
		switch(ch)
		{
			case 'i':
			cin>>element;
			val=Table.Insert(element);
			if(val==-1)
			cout<<"Cant Insert To table"<<endl;
			break;
			case 'r':
			val=Table.Delete();
			if(val==-1)
			cout<<"Table empty"<<endl;
			break;
			case 's':
			cin>>element;
			val=Table.AccessElement(element);
			if(val==-1)
			cout<<"Item Not Found"<<endl;
			else
			cout<<"Value : "<<val<<" position : "<<element<<endl;
			break;
			case 'd':
			Table.Display();
			break;
			case 'q':
			exit(0);
			break;
			default:
			Helper();
		}
	}
		return 0;
	
}
	

