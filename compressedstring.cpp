/*
 * compressedstring.cpp
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
 * It compresses a text file..
 * 
 * 
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int main(int argc, char *argv[]) {
	if(argc!=2)
	{
		cout<<"Enter filename as commandline argument!";
		exit(0);
	}	
	vector<char> myvector;
	vector<char>::iterator it; 
	char letter[1],str[10],cfname[20];
	int length=0,count=1;
	int inputfile=open(argv[1],O_RDONLY);
	if(inputfile<0)
	{
		cout<<"File Does Not Exist";
		exit(0);
	}
	while(read(inputfile,letter,1))
	{
		myvector.push_back(letter[0]);
		length++;
	}
	int k=close(inputfile);
	int i=0;
	int writefile;
	int clen=sprintf(cfname,"%s.zzz",argv[1]);
	int outfile=open(cfname,O_WRONLY|O_TRUNC|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	while(i<length-1)
	{	int j=i;
		letter[0]=myvector[i];
		writefile=write(outfile,letter,1);
		while(myvector[j]==myvector[j+1])
		{
			count+=1;
			j+=1;
		}
		i+=count;
		int len=sprintf(str,"%d",count);
		writefile=write(outfile,str,len);
		count=1;
	}


	
}
