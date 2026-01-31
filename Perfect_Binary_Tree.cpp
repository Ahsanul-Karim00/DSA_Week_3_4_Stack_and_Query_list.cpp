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

int max_height(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
       return 1; 
    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l,r) + 1;       
}

int count_total_nodes(Node* root)
{
    //base case
    if(root == NULL) 
        return 0;
    int l = count_total_nodes(root->left);
    int r = count_total_nodes(root->right);
    return l+r+1;  //left+right+root   

}

int main()
{
    Node* root = input_tree();
    // cout << count_total_nodes(root)<<endl;
    // cout << max_height(root)<<endl;
    int Total_number_of_nodes = pow(2,max_height(root)) -1;
    int count = count_total_nodes(root);
    if(count == Total_number_of_nodes)
        cout << "YES"<< endl;
    else 
       cout << "NO" << endl;    
    return 0;
}

