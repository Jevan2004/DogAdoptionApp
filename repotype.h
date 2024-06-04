//
// Created by tanas on 5/14/2024.
//

#ifndef OOP_A8_A9_JEVAN2004_REPOTYPE_H
#define OOP_A8_A9_JEVAN2004_REPOTYPE_H

#include <QWidget>
#include <qpushbutton.h>


QT_BEGIN_NAMESPACE
namespace Ui { class RepoType; }
QT_END_NAMESPACE

class RepoType : public QWidget
{
    Q_OBJECT

public:
    RepoType(QWidget* parent = nullptr);

    void init();
signals:
    void csvSelected();
    void htmlSelected();
    void textFileSelected();
    void memorySelected();
};


#endif //OOP_A8_A9_JEVAN2004_REPOTYPE_H
