#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> vec, vector<vector<int>> tag, int num, int m, int n)
{
    int Num = num-1;
    int i, j;
    for(num = 1; num <= Num; num++)
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++)
                if(vec[i][j] == num)
                    cout << '(' << i+1 << ',' << j+1 << ',' << tag[i][j] << ')'; 
        }
    cout << '(' << m << ',' << n << ',' << '0' << ')';
    exit(0);
}

void f(vector<vector<int>> vec1, vector<vector<int>> &vec, vector<vector<int>> &tag, int i, int j, int &num, int m, int n)
{
    if((i+1) == m && n == (j+1))
        print(vec, tag, num, m, n); ;
    if((j+1) < n && vec1[i][j+1] == 0 && tag[i][j] < 1 && vec[i][j+1] == 0){
        tag[i][j] = 1;
        vec[i][j] = num++;
        f(vec1, vec, tag, i, j+1, num, m, n);
    }else if((i+1) < m && vec1[i+1][j] == 0 && tag[i][j] < 2 && vec[i+1][j] == 0){
        tag[i][j] = 2;
        vec[i][j] = num++;
        f(vec1, vec, tag, i+1, j, num, m, n);
    }else if((j-1) >= 0 && vec1[i][j-1] == 0 && tag[i][j] < 3 && vec[i][j-1] == 0){
        tag[i][j] = 3;
        vec[i][j] = num++;
        f(vec1, vec, tag, i, j-1, num, m, n);
    }else if((i-1) >= 0 && vec1[i-1][j] == 0 && tag[i][j] < 4 && vec[i-1][j] == 0){
        tag[i][j] = 4;
        vec[i][j] = num++;
        f(vec1, vec, tag, i-1, j, num, m, n);
    }else {
        vec[i][j] = 0;
        tag[i][j] = 0;
        num--;
        return ;
    }
    
    f(vec1, vec, tag, i, j, num, m, n);
}

int main()
{
    int m, n, i, j, num = 1;

    cin >> m >> n;
    vector<vector<int>> vec(m, vector<int>(n, 0));
    vector<vector<int>> vec1(m, vector<int>(n, 0));
    vector<vector<int>> tag(m, vector<int>(n, 0));
    vector<string> str;
    
    
    for(i = 0; i < m; i++){
        string tem;
        cin >> tem;
        str.push_back(tem);
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            vec1[i][j] = str[i][j] - '0';
    }

    f(vec1, vec, tag, 0, 0, num, m, n);

    return 0;
}