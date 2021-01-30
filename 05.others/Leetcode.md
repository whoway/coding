# C++11版



## 一、快慢指针

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





## 二、100题

### [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

- 哈希

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        int len=nums.size();
        int temp[len];
        for(int i=0 ; i<len ; ++i)
        {
        	temp[i]=nums[i];
		}
		sort(temp,temp+len);
		
		int i=0,j=len-1;
		int num_min,num_max;
		while(i!=j)
		{
			if(target==temp[i]+temp[j])
			{
				num_min=temp[i];
				num_max=temp[j];
				break;
			}
			else if(temp[i]+temp[j]>target)
			{
				--j;
			}
			else
			{
				++i;
			}
		}
    	
    	int a,b;
        int flag=0;
    	for(int i=0 ; i<len ; ++i)
        {
        	if((nums[i]==num_min)&&(flag==0))
        	{
        		a=i;
                flag=1;
			}
			else if(nums[i]==num_max)
			{
				b=i;
			}
        	
		}
		
		vector<int> rt;
		rt.push_back(a);
		rt.push_back(b);
		return rt;
    }
};
```





### [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

- 『逆序』是大数加法的点睛之笔

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //头结点
        ListNode *rt=new ListNode(0);
        

        ListNode * pre=rt;//表示当前节点
        int tag=1;//头结点
        int carry=0;//进位

        while(NULL!=l1&&NULL!=l2)
        {
            if(tag)
            {
                rt->val=((l1->val+l2->val+carry)%10);
                carry=(l1->val+l2->val+carry)/10;
                tag=0;
                l1=l1->next;
                l2=l2->next;
            }
            else
            {
                pre->next=new ListNode(((l1->val+l2->val+carry)%10));
                carry=(l1->val+l2->val+carry)/10;
                pre=pre->next;

                l1=l1->next;
                l2=l2->next;
            }
        }

        if(NULL==l1&&NULL!=l2)
        {
            while(NULL!=l2)
            {
                pre->next=new ListNode((l2->val+carry)%10);
                carry=(l2->val+carry)/10;
                l2=l2->next;
                pre=pre->next;
            }
        }
        

        if(NULL!=l1&&NULL==l2)
        {
            while(NULL!=l1)
            {
                pre->next=new ListNode((l1->val+carry)%10);
                carry=(l1->val+carry)/10;
                l1=l1->next;
                pre=pre->next;
            }
        }

        if(0!=carry)
        {
            pre->next=new ListNode(carry);
        }

        return rt;

    }
};
```













