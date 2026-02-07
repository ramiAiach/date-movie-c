#ifndef DATELIB_H 
#define DATELIB_H 

#include <stddef.h>
#include <stdbool.h>


/**
 * @brief The year must be between YEAR_MIN and YEAR_MAX inclusive.
 */
#define YEAR_MIN 1582
#define YEAR_MAX 9999

/**
 * @brief the minimum size of a char array used to contain a string that represents a Gregorian date in the format "DD/MM/YYYY", including the terminating null byte ('\0').
 */
#define STRING_DATE_SIZE 11

/**
 * @brief Structure to represent a Gregorian date
 */
struct date{
  int day;
  int month;
  int year;
};

/**
 * @brief Checks if a year is a leap year.
 * 
 * @param year the year to check
 * @return bool Returns true if the year is a leap year, false otherwise
 */
bool year_is_a_leap_year(int year);

/**
 * @brief Checks if a date is a valid Gregorian date. 
 * 
 * The year must be between YEAR_MIN and YEAR_MAX inclusive.
 * The month must be between 1 and 12 inclusive. 
 * The day must be within the allowed number of days for the given month. Leap years are taken into consideration. 
 * 
 * @param day the day of the date
 * @param month the month of the date
 * @param year the year of the date
 * @return bool Returns true if the date is a valid Gregorian date
 */
bool date_is_valid(int day, int month, int year);

/**
 * @brief Converts a date to a string that represents it. 
 * 
 * The format used is "DD/MM/YYYY".
 * 
 * @param self pointer to the date to Convert
 * @param str pointer to the first element of the char array that receives the result 
 * @param size size of the char array allocated by the caller (must be >= STRING_DATE_SIZE)
 * @return int Returns 0 if no error occurs, -1 if size < STRING_DATE_SIZE, -2 if the date is invalid  
 */
int date_to_string(const struct date *self, char *str, size_t size);

/**
 * @brief Constructs a date from 3 int. 
 * 
 * @param self pointer to the date to construct
 * @param day the day of the date
 * @param month the month of the date
 * @param year the year of the date
 * @return int Returns 0 if the date is a valid Gregorian date, -1 otherwise  
 */
int date_from_int(struct date *self, int day, int month, int year);

/**
 * @brief Constructs a date from a string. 
 * 
 * The format of the incoming string must be "DD/MM/YYYY".
 * 
 * @param self pointer to the date to construct
 * @param str pointer to the first element of the string that must represent a valid Gregorian date
 * @return int Returns 0 if the string represents a valid Gregorian date, -1 otherwise  
 */
int date_from_string(struct date *self, const char *str);

#endif /* DATELIB_H */
