#ifndef DOCUMENTWRITER_H
#define DOCUMENTWRITER_H

#include <fstream>

class DocumentWriter
{
public:
    DocumentWriter();

    void writeToDocx(std::string);
};

#endif // DOCUMENTWRITER_H
