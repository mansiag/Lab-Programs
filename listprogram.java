import java.util.Scanner;
 class Node{
	protected int data;
	protected Node next;
	public Node()
	{
		data=0;
	 	next=null;
	}
	public Node(int d)
	{
		data = d;
	 	next = null;
	}
	public Node getnext()
	{
		return next;
	}
	public void setnext(Node n)
	{
		next=n;
	}
	public void setdata(int d)
	{
		data = d;
	}
	public int getdata()
	{
		return data;
	}
}
 class circularLinkedList extends Node{

	private Node head;
	private Node tail;
	private int num;
	public linkedlist()
	{	head=null;
		tail=null;
	}
	public void insertathead(int d)
	{
		Node newnode = new Node(d);
	 	if(head==null)
	 	{	head=newnode;
	 	        tail=newnode;
		}
	 	else
     	        {	newnode.setnext(head);
      	        	head=newnode;
            	}
     	 
	}
	public void insertattail(int d)
	{
		 Node newnode = new Node(d);
		 if(head==null)
	 		{
	 			head=newnode;
	 			tail=newnode;
			}
	 	 else{
                 tail.setnext(newnode);
	 			 tail=tail.getnext();
	 			 tail.setnext(null);
	 		}
	 	
         }

	public void delete(int n)
	{
	 Node temp1=head;
         Node temp2=head;
	 	 if(n==1)
	 	 	{ head=head.getnext();
	 	 	  return;
	 	 	}
         else 
         {
          while(temp1.getnext()!=tail)
          {
              temp1=temp1.getnext();
              
          }
          
          tail=temp1;
          temp1.setnext(null);
          }
     
	 }
	public void print()
	{
		Node temp = head;
		if(head==null)
		System.out.println("List is empty");
		while(temp!=null)
                {System.out.print(temp.getdata()+" ");
                 temp=temp.getnext();}
    }

}
public class listprogram
{public static void main(String args[])
	{char ans='y';
	 Scanner in=new Scanner(System.in);
	 int d,n;
	 circularLinkedList list = new circularLinkedList();
	 System.out.println("Enter elements of dequeue");
	 while(ans=='y')
	 	{System.out.print("Enter element: ");
	     d=in.nextInt();
	     list.insertattail(d);
	     System.out.println("Do you want to add more elements.(y/n)");
	     ans=in.next().charAt(0);

	     }
	 list.print();
	  do{
	  System.out.println("Enter the operation you want to do in dequeue");
	  System.out.println("1)Insertion at front");
	  System.out.println("2)Insertion at rear");
	  System.out.println("3)Delete at front");
	  System.out.println("4)Delete at rear");
	  int x = in.nextInt();
	  switch(x)
	  {
	  	case 1 :   System.out.println("Enter the element");
	  	           d=in.nextInt();
	  	           list.insertathead(d);
	  	           list.print();
	  	           break;
	  	case 2 :   System.out.println("Enter the element");
	  	           d=in.nextInt();
	  	           list.insertattail(d);
	  	           list.print();
	  	           break;
	  	case 3 :   list.delete(1);
	  	           list.print();
	  	           break;
	  	case 4 :   list.delete(2);
                           list.print();
	  	           break;
	  	default :  return;
	  }
	  System.out.println("Do you again want to perform any action.(y/n)");
	  ans=in.next().charAt(0);
     }while(ans=='y');
	}
}



