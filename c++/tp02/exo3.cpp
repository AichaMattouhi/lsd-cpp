

#include <iostream>
#include<vector>


using namespace std;




void enter_matrix (int rows , int cols  , vector<vector<int>>& M)
{  
 
   
   for (int i=0;i<rows;i++)
   {
     for (int j=0 ;j<cols; j++)
       {
         cin >> M[i][j];
             
        }
        
   }
   return ; 
 } 
 
 

void print_matrix (vector<vector<int>> M )
{  
 
 // int rows = sizeof(M)/sizeof(M[0]);
  //int cols = sizeof(M)/(sizeof(int)*rows);
 
  
   cout << "{ " ;
   for (int i=0;i<M.size() ;i++)
   {
     cout<< " { " ;
     for (int j=0 ;j<M[i].size(); j++)
       {
         cout << M[i][j]<<" " ;
            
         
        }
     cout << "}"  << endl;
     
 
        
   }
     cout << " }" ;
   return ; 
 } 
 
 
vector<vector<int>> multi_matrix(vector<vector<int>> M , vector<vector<int>> N)
{
   
   
   vector<vector<int>> mult;
   
   mult.resize(M.size());
   for (int a=0;a <M.size();a++)
        { mult[a].resize(N[a].size());}
   int rows_N=N.size();
   int cols_M=M.size();
   if (cols_M!=rows_N)
      { exit(EXIT_FAILURE);}
   else 
      {
        int rows_M=M.size();
        for (int i=0;i<rows_M;i++)
            {
              int cols_N=N.size();
              for (int j=0;j<cols_N;j++)
                  {
                     int cols_M=M.size();
                     for (int k=0;k<cols_M;k++)
                      {
                        mult[i][j]+=M[i][k]*N[k][j];
                      }
                      
                      
                   }
              }
       }
       return mult;
       
}


vector<vector<int>> powrec(vector<vector<int>> M,int n)
{
  
  if (n==1)
      return M;
  if (n%2==0)
    return multi_matrix(powrec(M,n/2),powrec(M,n/2));
  else
     return multi_matrix(multi_matrix(powrec(M,n/2),powrec(M,n/2)),M);
     
}
       
  
