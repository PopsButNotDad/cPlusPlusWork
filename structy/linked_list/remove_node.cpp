#include <string>

//Write a function, removeNode, that takes in a head of a linked list and a target value as arguments. The function should
//delete the target value from the linked list and return the head of the resulting linked list. If the target appears 
//multiple times in the linked list, only remove the first instance of the target in the list. 

//Do this in place

//You may assume that the input list is non empty. 
//You may assume that the input list contains the target. 

class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};



Node* removeNode(Node* head, std::string targetVal) {
    Node* current = head;
    Node* prev = nullptr;

    if(head->val == targetVal){
        return head->next;
    }

    while(current != nullptr){
        if(current->val == targetVal){
            prev->next = current->next;
            break;
        }

        prev = current;
        current = current->next;
    }
    return head;
}

Node* removeNodeRe(Node* head, std::string targetVal) {
    
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

    removeNode(&a, "c");
    // a -> b -> d -> e -> f

    Node x("x");
    Node y("y");
    Node z("z");

    x.next = &y;
    y.next = &z;

    // x -> y -> z

    removeNode(&x, "z");
    // x -> y

    Node q("q");
    Node r("r");
    Node s("s");

    q.next = &r;
    r.next = &s;

    // q -> r -> s

    removeNode(&q, "q");
    // r -> s

    Node node1("h");
    Node node2("i");
    Node node3("j");
    Node node4("i");

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    // h -> i -> j -> i

    removeNode(&node1, "i");
    // h -> j -> i

    Node node1("t");

    // t

    removeNode(&node1, "t");
    // nullptr
}

//Complexity
    //n = number of nodes
    
    //Time: O( n )
    //Space: O( 1 ) 