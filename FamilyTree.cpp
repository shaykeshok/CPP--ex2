#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "FamilyTree.hpp"
#include <stdio.h> 

using namespace std;
 
 namespace family{

//      Tree &addFather(string son_name, string father_name){

//      };
//      void insert(string key){
// 	if(root != NULL){
// 		insert(key, root);
// 	}else{
// 		root = new Node;
// 		root->value = key;
// 		root->left = NULL;
// 		root->right = NULL;
// 	}
// }

    Tree &Tree::addFather(string son_name, string father_name){
        return *this;
    };

    Tree &Tree::addMother(string son_name, string mom_name){
        return *this;
    };

    void Tree::display(){

    };

    string Tree::relation(string name){
        return "";
    };

    string Tree::find(string name){
        return "";
    };

    void Tree::remove(string name){

    };

}