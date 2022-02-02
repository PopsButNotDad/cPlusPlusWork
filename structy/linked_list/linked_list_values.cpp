#include <vector>
#include <string>
#include <iostream>

//Write a function, linkedListValues, that takes in a pointer to the head of a linked list as an argument. The function
//should return an array containing all values of the nodes in the linked list.


class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};



std::vector<std::string> linkedListValues(Node* head) {
    // todo
    return;
};

int main() {
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");

    a.next = &b;
    b.next = &c;
    c.next = &d;

    // a -> b -> c -> d

    linkedListValues(&a); // -> [ "a", "b", "c", "d" ]

    Node x("x");
    Node y("y");

    x.next = &y;

    // x -> y

    linkedListValues(&x); // -> [ "x", "y" ]

    Node q("q");

    // q

    linkedListValues(&q); // -> [ "q" ]

    linkedListValues(nullptr); // -> [ ]
}

//Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )