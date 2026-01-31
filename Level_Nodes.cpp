#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node *left;
        Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree()
{
    int val;
    cin >> val;
    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);
    
    queue<Node*>q ;
    if(root != NULL) q.push(root);

    while(!q.empty())
    {
        Node* p = q.front(); // root ber kora
        q.pop();

        int l ,r; // input 2 node
        cin >> l >> r;
        Node *myleft ,*myright;

        if(l == -1) myleft = NULL; // oi node er kaj
        else myleft = new Node(l);

        if(r == -1) myright = NULL;
        else myright = new Node(r);


        p->left = myleft;  //connetion
        p->right = myright;

        if(p->left)
           q.push(p->left);
        if(p->right)
           q.push(p->right);   

    }
    return root;

}

void level_order(Node* root,int x)
{
    if(root == NULL)
    {
        cout << "Invalid" << endl;
        return;
    }
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        //1 ber kore ana;
        Node* f = q.front().first;
        int level = q.front().second;
        q.pop();

        //2 oi Node ke niya kaj
        if(level == x)
            cout << f->val << " ";

        //3 children push kora
        if(f->left != NULL)
           q.push({f->left,level+1});
        if(f->right != NULL)
           q.push({f->right,level+1}); 

    }
}

int max_height(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
       return 0; 
    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l,r) + 1;       
}


int main()
{
    Node* root = input_tree();
    int x;
    cin >> x;
    int max_he = max_height(root);
    if(x>max_he)
       cout << "Invalid" << endl;
    level_order(root,x);
    

    return 0;
}

