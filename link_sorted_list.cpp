//https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && l2){ return l2;}
        if(l1&&!l2){return l1;}
        if(!l1 && !l2){return NULL;}
        ListNode *p1 = l1, *p2 = l2, *pret=NULL, *tmp=NULL;
        while(true){
            if(p1->val >= p2->val){
                if(!pret){
                    pret = p2;
                    tmp = pret;                    
                }else{
                    tmp->next = p2;
                    tmp = tmp->next;                    
                }
                p2 = p2 ->next;
                tmp->next = p1;
                
            }else if(p2->val > p1->val){
                if(!pret){
                    pret = p1;
                    tmp = pret;                    
                }else{
                    tmp->next = p1;
                    tmp = tmp->next;                    
                }
                p1 = p1 ->next;
                tmp->next = p2;                
                
            }
            
            if(!p1&&p2){
                tmp->next = p2;
            }else if(p1&&!p2){
                tmp->next = p1;
            }
            
            if(p1==NULL || p2==NULL){
                return pret;
            }
        }
    }
};
