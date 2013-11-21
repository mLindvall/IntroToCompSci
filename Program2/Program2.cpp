// ******************************************************************
// *                                                                *
// *   File Name:  Program2.ccp       Due Date: May 5, 2006         *
// *                                                                *
// *   Author:                                                      *
// *              Michael Lindvall                                  *
// *                                                                *
// *   Course:  CSC 100	              Section: 11                   *
// *                                                                *
// ******************************************************************
#include <fstream.h>
#include <iostream.h>
#include <iomanip.h>

#define Blank ' '

int main()
{
				// Declare program variables
	int Months, Count;
	float InterestRate, Principle, MonthlyPayment;
	float AmtApplied, TotalApplied=0;
	float OldBalance, NewBalance, Interest, TotalInterest=0.0;
	char Name[60];

				// Declare an output file
	ofstream outfile ("Table" , ios::out);

				// Set the output format codes
	outfile.setf(ios::fixed | ios::right);
	cout.setf(ios::fixed | ios::right);
	outfile.precision(2);
	cout.precision(2);

				// Get the barrower's name
	cout << "Please enter your full name. " << endl;
	cin.getline(Name, 70);
				
				// Input starting data
				// Get the starting Principle
	cout << endl << "Enter the amount of money you wish to borrow. " << endl;
	cout << "Enter a value between 1000.00 and 100000.00" << endl;
	cin >> Principle;

				// Get the interest Rate
	cout << endl << "Enter the interest rate you are to be charged for the " << endl
		 << "loan.  Enter an interest rate between 5.0 and 15.99" << endl;
	cout << "(Enter the value to two decimal points. "
		 << "For example:  9.25)" << endl;
	cin >> InterestRate;

				// Get the number of payments
	cout << endl << "Enter the number of months in which you will be making "
		 << "payments.  Enter the value between 12 and 360" << endl;
	cin >> Months;

				// Get monthly payment
	cout << endl << "Enter the amount for a monthly payment that you "
		 << "wish to pay. " << endl;
	cin >> MonthlyPayment;

				// Print the output greating
	for (int i=0; i < 30; i++)
		cout << endl;
	cout << "Thank you, " << Name << endl << endl;
	cout << "Here is your input data. " << endl << endl;
	cout << "	   ( NOTE: The results of this program hae been" << endl
		 << "              sent to a file on your disk called Table."<< endl
		 << "			   To view the results, open the file using" << endl
		 << "			   the C++ menu.  Remember to get a hard"    << endl
		 << "			   copy of the results for your instructor.)"<< endl;

				// Echo print the input data to the screen
	cout << endl << endl;
	cout << "              Loan Principle = " << setw(10) << Principle << endl << endl;
	cout << "              Interest Rate  = " << setw(10) << InterestRate << " %" ;
	cout << endl << endl;
	cout << "     Amt of Monthly Payment  = " << setw(10) << MonthlyPayment << endl << endl;
	cout << "  Number of Monthly Payment  = " << setw(7) << Months << endl;
	cout << endl << endl << endl << endl << endl << endl;

				// Echo print the input data to the output file
	outfile << " Here are your results,  " << Name << endl << endl << endl;
	outfile << "              Loan Principle = " << setw(10) << Principle << endl;
	outfile << "              Interest Rate  = " << setw(10) << InterestRate << " %" ;
	outfile << "     Amt of Monthly Payment  = " << setw(10) << MonthlyPayment << endl;
	outfile << "  Number of Monthly Payment  = " << setw(7)  << Months 
			<< endl << endl << endl;

				// Print the column headings for the table
	outfile << "			Beginning				Amount		End		" << endl
			<< "			of Month	Interest	Applied		of Month" << endl
			<< "Month		Balance		Paid		to Loan		Balance " << endl;
	outfile << "============================================================="<< endl;

				// Calculate the status of the loan after each payment and
				// print the results to the file.
	OldBalance = Principle;
	for (Count=1; Count <= Months; Count++)
	{
				// Calculate the amount of interest paid
		Interest = OldBalance * (InterestRate/100) / 12;
				// Calculate the amount of monthly payment applied to loan
		AmtApplied = MonthlyPayment - Interest;
				// Calculate the new balance owed
		NewBalance = OldBalance - AmtApplied;

				// Print the table entry for the month
		outfile << setw(3)	<< Count		<< setw(16) << OldBalance
				<< setw(11)	<< Interest		<< setw(11) << AmtApplied
				<< setw(14)	<< NewBalance	<< endl;

				// Set Old Balance to New Balance
		OldBalance = NewBalance;

				// Accumulate Total Interest paid and Toatl Applied to Loan
		TotalInterest += Interest;
		TotalApplied  += AmtApplied;
	}
				// Print the end of table marker
	outfile << "============================================================="
			<< endl << endl;

				// Print the Total Amount of interest paid
	outfile << "	  The Total Interest Paid to date on this loan is: "
			<< setw(8) << TotalInterest << endl << endl;

				// Print the Total Amount of Principle Paid Off
	outfile << "	  The Total Amount of Principle Paid Off to date ";
	outfile << endl << "	  on this loan is: "
			<< setw(40) << TotalApplied << endl << endl;

				// Print Total Cost of this Loand
	outfile << "	  The total amount of money paid out is: "
			<< setw(18) << TotalInterest + TotalApplied << endl << endl;

	outfile << "            --------------------" << endl;
	outfile << "Thank you for your Business!	Please Come Again ! " << endl;

	return 0;
}