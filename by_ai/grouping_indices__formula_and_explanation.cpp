/*
    
    GROUPING INDICES

    Before understanding expressions such as:

        i / 2 % 2

    it helps to understand the idea of "groups".

    Suppose we have the indices:

        0 1 2 3 4 5 6 7 8 9 10 11

    We can divide them into consecutive groups.

    For example, groups of size 2:

        [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]

    Every index belongs to exactly one group.

    We can give each group a number:

        [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]
          0      1      2      3      4       5

    The important observation is that:

        i / 2

    gives us exactly the group number of index i.

        i:        0 1 | 2 3 | 4 5 | 6 7 | 8 9 | 10 11
        i / 2:    0 0 | 1 1 | 2 2 | 3 3 | 4 4 |  5  5

    Why?

        0 / 2 = 0
        1 / 2 = 0
        2 / 2 = 1
        3 / 2 = 1
        4 / 2 = 2
        ...

    Integer division makes every group of 2 indices have the same
    group number.

    ------------------------------------------------------------

    Now suppose we do not want every group to have a unique number.

    Maybe we want the groups to alternate between two states:

        [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]
          0      1      0      1      0       1

    We can get this by taking the group number modulo 2:

        i / 2 % 2

        i / 2:    0 0 | 1 1 | 2 2 | 3 3 | 4 4 | 5 5
        % 2:      0 0 | 1 1 | 0 0 | 1 1 | 0 0 | 1 1

    This happens because:

        0 % 2 = 0
        1 % 2 = 1
        2 % 2 = 0
        3 % 2 = 1
        4 % 2 = 0
        ...

    So:

        / 2 -> creates groups of size 2
        % 2 -> makes the groups alternate between 0 and 1

    Therefore:

        i / 2 % 2

    means:

        "Which group am I in, and is that group even or odd?"

    ------------------------------------------------------------

    USING IT TO FLIP A BINARY VALUE

    Suppose x is either 0 or 1.

        x ^ 0 = x
        x ^ 1 = 1 - x

    Therefore:

        x ^ (i / 2 % 2)

    gives:

        x x | 1-x 1-x | x x | 1-x 1-x | ...

    The XOR does not create the groups.
    The expression:

        i / 2 % 2

    creates the 0/1 pattern.

    XOR simply uses that pattern to decide whether x should stay
    the same or be flipped.

    ------------------------------------------------------------

    GENERAL FORMULA

        floor(i / k) % y

    The first part:

        floor(i / k)

    divides the indices into groups of size k.

        k = 2:

            [0 1] [2 3] [4 5] [6 7] ...

        k = 3:

            [0 1 2] [3 4 5] [6 7 8] ...

        k = 4:

            [0 1 2 3] [4 5 6 7] [8 9 10 11] ...

    The second part:

        % y

    makes the group numbers repeat every y groups.

    For example:

        i / 3 % 2

        groups:

            [0 1 2] [3 4 5] [6 7 8] [9 10 11]
              0        1        0          1

        So we get:

            0 0 0 | 1 1 1 | 0 0 0 | 1 1 1 | ...

    Another example:

        i / 2 % 3

        groups:

            [0 1] [2 3] [4 5] [6 7] [8 9] [10 11]
              0      1      2      0      1       2

        So we get:

            0 0 | 1 1 | 2 2 | 0 0 | 1 1 | 2 2 | ...

    GENERAL IDEA:

        / k  -> determines the group size
        % y  -> determines how many group values are repeated

    Therefore:

        floor(i / k) % y

    means:

        "Divide the indices into groups of size k,
         then cycle the group number through 0, 1, ..., y-1."

    In C++, because / between integers is integer division:

        i / k % y

    is the implementation of:

        floor(i / k) % y
        
        
*/
