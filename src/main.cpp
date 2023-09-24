#include <QtUiTools>
#include <QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QFile>
#include <memory>

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

    //! [2]
    auto *inputSpinBox1 = formWidget->findChild<QSpinBox *>(u"inputSpinBox1"_s);
    auto *inputSpinBox2 = formWidget->findChild<QSpinBox *>(u"inputSpinBox2"_s);
    auto *outputWidget = formWidget->findChild<QLabel *>(u"outputWidget"_s);
    //! [2]

    //! [3]
    auto updateResult = [inputSpinBox1, inputSpinBox2, outputWidget]()
    {
        const int sum = inputSpinBox1->value() + inputSpinBox2->value();
        outputWidget->setText(QString::number(sum));
    };
    QObject::connect(inputSpinBox1, &QSpinBox::valueChanged, formWidget, updateResult);
    QObject::connect(inputSpinBox2, &QSpinBox::valueChanged, formWidget, updateResult);
    //! [3]

    return formWidget;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    auto *formWidget = loadCalculatorForm(&w);
    if (formWidget == nullptr)
        return -1;
    //! [4]
    auto *layout = new QVBoxLayout(&w);
    layout->addWidget(formWidget);
    w.setWindowTitle(QCoreApplication::translate("CalculatorForm",
                                                 "Calculator Builder"));
    //! [4]
    w.show();
    return app.exec();
}
