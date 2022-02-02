#include <string>

//Write a function, linkedListFind, that takes in a pointer to the head of a linked list and a target value. The function
//should return a boolean indicating whether or not the linked list contains the target.

class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

bool linkedListFind(Node* head, std::string target) {
    Node* current = head;
    while (current != nullptr){
        if(current->val == target) return true;

        current = current->next;
    }
    return false;
}

bool linkedListFindRe(Node* head, std::string target) {
    if(head == nullptr) return false;
    if(head->val == target) return true;
    return linkedListFindRe(head->next, target);
}

int main( ) {
    Node a0("a");
    Node b0("b");
    Node c0("c");
    Node d0("d");

    a0.next = &b0;
    b0.next = &c0;
    c0.next = &d0;

    // a -> b -> c -> d

    linkedListFind(&a0, "c"); // 1 (true)

    Node a1("a");
    Node b1("b");
    Node c1("c");
    Node d1("d");

    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;

    // a -> b -> c -> d

    linkedListFind(&a1, "d"); // 1 (true)

    Node a2("a");
    Node b2("b");
    Node c2("c");
    Node d2("d");

    a2.next = &b2;
    b2.next = &c2;
    c2.next = &d2;

    // a -> b -> c -> d

    linkedListFind(&a2, "q"); // 0 (false)

    Node node1("jason");
    Node node2("leneli");

    node1.next = &node2;

    // jason -> leneli

    linkedListFind(&node1, "jason"); // 1 (true)

    Node node10("potato");// potato

    linkedListFind(&node10, "potato"); // 1 (true)

    Node node11("potato"); // potato

    linkedListFind(&node11, "apple"); // 0 (false)
}

//Iterative Complexity:
    //n = number of nodes

    //Time: O( n )
    //Space:O( 1 )

//Recursive Complexity:
    //n = numbers of node

    //Time: O( n )
    //Space: O( n )