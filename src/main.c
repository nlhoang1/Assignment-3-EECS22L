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
    char inputFile[256];

    // Prompt user for input file
    printf("Input the SRS file: ");
    if (scanf("%255s", inputFile) != 1) {
        fprintf(stderr, "Error: Failed to read input.\n");
        return 1;
    }

    printf("Source file: %s\n", inputFile);

    // Print the first 3 lines of the file
    file = fopen(inputFile, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", inputFile);
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
    int reqCount = parseSRS(inputFile, reqs, MAX_REQS);

    // Print and generate dependency graph/report
    if (reqCount > 0) {
        // Build dependency graph
        DepList graph[MAX_REQS];
        createDepGraph(reqs, reqCount, graph);

        // Print dependency graph to console
        printDepGraph(graph, reqCount);

        // Generate report file (replace 01234567 with your actual student ID)
        CreateReport(graph, reqCount, "rdgg-report-01234567.md");
        printf("Report generated: rdgg-report-01234567.md\n");
    } else {
        printf("No requirements found or error parsing file.\n");
    }

    return 0;
}
