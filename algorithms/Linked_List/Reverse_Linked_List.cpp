/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // method 1, 暴力法，时间复杂度o(2*n)，空间复杂度o(n)
    // 遍历两次单链表，通过中间数组变量存储val来修改链表的值
    // 第一次遍历，利用一个中间数组变量来存储不同节点val
    // 第二次遍历，利用中间变量数组来修改链表的值
    
    // method 2, 指针法， 时间复杂度o(n), 空间复杂度o(1)
    // 反转指针的指向, 遍历单链表，利用中间节点变量存储下一个节点，再反转next指针
    ListNode* reverseList(ListNode* head) {
        // 处理特例
        if (NULL == head || NULL == head->next)return head;
        // 定义三元组，
        ListNode* left = NULL;
        ListNode* mid = head;
        ListNode* right = mid->next;
        while (NULL != right){
            // 反转指针
            mid->next = left;
            // 滑动三元组，先后顺序不要错了
            left = mid;
            mid = right;
            right = right->next;
        }
        // 滑动到最右端的三元组(倒数第二个节点，倒数第一个节点，NULL)，没有做mid->next赋值，这里补上
        mid->next = left;
        return mid;
    }
};
