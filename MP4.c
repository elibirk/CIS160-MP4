/* ========================================================
Leah Perry								  CIS 160 Fall 2014
MP4							 			Submitted: 10/28/14
Quadratic Equation Solver				Revised on: -------


Data Dictionary
Variable				Used to
--------				-------
int MainLoopInput		store whether or not user wants to repeat the function
int a					Store a in ax^2 + bx + c = 0
int b					Store b in ax^2 + bx + c = 0
int c					Store c in ax^2 + bx + c = 0
int input				holds user response in IntULandLL
int LowerLimit			sets minimum value in IntULandLL
int UpperLimit			sets maximum value in IntULandLL
float input				holds user response in FloatULandLL
float LowerLimit		sets minimum value in FloatULandLL
float UpperLimit		sets maximum value in FloatULandLL
char variable			Determine which variable the user is being asked for in QuadraticInput
int var					store the variable input by the user in QuadraticInput
int PosRoot				Stores answer (-b + sqrt(b^2) -4ac)/2a in QuadraticData
int NegRoot				Stores answer (-b - sqrt(b^2) -4ac)/2a in QuadraticData
int StopCalculation		Determine whether or not to go through with the calculation in QuadraticData
int max					Holds whichever value is larger of b^2 or 4ac
int irrational			Return value determining whether or not the equation can be solved in PreventIrrationals
float x					holds first number in MaxOf2
float y					holds second number in MaxOf2

Functions Called		What They Do
----------------		------------
MainLoop				Let's users repeat or end code
IntULandLL				Collects an int value from the user between preset limits
FloatULandLL			Collects a float value from the user between preset limits
MaxOf2					Determined the maximum of two numbers
QuadraticInput			Takes user input for the parts of the quadratic equation
PreventIrrationals		Calculates if b^2 is lower than 4ac to prevent negative square roots
QuadraticData			Solves the quadratic function and prints out the results

C:\User\Owner\My Documents\Visual Studio 2013\Projects\MP4
==========================================================*/

//precompiler directives
#include <stdio.h>
#include <math.h>

//function prototypes go here
int MainLoop();//function to let users repeat or end the code
int IntULandLL(int LowerLimit, int UpperLimit); //Int between limits
float FloatULandLL(float LowerLimit, float UpperLimit); //float between limits
float MaxOf2(float x, float y); //determining the maximum of two numbers
int QuadraticInput(char variable [50]); //takes user input for the parts of a quadratic equation
int PreventIrrationals(int a, int b, int c); //calculates if b^2 is lower than 4ac to prevent negative square roots
void QuadraticData(int a, int b, int c); //actually solves the quadratic function and prints out the results



int main (void) //main function
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Solves User-Given Quadrtaic Equations	Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	int MainLoopInput		store whether or not user wants to repeat the function
	int a					Store a in ax^2 + bx + c = 0
	int b					Store b in ax^2 + bx + c = 0
	int c					Store c in ax^2 + bx + c = 0

	Functions Called		What They Do
	----------------		------------
	MainLoop				Let's users repeat or end code
	QuadraticInput			Takes user input for the parts of the quadratic equation
	QuadraticData			Solves the quadratic function and prints out the results
	==========================================================*/
	//insert code here

	int MainLoopInput = 1; //set as 1 so main runs at least once
	int a;
	int b;
	int c; //for quadratic values

	while (MainLoopInput == 1){
		a = QuadraticInput("a"); //input a
		b = QuadraticInput("b"); //input b
		c = QuadraticInput("c"); //input c
		QuadraticData(a, b, c); //solves using a, b, and c
		MainLoopInput = MainLoop();//determines whether or not user wants to repeat main
	}//end while

return 0;
} //end main function




//insert function definitions here
int MainLoop()
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Does the User Want to Rerun Code?		Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	int MainLoopInput		holds value to determine answer

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	int MainLoopInput;
	printf("Do you want to run the program again? \nEnter 1 to continue the program, anything else will exit."); //exit prompt
	scanf_s("%d", &MainLoopInput, 1); //scan user response
	return MainLoopInput; //returns answer
}//End MainLoop

