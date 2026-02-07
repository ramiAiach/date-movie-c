#include "date.h"

#include <assert.h>
#include <string.h>

bool year_is_a_leap_year(int year){
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool date_is_valid(int day, int month, int year){
  if (year < YEAR_MIN || year > YEAR_MAX){
    return false;
  }
  if (month < 1 || month > 12){
    return false;
  }
  int tab[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year_is_a_leap_year(year)){
    tab[1] = 29;
  }
  if (day < 1 || day > tab[month - 1]){
    return false;
  }
  return true;
}

int date_to_string(const struct date *self, char *str, size_t size){
  assert(self);
  if (size < STRING_DATE_SIZE){
    return -1;
  }
  if (self->day <= 0){
    return -2;
  }
  assert(date_is_valid(self->day, self->month, self->year));
  str[0] = self->day/10 + '0';
  str[1] = self->day%10 + '0';
  str[2] = '/';
  str[3] = self->month/10 + '0';
  str[4] = self->month%10 + '0';
  str[5] = '/';
  int y = self->year;
  str[6] = y/1000 + '0';
  y -= y/1000*1000;
  str[7] = y/100 + '0';
  y -= y/100*100;
  str[8] = y/10 + '0';
  str[9] = y%10 + '0';
  str[10] = '\0';
  return 0;
}

int date_from_int(struct date *self, int day, int month, int year){
  assert(self);
  if (!date_is_valid(day, month, year)){
    self->year = self->month = self->day = -1;
    return -1;
  }
  self->year = year;
  self->month = month;
  self->day = day;
  return 0;
}

int date_from_string(struct date *self, const char *str){
  assert(self);
  assert(str);
  int tab[3] = {0, 0, 0}; //jour, mois, année
  size_t l = strlen(str);
  bool error = false;
  for (size_t i = 0, j = 0; i < l && !error; ++i){
    if (str[i] == '/'){
      ++j;
      if (j == 3){
        error = true;
      }
      continue;
    }
    if (str[i] < '0' || str[i] > '9'){
      error = true;
      break;
    }
    tab[j] = tab[j]*10 + str[i] - '0'; 
  }
  if (error || !date_is_valid(tab[0], tab[1], tab[2])){
    self->year = self->month = self->day = -1;
    return -1;
  }
  self->day = tab[0];
  self->month = tab[1];
  self->year = tab[2];
  return 0;
}
