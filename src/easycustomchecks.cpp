#include "easycustomchecks.h"

EasyCustomChecks::EasyCustomChecks(QWidget *parent) : QWidget(parent)
{
    // document class selection
    docuclass = new QComboBox();
    docuclass->addItem("article");
    docuclass->addItem("report");
    docuclass->addItem("letter");
    docuclass->addItem("book");
    docuclass->addItem("proc");
    docuclass->addItem("slides");
    docuclass->addItem("apa6");
    docuclass->addItem("apa7");
    docuclass->addItem("IEEEtran");
    QLabel *docuclassLabel = new QLabel("Choose documentclass");
    // general document management packages
    geometry = new QCheckBox("geometry");
    QLabel *geometryLabel = new QLabel("Better page size handling");
    hyperref = new QCheckBox("hyperref");
    QLabel *hyperrefLabel = new QLabel("Better hyperlinks");
    enumitem = new QCheckBox("enumitem");
    QLabel *enumitemLabel = new QLabel("More enumerations");
    inputenc = new QCheckBox("inputenc");
    QLabel *inputencLabel = new QLabel("Define special encoding");
    // document management grid
    QGridLayout *docmngGrid = new QGridLayout;
    docmngGrid->addWidget(docuclass, 0 , 0);
    docmngGrid->addWidget(docuclassLabel, 0, 1, 1, 2);
    docmngGrid->addWidget(geometry, 1, 0);
    docmngGrid->addWidget(geometryLabel, 1, 1, 1, 2);
    docmngGrid->addWidget(hyperref, 2, 0);
    docmngGrid->addWidget(hyperrefLabel, 2, 1, 1, 2);
    docmngGrid->addWidget(enumitem, 3, 0);
    docmngGrid->addWidget(enumitemLabel, 3, 1, 1, 2);
    docmngGrid->addWidget(inputenc, 4, 0);
    docmngGrid->addWidget(inputencLabel, 4, 1, 1, 2);
    // document management group box
    QGroupBox *docmngGroup = new QGroupBox("General document");
    docmngGroup->setLayout(docmngGrid);

    // math related packages
    amsmath = new QCheckBox("amsmath");
    QLabel *amsmathLabel = new QLabel("Allows for most equation related needs");
    tcolorbox = new QCheckBox("tcolorbox");
    QLabel *tcolorboxLabel = new QLabel("Highlight answer or solution");
    // math grid layout
    QGridLayout *mathGrid = new QGridLayout;
    mathGrid->addWidget(amsmath, 0, 0);
    mathGrid->addWidget(amsmathLabel, 0, 1, 1, 2);
    mathGrid->addWidget(tcolorbox, 1, 0);
    mathGrid->addWidget(tcolorboxLabel, 1, 1, 1, 2);
    // math group box
    QGroupBox *mathGroup = new QGroupBox("Math/equations");
    mathGroup->setLayout(mathGrid);

    // Figures related packages
    graphicx = new QCheckBox("graphicx");
    QLabel *graphicxLabel = new QLabel("Easy figure inclusion to the document");
    floatpkg = new QCheckBox("float");
    QLabel *floatpkgLabel = new QLabel("Figures in the document body");
    // figure grid layout
    QGridLayout *figGrid = new QGridLayout;
    figGrid->addWidget(graphicx, 0, 0);
    figGrid->addWidget(graphicxLabel, 0, 1, 1, 2);
    figGrid->addWidget(floatpkg, 1, 0);
    figGrid->addWidget(floatpkgLabel, 1, 1, 1, 2);
    // fig group box
    QGroupBox *figGroup = new QGroupBox("Figures/pictures");
    figGroup->setLayout(figGrid);

    // EE related packages
    circuitz = new QCheckBox("circuitz");
    QLabel *circuitzLabel = new QLabel("Allows to generate circuit diagrams");
    // EE grid layout
    QGridLayout *eeGrid = new QGridLayout;
    eeGrid->addWidget(circuitz, 0, 0);
    eeGrid->addWidget(circuitzLabel, 0, 1, 1, 2);
    // EE group box
    QGroupBox *eeGroup = new QGroupBox("Electrical Engineering");
    eeGroup->setLayout(eeGrid);

    // coding related packages
    // aka: I hope you aren't just writing documentation without using MD
    listings = new QCheckBox("listings");
    QLabel *listingsLabel = new QLabel("Embedding code to the body");
    // EE grid layout
    QGridLayout *codeGrid = new QGridLayout;
    codeGrid->addWidget(listings, 0, 0);
    codeGrid->addWidget(listingsLabel, 0, 1, 1, 2);
    // EE group box
    QGroupBox *codeGroup = new QGroupBox("Coding related");
    codeGroup->setLayout(codeGrid);

    // final layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(docmngGroup);
    layout->addWidget(mathGroup);
    layout->addWidget(figGroup);
    layout->addWidget(eeGroup);
    layout->addWidget(codeGroup);
    setLayout(layout);
}

std::string EasyCustomChecks::GetDocuClass() { return docuclass->currentText().toStdString(); }

bool EasyCustomChecks::CheckedGeometry() { return geometry->isChecked(); }

bool EasyCustomChecks::CheckedMath() { return amsmath->isChecked(); }

bool EasyCustomChecks::CheckedTCBox() { return tcolorbox->isChecked(); }

bool EasyCustomChecks::CheckedGraphicx() { return graphicx->isChecked(); }

bool EasyCustomChecks::CheckedFloat() { return floatpkg->isChecked(); }

bool EasyCustomChecks::CheckedCircuit() { return circuitz->isChecked(); }

bool EasyCustomChecks::CheckedHyperref() { return hyperref->isChecked(); }

bool EasyCustomChecks::CheckedInputenc() { return inputenc->isChecked(); }

bool EasyCustomChecks::CheckedEnumitem() { return enumitem->isChecked(); }

bool EasyCustomChecks::CheckedListings() { return listings->isChecked(); }
