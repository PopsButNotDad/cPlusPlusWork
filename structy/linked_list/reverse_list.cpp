#include <string>

//Write a function, reverseList, that takes in a pointer to the head of a linked list as an argument. The function
//should reverse the order of the nodes in the linked list in-place and return the new head of the reversed linked list.

class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

Node* reverseList(Node* head) {
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr){
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

//OVERLOADING FUNCTION
Node* reverseListRe(Node* current, Node* prev) {
    if (current == nullptr){
        return prev;
    }
    Node* newHead = reverseListRe(current->next, current);
    current->next = prev;
    return newHead;
}

Node* reverseListRe(Node* head) {
    
    return reverseListRe(head, nullptr);
}

int main() {
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    // a -> b -> c -> d -> e -> f

    reverseList(&a); // f -> e -> d -> c -> b -> a

    Node x("x");
    Node y("y");

    x.next = &y;

    // x -> y

    reverseList(&x); // y -> x

    Node p("p");

    // p

    reverseList(&p); // p
};

//Iterative Complexity
    // n = number of nodes

    //Time: O( n )
    //Space:  O( 1 )

//Recursive Complexity
    // n = number of nodes
    
    //Time: O( n )
    //Space: O( n )