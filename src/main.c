//main.c 
//Module that contains the main function for the program
// This program generates a dependency graph from a source file and prints the graph
// and generates a report. Uses all modules to parse the file, build the graph, and generate the report
#include "DepGraph.h"
#include "Report.h"
#include "ParseFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_REQS 100

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }
    printf("Source file: %s\n", argv[1]);

    // Print the first 3 lines of the file
    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }
    for (i = 0; i < 3; i++) {
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        } else {
            break;
        }
    }
    fclose(file);

    // Parse requirements
    Requirement reqs[MAX_REQS];
    int reqCount = parseSRS(argv[1], reqs, MAX_REQS);

    // Print dependency graph
    if (reqCount > 0) {
        printDepGraph(reqs, reqCount);
    } else {
        printf("No requirements found or error parsing file.\n");
    }

    // (LATER) code to generate the report
    return 0;
}
