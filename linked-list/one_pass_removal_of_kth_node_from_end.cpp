/*
Given the head of a singly linked list and an integer k, remove the k-th node from the end in one traversal and return the new head. If k is invalid, return the original list.

Example

Input;
head = [5, 6, 7, 8]
k = 3

Output;
[6, 7, 8]

Explanation;
The list has 4 nodes. 
The k-th node from the end with k=3 is the 4th node from the end (value 5), which is the head. Removing it yields [6,7,8].
*/

#include <iostream>
using namespace std;


struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* removeKthNodeFromEnd(SinglyLinkedListNode* head, int k) {
    
    if(!head) return nullptr;
    
    SinglyLinkedListNode* fast = head;
    SinglyLinkedListNode* slow = head;
    
    for(int i = 0; i < k+1; i++){
     if(fast == nullptr) return head; //If K > Lenght of Linked list
     
     fast = fast->next;
    }
    
    if(fast == nullptr){// K = Lenght of Linked List
        //Remove the head
        SinglyLinkedListNode* newHead = head->next;
        delete head;
        return newHead;
    }
    
    SinglyLinkedListNode* prev = nullptr;
    while(fast != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    
    prev->next = slow->next;
    delete slow;
    
    return head;
}

int main(){
    return 0;
}