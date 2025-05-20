//Report.h
#ifndef REPORT_H
#define REPORT_H
#include "DepGraph.h" //use ReqNode struct
#include <stdio.h>


//Generates a text report of the requirement dependency graph
// graph = Array of ReqNode structures (from DepGraph.h)
// reqLEN = Number of requirements in the graph
// filename = Name of the output report file
void CreateReport(const ReqNode *graph, int num_reqs, const char *filename);

#endif










