//Joel Miller
//CPSC 3120
//10/24/2023



#include "OurCPSC3120Tree.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
class OurCPSC3120Tree{
 public:
  OurCPSC3120Tree(void);
  OurCPSC3120Tree(OurCPSC3120Tree&);
  ~OurCPSC3120Tree(void);
  OurCPSC3120Tree* getParent(void);
  OurCPSC3120Tree* getLeft(void);
  OurCPSC3120Tree* getRight(void);
  int getValue(void);
  void setParent(OurCPSC3120Tree&);
  void setLeft(OurCPSC3120Tree&);
  void setRight(OurCPSC3120Tree&);
  void setValue(int);
  void insert(int);
  void printPreorder(void);
  void printInorder(void);
  void printPostorder(void);
  void rotateLeft(void);
  void rotateRight(void);
  void rotateLeftRight(void);
  void rotateRightLeft(void);
  void deleteNode(int);
    
 private:
  int value;
  OurCPSC3120Tree *parent;
  OurCPSC3120Tree *left;
  OurCPSC3120Tree *right;
  int getHeight();
  void balanceTree();
  void printInfo();
};
 */


OurCPSC3120Tree::OurCPSC3120Tree(){
  value = 0;
  parent = NULL;
  left = NULL;
  right = NULL;
}

OurCPSC3120Tree::OurCPSC3120Tree( OurCPSC3120Tree &t ){
  setParent( *t.getParent() );
  setLeft( *t.getLeft() );
  setRight( *t.getRight() );
}

OurCPSC3120Tree::~OurCPSC3120Tree(){
  delete left;
  delete right;
  delete parent;
  left = NULL;
  right = NULL;
  parent = NULL;
}

int OurCPSC3120Tree::getValue(){
  return value;
}

OurCPSC3120Tree* OurCPSC3120Tree::getLeft(){
  return left;
}

OurCPSC3120Tree* OurCPSC3120Tree::getRight(){
  return right;
}

OurCPSC3120Tree* OurCPSC3120Tree::getParent(){
  return parent;
}

void OurCPSC3120Tree::setValue( int v ){
  value = v;
  return;
}

void OurCPSC3120Tree::setParent( OurCPSC3120Tree &newParent ){
  parent = &newParent;
}

void OurCPSC3120Tree::setLeft( OurCPSC3120Tree &newLeft ){
  left = &newLeft;
  return;
}

void OurCPSC3120Tree::setRight( OurCPSC3120Tree &newRight ){
  right = &newRight;
  return;
}

void OurCPSC3120Tree::printInfo(){
  cerr << this << endl;
  cerr << "---------------" << endl;
  cerr << "Value : " << getValue() << endl;
  cerr << "Parent: " << getParent() << endl;
  cerr << "Left  : " << getLeft() << endl;
  cerr << "Right : " << getRight() << endl;
  cerr << "Height: " << getHeight() << endl;
  cerr << "===============" << endl;
  if( getLeft() ){
    getLeft()->printInfo();
  }
  if( getRight() ){
    getRight()->printInfo();
  }
}

void OurCPSC3120Tree::printPreorder(){
  cout << getValue();
  if( getLeft() && getLeft()->getValue() ){
    cout << ",";
    getLeft()->printPreorder();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printPreorder();
  }

  return;
}

void OurCPSC3120Tree::printInorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printInorder();
    cout << ",";
  }
  cout << getValue();
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printInorder();
  }

  return;
}

void OurCPSC3120Tree::printPostorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printPostorder();
    cout << ",";
  }
  if( getRight() && getRight()->getValue() ){
    getRight()->printPostorder();
    cout << ",";
  }
  cout << getValue();
  return;
}

void OurCPSC3120Tree::insert( int val ){
  if( !getValue() ){
    setValue( val );
  }
  else if( val < getValue() && !getLeft() ){
    left = new OurCPSC3120Tree();
    getLeft()->setParent( *this );
    getLeft()->insert( val );
  }
  else if( val > getValue() && !getRight() ){
    right = new OurCPSC3120Tree();
    getRight()->setParent( *this );
    getRight()->insert( val );
  }
  else if( val < getValue() ){
    getLeft()->insert( val );
  }
  else{
    getRight()->insert( val );
  }

  balanceTree();
  
  return;
}

int OurCPSC3120Tree::getHeight(){
  if( !getValue() ){
    return 0;
  }
  if( !getLeft() && !getRight() ){
    return 1;
  }
  if( getLeft() && !getRight() ){
    return getLeft()->getHeight() + 1;
  }
  if( !getLeft() && getRight() ){
    return getRight()->getHeight() + 1;
  }
  
  return fmax( getLeft()->getHeight() , getRight()->getHeight() ) + 1;
}

