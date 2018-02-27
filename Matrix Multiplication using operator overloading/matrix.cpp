#include<iostream>
#include<iomanip>
using namespace std;
class matrix
{private:
  int rows,columns;
  int a[100][100];
 public:
   void get_matrix()
   {cout<<"Enter the number of rows of matrix ";
    cin>>rows;
    cout<<"Enter the number of columns of matrix ";
    cin>>columns;
    cout<<"Enter the elements of matrix:\n";
    for(int i=0;i<rows;i++)
    	{for(int j=0;j<columns;j++)
    	   cin>>a[i][j];
    	}
   }
   void print_matrix() const
   { if(rows==0 || columns==0)
      cout<<"Invalid matrix"<<endl;
     for(int i=0;i<rows;i++)
    	{for(int j=0;j<columns;j++)
    	   cout<<setw(4)<<a[i][j];
    	 cout<<endl;
        }
   }
   matrix transpose() const
   {matrix temp;
    temp.rows=columns;
    temp.columns=rows;
     for(int i=0;i<rows;i++)
    	{for(int j=0;j<columns;j++)
    	   temp.a[j][i]=a[i][j];
    	}
    return temp;
   }
   matrix operator * (matrix const)const ;
  
};
matrix matrix::operator * (matrix const b) const
 {matrix t;
    if(columns!=b.rows)
     {cout<<"Matrix multiplication is not possible\n";t.rows=0;t.columns=0;return t;}
    t.rows=rows;
    t.columns=b.columns;
    for(int i=0;i<rows;i++)
    	{
    	 for(int k=0;k<b.columns;k++)
    	  {t.a[i][k]=0;
    	   for(int j=0;j<columns;j++)
    	    {t.a[i][k]+=(a[i][j]*b.a[j][k]);
    	    }
    	  }
        }
     return t;
 }

int main()
{matrix b,c,d,e;
 char ch,ans;
 do{
     cout<<"Which operation do you want to perform?\n(a)transpose of the matrix\n(b)Matrix multiplication\nEnter(a/b)? ";
     cin>>ch;
     if(ch=='a')
     { cout<<"Enter matrix :\n";
       b.get_matrix();
       cout<<"The matrix is:"<<endl;
       b.print_matrix();
       c=b.transpose();
       cout<<"Transpose of the matrix is:"<<endl;
       c.print_matrix();
     }
     else if(ch=='b')
     { cout<<"Enter matrix 1:\n";
       b.get_matrix();
       cout<<"The first matrix is:"<<endl;
       b.print_matrix();
       cout<<"Enter matrix 2:\n";
       d.get_matrix();
       cout<<"The second matrix is:"<<endl;
       d.print_matrix();
       e=(b*d);
       cout<<"Product of matrices 1 and 2 is:"<<endl;
       e.print_matrix();
     }
     cout<<"Do you want to continue?(y/n)";
     cin>>ans;
   }while(ans=='y');
 return 0;
}



































