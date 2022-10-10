#include "patient_disease_data.h"

PatientDiseaseData::PatientDiseaseData()
    : _diseaseData(13, "")
    , _diseaseManifestation(1, "") {
    setlocale(LC_ALL, "Russian");
}

PatientDiseaseData::~PatientDiseaseData() {}

std::string PatientDiseaseData::getDiseaseStartTime() {
    return _diseaseData[0];
}

std::string PatientDiseaseData::getOccurrenceOfDisease() {
    return _diseaseData[1];
}

std::string PatientDiseaseData::getManifestationOfDisease() {
    return _diseaseData[2];
}

std::string PatientDiseaseData::getRevealed() {
    return _diseaseData[3];
}

std::string PatientDiseaseData::getFirstWentToMedicalFacility() {
    return _diseaseData[4];
}

std::string PatientDiseaseData::getMedicalFacility() {
    return _diseaseData[5];
}

std::string PatientDiseaseData::getTreatmentTimeInDays() {
    return _diseaseData[6];
}

std::string PatientDiseaseData::getTypeOfTreatment() {
    return _diseaseData[7];
}

std::string PatientDiseaseData::getTypeOfTreatmentAddition() {
    return _diseaseData[8];
}

std::string PatientDiseaseData::getTreatmentResult() {
    return _diseaseData[9];
}

std::string PatientDiseaseData::getNewDisease() {
    return _diseaseData[10];
}

std::string PatientDiseaseData::getWentToOtherMedicalFacility() {
    return _diseaseData[11];
}

std::string PatientDiseaseData::getAddition() {
    return _diseaseData[12];
}

const std::vector<std::string> &PatientDiseaseData::getDiseaseData() {
    return _diseaseData;
}

const std::vector<std::string> &PatientDiseaseData::getDiseaseManifestation() {
    return _diseaseManifestation;
}

void PatientDiseaseData::setDiseaseStartTime(std::string time) {
    _diseaseData[0] = time;
}

void PatientDiseaseData::setOccurrenceOfDisease(std::string occurrence){
    _diseaseData[1] = occurrence;
}

void PatientDiseaseData::setManifestationOfDisease(std::string manifestation) {
    _diseaseData[2] = manifestation;
}

void PatientDiseaseData::setRevealed(std::string revealed) {
    _diseaseData[3] = revealed;
}

void PatientDiseaseData::setFirstWentToMedicalFacility(std::string time) {
    _diseaseData[4] = time;
}

void PatientDiseaseData::setMedicalFacility(std::string medicalFacility) {
    _diseaseData[5] = medicalFacility;
}

void PatientDiseaseData::setTreatmentTimeInDays(std::string time) {
    _diseaseData[6] = time;
}

void PatientDiseaseData::setTypeOfTreatment(std::string type) {
    _diseaseData[7] = type;
}

void PatientDiseaseData::setTypeOfTreatmentAddition(std::string typeAddition) {
    _diseaseData[8] = typeAddition;
}

void PatientDiseaseData::setTreatmentResult(std::string result) {
    _diseaseData[9] = result;
}

void PatientDiseaseData::setNewDisease(std::string newDisease) {
    _diseaseData[10] = newDisease;
}

void PatientDiseaseData::setWentToOtherMedicalFacility(std::string wentToOtherMedicalFacility) {
    _diseaseData[11] = wentToOtherMedicalFacility;
}

void PatientDiseaseData::setAddition(std::string addition) {
    _diseaseData[12] = addition;
}

void PatientDiseaseData::setDiseaseManifestation(std::vector<std::string> diseaseManifestation) {
    _diseaseManifestation = diseaseManifestation;
}

bool PatientDiseaseData::diseaseDataIsFull() {
    bool result = true;
    for (int i = 0; i < _diseaseData.size() - 1 && result; i++) {
        if (_diseaseData[i] == "") {
            result = false;
        }
    }
    return result;
}

bool PatientDiseaseData::diseaseManifestationIsFull() {
    bool result = true;
    for (int i = 0; i < _diseaseManifestation.size() - 1 && result; i++) {
        if (_diseaseManifestation[i] == "") {
            result = false;
        }
    }
    return result;
}

