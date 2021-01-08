#ifndef HASSA_H
#define HASSA_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QComboBox>
#include <QStringList>
#include <QDebug>
#include <QTableView>
#include <QGridLayout>
#include <QDateTimeEdit>
#include <QTableView>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlTableModel>

class hassa : public QWidget
{
    Q_OBJECT

public:
    hassa(QWidget *parent = 0);
    void connect2Database();
    QSqlDatabase derman;
    ~hassa();
/*------------------------------------------------------------------------
 *                                kabul                                 //
 *----------------------------------------------------------------------*/
public:
    void kabul_tableRefresh();
    void kabul_clearEditLine();

private:
    QWidget *kabul;
    QLabel *kabul_illAdd_Label;
    QLabel *kabul_id_Label;
    QLabel *kabul_sname_Label;
    QLabel *kabul_name_Label;
    QLabel *kabul_comeTime_Label;
    QLabel *kabul_lukmanlar_Label;
    QLabel *kabul_location_Label;
    QLabel *kabul_bornDate_Label;

    QStringList lukmanlar;

    QLineEdit *kabul_id_LineEdit;
    QLineEdit *kabul_name_LineEdit;
    QLineEdit *kabul_sname_LineEdit;
    QLineEdit *kabul_location_LineEdit;
    QComboBox *kabul_lukmanlar_ComboBox;
    QDateTimeEdit *kabul_comeTime_DateTimeEdit;
    QDateTimeEdit *kabul_bornDate_DateTimeEdit;

    QPushButton *kabul_add_PushButton;
    QPushButton *kabul_delete_PushButton;
    QPushButton *kabul_update_PushButton;
    QPushButton *kabul_clear_PushButton;
    QPushButton *kabul_back_PushButton;

    QVBoxLayout *kabul_vb_VBoxLayout;
    QHBoxLayout *kabul_hb_VBoxLayout;
    QGridLayout *kabul_gb_GridLayout;

    QTableView *kabul_view;
    QSqlQueryModel *kabul_model;

private slots:
    void kabul_add_PushButtonSlot();
    void kabul_delete_PushButtonSlot();
    void kabul_update_PushButtonSlot();
    void kabul_clear_PushButtonSlot();
    void kabul_back_PushButtonSlot();
    void kabul_id_LineEditSlot();
/*------------------------------------------------------------------------
 *                               lukman edit                            //
 *----------------------------------------------------------------------*/
public:
    void lukmanEdit_tableRefresh();
    void lukmanEdit_clearLineEdit();
private:
    QWidget *lukmanEdit;
    QLabel *lukmanEdit_id_Label;
    QLabel *lukmanEdit_name_Label;
    QLabel *lukmanEdit_sname_Label;
    QLabel *lukmanEdit_kind_Label;
    QLabel *lukmanEdit_born_Label;

    QLineEdit *lukmanEdit_id_LineEdit;
    QLineEdit *lukmanEdit_name_LineEdit;
    QLineEdit *lukmanEdit_sname_LineEdit;
    QStringList gornushler;
    QComboBox *lukmanEdit_kind_ComboBox;

    QDateTimeEdit *lukmanEdit_born_DateTimeEdit;

    QPushButton *lukmanEdit_add_PushButton;
    QPushButton *lukmanEdit_delete_PushButton;
    QPushButton *lukmanEdit_update_PushButton;
    QPushButton *lukmanEdit_clear_PushButton;
    QPushButton *lukmanEdit_back_PushButton;
    QPushButton *lukmanEdit_type_PushButton;

    QVBoxLayout *lukmanEdit_vb_VBoxLayout;
    QHBoxLayout *lukmanEdit_hb_VBoxLayout;
    QGridLayout *lukmanEdit_gb_GridLayout;

    QTableView *lukmanEdit_view;
    QSqlQueryModel *lukmanEdit_model;
private slots:
    void lukmanEdit_add_PushButtonSlot();
    void lukmanEdit_delete_PushButtonSlot();
    void lukmanEdit_update_PushButtonSlot();
    void lukmanEdit_clear_PushButtonSlot();
    void lukmanEdit_back_PushButtonSlot();
    void lukmanEdit_type_PushButtonSlot();
    void lukmanEdit_id_LineEditSlot();

    /*------------------------------------------------------------------------
     *                                hunar edit                            //
     *----------------------------------------------------------------------*/
public:
    void hunarEdit_tableRefresh();
    void hunarEdit_clearLineEdit();
private:
    QWidget *hunarEdit;

    QLabel *hunarEdit_id_Label;
    QLabel *hunarEdit_name_Label;

    QLineEdit *hunarEdit_id_LineEdit;
    QLineEdit *hunarEdit_name_LineEdit;

    QPushButton *hunarEdit_add_PushButton;
    QPushButton *hunarEdit_delete_PushButton;
    QPushButton *hunarEdit_update_PushButton;
    QPushButton *hunarEdit_clear_PushButton;
    QPushButton *hunarEdit_back_PushButton;

    QTableView *hunarEdit_view;
    QSqlQueryModel *hunarEdit_model;

    QVBoxLayout *hunarEdit_vb_VBoxLayout;
    QHBoxLayout *hunarEdit_hb_VBoxLayout;
    QGridLayout *hunarEdit_gb_GridLayout;

private slots:
    void hunarEdit_add_PushButtonSlot();
    void hunarEdit_delete_PushButtonSlot();
    void hunarEdit_update_PushButtonSlot();
    void hunarEdit_clear_PushButtonSlot();
    void hunarEdit_back_PushButtonSlot();
    void hunarEdit_id_LineEditSlot();
};

#endif // HASSA_H
