
#include <iostream>


using namespace std;

template<typename T>
T powiter (T a, int n)
{
    T res = 1;
    while (n >  0) {
        if (n  & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}




template<typename T>
T powrec(T a, int n)
{
  if (n == 0)
        return 1;
  T  res = powrec(a, n / 2);
  if (n % 2)
        return res * res * a;
  else
        return res * res;
        
}


