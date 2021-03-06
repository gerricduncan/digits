//
//  CSVRow.h
//  digits
//
//  Created by Gary Duncan on 5/5/16.
//  Copyright © 2016 Gary Duncan. All rights reserved.
//

#ifndef CSVRow_h
#define CSVRow_h

class CSVRow{
public:
    std::string const& operator[](std::size_t index) const{
        return m_data[index];}
    
    std::size_t size() const{
        return m_data.size();}
    
    void readNextRow(std::istream& str)
    {
        std::string         line;
        std::getline(str,line);
        
        std::stringstream   lineStream(line);
        std::string         cell;
        
        m_data.clear();
        while(std::getline(lineStream,cell,','))
        {
            m_data.push_back(cell);
        }
    }
private:
    std::vector<std::string>    m_data;
};

std::istream& operator>>(std::istream& str,CSVRow& data)
{
    data.readNextRow(str);
    return str;
}


#endif /* CSVRow_h */