std::string PatientDiseaseData::makeText(std::string sex) {
    std::string result{""};
    result += "Анамнез по заболеванию позвоночника:\n\n";

    std::string day = _diseaseData[0].substr(_diseaseData[0].size() - 15, 2);
    std::string month = _diseaseData[0].substr(_diseaseData[0].size() - 19, 3);
    std::string year = _diseaseData[0].substr(_diseaseData[0].size() - 4, 4);

    if (month == "Dec") {
        month = "Декабря";
    } else if ("Jan") {
        month = "Января";
    } else if ("Feb") {
        month = "Февраля";
    } else if ("Mar") {
        month = "Марта";
    } else if ("Apr") {
        month = "Апреля";
    } else if ("May") {
        month = "Мая";
    } else if ("Jun") {
        month = "Июня";
    } else if ("Jul") {
        month = "Июля";
    } else if ("Aug") {
        month = "Августа";
    } else if ("Sep") {
        month = "Сентября";
    } else if ("Oct") {
        month = "Октября";
    } else if ("Nov") {
        month = "Ноября";
    }

    if (sex == "man") {
        result += "Пациент считает себя больным с " + day + "-го " + month + " " + year + "-го года, ";
    } else {
        result += "Пациентка считает себя больной с " + day + "-го " + month + " " + year + "-го года, ";
    }

    std::string str = _diseaseData[1];
    if (str == "Не знает") {
        result += "чем вызвана болезнь не знает, ";
    } else if (str == "Травма") {
        result += "возникновение болезни связывает с травмой, ";
    } else if (str == "Физическая нагрузка") {
        result += "возникновение болезни связывает с физической нагрузкой, ";
    } else if (str == "Переохлаждение") {
        result += "возникновение болезни связывает с переохлаждением, ";
    } else if (str == "Беременность") {
        result += "возникновение болезни связывает с беременностью, ";
    } else if (str == "Роды") {
        result += "возникновение болезни связывает с родами, ";
    } else if (str == "Прочее") {
        result += "возникновение болезни связывает с прочими причинами, ";
    }

    result += "\n";

    str = _diseaseData[2];
    if (str == "Не проявляет") {
        result += "болезнь себя не проявляла.\n";
    } else if (str == "Боли") {
        result += "болезнь проявила себя болью, локализация прилагается (см. ниже):\n\nЛокализация боли:\n";
    } else if (str == "Деформация туловища") {
        result += "болезнь проявила себя деформацией туловища, локализация прилагается (см. ниже):\n\nЛокализация деформации:\n";
    } else if (str == "Неврологические нарушения") {
        result += "болезнь проявила себя неврологическими нарушениями, локализация прилагается (см. ниже):\n\nЛокализация неврологических нарушений:\n";
    }

    if (_diseaseManifestation.size() == 8) {
        if (_diseaseManifestation[0] == "Нет" && _diseaseManifestation[2] == "Нет") {
            result += "  Локализация не установлена.\n";
        } else if (_diseaseManifestation[0] != "Нет") {
            result += "  Локализация установлена ";
            if (_diseaseManifestation[1] == "Копчиковый отдел") {
                result += "в копчиковом отделе";
            } else if (_diseaseManifestation[1] == "Кресцовый отдел") {
                result += "в крестцовом отделе";
            } else if (_diseaseManifestation[1] == "Поясничный отдел") {
                result += "в поясничном отделе";
            } else if (_diseaseManifestation[1] == "Грудной отдел") {
                result += "в грудном отделе";
            } else if (_diseaseManifestation[1] == "Шейный отдел") {
                result += "в шейном отделе";
            } else if (_diseaseManifestation[1] == "Грудина") {
                result += "в грудине";
            } else if (_diseaseManifestation[1] == "За грудиной") {
                result += "за грудиной";
            } else if (_diseaseManifestation[1] == "Под лопаткой") {
                result += "под лопаткой";
            } else if (_diseaseManifestation[1] == "Межреберье") {
                result += "в межреберье";
            } else if (_diseaseManifestation[1] == "Брюшная область") {
                result += "в брюшной области";
            } else if (_diseaseManifestation[1] == "Плечо") {
                result += "в плече";
            } else if (_diseaseManifestation[1] == "Локоть") {
                result += "в локте";
            } else if (_diseaseManifestation[1] == "Запястье") {
                result += "в запястье";
            } else if (_diseaseManifestation[1] == "Кончики пальцев" && _diseaseManifestation[6] == "Рука") {
                result += "в кончиках пальцев руки";
            } else if (_diseaseManifestation[1] == "Пальцы" && _diseaseManifestation[6] == "Рука") {
                result += "в пальцах руки";
            } else if (_diseaseManifestation[1] == "Предплечье") {
                result += "в предплечье";
            } else if (_diseaseManifestation[1] == "Ключица") {
                result += "в ключице";
            } else if (_diseaseManifestation[1] == "Бедро (Внутреняя сторона)") {
                result += "на внутренней стороне бедра";
            } else if (_diseaseManifestation[1] == "Бедро (Внешняя сторона)") {
                result += "на внешней стороне бедра";
            } else if (_diseaseManifestation[1] == "Колено") {
                result += "в колено";
            } else if (_diseaseManifestation[1] == "Подколенная область") {
                result += "в подколенной области";
            } else if (_diseaseManifestation[1] == "Голиностоп") {
                result += "в голиностопе";
            } else if (_diseaseManifestation[1] == "Пятка") {
                result += "в пятке";
            } else if (_diseaseManifestation[1] == "Стопа") {
                result += "в стопе";
            } else if (_diseaseManifestation[1] == "Пальцы" && _diseaseManifestation[6] == "Нога") {
                result += "в пальцах ноги";
            } else if (_diseaseManifestation[1] == "Паховая область") {
                result += "в паховой области";
            } else if (_diseaseManifestation[1] == "Лобная часть") {
                result += "в лобной части";
            } else if (_diseaseManifestation[1] == "Теменная часть") {
                result += "в теменной части";
            } else if (_diseaseManifestation[1] == "Затылочная часть") {
                result += "в затылочной части";
            } else if (_diseaseManifestation[1] == "Височная часть") {
                result += "в височной части";
            } else if (_diseaseManifestation[1] == "Лицевая часть") {
                result += "в лицевой части";
            }
            if (_diseaseManifestation[2] == "Нет") {
                result += "";
            } else if (_diseaseManifestation[2] == "Левая") {
                result += " с левой стороны";
            } else if (_diseaseManifestation[2] == "Правая") {
                result += " с правой стороны";
            } else if (_diseaseManifestation[2] == "И левая и правая") {
                result += " и с левой и с правой сторон";
            }
            if (_diseaseManifestation[3] == "0") {
                result += ".\n";
            } else if (_diseaseManifestation[3] == "Внутренняя") {
                result += ", на внутренней поверхности.\n";
            } else if (_diseaseManifestation[3] == "Внешняя") {
                result += ", на внешней поверхности.\n";
            } else if (_diseaseManifestation[3] == "Передняя") {
                result += ", на передней поверхности.\n";
            } else if (_diseaseManifestation[3] == "Задняя") {
                result += ", на задней поверхности.\n";
            }
        }

        if (_diseaseManifestation[4] == "Слабая") {
            result += "  Слабая интенсивность боли, ";
        } else if (_diseaseManifestation[4] == "Средняя") {
            result += "  Средняя интенсивность боли, ";
        } else if (_diseaseManifestation[4] == "Сильная") {
            result += "  Сильная интенсивность боли, ";
        } else if (_diseaseManifestation[4] == "Невыносимая") {
            result += "  Невыносимая интенсивность боли, ";
        }

        if (_diseaseManifestation[5] == "Приступообразная") {
            result += "приступообразного характера.\n";
        } else if (_diseaseManifestation[5] == "Пароксимальная") {
            result += "пароксимального характера.\n";
        } else if (_diseaseManifestation[5] == "Пульсирующая") {
            result += "пульсирующего характера.\n";
        } else if (_diseaseManifestation[5] == "Тупая") {
            result += "тупого характера.\n";
        } else if (_diseaseManifestation[5] == "Колючая") {
            result += "колючего характера.\n";
        } else if (_diseaseManifestation[5] == "Режущая") {
            result += "режущего характера.\n";
        } else if (_diseaseManifestation[5] == "Стреляющая") {
            result += "стреляющего характера.\n";
        } else if (_diseaseManifestation[5] == "Давящая") {
            result += "давящего характера.\n";
        } else if (_diseaseManifestation[5] == "Сжимающая") {
            result += "сжимающего характера.\n";
        } else if (_diseaseManifestation[5] == "Рвущая") {
            result += "рвущего характера.\n";
        } else if (_diseaseManifestation[5] == "Дергающая") {
            result += "дёргающего характера.\n";
        } else if (_diseaseManifestation[5] == "Сверлящая") {
            result += "сверлящего характера.\n";
        } else if (_diseaseManifestation[5] == "Жгучая") {
            result += "жгучего характера.\n";
        } else if (_diseaseManifestation[5] == "Фантомная") {
            result += "фантомного характера.\n";
        } else if (_diseaseManifestation[5] == "Реактивная") {
            result += "реактивного характера.\n";
        } else if (_diseaseManifestation[5] == "Острая") {
            result += "острого характера.\n";
        }

        if (_diseaseManifestation[6] == "Нет") {
            result += "  Иррадиация не установлена.\n";
            result += "\n";
        } else {
            result += "  Иррадиация установлена ";
            if (_diseaseManifestation[7] == "Копчиковый отдел") {
                result += "в копчиковом отделе.\n\n";
            } else if (_diseaseManifestation[7] == "Кресцовый отдел") {
                result += "в крестцовом отделе.\n\n";
            } else if (_diseaseManifestation[7] == "Поясничный отдел") {
                result += "в поясничном отделе.\n\n";
            } else if (_diseaseManifestation[7] == "Грудной отдел") {
                result += "в грудном отделе.\n\n";
            } else if (_diseaseManifestation[7] == "Шейный отдел") {
                result += "в шейном отделе.\n\n";
            } else if (_diseaseManifestation[7] == "Грудина") {
                result += "в грудине.\n\n";
            } else if (_diseaseManifestation[7] == "За грудиной") {
                result += "за грудиной.\n\n";
            } else if (_diseaseManifestation[7] == "Под лопаткой") {
                result += "под лопаткой.\n\n";
            } else if (_diseaseManifestation[7] == "Межреберье") {
                result += "в межреберье.\n\n";
            } else if (_diseaseManifestation[7] == "Брюшная область") {
                result += "в брюшной области.\n\n";
            } else if (_diseaseManifestation[7] == "Плечо") {
                result += "в плече.\n\n";
            } else if (_diseaseManifestation[7] == "Локоть") {
                result += "в локте.\n\n";
            } else if (_diseaseManifestation[7] == "Запястье") {
                result += "в запястье.\n\n";
            } else if (_diseaseManifestation[7] == "Кончики пальцев" && _diseaseManifestation[6] == "Рука") {
                result += "в кончиках пальцев руки.\n\n";
            } else if (_diseaseManifestation[7] == "Пальцы" && _diseaseManifestation[6] == "Рука") {
                result += "в пальцах руки.\n\n";
            } else if (_diseaseManifestation[7] == "Предплечье") {
                result += "в предплечье.\n\n";
            } else if (_diseaseManifestation[7] == "Ключица") {
                result += "в ключице.\n\n";
            } else if (_diseaseManifestation[7] == "Бедро (Внутреняя сторона)") {
                result += "на внутренней стороне бедра.\n\n";
            } else if (_diseaseManifestation[7] == "Бедро (Внешняя сторона)") {
                result += "на внешней стороне бедра.\n\n";
            } else if (_diseaseManifestation[7] == "Колено") {
                result += "в колено.\n\n";
            } else if (_diseaseManifestation[7] == "Подколенная область") {
                result += "в подколенной области.\n\n";
            } else if (_diseaseManifestation[7] == "Голиностоп") {
                result += "в голиностопе.\n\n";
            } else if (_diseaseManifestation[7] == "Пятка") {
                result += "в пятке.\n\n";
            } else if (_diseaseManifestation[7] == "Стопа") {
                result += "в стопе.\n\n";
            } else if (_diseaseManifestation[7] == "Пальцы" && _diseaseManifestation[6] == "Нога") {
                result += "в пальцах ноги.\n\n";
            } else if (_diseaseManifestation[7] == "Паховая область") {
                result += "в паховой области.\n\n";
            } else if (_diseaseManifestation[7] == "Лобная часть") {
                result += "в лобной части.\n\n";
            } else if (_diseaseManifestation[7] == "Теменная часть") {
                result += "в теменной части.\n\n";
            } else if (_diseaseManifestation[7] == "Затылочная часть") {
                result += "в затылочной части.\n\n";
            } else if (_diseaseManifestation[7] == "Височная часть") {
                result += "в височной части.\n\n";
            } else if (_diseaseManifestation[7] == "Лицевая часть") {
                result += "в лицевой части.\n\n";
            }
        }
    } else if (_diseaseManifestation.size() == 4) {
        result += _diseaseManifestation[0] + " деформации, ";
        if (_diseaseManifestation[1] == "Не определено") {
            result += "не определённого вида,\n";
        } else if (_diseaseManifestation[1] == "Сколиоз") {
            result += "сколиоз,\n";
        } else if (_diseaseManifestation[1] == "Кифоз") {
            result += "кифоз,\n";
        } else if (_diseaseManifestation[1] == "Лордоз") {
            result += "лордоз,\n";
        } else if (_diseaseManifestation[1] == "Ротация") {
            result += "ротация,\n";
        }
        if (_diseaseManifestation[2] == "Нет") {
            result += "";
        } else if (_diseaseManifestation[2] == "Левая") {
            result += " с левой стороны, ";
        } else if (_diseaseManifestation[2] == "Правая") {
            result += " с правой стороны, ";
        } else if (_diseaseManifestation[2] == "И левая и правая") {
            result += " и с левой и с правой сторон, ";
        }
        if (_diseaseManifestation[3] == "Не выявлено") {
            result += "деформация ранее не выявлена.\n\n";
        } else if (_diseaseManifestation[3] == "Гиперлордоз") {
            result += "ранее выявлен гиперлордоз.\n\n" + _diseaseManifestation[3];
        } else if (_diseaseManifestation[3] == "Гиполордоз") {
            result += "ранее выявлен гиполордоз.\n\n" + _diseaseManifestation[3];
        } else {
            result += "ранее выявлена деформация " + _diseaseManifestation[3] + ".\n\n";
        }
    } else if (_diseaseManifestation.size() == 6) {
        if (_diseaseManifestation[0] == "Нет" && _diseaseManifestation[2] == "Нет") {
            result += "  Локализация не установлена.\n";
        } else if (_diseaseManifestation[0] != "Нет") {
            result += "  Локализация установлена ";
            if (_diseaseManifestation[1] == "Копчиковый отдел") {
                result += "в копчиковом отделе";
            } else if (_diseaseManifestation[1] == "Кресцовый отдел") {
                result += "в крестцовом отделе";
            } else if (_diseaseManifestation[1] == "Поясничный отдел") {
                result += "в поясничном отделе";
            } else if (_diseaseManifestation[1] == "Грудной отдел") {
                result += "в грудном отделе";
            } else if (_diseaseManifestation[1] == "Шейный отдел") {
                result += "в шейном отделе";
            } else if (_diseaseManifestation[1] == "Грудина") {
                result += "в грудине";
            } else if (_diseaseManifestation[1] == "За грудиной") {
                result += "за грудиной";
            } else if (_diseaseManifestation[1] == "Под лопаткой") {
                result += "под лопаткой";
            } else if (_diseaseManifestation[1] == "Межреберье") {
                result += "в межреберье";
            } else if (_diseaseManifestation[1] == "Брюшная область") {
                result += "в брюшной области";
            } else if (_diseaseManifestation[1] == "Плечо") {
                result += "в плече";
            } else if (_diseaseManifestation[1] == "Локоть") {
                result += "в локте";
            } else if (_diseaseManifestation[1] == "Запястье") {
                result += "в запястье";
            } else if (_diseaseManifestation[1] == "Кончики пальцев" && _diseaseManifestation[6] == "Рука") {
                result += "в кончиках пальцев руки";
            } else if (_diseaseManifestation[1] == "Пальцы" && _diseaseManifestation[6] == "Рука") {
                result += "в пальцах руки";
            } else if (_diseaseManifestation[1] == "Предплечье") {
                result += "в предплечье";
            } else if (_diseaseManifestation[1] == "Ключица") {
                result += "в ключице";
            } else if (_diseaseManifestation[1] == "Бедро (Внутреняя сторона)") {
                result += "на внутренней стороне бедра";
            } else if (_diseaseManifestation[1] == "Бедро (Внешняя сторона)") {
                result += "на внешней стороне бедра";
            } else if (_diseaseManifestation[1] == "Колено") {
                result += "в колено";
            } else if (_diseaseManifestation[1] == "Подколенная область") {
                result += "в подколенной области";
            } else if (_diseaseManifestation[1] == "Голиностоп") {
                result += "в голиностопе";
            } else if (_diseaseManifestation[1] == "Пятка") {
                result += "в пятке";
            } else if (_diseaseManifestation[1] == "Стопа") {
                result += "в стопе";
            } else if (_diseaseManifestation[1] == "Пальцы" && _diseaseManifestation[6] == "Нога") {
                result += "в пальцах ноги";
            } else if (_diseaseManifestation[1] == "Паховая область") {
                result += "в паховой области";
            } else if (_diseaseManifestation[1] == "Лобная часть") {
                result += "в лобной части";
            } else if (_diseaseManifestation[1] == "Теменная часть") {
                result += "в теменной части";
            } else if (_diseaseManifestation[1] == "Затылочная часть") {
                result += "в затылочной части";
            } else if (_diseaseManifestation[1] == "Височная часть") {
                result += "в височной части";
            } else if (_diseaseManifestation[1] == "Лицевая часть") {
                result += "в лицевой части";
            }
            if (_diseaseManifestation[2] == "Нет") {
                result += "";
            } else if (_diseaseManifestation[2] == "Левая") {
                result += " с левой стороны";
            } else if (_diseaseManifestation[2] == "Правая") {
                result += " с правой стороны";
            } else if (_diseaseManifestation[2] == "И левая и правая") {
                result += " и с левой и с правой сторон";
            }
            if (_diseaseManifestation[3] == "0") {
                result += ".\n";
            } else if (_diseaseManifestation[3] == "Внутренняя") {
                result += ", на внутренней поверхности.\n";
            } else if (_diseaseManifestation[3] == "Внешняя") {
                result += ", на внешней поверхности.\n";
            } else if (_diseaseManifestation[3] == "Передняя") {
                result += ", на передней поверхности.\n";
            } else if (_diseaseManifestation[3] == "Задняя") {
                result += ", на задней поверхности.\n";
            }
        }
        if (_diseaseManifestation[4] == "Нет") {
            result += "  Нарушений нет.\n\n";
        } else if (_diseaseManifestation[4] == "Двигательные функции") {
            result += "  Нарушение двигательных функций";
        } else if (_diseaseManifestation[4] == "Чувствительность") {
            result += "  Нарушение чувствительности";
        }
        if (_diseaseManifestation[5] == "0") {
            result += "";
        } else if (_diseaseManifestation[5] == "Парез"){
            result += ", парез.\n\n";
        } else if (_diseaseManifestation[5] == "Паралич"){
            result += ", паралич.\n\n";
        } else if (_diseaseManifestation[5] == "Парастезия"){
            result += ", парастезия.\n\n";
        } else if (_diseaseManifestation[5] == "Гиперстезия"){
            result += ", гипрестезия.\n\n";
        } else if (_diseaseManifestation[5] == "Гипостезия"){
            result += ", гипостезия.\n\n";
        } else if (_diseaseManifestation[5] == "Дистезия"){
            result += ", дистезия.\n\n";
        }
    }

    str = _diseaseData[3];
    if (str == "Самостоятельно") {
        result += "Деформация выявлена самостоятельно.\n ";
    } else if (str == "Родственник") {
        result += "Деформация выявлена родственником.\n ";
    } else if (str == "Окружающие") {
        result += "Деформация выявлена окружающими.\n ";
    } else if (str == "Доктор") {
        result += "Деформация выявлена доктором.\n ";
    } else if (str == "Портниха") {
        result += "Деформация выявлена портнихой.\n ";
    } else if (str == "Прочее") {
        result += "Деформация выявлена при уточняемых обстоятельствах.\n ";
    }

    if (sex == "man") {
        str = _diseaseData[5];
        if (str == "Поликлиника") {
            result += "Впервые в поликлинику обратился ";
        } else if (str == "Консультативный приём") {
            result += "Впервые на консультативный приём обратился ";
        } else if (str == "Стационар") {
            result += "Впервые в стационар обратился ";
        } else if (str == "Прочее") {
            result += "Впервые в медицинское учереждение обратился ";
        }
    } else {
        str = _diseaseData[5];
        if (str == "Поликлиника") {
            result += "Впервые в поликлинику обратилась ";
        } else if (str == "Консультативный приём") {
            result += "Впервые на консультативный приём обратилась ";
        } else if (str == "Стационар") {
            result += "Впервые в стационар обратился ";
        } else if (str == "Прочее") {
            result += "Впервые в медицинское учереждение обратилась ";
        }
    }

    day = _diseaseData[4].substr(_diseaseData[4].size() - 15, 2);
    month = _diseaseData[4].substr(_diseaseData[4].size() - 19, 3);
    year = _diseaseData[4].substr(_diseaseData[4].size() - 4, 4);

    if (month == "Dec") {
        month = "Декабря";
    } else if ("Jan") {
        month = "Января";
    } else if ("Feb") {
        month = "Февраля";
    } else if ("Mar") {
        month = "Марта";
    } else if ("Apr") {
        month = "Апреля";
    } else if ("May") {
        month = "Мая";
    } else if ("Jun") {
        month = "Июня";
    } else if ("Jul") {
        month = "Июля";
    } else if ("Aug") {
        month = "Августа";
    } else if ("Sep") {
        month = "Сентября";
    } else if ("Oct") {
        month = "Октября";
    } else if ("Nov") {
        month = "Ноября";
    }

    result += day + "-го " + month + " " + year + "-го года, ";

    str = _diseaseData[6];
    if (str == "1") {
        result += "лечение продлилось " + str + " день.\n";
    } else if ((str[str.size() - 1] == '2' || str[str.size() - 1] == '3' || str[str.size() - 1] == '4') && (str != "11" && str != "12" && str != "13" && str != "14")) {
        result += "лечение продлилось " + str + " дня.\n";
    } else {
        result += "лечение продлилось " + str + " дней.\n";
    }

    std::string add = _diseaseData[8];
    str = _diseaseData[7];
    if (str == "Нет") {
        result += "Вид лечения: Нет.\n";
    } else if (str == "Консервативное") {
        result += "Вид лечения: Консервативное, " + add + ".\n";
    } else if (str == "Оперативное") {
        result += "Вид лечения: Оперативное, " + add + ".\n";
    } else if (str == "Санаторно - курортное") {
        result += "Вид лечения: Санаторно-курортное, " + add + ".\n";
    }

    str = _diseaseData[9];
    if (str == "Отлично") {
        result += "Результаты лечения оценивает как \"отличные\", ";
    } else if (str == "Хорошо") {
        result += "Результаты лечения оценивает как \"хорошие\", ";
    } else if (str == "Удовлетворительно") {
        result += "Результаты лечения оценивает как \"удовлетворительные\", ";
    } else if (str == "Плохо") {
        result += "Результаты лечения оценивает как \"плохие\", ";
    } else if (str == "Ухудшение") {
        result += "Результаты лечения оценивает как \"ухудшающие\", ";
    }

    str = _diseaseData[10];
    if (str == "Да") {
        result += "присоединились новые проявления болезни, ";
    } else if (str == "Нет") {
        result += "новые проявления болезни не присоединились, ";
    }

    str = _diseaseData[11];
    if (str == "Да") {
        result += "было повторное обращение в мед. учереждение.\n";
    } else if (str == "Нет") {
        result += "повторного обращения в мед. учереждение не было.\n";
    }

    std::string addition_str = _diseaseData[12];
    if (addition_str == "") {
        addition_str = "-";
    }
    result += "Дополнительные сведения: " + addition_str + "\n";

    result += "\n---------------------------------------------------------------------\n";
    result += "Предположительные диагнозы:\n";
    if (_diseaseManifestation[1] == "Поясничный отдел" && _diseaseManifestation[5] == "Острая"
            && (_diseaseManifestation[7] == "Бедро (Внутренняя сторона)" || _diseaseManifestation[7] == "Бедро (Внешняя сторона)")) {
        result += "Остеохондроз в поясничном отделе.\n";
    }
    if (_diseaseManifestation[1] == "Шейный отдел" && _diseaseManifestation[5] == "Острая"
            && (_diseaseManifestation[7] == "Шейный отдел")) {
        result += "Остеохондроз в шейном отделе.\n";
    }
    if (_diseaseManifestation[1] == "Грудной отдел" && _diseaseManifestation[5] == "Острая"
            && (_diseaseManifestation[7] == "Грудина")) {
        result += "Остеохондроз в грудном отделе.\n";
    }
    if (_diseaseManifestation[1] == "Кресцовый отдел" && _diseaseManifestation[5] == "Острая"
            && (_diseaseManifestation[7] == "Кресцовый отдел")) {
        result += "Остеохондроз в крестцовом отделе.\n";
    }

    if (_diseaseManifestation[1] == "Крестцовый отдел"
            && (_diseaseManifestation[7] == "Бедро (Внутренняя сторона)" || _diseaseManifestation[7] == "Бедро (Внешняя сторона)" || _diseaseManifestation[7] == "Колено")) {
        result += "Болезнь Бехтерева в крестцовом отделе.\n";
    }
    if (_diseaseManifestation[1] == "Грудной отдел"
            && (_diseaseManifestation[7] == "Межреберье")) {
        result += "Болезнь Бехтерева в грудном отделе.\n";
    }
    if (_diseaseManifestation[1] == "Шейный отдел"
            && (_diseaseManifestation[7] == "Шейный отдел" || _diseaseManifestation[6] == "Рука" || _diseaseManifestation[7] == "Плечо")) {
        result += "Болезнь Бехтерева в грудном отделе.\n";
    }

    if ((_diseaseManifestation[1] == "Поясничный отдел" || _diseaseManifestation[1] == "Кресцовый отдел") && (_diseaseManifestation[7] == "Бедро (Внутренняя сторона)" || _diseaseManifestation[7] == "Бедро (Внешняя сторона)")) {
        result += "Спондилолистез.\n";
    }

    if (_diseaseManifestation[1] == "Сколиоз" && _diseaseManifestation[0] == "Шейные") {
        result += "Шейный сколиоз.\n";
    }
    if (_diseaseManifestation[1] == "Сколиоз" && _diseaseManifestation[0] == "Поясничные") {
        result += "Поясничный сколиоз.\n";
    }

    if (_diseaseManifestation[1] == "Лордоз" && _diseaseManifestation[0] == "Шейные") {
        result += "Шейный сколиоз.\n";
    }
    if (_diseaseManifestation[1] == "Лордоз" && _diseaseManifestation[0] == "Поясничные") {
        result += "Поясничный сколиоз.\n";
    }

    return result;
}
