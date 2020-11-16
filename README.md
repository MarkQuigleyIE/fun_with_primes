# fun_with_primes

This was a simple project I found on CodeChef [Link](https://www.codechef.com/problems/MAXSPSUM). I used it as a way to familiarise myself with C++ again (forgive the mixed-use of cout and printf). 

I wasn't able to get the actual CodeChef project to work (I didn't understand the final calculation).

## Usfull Parts
The SLL.h containers two classes for singly-linked lists (SLL), the nodes(SLL_NODE) and the list(S_LIST). 

The main.cpp has two functions for working with primes.
* find_primes: finds all the primes less than a given integer.
* find_prime_factors: finds prime factors of a given integer, using the list of primes less than it.

Both return SLL's as the exact size of the array before the calculation is unknown. 
