#include "movie.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <strings.h>

int movie_create(struct movie *self, const char *name, int day, int month, int year){
  assert(self);
  assert(name);
  if (date_from_int(&self->release_date, day, month, year)){
    self->name = NULL;
    return -1;
  }
  self->name = calloc(strlen(name)+1, sizeof(char));
  if (! self->name){
    fprintf(stderr, "Memory allocation failure.\n");
    return -1;
  }
  strcpy(self->name, name);
  return 0;
}

void movie_destroy(struct movie *self){
  assert(self);
  free(self->name);
  bzero(self, sizeof(struct movie));
}

void movie_print(const struct movie *self){
  assert(self);
  if (! self->name){
    printf("Empty movie\n");
    return;
  }
  char s[STRING_DATE_SIZE];
  assert (! date_to_string(&self->release_date, s, STRING_DATE_SIZE));
  printf("Name : %s, release date : %s\n", self->name, s);
}
