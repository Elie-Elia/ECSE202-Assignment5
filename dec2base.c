/*Author: Elie Elia
 * Student ID: 260759306
 */
#include <stdio.h>
#include <math.h>

void dec2base(int input,int base,char *str){

	//Initializes remainder as an int variable
	int remainder;
	//Creates a character array of the numbers 0-9, letters A-F
	char base_digits[36] = {'0', '1', '2', '3', '4', '5', '6', '7',
			'8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	//Initializes the index of the array
	int index = 0;
	//As long as the input is not zero, the while loop will run
	while (input!=0) {
		//Value of remainder from input%base
		remainder = (input % base);
		//The input is then continuously divided by the base
		input = input / base;
		//Value to store at index position in string is equal to the value in the base_digits array at index remainder
		str[index] = base_digits[remainder];
		//Array index counter as the while loop runs
		index++;
	}
}

//Reverse string function which takes an array of characters and length
void revStr(char *str, int length){

	//Initializes character array of size length
	char result[length];
	//Initializes i as variable int
	int i;
	//Loops through until i is less than the length of character array
	for (i=0 ; i<length ; i++){
		//The result array is equal to the reverse of the string array containing the conversion
		result[i] = str[length-i-1];
	}
	for (i=0 ; i<length ; i++){
		//Equate the values found at the index positions of the string array and result array
		str[i] = result[i];
	}
}

int main(int argc, char *argv[]) {

	//Initializes the variables as type int
	int input, base, remainder, length;
	/*If the number of arguments entered as input is greater than three or less than two,
    the user has entered an invalid number of arguments*/
	if (argc > 3 || argc < 2) {
		printf("You have entered an invalid number of arguments. \n");
		return 0;
	}
	//If the number of input arguments is two
	if (argc == 2) {
		//Default base to convert to is 2
		base = 2;
	} else {
		//The second argument is passed to base as int data type
		sscanf(argv[2], "%d", &base);
	}
	//Input number and base from arguments
	sscanf(argv[1], "%d", &input);
	//If the base to convert to is less than 2 or greater than 16
	if (base < 2 || base > 36) {
		//The user is informed of the illegal input
		printf("You have entered an incorrect base. \n");
		return 0;
	}
	//Number of digits to compute size of the output array
	length =(int)(log((double) input)/log(base) +1);
	//Creates array with the specified correct size
	char str[length];
	//Calls dec2base function
	dec2base(input, base, str);
	//Calls reverse string function
	revStr(str, length);
	//Prints the output for user
	printf("%d\n",length);
	printf("The Base-%d form of %d is: ", base, input);
	int i;
	for (i = 0; i < length; i++) {
		printf("%c", str[i]);
	}
}
