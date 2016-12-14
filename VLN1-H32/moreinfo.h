#ifndef MOREINFO_H
#define MOREINFO_H

#include <QDialog>

namespace Ui {
class MoreInfo;
}

class MoreInfo : public QDialog
{
    Q_OBJECT

public:
    explicit MoreInfo(QWidget *parent = 0);
    ~MoreInfo();

private:
    Ui::MoreInfo *ui;
};

#endif // MOREINFO_H
