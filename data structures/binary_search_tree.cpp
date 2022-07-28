#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define bug(x) cerr << #x << " = " << x << endl
#define bugf(x) cerr << x << " "
#define bugl() cerr << endl
#define couts(x) cout << x << " "
#define coutl(x) cout << x << "\n"
#define endl '\n'
#define int long long


typedef long long ll;

const int N = 1e3 + 5;
int TEST_NUM = 1;

using namespace std;

class Node {
public:
    Node() {}
    Node (int value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
    Node *left;
    Node *right;
    int value;
};

class BST {
public:
    Node *root;

    BST() {
        root =  nullptr;

    }

    BST(int value) {
        root = new Node(value);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    pair<Node*, Node*> find(int value) {
        return find(root, value, nullptr);
    }
    void erase(int value) {
        root = erase(root, value);
    }
    pair<Node*, Node*> findMin() {
        return findMin(root, nullptr);
    }

    Node* erase(Node* node, int value) {
        if (node == nullptr) return nullptr;

        if (node->value > value) {
            node->left = erase(node->left, value);
            return node;
        }
        if (node->value < value) {
            node->right = erase(node->right, value);
            return node;
        }
        if (node->left == nullptr && node->right == nullptr) {
            free(node);
            return nullptr;
        }
        if (node->left == nullptr) {
            auto rightChild = node->right;
            free(node);
            return rightChild;
        }
        if (node->right == nullptr) {
            auto leftChild = node->left;
            free(node);
            return leftChild;
        }
        auto nextNodePair = findMin(node->right, node);
        auto nextNode = nextNodePair.first;
        auto nextNodeParent = nextNodePair.second;
        node->value = nextNode->value;
        nextNodeParent->left = nextNode->right;
        free(nextNode);

        return node;
    }
    pair<Node*, Node*> findMin(Node *node, Node *parent) {
        if (node == nullptr) return {nullptr, parent};
        if (node->left != nullptr) return findMin(node->left, node);
        return {node, parent};
    }

    Node* insert(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (node->value > value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    pair<Node*, Node*> find(Node *node, int value, Node *parent) {
        if (node == nullptr) {
            return make_pair(nullptr, parent);
        }
        if (node->value == value) return make_pair(node, parent);
        if (node->value > value) return find(node->left, value, node);
        return find(node->right, value, node);
    }
};


void solve() {
    srand(time(NULL));
    int n = 1000000;
    vector<int> nums(n);

    BST bst = BST();
    for (int i = 0; i < n; i++) {
        nums[i] = rand() % 10000000;
    }
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        bst.insert(nums[i]);
    }

    for (int i = 0; i < n; i++) {
        int minValue = bst.findMin().first->value;
        // cout<< minValue<<' ';
        bst.erase(minValue);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::milliseconds>(stop - start);
    cout<< duration.count() << endl;


    start = chrono::high_resolution_clock::now();
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        ms.insert(nums[i]);
    }

    for (int i = 0; i < n; i++) {
        int minValue = *ms.begin();
        // cout<< minValue<<' ';
        ms.erase(minValue);
    }
    stop = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::milliseconds>(stop - start);
    cout<< duration.count() << endl;



}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    cin>> TEST_NUM;
    while (TEST_NUM--){
        solve();
    }
    return 0;
}