void OurCPSC3120Tree::balanceTree(){
  if( !getRight() && getLeft() && !getLeft()->getLeft() && getLeft()->getHeight() >= 2 ){
    rotateLeftRight();
    return;
  }
  if( !getRight() && getLeft() && getLeft()->getLeft() && getLeft()->getRight() && getLeft()->getRight()->getHeight() > getLeft()->getLeft()->getHeight() ){
    rotateLeftRight();
    return;
  }
  if( !getLeft() && getRight() && !getRight()->getRight() && getRight()->getHeight() >= 2 ){
    rotateRightLeft();
    return;
  }
  if( !getLeft() && getRight() && getRight()->getRight() && getRight()->getLeft() && getRight()->getLeft()->getHeight() > getRight()->getRight()->getHeight() ){
    rotateRightLeft();
    return;
  }
  if( !getLeft() && getRight() && getRight()->getHeight() >= 2 ){
    rotateLeft();
    return;
  }
  if( getLeft() && getRight() && getRight()->getHeight() >= ( getLeft()->getHeight() + 2 ) ){
    rotateLeft();
    return;
  }
  if( !getRight() && getLeft() && getLeft()->getHeight() >= 2 ){
    rotateRight();
    return;
  }
  if( getRight() && getLeft() && getLeft()->getHeight() >= ( getRight()->getHeight() + 2 ) ){
    rotateRight();
    return;
  }
}

void OurCPSC3120Tree::rotateLeftRight(){
  getLeft()->rotateLeft();
  rotateRight();
  return;
}

void OurCPSC3120Tree::rotateRightLeft(){
  getRight()->rotateRight();
  rotateLeft();
  return;
}



void OurCPSC3120Tree::rotateLeft() {
    // Create a new tree node to become the new root
    OurCPSC3120Tree *newRoot = new OurCPSC3120Tree;
    newRoot->setValue(getValue());

    // If the right child has a left child, update their relationships
    if (getRight()->getLeft()) {
        getRight()->getLeft()->setParent(*newRoot);
        newRoot->setRight(*getRight()->getLeft());
    }
    // If the current node has a left child, update their relationship
    if (getLeft()) {
        getLeft()->setParent(*newRoot);
        newRoot->setLeft(*getLeft());
    }

    // Update the parent of the new root and set it as the left child of the current node
    newRoot->setParent(*this);
    setLeft(*newRoot);
    setValue(getRight()->getValue());

    // If the right child has a right child, update their relationships
    if (getRight()->getRight()) {
        OurCPSC3120Tree *remove = getRight();

        setRight(*remove->getRight());
        remove->getRight()->setParent(*this);
    }
}



void OurCPSC3120Tree::rotateRight() {
    // Create a new tree node to become the new root
    OurCPSC3120Tree* newRoot = new OurCPSC3120Tree;
    newRoot->setValue(getValue());

    // If there is a right child, update their relationships
    if (getRight()) {
        getRight()->setParent(*newRoot);
        newRoot->setRight(*getRight());
    }

    // If the left child's right child exists, update their relationships
    if (getLeft()->getRight()) {
        getLeft()->getRight()->setParent(*newRoot);
        newRoot->setLeft(*getLeft()->getRight());
    }

    // Update the parent of the new root and set it as the right child of the current node
    newRoot->setParent(*this);
    setRight(*newRoot);
    setValue(getLeft()->getValue());

    // If the left child's left child exists, update their relationships
    if (getLeft()->getLeft()) {
        OurCPSC3120Tree* remove = getLeft();

        setLeft(*remove->getLeft());
        remove->getLeft()->setParent(*this);
    }
}



void OurCPSC3120Tree::deleteNode(int val) {
    if (val < value) {
        if (left) {
            left->deleteNode(val);
            balanceTree();
        }
    } else if (val > value) {
        if (right) {
            right->deleteNode(val);
            balanceTree();
        }
    } else {
        // Node to delete has been found

        // If the node has two children
        if (left && right) {
            // Find the minimum value in the right subtree
            OurCPSC3120Tree* minRight = right;
            while (minRight->left) {
                minRight = minRight->left;
            }

            // Copy the minimum value to this node
            value = minRight->value;

            // Delete the node with the minimum value in the right subtree
            right->deleteNode(minRight->value);
        } else {
            OurCPSC3120Tree* child = left ? left : right;

            if (parent) {
                if (this == parent->left) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }

            if (child) {
                child->parent = parent;
            }

            // The node is no longer connected to the tree
            left = right = parent = nullptr;

            delete this;
        }
    }
}

