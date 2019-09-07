#include <stdio.h>
#include <iostream>
using namespace std;

int division(int num1, int num2)
{
	
	if(num1 == 0)
		return 0;
	if(num2 == 0)
		return INT_MAX;
	
	bool negResult = false;
	
	// Handling negative numbers.
	if (num1 < 0)
	{
		num1 = -num1;
		// Check if second number is negative.
		if (num2 < 0)
			num2 = -num2;
		else
			negResult = true;		
	}
	
	else if (num2 < 0)
	{
		num2 = -num2;
		negResult = true;	
	}
	
	// if num1 is greater than equal to num2
	// subtract num2 from num1 and increase
	// quotient by one.
	int quotient = 0;
	while (num1 >= num2)
	{
		num1 = num1 - num2;
		quotient++;
	}
	
	// checking if neg equals to 1 then making
	// quotient negative.
	if(negResult)
		quotient = -quotient;
	return quotient;
	
}

int main()
{
	int num1;
	int num2;
	printf("Number1: ");
	cin >> num1;
	printf("Divideby\nNumber2: ");
	cin >> num2;
	cout << "Answer: " << division(num1,num2) << endl;
	return 0;
}
