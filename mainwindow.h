#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_easyButton_clicked();

    void on_mediumButton_clicked();

    void on_hardButton_clicked();

private:
    Ui::MainWindow *ui;
    void UpdateScene(QGraphicsScene* scene);
};
#endif // MAINWINDOW_H