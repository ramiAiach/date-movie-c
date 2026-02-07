#ifndef MOVIE_H 
#define MOVIE_H

#include "date.h"

/**
 * @brief Structure to represent a movie
 */
struct movie{
  char *name;
  struct date release_date;
};

/**
 * @brief Creates a movie.
 * 
 * The release date must be a valid Gregorian date
 * 
 * @param self pointer to the movie to create
 * @param name the name of the movie
 * @param day the day of the release date
 * @param month the month of the release date
 * @param year the year of the release date
 * @return int Returns 0 if no error occurs, -1 otherwise
 */
int movie_create(struct movie *self, const char *name, int day, int month, int year);

/**
 * @brief Destroys a movie.
 * 
 * @param self pointer to the movie to destroy
 */
void movie_destroy(struct movie *self);

/**
 * @brief Prints a movie.
 * 
 * @param self pointer to the movie to print
 */
void movie_print(const struct movie *self);

#endif /* MOVIE_H */
