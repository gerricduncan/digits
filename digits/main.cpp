//
//  main.cpp
//  digits
//
//  Created by Gary Duncan on 12/15/15.
//  Copyright (c) 2015 Gary Duncan. All rights reserved.
//
#include "main.h"

int main() {
    dataMatrix dm("/Users/duncan4/projects/digits/inputData/train.csv");
    for (int i = 0; i < 200; i++)
        std::cout << dm.getCell(200, i) << std::endl;
    return 0;
}



