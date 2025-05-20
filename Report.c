//Report.c
#include "Report.h"
#include <stdio.h>
#include <stdlib.h>

// Stub function to generate a report
int generate_report(const RequirementNode *graph, int num_reqs, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open report file");
        return -1;
    }

    fprintf(file, "=== Requirement Dependency Report ===\n\n");

    for (int i = 0; i < num_reqs; i++) {
        fprintf(file, "Requirement: %s\n", graph[i].id);
        fprintf(file, "Depends on: ");
        if (graph[i].num_dependencies == 0) {
            fprintf(file, "None");
        } else {
            for (int j = 0; j < graph[i].num_dependencies; j++) {
                fprintf(file, "%d ", graph[i].depends_on[j]);  // Just index for now
            }
        }
        fprintf(file, "\n\n");
    }

    fclose(file);
    return 0;
}