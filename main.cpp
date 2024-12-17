#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    adrNode root;
    createTree(root);

    int x[10] = {15, 10, 20, 8, 12, 18, 25, 6, 9, 11};

    for(int i = 0; i < 10; i++){
        adrNode node = newNode(x[i]);
        insertNode(root, node);
    }

    for(int i = 0; i < 10; i++){
        cout << x[i] << " ";
    }
    cout << endl << endl;

    cout << "Preorder\t: ";
    preOrder(root);
    cout << endl << endl;

    cout << "Inorder\t\t: ";
    inOrder(root);
    cout << endl << endl;

    cout << "Postorder\t: ";
    postOrder(root);
    cout << endl << endl;

    cout << "BFS\t: ";
    bfs(root);
    cout << endl << endl;

    cout << "Descendant node 10\t: ";
    descendant(root, 10);
    cout << endl;

    cout << "Ancestor node 11\t: ";
    ancestor(root, 11);
    cout << endl << endl;

    cout << "Left node\t: ";
    cout << findLeftBinTree(root)->info << endl;

    cout << "Right node\t: ";
    cout << findRigthBinTree(root)->info << endl << endl;

    cout << "Sum Node\t: ";
    cout << sumNode(root) << endl;

    cout << "Count Node\t: ";
    cout << countNode(root) << endl;

    cout << "Count Leaves\t: ";
    cout << countLeaves(root) << endl;

    cout << "Count inner\t: ";
    cout << countInnerNode(root) << endl << endl;

    cout << "Height\t: ";
    cout << height(root) << endl;

    cout << "Depth 8\t: ";
    cout << depth(root, 8) << endl;

    cout << "Level \t: ";
    cout << levelTree(root) << endl;

    cout << "Level 8\t: ";
    cout << levelNode(root, 8) << endl;

    return 0;
}
