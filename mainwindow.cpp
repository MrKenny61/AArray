#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file.h"
#include "list.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    ui->statusBar->showMessage("OK");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    File *wnd = new File(this);
    wnd->show();

    connect(wnd, SIGNAL(filePath(QString)), this, SLOT(openFile(QString)));

}

void MainWindow::openFile(const QString &filePath)
{
    QFile mFile(filePath);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Error open file");
        ui->statusBar->showMessage("Error open file");
        return;
    }
    QTextStream stream(&mFile);
    QString buffer = stream.readAll();
    ui->textEdit->setText(buffer);
    ui->statusBar->showMessage("Read to file: " + filePath);
    mFile.flush();
    mFile.close();
}

void MainWindow::on_actionTask_triggered()
{
    ui->textEdit->clear();
    Task("C:\\Users\\Vova\\Documents\\Qt\\window\\123.txt");
}

void MainWindow::Task(const QString &filePath)
{
    string path = filePath.toStdString();
    liststr aar = massive(path);
    string s = aar.Total();
    QString qs = QString::fromStdString(s);
    ui->textEdit->setText(qs);
}
