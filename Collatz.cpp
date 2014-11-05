//
//  Collatz.cpp
//  
//
//  Created by Stuart George on 05/11/2014.
//
//

#include <iostream>


int do_collatz_step (int m)
{
    int result;
    
    if (m%2 == 0)
        result = m/2;
    else
        result = 3*m + 1;
    
    return result;
}

int main ()
{
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    
    std::cout << "The number you entered is: ";
    std::cout << n << std::endl;
    
    int threshold = 1000;
    int count = 1;
    while (n>1 && count<threshold)
    {
        n = do_collatz_step(n);
        count += 1;
        std::cout << n << std::endl;
    }
    
    if (n>1)
        std::cout << "Took too many steps\n";
    else
        std::cout << "Took " << count << " steps to get to 1\n";
    
    return 0;
    
}

