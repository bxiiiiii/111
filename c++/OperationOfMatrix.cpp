//The operation of a three-tuple table matrix

#include <iostream>

using namespace std;

int main()
{
    int m, n, num;
    int x, y, n1;
    char a;
    
    cin >> m >> n >> num;
    int arr1[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            arr1[i][j] = 0;
    
    for(int i = 0; i < num; i++){
        cin >> a;
        cin >> x;
        cin >> a;
        cin >> y;
        cin >> a;
        cin >> n1;
        cin >> a;
        arr1[x-1][y-1] = n1;
    }
    
    cin >> m >> n >> num;
    int arr2[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            arr2[i][j] = 0;
    for(int i = 0; i < num; i++){
        cin >> a;
        cin >> x ;
        cin >> a;
        cin >> y ;
        cin >> a;
        cin >> n1;
        cin >> a;;
        arr2[x-1][y-1] = n1;
    }
    
    int arr3[m][n];
    int sum = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr3[i][j] = arr1[i][j]+arr2[i][j];
            if(arr3[i][j]){
                sum++;
            }
        }
    }
    cout << m << " " << n << " " <<sum << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr3[i][j])
                cout << "(" << i+1 << "," << j+1 << "," << arr3[i][j] << ")";
        }
    }
    
    sum = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr3[i][j] = arr1[i][j]-arr2[i][j];
            if(arr3[i][j]){
                sum++;
            }
        }
    }
    
    cout << endl;
    cout << m << " " << n << " " <<sum<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr3[i][j])
                cout << "(" << i+1 << "," << j+1 << "," << arr3[i][j] << ")";
        }
    }
    cout << endl;
    return 0;
}