#include <iostream>
#pragma once
#include <cfloat>
#define PROTECTED
#define PUBLIC
#define PRIVATE
#define REF
#define STATIC
#define NO_ARC -1
#define MAX_LINE_LEN 256

namespace Graph {

    typedef struct ARC {
        int i_start;
        int j_end;
        double weight;

    } arc;

    typedef struct ITEM {
        int data; //vertex
        double key; //weight
    } item;


    typedef struct DIST{
        double weight;
        bool isInfinite;
    } dist;
}