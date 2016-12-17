#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <bits/stdc++.h>
using namespace std;

string ipath;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QString path = QFileDialog::getOpenFileName(this, tr("Open a file"), ".", tr("Assembler Files(*.yo)"));
    if(path.length() == 0) {
        exit(0);
    }
    else {
        ;//QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
    }
    ipath = path.toStdString();
    pipe_init(ipath);

    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(stepOne()));
    ui->mem_watch->resizeColumnsToContents();
    ui->ins_watch->resizeColumnsToContents();
}



void MainWindow::timerGo() {
    timer->start(1000);
}

void MainWindow::timerPause() {
    timer->stop();
}

void MainWindow::stepOne() {

    if (ended) {
        QMessageBox::information(NULL, tr(""), tr("Program has ended."));
        timerPause();
        return;
    }

    cerr << "step one called!" << endl;
    proc_one();
    showAll();
}

void MainWindow::stepNext() {
    cerr << "step next called!" << endl;
    timer->stop();
    stepOne();
}

void MainWindow::pipeReset() {
    pipe_init(ipath);
    showAll();
}

QString to16(int x) {
    stringstream buf;
    buf << "0x" << std::hex << x;
    return QString::fromStdString(buf.str());
}

void ST(QLineEdit *w, int x) {
    w->setText(to16(x));
}

void ST(QLineEdit *w, string x) {
    w->setText(QString::fromStdString(x));
}

void MainWindow::showAll() {
    const PIPE_ &p = PIPE[clock_cnt];
    cerr << "showAll called!!" << endl;
    ST(ui->tcond,to_string(p.ALU.ZF)+","+to_string(p.ALU.SF) +","+to_string(p.ALU.OF));
    /*
    printf("\"RegisterFiles\" : { ");
    printf("\"eax\" : %d, ",val[0]);
    printf("\"ecx\" : %d, ",val[1]);
    printf("\"edx\" : %d, ",val[2]);
    printf("\"ebx\" : %d, ",val[3]);
    printf("\"esp\" : %d, ",val[4]);
    printf("\"ebp\" : %d, ",val[5]);
    printf("\"esi\" : %d, ",val[6]);
    printf("\"edi\" : %d ",val[7]);
    printf("}\n");
    */
    ST(ui->teax, p.RegisterFiles.val[0]);
    ST(ui->tecx, p.RegisterFiles.val[1]);
    ST(ui->tedx, p.RegisterFiles.val[2]);
    ST(ui->tebx, p.RegisterFiles.val[3]);
    ST(ui->tesp, p.RegisterFiles.val[4]);
    ST(ui->tebp, p.RegisterFiles.val[5]);
    ST(ui->tesi, p.RegisterFiles.val[6]);
    ST(ui->tedi, p.RegisterFiles.val[7]);

    ST(ui->WdstE, p.W.dstE);
    ST(ui->WdstM, p.W.dstM);
    ST(ui->Wicode, p.W.icode);
    ST(ui->Wstat, p.W.stat);
    ST(ui->WvalE, p.W.valE);
    ST(ui->WvalM, p.W.valM);
    //ST(ui->Wstall, p.W.stall);

    ST(ui->MCnd, p.M.Cnd);
    ST(ui->MdstE, p.M.dstE);
    ST(ui->MdstM, p.M.dstM);
    ST(ui->Micode, p.M.icode);
    ST(ui->Mstat, p.M.stat);
    ST(ui->MvalA, p.M.valA);
    ST(ui->MvalE, p.M.valE);
    //p.M.bubble

    ST(ui->EdstE, p.E.dstE);
    ST(ui->EdstM, p.E.dstM);
    ST(ui->Eicode, p.E.icode);
    ST(ui->Eifun, p.E.ifun);
    ST(ui->EsrcA, p.E.srcA);
    ST(ui->EsrcB, p.E.srcB);
    ST(ui->Estat, p.E.stat);
    ST(ui->EvalA, p.E.valA);
    ST(ui->EvalB, p.E.valB);
    ST(ui->EvalE, p.E.valC);
    //         ^
    //p.E.bubble

    ST(ui->Dicode, p.D.icode);
    ST(ui->Difun, p.D.ifun);
    ST(ui->DrA, p.D.rA);
    ST(ui->DrB, p.D.rB);
    ST(ui->Dstat, p.D.stat);
    ST(ui->DvalC, p.D.valC);
    ST(ui->DvalP, p.D.valP);
    //p.D.bubble, p.D.ifun

    ST(ui->tpredPC, p.F.predPC);
    //for ()
}

void MainWindow::on_MainWindow_destroyed() {

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bReset_clicked()
{

}

