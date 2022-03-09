#include <iostream>
#include<string>
using namespace std;
class dictionary;
class node
{
     string word,meaning;
     node *left,*right;
    public:
     friend class dictionary;
     node()
     {
      left=NULL;
      right=NULL;

     }
     node(string word, string meaning)
     {
      this->word=word;
      this->meaning=meaning;
      left=NULL;
      right=NULL;
     }
};

class dictionary
{
     node *root;
    public:
     dictionary()
    {
      root=NULL;
    }
     void create();
     void inorder_rec(node *rnode);
     void postorder_rec(node *rnode);
     void inorder()
     {
      inorder_rec(root);
     }
     void postorder();

     bool insert(string word,string meaning);
     int search(string key);

};
int dictionary::search(string key)
{
     node *tmp=root;
     int count;
     if(tmp==NULL)
     {
      return -1;
     }
     if(root->word==key)
      return 1;
     while(tmp!=NULL)
     {

      if((tmp->word)>key)
      {
       tmp=tmp->left;
       count++;
      }
      else if((tmp->word)<key)
      {
       tmp=tmp->right;
       count++;
      }
      else if(tmp->word==key)
      {
       return ++count;
      }
     }
     return -1;

}
void dictionary::postorder()
{
    postorder_rec(root);
}
void dictionary::postorder_rec(node *rnode)
{
     if(rnode)
     {
      postorder_rec(rnode->right);
      cout<<" "<<rnode->word<<" : "<<rnode->meaning<<endl;
      postorder_rec(rnode->left);
     }
}
void dictionary::create()
{
     int n;
     string wordI,meaningI;
     cout<<"\n How many Word to insert?:\n";
     cin>>n;
     for(int i=0;i<n;i++)
     {
      cout<<"\n Enter Word: ";
      cin>>wordI;
      cout<<"\n Enter Meaning: ";
      cin>>meaningI;
      insert(wordI,meaningI);
     }
}
void dictionary::inorder_rec(node *rnode)
{
     if(rnode)
     {
      inorder_rec(rnode->left);
      cout<<" "<<rnode->word<<" : "<<rnode->meaning<<endl;
      inorder_rec(rnode->right);
     }
}
bool dictionary::insert(string word, string meaning)
{
     node *p=new node(word, meaning);
     if(root==NULL)
     {
      root=p;
      return true;
     }
     node *cur=root;
     node *par=root;
     while(cur!=NULL) //traversal
     {
      if(word>cur->word)
      {par=cur;
      cur=cur->right;
      }
      else if(word<cur->word)
      {
       par=cur;
       cur=cur->left;
      }
      else
      {
       cout<<"\n Word is already in the dictionary.";
       return false;
      }
     }
     if(word>par->word) //insertion of node
     {
      par->right=p;
      return true;
     }
     else
     {
      par->left=p;

      return true;
     }
}

int main()
{
     string word;
     dictionary months;
     int ch;
     char ch3;
     do
     {
             cout<<"\nEnter your choice:\n1.Create\n2.Sorting\n3.Search\n4.Remove\n5.Exit\n";
             cin>>ch;
             switch(ch)
             {
                 case 1:months.create();
                    break;
                case 2: cout<<"\nEnter your choice\n1. Ascending order \n2.Descending Order\n";
                        int ch1;
                        cin>>ch1;
                        switch(ch1)
                        {
                        case 1: cout<<"\n Ascending order\n";
                                months.inorder();
                                break;
                        case 2: cout<<"\n Descending order:\n";
                                months.postorder();
                                break;
                        }
                break;
                case 3: {cout<<"\n Enter word to search: ";
                         cin>>word;
                         int comparisons=months.search(word);
                         if(comparisons==-1)
                         {
                          cout<<"\n Not found word";
                         }
                         else
                         {
                          cout<<"\n "<<word<<" found in "<<comparisons<<" comparisons";
                         }}
                break;
                case 4: cout<<"";
                break;

             }
             cout<<"\nDo you want to continue??\n";
             cin>>ch3;
     }while(ch3=='y');



     return 0;
}
