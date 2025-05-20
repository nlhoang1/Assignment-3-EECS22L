// ParseFile.c
// This program parses inpuuted SRS file 
#include "ParseFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// (STUB) parse through the markdown SRS file and fill the array of requirements
int parse_srs_file(const char *filename, Requirement *reqs, int max_reqs) {
    // TODO: Implement markdown parsing logic
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    // (STUB) Pretend we read and parsed one requirement
    if (max_reqs > 0) {
        strcpy(reqs[0].id, "REQ-001");
        strcpy(reqs[0].description, "This is a stub requirement.");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}




