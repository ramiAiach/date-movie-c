#include "movie.h"

#include <stdio.h>
#include <stdlib.h>



int main(){
  printf("%s\n", year_is_a_leap_year(1999)? "true":"false");
  printf("%s\n", year_is_a_leap_year(2020)? "true":"false");
  printf("%s\n", year_is_a_leap_year(2100)? "true":"false");
  printf("%s\n\n", year_is_a_leap_year(2000)? "true":"false");

  printf("%s\n", date_is_valid(29, 2, 1999)? "true":"false");
  printf("%s\n", date_is_valid(29, 2, 2000)? "true":"false");
  
  struct date d;
  printf("%d\n", date_from_int(&d, 31, 10, 1600));
  char t[STRING_DATE_SIZE];
  printf("%d\n", date_to_string(&d, t, STRING_DATE_SIZE));
  printf("Date : %s\n", t);
  printf("%d\n", date_from_string(&d, t));
  printf("%d %d %d\n\n", d.day, d.month, d.year);
  
  printf("%d\n", date_from_int(&d, 29, 2, 1999));
  printf("%d %d %d\n", d.day, d.month, d.year);
  printf("%d\n", date_from_string(&d, "29/2/2000"));
  printf("%d %d %d\n", d.day, d.month, d.year);
  printf("%d\n", date_from_string(&d, "29/2/1999"));
  printf("%d %d %d\n\n", d.day, d.month, d.year);
  
  struct movie m;
  movie_create(&m, "Matrix Resurrections", 22, 12, 2021);
  movie_print(&m);
  movie_destroy(&m);

  return 0;
}
