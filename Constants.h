#include <iostream>
#pragma once

#define PROTECTED
#define PUBLIC
#define PRIVATE
#define REF
#define STATIC
#define MAX_LINE_LEN 256

namespace Graph {

    typedef struct ARC {
        int i_start;
        int j_end;
        double weight;
    } arc;

    typedef struct ITEM {
        int data;
        int key;
    } item;
}