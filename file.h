#ifndef FILE_H
#define FILE_H

#include <QDialog>
#include <mainwindow.h>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

namespace Ui {
class File;
}

class File : public QDialog
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = nullptr);
    ~File();

private:
    Ui::File *ui;
    MainWindow *win;

private slots:
    void okClicked();

signals:
    void filePath(const QString &str);
};

#endif // FILE_H
