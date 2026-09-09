/*
    
    Relation :
    x⊕y is equal to the difference between x OR y and x AND y , where OR and AND denote bitwise OR and bitwise AND, respectively.
    
    
    
    
    
    
    
    
    

    
    Identity:
        u + v = (u ^ v) + 2 * (u & v)

    This identity expresses normal addition using bitwise operations.

    1) u + v
       The usual arithmetic addition of u and v.

    2) u ^ v  (Bitwise XOR)
       Adds the bits at each position WITHOUT considering carries.

       For each bit:
           0 ^ 0 = 0
           0 ^ 1 = 1
           1 ^ 0 = 1
           1 ^ 1 = 0

       So when both bits are 1, XOR produces 0 because that addition
       generates a carry instead.

    3) u & v  (Bitwise AND)
       Finds the positions where BOTH bits are 1.

       These are exactly the positions where a carry is generated.

    4) 2 * (u & v)
       Multiplying by 2 shifts every carry one bit to the left:

           2 * (u & v) = (u & v) << 1

       This places each carry in the next bit position, where it belongs.

    Therefore:

        XOR gives the addition result without carries.
        AND finds where the carries are generated.
        << 1 moves those carries to the correct positions.

        Hence:

            u + v = (u ^ v) + ((u & v) << 1)

    This is essentially the same logic used by binary addition in hardware:
    XOR handles the sum bits, while AND identifies the carry bits.
*/
