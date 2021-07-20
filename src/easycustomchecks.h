#ifndef EASY_CUSTOM_CHECKS_H
#define EASY_CUSTOM_CHECKS_H

#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QComboBox>

#include <string>

class EasyCustomChecks : public QWidget {
    Q_OBJECT
public:
    explicit EasyCustomChecks(QWidget *parent = nullptr);
    std::string GetDocuClass();
    bool CheckedGeometry();
    bool CheckedMath();
    bool CheckedTCBox();
    bool CheckedGraphicx();
    bool CheckedFloat();
    bool CheckedCircuit();
    bool CheckedHyperref();
    bool CheckedInputenc();
    bool CheckedEnumitem();
    bool CheckedListings();
private:
    QComboBox *docuclass;
    QCheckBox *geometry;
    QCheckBox *amsmath;
    QCheckBox *tcolorbox;
    QCheckBox *graphicx;
    QCheckBox *floatpkg;
    QCheckBox *circuitz;
    QCheckBox *inputenc;
    QCheckBox *hyperref;
    QCheckBox *enumitem;
    QCheckBox *listings;
};

#endif //EASY_CUSTOM_CHECKS_H
