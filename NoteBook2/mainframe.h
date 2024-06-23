#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QMainWindow>
#include "dialog_login.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QColorDialog>
#include <QFontDialog> //易语言


QT_BEGIN_NAMESPACE

namespace Ui {
class MainFrame;
QT_END_NAMESPACE
}

class MainFrame : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainFrame(QWidget *parent = nullptr);
    ~MainFrame();

private slots:
    void on_actionNew_triggered();

    void on_actionsave_triggered();

    void on_actionexit_2_triggered();

    void on_actionopen_triggered();

    void on_actionundo_triggered();

    void on_actioncut_triggered();

    void on_actionpaste_triggered();

    void on_actioncopy_triggered();

    void on_actionsave2_triggered(); //修改

    void on_actionfont_triggered();

    void on_actioncolor_triggered();

private:
    Ui::MainFrame *ui;
     Dialog_login dialog; //只要窗体没结束那么我就一直存在
};

#endif // MAINFRAME_H
