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
//(STUB) get user input for source file name, parse the file, print dependency graph, and generate report
void main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int i;

    //get user input for source file name
    if (argc < 2) {
         
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return;
        //print file name and first 3 lines of the file
        printf("Source file: %s\n", argv[1]);
    }
    // Print the selected file name
    printf("Source file: %s\n", argv[1]);

    // Open the file for reading
    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    // Print the first 3 lines of the file
    for (i = 0; i < 3; i++) {
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        } else {
            break; // Less than 3 lines in file
        }
    }
    // (LATER) code to parse the file

    // (LATER) code to print the dependency graph

    // (LATER) code to generate the report
}
