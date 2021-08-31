#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <iterator>
#include <functional>

using namespace std::placeholders;

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

        int x = 10;
        auto f1 = [x](int i) { return i+x; };
}

void biggies(std::vector<std::string> &words, std::size_t sz)
{
        elimDups(words);
        stable_sort(words.begin(), words.end(),
                        [](std::string const &lhs, std::string const &rhs)
                                { return  lhs.size() < rhs.size(); });
        auto wc = find_if(words.begin(), words.end(), [sz](const std::string &s)
                                        { return s.size() >= sz; });
        for_each(wc, words.end(), [](const std::string &s)
                        { std::cout << s << " "; });
        std::cout << std::endl;
}

void biggies1(std::vector<std::string> &words, std::size_t sz)
{
        elimDups(words);
        stable_sort(words.begin(), words.end(),
                        [](std::string const &lhs, std::string const &rhs)
                                { return  lhs.size() < rhs.size(); });
        auto pivot = partition(words.begin(), words.end(), [sz](const std::string &s)
                                                        { return s.size() >= sz; });
        for(auto item = words.begin(); item != pivot; item++)
                std::cout << *item << " ";
        std::cout << std::endl;
}

bool check_size(const std::string &s, std::size_t sz)
{
        return s.size() >= sz;
}

void biggies2(std::vector<std::string> &words, std::size_t sz)
{
        elimDups(words);
        auto item = std::stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
        for_each(words.begin(), item, [](const std::string &s){ std::cout << s << " "; });
}

void Copy()
{
        std::vector<int> vec{1, 1, 2, 3, 4, 4, 5};
        std::list<int> li;

        std::unique_copy(vec.begin(), vec.end(), back_inserter(li));
        for(auto item : li)
                std::cout << item << " ";
        std::cout << std::endl;
}

void pro_copy()
{
        std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::list<int> li1, li2, li3;

        copy(vec.begin(), vec.end(), inserter(li1, li1.begin()));
        copy(vec.begin(), vec.end(), back_inserter(li2));
        copy(vec.begin(), vec.end(), front_inserter(li3));

}
/*
void func()
{
        using std::string;

        std::ifstream ifs("./test.txt");
        std::istream_iterator<string> in(ifs), eof;
        std::vector<string> vec;
        copy(in, eof, back_inserter(vec));

        copy(vec.begin(), vec.end(), std::ostream_iterator<string>(std::cout, "\n"));
}
*/
void func1()
{
        using namespace std;

        vector<int> vec;
        istream_iterator<int> in(cin), eof;
        
        copy(in, eof, back_inserter(vec));
        sort(vec.begin(), vec.end());

        //copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        unique_copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

}

void func2()
{
        using namespace std;

        vector<int> vec {1, 2, 3, 4, 5, 6, 7};
        for(auto i = vec.crbegin(); i != vec.crend(); i++)
        //for(auto i = prev(vec.end()); true; i--)
        {
                cout << *i << " ";
                //if(i == vec.begin()) break;
        }

        cout << endl;
}

void func3()
{
        using namespace std;

        list<int> li {1, 2, 0, 3, 4, 0, 5};
        auto i = find(li.crbegin(), li.crend(), 0);

        cout << distance(i, li.crend()) << endl;
}

void func4()
{
        using namespace std;

        vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        list<int> li;
        
        copy(vec.crbegin() + 3, vec.crbegin() + 8, back_inserter(li));
        for(auto i : li)
                cout << i << " ";
        cout << endl;

}

int main()
{
        Accumulate();
        Fill_n();
        pro_elimDups();
        Partition();
        Lambda();
        Copy();
        func2();
        func3();
        func4();
        return 0;
}