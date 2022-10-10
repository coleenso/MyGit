#ifndef PAIN_LOCAL_DATA_H
#define PAIN_LOCAL_DATA_H

#include <string>
#include <vector>

class PainLocalData {
public:
    PainLocalData();
    ~PainLocalData();

    std::string getPartOfTheBodyLocalization();
    std::string getClarification();
    std::string getSide();
    std::string getSurface();
    std::string getIntensity();
    std::string getCharacter();
    std::string getPartOfTheBodyIrradiation();
    std::string getLocalization();
    const std::vector<std::string> &getPainLocalData();

    void setPartOfTheBodyLocalization(std::string partOfTheBodyLocalization);
    void setClarification(std::string clarification);
    void setSide(std::string side);
    void setSurface(std::string surface);
    void setIntensity(std::string intensity);
    void setCharacter(std::string character);
    void setPartOfTheBodyIrradiation(std::string partOfTheBodyIrradiation);
    void setLocalization(std::string localization);

    bool localIsFull();
    bool characterIsFull();
    bool irradIsFull();

private:
    std::vector<std::string> _painLocalData;
};

#endif // PAIN_LOCAL_DATA_H
