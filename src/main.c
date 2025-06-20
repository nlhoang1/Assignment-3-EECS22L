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
    char inputFile[512];

    //prompt user for input file path until a valid file is opened or 'x' to exit
    while (1) {
        printf("Input the SRS file (or 'x' to exit): ");
        if (fgets(inputFile, sizeof(inputFile), stdin) == NULL) {
            fprintf(stderr, "Error: Failed to read input.\n");
            return 1;
        }
        //Remove trailing newline if present
        size_t len = strlen(inputFile);
        if (len > 0 && inputFile[len - 1] == '\n') {
            inputFile[len - 1] = '\0';
        }

        //exit if user enters 'x' or 'X'
        if (strcmp(inputFile, "x") == 0 || strcmp(inputFile, "X") == 0) {
            printf("Exiting program.\n");
            return 0;
        }

        file = fopen(inputFile, "r");
        if (!file) {
            fprintf(stderr, "Error: Could not open file '%s'. Please try again.\n", inputFile);
        } else {
            break; 
        }
    }

    printf("Source file: %s\n", inputFile);

    //Print the first 3 lines of file
    for (i = 0; i < 3; i++) {
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        } else {
            break;
        }
    }
    printf("\n");
    fclose(file);

    //Parse requirements from the SRS file (use ParseFile module)
    Requirement reqs[MAX_REQS];
    int reqCount = parseSRS(inputFile, reqs, MAX_REQS);

    //print and generate dependency graph/report
    if (reqCount > 0) {
        //build dependency graph (use DepGraph module)
        DepList graph[MAX_REQS];
        createDepGraph(reqs, reqCount, graph);

        //print dependency graph to terminal (use DepGraph module)
        printDepGraph(graph, reqCount);

        //create report file (future implementation: replace 01234567 with student ID)
        CreateReport(graph, reqCount, "rdgg-report-17583771.md");
        printf("Report generated: rdgg-report-17583771.md\n");
    } else {
        printf("No requirements found or error parsing file.\n");
    }

    return 0;
}
