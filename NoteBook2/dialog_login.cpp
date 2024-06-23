#include "dialog_login.h"
#include "ui_dialog_login.h"
#include <QMessageBox>  //信息对话框

Dialog_login::Dialog_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_login)
{
    ui->setupUi(this);
}

Dialog_login::~Dialog_login()
{
    delete ui;
}

//确认
void Dialog_login::on_btn_ok_clicked()
{
    //密码可以从我读取--用户的string
    QString user = ui->LineEdit_user->text().trimmed();//trimerd式为了去空格--放置不小心安乐控制但是登陆不了
    QString pwd = ui->LineEdit_password->text().trimmed();
    if(user == "admin" && pwd == "123456")
    {
        accept();

    }
    else
    {
        ui->LineEdit_password->clear();
        ui->LineEdit_user->clear();
        QMessageBox::warning(this,"警告","用户名或者密码错误");
    }
}

//取消
void Dialog_login::on_btn_cancel_clicked()
{
    reject();
}
