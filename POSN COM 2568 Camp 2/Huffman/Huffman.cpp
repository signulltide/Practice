#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f): ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(char c, int f, Node* l, Node* r): ch(c), freq(f), left(l), right(r) {}
};

struct CompareNodes {
    bool operator() (Node *n1, Node *n2) {
        return n1->freq > n2->freq;
    }
};

Node* head = NULL;

map<char, string> encodingMap;

void MakeTable(Node *curr, string code) {
    if (curr->left == nullptr && curr->right == nullptr) { // is leaf -> is char
        encodingMap[curr->ch] = code;
        return;
    }
    MakeTable(curr->left, code + "0");
    MakeTable(curr->right, code + "1");
}

void DecodeMessage(Node *curr, string encoded, int pos) {
    if (pos > encoded.length()) return;
    if (curr->left == nullptr && curr->right == nullptr) { // is leaf -> is char
        cout << curr->ch;
        curr = head;
    }
    if (encoded[pos] == '0') {
        curr = curr->left;
    } else if (encoded[pos] == '1') {
        curr = curr->right;
    }
    DecodeMessage(curr, encoded, pos+1);
}

void FreeTree(Node* root) {
    if (!root) return;
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
}

int main() {
    string message;
    cin >> message;
    map<char, int> freqMap;
    for (int i=0; i<message.length(); i++) {
        freqMap[message[i]]++;
    }
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    for (auto &[c, f] : freqMap) {
        Node *newnode = new Node(c, f);
        pq.push(newnode);
    }
    if (freqMap.size() == 1) {
        encodingMap[message[0]] = "0";
        goto SKIP;
    }
    while (pq.size() > 1) {

        Node *fir = pq.top(); pq.pop();
        Node *sec = pq.top(); pq.pop();
        Node *newnode = new Node('_', fir->freq + sec->freq, fir, sec);
        pq.push(newnode);
    }
    //out << pq.size();
    head = pq.top();
    MakeTable(head, "");
    SKIP:
    cout << "Huffman Codes:\n";
    for (auto &[c, e] : encodingMap) {
        cout << c << " = " << e << endl;
    }
    cout << "Encoded message:\n";
    string encodedMessage = "";
    for (char c : message) {
        encodedMessage += encodingMap[c];
    }
    cout << encodedMessage;
    cout << "\nDecoded message from encoded message:\n";
    DecodeMessage(head, encodedMessage, 0);
}