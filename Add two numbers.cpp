You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7


--------------------------------------------------------------------------------------------------------------------------------------------------------------------


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        
        ListNode* ptr = head, *prev = NULL, *ptr1 = NULL;
        
        while(ptr){
            ptr1 = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = ptr1;
        }
        return prev;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL and l2 == NULL)
            return NULL;
        
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        int carry = 0;
        ListNode* p1 = reverse(l1);
        ListNode* p2 = reverse(l2);
        
        ListNode* head = NULL,*ptr = head;
        
        while(p1 != NULL and p2 != NULL){
            int data = p1->val + p2->val + carry;
            carry =data > 9 ? data / 10 : 0;
            data =data > 9 ? data % 10 : data;
            ListNode* newNode = new ListNode(data);
            if(head == NULL){
                head = newNode;
                ptr = head;
            }
            else{ 
                head->next = newNode;
                head = newNode;
              //  cout<<head->val<<" ";
            }
         //   cout<<p1->val<<" ";
         //   head = head->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        
        while(p1 != NULL){
            // cout<<"hu";
            // cout<<p1->val<<" ";
            int data = p1->val + carry;
            carry =data > 9 ? data / 10 : 0;
            data =data > 9 ? data % 10 : data;
            
            ListNode* newNode = new ListNode(data);
            
            head->next = newNode;
            head = newNode;
            p1 = p1->next;
        }
        while(p2 != NULL){
            
            int data = p2->val + carry;
            carry =data > 9 ? data / 10 : 0;
            data =data > 9 ? data % 10 : data;
            ListNode* newNode = new ListNode(data);
            head->next = newNode;
            head = newNode;
            p2 = p2->next;
        }
        
        if(carry){
            head->next = new ListNode(carry);
        }
        
        return reverse(ptr);
        
    }
};
