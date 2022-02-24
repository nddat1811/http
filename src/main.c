#include<stdio.h>


int main(int argc, char *argv[])
{
    if( argc == 2 )
    {
      printf("Tham so duoc cung cap la: %s\n", argv[1]);
    }
   else if( argc > 2 )
    {
      printf("Tham so 1 duoc cung cap la: %s\n", argv[1]);
      printf("Tham so 2 duoc cung cap la: %s\n", argv[2]);
    }
    
    return 0;
}