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

int sum_leaf_nodes(Node* root)
{
    //base case
    if(root == NULL) 
        return 0;
    if(root->left ==NULL && root->right == NULL)
        return root->val;  
    int l = sum_leaf_nodes(root->left);
    int r = sum_leaf_nodes(root->right);
    return l+r;  //left+right+root   

}
int sum_total_nodes(Node* root)
{
    //base case
    if(root == NULL) 
        return 0;
    int l = sum_total_nodes(root->left);
    int r = sum_total_nodes(root->right);
    return l+r +root->val;  //left+right+root   

}

int main()
{
    Node* root = input_tree();
    cout << sum_total_nodes(root) - sum_leaf_nodes(root) << endl;

    return 0;
}

