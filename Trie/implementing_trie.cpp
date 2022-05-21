//IMPLEMENTATION OF TRIE


#include<bits/stdc++.h>
using namespace std;

struct node{
	bool f = 0;
	node *a[26];

	bool check(char c){
		return (a[c-'a'] != NULL);
	}

	void put(char c,node* node){
          a[c-'a'] = node;
	}

	node* nxtpos(char c){
		return a[c - 'a'];
	}

	void setf(){
		f = 1;
	}

	int isset()
	    {return f==1;}
};

node* root = new node();


void insert(string w){
	node* tmp = root;
	for(int i=0;i<w.size();i++){
		if(!(tmp->check(w[i]))){
			node *nwnode= new node();
			tmp->put(w[i],nwnode);
	    }
	    tmp=tmp->nxtpos(w[i]);
		}

    tmp->setf();
}


bool search(string w){
	node* it = root;
	for(int i=0;i<w.size();i++){
		if(it->check(w[i])){
			it = it->nxtpos(w[i]);
		}
		else
			return 0;
		}
	if(it->isset())
		return 1;
	return it->isset();
}

bool startswith(string s){
	node* tmp = root;
	for(int i=0;i<s.size();i++){
       if(tmp->check(s[i])){
       	 tmp = tmp->nxtpos(s[i]);
       }
       else
       	return 0;
	}
	return 1;
}

int main(){
	
	insert("word");
	insert("worf");
	insert("hello");
	cout<<search("word");
	cout<<startswith("wwhjbd");

}