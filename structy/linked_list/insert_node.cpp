#include <string>

//Write a function, insertNode, that takes in the head of a linked list, a value, and an index. The function should
//insert a new node with the value into the list at the specified index. Consider the head of the linked list as index 0.
//The function should return the head of the resulting linked list. 

//Do this in-place and be sure to dynamically allocate the new node in memory using new.

//You may assume the input list is non-empty and the index is not greater than the length of the input list. 

class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};



Node* insertNode(Node* head, std::string value, int idx) {
    
    return;
}

int main() {
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");

    a.next = &b;
    b.next = &c;
    c.next = &d;

    // a -> b -> c -> d

    insertNode(&a, "x", 2);
    // a -> b -> x -> c -> d

    Node a0("a");
    Node b0("b");
    Node c0("c");
    Node d0("d");

    a0.next = &b0;
    b0.next = &c0;
    c0.next = &d0;

    // a -> b -> c -> d

    insertNode(&a0, "v", 3);
    // a -> b -> c -> v -> d

    Node a1("a");
    Node b1("b");
    Node c1("c");
    Node d1("d");

    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;

    // a -> b -> c -> d

    insertNode(&a1, "m", 4);
    // a -> b -> c -> d -> m

    Node a2("a");
    Node b2("b");

    a2.next = &b2;

    // a -> b

    insertNode(&a2, "z", 0);
    // z -> a -> b
}