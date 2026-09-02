//nice formulas and additional information:
	
	//ranges from 0 to n that has xor zero has conditino that n%4==3 
	
	//so:
	
	// First x >= a such that:
	// 0 ^ 1 ^ 2 ^ ... ^ x = 0
	//
	// Equivalently:
	// First x >= a such that x % 4 == 3
	//
	// Formula:
	// int x = a + (3 - a % 4 + 4) % 4;
	
	
	// Largest x <= a such that:
	// 0 ^ 1 ^ 2 ^ ... ^ x = 0
	//
	// Equivalently:
	// Largest x <= a such that x % 4 == 3
	//
	// Formula:
	// int x = a - (a + 1) % 4;


	
	
	
	
	//ai told me another way which is:
	//xor from 0 to n is : 
	//n   if n%4==0
	//1   if n%4==1
	//n+1 if n%4==2
	//0   if n%4==3






// The numbers can be divided into blocks of 4:
//
// 0, 1, 2, 3
// 4, 5, 6, 7
// 8, 9, 10, 11
// 12, 13, 14, 15
// ...
//
// The XOR of every complete block is 0:
//
// 0 ^ 1 ^ 2 ^ 3 = 0
// 4 ^ 5 ^ 6 ^ 7 = 0
// 8 ^ 9 ^ 10 ^ 11 = 0
// ...
//
// Therefore, the prefix XOR becomes 0 after every complete block,
// i.e. at n = 3, 7, 11, 15, ...
//
// Equivalently:
// n % 4 == 3  ->  0 ^ 1 ^ ... ^ n = 0
