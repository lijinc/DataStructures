/*
 * hashtable.cpp
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

/*2012-11-30  LIJIN C  <lij@ubuntu>

 * Initial relese
 * Implimented Insert Delete Search & Display on HashTable
*/


#include <iostream>
#include <stdlib.h>

using namespace std;
struct Data
{
	int key;
	int value;
};
class Hasher
{
	Data Table[51];
	public:
	Hasher();
	int HashFunction1(int key);
	int HashFunction2(int key);
	int Hash(int key,int i);
	int Insert(Data d);	
    int Delete(int key);
    int Search(int key);
    void Display();
};

Hasher::Hasher()
{	
	for(int i=0;i<51;i++)
	{
		Table[i].key=-1;
		Table[i].value=0;
	}
}	
			
int Hasher::HashFunction1(int key)	
{
	return(key%51);
}

int Hasher::HashFunction2(int key)
{
	return(key%47);
}

int Hasher::Hash(int key,int i)
{
	return((HashFunction1(key)+(i*HashFunction2(key)))%51);
}

int Hasher::Insert(Data d)
{   
	  int i=0,Index;
      while(i!=51)
      {
		  Index=Hash(d.key,i);
		  if(Table[Index].key==-1||Table[Index].key==-2) //-1 null -2 deleted
		  {
			  Table[Index]=d;
			  return Index;
          }
          else
          {
			  i++;
		  }
	  }
	  return -1;
  }
		
int Hasher::Delete(int key)
{
	  int i=0,Index;
	  Index=Hash(key,i);
      while(i<51&&Table[Index].key!=-1)
      {
		  Index=Hash(key,i);
		  if(Table[Index].key==key)
		  {   
			  Table[Index].key=-2; //-2 deleted element			  
			  return 1;
          }
          else
          {
			  i++;
		  }
	  }
	  return -1;
}

int Hasher::Search(int key)
{
	  int i=0,Index;
	  Index=Hash(key,i);
      while(i<51&&Table[Index].key!=-1)
      {
		  Index=Hash(key,i);
		  if(Table[Index].key==key)
		  {
			  return Table[Index].value;
          }
          else
          {
			  i++;
		  }
	  }
	  return -1;	  	
}
void Hasher::Display()
{
	int j=0;
	for(j=0;j<51;j++)
	{   
		if(Table[j].key!=-1&&Table[j].key!=-2)
		{
			cout<<"Key : "<<Table[j].key<<" Value : "<<Table[j].value<<" Position : "<<j<<endl;
		}	
	}
}	     	

void Helper()
{
	cout<<"Insert: i <key> <value>"<<endl;
	cout<<"Remove: r <key> "<<endl;
	cout<<"Search: s <key> "<<endl;
	cout<<"Display: d"<<endl;
	cout<<"Quit: q"<<endl;
}

int main (void) 
{   
	Hasher HashTable;
	Data Item;
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
			cin>>Item.key;
			cin>>Item.value;
			val=HashTable.Insert(Item);
			if(val==-1)
			cout<<"Cant Insert To Hashtable"<<endl;
			break;
			case 'r':
			cin>>Item.key;
			val=HashTable.Delete(Item.key);
			if(val==-1)
			cout<<"Item not found"<<endl;
			break;
			case 's':
			cin>>Item.key;
			val=HashTable.Search(Item.key);
			if(val==-1)
			cout<<"Item Not Found"<<endl;
			else
			cout<<"Key : "<<Item.key<<" Value : "<<val<<endl;
			break;
			case 'd':
			HashTable.Display();
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
