 cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

//Logic 2
// Floyd's cycle-finding algorithm

bool has_cycle(Node* head) {
    
    Node* hare = head;
    Node* tortoise = head;
    
    if (head == nullptr)
        return false;
    
    do{
        if(hare->next == nullptr || hare->next->next == nullptr)
            return false;
        hare = hare->next->next;    // Hare is 2 steps ahead of tortoise
        tortoise = tortoise->next;
        
    }while(hare != tortoise);
    
    return true;
    
}

