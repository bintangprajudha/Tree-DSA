#include "header.h"

void createTree(adrNode &root){
    root = nullptr;
}
adrNode newNode(infotype x){
    adrNode node = new Node;
    node->info = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void insertNode(adrNode &root, adrNode node){
    if(root == nullptr){
        root = node;
    } else if (node->info < root->info) {
        insertNode(root->left, node);
    } else if (node->info > root->info) {
        insertNode(root->right, node);
    }
}

void preOrder(adrNode root){
    if(root != nullptr){
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(adrNode root){
    if(root != nullptr){
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}
void postOrder(adrNode root){
    if(root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

adrNode findNode(adrNode root, infotype x){
    if(root == nullptr || root->info == x){
        return root;
    }

    adrNode leftSearch = findNode(root->left, x);
    if(leftSearch != nullptr){
        return leftSearch;
    }
    return findNode(root->right, x);
}

void descendant(adrNode root, infotype x){
    adrNode node = findNode(root, x);
    if(node != nullptr){
        preOrder(node->left);
        preOrder(node->right);
    }
}

void ancestor(adrNode root, infotype x){
    if (root == nullptr) {
        return;  // Basis: jika root kosong, hentikan
    }
    cout << root->info << " ";
    if(x < root->info){
        ancestor(root->left, x);
    } else if (x > root->info) {
        ancestor(root->right, x);
    }
}

adrNode findLeftBinTree(adrNode root){
    if(root == nullptr || root->left == nullptr){
        return root;
    }
    return findLeftBinTree(root->left);
}

adrNode findRigthBinTree(adrNode root){
    if(root == nullptr || root->right == nullptr){
        return root;
    } else {
        return findRigthBinTree(root->right);
    }
}

int sumNode(adrNode root){
    if(root == nullptr){
        return 0;
    }
    return root->info + sumNode(root->left) + sumNode(root->right);
}

int countNode(adrNode root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

int countLeaves(adrNode root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int countInnerNode(adrNode root){
    return countNode(root) - countLeaves(root) - 1;
}

int height(adrNode root){
    if(root == nullptr){
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int depth(adrNode root, infotype x){
    /*
    if(root->info == x){
        return 0;
    }
    if(x < root->info){
        return 1 + depth(root->left, x);
    } else {
        return 1 + depth(root->right, x);
    }
    */

    // Basis Kasus: Node tidak ditemukan
    if (root == nullptr) {
        return -1;  // Node tidak ditemukan
    }
    // Basis Kasus: Node ditemukan
    if (root->info == x) {
        return 0;  // Kedalaman root adalah 0
    }
    // Cari di subtree kiri jika x lebih kecil dari info root
    if (x < root->info) {
        int leftDepth = depth(root->left, x);
        if (leftDepth != -1) {
            return 1 + leftDepth;  // Tambahkan 1 jika ditemukan
        }
    }
    // Cari di subtree kanan jika x lebih besar dari info root
    else {
        int rightDepth = depth(root->right, x);
        if (rightDepth != -1) {
            return 1 + rightDepth;  // Tambahkan 1 jika ditemukan
        }
    }
    return -1;  // Node tidak ditemukan
}

int levelTree(adrNode root){
    return height(root) + 1;
}

int levelNode(adrNode root, infotype x){
    return 1 + depth(root, x);
}

void bfs(adrNode root) {
    if (root == nullptr) {
        return; // Jika tree kosong, langsung keluar
    }
    queue<adrNode> q;
    q.push(root); // Memasukkan root ke dalam queue

    while (!q.empty()) {
        adrNode current = q.front();
        q.pop();

        cout << current->info << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void deleteNode_103032330147(adrNode &root, adrNode &p) {
    if (root == nullptr || p == nullptr) return;

    if (p->info < root->info) {
        deleteNode_103032330147(root->left, p);
    } else if (p->info > root->info) {
        deleteNode_103032330147(root->right, p);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }

        else if (root->left == nullptr) {
            adrNode temp = root;
            root = root->right;
            delete temp;
        }

        else if (root->right == nullptr) {
            adrNode temp = root;
            root = root->left;
            delete temp;
        }

        else {
            adrNode temp = findMin_103032330147(root->right);
            root->info = temp->info;
            deleteNode_103032330147(root->right, temp);
        }
    }
}
