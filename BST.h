#include "Treenode.h"

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();

  void insert_node(int);
  void print(int = 0);
    /* 0= inOrder 1=preOrder 2=postorder 3=printeverything 4=3+ print tree*/

};

// Additional functions
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr,int); //The real lab
  void kill(TreeNodePtr);

void BST::insert_node(int value) {
    int inserted = 0;
    TreeNodePtr new_node, t;
    new_node = new TreeNode(value);

    if (new_node) {
        if (rootPtr == NULL) {
            rootPtr = new_node;          
        } else {
            t = rootPtr;
            while (!inserted) {
                if (value < t->get_value()) {
                    if (t->move_left() == NULL) {
                        t->set_left(new_node);
                        inserted = 1;
                    } else {
                        t = t->move_left();
                    }
                } else {
                    if (t->move_right() == NULL) {
                        t->set_right(new_node);
                        inserted = 1;
                    } else {
                        t = t->move_right();
                    }
                }
            }
      cout << value << "inserted" << endl;  
     }
     ++size;
 }
}


void BST::print(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  case 3:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
      default:
    printTree(rootPtr,0);
    cout << endl;
  }
}


BST::BST() {
  rootPtr=NULL;
  size=0;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
  kill(rootPtr);     // free every node before the object dies
  rootPtr = NULL;
  size    = 0;
}

void inOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                                 // end if
} // end function
  //printTree(rootPtr,0);

void printTree(TreeNodePtr treePtr,int l) {
if(treePtr){
  printTree(treePtr->move_right(),1+l);
  cout<<setw(3*l)<<""<<treePtr->get_value()<<endl;
  printTree(treePtr->move_left(),1+l);
}
  // TreeNodePtr treePtr=rootPtr;
        // end if
} // end function


void postOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    postOrder(treePtr->move_left());
    postOrder(treePtr->move_right());
    cout<<setw(3)<<treePtr->get_value();
 
 
   
  }                                          // end if
} // end function

void kill(TreeNodePtr treePtr) {
  // TreeNodePtr 
  if(treePtr){
    kill(treePtr->move_left());   // delete left subtree first
    kill(treePtr->move_right());  // delete right subtree next
    delete treePtr;     
    }                                          // end if
} // end function

void preOrder(TreeNodePtr treePtr){
  if(treePtr){
    cout << setw(3) << treePtr->get_value(); 
    preOrder(treePtr->move_left());
    preOrder(treePtr->move_right());
  }                                          // end if
} // end function

