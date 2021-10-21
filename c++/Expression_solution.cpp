//Arithmetic expression solution

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
    int re, tem, temp;
    string str;
    vector<int> vec;
    vector<char> ch;

    cin >> str;
    for(auto i = str.begin(); i != str.end(); i++){

         if(*i == '+' || *i == '-')
            ch.push_back(*i);
        else if(*i == '*'){
            tem = *(i+1) - '0';
            while(*(i+2) >= '0' && *(i+2) <= '9'){
                tem = tem*10 + *(i+2) - '0';
                i++;
            }
            temp = tem * pop(vec);
            vec.push_back(temp);
            i++;
        }else if(*i == '/'){
            tem = *(i+1) - '0';
            while(*(i+2) >= '0' && *(i+2) <= '9'){
                tem = tem*10 + *(i+2) - '0';
                i++;
            }
            temp = pop(vec) / tem;
            vec.push_back(temp);
            i++;
        }else if(*i >= '0' && *i <= '9'){
            tem = *i - '0';
            while(*(i+1) >= '0' && *(i+1) <= '9'){
                tem = tem*10 + *(i+1) - '0';
                i++;
            }
            vec.push_back(tem);
        }
        
        if(*i == '#')
            break;
    }

    for(auto j = ch.rbegin(); j != ch.rend(); j++){
        tem = pop(vec);
        temp = pop(vec);
        if(*j == '+')
            re = tem + temp;
        else 
            re = temp - tem;
        vec.push_back(re);
    }
    cout << re;
}