// ParseFile.c
// This program parses through inputed SRS file and gathers the requirements
#include "ParseFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// (STUB) parse through the markdown SRS file and fill num array of requirements
int parseSRS(const char *filename, Requirement *reqs, int max_reqs) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    int lineno = 0;
    regex_t regex;
    regmatch_t matches[1];

    // Regex for REQ-XX-YYYY-DDDD
    const char *pattern = "REQ-[A-Z]{2}-[A-Z]{4}-[0-9]{4}";
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        fprintf(stderr, "Could not compile regex\n");
        return -1;
    }

    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        regfree(&regex);
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        lineno++;
        char *cursor = line;
        int offset = 0;
        while (regexec(&regex, cursor, 1, matches, 0) == 0) {
            int start = matches[0].rm_so;
            int end = matches[0].rm_eo;
            char tag[17];
            strncpy(tag, cursor + start, end - start);
            tag[end - start] = '\0';
            printf("%04d: %s\n", lineno, tag);
            cursor += end;
            offset += end;
        }
    }

    fclose(file);
    regfree(&regex);
    return 0;
}




