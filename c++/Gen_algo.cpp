#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>

void Count()
{
        int num;
        std::vector<int> vec;
        while(std::cin >> num)
                vec.push_back(num);
        
        int ret = count(vec.begin(), vec.end(), 2);

        std::string word;
        std::vector<std::string> vec1;
        while(getline(std::cin, word))
                vec1.push_back(word);
        int ret1 = count(vec1.begin(), vec1.end(), "a");
} 

void Accumulate()
{
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << "sum = " << accumulate(vec.begin(), vec.end(), 0) << std::endl;
}

void Fill_n()
{
        std::vector<int> vec {1, 2, 3, 4, 5};
        fill_n(vec.begin(), vec.size(), 0);
        for(auto i : vec)
                std::cout << i << " ";
        std::cout << std::endl;
}

void elimDups(std::vector<std::string> &vec)
{
        //std::vector<int> vec {1, 2, 4, 5, 4, 3, 3};
        sort(vec.begin(), vec.end());
        auto i = unique(vec.begin(), vec.end());
        vec.erase(i, vec.end());
        //for(auto i : vec)
        //        std::cout << i << " ";
        //std::cout << std::endl;
}

bool is_shorter(std::string const &lhs, std::string const &rhs)
{
        return  lhs.size() < rhs.size();
}

void pro_elimDups()
{
        std::vector<std::string> vec { "1234", "1234", "1234", "Hi", "alan", "wang"};
        elimDups(vec);
        stable_sort(vec.begin(), vec.end(), is_shorter);
        for(auto &i : vec)
                std::cout << i << " ";
        std::cout << std::endl;
}

bool predicate(const std::string &word)
{
        return word.size() >= 5;
}

void Partition()
{
        std::vector<std::string> vec { "12345", "1234", "1234", "Haaaai", "alan", "wang"};
        auto pivot = partition(vec.begin(), vec.end(), predicate);
        for(auto &i : vec)
                std::cout << i << " ";
        std::cout << std::endl;

        for (auto it = vec.cbegin(); it != pivot; ++it)
                std::cout << *it << " ";
        std::cout << std::endl;
}

void Lambda()
{
        int a = 1, b = 2;
        auto f = [](int i, int j) ->int
        {
                return i+j;
        };

        int sum = f(a, b);
        std::cout << "sum = " << sum << std::endl;
}

int main()
{
        Accumulate();
        Fill_n();
        pro_elimDups();
        Partition();
        Lambda();
        return 0;
}