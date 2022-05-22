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


vector<vector<int>> bfs(node* root){
		queue<node*> q;
		vector<vector<int>> v;
	    if(!root)
	    	return v;
		q.push(root);
		while(!q.empty()){
			int s = q.size();
			vector<int> tmp;
			for(int i=0;i<s;i++){
				node* val = q.front();
				q.pop();
				if(val->l !=0)
			       q.push(val->l);
			    if(val->r != 0)
				   q.push(val->r);
				tmp.push_back(val->d);
			}
			v.push_back(tmp);
		}
		return v;
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
	vector<vector<int>> v;
    v = bfs(root);
    for(int i=0;i<v.size();i++){
    	for(auto x: v[i])
    		cout<<x<<" ";
    }
    
	return 0;
}