QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deformation_local_window.cpp \
    injury_window.cpp \
    main.cpp \
    main_window.cpp \
    neuro_local_window.cpp \
    pain_local_window.cpp \
    patient_disease_window.cpp \
    patient_history_data_clasess/deformation_local_data.cpp \
    patient_history_data_clasess/document_writer.cpp \
    patient_history_data_clasess/illness_code.cpp \
    patient_history_data_clasess/neuro_local_data.cpp \
    patient_history_data_clasess/pain_local_data.cpp \
    patient_history_data_clasess/patient_data.cpp \
    patient_history_data_clasess/patient_disease_data.cpp \
    patient_history_data_clasess/patient_history.cpp \
    patient_history_data_clasess/patient_injury_data.cpp

HEADERS += \
    deformation_local_window.h \
    injury_window.h \
    main_window.h \
    neuro_local_window.h \
    pain_local_window.h \
    patient_disease_window.h \
    patient_history_data_clasess/deformation_local_data.h \
    patient_history_data_clasess/document_writer.h \
    patient_history_data_clasess/illness_code.h \
    patient_history_data_clasess/neuro_local_data.h \
    patient_history_data_clasess/pain_local_data.h \
    patient_history_data_clasess/patient_data.h \
    patient_history_data_clasess/patient_disease_data.h \
    patient_history_data_clasess/patient_history.h \
    patient_history_data_clasess/patient_injury_data.h

FORMS += \
    deformation_local_window.ui \
    injury_window.ui \
    main_window.ui \
    neuro_local_window.ui \
    pain_local_window.ui \
    patient_disease_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Questionnaire.pro.user \
    patient_history_data_clasess/Dictionary.txt
