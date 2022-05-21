//SINGLE LINKED LIST


#include<bits/stdc++.h>
using namespace std;


struct node{
	int d;
	node * nxt;
};

node *head;

void insert_front(int x){
	node *tmp = new node();
	tmp->d = x;
	tmp->nxt = head;
    head = tmp;
}

void insert_end(int x){
	node *tmp = head;
	node *tmp1 = new node();
	tmp1 ->d = x;
	while(tmp->nxt){
		tmp= tmp->nxt;
	}
	tmp->nxt = tmp1;
	tmp1=0;
}

void delete_front(){
	 head = head->nxt;
}

void delete_end(){
	node *tmp = head;
	while(tmp->nxt->nxt)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
}

void prnt(){
	node *tmp = head;
	while(tmp){
		cout<<tmp->d<<" ";
		tmp = tmp->nxt;
	}
}

void prnt_recursive(node * head){
	if(!head)
		return;
	cout<<head->d<<" ";
	prnt_recursive(head->nxt);
}

void reverse_iterative(){
	node *tmp = head;
	node *prev = 0;
	while(tmp){
		node *st = tmp->nxt;
		tmp->nxt = prev;
		prev = tmp;
		tmp = st;
	}
	head = prev;
}

void reverse_recursive(node *add){
	if(add->nxt == 0){
		head = add;
		return;
	}
    reverse_recursive(add->nxt);
    add->nxt->nxt =add;
    add->nxt = 0;
	
}

void delete_at_node(int n){
	node  *tmp = head;
	
	if(n==1){
		head = head->nxt;
	}
	for(int i=1;i<n-1;i++){
		tmp=tmp->nxt;
	}
	tmp->nxt = tmp->nxt->nxt;
}

void insert_at_node(int x,int n){
	node *tmp = head;
	node *nw = new node();
	nw->d = x;
	if(n=1){
       nw->nxt = head;
       head = nw;
	}
	for(int i=1;i<n-1;i++){
		tmp=tmp->nxt;
	}
	nw->nxt = tmp->nxt;
	tmp->nxt = nw;
}


int main(){

    head = NULL;
    insert_front(5);
    insert_front(10);
    insert_end(11);
    prnt_recursive(head);
    prnt();
    reverse_iterative();
    prnt_recursive(head);
    reverse_recursive(head);
    prnt();
    delete_end();
    prnt_recursive(head);
    delete_front();
    prnt();
    delete_at_node(2);
    prnt();
    insert_at_node(2,5);
    prnt();
  
    
	return 0;
}
