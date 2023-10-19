//TREE INPUT

#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		string data;
		node* left;
		node* right;
};
class stack1{
    public:
        node* arr[20];
        int top;
        stack1(){
            top=-1;
        }
        void push(node* temp){
            top++;
            arr[top]=temp;
        }
        int empty(){
            if(top==-1){
                return 1;
            }
            else{
                return 0;
            }
        }
        node* pop(){
            node* p=arr[top];
            top--;
            return p;
        }
};
class stack2{
    public:
        node* arr[20];
        int top;
        stack2(){
            top=-1;
        }
        void push(node* temp){
            top++;
            arr[top]=temp;
        }
        int empty(){
            if(top==-1){
                return 1;
            }
            else{
                return 0;
            }
        }
        node* pop(){
            node* p=arr[top];
            top--;
            return p;
        }
};
class queue1{
    public:
    int r,f;
    node* arr[20];
    queue1()
    {
        r=f=-1;
    }
    int empty()
    {
        if(r==-1 && f==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    void insert(node* p)
    {
        if(empty()==1)
        {
            r=f=0;
            arr[r]=p;
        }
        else{
            r=r+1;
            arr[r]=p;
        }
        
    }
    node* remove()
    {
        node* temp=arr[f];
        if(r==f)
        {
            r=f=-1;
        }
        else{
            f++;
        }
        return temp;
    }
    
};
class tree{
	public:
		node* root;
		tree(){
			root=NULL;
		}
		node* create(){
			string key;
			cout<<"Enter the book(if not enter NULL):";
			cin>>key;
			if(key=="N"){
			    return NULL;
			}
			node* temp=new node();
			temp->data=key;
			temp->left=NULL;
			temp->right=NULL;
		    cout<<"Enter the left part(if not enter NULL):"<<key<<endl;
			temp->left=create();
			cout<<"Enter the right part(if not enter NULL):"<<key<<endl;
			temp->right=create();
			
			return temp;
		}
		void preorder(node* t){
			if(t==NULL)
			    return;
			cout<<t->data<<" ";
			preorder(t->left);
			preorder(t->right);
		}
		void inorder(node* t){
			if(t==NULL)
			    return;
			inorder(t->left);
			cout<<t->data<<" ";
			inorder(t->right);
			
		}
		void postorder(node* t){
			if(t==NULL)
			    return;
			postorder(t->left);
			postorder(t->right);
			cout<<t->data<<" ";
		}
		void nonrecursive_inorder(node* t){
		    stack1 st;
		    while(t!=NULL || st.empty()!=1){
		        while(t!=NULL){
		            st.push(t);
		            t=t->left;
		        }
		        t=st.pop();
		        cout<<t->data<<" ";
		        t=t->right;
		    }
		    
		}
		void nonrecursive_preorder(node* t){
		    stack1 st;
		    while(t!=NULL || st.empty()!=1){
		        while(t!=NULL){
		            cout<<t->data<<" ";
		            st.push(t);
		            t=t->left;
		        }
		        t=st.pop();
		        t=t->right;
		    }
		}
		void nonrecursive_postorder(node* t){
		    stack1 st;
		    stack2 st1;
		    node* temp;
		    if(t==NULL){
		        return;
		    }
		    st.push(t);
		    while(st.empty()!=1){
		        temp=st.pop();
		        st1.push(temp);
		        if(temp->left!=NULL)
		            st.push(temp->left);
		        if(temp->right)
		            st.push(temp->right);
		    }
		    while(st1.empty()!=1){
		        temp=st1.pop();
		        cout<<temp->data<<" ";
		    }
		}
		void BFS(node* t)
		{
		    queue1 q;
		    q.insert(t);
		    cout<<t->data<<" ";
		    while(q.empty()!=1){
		        t=q.remove();
		        if(t->left!=NULL)
		        {
		            cout<<t->left->data<<" ";
		            q.insert(t->left);
		        }
		        if(t->right!=NULL)
		        {
		            cout<<t->right->data<<" ";
		            q.insert(t->right);
		        }
		    }
		}
		
};
int main(){
	tree t;
	int ch;
	cout<<"**********MENU**********"<<endl;
	cout<<"\n1.Create\n2.Recursive Inorder\n2.Recursive Preorder\n3.Recursive Postorder\n4.Non-Recursive Inorder\n5.Non-Recursive Preorder\n6.Non-Recursive Postorder\n7.BFS\n8.Exit\n";
	while(1){
		cout<<"\nEnter a choice:";
		cin>>ch;
		switch(ch){
			case 1:
				t.root=t.create();
				break;
			case 2:
				t.preorder(t.root);
				break;
			case 3:
			    t.inorder(t.root);
			    break;
			case 4:
			    t.postorder(t.root);
			    break;
			case 5:
			    t.nonrecursive_inorder(t.root);
			    break;
			case 6:
			    t.nonrecursive_preorder(t.root);
			    break;
			case 7:
			    t.nonrecursive_postorder(t.root);
			    break;
			case 8:
			    t.BFS(t.root);
			    break;
			case 9:
			    exit(1);
		}
	}
	return 0;
}

