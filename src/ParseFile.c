// ParseFile.c
// This program parses through inputed SRS file and gathers the requirements
#include "ParseFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Parse through the markdown SRS file and fill num array of requirements
int parseSRS(const char *filename, Requirement *reqs, int max_reqs) {
    // Declare variables for file handling and regex
    FILE *file = fopen(filename, "r");
    char line[1024];
    int lineno = 0;
    regex_t regex;
    regmatch_t matches[1];

    // Define the regex pattern for requirement tags: REQ-XX-YYYY-DDDD
    const char *pattern = "REQ-[A-Z]{2}-[A-Z]{4}-[0-9]{4}";

    // Compile the regex pattern
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        fprintf(stderr, "Could not compile regex\n");
        return -1;
    }

    // Check if the file was opened successfully
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        regfree(&regex);
        return -1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        lineno++; // Increment line number

        char *cursor = line; // Pointer to traverse the line

        // Search for all matches of the requirement tag in the current line
        while (regexec(&regex, cursor, 1, matches, 0) == 0) {
            int start = matches[0].rm_so; // Start index of match
            int end = matches[0].rm_eo;   // End index of match

            // Extract the matched tag into a buffer
            char tag[17];
            strncpy(tag, cursor + start, end - start);
            tag[end - start] = '\0';

            // Print the line number and the found tag
            printf("%04d: %s\n", lineno, tag);

            // Move the cursor forward to continue searching for more tags in the same line
            cursor += end;
        }
    }

    // Clean up: close the file and free the regex resources
    fclose(file);
    regfree(&regex);
    return 0;
}




