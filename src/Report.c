//Report.c
// Module that generates a report of the requirement dependency graph
#include "Report.h"
#include "DepGraph.h"
#include <stdio.h>
#include <string.h>

/*
 * Generates a markdown report of the dependency graph.
 * The format matches the provided sample.
 */
void CreateReport(const DepList *graph, int num_reqs, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error: Could not open report file for writing.\n");
        return;
    }

    // Header
    fprintf(f, "# <center>Software Requirements Specification </center>\n");
    fprintf(f, "<center> EECS 22L - Spring 2025 </center>\n");
    fprintf(f, "<center> Project 1 - Chess Game </center>\n\n"); // Blank line after header

    for (int i = 0; i < num_reqs; i++) {
        // Record line
        fprintf(f, "Line %d: %s --\n", graph[i].line_number, graph[i].id);

        // Parent dependencies
        for (int p = 0; p < graph[i].num_parents; p++) {
            fprintf(f, "Line %d: %s -> %s\n", graph[i].parent_lines[p], graph[i].parents[p], graph[i].id);
        }

        // Child dependencies
        for (int c = 0; c < graph[i].num_children; c++) {
            fprintf(f, "Line %d: %s -> %s\n", graph[i].child_lines[c], graph[i].id, graph[i].children[c]);
        }
    }

    fclose(f);
}