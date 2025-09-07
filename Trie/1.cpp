#include<bits/stdc++.h>
using namespace std;
struct node 
{
    struct node *childern[26];
    bool isend;
    node()
    {
        for(int i=0;i<26;i++)
        {
            childern[i] = nullptr;
        }
        isend = false;
    }   
    struct node* put(char ch,struct node*temp)
    {
        if(temp->childern[ch - 'a'] == nullptr)
        {
                temp->childern[ch - 'a'] = new node();
                return temp->childern[ch - 'a'];
        }
        temp = temp->childern[ch-'a'];
        return temp;
    }
    bool search(string s)
    {
        struct node *temp =this;
        for(int i=0;i<s.length();i++)
        {
            if(temp->childern[s[i]-'a'] == nullptr)
            {
                return false;
            }
            temp = temp->childern[s[i]-'a'];
        }
        return temp->isend;
    }
    void Insert(string s)
    {
        struct node *temp = this;
        for(int i=0;i<s.length();i++)
        {
            temp = temp->put(s[i],temp);
        }
        temp->isend = true;

    }
};
int main()
{
    struct node *Trie = new node();
    Trie->Insert("apple");
    cout<<Trie->search("apple")<<endl;
    return 0;
}