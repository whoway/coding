# C++11版



## 快慢指针

> fast、slow
>
> fast 2步/次
>
> slow 1步/次



#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

```cpp
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
    bool hasCycle(ListNode *head) {
        
        if( nullptr==head || nullptr==(head->next) ) return false;

        ListNode * fast=head;
        ListNode * slow=head;

        while( 1 )
        {
            if( nullptr==fast || nullptr==fast->next ) return false;
            fast=fast->next->next;
            slow=slow->next;
            if( fast==slow ) break;
        } 

        return true;
    }
};
```

