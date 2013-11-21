// ************************  PROGRAM IDENTIFICATION  ***********************
// *                                                                       *
// *   PROGRAM FILE NAME:  Program1.cc		ASSIGNMENT #: 1                *
// *                                                                       *
// *   PROGRAM AUTHOR: 													   *
// *                    Michael Lidnvall                                   *
// *                                                                       *
// *   COURSE #:  CSC 100-11                 DUE DATE: April 21, 2006      *
// *                                                                       *
// *************************************************************************

// ************************  PROGRAM DESCRIPTION  **************************
// *                                                                       *
// *   MAJOR CONSTANTS:		MaxTemp	- the maxium Celsius temperature       *
// *                                  to be converted                      *
// *                                                                       *
// *   INPUT VARIABLES: 	NONE                                           *
// *                                                                       *
// *   OUTPUT VARIABLES:	DegCel	- holds the temperature in degrees     *
// *                                  Celsius                              *
// *                    	DegFah	- holds the temperature in degrees     *
// *                                  Fahrenheit                           *
// *                                                                       *
// *   OTHER VARIABLES:		NONE                                           *
// *                                                                       *
// *   PROCESS:  This program is designed to print a temperature           *
// *   converstion table.  It prints out a listing of temperatures in      *
// *   degress Celsius along with the corresponding Fahrenheit             *
// *   temperatures.  The table with give the Fahrenheit equivalent        *
// *   temperature for each of the indicated Celsius temperatures          *
// *   between -40 degrees and +50 degrees, in steps of 2 degrees.         *
// *                                                                       *
// *   LIST OF FUNCTIONS:	Header - Prints the output preamble            *
// *                        Footer - Prints the output postscript          *
// *                                                                       *
// *************************************************************************
			// list header files used
#include <fstream.h>
#include <iostream.h>
#include <math.h>
#include <iomanip.h>
			// Define program constrants
#define Blank ' '

			// Declare FUNCTION PROTOTYPES
void Header (ofstream);
void Footer (ofstream) ;
// ************************  MAIN FUNCTION  ********************************
int main()
{
			// Open a file for output
	ofstream Outfile("P1_output", ios::out);
	
			// Set the numeric display format to FIXED DECIMAL, two
			// decimal places.  Set placement within the print field
			// to LEFT justify and field width to nine characters
	Outfile.precision(2);
	Outfile.setf(ios::fixed | ios::left);
	
			// Declare and Initialize Variables
	float MaxTemp = 50.0;
	float DegCel  = -40.0;
	float DegFah;
	
			// Print the OUTPUT Preamble
	Header(Outfile);
	
			// Set justification to RIGHT justify
	Outfile.unsetf(ios::left);
	
				// Print Output Heading
	Outfile << "   DEGREES      DEGREES"   << endl;
	Outfile << "   CELSIUS     FAHRENHEIT" << endl;
	Outfile << " ---------   ------------" << endl;
	
			// Compute Table Values
			// and Print the Table
	while (DegCel <= MaxTemp)
	{
		DegFah = ( (DegCel * 9.0) / 5.0 ) + 32.0;
		Outfile << setw(3) << Blank
		        << setw(6) << DegCel
				<< setw(8) << Blank
				<< setw(8) << DegFah << endl;
		DegCel += 2.0;
	}
			// Print the End of Output Message
	Footer(Outfile);
	
		return 0;	// end of function main
}
// ************************  FUNCTION HEADER  ******************************
void Header(ofstream Outfile)
{
			// Recieves - the output file
			// Task - Prints the output preamble
			// Returns - Nothing
	Outfile << setw(30) << "Michael Lindvall";
	Outfile << setw(17) << "CSC 100";
	Outfile << setw(15) << "Section # 11" << endl;
	Outfile << setw(30) << "Spring 2006";
	Outfile << setw(20) << "Assignment #1" << endl;
	Outfile << setw(35) << "-----------------------------------";
	Outfile << setw(35) << "-----------------------------------"
			<< endl		<< endl;
	return;
}
// ************************  FUNCTION FOOTER  ******************************
void Footer(ofstream Outfile)
{
			// Recieves - the output file
			// Task - Prints the end of output message
			// Returns - Nothing
	Outfile << endl << endl;
	Outfile << "         END OF OUTPUT " << endl;
	return;
}
// ****************   END OF PROGRAM SOURCE CODE   *************************