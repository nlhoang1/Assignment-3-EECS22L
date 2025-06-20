//Report.c
// Module that generates a report of the requirement dependency graph
#include "Report.h"
#include "DepGraph.h"
#include <stdio.h>
#include <string.h>


//Function generates a markdown report of the dependency graph
void CreateReport(const DepList *graph, int num_reqs, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error: Could not open report file for writing.\n");
        return;
    }

    //Header for the report
    fprintf(f, "# <center>Software Requirements Specification </center>\n");
    fprintf(f, "<center> EECS 22L - Spring 2025 </center>\n");
    fprintf(f, "<center> Project 1 - Chess Game </center>\n\n"); //add blank line after header

    //loop through each requirement in the graph
    for (int i = 0; i < num_reqs; i++) {
        //record line
        fprintf(f, "Line %d: %s --\n", graph[i].line_number, graph[i].id);

        //prints parent dependencies
        for (int p = 0; p < graph[i].num_parents; p++) {
            // Skip if the parent string is empty or just "--"
            if (strlen(graph[i].parents[p]) == 0) continue;
            if (strcmp(graph[i].parents[p], "--") == 0) continue;
            fprintf(f, "Line %d: %s -> %s\n", graph[i].parent_lines[p], graph[i].parents[p], graph[i].id);
        }

        //prints child dependencies
        for (int c = 0; c < graph[i].num_children; c++) {
            //skip if the child string is empty after trimming
            if (strlen(graph[i].children[c]) == 0) continue;
            //skip if the child is just "--"
            if (strcmp(graph[i].children[c], "--") == 0) continue;
            fprintf(f, "Line %d: %s -> %s\n", graph[i].child_lines[c], graph[i].id, graph[i].children[c]);
        }
    }

    fclose(f);
}