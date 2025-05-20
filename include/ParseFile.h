//ParseFile.h
#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <stdio.h>

//Struct to hold a parsed requirement
typedef struct {
    char id[50];
    char description[256];
} Requirement;

//Parses the markdown SRS file and fills the array of requirements.
//filename = path to the markdown SRS file
// reqs = array of Requirement structs to fill
//max_reqs Maximum number of requirements to parse
//returns number of requirements parsed, or return -1 for error
int parseSRS(const char *filename, Requirement *reqs, int max_reqs);

#endif