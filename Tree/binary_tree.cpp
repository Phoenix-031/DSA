// BINARY TREE

#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node* l;
	node* r;

	node(int v){
		d = v;
		l=r=0;
	}
};

void preorder(node* root){
	if(!root)
		return;
	cout<<root->d<<" ";
	preorder(root->l);
	preorder(root->r);
}

void inorder(node* root){
	if(!root)
		return;
	inorder(root->l);
	cout<<root->d<<" ";
	inorder(root->r);
}

void postorder(node* root){
	if(!root)
		return;
	postorder(root->l);
	postorder(root->r);
	cout<<root->d<<" ";
}


int main(){

    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->r = new node(10);
    root->r->l = new node(19);
    preorder(root);
    postorder(root);
    inorder(root);
    
	return 0;
}