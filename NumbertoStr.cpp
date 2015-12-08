/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int int_part = (int)number;
	int i = 0;
	char sign = NULL;
	if (number < 0){
		sign = '-';
		int_part *= -1;
	}
	while (int_part > 0){
		str[i] = (int_part % 10) + '0';
		int_part = int_part / 10;
		i++;
	}
	if (number < 0){
		sign = '-';
		int_part *= -1;
	}
	if (sign == '-'){
		str[i] == '-';
		i++;
	}
	//we have to reverse the string for correct integer part of the number
	int temp;
	for (int k = 0, j = i - 1; i < j; i++, j--) {
		temp = str[k];
		str[k] = str[j];
		str[j] = temp;
	}
	if (afterdecimal > 0) {
		str[i] = '.';
		i++;
		if (number < 0)
			number *= -1;
		float float_part = number - (float)((int)number);
		for (int j = 0; j < afterdecimal; j++) {
			float_part *= 10;
			str[i] = ((int)float_part % 10) + '0';
			i++;
		}
	}
	str[i] = '\0';
}
