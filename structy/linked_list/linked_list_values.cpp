#include <vector>
#include <string>

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

//iterative
std::vector<std::string> linkedListValues(Node* head) {
    std::vector<std::string> result;
    Node* current = head;
    while(current != nullptr){
        result.push_back(current->val);
        current = current->next;
    }
    return result;
};

//USING OVERLOADING HERE, SAME FUNCTION IS NAMED TWICE BUT TAKES DIFFERENT ARGUMENTS
//recursive
void linkedListValuesRe(Node* head, std::vector<std::string> &values) {
    if(head == nullptr){
        return;
    }
    values.push_back(head->val);
    linkedListValuesRe(head->next, values);
};

std::vector<std::string> linkedListValuesRe(Node* head) {
    std::vector<std::string> values;
    linkedListValuesRe(head,values);
    return values;
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
    linkedListValuesRe(&a); // -> [ "a", "b", "c", "d" ]

    Node x("x");
    Node y("y");

    x.next = &y;

    // x -> y

    linkedListValues(&x); // -> [ "x", "y" ]
    linkedListValuesRe(&x); // -> [ "x", "y" ]

    Node q("q");

    // q

    linkedListValues(&q); // -> [ "q" ]
    linkedListValuesRe(&q); // -> [ "q" ]

    linkedListValues(nullptr); // -> [ ]
    linkedListValuesRe(nullptr); // -> [ ]
}

//Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )