#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// link: https://leetcode.com/problems/add-two-numbers/submissions/1549608976/
// github: https://github.com/Muhammad-Fiqri
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    algorithm to sum 2 list node

    1. count the length of the 2 list node by traversing through the node until the next pointer is nullptr while counting ✅
    2. if one node is shorter then the other, insert that node with 0 until they are the same length 
    2. traverse through the longest list node while counting the node until it's the last node ✅

    3. sum the last node and keep the carry and then reduce the node to the node before the last ✅
    4. store the sum inside a node ✅
    5. repeat 3, and 4 until you run out of node ✅

    6. return the node made by the sum ✅
*/
void printNode(ListNode* head) {
    ListNode* currNode = head;

    cout << "[";
    while(currNode != nullptr) {
        cout << " ";
        cout << currNode->val;
        currNode = currNode->next;
    }
    cout << "]" << endl;
}

int getListNodeLength(ListNode* l1) {
    int length = 0;
    ListNode* currNode = l1;

    while(currNode != nullptr) {
        length++;
        currNode = currNode->next;
    }

    return length;
}

ListNode* traverseToNode(ListNode* l1,int index) {
    ListNode* currNode = l1;

    for(int i = index;i > 1;i--) {
        if(currNode->next != nullptr) {
            currNode = currNode->next;
        } else {
            return new ListNode(0);
        }
    } 

    return currNode;
}

ListNode* insertToList(ListNode*& l1, int val) {
    if(l1 == nullptr) {
        l1 = new ListNode(val);
        cout << l1->val << "first_insertion ";
        return l1;
    }

    ListNode* currNode = l1;

    while(currNode->next != nullptr) {
        currNode = currNode->next;
    }
    
    currNode->next = new ListNode(val);
    cout << currNode->next->val << "last_insertion ";

    return l1;
}

ListNode* sumList(ListNode* l1,int l1_length,ListNode* l2,int l2_length,int carry) {
    int result;
    ListNode* result_ListNode = nullptr;

    for(int i = 1;i <= max(l1_length,l2_length);i++) {
        cout << i << "index ";
        ListNode* currNode1 = traverseToNode(l1,i);
        ListNode* currNode2 = traverseToNode(l2,i);
        cout << currNode1->val << "currNode1 ";
        cout << currNode2->val << "currNode2 ";

        int sum = currNode1->val + currNode2->val + carry;
        cout << sum << "sum ";
        if(sum > 9){
            result = sum - 10;
            carry = 1;
        } else {
            result = sum;
            carry = 0;
        }
        cout << result << "result ";
        cout << carry << "carry ";
        result_ListNode = insertToList(result_ListNode,result);

        cout << endl;
    }
    if(carry > 0) {
        result_ListNode = insertToList(result_ListNode,1);
    }

    printNode(result_ListNode);

    return result_ListNode;
}

//main function
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    printNode(l1);
    printNode(l2);
    ListNode* result_List = sumList(l1,getListNodeLength(l1),l2,getListNodeLength(l2),0);
    return result_List;
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next= new ListNode(4);

    addTwoNumbers(l1,l2);
}