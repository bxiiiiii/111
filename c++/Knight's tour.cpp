#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

void f(vector<vector<int>> &vec, vector<vector<int>> &tag, int i, int j, int &num)
{
       if(num == 65)
            return ;
        if((i-2) >= 0 && (j+1) <= 7 && vec[i-2][j+1] == 0 && tag[i][j] < 1){
            tag[i][j] = 1;
            vec[i-2][j+1] = num++;
            f(vec, tag, i-2, j+1, num);
        }else if((i-1) >= 0 && (j+2) <= 7 && vec[i-1][j+2] == 0 && tag[i][j] < 2){
            tag[i][j] = 2;
            vec[i-1][j+2] = num++;
            f(vec, tag, i-1, j+2, num);
        }else if((i+1) <= 7 && (j+2) <= 7 && vec[i+1][j+2] == 0 && tag[i][j] < 3){
            tag[i][j] = 3;
            vec[i+1][j+2] = num++;
            f(vec, tag, i+1, j+2, num);
        }else if((i+2) <= 7 && (j+1) <= 7 && vec[i+2][j+1] == 0 && tag[i][j] < 4){
            tag[i][j] = 4;
            vec[i+2][j+1] = num++;
            f(vec, tag, i+2, j+1, num);
        }else if((i+2) <= 7 && (j-1) >= 0 && vec[i+2][j-1] == 0 && tag[i][j] < 5){
            tag[i][j] = 5;
            vec[i+2][j-1] = num++;
            f(vec, tag, i+2, j-1, num);
        }else if((i+1) <= 7 && (j-2) >= 0 && vec[i+1][j-2] == 0 && tag[i][j] < 6){
            tag[i][j] = 6;
            vec[i+1][j-2] = num++;
            f(vec, tag, i+1, j-2, num);
        }else if((i-1) >= 0 && (j-2) >= 0 && vec[i-1][j-2] == 0 && tag[i][j] < 7){
            tag[i][j] = 7;
            vec[i-1][j-2] = num++;
            f(vec, tag, i-1, j-2, num);
        }else if((i-2) >= 0 && (j-1) >= 0 && vec[i-2][j-1] == 0 && tag[i][j] < 8){
            tag[i][j] = 8;
            vec[i-2][j-1] = num++;   
            f(vec, tag, i-2, j-1, num);
        }else {
            vec[i][j] = 0;
            num--;
            tag[i][j] = 0;
            return ;
        }
        f(vec, tag, i, j, num);
        
}

int main()
{
    int m, n, i, j, num = 1, ice = 0, tem = 0, NUM= 0;
    vector<vector<int>> vec(8, vector<int>(8, 0));
    vector<vector<int>> tag(8, vector<int>(8, 0));
    
    cin >> m >> n;
    i = m-1;
    j = n-1;
    vec[i][j] = num++;
    f(vec, tag, i, j, num);

    for(auto a : vec){
        for(auto b : a)
            printf("%2d ", b);
        cout << endl;
    }

    return 0;
}