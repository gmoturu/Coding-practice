/*
	https://leetcode.com/problems/delete-node-in-a-linked-list/
*/
class Solution{
public:
    void deleteNode(ListNode* node){
        if(node==NULL || node->next==NULL)
            return;
        for(;node->next && node->next->next;node->val=node->next->val,node=node->next);
        node->val=node->next->val;
        delete node->next;
        node->next=NULL;
    }
};
