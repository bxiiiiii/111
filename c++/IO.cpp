#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

class PersonInfo
{
    string name;
    std::vector<std::string> numbers;
}

std::istream& func(std::istream &is)
{
    std::string buf;
    while(is >> buf)
        std::cout << buf << std::endl;
    is.clear();

    return is;
}

void func1(const std::string &file_name， std::vector<std::string> &vec)
{
    ifstream fd(file_name);
    if(fd)
    {
        std::string buf;
        while(getline(fd, buf))
            vec.push_back(buf);
    }
}

void func2(const std::string &file_name， std::vector<std::string> &vec)
{
    ifstream fd(file_name);
    if(fd)
    {
        std::string buf;
        while(fd >> buf)
            vec.push_back(buf);
    }
}

void func3(const std::string &file_name， std::vector<std::string> &vec)
{
    ifstream fd(file_name);
    if(fd)
    {
        std::string buf;
        while (getline(fd, buf))
            vec.push_back(buf);
    }
    else
        return ;

    for(auto &s : vec)
    {
        istringstream iss(s);
        std::string word;
        while(iss >> word)
            std::std::cout << word << std::endl;
    }
}

void func4()
{
    std::string line, word;
    std::vector people;
    istringstream record;
    while(getline(std::cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word))
            info.numbers.push_back(word);
        people.push_back(info);
    }

    for(auto &p : people)
    {
        std::std::cout << p.name << " ";
        for(auto &s : p.numbers)
            std::cout << s << " ";
        std::std::cout << std::endl;
    }
}

int main()
{
    std::istringstream iss("hello");
    func(iss);

    return 0;
}