#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Token.h"
#include "analyzer.h"
using namespace std;

int main()
{
	string program = "";
	string buffer;
	ifstream in;
	in.open("test.txt");
	if (!in.is_open())
	{
		cout << "打开程序文件错误";
		return 1;
	}
	while (getline(in, buffer))
	{
		program += buffer;
		program += "\n";
	}
	Analyzer analyzer(program);
	vector<Token> v = analyzer.getTokenlist();
	for (int i = 0; i < v.size(); i++) {
		v[i].printToken();
	}
}
