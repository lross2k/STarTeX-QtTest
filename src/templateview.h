#ifndef TEMPLATE_VIEW_H
#define TEMPLATE_VIEW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class TemplateView : public QWidget {
    Q_OBJECT
public:
    explicit TemplateView(QWidget *parent = nullptr);
private:
};

#endif //TEMPLATE_VIEW_H
