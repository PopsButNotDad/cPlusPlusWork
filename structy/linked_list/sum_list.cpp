class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};

int sumList(Node* head) {
  // todo
  return;
}

int main() {
    Node a(2);
    Node b(8);
    Node c(3);
    Node d(-1);
    Node e(7);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    // 2 -> 8 -> 3 -> -1 -> 7

    sumList(&a); // 19

    Node x(38);
    Node y(4);

    x.next = &y;

    // 38 -> 4

    sumList(&x); // 42

    Node z(100);

    // 100

    sumList(&z); // 100

    sumList(nullptr); // 0

}

//Iterative Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )

//Recursive Complexity
    //n = number of nodes 

    //Time: O(  )
    //Space: O(  )