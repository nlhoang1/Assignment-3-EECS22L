//DepGraph.c
//Program generates a dependency graph from a source file and prints graph
#include "DepGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//(STUB) function to build a dependency graph
void createDepGraph(const Requirement *reqs, int reqsLEN, DepList *graph);
//(LATER) code to build a dependency graph
    

// Helper function to trim leading/trailing whitespace
static void trim(char *str) {
    char *end;
    while (*str == ' ' || *str == '\t') str++;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) *end-- = '\0';
}

// Print the dependency graph in the required format
void printDepGraph(const Requirement *reqs, int reqsLEN) {
    for (int i = 0; i < reqsLEN; i++) {
        // Print the record line
        printf("%04d: %s --\n", reqs[i].line_number, reqs[i].id);

        // Print parent dependencies (parent -> this requirement)
        if (strlen(reqs[i].parents) > 0) {
            char parents_copy[256];
            strcpy(parents_copy, reqs[i].parents);
            char *parent = strtok(parents_copy, ",");
            while (parent) {
                trim(parent);
                printf("%04d: %s -> %s\n", reqs[i].parent_line, parent, reqs[i].id);
                parent = strtok(NULL, ",");
            }
        }

        // Print child dependencies (this requirement -> child)
        if (strlen(reqs[i].children) > 0) {
            char children_copy[256];
            strcpy(children_copy, reqs[i].children);
            char *child = strtok(children_copy, ",");
            while (child) {
                trim(child);
                printf("%04d: %s -> %s\n", reqs[i].child_line, reqs[i].id, child);
                child = strtok(NULL, ",");
            }
        }
    }
}

void createDepGraph(const Requirement *reqs, int reqsLEN, DepList *graph) {
    for (int i = 0; i < reqsLEN; i++) {
        // Copy the requirement ID
        strncpy(graph[i].id, reqs[i].id, sizeof(graph[i].id));
        graph[i].num_parents = 0;
        graph[i].num_children = 0;

        // Parse parents
        if (strlen(reqs[i].parents) > 0) {
            char parents_copy[256];
            strcpy(parents_copy, reqs[i].parents);
            char *parent = strtok(parents_copy, ",");
            while (parent && graph[i].num_parents < MAX_DEP) {
                // Remove whitespace
                while (*parent == ' ' || *parent == '\t') parent++;
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
                // Remove whitespace
                while (*child == ' ' || *child == '\t') child++;
                strncpy(graph[i].children[graph[i].num_children], child, 50);
                graph[i].children[graph[i].num_children][49] = '\0';
                graph[i].num_children++;
                child = strtok(NULL, ",");
            }
        }
    }
}