#include <iostream>
#include <string>
#include <cctype>

int main()
{
		std::string str1, str2， str3, str4;

		getline(std::cin, str1);
		getline(std::cin, str2);

		std::cout << "str1:" << str1 << std::endl;
		std::cout << "str2:" << str2 << std::endl;
		
		std::cout << str1.empty() << std::endl;
		std::cout << str1.size() << " " << str2.size() << std::endl;

		str3 = str1+str2;
		std::cout << "str3:" << str3 << std::endl;

		str4 = str3 + " hhh";
		std::cout << "str4:" << str4 << std::endl;

		int sum = 0;
		for (auto &c : str4){
				if (islower(c))
						sum++;
				c = toupper(c);
		}
		std::cout << "sum:" << sum<< std::endl;
		std::cout << str4 << std::endl;
		
		return 0;
}
