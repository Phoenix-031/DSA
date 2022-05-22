
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

vector<int> it_preorder(node* root){
	stack<node*> s;
	s.push(root);
	vector<int> v;
	while(!s.empty()){
        node* tmp = s.top();
		s.pop();
		v.push_back(tmp->d);
		if(tmp->r != NULL)
		  s.push(tmp->r);
		if(tmp->l != 0)
		  s.push(tmp->l);
	}
	return v;
}

stack<node*> it_postorder(node* root){
	stack<node* >s1,s2;
	s1.push(root);
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
		if(s2.top()->l != 0)
		  s1.push(s2.top()->l);
		if(s2.top()->r != 0)
		  s1.push(s2.top()->r);
	}
	return s2;

}

vector<int> it_inorder(node* root){
	node* tmp = root;
	vector<int> v;
	stack<node*> s;
	while(1){
		if(tmp != 0){
			s.push(tmp);
			tmp = tmp->l;
		}
		else{
			if(s.empty())
				break;
			tmp = s.top();
			s.pop();
            v.push_back(tmp->d);
            tmp = tmp->r;
		}
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
    vector<int> v1;
    v1 = it_preorder(root);
    for(auto x:v1)
    	cout<<x<<" ";
    
    stack<node*> s;
    s = it_postorder(root);
    while(!s.empty()){
    	cout<<s.top()->d<<" ";
    	s.pop();
    }

    vector<int> v2 = it_inorder(root);
    for(auto x:v2)
    	cout<<x<<" ";

	return 0;
}
