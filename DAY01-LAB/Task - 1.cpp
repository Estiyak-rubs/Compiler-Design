#include <iostream>
using namespace std ;

int main ()
{
    int num [] = {1,2,3,4,5};
    int length = sizeof (num)/sizeof(num[1]);
    int sum=0;

    for(int i=0; i<length ; i++)
    {
        sum=sum+num[i];
    }
    double avg=sum/length;

    cout << "Average is : " << avg;

return 0;
}
