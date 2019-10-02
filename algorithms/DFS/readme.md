# 理论
## 深度优先遍历
从根节点出发，沿着左子树方向进行纵向遍历，直到找到叶子节点为止。然后回溯到前一个节点，进行右子树节点的遍历，直到遍历完所有可达节点为止。
## 广度优先遍历
从根节点出发，在横向遍历二叉树层段节点的基础上纵向遍历二叉树的层次。

# 特点及场景

# demo
深度优先遍历和广度优先遍历的demo
1. 编译demo文件
g++ tree.cc -o tree -std=c++11
2. 执行
./tree
3. 结果  
深度优先遍历二叉树结果:  
DFS: A  
DFS: B  
DFS: D  
DFS: E  
DFS: C  
DFS: F  
DFS: G  
广度优先遍历二叉树结果:  
BFS: A  
BFS: B  
BFS: C  
BFS: D  
BFS: E  
BFS: F  
BFS: G  
前序优先遍历二叉树结果（递归）:  
pre_order_recursive: A  
pre_order_recursive: B  
pre_order_recursive: D  
pre_order_recursive: E  
pre_order_recursive: C  
pre_order_recursive: F  
pre_order_recursive: G  
中序优先遍历二叉树结果（递归）:  
in_order_recursive: D  
in_order_recursive: B  
in_order_recursive: E  
in_order_recursive: A  
in_order_recursive: F  
in_order_recursive: C  
in_order_recursive: G  
后序优先遍历二叉树结果（递归）:  
post_order_recursive: D  
post_order_recursive: E  
post_order_recursive: B  
post_order_recursive: F  
post_order_recursive: G  
post_order_recursive: C  
post_order_recursive: A  
所以，前序遍历其实就是广度优先遍历
# Leetcode
## 题
