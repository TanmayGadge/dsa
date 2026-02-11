/*
Reverse Even-Indexed Nodes and Append

Given a singly linked list, extract all even-indexed nodes, reverse their order, and append them to the end of the list in one traversal. Return the head of the modified list.

Example

Input:
head = [10, 20, 30, 40, 50, 60]

Output:
[20, 40, 60, 50, 30, 10]

Explanation:
- Step 1: Extract sponsored nodes at even positions 0, 2, 4 → [10, 30, 50]. 
- Step 2: Remaining non-sponsored nodes are [20, 40, 60]. 
- Step 3: Reverse the extracted sponsored list → [50, 30, 10]. 
- Step 4: Append the reversed list to [20, 40, 60], yielding [20, 40, 60, 50, 30, 10].
*/

#include <iostream>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* extractAndAppendSponsoredNodes(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* temp = head;
    SinglyLinkedListNode* newHead = nullptr;
    SinglyLinkedListNode* newTemp = nullptr;
    SinglyLinkedListNode* prev = nullptr;

    int index = 0;

    while(temp != nullptr){
        if(index % 2 == 0){

            if(index == 0){
                //Removing the head and adding it to another linked list
                newTemp = head;
                
                head = head->next;
                if(head == nullptr){
                    //There is only one element in the linked list
                    return newTemp;
                }

                newTemp->next = nullptr;
                newHead = newTemp;

                temp = head;
                index++;

            }else{
                prev->next = temp->next;
                
                newTemp->next = temp; //attaching the current node to the new list
                newTemp = newTemp->next;
                
                temp = temp->next;
                index++;

                newTemp->next = nullptr;
            }

        }else{

            if(prev == nullptr){
                prev = temp;
            }else{
                prev = prev->next;
            }
    
            temp = temp->next;
            index++;
        }


    }

    //Reverse the newHead linked list
    SinglyLinkedListNode* curr = newHead;
    SinglyLinkedListNode* newPrev = nullptr;
    // SinglyLinkedListNode* next = newHead->next;
    SinglyLinkedListNode* nextTemp;

    while(curr != nullptr){
        nextTemp = curr->next;
        curr->next = newPrev;
        newPrev = curr;

        curr = nextTemp;
    }

    newHead = newPrev; //newPrev will point to the head of the reversed list
    
    if(prev != nullptr){
        prev->next = newHead; //joining the two lists
    }else{
        return nullptr;
    }

    return head;

}


int main(){

    SinglyLinkedListNode* head = new SinglyLinkedListNode();
    head->data = 10;
    SinglyLinkedListNode* temp = head;

    cout << "head->";
    for(int i = 1; i < 6; i++){
        temp->next = new SinglyLinkedListNode();
        temp = temp->next;
        temp->data = i * 10;
        temp->next = nullptr;
        cout << temp->data << "->";
    }
    cout << "nullptr" << endl;
    cout << endl;

    SinglyLinkedListNode* newHead = extractAndAppendSponsoredNodes(head);
    temp = newHead;

    cout << "head->";
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;


    return 0;
}