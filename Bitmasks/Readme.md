### 1. Find Out x % 2^k:
  -> x & ((1<<k) - 1)   or x & (2^k - 1)
.......................................Basically this takes the sign bits before Kth bit of x


### 2. Swap Two Numbers:
 -> x = x ^ y
    y = x ^ y
    x = x ^ y ..........when we xor the same two number , it wipes out


### 3. Count Sign Bits

      No. of set bits in A = x
      No. of set bits in B = y
      No. of set bits in (A ^ B) = z

    Then, z is even if x+y is even
          z is odd if x+y is odd



### 4. Alternate of conditional statement:

  *** Raw statement: ***

    ```c++
    if(x == a) x = b;
    else if(x == b) x = a;
    ```
  *** Bitwise code base: ***

    ```C++
    x = a ^ b ^ x;
    ```