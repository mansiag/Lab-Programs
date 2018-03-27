#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
protected:
	int data;
	Node* next;
public:
	Node()
	{}
	Node(int d)
	{
		data=d;
		next=NULL;
	}
	void setnext(Node* n)
	{next=n;}
	int getdata()
	{return data;}
	Node* getnext()
	{return next;}
	
};
class stack : public Node{
	private:
		Node* head;
	public:
		 stack()
		{head=NULL;}
		void push(int d)
		{
			Node* newnode = new Node(d);
			newnode->setnext(head);
			head=newnode;

		}
		bool empty()
		{if(head==NULL)
		  	return true;
		 else
		  	return false;
	    }
	    void pop()
	    { Node* temp=head;
	      head=head->getnext();
	      free(temp);
        }
        char top()
        {if(!empty())
         	return head->getdata();
         else
         {
         	cout<<"Stack is empty!";
         	return 'e';
         }
    	 }
   
    	
         bool isoperator(char a)
         {if(a=='*' || a=='/' || a=='%' || a=='+' || a=='-')
          return true;
          else return false;
         }
       
        int perform(char a ,int x,int y)
        {switch(a)
         {case '*': return x*y;
          case '/': return y/x;
          case '+': return x+y;
          case '-': return y-x;
          case '^': return y^x;
          case '%': return y%x;}
         }
        int evaluatepostfix(string exp)
        {int n=exp.length();
         for(int i=0;i<n;i++)
         {
            if(!isoperator(exp[i]))
            	{ 
                push(int(exp[i]-'0'));
            }
            else
            {
                int x = top();
                pop();
                int y = top();
                pop();
                int res = perform(exp[i],x,y);
                push(res);
                
            }
         }
        return top();
    }


};
int main(){
	stack s;
	string exp,res;
	cout<<"Enter the postfix expression:\n";
    cin>>exp;
    cout<<s.evaluatepostfix(exp);
	return 0;
}