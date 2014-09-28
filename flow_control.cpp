#include <iostream>
using namespace std;

int main ()
{
  for (int n=10; n>0; n--) {
    cout << n << ", ";
  }
  cout << "liftoff!\n";
  int n;
  int i;
  for ( n=0, i=100 ; n<100 ; ++n, --i ) {
    cout << i*n << ", ";
  }
  cout << "\n";
}
