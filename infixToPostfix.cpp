#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
protected:
	char data;
	Node* next;
public:
	Node()
	{}
	Node(char d)
	{
		data=d;
		next=NULL;
	}
	void setnext(Node* n)
	{next=n;}
	char getdata()
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
		void push(char d)
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
   
    	 bool isOpeningParenthesis(char a)
         {
         	if(a=='(' || a=='{' || a=='[')
         		return true;
         	else 
         		return false;
         }
         bool isClosingParenthesis(char a)
         {	
         	if(a==')' || a=='}' || a==']')
         		return true;
         	else
         		 return false;
         }
         bool hasHigherPrecedence(char a,char b)
         {
         	int temp_a;
            int temp_b;
            if(a=='^')
            	temp_a=3;
            else if(a=='*' || a=='/' || a=='%')
            	temp_a=2;
            else
            	temp_a=1;
            if(b=='^')
            	temp_b=3;
            else if(b=='*' || b=='/' || b=='%')
            	temp_b=2;
            else
            	temp_b=1;
            if(temp_a<temp_b)
            return false;
            else
            return true;            
         }
         bool isoperator(char a)
         {if(a=='*' || a=='/' || a=='%' || a=='+' || a=='-')
          return true;
          else return false;
         }
         bool isoperand(char a)
         {
         	if(!isoperator(a) && !isOpeningParenthesis(a) && !isClosingParenthesis(a))
         		return true;
         	else
         		return false;
         }
         string infixtopostfix(string exp)
         {  string res;
         	int n=exp.length();
           for(int i=0;i<n;i++)
          {
    		if(isoperand(exp[i]))
    		res=res+exp[i];
    		else if(isOpeningParenthesis(exp[i]))
    		push(exp[i]);
    		else if(isClosingParenthesis(exp[i]))
    			{
    				while(!empty() && !isOpeningParenthesis(top()))
    					{
    						res=res+top();
    						pop();
    					}
    				pop();
    			}
    		else
    			{
    				while(!empty() && !isOpeningParenthesis(top()) && hasHigherPrecedence(top(),exp[i]))
    					{
    						res=res+top();
    						pop();
    					}
    				push(exp[i]);
    			}

    		}
    		while(!empty())
    		{res=res+top();
    	 	 pop();}
    	 return res;
    	}

};
int main(){
	stack s;
	string exp,res;
	cout<<"Enter the infix expression:\n";
    cin>>exp;
    cout<<"The postfix expression is:\n";
    cout<<s.infixtopostfix(exp);
	return 0;
}