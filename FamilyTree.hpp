#include <iostream>
#include <stdexcept>
#include <list> 
#include <iterator> 
#include <vector>
#include <queue>

using namespace std;

namespace family{
  vector<string> split(string text, bool caseSen);
  int countFreq(string &pat, string &txt);

  class Node{
        public:
        string name;
        Node* mother;
        Node* father;
        int level;
        int gender; // 0->root; 1->father; 2->mother
        Node(string name,int level,int gender){
            this->name=name;
            this->mother=nullptr;
            this->father=nullptr;
            this->level=level;
            this->gender=gender;
        }
     };

    class Tree{
        Node* root;

        public:
        list <Node*> items; 
        int level=0;
        Tree(const string& name){
          Node* newNode = new Node(name,0,0);
          newNode->gender=0;
          this->root=newNode;
          items.push_front(newNode);
        };
        Tree &addFather(string son_name, string father_name); 
        Tree &addMother(string son_name, string mom_name);   
        void display();
        string relation(string name);
        string find(string kirva);
        void remove(string name);
        void printTree(Node* node);
        Node* findNode(string name, Node* iter);
        void print_tree_structure(Node* iter, int spaces);
        void print();


    };
};