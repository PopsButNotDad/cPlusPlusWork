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
    
    return;
}

int main() {
    Node a(5);
    Node b(5);
    Node c(7);
    Node d(7);
    Node e(7);
    Node f(6);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    // 5 -> 5 -> 7 -> 7 -> 7 -> 6

    longestStreak(&a); // 3

    Node a(3);
    Node b(3);
    Node c(3);
    Node d(3);
    Node e(9);
    Node f(9);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    // 3 -> 3 -> 3 -> 3 -> 9 -> 9

    longestStreak(&a); // 4

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

    Node a(5);
    Node b(5);

    a.next = &b;

    // 5 -> 5

    longestStreak(&a); // 2

    Node a(4);

    // 4

    longestStreak(&a); // 1

    longestStreak(nullptr); // 0
};