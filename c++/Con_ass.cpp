#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

class Family
{
public:
        Family() = default;
        void Add(const std::string &last, const std::string &first, const std::string &bir)
        {
                auto child = std::make_pair(first, bir);
                data[last].push_back(child);
        }
        
        void Print()
        {
                for(auto pair : data)
                {
                        std::cout << pair.first << ":\n";
                        for(auto child : pair.second)
                                std::cout << child.first << " " << child.second << std::endl;
                        std::cout << std::endl;
                }   
        }

private:
        std::map<std::string, std::vector<std::pair<std::string, std::string>>> data;
};

void Word_count()
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while(std::cin >> word)
        word_count[word]++;
        //{auto re = word_count.insert({word, 1});
        //if(!re.second)
        //    re.first->second++;}
    for(auto i : word_count)
        std::cout << i.first << " occurs " << i.second << std::endl;
}

void Word_count_pro()
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while(std::cin >> word)
    {
        for(auto &t : word)
            t = tolower(t);
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());

        word_count[word]++;
    }
        

    for(auto i : word_count)
        std::cout << i.first << " occurs " << i.second << std::endl;
}

void func()
{
        std::map<std::string, std::vector<std::string>> family;

        for(std::string ln; std::cout << "last name: ", std::cin >> ln; )
                for(std::string cn; std::cout << "kid name: ", std::cin >> cn;)
                        family[ln].push_back(cn);
}

void func1()
{
        std::vector<std::string> vec = {"aa", "bb", "cc"};
        for(std::string word; std::cout << "enter plz: ", std::cin >> word; )
        {
                auto is_excluded = std::binary_search(vec.cbegin(), vec.cend(), word);
                auto reply = is_excluded ? "excluded" : "not excluded";
                std::cout << reply << std::endl;           
                
        }
}

void func2()
{
        std::vector<std::pair<std::string, int>> vec;
        std::string str;
        int i;
        while(std::cin >> str >> i)
                vec.push_back(std::pair<std::string, int>(str, i));
                //vec.push_back({str, i});
                //vec.push_back(std::make_pair(str, i));
        for(auto &p : vec)
                std::cout << p.first << ":" << p.second << std::endl;
}

void func3()
{
        std::multimap<std::string, std::string> kids;
        for(std::string lname, cname; std::cin >> cname >> lname; kids.emplace(lname, cname));
        for(auto const &fa : kids)
                std::cout << fa.second << " " << fa.first << std::endl;
}

std::map<std::string, std::string> Build_map(std::ifstream &map_file)
{
        std::map<std::string, std::string> trans_map;
        std::string key;
        std::string value;
        while (map_file >> key && getline(map_file, value))
        {
                if(value.size() > 1)
                        trans_map[key] = value.substr(1);
                else
                        throw runtime_error("no rule for " + key);
        }
        
}

std::string &transform(const std::string &s, const std::map<std::string, std::string> &m)
{

}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
        auto trans_map = Build_map(map_file);
        std::string str;
        while(getline(std::cin, str))
        {
                std::istringstream stream(str);
                std::string word;
                bool is_firstword = true;
                while (stream >> word)
                {
                        if(is_firstword)
                                is_firstword = false;
                        else
                                std::cout << " ";
                        std::cout << transform(str, trans_map)
                }
                std::cout << std::endl;
        }
}

int main()
{
   

}
