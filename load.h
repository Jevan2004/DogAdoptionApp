//
// Created by tanas on 5/20/2024.
//

#ifndef OOP_A8_A9_JEVAN2004_LOAD_H
#define OOP_A8_A9_JEVAN2004_LOAD_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class load; }
QT_END_NAMESPACE

class load : public QWidget {
Q_OBJECT

public:
    explicit load(QWidget *parent = nullptr);

    void init();
    ~load() override;

    signals:
    void load_data_selected();
    void dont_load_data_selected();
private:
    Ui::load *ui;
};


#endif //OOP_A8_A9_JEVAN2004_LOAD_H
