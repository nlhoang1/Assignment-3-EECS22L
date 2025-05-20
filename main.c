//main.c 
#include "DepGraph.h"
#include "Report.h"
#include "ParseFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
void main(int argc, char *argv[]) {
    //get source file name
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return;
    }

    // Initialize the dependency graph
    DependencyGraph *graph = createDependencyGraph();
    if (!graph) {
        fprintf(stderr, "Failed to create dependency graph\n");
        return;
    }

    // Parse the source file and populate the dependency graph
    if (parseFile(argv[1], graph) != 0) {
        fprintf(stderr, "Failed to parse file: %s\n", argv[1]);
        freeDependencyGraph(graph);
        return;
    }

    // Generate the report
    generateReport(graph);

    // Clean up
    freeDependencyGraph(graph);
}
