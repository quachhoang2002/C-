#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

struct Node *createNode(int value)
{
    struct Node *newnode = new Node;    
    newnode->data = value;	 	
    newnode->left = NULL; 		
    newnode->right = NULL;
    return newnode;
}

struct Node *addNode(struct Node *r, int value)
{
	if (r==NULL)
	         return createNode(value);
	else
	{
	         if (value < r->data)
	                     r->left = addNode(r->left, value);
	         else
	                     r->right = addNode(r->right, value);
	         return r;
	}
}

void xuatLNR(Node *r)
{
	if(r!=NULL)
	{
	          xuatLNR(r->left);
	          cout<<r->data<<" ";
	          xuatLNR(r->right);
	}
}

void xuatRNL(Node *r)
{
	if(r!=NULL)
	{
	          xuatRNL(r->right);
	          cout<<r->data<<" ";
	          xuatRNL(r->left);
	}
}

void xuatNLR(Node *r)
{
	if(r!=NULL)
	{
	          if(r!=NULL)
	                     cout<<r->data<<" ";
	          xuatNLR(r->left);
	          xuatNLR(r->right);
	}
}

void xuatLRN(Node *r)
{
	if(r!=NULL)
	{
	          xuatLRN(r->left);
	          xuatLRN(r->right);
	          if(r!=NULL)
	                     cout<<r->data<<" ";
	}
}

struct Node *searchNode(Node *r, int x)
{
	if (r == NULL)
	          return NULL;
	if(r->data==x)
	          return r;
	if(r->data>x)
	          return searchNode(r->left, x);
	else
	          return searchNode(r->right, x);
}

struct Node* minValueNode(struct Node* node) 
{
	struct Node* current = node;
	while (current && current->left != NULL)
	          current = current->left;
	return current;
}

struct Node *deleteNode(struct Node *r, int value) 
{
	if(r == NULL) return r;
	if(value < r->data) 
	          r->left = deleteNode(r->left, value);
	else 
	          if(value > r->data) 
	                    r->right = deleteNode(r->right, value);
	          else 
                   {
	                    if(r->left == NULL && r->right == NULL) 
                             {			                              delete(r);
	                              return NULL;
	                    }		
	                    else 
	                              if(r->left == NULL) 
                                       {
	                                        struct Node* temp = r->right;
	                                        delete(r);
	                                        return temp;
	                              }
	                              else 
	                                        if(r->right == NULL) 
                                                 {			                                                  struct Node* temp = r->left;
	                                                  delete(r);
	                                                  return temp;
	                                        }
                              struct Node*temp = minValueNode(r->right);
                              r->data = temp->data;
	                     r->right = deleteNode(r->right, temp->data);
                    }
	return r;
}
int main(){
	 Node r;
	addNode(r,10);
		addNode(r,6);
			addNode(r,7);
				addNode(r,9);
					addNode(r,2);	
xuatLNR(r);					
					
}
