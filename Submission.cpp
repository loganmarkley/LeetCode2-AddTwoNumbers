// Logan Markley
// 7-5-2023

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   //will use l1 and l2 as the LL iterators
        ListNode* tmp = new ListNode(); //will return tmp b/c it is the head of the LL
        ListNode* tmpIterator = tmp;
        bool wasThereOverflow = false;

        do
        {
            if(l1 != NULL && l2 != NULL) //if both pointers point to a node, add them
            {
                tmpIterator -> val = (l1 -> val) + (l2 -> val);
                if(wasThereOverflow == true)    //need to add a 1 to the addition operation b/c last digit overflowed
                {
                    tmpIterator -> val += 1;
                }
                
                if(tmpIterator -> val / 10 != 0)    //if this op is not 0, then val is greater than 9 which means overflow
                {
                    tmpIterator -> val %= 10;   //get rid of the tens digit and change wasThereOverflow
                    wasThereOverflow = true;
                }
                else
                {
                    wasThereOverflow = false;
                }

                l1 = l1 -> next;                        //l1 and l2 advance one node
                l2 = l2 -> next;
            }
            else if(l1 == NULL) //if l1 is NULL
            {
                tmpIterator -> val = l2 -> val;
                if(wasThereOverflow == true)
                {
                    tmpIterator -> val += 1;
                }

                if(tmpIterator -> val / 10 != 0)    //if this op is not 0, then val is greater than 9 which means overflow
                {
                    tmpIterator -> val %= 10;   //get rid of the tens digit and change wasThereOverflow
                    wasThereOverflow = true;
                }
                else
                {
                    wasThereOverflow = false;
                }

                l2 = l2 -> next;                        //only l2 advances one node b/c l1 is already at its end
            }
            else    //if l2 is NULL
            {
                tmpIterator -> val = l1 -> val;
                if(wasThereOverflow == true)
                {
                    tmpIterator -> val += 1;
                }

                if(tmpIterator -> val / 10 != 0)    //if this op is not 0, then val is greater than 9 which means overflow
                {
                    tmpIterator -> val %= 10;   //get rid of the tens digit and change wasThereOverflow
                    wasThereOverflow = true;
                }
                else
                {
                    wasThereOverflow = false;
                }

                l1 = l1 -> next;                        //only l1 advances one node b/c l2 is already at its end
            }

            if(l1 != NULL || l2 != NULL || wasThereOverflow)  //if there are more elements to add, make a new node in tmp
            {
                tmpIterator -> next = new ListNode();   //creates a new Node in tmp
                tmpIterator = tmpIterator -> next;      //iterator now points to that node

                if(l1 == NULL && l2 == NULL && wasThereOverflow) //out of elements, but there was overflow
                    tmpIterator -> val = 1;
            }

        } while(l1 != NULL || l2 != NULL);  //loop stops after adding the last blocks

        tmpIterator = NULL;
        return tmp;
    }
};