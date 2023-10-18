/*
 * File: calendar.c
 * ----------------
 * This program is used to generate a calendar for a year
 * entered by the user.
 *
 */
#include<stdio.h>

/*
 * Constants
 * ---------
 * Days of the week are representd by the integers 0-6.
 *
 */
#define Sunday		7
#define	Monday		1
#define Tuesday		2
#define Wednesday	3
#define	Thursday	4
#define	Firday		5
#define	Saturday	6

/*
* Constants
* ----------
* MonthName converts a numeric month in the range 1-12
* into the string name for that month.
*/
const char *MonthName[] = {"","January", "February", "March",
"April", "May", "June","July","August","September","October",
"November","December"};


/*
 * Function: GiveInstructions
 * Usage: GiveInstructions();
 * --------------------------
 * This procedure prints out instructions to the user.
 */
void GiveInstructions(void)
{
	printf("This program displays a callendar for a full year. \n");
	printf("The year must not be before 1900.\n");
}

/*
 * Function: GetYearFromUser
 * Usage: year = GetYearFromUser();
 * --------------------------------
 * This function reads in a year from the user and returns
 * that value. If the user enters a year before 1900, the
 * function gives the user another chance.
*/
int GetYearFromUser(void)
{
	int year;
	
	while(1){
		printf("Which year? ");
		scanf("%d", &year);
		if (year >= 1900) return year;
		printf("The year must be at least 1900.\n");	
	}
}

/*
 * Function: IndentFirstLine
 * Usage: IndentFirstLine(weekday);
 * ---------------------------
 * This procedure indents the first line of the calendar
 * by printing engough blank spaces to get to the position
 * on the line corresponding to weekday.
*/
void IndentFirstLine(int weekday)
{
	int w;
	
	for(w = 1; w < weekday; w++)
		printf("   ");
}

/*
 * Function: MonthDays
 * Usage: MonthDays(month, year);
 * ---------------------------
 * MonthDays returns the number of days in the indicated
 * month and year. The year is required to handle leap years.
*/
int MonthDays(int month, int year)
{
	switch(month)
	{
		case 2: return 28 + IsLeapYear(year);
		case 4: case 6: case 9: case 11:return 30;
		default: return 31;
	}
}

/*
 * Function: IsLeapYear
 * Usage: IsLeapYear(year);
 * ---------------------------
 * This function returns TRUE if year is a leap year.
 */  
int IsLeapYear(int year)
{
	return year%4==0 && year%100!=0 || year % 400 == 0;
}

/*
 * Function: FirstDayofMonth
 * Usage: FirstDayofMonth(month, year);
 * ---------------------------
 * This function returns the day of the week on which the 
 * indicated month begins, This program simply counts
 * forward from January 1, 1900, which was a Monday.
*/
int FirstDayofMonth(int month, int year)
{
	int weekday = Monday;
	int i;
	
	for(i = 1900; i < year; i++) {
		weekday = (weekday + 365 + IsLeapYear(i)) % 7;
	}
	
	for(i = 1; i < month; i++) {
		weekday = (weekday + MonthDays(i, year)) % 7;
	}
	
	if (weekday == 0) weekday = Sunday;
	
	return weekday;
}

/*
 * Function: PrintCalendarMonth
 * Usage: PrintCalendarMonth(month,year);
 * --------------------------------------
 * This procedure prints a calendar for the given month
 * and year.
*/
void PrintCalendarMonth(int month, int year)
{
	int nDays, weekday, day;
	
	printf("   %s %d\n", MonthName[month], year);
	printf(" Mo Tu We Th Fr Sa Su\n");
	
	nDays = MonthDays(month, year);
	weekday = FirstDayofMonth(month, year);
	IndentFirstLine(weekday);
	for(day = 1; day <= nDays; day++) {
		printf(" %2d", day);
		if (weekday == Sunday) printf("\n");
		weekday = weekday % 7 + 1;
	}
	printf("\n");
}


/*
 * Function: PrintCalendar
 * Usage: PrintCalendar(year);
 * ---------------------------
 * This procedure prints a calendar for an entire year.
*/
void PrintCalendar(int year)
{
	int month;
	
	for(month = 1; month <= 12; month++) {
		PrintCalendarMonth(month, year);
		printf("\n");
	}
}

int main()
{
	int year;
	
	GiveInstructions();
	year = GetYearFromUser();
	PrintCalendar(year);
} 
