#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;
class Node{
protected:
	int data;
	Node* right;
	Node* left;
public:
	Node()
	{}
	Node(int d)
	{
		data=d;
		right=NULL;
		left=NULL;
	}
	void setleft(Node* n)
	{left=n;}

    void setright(Node* n)
	{right=n;}

	int getdata()
	{return data;}

	Node* getright()
	{return right;}

	Node* getleft()
	{return left;}
	
};
class Binary_tree : public Node{
private :
	Node *root;
	int count;
	queue<Node*> q;
	stack<Node*> s1;
	stack<Node*> s2;
	stack<int> q2;
public :
	Binary_tree()
	{
		root = NULL;
		count = 0;
	}
	void insert(int d)
	{	
		Node* newnode = new Node(d);
		if(q.empty())
		{ 
			root = newnode;
			q.push(root);
			return;
        }
        Node*temp = q.front();
        if(temp->getleft()==NULL)
        {
            temp->setleft(newnode);
            q.push(newnode);
        }
        else
        {
        	temp->setright(newnode);
        	q.push(newnode);
        	q.pop();
        }
        count++;
	}

	void preorder(Node *temp)
	{   if(temp == NULL)return;
		cout<<temp->getdata()<<" ";
		preorder(temp->getleft());
		preorder(temp->getright());
	}

    void postorder(Node *temp)
	{   
		if(temp == NULL)return;
		postorder(temp->getleft());
		postorder(temp->getright());
		cout<<temp->getdata()<<" ";
	}
	void inorder(Node *temp)
	{
		if(temp == NULL)return;
		inorder(temp->getleft());
		cout<<temp->getdata()<<" ";
		inorder(temp->getright());
	}
	void spiral()
	{
        Node*temp = root;

		
		q2.push(root->getdata());
		if(root->getleft()!=NULL)
			s1.push(root->getleft());
		
		if(root->getright()!=NULL)
			s1.push(root->getright());
		
		while(!s1.empty() || !s2.empty())
		{
			while(!s1.empty())
			{
				Node*temp = s1.top();

				if(temp->getright()!=NULL)
		        	s2.push(temp->getright());
		          
		        if(temp->getleft()!=NULL)
		        	s2.push(temp->getleft());
		           
		      	q2.push(temp->getdata());
		        s1.pop();   
             }
             
             while(!s2.empty())
             {

			    Node*temp = s2.top();

				if(temp->getleft()!=NULL)
			        s1.push(temp->getleft());
		           
		        if(temp->getright()!=NULL)
		        	s1.push(temp->getright());

		        q2.push(temp->getdata());
		        s2.pop();   
             }
       
	    }
	 	
	    while(!q2.empty())
	     {
           cout<<q2.top()<<" ";
           q2.pop();
	     }
	}

	void traversal()
	{   
		int x;

		cout<<"1)Preorder Traversal\n";
		preorder(root);
		cout<<endl;
		cout<<"2)Postorder Traversal\n";
		postorder(root);
		cout<<endl;
		cout<<"3)Inorder traversal\n";
		inorder(root);
		cout<<endl;
		cout<<"4)Spiral traversal\n";
		spiral();

	}	   
	
	void sum()
	{
       stack<int >s;
       Node* temp = root;
       q2.push(temp);
       while(!q2.empty())
       {
       	 Node*temp2= q2.front();
       	  if(temp2->left==NULL && temp2->right==NULL)
         {
         	
         	s.push(temp2->data);
         }
         //else
         	//{
       	 if(temp2->left!=NULL)
       	 {
       	 	temp2->left->data+=temp2->data;
       	 	q2.push(temp2->left);
       	 }
       	 if(temp2->right!=NULL)
       	 {
       	 	temp2->right->data+=temp2->data;
       	 	q2.push(temp2->right);
       	 }
        
       	 q2.pop();
       	//}
       }
       cout<<endl;
       while(!s.empty())
       {
       	cout<<s.top()<<" ";
       	s.pop();
       }
      
	}
	
	
};
int main()
{   
	int d, i=1;
	char ans='y';
	Binary_tree b;
	while(ans=='y')
	{   cout<<"Enter data for node "<<i<<": ";
        cin>>d;
        b.insert(d);
		cout<<"Do you want to add more nodes? :";
		cin>>ans;
		i++;
	}
	b.traversal();
	return 0;
}