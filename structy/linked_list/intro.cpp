#include <string>
#include <iostream>

//class node contains public values
class Node {
    public:
        //a string data variable called val
        std::string val;
        //a pointer to the next node in the linked list
        Node* next;

    //constructor takes a string data variable called initialVal
    Node(std::string initialVal) {
        //assigns the val variable to the initialVal
        val = initialVal;
        //sets next to nullptr
        next = nullptr;
    }
};

//iterative solution
void printList(Node* head){
    Node* current = head;
    while (current != nullptr){
        //since current is a node pointer, to get any values of the reference you must use the skinny pointer
        std::cout << current->val << std::endl;
        current = current->next;
    }
};

void printListRecursive(Node* head){
    if (head == nullptr){
        return;
    }
    std::cout << head->val << std::endl;
    printListRecursive(head->next);    
};

int main () {
    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");

    //using the ampersand reference operator because of initializing with a pointer in the class function
    a.next = &b;
    b.next = &c;
    c.next = &d;

    //A -> B -> C -> D -> null
    

    //once again using the & operator because it needs to be a reference to the memory address of the node pointer
    printList(&a);
    printListRecursive(&a);

};