#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node* head = nullptr;

void AddToBeginning(int n) {
    struct Node* newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

void AddToEnd(int n) {
    struct Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    struct Node* newNode = new Node;
    newNode->data = n;
    newNode->next = nullptr;
    temp->next = newNode;
}

int FindMiddle() {
    struct Node* tempEnd = head;
    struct Node* tempMid = head;
    int counter = 0;
    while (tempEnd != nullptr) {
        tempEnd = tempEnd->next;
        counter++;
        if (counter % 2 == 0) {
            tempMid = tempMid->next;
        }
    }
    return tempMid->data;
}

int AddToMiddle() {
    struct Node* tempEnd = head;
    struct Node* tempMid = head;
    int counter = 0;
    while (tempEnd != nullptr) {
        tempEnd = tempEnd->next;
        counter++;
        if (counter % 2 == 0) {
            tempMid = tempMid->next;
        }
    }
    
}

void DisplayAll() {
    struct Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int cmd, a;
    while (cmd != -1) {
        cout << "CMD: ";
        cin >> cmd;
        switch (cmd) {
            case 1:
                cin >> a;
                AddToBeginning(a);
                break;
            case 2:
                cin >> a;
                AddToEnd(a);
                break;
            case 3:
                cout << FindMiddle() << endl;
                break;
            case 0:
                DisplayAll();
                break;
            default:
                cout << "Invalid Command." << endl;
        }
    }
    
    return 0;
}