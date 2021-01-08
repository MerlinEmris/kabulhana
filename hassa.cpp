#include "hassa.h"

hassa::hassa(QWidget *parent)
    : QWidget(parent)
{
    /*------------------------------------------------------------------------
     *                                kabul                                 //
     *----------------------------------------------------------------------*/
    kabul = new QWidget;
    kabul_illAdd_Label = new QLabel("Hassa gosh");
    kabul_id_Label = new QLabel("Id");
    kabul_sname_Label = new QLabel("Familiyasy");
    kabul_name_Label = new QLabel("Ady");
    kabul_comeTime_Label = new QLabel("Wagty");
    kabul_lukmanlar_Label = new QLabel("Lukmanlar");
    kabul_location_Label = new QLabel("Yasayan yeri");
    kabul_bornDate_Label = new QLabel("Doglan senesi");

    kabul_id_LineEdit = new QLineEdit;
    kabul_name_LineEdit = new QLineEdit;
    kabul_sname_LineEdit = new QLineEdit;
    kabul_location_LineEdit = new QLineEdit;

    kabul_lukmanlar_ComboBox = new QComboBox;

    connect2Database();



    kabul_comeTime_DateTimeEdit = new QDateTimeEdit(QDate::currentDate());
    kabul_comeTime_DateTimeEdit->setDisplayFormat("yyyy-MM-dd hh-mm-ss");
    kabul_bornDate_DateTimeEdit = new QDateTimeEdit(QDate::currentDate());
    kabul_bornDate_DateTimeEdit->setDisplayFormat("yyyy-MM-dd");
    kabul_add_PushButton = new QPushButton("Gosh");
    kabul_delete_PushButton = new QPushButton("Poz");
    kabul_update_PushButton = new QPushButton("Tazele");
    kabul_clear_PushButton = new QPushButton("Arassala");
    kabul_back_PushButton = new QPushButton("Yza");
    kabul_view = new QTableView;
    kabul_model = new QSqlQueryModel;

    kabul_vb_VBoxLayout = new QVBoxLayout;
    kabul_hb_VBoxLayout = new QHBoxLayout;
    kabul_gb_GridLayout = new QGridLayout;
    kabul_vb_VBoxLayout->addWidget(kabul_illAdd_Label);
    kabul_gb_GridLayout->setSpacing(15);
    kabul_gb_GridLayout->addWidget(kabul_id_Label,0,0);
    kabul_gb_GridLayout->addWidget(kabul_name_Label,0,1);
    kabul_gb_GridLayout->addWidget(kabul_sname_Label,0,2);
    kabul_gb_GridLayout->addWidget(kabul_location_Label,0,3);
    kabul_gb_GridLayout->addWidget(kabul_bornDate_Label,0,4);
    kabul_gb_GridLayout->addWidget(kabul_lukmanlar_Label,0,5);
    kabul_gb_GridLayout->addWidget(kabul_comeTime_Label,0,6);
    kabul_gb_GridLayout->addWidget(kabul_id_LineEdit,1,0);
    kabul_gb_GridLayout->addWidget(kabul_name_LineEdit,1,1);
    kabul_gb_GridLayout->addWidget(kabul_sname_LineEdit,1,2);
    kabul_gb_GridLayout->addWidget(kabul_location_LineEdit,1,3);
    kabul_gb_GridLayout->addWidget(kabul_bornDate_DateTimeEdit,1,4);
    kabul_gb_GridLayout->addWidget(kabul_lukmanlar_ComboBox,1,5);
    kabul_gb_GridLayout->addWidget(kabul_comeTime_DateTimeEdit,1,6);
    kabul_vb_VBoxLayout->addLayout(kabul_gb_GridLayout);
    kabul_hb_VBoxLayout->addWidget(kabul_add_PushButton);
    kabul_hb_VBoxLayout->addWidget(kabul_delete_PushButton);
    kabul_hb_VBoxLayout->addWidget(kabul_update_PushButton);
    kabul_hb_VBoxLayout->addWidget(kabul_clear_PushButton);
    kabul_hb_VBoxLayout->addWidget(kabul_back_PushButton);
    kabul_vb_VBoxLayout->addLayout(kabul_hb_VBoxLayout);
    kabul_vb_VBoxLayout->addWidget(kabul_view);
    kabul->setLayout(kabul_vb_VBoxLayout);
    kabul_tableRefresh();
    kabul->show();

    connect(kabul_clear_PushButton,SIGNAL(clicked()),SLOT(kabul_clear_PushButtonSlot()));
    connect(kabul_delete_PushButton,SIGNAL(clicked()),SLOT(kabul_delete_PushButtonSlot()));
    connect(kabul_update_PushButton,SIGNAL(clicked()),SLOT(kabul_update_PushButtonSlot()));
    connect(kabul_add_PushButton,SIGNAL(clicked()),SLOT(kabul_add_PushButtonSlot()));
    connect(kabul_back_PushButton,SIGNAL(clicked()),SLOT(kabul_back_PushButtonSlot()));
    connect(kabul_id_LineEdit,SIGNAL(textChanged(QString)),SLOT(kabul_id_LineEditSlot()));
    /*------------------------------------------------------------------------
     *                              lukman edit                             //
     *----------------------------------------------------------------------*/
    lukmanEdit = new QWidget;
    lukmanEdit_id_Label = new QLabel("Id");
    lukmanEdit_name_Label = new QLabel("Ady");
    lukmanEdit_sname_Label = new QLabel("Familiyasy");
    lukmanEdit_kind_Label = new QLabel("Gornush");
    lukmanEdit_born_Label = new QLabel("Doglan sene");

    lukmanEdit_id_LineEdit = new QLineEdit;
    lukmanEdit_name_LineEdit = new QLineEdit;
    lukmanEdit_sname_LineEdit = new QLineEdit;

    lukmanEdit_kind_ComboBox = new QComboBox;


    lukmanEdit_born_DateTimeEdit = new QDateTimeEdit(QDate::currentDate());
    lukmanEdit_born_DateTimeEdit->setDisplayFormat("yyyy-MM-dd");

    lukmanEdit_add_PushButton = new QPushButton("Gosh");
    lukmanEdit_delete_PushButton = new QPushButton("Ayyr");
    lukmanEdit_update_PushButton = new QPushButton("Tazele");
    lukmanEdit_clear_PushButton = new QPushButton("Arassala");
    lukmanEdit_type_PushButton = new QPushButton("Hunarler");
    lukmanEdit_back_PushButton = new QPushButton("Yza");

    lukmanEdit_view = new QTableView;
    lukmanEdit_model = new QSqlQueryModel;
    lukmanEdit_vb_VBoxLayout = new QVBoxLayout;
    lukmanEdit_hb_VBoxLayout = new QHBoxLayout;
    lukmanEdit_gb_GridLayout = new QGridLayout;

    lukmanEdit_gb_GridLayout->setSpacing(15);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_id_Label,0,0);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_name_Label,0,1);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_sname_Label,0,2);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_kind_Label,0,3);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_born_Label,0,4);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_id_LineEdit,1,0);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_name_LineEdit,1,1);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_sname_LineEdit,1,2);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_kind_ComboBox,1,3);
    lukmanEdit_gb_GridLayout->addWidget(lukmanEdit_born_DateTimeEdit,1,4);

    lukmanEdit_vb_VBoxLayout->addLayout(lukmanEdit_gb_GridLayout);
    lukmanEdit_hb_VBoxLayout->addWidget(lukmanEdit_add_PushButton);
    lukmanEdit_hb_VBoxLayout->addWidget(lukmanEdit_delete_PushButton);
    lukmanEdit_hb_VBoxLayout->addWidget(lukmanEdit_update_PushButton);
    lukmanEdit_hb_VBoxLayout->addWidget(lukmanEdit_clear_PushButton);
    lukmanEdit_hb_VBoxLayout->addWidget(lukmanEdit_type_PushButton);
    lukmanEdit_hb_VBoxLayout->addWidget(lukmanEdit_back_PushButton);
    lukmanEdit_vb_VBoxLayout->addLayout(lukmanEdit_hb_VBoxLayout);
    lukmanEdit_vb_VBoxLayout->addWidget(lukmanEdit_view);
    lukmanEdit->setLayout(lukmanEdit_vb_VBoxLayout);
    lukmanEdit_tableRefresh();

    connect(lukmanEdit_clear_PushButton,SIGNAL(clicked()),SLOT(lukmanEdit_clear_PushButtonSlot()));
    connect(lukmanEdit_delete_PushButton,SIGNAL(clicked()),SLOT(lukmanEdit_delete_PushButtonSlot()));
    connect(lukmanEdit_update_PushButton,SIGNAL(clicked()),SLOT(lukmanEdit_update_PushButtonSlot()));
    connect(lukmanEdit_add_PushButton,SIGNAL(clicked()),SLOT(lukmanEdit_add_PushButtonSlot()));
    connect(lukmanEdit_back_PushButton,SIGNAL(clicked()),SLOT(lukmanEdit_back_PushButtonSlot()));
    connect(lukmanEdit_type_PushButton,SIGNAL(clicked()),SLOT(lukmanEdit_type_PushButtonSlot()));
    connect(lukmanEdit_id_LineEdit,SIGNAL(textChanged(QString)),SLOT(lukmanEdit_id_LineEditSlot()));
    /*------------------------------------------------------------------------
     *                                hunar edit                            //
     *----------------------------------------------------------------------*/
    hunarEdit = new QWidget;

    hunarEdit_id_Label = new QLabel("Id");
    hunarEdit_name_Label = new QLabel("Bolumin ady");

    hunarEdit_id_LineEdit = new QLineEdit;
    hunarEdit_name_LineEdit = new QLineEdit;

    hunarEdit_add_PushButton = new QPushButton("Gosh");
    hunarEdit_delete_PushButton = new QPushButton("Poz");
    hunarEdit_update_PushButton = new QPushButton("Tazele");
    hunarEdit_clear_PushButton = new QPushButton("Arassala");
    hunarEdit_back_PushButton = new QPushButton("Yza");

    hunarEdit_view = new QTableView;
    hunarEdit_model = new QSqlQueryModel;
    hunarEdit_vb_VBoxLayout = new QVBoxLayout;
    hunarEdit_hb_VBoxLayout = new QHBoxLayout;
    hunarEdit_gb_GridLayout = new QGridLayout;
    hunarEdit_gb_GridLayout->setSpacing(15);
    hunarEdit_gb_GridLayout->addWidget(hunarEdit_id_Label,0,0);
    hunarEdit_gb_GridLayout->addWidget(hunarEdit_name_Label,0,1);
    hunarEdit_gb_GridLayout->addWidget(hunarEdit_id_LineEdit,1,0);
    hunarEdit_gb_GridLayout->addWidget(hunarEdit_name_LineEdit,1,1);
    hunarEdit_hb_VBoxLayout->addWidget(hunarEdit_add_PushButton);
    hunarEdit_hb_VBoxLayout->addWidget(hunarEdit_delete_PushButton);
    hunarEdit_hb_VBoxLayout->addWidget(hunarEdit_update_PushButton);
    hunarEdit_hb_VBoxLayout->addWidget(hunarEdit_clear_PushButton);
    hunarEdit_hb_VBoxLayout->addWidget(hunarEdit_back_PushButton);
    hunarEdit_vb_VBoxLayout->addLayout(hunarEdit_gb_GridLayout);
    hunarEdit_vb_VBoxLayout->addLayout(hunarEdit_hb_VBoxLayout);
    hunarEdit_vb_VBoxLayout->addWidget(hunarEdit_view);
    hunarEdit->setLayout(hunarEdit_vb_VBoxLayout);
    hunarEdit_tableRefresh();
    connect(hunarEdit_clear_PushButton,SIGNAL(clicked()),SLOT(hunarEdit_clear_PushButtonSlot()));
    connect(hunarEdit_delete_PushButton,SIGNAL(clicked()),SLOT(hunarEdit_delete_PushButtonSlot()));
    connect(hunarEdit_update_PushButton,SIGNAL(clicked()),SLOT(hunarEdit_update_PushButtonSlot()));
    connect(hunarEdit_add_PushButton,SIGNAL(clicked()),SLOT(hunarEdit_add_PushButtonSlot()));
    connect(hunarEdit_back_PushButton,SIGNAL(clicked()),SLOT(hunarEdit_back_PushButtonSlot()));
    connect(hunarEdit_id_LineEdit,SIGNAL(textChanged(QString)),SLOT(hunarEdit_id_LineEditSlot()));
}

