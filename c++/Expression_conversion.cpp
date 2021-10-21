//The middle suffix expression to suffix expression problem

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T pop(vector<T> &vec)
{
    if(vec.empty())
        return 0;
    T tem = vec.back();
    vec.pop_back();
    return tem;
}

int main()
{
    string str;
    vector<char> vec;

    cin >> str;
    for(auto i : str){
        if(i == '#')
            break;
        if(i >= 'a' && i <= 'z')
            cout << i;
        else if(i == '+' || i == '-'){
            if(!vec.empty())
            while(vec.back() == '+' || vec.back() == '-' || vec.back() == '*' || vec.back() == '/')
                cout << pop(vec);
            vec.push_back(i);
        }else if(i == '*' || i == '/'){
            while(vec.back() == '*' || vec.back() == '/')
                cout << pop(vec);
            vec.push_back(i);
        }else if(i == '('){
            vec.push_back(i);
        }else if(i == ')'){
            while(vec.back() != '(')
                cout << pop(vec);
            pop(vec);
        }
    }
    for(auto i : vec)
        cout << i;
    return 0;
}