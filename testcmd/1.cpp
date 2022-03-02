#include<iostream>

using namespace std;


int main( int argc, char *argv[] )  
{
    if( argc == 2 )
    {
        std::cout << "Tham so duoc cung cap la:" << argv[1] << endl;
    }
    else if( argc > 2 )
    {
        std::cout << "Tham so duoc cung cap la:" << argv[1] << endl;
        std::cout << "Tham so duoc 2 cung cap la:" << argv[2] << endl;
    }
    else
    {
      cout << "Ban nen cung cap mot tham so" << endl;
    }
}