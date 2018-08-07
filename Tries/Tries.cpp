#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
private:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*> childmap;
public:
    TrieNode(char ch){
        data=ch;
        isTerminal=false;
    }
    friend class Trie;
};

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root=new TrieNode('\0');
    }
    void AddWord(char word[], TrieNode* rt){
        if (word[0]=='\0') {
            rt->isTerminal=true;
            return;
        }
        char ch=word[0];
        auto it=rt->childmap.find(ch);
        if(it==rt->childmap.end()){
            TrieNode* newChild=new TrieNode(ch);
            rt->childmap[ch]=newChild;
        }
        AddWord(word+1,rt->childmap[ch]);
    }
    void AddWord(char word[]){
        AddWord(word,root);
    }
    bool Search(char word[]){
        TrieNode *temp =root;
        for (int i=0;word[i]!='\0';i++){
            char ch=word[i];
            auto it=temp->childmap.find(ch);
            if (it==temp->childmap.end()) return false;
            temp=it->second;
        }
        if (temp->isTerminal==true) return true; else return false;
    }
};

int main(){
    Trie t;
    t.AddWord("are");
    t.AddWord("ant");
    t.AddWord("cow");
    t.AddWord("dog");
    t.AddWord("an");
    cout<<t.Search("are")<<endl;
    cout<<t.Search("test")<<endl;
    cout<<t.Search("an")<<endl;
    cout<<t.Search("do")<<endl;

}
