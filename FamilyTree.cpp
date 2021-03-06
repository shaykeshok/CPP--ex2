#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "FamilyTree.hpp"
#include <stdio.h>

using namespace std;

namespace family{



    Tree &Tree::addFather(string son_name, string father_name)
    {
        // cout<<"\naddFather"<<"\nson_name: "<<son_name<<"\nfather_name: "<<father_name<<endl;

         Node *iterSon=findNode(son_name, this->root);
         if (iterSon==nullptr){
            // cout<<"Exception: "<<"(!findNode(son_name, this->root, iterSon)"<<endl;
            string ex="son not found";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        // cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;
        // cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;

        //בדיקה שהפויינטר לא ריק
        if (iterSon == nullptr){
            // cout<<"Exception: "<<"iterSon == nullptr"<<endl;
            string ex="Must have root to the tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //בדיקה שאין לו אבא
        if (iterSon->father != nullptr){
            // cout<<"Exception: "<<"iterSon->father != nullptr)"<<son_name<<father_name<<"  "<<iterSon->father->name<<endl;
            string ex="Son have a father";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //יצירת חוליה חדשה עם הפרטים של האבא
        Node *father = new Node(father_name,(iterSon->level)+1,1);
        //הפניית המצביע של חוליית האבא של הילד על החולייה החדשה
        iterSon->father = father;
        //הוספת האבא לרשימה של הnodes
        this->items.push_back(father);
        //הגדלת השלב של העץ
        if(this->level<father->level) this->level=father->level;
        // cout<<"-----------------------------"<<endl;
        return *this;
    };

     Node* Tree::findNode(string name, Node *iter){
        // cout<<"\n\nfindNode->"<<name<<endl;

        list <Node*> :: iterator it; 

        for(it = this->items.begin(); it != this->items.end(); it++){
            // cout<<"(*it)->name: "<<(*it)->name<<endl;

            if((*it)->name.compare(name)==0){
                // cout<<"I find node with name: "<<(*it)->name<<endl;
                // iterSon=*it;
                return *it;
            } 
        }
        return nullptr;
     }

    Tree &Tree::addMother(string son_name, string mom_name)
    {
        // cout<<"\naddMother"<<"\nson_name: "<<son_name<<"\nmom_name: "<<mom_name<<endl;
        Node *iterSon=findNode(son_name, this->root);
        if (iterSon==nullptr){
            // cout<<"Exception: "<<"(!findNode(son_name, this->root, iterSon)"<<endl;
            string ex="son not found";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        // cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;
        // cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;

        //בדיקה שהפויינטר לא ריק
        if (iterSon == nullptr){
            // cout<<"Exception: "<<"iterSon == nullptr"<<endl;
            string ex="Must have root to the tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //בדיקה שאין לו אמא
        if (iterSon->mother != nullptr){
            // cout<<"Exception: "<<"iterSon->mother != nullptr"<<endl;
            string ex="Son have a mother";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //יצירת חוליה חדשה עם הפרטים של האמא
        Node *mother = new Node(mom_name,(iterSon->level)+1,2);
        //הפניית המצביע של חוליית האמא של הילד על החולייה החדשה
        iterSon->mother = mother;
        //הוספת האמא לרשימה של הnodes
        this->items.push_back(mother);
        //הגדלת השלב של העץ
        if(this->level<mother->level) this->level=mother->level;
        // cout<<"-----------------------------"<<endl;
        return *this;
    };

    void Tree::display(){
        if(this->root==nullptr){
            string ex="There isn't root to this tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        print_tree_structure(this->root,5);
    };
  
void Tree::print_tree_structure(Node* iter, int spaces)
{
  if(iter != NULL)
  {
    print_tree_structure(iter->father, spaces + 5);
    for(int i = 0; i < spaces; i++)
      	cout << ' ';
    	cout << "   " << iter->name << endl;
    print_tree_structure(iter->mother, spaces + 5);
  }
}
    string Tree::relation(string name){
        //בדיקה שהאיש קיים והחזרה של מצביע עליו
        // cout<<"\n\n\n----------------------------"<<endl;
        // cout<<"relation: "<<name<<endl;
        Node *iter = findNode(name, this->root);
        if (iter==nullptr)
           return "unrelated";
        else
        {
            int level=iter->level;
            string gender = "";
            // cout<<"name: "<<iter->name<<"\ngender: "<<iter->gender<<endl;
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
        if(root==nullptr){
            string ex="There is no root to the tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //  cout<<"\n\n\n----------------------------"<<endl;
        //  cout<<"find: "<<kirva<<endl;

        //בדיקה שקיבלתי מחרוזת תקינה
        vector<string> v1=split(kirva,false);
        for(int i=0;i<v1.size();i++){ //מעבר על הוקטור של המילים
            string temp=v1[i];
            // cout<<"temp: "<<temp<<endl;
            std::transform(temp.begin(), temp.end(),temp.begin(), ::tolower);
            if(temp.compare("me")!=0 && temp.compare("father")!=0 && temp.compare("mother")!=0 && temp.compare("grandmother")!=0 && temp.compare("grandfather")!=0 && temp.compare("great")!=0){
                string ex="The tree cannot handle the '";
                ex.append(kirva);
                ex.append("' relation");
                const char * c = ex.c_str();
                __throw_runtime_error(c);
            }
        }
        // cout<<"check1"<<endl;
        if (kirva.compare("me") == 0){
            // cout<<"in me"<<endl;
            if(root!=nullptr)
                return root->name;
        }
        else if (kirva.compare("father") == 0){
            // cout<<"in father"<<endl;
            if(root->father!=nullptr)
                return root->father->name;
        }
        else if (kirva.compare("mother") == 0 ){
            // cout<<"in mother"<<endl;
            if(root->mother!=nullptr)
                return root->mother->name;
        }
        else if (kirva.compare("grandmother") == 0){
            // cout<<"in grandmother"<<endl;
            if(root->mother!=nullptr)
                if(root->mother->mother!=nullptr)
                    return root->mother->mother->name;
            if(root->father!=nullptr)
                if(root->father->mother!=nullptr)
                    return root->father->mother->name;           
        }
        else if (kirva.compare("grandfather") == 0){
            // cout<<"in grandfather"<<endl;
            if(root->mother!=nullptr)
                if(root->mother->father!=nullptr)
                    return root->mother->father->name;
            if(root->father!=nullptr)
                if(root->father->father!=nullptr)
                    return root->father->father->name;
        }
        else{
            // cout<<"check2"<<endl;
            int len=kirva.length()-6;
            char suffix=kirva.at(len);
            int gender=0;
            if(suffix=='f')gender=1;
            else
                gender=2;
            
            
            // cout<<suffix<<endl;
            string pattern="great";
            int countGreat=countFreq(pattern, kirva);
            // cout<<countGreat<<endl;

            list <Node*> :: iterator it; 

            for(it = this->items.begin(); it != this->items.end(); ++it){
                 if((*it)->level==countGreat+2 && (*it)->gender==gender) return (*it)->name;
            }
        }
        // cout<<"check3"<<endl;
        string ex="There is no generation like this in this tree";
        const char * c = ex.c_str();
        __throw_runtime_error(c);
        return "There is no generation like this in this tree";
    };
    void Tree::print(){
        list <Node*> :: iterator it; 

        for(it = this->items.begin(); it != this->items.end() ; ++it){
            	cout<<"name:" <<(*it)->name<<endl;

        }
    };
    void Tree::remove(string name){
        //בדיקה שלא מנסים למחוק את השורש של העץ
        if(root->name.compare(name)==0){
            string ex="Remove the root of the tree is impossible";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        list <Node*> :: iterator it; 
        Node* temp=nullptr;
        Node* tempparent=nullptr;
        for(it = this->items.begin(); it != this->items.end() ; ++it){
            // cout<<"name: "<<(*it)->name<<endl;
            //cout<<"father-name: "<<(*it)->father->name<<endl;

            if((*it)->name.compare(name)==0){
                // cout<<"(*it)->name.compare(name)==0)"<<endl;
                // cout<<"inner name: "<<(*it)->name<<endl;
                temp=(*it);
                break;
            } 
        }
        if(temp==nullptr){
            string ex="Cant remove name that isnt exist in tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        if(temp->father!=nullptr){
            // cout<<"have father"<<endl;
            remove(temp->father->name);
        }

        if(temp->mother!=nullptr){
            // cout<<"have mother"<<endl;
            remove(temp->mother->name);
        }
         for(it = this->items.begin(); it != this->items.end() ; ++it){

            if((*it)->father==temp ){
                (*it)->father=nullptr;
                break;
            } 
            if((*it)->mother==temp){
                (*it)->mother=nullptr;
                break;
            }
        }
        // cout<<"remove: "<<temp->name<<endl;
        this->items.remove(temp);
        // cout<<"free: "<<temp->name<<endl;
        free(temp);

    };
    vector<string> split(string text, bool caseSen){
        string delimiter = "-";
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
    };
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
    };
}


