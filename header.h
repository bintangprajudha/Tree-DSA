#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <queue>
using namespace std;

typedef struct Node* adrNode;
typedef int infotype;

struct Node {
    infotype info;
    adrNode left, right;
};

void createTree(adrNode &root);
adrNode newNode(infotype x);
void insertNode(adrNode &root, adrNode node);

void preOrder(adrNode root);
void inOrder(adrNode root);
void postOrder(adrNode root);

adrNode findNode(adrNode root, infotype x);

void descendant(adrNode root, infotype x);
void ancestor(adrNode root, infotype x);

adrNode findLeftBinTree(adrNode root);
adrNode findRigthBinTree(adrNode root);

int sumNode(adrNode root);
int countNode(adrNode root);
int countLeaves(adrNode root);
int countInnerNode(adrNode root);

int height(adrNode root);
int depth(adrNode root, infotype x);
int levelTree(adrNode root);
int levelNode(adrNode root, infotype x);

void bfs(adrNode root);
void deleteNode_103032330147(adrNode &root, adrNode &p);

#endif // HEADER_H_INCLUDED
