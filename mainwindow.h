#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QTextEdit>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void openFile(const QString &filePath);
    void on_actionOpen_File_triggered();

    void Task(const QString &filePath);
    void on_actionTask_triggered();
};

#endif // MAINWINDOW_H
