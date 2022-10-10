#ifndef DEFORMATION_LOCAL_DATA_H
#define DEFORMATION_LOCAL_DATA_H

#include <string>
#include <vector>

class DeformationLocalData {
public:
    DeformationLocalData();
    ~DeformationLocalData();

    std::string getDeformationLocalInfo();
    std::string getView();
    std::string getSide();
    std::string getDegree();
    const std::vector<std::string> &getDeformationLocalData();

    void setDeformationLocalInfo(std::string deformationLocalInfo);
    void setView(std::string view);
    void setSide(std::string side);
    void setDegree(std::string degree);

    bool isFull();

private:
    std::vector<std::string> _deformationLocalData;
};

#endif // DEFORMATION_LOCAL_DATA_H
