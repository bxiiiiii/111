/*Binary tree creation and recursive traversal*/

#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
	char elem;
	struct TreeNode* ls;
	struct TreeNode* rs;
}tnode;

tnode* CreateTree()
{
	char elem;
	tnode* newnode;
	scanf("%c", &elem);
	
	if(elem == '#'){
		newnode = NULL;
	}else{
		newnode = (tnode* )malloc(sizeof(tnode));
		newnode->elem = elem;
		newnode->ls = CreateTree();
		newnode->rs = CreateTree();
	}
	
	return newnode;
}

void PrePrint(tnode* node)
{
	if(node){
		printf("%c", node->elem);
		PrePrint(node->ls);
		PrePrint(node->rs);
	}
}

void InPrint(tnode* node)
{
	if(node){
		InPrint(node->ls);
		printf("%c", node->elem);
		InPrint(node->rs);
	}
}

void PostPrint(tnode* node)
{
	if(node){
		PostPrint(node->ls);
		PostPrint(node->rs);
		printf("%c", node->elem);
	}
}


int main()
{
	tnode *head;
	head = CreateTree();
	PrePrint(head);
	printf("\n");
	InPrint(head);
	printf("\n");
	PostPrint(head);
	return 0;
}