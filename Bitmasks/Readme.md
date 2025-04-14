# Bitwise Tricks and Optimizations


## Table of Contents:
- [1. Find Out x % 2^k](#1-find-out-x-mod-2-k)
- [2. Swap Two Numbers](#2-swap-two-numbers)
- [3. Find Sign Bits of XOR Values](#3-find-sign-bits-of-xor-values)
- [4. Alternate of conditional statement](#4-alternate-of-conditional-statement)
- [5. Sum of Two Number](#5-sum-of-=two-number)
- [6.Finding The Number of Set Bits in an Integer](#6-finding-the-number-of-set-bits-in-an-integer)
- [7. Toggling i'th Bit of a Number](#7-toggling-ith-bit-of-a-number)
- [8. Check i'th Bit is Set or not](#8-check-ith-bit-is-set-or-not)
- [9. Check a Number is Power of 2 or not](#9-check-a-number-is-power-of-2-or-not)

---

### 1. Find Out `x % 2^k`:

  ➡️ `x & ((1<<k) - 1)   or x & (2^k - 1)`
  Basically this takes all the sign bits before Kth bit of `x`

---

### 2. Swaping Two Numbers:

 ```cpp
    x = x ^ y
    y = x ^ y
    x = x ^ y 
 ```
    When we XOR the same two number , it wipes out 
    

---


### 3. Find Sign Bits of XOR Values

    - No. of set bits in A = x
    - No. of set bits in B = y
    - No. of set bits in (A ^ B) = z

    Then, z is even if x+y is even
          z is odd if x+y is odd

---

### 4. Alternate of conditional statement:

  ***Raw statement***:

```cpp
    if(x == a) x = b
    else if(x == b) x = a
```
     
***Bitwise code base***: 

```cpp
    x = a ^ b ^ x;
```

---

### 5. Sum of Two Number
 ***Generel Code base***:
 ```cpp
    int128_t a, b, sum;
    sum = a + b;
```

***Bitwise Code Base***:
```cpp
   int128_t a, b, sum;
   sum = (a ^ b) + 2*(a & b);
   // or we can write as:
   sum = (a | b) + (a & b);
```

---

### 6.Finding The Number of `Set` Bits in an Integer
```cpp

    __builtin_popcount(x); // for int
    __builtin_popcountll(x); // for long long
```

---

### 7. Toggling `i'th`  Bit of a Number
```cpp
  x = x ^ (1 << i);
```

---

### 8. Check `i'th` Bit is Set or not
```cpp
  if(x & (1 << i)) cout << "Set";
  else cout << "Unset";
```

---


### 9. Check a Number is Power of `2` or not
```cpp
   if((n & (n - 1)) == 0) cout << "YES";
   else cout << "NOT";
```