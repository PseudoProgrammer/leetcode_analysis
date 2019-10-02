#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <Stack>
#include <Queue>
using namespace std;
 
typedef struct Node {
    char data;
    struct Node *lchild;
    struct Node *rchild;
} *Tree;
//Tree 是一个node指针的类型定义
 
int index = 0;  //全局索引变量
//二叉树构造器,按先序遍历顺序构造二叉树
//无左子树或右子树用'#'表示
void treeNodeConstructor(Tree &root, char data[]){
    char e = data[index++];
    if(e == '#'){
        root = NULL;
    }else{
        root = (Node *)malloc(sizeof(Node));
        root->data = e;
        treeNodeConstructor(root->lchild, data);  //递归构建左子树
        treeNodeConstructor(root->rchild, data);  //递归构建右子树
    }
}
//深度优先遍历
void depthFirstSearch(Tree root){
    stack<Node *> nodeStack;  //使用C++的STL标准模板库
    nodeStack.push(root);
    Node *node;
    while(!nodeStack.empty()){
	    node = nodeStack.top();
		cout<<node->data;//遍历根结点
        nodeStack.pop();
        if(node->rchild){
            nodeStack.push(node->rchild);  //先将右子树压栈
        }
        if(node->lchild){
            nodeStack.push(node->lchild);  //再将左子树压栈
        }
    }
}
 
//广度优先遍历
void breadthFirstSearch(Tree root){
    queue<Node *> nodeQueue;  //使用C++的STL标准模板库
    nodeQueue.push(root);
    Node *node;
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        cout<<node->data;//遍历根结点
        if(node->lchild){
            nodeQueue.push(node->lchild);  //先将左子树入队
        }
        if(node->rchild){
            nodeQueue.push(node->rchild);  //再将右子树入队
        }
    }
}
 
int main() {
    //上图所示的二叉树先序遍历序列,其中用'#'表示结点无左子树或无右子树
    char data[15] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    Tree tree;
    treeNodeConstructor(tree, data);
    printf("深度优先遍历二叉树结果: ");
    depthFirstSearch(tree);
    printf("\n\n广度优先遍历二叉树结果: ");
    breadthFirstSearch(tree);
    return 0;
}



————————————————
版权声明：本文为CSDN博主「mingwanganyu」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/mingwanganyu/article/details/72033122
