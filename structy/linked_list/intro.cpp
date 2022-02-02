#include <string>

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

int main () {
    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");

    //using the ampersand reference operator because of initializing with a pointer in the class function
    a.next = &b;
    b.next = &c;
    c.next = &d;





};