int IntULandLL(int LowerLimit, int UpperLimit) //take in int between limits
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Int value between boundaries			Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	int input				holds user response
	int LowerLimit			sets minimum value
	int UpperLimit			sets maximum value

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	int input;
	do {
		printf("Enter a number between %d and %d.", LowerLimit, UpperLimit); //number prompt
		scanf_s("%d", &input, 50); //scan number
	} while (input < LowerLimit || input > UpperLimit); //keeps doing this until the nubmer is within the prompt
	return input; //returns number
}//end IntULandLL

float FloatULandLL(float LowerLimit, float UpperLimit)//take in float between limits
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Float value between boundaries			Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	float input				holds user response
	float LowerLimit		sets minimum value
	float UpperLimit		sets maximum value

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	float input;
	do {
		printf("Enter a number between %f and %f.", LowerLimit, UpperLimit); //number prompt
		scanf_s("%f", &input, 50); //scan number
	} while (input < LowerLimit || input > UpperLimit); //repeats until number is within limits
	return input; //returns number
}//end FloatULandLL

int QuadraticInput(char variable [50]) //takes user input for the variable values
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Takes in input for quadratic values		Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	char variable			Determine which variable the user is being asked for
	int var					store the variable input by the user

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	int var;
	printf("Using the format 'ax^2 + bx + c = 0', enter %s.", variable); //prompts for number
	scanf_s("%d", &var, 50); //scans number

	return var; //returns number
}//end QuadraticInput

void QuadraticData(int a, int b, int c)//actually does the math
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Output quadratic answers				Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	int a					Store a in ax^2 + bx + c = 0
	int b					Store b in ax^2 + bx + c = 0
	int c					Store c in ax^2 + bx + c = 0
	int PosRoot				Stores answer (-b + sqrt(b^2) -4ac)/2a
	int NegRoot				Stores answer (-b - sqrt(b^2) -4ac)/2a
	int StopCalculation		Determine whether or not to go through with the calculation

	Functions Called		What They Do
	----------------		------------
	PreventIrrationals		prevents calculating quadratics that can't be solved this way
	==========================================================*/
	int PosRoot;
	int NegRoot;
	int StopCalculation;
	printf("Quadratic Equation : %dx^ 2 + %dx + %d\n", a, b, c); //prints the equation
	StopCalculation = PreventIrrationals(a, b, c); //determines whether or not the calculations should stop
	if (StopCalculation == 0)//do the actual math
	{
		PosRoot = ((-b + (sqrt(pow(b, 2) - 4 * a*c))) / 2 * a); //two roots bc it's -b +/- ... 
		NegRoot = ((-b - (sqrt(pow(b, 2) - 4 * a*c))) / 2 * a);
		printf("The roots are: x = %d and x = %d\n", PosRoot, NegRoot); //prints results
	}//end calculation then
}//end QuadraticData

int PreventIrrationals(int a, int b, int c)
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Exit code to prevent irrational roots	Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	int a					Store a in ax^2 + bx + c = 0
	int b					Store b in ax^2 + bx + c = 0
	int c					Store c in ax^2 + bx + c = 0
	int max					Holds whichever value is larger of b^2 or 4ac
	int irrational			Return value determining whether or not the equation can be solved

	Functions Called		What They Do
	----------------		------------
	MaxOf2					Determines the maximum of two numbers
	==========================================================*/
	int max;
	int irrational = 0;
	max = MaxOf2((pow(b, 2)), (4*a*c)); //determines the maximum of the two
	if (max == (4 * a*c)) //if the max is 4ac then there would be an irrational root
	{
		printf("Sorry, that would result in an irrational root.\n");//print reasoning
		irrational = 1;
	}//exit neg square then
	//scanf_s("%d", &max, 50);
	if (a == 0) //if a is 0 then division by zero would occur 
	{
		printf("A can't be zero, that's not a quadratic function and would cause dividing by zero, which is impossible to do.\n");//print reasoning
		irrational = 1;
	}//end prevent dividing by zero then
	return irrational; //returns irrational 1 (true) or 0 (false)
}//end PreventIrrationals


float MaxOf2(float x, float y) //determine max of two numbers
{
	/* ========================================================
	Leah Perry								  CIS 160 Fall 2014
	MP4							 			Submitted: 10/28/14
	Determines maximum of two numbers		Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	float x					holds first number
	float y					holds second number
	float max				holds higher number

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	float max;
	float min;
	if (x >= y) //if x>=y then x is max
	{
		max = x;
	}//end then
	else //otherwise y is max
	{
		max = y;
	}//end else

	return max;//returns maximum value
}//end MaxOf2