void hassa::connect2Database()
{

    derman = QSqlDatabase::addDatabase("QSQLITE");
    derman.setDatabaseName("kabulhana.db");
    if(derman.open())
    {
        kabul->setWindowTitle("connected");
    }
    else
    {
        kabul->setWindowTitle("not connected");
    }

    QSqlQuery   query;
    if(query.exec("select * from hassalar;") || query.exec("select * from lukmanlar"))
    {
        //QMessageBox::about(this,"Records","Tables are exist");
    }
    else
    {
        //hassa
        if(query.exec("create table hassalar (ID integer primary key autoincrement,name varchar(45),sname varchar(45),location varchar(100),born date,lukman varchar(45),comeTime date);"))
        {
            QMessageBox::about(this,"Records","hassalar tablisasy doredildi");
        }
        else
        {
            QMessageBox::about(this,"Records","hassalar tablisasy doredilmedi");
        }
        //hunar
        if(query.exec("create table hunar (ID integer primary key autoincrement,name varchar(45));"))
        {
            QMessageBox::about(this,"Records","hunar tablisasy doredildi");
            //query.exec("insert into hunar(name) values('Nevrolog'),('dermotolog'),('dantist'),('ankolog')");
        }
        else
        {
            QMessageBox::about(this,"Records","hassalar tablisasy doredilmedi");
        }
        //lukman
        if(query.exec("create table lukmanlar (ID integer primary key autoincrement,name varchar(45),sname varchar(45),kind varchar(45),born date);"))
        {
                QMessageBox::about(this,"Records","lukman table doredildi");
        }
        else
        {
                QMessageBox::about(this,"Records","lukman table doredilmedi");
        }
    }


}

