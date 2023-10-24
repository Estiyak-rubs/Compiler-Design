#include <iostream>
using namespace std ;

int main ()
{
    int num [] = {1,2,3,4,5};
    int length = sizeof (num)/sizeof(num[1]);
    int min= num[0];
    int max= num[0];

    for(int i=0; i<length ; i++)
    {
        if(num[i]<min)
        {
            min=num[i];
        }
        if(num[i]>max)
        {
            max=num[i];
        }
    }

    cout << "Minimum value is : " << min << endl;
    cout << "Maximum value is : " << max ;

return 0;
}
