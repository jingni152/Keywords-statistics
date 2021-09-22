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
	vector<string> ifelse1;
	vector<string> shortcode;
	int n = 0,n1=0;
	int a,b,c;
	int d=0,e=0,f=0;
	int x,y,z; 
	int nif = 0;
	int num1 = 0;
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
		x = 0;
		y = 0;
		z = 0;
		if(str.length() > 1)
		{
			
			for(int j = 0;j<str.length();j++)
			{
				/*quotation mark*/
				if (str[j]=='\"'||str[j]=='\'')
				{
					x += 1;
				}
				/*annotation*/
				if ((str[j]=='\/'&&str[j+1]=='\*')||(str[j]=='\*'&&str[j+1]=='\/'))
				{
					y += 1;
				}
				if(str[j]=='\/'&&str[j+1]=='\/')
				{
					z = 1; 
				} 
				
				if ( x%2 != 1&&y%2!=1&&z !=1)
				{
				
					/*Extract words*/
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
			 
					
					if(str[j]=='i'&&str[j+1]=='f')
					{
						
						ifelse1.push_back("if");
						shortcode.push_back("if");
						nif += 1;
						num1 +=2;
						cout<<"if"<<endl;
					}
					
					if( (nif > 0)|| (num1 > 0))
					{
						if(str[j]=='{')
						{
							shortcode.push_back("{");
							num1 -=1;
							cout<<"{"<<endl;
						}
						if(str[j]=='}')
						{
							shortcode.push_back("}");
							num1 -=1;
							cout<<"}"<<endl;
						}
						if(str[j]=='e'&&str[j+1]=='l'&&str[j+2]=='s'&&str[j+3]=='e')
						{
							ifelse1.push_back("else");
							shortcode.push_back("else");
							nif -= 1;
							num1 +=2;
							if(str[j+5]=='i'&&str[j+6]=='f')
							{
								num1 -=2;
							}
							cout<<"else"<<endl;
						}
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
	
	cout<<"total num:"<<n1<<endl;
	
	cout<<"switch num:"<<arr[58].count<<endl;
	
	cout<<"case num:"<<e<<" "<<f<<endl;
	
	for (int p = 0;p<ifelse1.size()-2;p++)
	{
		if(ifelse1[p]=="if"&&ifelse1[p+1]=="else"&&ifelse1[p+2]!="if")
		{
			
			arr1[0].count += 1;
		}
	}
	

	
	cout<<"if else:"<<arr1[0].count<<endl;
	
	


	
	
	
	infile.close();
	
	
	
	
	
	
	return 0;
	
	
	
	
	
}






 
