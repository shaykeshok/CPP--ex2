#include <iostream>
#include <stdexcept>

using namespace std;

namespace family{
  class Node{
        public:
        string data;
        Node*left;
        Node*right;
        Node(string d){
            data=d;
            left=NULL;
            right=NULL;
        }
     };

    class Tree{
        string root;

        public:
        Tree(const string& name){
          root=name;
        };
        Tree &addFather(string son_name, string father_name); 
        Tree &addMother(string son_name, string mom_name);   
        void display();
        string relation(string name);
        string find(string kirva);
        void remove(string name);
       void insert(string name);
    };
};