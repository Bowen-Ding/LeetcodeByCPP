#include <bits//stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*
题目描述:
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。

示例 1：
输入：head = [1,2,null,3]
输出：[1,3,2]
解释：

输入的多级列表如下图所示：

  1---2---NULL
  |
  3---NULL
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    // 栈方法： 栈存放有孩子节点的next节点
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node* node = head;
        while ( node != nullptr) {
            if ( node -> child != nullptr) {
                if ( node -> next != nullptr ){
                    s.push(node -> next);
                }
                Node* child = node -> child;
                node -> next = child;
                child -> prev = node;

                node -> child = nullptr;
            }

            if (node -> next == nullptr && !s.empty()) {
                Node* tmp = s.top();
                s.pop();
                node -> next = tmp;
                tmp -> prev = node;
            }
            node = node -> next;
        } 
        return head;
        
    }

    // 递归方法： 深度优先搜索（dfs）
    Node* flatten(Node* head) {
        if ( head == nullptr) return nullptr;
        Node* node = head;
        while ( node != nullptr) {
            if ( node -> child != nullptr) {
                Node* nextNode = node -> next;
                Node* child = flatten(node -> child);

                node -> next = child;
                child -> prev = node;
                node -> child = nullptr;

                if ( nextNode != nullptr) {
                    while ( node -> next != nullptr) {
                        node = node -> next;
                    }
                    
                    // 和之前的next链接
                    node -> next = nextNode;
                    nextNode -> prev = node;
                }
                
            }
            node = node -> next;
        }
        return head;
    }

};