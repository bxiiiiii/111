#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>

bool f(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int i)
{
        while(begin != end)
        {
                if(*begin == i)
                        return true;
                else
                        begin++;
        }
        return false;
}

std::vector<int>::const_iterator f1(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int i)
{
        while(begin != end)
        {
                if(*begin == i)
                        return begin;
                else
                        begin++;
        }
        return end;
}

void f2()
{
        std::deque<std::string> input;
        for(std::string str; std::cin >> str; input.push_back(str));
        for(auto iter = input.cbegin(); iter != input.cend(); iter++)
                std::cout << *iter << std::endl;
}

void f3()
{
        std::list<int> li{1, 2, 3, 4, 5};
        std::deque<int> de1, de2;
        /*
        for(auto iter : li)
                (i &0x1 ? de1 : de2).push_back(iter);
        */
        for(auto iter : li)
        {
                if(iter % 2)
                        de1.push_back(iter);
                else
                        de2.push_back(iter);
        }
}

void f4()
{
        int some_val;
        std::vector<int> vec;
        std::vector<int>::iterator iter = vec.begin(), mid = vec.begin() + vec.size()/2;
        while (iter != mid)
        {
                if(*iter == some_val)
                {
                        iter = vec.insert(iter, 2*some_val);
                        ++iter;
                }
                ++iter;
        }
}

void f5()
{
        std::vector<int> vec;
        std::cout << vec.at(0);
        std::cout << vec[0];
        std::cout << vec.front();
        std::cout << *vec.begin();
}

void f6()
{
        int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
        std::vector<int> vec(ia, std::end(ia));
        std::list<int> li(vec.begin(), vec.end());

        for(auto iter = li.begin(); iter != li.end(); )
                if(*iter & 0x1)
                        iter = li.erase(iter);
                else
                        iter++;

        for(auto iter = vec.begin(); iter != vec.end(); )
                if(!(*iter & 0x1))
                        iter = vec.erase(iter);
                else
                        ++iter;
}

void f7()
{
        std::forward_list<int> li{1, 2, 3, 4, 5};
        /*
        auto is_odd = [] (int i) { return i & 0x1; };
        li.remove_if(is_odd);
        */
        auto prev = li.before_begin();
        auto curr = li.begin();
        while(curr != li.end())
        {
                if(*curr % 2)
                        curr = li.erase_after(prev);
                else
                        prev = curr;
                curr++;
        }
        for(auto iter : li)
                std::cout << iter << std::endl;
}

void f8(std::forward_list<std::string> &li, const std::string &str1, const std::string &str2)
{
        auto prev = li.before_begin();
        auto curr = li.begin();
        while (curr != li.end())
        {
                if(*curr == str1)
                {
                        li.insert_after(curr, str2);
                        return ;
                }
                prev = curr;
                curr++;
        }
        li.insert_after(prev, str2);
}

int main()
{
    std::list<std::deque<int>> item;

    std::vector<int> tmp;
    std::vector<int> vec;
    std::vector<int> vec1(10);
    std::vector<int> vec2(10, 1);
    std::vector<int> vec3{1, 2, 3};
    std::vector<int> vec4(tmp);
    std::vector<int> vec5(tmp.begin(), tmp.end());

    std::list<const char*> list1{"111", "222"};
    std::vector<std::string> vv;
    vv.assign(list1.cbegin(), list1.cend());

    std::vector<int> vecc{1, 2, 3};
    std::vector<int> veccc{1, 2, 3};
    std::vector<int> vecccc{1, 2};
    std::cout << (vecc == veccc ? "true" : "false") << std::endl;
    std::cout << (vecc == vecccc ? "true" : "false") << std::endl;
    std::list<int> listt{1, 2, 3};
    std::cout << (std::vector<int>(listt.begin(), listt.end()) == vecc ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(listt.begin(), listt.end()) == vecccc ? "true" : "false") << std::endl;

    return 0;
}