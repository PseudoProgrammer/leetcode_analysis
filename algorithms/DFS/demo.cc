#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <stack>
#include <queue>
using namespace std;
typedef struct Node {
    char data;
    struct Node *lchild;
    struct Node *rchild;
} *Tree;

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

void DFS(Tree root){
    stack<Node *> node_list;
    node_list.push(root);
    // stack 运算符.
    while(!node_list.empty()){
        Node* top = node_list.top();
        cout << "DFS: " << top->data<<endl;;
        node_list.pop();
        // 指针运算符->
        if(top->rchild)node_list.push(top->rchild);
        if(top->lchild)node_list.push(top->lchild);
    }
}


void BFS(Tree root){
    //广度优先遍历, 使用队列
    queue<Tree> node_list;
    node_list.push(root);
    while(!node_list.empty()){
        Tree top = node_list.front();
        node_list.pop();
        cout << "BFS: "<< top->data<<endl;
        if(top->lchild)node_list.push(top->lchild);
        if(top->rchild)node_list.push(top->rchild);
    }
}

void pre_order_traverse(Tree root){
    //广度优先遍历，递归方式
    Tree top = root;
    // firstly, root node
    cout << "pre_order_recursive: " << top->data<<endl;
    // secondly, left child
    if(top->lchild)pre_order_traverse(top->lchild);
    // thirdly, right child
    if(top->rchild)pre_order_traverse(top->rchild);
}

void in_order_traverse(Tree root){
    //广度优先遍历，递归方式
    Tree top = root;
    // firstly, left child
    if(top->lchild)in_order_traverse(top->lchild);
    // second, root node
    cout << "in_order_recursive: " << top->data<<endl;
    // thirdly, right child
    if(top->rchild)in_order_traverse(top->rchild);
}

void post_order_traverse(Tree root){
    //广度优先遍历，递归方式
    Tree top = root;
    // firstly, left child
    if(top->lchild)post_order_traverse(top->lchild);
    // second, right child
    if(top->rchild)post_order_traverse(top->rchild);
    // thirdly, root node
    cout << "post_order_recursive: " << top->data<<endl;
}

int main() {
    //上图所示的二叉树先序遍历序列,其中用'#'表示结点无左子树或无右子树
    char data[15] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    Tree tree;
    treeNodeConstructor(tree, data);
    printf("深度优先遍历二叉树结果: \n");
    DFS(tree);
    //depthFirstSearch(tree);
    printf("广度优先遍历二叉树结果: \n");
    BFS(tree);

    printf("前序优先遍历二叉树结果（递归）:\n");
    pre_order_traverse(tree);
    printf("中序优先遍历二叉树结果（递归）:\n");
    in_order_traverse(tree);
    printf("后序优先遍历二叉树结果（递归）:\n");
    post_order_traverse(tree);
    printf("所以，前序遍历其实就是深度优先遍历\n");
    //breadthFirstSearch(tree);
    return 0;
}
