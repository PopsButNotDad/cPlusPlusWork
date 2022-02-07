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
    Node* dummyHead = new Node("");
    Node* tail = dummyHead;

    for(std::string val : values){
        tail->next = new Node(val);
        tail = tail->next;
    }

    
    return dummyHead->next;
}

Node* createLinkedListRe(std::vector<std::string> values, int idx) {
    if(idx == values.size()){
        return nullptr;
    }

    Node* head = new Node(values[idx]);
    head->next = createLinkedListRe(values, idx + 1);
}

Node* createLinkedListRe(std::vector<std::string> values) {
    return createLinkedListRe(values, 0);
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

//Iterative Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )

//Recursive Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )