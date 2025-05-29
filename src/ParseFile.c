// ParseFile.c
// This program parses through inputed SRS file and gathers the requirements
#include "ParseFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Helper to trim whitespace
static void trim(char *str) {
    char *end;
    while (*str == ' ' || *str == '\t') str++;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) *end-- = '\0';
}

// Parse through the markdown SRS file and fill array of requirements
int parseSRS(const char *filename, Requirement *reqs, int max_reqs) {
    // Declare variables for file handling and regex
    FILE *file = fopen(filename, "r");
    char line[1024];
    int lineno = 0;
    int reqCount = 0;
    Requirement currentReq;
    int inReq = 0;

    // Check if the file was opened successfully
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return -1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        lineno++; // Increment line number

        // Check for requirement ID line
        if (strncmp(line, "ID:", 3) == 0) {
            // If already inside a requirement and we have not yet reached the max limit, save the current requirement
            if (inReq && reqCount < max_reqs) {
                reqs[reqCount++] = currentReq;
            }
            // Initialize a new requirement
            memset(&currentReq, 0, sizeof(Requirement));
            inReq = 1;
            // Extract ID
            char *id_start = strstr(line, "REQ-");
            if (id_start) {
                sscanf(id_start, "%49s", currentReq.id);
                currentReq.line_number = lineno;
            }
        } 
        // Check for Parents line
        else if (strstr(line, "Parents:")) {
            char *p = strchr(line, ':');
            if (p) {
                strncpy(currentReq.parents, p + 1, sizeof(currentReq.parents) - 1);
                trim(currentReq.parents);
                currentReq.parent_line = lineno;
            }
        } 
        // Check for Children line
        else if (strstr(line, "Children:")) {
            char *p = strchr(line, ':');
            if (p) {
                strncpy(currentReq.children, p + 1, sizeof(currentReq.children) - 1);
                trim(currentReq.children);
                currentReq.child_line = lineno;
            }
        } 
        // Check for Description line
        else if (strstr(line, "Description:")) {
            char *p = strchr(line, ':');
            if (p) {
                strncpy(currentReq.description, p + 1, sizeof(currentReq.description) - 1);
                trim(currentReq.description);
            }
        }
    }
    // Add the last requirement if file ends after a record
    if (inReq && reqCount < max_reqs) {
        reqs[reqCount++] = currentReq;
    }

    // Clean up: close the file and free the regex resources
    fclose(file);
    return reqCount;
}




