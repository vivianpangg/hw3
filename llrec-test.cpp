#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

// /**
//  * Reads integers (separated by whitespace) from a file
//  * into a linked list.
//  *
//  * @param[in] filename
//  *  The name of the file containing the data to read
//  * @return
//  *  Pointer to the linked list (or NULL if empty or the
//  *  file is invalid)
//  */
// Node* readList(const char* filename){
//   ifstream file(filename);

//   if(!file){
//     return nullptr;
//   }

//   Node* head = nullptr; //start of linked list
//   int num;
//   while(file>>num){
//     //create a new temp node with the new value
//     Node* newNode = new Node(num);

//     // if the very start of the list, make the first node the head
//     if(head ==nullptr){
//       head = newNode;
//     //if not start of list, loop to the end of linked list and add new node
//     }else{
//       Node* currentNode = head;
//       while(currentNode->next != nullptr){
//         currentNode = currentNode->next;
//       }
//       currentNode->next = newNode;
//     }
    
//   }

//   file.close();

//   //return the head of the linked list with all the data
//   return head;
// }

// /**
//  * Prints the integers in a linked list pointed to
//  * by head.
//  */
// void print(Node* head){
//   Node* temp =head;
//   while(temp != nullptr){
//     cout<< temp->val <<" ";
//     temp = temp->next;
//   }
//   cout<<endl;
// }

// /**
//  * Deallocates the linked list nodes
//  */
// void dealloc(Node* head){
//   while(head !=nullptr){
//     Node* temp = head;
//     head = head->next;
//     delete temp;
    
//   }
// }


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code



    
    return 0;

}
