//ParseFile.h
#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <stdio.h>

// define struct to hold a parsed requirement
typedef struct {
    char id[50];
    char description[256];
    // Add other fields like priority, dependencies, etc.
} Requirement;

/**
 * Parses the markdown SRS file and fills the array of requirements.
 * 
 * @param filename The path to the markdown SRS file.
 * @param reqs Array of Requirement structures to populate.
 * @param max_reqs Maximum number of requirements to parse.
 * @return The number of requirements parsed, or -1 on error.
 */
//Parses the SRS file and fills the array of requirements
int parse_srs_file(const char *filename, Requirement *reqs, int max_reqs);

#endif