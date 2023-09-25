#include <QtUiTools>
#include <QApplication>
#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QTranslator>
#include <QFile>
#include <memory>
#include "FlowLayout.h"

using namespace Qt::StringLiterals;

static QWidget *loadCalculatorForm(QWidget *parent = nullptr)
{
    QFile file(u":/forms/form.ui"_s);
    if (!file.open(QFile::ReadOnly))
        return nullptr;

    QUiLoader loader;
    QWidget *formWidget = loader.load(&file, parent);

    file.close();
    if (formWidget == nullptr)
        return nullptr;

    auto *inputSpinBox1 = formWidget->findChild<QSpinBox *>(u"inputSpinBox1"_s);
    auto *inputSpinBox2 = formWidget->findChild<QSpinBox *>(u"inputSpinBox2"_s);
    auto *outputWidget = formWidget->findChild<QLabel *>(u"outputWidget"_s);

    auto updateResult = [inputSpinBox1, inputSpinBox2, outputWidget]()
    {
        const int sum = inputSpinBox1->value() + inputSpinBox2->value();
        outputWidget->setText(QString::number(sum));
    };
    QObject::connect(inputSpinBox1, &QSpinBox::valueChanged, formWidget, updateResult);
    QObject::connect(inputSpinBox2, &QSpinBox::valueChanged, formWidget, updateResult);

    return formWidget;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget widget;
    
    // auto *formWidget = loadCalculatorForm(&widget);
    // if (formWidget == nullptr)
        // return -1;
    //! [4]
    // auto *layout = new QVBoxLayout(&widget);
    // layout->addWidget(formWidget);

    FlowLayout *flowLayout = new FlowLayout;
    flowLayout->addWidget(new QPushButton(QPushButton::tr("Short")));
    flowLayout->addWidget(new QPushButton(QPushButton::tr("Longer")));
    flowLayout->addWidget(new QPushButton(QPushButton::tr("Different text")));
    flowLayout->addWidget(new QPushButton(QPushButton::tr("More text")));
    flowLayout->addWidget(new QPushButton(QPushButton::tr("Even longer button text")));
    widget.setLayout(flowLayout);

    widget.setWindowTitle(QCoreApplication::translate("Orianne",
                                                 "Orianne Test"));
    //! [4]
    widget.show();
    return app.exec();
}