hassa::~hassa()
{

}

void hassa::kabul_tableRefresh()
{
    kabul_model->setQuery("SELECT * FROM hassalar;");
    kabul_model->setHeaderData(0,Qt::Horizontal,tr("ID"));
    kabul_model->setHeaderData(1, Qt::Horizontal, tr("Ady"));
    kabul_model->setHeaderData(2,Qt::Horizontal, tr("Familiyasy"));
    kabul_model->setHeaderData(3,Qt::Horizontal, tr("Yasayan salgysy"));
    kabul_model->setHeaderData(4,Qt::Horizontal, tr("Doglan yyly"));
    kabul_model->setHeaderData(5,Qt::Horizontal, tr("lukman"));
    kabul_model->setHeaderData(6,Qt::Horizontal, tr("Gelen wagty"));
    kabul_view->setModel(kabul_model);

    QSqlQuery luki;
    if(!luki.exec("SELECT * FROM lukmanlar;"))
        QMessageBox::critical(this,"Error","Error");
    else
    while(luki.next())
    {
        lukmanlar<<luki.record().value("name").toString()+" "+luki.record().value("sname").toString();
        //QMessageBox::about(this,"Records",luki->record().value("name").toString()+" "+luki->record().value("sname").toString());
    }
    kabul_lukmanlar_ComboBox->clear();
    kabul_lukmanlar_ComboBox->addItems(lukmanlar);
    lukmanlar.clear();
}

