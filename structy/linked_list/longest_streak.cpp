//Write a function, longestStreak, that takes in the head of a linked list as an argument. The function should return
//the length of the longest consecutive streak of the same value within the list.

class Node {
    public:
        int val;    
        Node* next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};



int longestStreak(Node* head) {
    Node* currentNode = head;
    int maxStreak = 0;
    int currentStreak = 0;
    int prevVal = 0;
    while (currentNode != nullptr){
        if(prevVal == currentNode->val){
            currentStreak += 1;
        } else {
            currentStreak = 1;
        }
        if(currentStreak > maxStreak){
            maxStreak = currentStreak;
        }
        prevVal = currentNode->val;
        currentNode = currentNode->next;
    };
    return maxStreak;
}

int main() {
    Node a0(5);
    Node b0(5);
    Node c0(7);
    Node d0(7);
    Node e0(7);
    Node f0(6);

    a0.next = &b0;
    b0.next = &c0;
    c0.next = &d0;
    d0.next = &e0;
    e0.next = &f0;

    // 5 -> 5 -> 7 -> 7 -> 7 -> 6

    longestStreak(&a0); // 3

    Node a1(3);
    Node b1(3);
    Node c1(3);
    Node d1(3);
    Node e1(9);
    Node f1(9);

    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    d1.next = &e1;
    e1.next = &f1;

    // 3 -> 3 -> 3 -> 3 -> 9 -> 9

    longestStreak(&a1); // 4

    Node a(9);
    Node b(9);
    Node c(1);
    Node d(9);
    Node e(9);
    Node f(9);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    // 9 -> 9 -> 1 -> 9 -> 9 -> 9

    longestStreak(&a); // 3

    Node a3(5);
    Node b3(5);

    a3.next = &b3;

    // 5 -> 5

    longestStreak(&a3); // 2

    Node a2(4);

    // 4

    longestStreak(&a2); // 1

    longestStreak(nullptr); // 0
};

//Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( 1 )