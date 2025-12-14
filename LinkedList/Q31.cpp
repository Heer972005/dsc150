//Write a Program to Move the last element to Front in a Linked List.
// C++ Program to move last element
// to front in a given linked list

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to move the last node to the
// front of the linked list
Node *moveToFront(Node *head) {
  
    // If the list is empty or has only one node,
    // no need to move
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // To keep track of the second last node
    Node *secLast = NULL;

    // To traverse to the last node
    Node *last = head;

    // Traverse the list to find the last and
    // second last nodes
    while (last->next != NULL) {
        secLast = last;
        last = last->next;
    }

    // Change the next of second last node to NULL
    secLast->next = NULL;

    // Make the last node as the new head
    last->next = head;
    head = last;

    return head;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
  
    // Create a linked list 1->2->3->4->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked list before: " << endl;
    printList(head);

    head = moveToFront(head);

    cout << "Linked list after: " << endl;
    printList(head);

    return 0;
}