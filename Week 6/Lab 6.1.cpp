
#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *left , *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *insert(Node *root, int x)
{
    if (root == NULL){
        return new Node(x);
    }
    if (x < root->data){
        root->left = insert(root->left, x);
    }
    else if (x > root->data){
        root->right = insert(root->right, x);
    }
    return root;        
}

Node *lca(Node *root, int n1, int n2){

    if (root == NULL){
        return NULL;
    }
        
    if (root->data > n1 && root->data > n2) {
        return lca(root->left, n1, n2);
    }
        
    else if (root->data < n1 && root->data < n2){
        return lca(root->right, n1, n2);
    }

    else{
        return root;
    }
}

int main(){

    Node*root = NULL;
    int n;

    cin >> n;

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int n1, n2;
    cin >> n1 >> n2;

    Node *ans = lca(root, n1, n2);

    if (ans == NULL){
        cout << "Invalid Input" << endl;
    }
     else{
        cout << ans->data << endl;
     }


}