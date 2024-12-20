# Maths for DSA

## Prime numbers
For n -> Check if n is divisible from 2 -> square_root(n). If it is divisible, it is not a prime number, otherwise it is.

Loop through 2 - i^2 <= n, for each i, check if n % i == 0, if yes, n is prime, else it isn't.

## Prime numbers is a range
Brute force approach will be to create a nested loop for range and inner loop will check each n to be prime or not.
### Sieve of Eratostheses
An optimized approach.
This approach says if we have to count primes in range from 1 to n.
1. Assume all number in the range are prime. Create a boolean vector of size n+1 with true for all.
2. Start from 2, if it is prime(as we assumed), mark all its multiples as not prime and discard them.

## Digits in a number
For a number n, count digits in it.

Repeatedly take modulo of n by 10 and then divide n by 10, until n becomes 0.

Using this approach, we can extract all individual digits of a number.

We can count, calculate sum, or print the digits.

## Armstrong number
An armstrong number is a number that is equal to the sum of cube of its digits.

For n = 153 => 1^3 + 5^3 + 3^3 => 1 + 125 + 27 => 153


## GCD / HCF
Greatest Common Divisor / Highest Common Factor

For two numbers a, and b, GCD or HCF is the highest number that can divide both a and b.

1 is the smallest number in the range, so it will be the start. minimum of a and b is greatest number in the range.

Brute Force Approach: 

Loop throug i to min(a, b) until gcd is found.

If a is , b is GCD and vice versa, and if a is equals to be the a/b is GCD.

### Euclid's Algorithm
```
gcd(a,b) = gcd(a-b, b) , a > b
           gcd(b, b-a) , b > a
```

Ex: gcd(20, 28) -> gcd(20, 8) -> gcd(12, 8) -> gcd(4, 8) -> gcd(4, 4) -> gcd(0, 4) = 4

Here we are repeatedly doin subtractions, what if a >> b (a is more greater than b)

Repeated subtraction is actually division

So, instead of repeated subtraction we can take modulo of greater number with smaller number, so we'll directly reach at the number being lesser than the previous smaller number

Ex: 20 - 8 = 12 => 12 - 8 = 4 / 20 % 8 = 4

Now, the algorithm will become

```
gcd(a,b) = gcd(a%b, b) , a > b
           gcd(b, b%a) , b > a
```

Ex: gcd(20, 28) -> gcd(20, 8) -> gcd(4, 8) -> gcd(4, 0) = 4

## LCM 
Lowest/Least Common Multiple

For two numbers a nad b

```
a * b = gcd(a, b) * lcm(a,b)

lcm = a * b / gcd(a,b)
```

## Reverse a number
For num = 4357 -> num = 7534

Extract each digit from num

7534 = 7 * 10^3 + 5 * 10^2 + 3 * 10^1 + 4 * 10^0

1. Extract a digit from num
2. Add it into final answer as  follows
``` ans = (ans * 10) + digit ``` 

## Palindorme Number
A number is a plaindrome if it is same as read forward or backward

Ex: 353 is a plandrome. 852 is not a plaindrome.

Negative numbers are not plandorme.

We can calculate reverse of a number, If it is same as original number, it is a palindrome, else it isn't.

## Modulo Arithmetics
We mainly take mod when the given answer is way larger than integr or even log integer range, preventing overflow condition
 ans % (10^7 + 9)

For x % n = [0 , n-1]

Ex: 10 % 3 -> [0, 1, 2]

### Properties
- (x + y) % m = x % m + y % m
- (x - y) % m = x % m - y % m
- (x . y) % m = x % m . y % m

- (((x % m) % m) % m)... = x % m

## Power exponentiation (HW)
Lecture # 13 -> pow(x, n)