//DepGraph.c
// Program generates a dependency graph from a source file
#include "DepGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stub function to build a dependency graph
void build_dependency_graph(const Requirement *reqs, int num_reqs, RequirementNode *graph) {
    // TODO: Actually analyze requirement descriptions for dependencies
    for (int i = 0; i < num_reqs; i++) {
        strcpy(graph[i].id, reqs[i].id);
        graph[i].num_dependencies = 0;

        // Stub: No real dependencies yet
    }
}

// Stub function to print the dependency graph
void print_dependency_graph(const RequirementNode *graph, int num_reqs) {
    printf("Dependency Graph:\n");
    for (int i = 0; i < num_reqs; i++) {
        printf("%s depends on: ", graph[i].id);
        for (int j = 0; j < graph[i].num_dependencies; j++) {
            printf("%d ", graph[i].depends_on[j]);  // Just index for now
        }
        printf("\n");
    }
}
