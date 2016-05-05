//
//  dataMatrix.h
//  digits
//
//  Created by Gary Duncan on 5/5/16.
//  Copyright © 2016 Gary Duncan. All rights reserved.
//

#ifndef dataMatrix_h
#define dataMatrix_h

#include <vector>
#include <fstream>
#include "CSVRow.h"

class dataMatrix{
public:
//Construct from file
    dataMatrix(std::string);
//Set a data element
    int getCell(int i, int j){
        return cells[i][j];}
    
    std::string getLable(int i){
        return labels[i];}
    
private:
    std::vector<std::string> labels;
    std::vector<std::vector<int>>cells;
};

//Construct from file
dataMatrix::dataMatrix(std::string fileName){
    std::ifstream file(fileName);
    std::string line;
    std::string strCell;
    bool firstRow = true;
    
    // Get data cells
    std::vector<int> vecRow;
    while(std::getline(file,line)){
        std::stringstream lineStream(line);
        vecRow.clear();
        while(std::getline(lineStream,strCell,',')){
            if(firstRow)
                labels.push_back(strCell);
            else
                vecRow.push_back(stoi(strCell));
           // std::cout << strCell << std::endl;
        }
        if(firstRow)
            firstRow = false;
        else
            cells.push_back(vecRow);
    }
}


#endif /* dataMatrix_h */
