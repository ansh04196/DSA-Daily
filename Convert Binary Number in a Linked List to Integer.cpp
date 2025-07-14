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
    int binaryStrintoDecimal(string str){
        int n = str.size(), res = 0;
        for (int i = 0; i < n; i++){
            res += (1 << (n - i - 1)) * (str[i] == '1' ? 1 : 0);
        }
        return res;
    }
    int getDecimalValue(ListNode* head) {
        string str;
        ListNode* ptr = head;
        while(ptr) str += ptr->val ? "1" : "0", ptr = ptr->next;
        return binaryStrintoDecimal(str);
    }
};
