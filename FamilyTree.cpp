#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "FamilyTree.hpp"
#include <stdio.h>

using namespace std;

namespace family{



    Tree &Tree::addFather(string son_name, string father_name)
    {
        cout<<"\naddFather"<<"\nson_name: "<<son_name<<"\nfather_name: "<<father_name<<endl;

         Node *iterSon=findNode(son_name, this->root);
         if (iterSon==nullptr){
            cout<<"Exception: "<<"(!findNode(son_name, this->root, iterSon)"<<endl;
            string ex="son not found";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        // cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;
        cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;

        //בדיקה שהפויינטר לא ריק
        if (iterSon == nullptr){
            cout<<"Exception: "<<"iterSon == nullptr"<<endl;
            string ex="Must have root to the tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //בדיקה שאין לו אבא
        if (iterSon->father != nullptr){
            cout<<"Exception: "<<"iterSon->father != nullptr)"<<son_name<<father_name<<"  "<<iterSon->father->name<<endl;
            string ex="Son have a father";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //יצירת חוליה חדשה עם הפרטים של האבא
        Node *father = new Node(father_name,(iterSon->level)+1,1);
        //הפניית המצביע של חוליית האבא של הילד על החולייה החדשה
        iterSon->father = father;
        this->items.push_back(father);
        cout<<"-----------------------------"<<endl;
        return *this;
    };

     Node* Tree::findNode(string name, Node *iter){
        cout<<"\n\nfindNode->"<<name<<endl;

        list <Node*> :: iterator it; 

        for(it = this->items.begin(); it != this->items.end(); it++){
            cout<<"(*it)->name: "<<(*it)->name<<endl;

            if((*it)->name.compare(name)==0){
                cout<<"I find node with name: "<<(*it)->name<<endl;
                // iterSon=*it;
                return *it;
            } 
        }
        return nullptr;
     }

    Tree &Tree::addMother(string son_name, string mom_name)
    {
        cout<<"\naddMother"<<"\nson_name: "<<son_name<<"\nmom_name: "<<mom_name<<endl;
        Node *iterSon=findNode(son_name, this->root);
        if (iterSon==nullptr){
            cout<<"Exception: "<<"(!findNode(son_name, this->root, iterSon)"<<endl;
            string ex="son not found";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        // cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;
        cout<<"\nson name after return from findNode: "<<iterSon->name<<endl;

        //בדיקה שהפויינטר לא ריק
        if (iterSon == nullptr){
            cout<<"Exception: "<<"iterSon == nullptr"<<endl;
            string ex="Must have root to the tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //בדיקה שאין לו אמא
        if (iterSon->mother != nullptr){
            cout<<"Exception: "<<"iterSon->mother != nullptr"<<endl;
            string ex="Son have a mother";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        //יצירת חוליה חדשה עם הפרטים של האמא
        Node *mother = new Node(mom_name,(iterSon->level)+1,2);
        //הפניית המצביע של חוליית האמא של הילד על החולייה החדשה
        iterSon->mother = mother;
        this->items.push_back(mother);

        cout<<"-----------------------------"<<endl;
        return *this;
    };

    void Tree::display(){

    };

    string Tree::relation(string name){
        //בדיקה שהאיש קיים והחזרה של מצביע עליו
        cout<<"\n\n\n----------------------------"<<endl;
        cout<<"relation: "<<name<<endl;
        Node *iter = findNode(name, this->root);
        if (iter==nullptr)
           return "unrelated";
        else
        {
            int level=iter->level;
            string gender = "";
            cout<<"name: "<<iter->name<<"\ngender: "<<iter->gender<<endl;
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
        cout<<"\n\n\n----------------------------"<<endl;
        cout<<"find: "<<kirva<<endl;

        //בדיקה שקיבלתי מחרוזת תקינה
         vector<string> v1=split(kirva,false);
            for(int i=0;i<v1.size();i++){ //מעבר על הוקטור של המילים
                string temp=v1[i];
                cout<<"temp: "<<temp<<endl;
                std::transform(temp.begin(), temp.end(),temp.begin(), ::tolower);
                if(temp.compare("me")!=0 && temp.compare("father")!=0 && temp.compare("mother")!=0 && temp.compare("grandmother")!=0 && temp.compare("grandfather")!=0 && temp.compare("great")!=0){
                    cout<<"exception: temp.compare(me)!=0 || temp.compare(father)!=0 || temp.compare(mother)!=0 || temp.compare(grandmother)!=0 || temp.compare(grandfather)!=0 || temp.compare(great)!=0"<<endl;
                    string ex="The tree cannot handle the '";
                    ex.append(kirva);
                    ex.append("' relation");
                    const char * c = ex.c_str();
                    __throw_runtime_error(c);
                }
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
            int len=kirva.length()-6;
            char suffix=kirva.at(len);
            string pattern="great";
            int countGreat=countFreq(pattern, kirva);
            list <Node*> :: iterator it; 

            for(it = this->items.begin(); it != this->items.end(); ++it){
                 if((*it)->level==countGreat+2) return (*it)->name;
            }
        }
        return "There is no generation like this in this tree";
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
        for(it = this->items.begin(); it != this->items.end(); ++it){
            if((*it)->name==name){
                temp=(*it);
                break;
            } 
        }
        if(temp==nullptr){
            string ex="Cant remove name that isnt exist in tree";
            const char * c = ex.c_str();
            __throw_runtime_error(c);
        }
        if(temp->father!=nullptr)
            remove(temp->father->name);
        if(temp->mother!=nullptr)
            remove(temp->mother->name);

        this->items.remove(temp);
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


