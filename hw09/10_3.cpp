#include "filestreambuf.h"
#include <string>


int main() {
	{
		FILE* fp = fopen("test.txt", "w"); //stdout;
		FileStreamBuf f(fp);
		std::ostream out(&f);
		out << "testatestaaab" << std::endl;
	}
	{
		FILE* fp = fopen("test.txt", "r");
		FileStreamBuf f(fp);
		std::istream in(&f);
		std::string s;
		in >> s;
		std::cout << "output? '" << s << "'" << std::endl;
	}
	return 0;
}
