#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QFile>
#include <QTextStream>

#include <fstream>
#include <iostream>
#include <string>

#include "easycustomchecks.h"
#include "templateview.h"

class Window : public QWidget
{
    Q_OBJECT
private slots:
    void WriteDocument();
public:
    explicit Window(QWidget *parent = 0);
private:
    QTabWidget *TabWidget;
    QPushButton *CreateButton;
    EasyCustomChecks *CustomChecks;
    TemplateView *Templates;
};

#endif // WINDOW_H
