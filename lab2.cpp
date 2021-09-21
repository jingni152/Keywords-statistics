#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct count
{
	char* name;
	int count;
};


int main()
{
	int n = 0,n1=0,n2=0;
	string string1;
	char str1[20],str2[20],data[10000];
	
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
	

	
	cout<<"enter the file:"<<endl;
	cin>>string1;
	
	
	
	ifstream infile;
	infile.open(string1, ios::in);
	if (!infile.is_open()) 
    { 
        cout <<"no"<< endl; 
    }
	
	infile >> data;
	
	cout<<data<<endl;
	
	
	
	infile.close();
	
	
	
	
	
	
	return 0;
	
	
	
	
	
}






 
