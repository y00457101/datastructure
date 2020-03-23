/*
 * 求二叉树的最大深度（递归,深度优先DFS,广度优先BSF等3种方法）
 */
#include <stdio.h>
#include <stdlib.h>
/* Definition for a binary tree node */
 typedef struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 } Tree;

#define Max(a, b) (a > b ? a : b)

int maxDepth(Tree * root)
{
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + Max(left,right);
}

/* 深度优先搜索 DFS 非递归 用栈实现 后进先出*/
void DFS(Tree *pRoot)  
{
    if (pRoot==NULL)  return; 

    Stack S;
    S.add(pRoot);
    while(!S.empty()) {
        Tree node = S.peek();
        cout<<node.val<<"->"; 

        S.pop(node);         // 弹栈

        if (node.right != NULL) {
            S.push(node.right);   // 入栈 右节点先入栈 搜索顺序为 树的中序遍历
        }
        if (node.left != NULL) {
            S.push(node.left);    // 入栈
        }
    }
}

/*        A        */
/*      /   \      */
/*     B     C     */
/*    / \   / \    */
/*   D   E  F  G   */

/* 广度优先搜索 BFS 用queue队列实现 先进先出*/ 
void BFS(Tree *pRoot)  
{  
    if (pRoot==NULL)  return;  

    queue<Tree*> Q;  
    Q.push(pRoot);  

    while(!Q.empty())  {  
        Tree *node = Q.front();  //指向新的队首
        cout<<node->val<<"->";  
        if (node->left != NULL) {  
            Q.push(node->left);  //入队
        }  
  
        if (node->right != NULL) {  
            Q.push(node->right); //入队
        }  
        Q.pop();  //出队
    }   
}  