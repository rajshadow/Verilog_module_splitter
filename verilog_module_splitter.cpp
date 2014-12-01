#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int main()
{
	string str,fileName,in_path,out_path;

	cout<<"Enter full path of input file (eg. C:\\folder1\\test.v):\n";
	getline(cin,in_path);
	cout<<"\nEnter full path of output/destination folder (eg. C:\\folder1\\SplitFiles) :\n";
	getline(cin,out_path);
	ifstream fin(in_path);
	
	int i;

	while(fin.eof()==0)
	{
		getline(fin,str,'\n');
		//cout<<str<<endl;
		if(str.length()>=6 && str.compare(0,6,"module")==0)
			{
				fileName="";
				for(i=7;str[i]!='(' && str[i]!=';';++i)
					fileName+=str[i];
				ofstream fout(out_path+"\\"+fileName+".v");
				while(1)
				{
					fout<<str<<endl;
					getline(fin,str,'\n');	
					if(str.length()>=9 && str.compare(0,9,"endmodule")==0)
					{
						fout<<str;						//print "endmodule" at the end of file before closing it
						fout.close();
						break;
					}
				}
				
			}
		
	}
	fin.close();
	cout<<"\n\nOPERATION COMPLETE. press any key to exit.";
	_getch();
}