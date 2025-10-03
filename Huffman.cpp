#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// For min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman codes
void printHuffman(Node* root, string code) {
    if (!root) return;
    if (root->ch != '#') cout << root->ch << ":" << code << " ";
    printHuffman(root->left, code + "0");
    printHuffman(root->right, code + "1");
}

// Build Huffman tree and print codes
void huffman(string S, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> heap;

    // put all chars in heap
    for (int i = 0; i < S.size(); i++) {
        heap.push(new Node(S[i], freq[i]));
    }

    // make tree
    while (heap.size() > 1) {
        Node* left = heap.top(); heap.pop();
        Node* right = heap.top(); heap.pop();
        Node* newNode = new Node('#', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        heap.push(newNode);
    }

    // prin codes
    printHuffman(heap.top(), "");
}

int main() {
    string S = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    if (S.size() != freq.size()) {
        cout << "string and freq size not same!\n";
        return 1;
    }

    huffman(S, freq);
    cout << "\n";
    return 0;
}
