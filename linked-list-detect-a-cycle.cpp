/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

// Logic 1
bool has_cycle(Node* head) {
    //save data in hastable
    //If encountered null; return false
    //If encountered same memory location twice; return true

    unordered_map <Node*, int> unique_nodes;
    Node* temp = head;
    while (temp != nullptr){
        unique_nodes[head] += 1;
        if(unique_nodes[temp] > 1)
            return false;
        temp = temp -> next;
    }
    
    return true;
     
}
