/*
 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


* */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverSe(ListNode * l1){
    if(!l1  || !l1->next){
        return NULL;
    }
    ListNode *pre = l1;
    ListNode *cur = l1->next;
    ListNode *next = cur->next;

    while(cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;         
    }
    l1->next = NULL;
    return pre;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1=NULL, *p2=NULL;        

    /*
    ListNode *ptmp = l1;
    while(ptmp){
        cout<<"l1:"<<ptmp->val<<endl;
        ptmp = ptmp->next;
    }
    ptmp = l2;
    while(ptmp){
        cout<<"l2:"<<ptmp->val<<endl;
        ptmp = ptmp->next;
    } 
    */

    ListNode *re = new ListNode(0);
    p1 = re;
    int sval = 0;
    while(true){
        sval = sval / 10;
        if(l1){
            sval += l1->val;    
        }
        if(l2){
            sval += l2->val;
        }            
        re->val = sval%10;

        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
        if( !l1 && !l2 ){
            sval = sval / 10;
            break;
        }
        ListNode *ptmp = new ListNode(0);
        re->next = ptmp;
        re = re->next;
    }

    while(sval != 0 ){
        int nowv = sval%10;
        sval = sval / 10;
        ListNode *ptmp = new ListNode(nowv);
        re->next = ptmp;
        re = re->next;
    }



    return p1;
}

int main(){
    ListNode *p1= NULL, *p2 = NULL;
    int ary1[] = {2,4,33};
    int ary2[] = {5,66,4,55};

    ListNode *ptmp = NULL;
    for(int i=0;i<3;i++){
        p1 = new ListNode(ary1[i]);
        p1->next = ptmp;
        ptmp = p1;
    }
    p1 = reverSe(p1);

    ptmp = NULL;
    for(int i=0;i<4;i++){
        p2 = new ListNode(ary2[i]);
        p2->next = ptmp;
        ptmp = p2;
    }
    p2 = reverSe(p2);


    ListNode *p = addTwoNumbers(p1, p2);
    while(p){
        cout <<p->val<<" ";
        p = p->next;
    }
    return 0;
}
