#include <string>

//Write a function, getNodeValue, that takes in a pointer to the head of a linked list and an index. The functions
//should return the value of the linked list at the specified index.

//If there is no node at the given index, then return the empty string.

class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};



std::string getNodeValue(Node* head, int idx) {
    Node* current = head;
    int count = 0;
    while (current != nullptr){
        if(count == idx) return current->val;
        current = current->next;
        count += 1;
    }
    return nullptr;
}

int main () {
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");

    a.next = &b;
    b.next = &c;
    c.next = &d;

    // a -> b -> c -> d

    getNodeValue(&a, 2); // "c"

    Node a0("a");
    Node b0("b");
    Node c0("c");
    Node d0("d");

    a0.next = &b0;
    b0.next = &c0;
    c0.next = &d0;

    // a -> b -> c -> d

    getNodeValue(&a0, 3); // "d"

    Node a1("a");
    Node b1("b");
    Node c1("c");
    Node d1("d");

    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;

    // a -> b -> c -> d

    getNodeValue(&a1, 7); // ""

    Node node1("banana");
    Node node2("mango");

    node1.next = &node2;

    // banana -> mango

    getNodeValue(&node1, 0); // "banana"

    Node node10("banana");
    Node node20("mango");

    node10.next = &node20;

    // banana -> mango

    getNodeValue(&node10, 1); // "mango"
}

//Iterative Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( 1 )

//Recursive Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )