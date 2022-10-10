#include "document_writer.h"
#include <iostream>

DocumentWriter::DocumentWriter() {}

void DocumentWriter::writeToDocx(std::string text) {
    std::ofstream pacient("Pacient.txt");
    if (pacient.is_open()) {
        pacient << text;
        pacient.close();
    }
}
