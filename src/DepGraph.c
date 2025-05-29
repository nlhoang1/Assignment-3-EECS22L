//DepGraph.c
//Program generates a dependency graph from a source file and prints graph
#include "DepGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Data Structure Choice: Array of Structures (DepList)
 * ----------------------------------------------------
 * We use an array of DepList structs to represent the dependency graph.
 * Each DepList stores the requirement ID and arrays of parent and child IDs.
 * This allows efficient access by index and is simple to implement for a moderate number of requirements.
 * The structure is flexible and easy to traverse for printing or further processing.
 */

// Helper function to trim leading/trailing whitespace and return pointer to trimmed string
static char* trim(char *str) {
    while (*str == ' ' || *str == '\t') str++; // skip leading
    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) *end-- = '\0';
    return str;
}

// Build the dependency graph from parsed requirements
void createDepGraph(const Requirement *reqs, int reqsLEN, DepList *graph) {
    for (int i = 0; i < reqsLEN; i++) {
        strncpy(graph[i].id, reqs[i].id, sizeof(graph[i].id));
        graph[i].id[sizeof(graph[i].id) - 1] = '\0';
        graph[i].line_number = reqs[i].line_number;
        graph[i].num_parents = 0;
        graph[i].num_children = 0;

        // Parse parents
        if (strlen(reqs[i].parents) > 0) {
            char parents_copy[256];
            strcpy(parents_copy, reqs[i].parents);
            char *parent = strtok(parents_copy, ",");
            while (parent && graph[i].num_parents < MAX_DEP) {
                char *trimmed_parent = trim(parent);
                strncpy(graph[i].parents[graph[i].num_parents], trimmed_parent, 50);
                graph[i].parents[graph[i].num_parents][49] = '\0';
                graph[i].parent_lines[graph[i].num_parents] = reqs[i].parent_line;
                graph[i].num_parents++;
                parent = strtok(NULL, ",");
            }
        }

        // Parse children
        if (strlen(reqs[i].children) > 0) {
            char children_copy[256];
            strcpy(children_copy, reqs[i].children);
            char *child = strtok(children_copy, ",");
            while (child && graph[i].num_children < MAX_DEP) {
                char *trimmed_child = trim(child);
                strncpy(graph[i].children[graph[i].num_children], trimmed_child, 50);
                graph[i].children[graph[i].num_children][49] = '\0';
                graph[i].child_lines[graph[i].num_children] = reqs[i].child_line;
                graph[i].num_children++;
                child = strtok(NULL, ",");
            }
        }
    }
}

// Print the dependency graph in the required format
void printDepGraph(const DepList *graph, int reqsLEN) {
    for (int i = 0; i < reqsLEN; i++) {
        // Print the record line with the actual line number
        printf("Line %d: %s --\n", graph[i].line_number, graph[i].id);

        // Print parent dependencies (parent -> this requirement)
        for (int p = 0; p < graph[i].num_parents; p++) {
            printf("Line %d: %s -> %s\n", graph[i].parent_lines[p], graph[i].parents[p], graph[i].id);
        }

        // Print child dependencies (this requirement -> child)
        for (int c = 0; c < graph[i].num_children; c++) {
            printf("Line %d: %s -> %s\n", graph[i].child_lines[c], graph[i].id, graph[i].children[c]);
        }
    }
}