#pragma once
#include <iostream>
#include <string>

class Edge {

    public:

    int src, dest, weight;

    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }

    Edge(int src, int dest){
        this->src = src;
        this->dest = dest;
        this->weight = 1;
    }

    std::string toString() {

        return "<" + std::to_string(src) + ", " 
        + std::to_string(dest) + ", " 
        + std::to_string(weight) + "> ";

    }

};
