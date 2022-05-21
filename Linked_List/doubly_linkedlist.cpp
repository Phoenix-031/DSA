
// DOUBLY LINKED LIST

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int d;
	node* nxt;
	node* prev;
};


node* head;

void insert_front(int x){
	node* tmp = new node();
	tmp->d = x;
	tmp->nxt = head;
	tmp->prev = NULL;
	head=tmp;
}

void inset_at_end(int x){
	node *tmp = new node();
	tmp->d = x;
	node* tmp1 = head;
	while(tmp1->nxt)
		tmp1 = tmp1->nxt;
    tmp->prev = tmp1;
    tmp1->nxt = tmp;
    tmp->nxt = NULL;
}

void delete_front(){
	node* tmp =head;
	head = head->nxt;
	head->nxt->prev = 0;
	delete tmp;
}

void delete_end(){
	node* tmp = head;
	while(tmp->nxt)
		tmp = tmp->nxt;
    tmp->prev->nxt = NULL;
    delete tmp;
}

void insert_at_position(int n,int x){
	node* tmp= head;
	for(int i=0;i<n-1;i++){
		tmp = tmp->nxt;
	}
	node* tmp1 = new node();
	tmp1->d = x;
	tmp1->nxt = tmp->nxt;
	tmp->nxt = tmp1;
	tmp1->prev = tmp;
}

void delete_at_position(int n){
	node* tmp = head;
	for(int i=0;i<n-1;i++)
		tmp=tmp->nxt;
	tmp->nxt = tmp->nxt->nxt;
	
}

void prnt(){
	node* tmp = head;
	while(tmp){
		cout<<tmp->d<<" ";
		tmp = tmp->nxt;
	}
}

int main(){
    head= 0;
    insert_front(1);
    insert_front(10);
    prnt();
    inset_at_end(8);
    insert_at_position(3,97);
    prnt();
    delete_end();
    prnt();
    delete_front();
    prnt();
    insert_at_position(2,10);
    insert_at_position(3,100);
    delete_at_position(2);
    prnt();
    
	return 0;
}