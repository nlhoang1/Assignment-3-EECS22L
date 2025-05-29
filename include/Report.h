//Report.h
#ifndef REPORT_H
#define REPORT_H
#include "DepGraph.h" // use DepList struct
#include <stdio.h>


//Generates a text report of the requirement dependency graph.
//graph = Array of DepList structures (from DepGraph.h)
//num_reqs = Number of requirements in the graph
//filename = Name of the output report file
void CreateReport(const DepList *graph, int num_reqs, const char *filename);

#endif










