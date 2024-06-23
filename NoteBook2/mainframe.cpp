#include "mainframe.h"
#include "ui_mainframe.h"

MainFrame::MainFrame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainFrame)
{
    ui->setupUi(this);

    if(dialog.exec() == QDialog::Accepted)
    {
        ;
    }
    else
    {
        this->close();
        exit(0);
    }
    dialog.show();//非模态，步阻塞
}

MainFrame::~MainFrame()
{
    delete ui;
}

void MainFrame::on_actionNew_triggered()
{

}

//保存
void MainFrame::on_actionsave2_triggered()
{
    //1.判断是否保存了-如何实现？
    //首先，定义一个变量，不是不是 应该是建立一个信号槽机制，只要文本内容发生了改变，那么就触发这个函数，把我们的这个变量 改为 false，然后检测如果是false那么就重新把信的内容赋值位最新的内容
    //检测的是QTEXTEdit是否发生了改变
//    QTextEdit

    /*2.如果没保存那么就可以直接调用另存为--胡总和直接用它的代码逻辑
     *
     * 保存了的话，那就是把我的文件内容重新写入一遍，胡总和是更新
     */
}

//另存为
void MainFrame::on_actionsave_triggered()
{

    QString filename = QFileDialog::getSaveFileName(this,"文件另存为");
    ui->textEdit->setText(filename);
    QFile file(filename);
    bool res = file.open(QIODevice::WriteOnly | QFile::Text); //如果调用出来什么文字都没有呢？
    if(res)
    {
        setWindowTitle(filename);//设置窗体得标题
        QTextStream out(&file); //流 绑定文件 #include <QTextStream>
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
    ui->textEdit->setText(text);

    }
    else //打开文件失败
    {
        //需要提示
        //没有跳出来添加头文件
        QMessageBox::about(this,"提示","文件打开失败");
    }
}

void MainFrame::on_actionexit_2_triggered()
{

}

//打开
    void MainFrame::on_actionopen_triggered()
    {
            QString filename = QFileDialog::getSaveFileName(this,"打开文件");
            ui->textEdit->setText(filename);
            QFile file(filename);
            bool res = file.open(QIODevice::ReadOnly | QFile::Text); //如果调用出来什么文字都没有呢？
            if(res)
            {
                setWindowTitle(filename);//设置窗体得标题
                QTextStream in(&file); //流 绑定文件 #include <QTextStream>
                QString text = in.readAll(); //读取内容
            ui->textEdit->setText(text); //覆盖显示
//            ui->textEdit->append(text);

            }
            else //打开文件失败
            {
                //需要提示
                //没有跳出来添加头文件
                QMessageBox::about(this,"提示","文件打开失败");
            }

    }












void MainFrame::on_actionundo_triggered()
{

}

void MainFrame::on_actioncut_triggered()
{

}

void MainFrame::on_actionpaste_triggered()
{

}

void MainFrame::on_actioncopy_triggered()
{

}


//字体,调用

void MainFrame::on_actionfont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if(ok)
    {
        //按值 按地址 一般交换只能用地址   但是引用也可以
        ui->textEdit->setFont(font);
    }
}


//颜色
void MainFrame::on_actioncolor_triggered()
{
    QColor color = QColorDialog::getColor(); //获取颜色
    //如何使用呢？
    //画板的类Qpalette？    调色板
    QPalette palette = ui->textEdit->palette();//先获取到控件的调色板--然后才可以修改
    palette.setColor(QPalette::Text,color); //加载颜色
    ui->textEdit->setPalette(palette);//修改颜色


//    color.getRgb()
}




















