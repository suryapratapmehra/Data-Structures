#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
struct node{
	int l, r, data;
	node* left;
	node* right;
};

node* buildNode(int data, int l, int r){
	node* temp=new node();
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	temp->l=l;
	temp->r=r;
	return temp;
}

void buildTree(node* root){
	if(root->l==root->r)
		return;
	if(((root->l+root->r)/2)>=root->l){
		root->left=buildNode(0, root->l, ((root->l+root->r)/2));
		buildTree(root->left);
	}
	if((root->r)>=((root->l+root->r)/2+1)){
		root->right=buildNode(0,(root->l+root->r)/2+1, root->r);
		buildTree(root->right);
	}
}

void postOrder(node* root){
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" "<<root->l<<" "<<root->r<<endl;
}

void update (node* root, int index, int value){
	if(index < root->l || index > root->r)
		return;
	if(root->l == index && root->r == index){
		root->data = value;
		return;//take care of the updation shit
	}

	else if((root->left)->l <= index && (root->left)->r >= index){
		update(root->left, index, value);
	}

	else if((root->right)->l <= index && (root->right)->r >=index){
		update(root->right, index, value);
	}

	if(root->left == NULL && root->right == NULL)
		return;

	else if(root->left == NULL && root->right != NULL){
		root->data = (root->right)->data;
		return;
	}
	else if(root->left !=NULL && root->right == NULL){
		root->data = (root->left)->data;
		return;
	}
	else if(root->left !=NULL && root->right !=NULL){
		if((root->left)->data < (root->right)->data)
			root->data = (root->left)->data;
		else
			root->data = (root->right)->data;
		return;
 	}
}

int query (node* root, int l, int r){
	

}

int main(){
	int n;
	cin>>n;
	node* root=buildNode(0,1,n);
	buildTree(root);
	update(root,4,1);
	postOrder(root);
	return 0;
}