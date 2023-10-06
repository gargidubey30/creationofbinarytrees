
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;
#include <queue>

class node{
    public:
    int data;
    node* left;
    node* right;

    // constructor
     node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
     }

};



void zigZagTraversal(node* root)
    {
    vector<int>result;
    
    if(root==NULL){
        return;
        
    }
        
        queue<node*>q;
        q.push(root);
         bool leftToRight=true; // for direction
         
         while(!q.empty()){
             
             int size=q.size();       //queue ka size nikala
             vector<int> ans(size); //  size ka temp array
             
             //level process
             for(int i=0;i<size; i++){              //loop in all elements of current  queue
                 node* frontNode=q.front();
                 q.pop();
                 
                 //if true normal insert else  reverse insert
                  int index= leftToRight ? i : size - 1 -i;
                  
                  ans[index]= frontNode ->data;
                  
                  if(frontNode ->left)
                  q.push(frontNode ->left);
                  
                      
                  if(frontNode ->right)
                  q.push(frontNode ->right);
                  
                  
                  }
             
             // direction change karo
             leftToRight=!leftToRight;// it will become false
             
             // ans ko store karaya
             for(auto i:ans){               //temporary array se wapas result me daal diya
                 result.push_back(i);   
             }

            //  for(int i=0;i<result.size(); i++){  
            //     cout<<result[i];
               
            //   }
             
         
        }
  
    
    }

void levelOrderTraversal(node *root) // building tree by iteration print the tree
{
     queue<node *> q;
     q.push(root);
     q.push(NULL);

     while (!q.empty())
     {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
     }
}

node* buildTree(node* root){ // building tree by recursion 

    cout<<"Enter the data for the node:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1){// base case 
      return NULL;
    }
  
    cout<<" enter the data for inserting in the left of  "<<data<<endl;
    root->left=buildTree(root->left);// call for left node
    cout<<" enter the data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);// call for right node
    return root;

}

int main(){

    node* root=NULL;

    // creating a tree
    root= buildTree(root);

    // cout<<"printing the level order traversal"<<endl;
    // levelOrderTraversal(root);


 cout<<"printing the zig zag traversal"<<endl;
 zigZagTraversal(root);





	return 0;
}
