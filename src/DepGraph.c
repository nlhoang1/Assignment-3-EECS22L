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

// Helper function to trim leading/trailing whitespace
static void trim(char *str) {
    char *end;
    while (*str == ' ' || *str == '\t') str++;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) *end-- = '\0';
}

// Build the dependency graph from parsed requirements
void createDepGraph(const Requirement *reqs, int reqsLEN, DepList *graph) {
    for (int i = 0; i < reqsLEN; i++) {
        // Copy the requirement ID
        strncpy(graph[i].id, reqs[i].id, sizeof(graph[i].id));
        graph[i].id[sizeof(graph[i].id) - 1] = '\0';
        graph[i].num_parents = 0;
        graph[i].num_children = 0;

        // Parse parents
        if (strlen(reqs[i].parents) > 0) {
            char parents_copy[256];
            strcpy(parents_copy, reqs[i].parents);
            char *parent = strtok(parents_copy, ",");
            while (parent && graph[i].num_parents < MAX_DEP) {
                trim(parent);
                strncpy(graph[i].parents[graph[i].num_parents], parent, 50);
                graph[i].parents[graph[i].num_parents][49] = '\0';
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
                trim(child);
                strncpy(graph[i].children[graph[i].num_children], child, 50);
                graph[i].children[graph[i].num_children][49] = '\0';
                graph[i].num_children++;
                child = strtok(NULL, ",");
            }
        }
    }
}

// Print the dependency graph in the required format
void printDepGraph(const DepList *graph, int reqsLEN) {
    for (int i = 0; i < reqsLEN; i++) {
        // Print the record line
        printf("%04d: %s --\n", i + 1, graph[i].id);

        // Print parent dependencies (parent -> this requirement)
        for (int p = 0; p < graph[i].num_parents; p++) {
            printf("%04d: %s -> %s\n", i + 1, graph[i].parents[p], graph[i].id);
        }

        // Print child dependencies (this requirement -> child)
        for (int c = 0; c < graph[i].num_children; c++) {
            printf("%04d: %s -> %s\n", i + 1, graph[i].id, graph[i].children[c]);
        }
    }
}