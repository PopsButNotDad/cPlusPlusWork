#include <string>
#include <vector>

//Write a function, createLinkedList, that takes in a vector of values as an argument. 
//The function should create a linked list containing each element of the vector as the values of the nodes. 
//The function should return the head of the linked list.

//Be sure to dynamically allocate the new nodes in memory using new.

class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};



Node* createLinkedList(std::vector<std::string> values) {
    // todo
    return;
}

int main() {
    std::vector<std::string> values0 { "h", "e", "y" };
    createLinkedList(values0);
    // h -> e -> y

    std::vector<std::string> values1 { "1", "7", "1", "8" };
    createLinkedList(values1);
    // 1 -> 7 -> 1 -> 8

    std::vector<std::string> values2 { "a" };
    createLinkedList(values2);
    // a

    std::vector<std::string> values3;
    createLinkedList(values3);
    // nullptr


}