void hassa::kabul_clearEditLine()
{
    kabul_id_LineEdit->clear();
    kabul_name_LineEdit->clear();
    kabul_sname_LineEdit->clear();
    kabul_location_LineEdit->clear();
    kabul_bornDate_DateTimeEdit->setDate(QDate::currentDate());
    kabul_comeTime_DateTimeEdit->setDate(QDate::currentDate());
}
//kabul start
void hassa::kabul_add_PushButtonSlot()
{
    QSqlQuery query;
    if(query.exec("INSERT INTO hassalar (name,sname,location,born,lukman,comeTime)"
               "VALUES('"+kabul_name_LineEdit->text()
                  +"','"+kabul_sname_LineEdit->text()
                  +"','"+kabul_location_LineEdit->text()
                  +"','"+kabul_bornDate_DateTimeEdit->text()
                  +"','"+kabul_lukmanlar_ComboBox->currentText()
                  +"','"+kabul_comeTime_DateTimeEdit->text()
                  +"');"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme goshuldow bravo bla");
        kabul_tableRefresh();
        kabul_clearEditLine();
    }
    else
    {
        QMessageBox::about(this,"Records","INSERT INTO hassalar (name,sname,location,born,lukman,comeTime)"
                                          "VALUES('"+kabul_name_LineEdit->text()
                                             +"','"+kabul_sname_LineEdit->text()
                                             +"','"+kabul_location_LineEdit->text()
                                             +"','"+kabul_bornDate_DateTimeEdit->text()
                                             +"','"+kabul_lukmanlar_ComboBox->currentText()
                                             +"','"+kabul_comeTime_DateTimeEdit->text()
                                             +"'); sql not work");
    }
}

void hassa::kabul_delete_PushButtonSlot()
{
    QSqlQuery query;
    if(query.exec("delete from hassalar where ID="+kabul_id_LineEdit->text()+";"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme pozuldow bravo bla");
        kabul_tableRefresh();
        kabul_clearEditLine();
    }
    else
    {
        QMessageBox::about(this,"Records"," blin bolmady ");
    }
}

void hassa::kabul_update_PushButtonSlot()
{

    QSqlQuery query1;
    if(query1.exec("update hassalar set "
                   "name='"+kabul_name_LineEdit->text()
                   +"',sname='"+kabul_sname_LineEdit->text()
                   +"',location='"+kabul_location_LineEdit->text()
                   +"',born='"+kabul_bornDate_DateTimeEdit->text()
                   +"',lukman='"+kabul_lukmanlar_ComboBox->currentText()
                   +"',comeTime='"+kabul_comeTime_DateTimeEdit->text()
                   +"' where ID="+kabul_id_LineEdit->text()
                   +";"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme uytgedildi bravo bla");
        kabul_tableRefresh();
        kabul_clearEditLine();
    }
    else
    {
        QMessageBox::about(this,"Records","gechmish olsun");
    }
}

void hassa::kabul_clear_PushButtonSlot()
{

}

void hassa::kabul_back_PushButtonSlot()
{
    lukmanEdit->show();
    kabul->close();
    kabul_tableRefresh();
    lukmanEdit_tableRefresh();
}

void hassa::kabul_id_LineEditSlot()
{
    QString name,sname,location,born,lukman,comeTime,quer;
    quer="select * from hassalar where ID="+kabul_id_LineEdit->text()+";";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(quer);
    name = model->data(model->index(0, 1)).toString();
    sname = model->data(model->index(0, 2)).toString();
    location = model->data(model->index(0, 3)).toString();
    born = model->data(model->index(0, 4)).toString();
    lukman = model->data(model->index(0, 5)).toString();
    comeTime = model->data(model->index(0, 6)).toString();
    kabul_name_LineEdit->setText(name);
    kabul_sname_LineEdit->setText(sname);
    kabul_location_LineEdit->setText(location);
    kabul_lukmanlar_ComboBox->setCurrentText(lukman);
    //kabul_comeTime_DateTimeEdit->setDate((QDate)comeTime);
    //kabul_bornDate_DateTimeEdit->setDate((QDate)born);
}

void hassa::lukmanEdit_tableRefresh()
{
    lukmanEdit_model->setQuery("SELECT * FROM lukmanlar;");
    lukmanEdit_model->setHeaderData(0,Qt::Horizontal,tr("ID"));
    lukmanEdit_model->setHeaderData(1, Qt::Horizontal,tr("Ady"));
    lukmanEdit_model->setHeaderData(2,Qt::Horizontal,tr("Familiyasy"));
    lukmanEdit_model->setHeaderData(3,Qt::Horizontal,tr("Gornush"));
    lukmanEdit_model->setHeaderData(4,Qt::Horizontal,tr("Doglan yyly"));
    lukmanEdit_view->setModel(lukmanEdit_model);

    QSqlQuery luki;
    if(!luki.exec("SELECT * FROM hunar;"))
        QMessageBox::critical(this,"Error","Error");
    else
    while(luki.next())
    {
        gornushler<<luki.record().value("name").toString();
        //QMessageBox::about(this,"Records",luki->record().value("name").toString()+" "+luki->record().value("sname").toString());
    }
    lukmanEdit_kind_ComboBox->clear();
    lukmanEdit_kind_ComboBox->addItems(gornushler);
    gornushler.clear();
}

void hassa::lukmanEdit_clearLineEdit()
{
    lukmanEdit_id_LineEdit->clear();
    lukmanEdit_name_LineEdit->clear();
    lukmanEdit_sname_LineEdit->clear();
    lukmanEdit_born_DateTimeEdit->setDate(QDate::currentDate());
}

void hassa::lukmanEdit_add_PushButtonSlot()
{
    QSqlQuery query;
    if(query.exec("INSERT INTO lukmanlar (name,sname,kind,born) "
               "VALUES('"+lukmanEdit_name_LineEdit->text()
                   +"','"+lukmanEdit_sname_LineEdit->text()
                   +"','"+lukmanEdit_kind_ComboBox->currentText()
                   +"','"+lukmanEdit_born_DateTimeEdit->text()
                   +"');"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme goshuldow bravo bla");
        lukmanEdit_tableRefresh();
        lukmanEdit_clearLineEdit();
    }
    else
    {
        QMessageBox::about(this,"Records","INSERT INTO lukmanlar (name,sname,kind,born) "
                                          "VALUES('"+lukmanEdit_name_LineEdit->text()
                                              +"','"+lukmanEdit_sname_LineEdit->text()
                                              +"','"+lukmanEdit_kind_ComboBox->currentText()
                                              +"','"+lukmanEdit_born_DateTimeEdit->text()
                                              +"');");
    }

}

void hassa::lukmanEdit_delete_PushButtonSlot()
{
    QSqlQuery query;
    if(query.exec("delete from lukmanlar where ID="+lukmanEdit_id_LineEdit->text()+";"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme pozuldow bravo bla");
        lukmanEdit_tableRefresh();
        lukmanEdit_clearLineEdit();
    }
    else
    {
        QMessageBox::about(this,"Records"," blin bolmady ");
    }
}

void hassa::lukmanEdit_update_PushButtonSlot()
{
    QSqlQuery query1;
    if(query1.exec("update lukmanlar set "
                   "name='"+lukmanEdit_name_LineEdit->text()
                   +"',sname='"+lukmanEdit_sname_LineEdit->text()
                   +"',kind='"+lukmanEdit_kind_ComboBox->currentText()
                   +"',born='"+lukmanEdit_born_DateTimeEdit->text()
                   +"' where ID="+lukmanEdit_id_LineEdit->text()
                   +";"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme uytgedildi bravo bla");
        lukmanEdit_tableRefresh();
        lukmanEdit_clearLineEdit();
    }
    else
    {
        QMessageBox::about(this,"Records","gechmish olsun");
    }
}

void hassa::lukmanEdit_clear_PushButtonSlot()
{

}

void hassa::lukmanEdit_back_PushButtonSlot()
{
    lukmanEdit->close();
    kabul->show();
    kabul_tableRefresh();
}

void hassa::lukmanEdit_type_PushButtonSlot()
{
    hunarEdit->show();
    lukmanEdit->close();
    lukmanEdit_tableRefresh();
    hunarEdit_tableRefresh();
}

void hassa::lukmanEdit_id_LineEditSlot()
{
    QString name,sname,kind,born,quer;
    quer="select * from lukmanlar where ID="+lukmanEdit_id_LineEdit->text()+";";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(quer);
    name = model->data(model->index(0, 1)).toString();
    sname = model->data(model->index(0, 2)).toString();
    kind = model->data(model->index(0, 3)).toString();
    born = model->data(model->index(0, 4)).toString();
    lukmanEdit_name_LineEdit->setText(name);
    lukmanEdit_sname_LineEdit->setText(sname);
    lukmanEdit_kind_ComboBox->setCurrentText(kind);
    //lukmanEdit_born_DateTimeEdit->setDate((QDate)born);
}

void hassa::hunarEdit_tableRefresh()
{
    hunarEdit_model->setQuery("SELECT * FROM hunar;");
    hunarEdit_model->setHeaderData(0,Qt::Horizontal,tr("ID"));
    hunarEdit_model->setHeaderData(1, Qt::Horizontal,tr("Ady"));
    hunarEdit_view->setModel(hunarEdit_model);
}

void hassa::hunarEdit_clearLineEdit()
{

}

void hassa::hunarEdit_add_PushButtonSlot()
{
    QSqlQuery query;
    if(query.exec("INSERT INTO hunar (name) "
               "VALUES('"+hunarEdit_name_LineEdit->text()
                   +"');"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme goshuldow bravo bla");
        hunarEdit_tableRefresh();
        hunarEdit_clearLineEdit();
    }
    else
    {
        QMessageBox::about(this,"Records","INSERT INTO hunar (name) "
                                          "VALUES('"+lukmanEdit_name_LineEdit->text()
                                              +"');");
    }
}

void hassa::hunarEdit_delete_PushButtonSlot()
{
    QSqlQuery query;
    if(query.exec("delete from hunar where ID="+hunarEdit_id_LineEdit->text()+";"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme pozuldow bravo bla");
        hunarEdit_tableRefresh();
        hunarEdit_clearLineEdit();
    }
    else
    {
        QMessageBox::about(this,"Records"," blin bolmady ");
    }
}

void hassa::hunarEdit_update_PushButtonSlot()
{
    QSqlQuery query1;
    if(query1.exec("update hunar set "
                   "name='"+hunarEdit_name_LineEdit->text()
                   +"' where ID="+hunarEdit_id_LineEdit->text()
                   +";"))
    {
        QMessageBox::about(this,"Records","ey inim tuweleme uytgedildi bravo bla");
        hunarEdit_tableRefresh();
        hunarEdit_clearLineEdit();
    }
    else
    {
        QMessageBox::about(this,"Records","gechmish olsun");
    }
}

void hassa::hunarEdit_clear_PushButtonSlot()
{
    hunarEdit_clearLineEdit();
}

void hassa::hunarEdit_back_PushButtonSlot()
{
    hunarEdit->close();
    lukmanEdit->show();
    lukmanEdit_tableRefresh();
}

void hassa::hunarEdit_id_LineEditSlot()
{
    QString name,quer;
    quer="select * from hunar where ID="+hunarEdit_id_LineEdit->text()+";";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(quer);
    name = model->data(model->index(0, 1)).toString();
    hunarEdit_name_LineEdit->setText(name);
}
//kabul end
