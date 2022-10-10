#ifndef PATIENTDATA_H
#define PATIENTDATA_H

#include <string>
#include <vector>

class PatientData {
public:
    PatientData();
    ~PatientData();

    std::string getSurname();
    std::string getName();
    std::string getPatronymic();
    std::string getBirthday();
    std::string getSex();
    std::string getAge();
    std::string getComplaint();
    std::string getAddition();
    const std::vector<std::string> &getData();

    void setSurname(std::string surname);
    void setName(std::string name);
    void setPatronymic(std::string patronymic);
    void setBirthday(std::string birthday);
    void setSex(std::string sex);
    void setAge(std::string age);
    void setComplaint(std::string complaint);
    void setAddition(std::string additions);

    bool isFull();
    std::string makeText();

private:
    std::vector<std::string> _data;
};

#endif // PATIENTDATA_H
