//Solve the saddle point problem

#include <iostream>

using namespace std;

struct Node{
    int x;
    int y;
    int num;
    struct Node* next;
};

int main()
{
    int m, n;
    cin >> m >> n;
    int vec[m][n];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> vec[i][j];
        }
    }
    
    struct Node* list1 = new struct Node;
    struct Node* last1 = new struct Node;
    list1->next = nullptr;
    for(int i = 0; i < m; i++){
        int min = vec[i][0];
        
        for(int j = 0; j < n; j++)
            if(min > vec[i][j])
                min = vec[i][j];
        
        for(int j = 0; j < n; j++){
            if(min == vec[i][j]){
                struct Node* p = new struct Node;
                p->x = i+1;
                p->y = j+1;
                p->num = min;
                p->next = nullptr;
                if(list1->next == nullptr)
                    list1->next = p;
                else
                    last1->next = p;
                last1 = p;
            }
        }
    }
    
    struct Node* list2 = new struct Node;
    struct Node* last2 = new struct Node;
    list2->next = nullptr;
    for(int i = 0; i < n; i++){
        int max = 0, x, y;
        
        for(int j = 0; j < m; j++)
            if(max < vec[j][i])
                max = vec[j][i];
        
        for(int j = 0; j < m; j++){
            if(max == vec[j][i]){
                struct Node* p = new struct Node;
                p->x = j+1;
                p->y = i+1;
                p->num = max;
                p->next = nullptr;
                if(list2->next == nullptr)
                    list2->next = p;
                else
                    last2->next = p;
                last2 = p;
            }
        }
    }
    
    int ice = 0;
    for( struct Node* p = list1->next; p != nullptr; p = p->next){
        for(struct Node* q = list2->next; q; q = q->next){
            if(p->x == q->x && p->y == q->y && q->num == p->num){
                ice = 1;
                cout << "(" << p->x << "," << p->y << "," << p->num << ")";
            }
        }
    }
    if(!ice)
        cout << "NONE";
    return 0;
}