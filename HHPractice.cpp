#include <iostream>
#include <fstream>
#include <boost/array.hpp>

#include <boost/numeric/odeint.hpp>

using namespace std;
using namespace boost::numeric::odeint;

const double sigma = 10.0;
const double R = 28.0;
const double b = 8.0 / 3.0;

typedef boost::array< double , 3 > state_type;

void lorenz( const state_type &x , state_type &dxdt , double t )
{
  dxdt[0] = sigma * ( x[1] - x[0] );
  dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
  dxdt[2] = -b * x[2] + x[0] * x[1];
}

struct output_observer
{
    string filename_;
    size_t count_;
    output_observer( const string &filename ) : filename_( filename ) , count_( 0 ) { }
    void operator()( const state_type &x , time_type dt )
    {
        char fn[512] = "";
        sprintf( fn , "%s_%04lu.csv" , filename_.c_str() , count_ );
        ofstream fout( fn );
        for( size_t i=0 ; i<x.size() ; ++i ) fout << x[i] << "\n";
        ++count_;
    }
};

void write_lorenz( const state_type &x , const double t)
{
  cout << t << '\t' << x[0] << '\t' << x[1] << '\t' << x[2] << endl;
}

int main(int argc, char **argv)
{
  string filename = "output_data.txt";
  state_type x = { 10.0 , 1.0 , 1.0 }; // initial conditions
  integrate( lorenz , x , 0.0 , 25.0 , 0.1 , output_observer( "filename" );
}
