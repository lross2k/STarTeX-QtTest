#include "templateview.h"

TemplateView::TemplateView(QWidget *parent) : QWidget(parent)
{
    QLabel *text2 = new QLabel("Feature for a future version");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(text2);

    setLayout(layout);
}
