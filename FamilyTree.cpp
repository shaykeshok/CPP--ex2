#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "FamilyTree.hpp"
#include <stdio.h>
#include <vector>

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

    Tree &Tree::addFather(string son_name, string father_name)
    {
        Node *iterSon = root;
        int generation = 0;
        //בדיקה שהילד קיים והחזרה של מצביע עליו
        if (!findNode(son_name, this->root, iterSon))
            throw "son not found";
        //בדיקה שהפויינטר לא ריק
        if (iterSon == nullptr)
            throw "Must have root to the tree";
        //בדיקה שאין לו אבא
        if (iterSon->father != nullptr)
            throw "Son have a father";
        //יצירת חוליה חדשה עם הפרטים של האבא
        Node *father = new Node(father_name,iterSon->level+1);
        //הפניית המצביע של חוליית האבא של הילד על החולייה החדשה
        iterSon->father = father;
        return *this;
    };
    //func that find if the node we want to add him parent is exist and if is exist
    //the func return true and we have pointer to the node
    //bool Tree::findNode(string name, Node *iter, Node *iterSon, int &generation)
    bool Tree::findNode(string name, Node *iter, Node *iterSon)
    {
        if (iter == nullptr)
        {
            return false;
        }
        if (name.compare(iter->name) == 0)
        {
            iterSon = iter;
            return true;
        }
        else
        {
            //generation += 1;
            if (findNode(name, iter->father, iterSon))
                return true;
            if (findNode(name, iter->mother, iterSon))
                return true;
        }
        return false;
    }

    Tree &Tree::addMother(string son_name, string mom_name)
    {
        Node *iterSon = root;
        //בדיקה שהילד קיים והחזרה של מצביע עליו
        if (findNode(son_name, this->root, iterSon))
            throw "son not found";
        //בדיקה שהפויינטר לא ריק
        if (iterSon == nullptr)
            throw "Must have root to the tree";
        //בדיקה שאין לו אמא
        if (iterSon->mother != nullptr)
            throw "Son have a mother";
        //יצירת חוליה חדשה עם הפרטים של האמא
        Node *mother = new Node(mom_name,iterSon->level+1);
        //הפניית המצביע של חוליית האמא של הילד על החולייה החדשה
        iterSon->mother = mother;
        return *this;
    };

    void Tree::display(){

    };

    string Tree::relation(string name){
        Node *iter = root;
        // int generation = 0;
        //בדיקה שהאיש קיים והחזרה של מצביע עליו
        if (!findNode(name, this->root, iter))
            throw "Not found";
        else
        {
            int level=iter->level;
            string gender = "";
            if (iter->gender == 1)
                gender = "father";
            else
                gender = "mother";

            switch (level)
            {
            case 0: //me
                return "me";
                break;
            case 1: //father or mother
                return gender;
                break;
            case 2: //grandmother or grandfather
                return "grand" + gender;
                break;
            default: //great...
                string greatStr = "";
                for (int i = 3; i <= level; i++)
                {
                    greatStr = greatStr + "great-";
                }
                return greatStr + "grand" + gender;
                break;
            }
        }
        return "";
    };

    string Tree::find(string kirva){
        //בדיקה שקיבלתי מחרוזת תקינה
         vector<string> v1=split(kirva,false);
            for(int i=0;i<v1.size();i++){ //מעבר על הוקטור של המילים
                string temp=v1[i];
                std::transform(temp.begin(), temp.end(),temp.begin(), ::tolower);
                if(temp.compare("me")!=0 || temp.compare("father")!=0 || temp.compare("mother")!=0 || temp.compare("grandmother")!=0 || temp.compare("grandfather")!=0 || temp.compare("great")!=0)
                    throw "The tree cannot handle the '" + kirva + "' relation";
            }
                        
        if (kirva.compare("me") == 0)
            return root->name;
        else if (kirva.compare("father") == 0)
            return root->father->name;
        else if (kirva.compare("mother") == 0)
            return root->mother->name;
        else if (kirva.compare("grandmother") == 0)
            return root->mother->mother->name;
        else if (kirva.compare("grandfather") == 0)
            return root->mother->father->name;
        else{
            char suffix=kirva.at(kirva.length-6);
            string pattern="great";
            int countGreat=countFreq(pattern, kirva);
            list <Node*> :: iterator it; 

            for(it = this->items.begin(); it != this->items.end(); ++it){
                 if((*it)->level==countGreat+2) return (*it)->name;
            }
            // switch (countGreat){
                // case 1: //great grnadfather or grnadmother
                //     if
                //     break;
                // case 2: //great-great grnadfather or grnadmother
                //     return "grand" + gender;
                //     break;
                // default: //great...
                    // string greatStr = "";
                    // for (int i = 3; i <= generation; i++)
                    // {
                    //     greatStr = greatStr + "great-";
                    // }
                    // return greatStr + "grand" + gender;
                    // break;
            // }
        }
        return "There is no generation like this in this tree";
    };

    void Tree::remove(string name){

    };
}
vector<string> split(string text, bool caseSen){
        string delimiter = " ";
        vector<string> data;

        size_t pos = 0;
        string token;
        if(caseSen) std::transform(text.begin(), text.end(),text.begin(), ::tolower);
        while ((pos = text.find(delimiter)) != std::string::npos) {
            token = text.substr(0, pos);
            data.push_back(token);
            text.erase(0, pos + delimiter.length());
        }
        data.push_back(text);
        return data;
    }
//copy from 'https://www.geeksforgeeks.org/frequency-substring-string/'
int countFreq(string &pat, string &txt){
    int M = pat.length();
    int N = txt.length();
    int res = 0;

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        /* For current index i, check for  
        pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M)
        {
            res++;
            j = 0;
        }
    }
    return res;
}
