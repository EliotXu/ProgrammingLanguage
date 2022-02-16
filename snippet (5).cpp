/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> results;
        
        while(head) {
            results.push_back(head->val);
            head = head->next;
        }
        
        std::reverse(results.begin(), results.end());
        
        return results;
    }
};