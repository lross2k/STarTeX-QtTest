#include "window.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Window w;
    w.show();

    return app.exec();
}
