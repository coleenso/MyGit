#ifndef NEURO_LOCAL_DATA_H
#define NEURO_LOCAL_DATA_H

#include <string>
#include <vector>

class NeuroLocalData {
public:
    NeuroLocalData();
    ~NeuroLocalData();

    std::string getPartOfTheBody();
    std::string getClarification();
    std::string getSide();
    std::string getSurface();
    std::string getDisorder();
    std::string getView();
    const std::vector<std::string> &getNeuroLocalData();

    void setPartOfTheBody(std::string partOfTheBody);
    void setClarification(std::string clarification);
    void setSide(std::string side);
    void setSurface(std::string surface);
    void setDisorder(std::string disorder);
    void setView(std::string view);

    bool isFull();

private:
    std::vector<std::string> _neuroLocalData;
};

#endif // NEURO_LOCAL_DATA_H
