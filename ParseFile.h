//ParseFile.h
#ifndef PARSEFILE_H
#define PARSEFILE_H

#include "graph.h"  // For struct Requirement or similar

// Parses the markdown file and returns an array/list of requirements
// filename: path to the markdown file
Requirement* parse_srs(const char *filename, int *req_count);

#endif // PARSER_H
