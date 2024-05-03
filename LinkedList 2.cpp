#include <iostream>

using namespace std;

class Node {
public:
    char data;  // Ubah dari 'id' menjadi 'data'
    Node* next;

    Node() {
        next = NULL;
    }
};

class LinkedList {
public:
    Node* first;  // Ubah dari 'head' menjadi 'first'
    Node* last;   // Ubah dari 'tail' menjadi 'last'

    LinkedList() {
        first = last = NULL;
    }

    void insertToHead(char newData) {
        Node* newNode = new Node();
        newNode->data = newData;

        if (first == NULL) {
            first = last = newNode;
        } else {
            Node* tmp = first;
            first = newNode;
            newNode->next = tmp;
        }
    }

    void insertToTail(char newData) {
        Node* newNode = new Node();
        newNode->data = newData;

        if (first == NULL) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void traversal() {
        Node* tmp = first;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void insertDataAfter(char newData, char afterData) {
        if (first == NULL) {
            cout << "ERROR: LinkedList Empty" << endl;
        } else {
            Node* tmp = first;
            while (tmp != NULL && tmp->data != afterData) {
                tmp = tmp->next;
            }
            if (tmp == NULL) {
                cout << "ERROR: Node with data '" << afterData << "' not found" << endl;
            } else {
                Node* newNode = new Node();
                newNode->data = newData;
                newNode->next = tmp->next;
                tmp->next = newNode;
                if (tmp == last) {
                    last = newNode;
                }
            }
        }
    }
};

int main(int argc, char** argv) {

    LinkedList* list1 = new LinkedList();

    list1->insertToHead('A');
    list1->insertToTail('B');

    cout << list1->first->data << endl;
    cout << list1->first->next->data << endl;

    Node* nodeX = new Node();
    nodeX->data = 'X';

    Node* tmp = list1->first->next;
    list1->first->next = nodeX;
    nodeX->next = tmp;

    list1->insertToTail('C');
    list1->insertToTail('D');

    cout << list1->first->data << endl;
    cout << list1->last->data << endl;

    return 0;
}

