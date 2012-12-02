/*
 * uniquestring.cpp
 * 
 * finds weather a string has unique character
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
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	char s[512];
	int i=0;
	vector<char> myvector;
	cin>>s;
	int flag=0;
	while(i<strlen(s))
	{
		myvector.push_back(s[i]);
		i++;
	}

	sort(myvector.begin(),myvector.end());
	i=0;
	while(i<strlen(s)-1)
	{
		if(myvector[i]==myvector[i+1])
		{
		cout<<"Not unique";
		flag=1;
		break;
		}
		else
	i++;
	}
	if(flag==0)
	cout<<"Unique";
	
}
