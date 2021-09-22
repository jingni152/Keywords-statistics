#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct count
{
	char* name;
	int count;
};


int main()
{
	vector<string> codeword;
	int n = 0,n1=0,n2 = 0, n3 = 0;
	int a,b,c;
	int d=0,e=0,f=0;
	string string1,str,s;
	
	struct count arr[63] = 
	{
	"asm",0,
	"else",0,
	"new",0,
	"this",0,
	"auto",0,
	"enum",0,
	"operator",0,
	"throw",0,
	"bool",0,
	"explicit",0,
	"private",0,
	"true",0,
	"break",0,
	"export",0,
	"protected",0,
	"try",0,
	"case",0,
	"extern",0,
	"public",0,
	"typedef",0,
	"catch",0,
	"false",0,
	"register",0,
	"typeid",0,
	"char",0,
	"float",0,
	"reinterpret_cast",0,
	"typename",0,
	"class",0,
	"for",0,
	"return",0,
	"union",0,
	"const",0,
	"friend",0,
	"short",0,
	"unsigned",0,
	"const_cast",0,
	"goto",0,
	"signed",0,
	"using",0,
	"continue",0,	
	"if",0,
	"sizeof",0,
	"virtual",0,
	"default",0,
	"inline",0,
	"static",0,
	"void",0,
	"delete",0,
	"int",0,
	"static_cast",0,
	"volatile",0,
	"do",0,
	"long",0,
	"struct",0,
	"wchar_t",0,
	"double",0,
	"mutable",0,
	"switch",0,
	"while",0,
	"dynamic_cast",0,
	"namespace",0,
	"template",0,	
		
	};
	

	struct count arr1[1] =
	{
		"if else",0,
		
	}; 
	
	cout<<"enter the file:"<<endl;
	cin>>string1;
	
	
	
	ifstream infile;
	infile.open(string1, ios::in);
	if (!infile.is_open()) 
    { 
        cout <<"no"<< endl; 
    }
	
	while(getline(infile,str))
	{
		a = 0;
		b = 0;
		c = 0;
		if(str.length() > 1)
		{

			for(int j = 0;j<str.length();j++)
			{

				if(!(str[j]>='a'&&str[j]<='z'))
				{
					if(c == 1)
					{
						
						b = j;
						s = str.substr(a,b-a);
						codeword.push_back(s);

						c = 0;
					
					}
					
				}
				else
				{
					if(c == 0)
					{
						a = j;
						c = 1;
						
					}
				}
			}
    	}
    }


	for(int k = 0;k<codeword.size();k++)
	{
		for(int q = 0;q<63;q++)
		{
			if(codeword[k]==arr[q].name)
			{
				arr[q].count += 1;
				n1 += 1;
			}
    	}
		if(codeword[k]=="switch"||codeword[k]=="default")
		{
			d += 1;
		}
		if(d ==1)
		{
			if(codeword[k]=="case")
			{
				e += 1;
			}
		}
		if(d ==3)
		{
			if(codeword[k]=="case")
			{
				f += 1;
			}
		}
		
	
	}
	
	
	for (int p = 0;p<codeword.size();p++)
	{
		if(codeword[p]=="if"&&codeword[p+1]=="else"&&codeword[p+2]!="if")
		{
			arr1[0].count += 1;
		}
	}
	cout<<"total num:"<<n1<<endl;
	
	cout<<"switch num:"<<arr[58].count<<endl;
	
	cout<<"case num:"<<e<<" "<<f<<endl;
	
	cout<<"if else:"<<arr1[0].count<<endl;


	
	
	
	infile.close();
	
	
	
	
	
	
	return 0;
	
	
	
	
	
}






 
