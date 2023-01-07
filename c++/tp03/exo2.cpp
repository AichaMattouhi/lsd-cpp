#include <iostream>
using namespace std;

class shape 

{
  protected : 
  int width;
  int height;
  public:
  shape():width(1),height(1){}
  shape(int a , int b):width(a),height(b){}
  
  
};

class triangle :public shape
{
   public :
   using shape::shape;
   float area() {return width*height/2 ;}
   
   
};

class rectangle : public shape
{
  public :
  using shape::shape;
  float area(){return width*height ;}
};

