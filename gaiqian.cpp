#include "gaiqian.h"
#include "ui_gaiqian.h"

#include "gaiqian.h"

customer_GaiQian::customer_GaiQian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customer_GaiQian)
{
    ui->setupUi(this);
    ui->lineEditChu->setPlaceholderText("出发地");
    ui->lineEditDao->setPlaceholderText("到达地");
    setFixedSize(1061,611);
    setWindowTitle("改签");

    has_validTickets=true;

    QPixmap pixmap(":/img/bgground2.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    setAutoFillBackground(true);

    ui->titleLabel->setStyleSheet("color:black;");

    connect(ui->searchButton,&QPushButton::clicked,ui->dateEdit,[=]{
        if(ui->dateEdit->date()<=today){
            ui->userOrderTable->setRowCount(0);
            QMessageBox::warning(this,"警告","更早日期无航班");
            return;
        }
        current_order.date=ui->dateEdit->text();
        showDatabase();
    });

    connect(ui->backwardButton,&QPushButton::clicked,this,[=]{
        this->close();
    });
}

customer_GaiQian::~customer_GaiQian()
{
    delete ui;
}

void customer_GaiQian::receiveOrder(const Order order,const QSqlDatabase &dbcon){
    current_order=order;
    current_order.printOrder();
    this->dbcon=dbcon;

    ui->lineEditChu->setText(current_order.departCityName);
    ui->lineEditDao->setText(current_order.arriveCityName);
    ui->lineEditChu->setReadOnly(true);
    ui->lineEditDao->setReadOnly(true);

    // date=QDate::fromString(current_order.date,"yyyy-MM-dd");
    today = QDate::currentDate();
    // date=date.addDays(1);
    ui->dateEdit->setDate(QDate::fromString(current_order.date,"yyyy-MM-dd"));

    origin_date=current_order.date;

    // current_order.date=today.toString("yyyy-MM-dd");

    showDatabase();
}

//改签列表显示
void customer_GaiQian::showDatabase(){
    has_validTickets=true;

    ui->userOrderTable->setSortingEnabled(false);
    ui->userOrderTable->clear();
    ui->userOrderTable->setRowCount(0);
    ui->userOrderTable->setColumnCount(0);

    QString depart=current_order.departCityName;
    QString arrive=current_order.arriveCityName;
    QStringList date=current_order.date.split("-");
    //QString flightNo=current_order.flightNo;

    QSqlQuery query(dbcon);
    QString sql=QString("select flightNo,departTime,arriveTime,onTimeRate "
                          "from flight_db.flight "
                          "where departCityName = '%1' and arriveCityName = '%2'").arg(depart).arg(arrive);
    query.prepare(sql);

    QVector<QString> flights;
    QVector<QString> departTimes;
    QVector<QString> arriveTimes;
    QVector<QString> onTimeRates;
    if(query.exec()){
        while(query.next()){
            flights.push_back(query.value("flightNo").toString());
            departTimes.push_back(query.value("departTime").toString().left(8));
            arriveTimes.push_back(query.value("arriveTime").toString().left(8));
            onTimeRates.push_back(query.value("onTimeRate").toString().left(8));
        }
    }else{
        qDebug()<<"error in customer_Gaiqian::showDatabase";
    }

    int rowCount=0;

    int columnCount = 11;
    ui->userOrderTable->setColumnCount(columnCount);

    // 设置表头
    QStringList headers;
    headers << "航班号" << "出发时间" << "到达时间" << "正点率"
            << "经济舱余票" << "经济舱票价" << "商务舱余票" << "商务舱票价" << "头等舱余票" << "头等舱票价" << "操作";

    for (int i = 0; i < headers.size(); ++i) {
        ui->userOrderTable->setHorizontalHeaderItem(i, new QTableWidgetItem(headers.at(i)));
    }

    for(int i=0;i<flights.size();i++){
        QString flight=flights[i];
        sql=QString("select * from schedule"
                      +date[0]+date[1]+date[2]+" where flightNo = '%1'").arg(flight);
        query.prepare(sql);
        if(query.exec()){
            if(query.next()){
                //qDebug()<<query.value(0)<<query.value(1)<<query.value(2)<<query.value(3)<<query.value(4);
                if(query.value(0)!=NULL){
                    if(query.value("flightNo").toString()==current_order.flightNo){
                        current_eco=query.value("eco_seat").toInt();
                        current_bus=query.value("bus_seat").toInt();
                        current_pri=query.value("pri_seat").toInt();
                    }

                    qDebug()<<"row:"<<rowCount;
                    ui->userOrderTable->insertRow(rowCount);
                    ui->userOrderTable->setItem(rowCount,0,new QTableWidgetItem(query.value("flightNo").toString()));
                    ui->userOrderTable->setItem(rowCount,1,new QTableWidgetItem(departTimes[i]));
                    ui->userOrderTable->setItem(rowCount,2,new QTableWidgetItem(arriveTimes[i]));
                    ui->userOrderTable->setItem(rowCount,3,new QTableWidgetItem(onTimeRates[i]));

                    ui->userOrderTable->setItem(rowCount,4,new QTableWidgetItem(query.value("eco_seat").toString()));
                    ui->userOrderTable->setItem(rowCount,5,new QTableWidgetItem());
                    double eco_price=query.value("price").toDouble();
                    ui->userOrderTable->item(rowCount,5)->setData(Qt::DisplayRole,eco_price);

                    ui->userOrderTable->setItem(rowCount,6,new QTableWidgetItem(query.value("bus_seat").toString()));
                    ui->userOrderTable->setItem(rowCount,7,new QTableWidgetItem());
                    double bus_price=query.value("price").toDouble()*2.0;
                    ui->userOrderTable->item(rowCount,7)->setData(Qt::DisplayRole,bus_price);

                    ui->userOrderTable->setItem(rowCount,8,new QTableWidgetItem(query.value("pri_seat").toString()));
                    ui->userOrderTable->setItem(rowCount,9,new QTableWidgetItem());
                    double pri_price=query.value("price").toDouble()*4.0;
                    ui->userOrderTable->item(rowCount,9)->setData(Qt::DisplayRole,pri_price);

                    //qDebug()<<origin_date<<query.value("date").toString();
                    QPushButton *eco_select = new QPushButton("改签经济舱");
                    eco_select->setMinimumWidth(100);
                    if(current_order.flightNo==query.value("flightNo").toString()&&current_order.eco==1&&origin_date==current_order.date){
                        eco_select->setDisabled(true);
                    }
                    QPushButton *bus_select = new QPushButton("改签商务舱");
                    bus_select->setMinimumWidth(100);
                    if(current_order.flightNo==query.value("flightNo").toString()&&current_order.bus==1&&origin_date==current_order.date){
                        bus_select->setDisabled(true);
                    }
                    QPushButton *pri_select = new QPushButton("改签头等舱");
                    pri_select->setMinimumWidth(100);
                    if(current_order.flightNo==query.value("flightNo").toString()&&current_order.pri==1&&origin_date==current_order.date){
                        pri_select->setDisabled(true);
                    }

                    QHBoxLayout *buttonLayout = new QHBoxLayout();
                    buttonLayout->addWidget(eco_select);
                    buttonLayout->addWidget(bus_select);
                    buttonLayout->addWidget(pri_select);
                    buttonLayout->setContentsMargins(0, 0, 0, 0);
                    buttonLayout->setSpacing(5);

                    QWidget *widget = new QWidget();
                    widget->setLayout(buttonLayout);

                    ui->userOrderTable->setCellWidget(rowCount, 10, widget);
                    ui->userOrderTable->resizeColumnToContents(10);

                    connect(eco_select,&QPushButton::clicked,[=]{
                        QMessageBox message;
                        message.setWindowTitle("改签确认");
                        message.setIcon(QMessageBox::Question);
                        message.setText("确认改签该班次经济舱吗？");
                        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                        if(message.exec()==QMessageBox::Ok){
                            int remain_eco=ui->userOrderTable->item(rowCount,4)->text().toInt()-1;
                            int remain_bus=ui->userOrderTable->item(rowCount,6)->text().toInt();
                            int remain_pri=ui->userOrderTable->item(rowCount,8)->text().toInt();

                            qDebug()<<"remain eco:"<<remain_eco;

                            if(remain_eco<0){
                                QMessageBox::critical(this, "Error", "经济舱余票不足，请选择其他班次或票型");
                                return;
                            }

                            qDebug()<<"改签"<< ui->userOrderTable->item(rowCount,0)->text() <<"经济舱";

                            // 创建新订单
                            Order newOrder = current_order;
                            newOrder.order_ID = 0;  // 新订单的订单号由数据库自动生成
                            newOrder.status = 1;  // 新订单的状态为“正常”
                            newOrder.eco=1;
                            newOrder.bus=0;
                            newOrder.pri=0;
                            newOrder.flightNo=ui->userOrderTable->item(rowCount,0)->text();
                            newOrder.date=ui->dateEdit->text();
                            newOrder.price=ui->userOrderTable->item(rowCount,5)->text().toDouble();

                            refreshDatabaseFromNewOrder(rowCount,remain_eco,remain_bus,remain_pri,date,newOrder);

                            this->close();
                        }else{
                            qDebug()<<"用户取消改签操作";
                        }
                    });

                    connect(bus_select,&QPushButton::clicked,[=]{
                        QMessageBox message;
                        message.setWindowTitle("改签确认");
                        message.setIcon(QMessageBox::Question);
                        message.setText("确认改签该班次商务舱吗？");
                        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                        if(message.exec()==QMessageBox::Ok){
                            int remain_eco=ui->userOrderTable->item(rowCount,4)->text().toInt();
                            int remain_bus=ui->userOrderTable->item(rowCount,6)->text().toInt()-1;
                            int remain_pri=ui->userOrderTable->item(rowCount,8)->text().toInt();
                            if(remain_bus<0){
                                QMessageBox::critical(this, "Error", "商务舱余票不足，请选择其他班次或票型");
                                return;
                            }

                            qDebug()<<"改签"<< ui->userOrderTable->item(rowCount,0)->text() <<"商务舱";

                            // 创建新订单
                            Order newOrder = current_order;
                            newOrder.order_ID = 0;  // 新订单的订单号由数据库自动生成
                            newOrder.status = 1;  // 新订单的状态为“正常”
                            newOrder.eco=0;
                            newOrder.bus=1;
                            newOrder.pri=0;
                            newOrder.flightNo=ui->userOrderTable->item(rowCount,0)->text();
                            newOrder.date=ui->dateEdit->text();
                            newOrder.price=ui->userOrderTable->item(rowCount,7)->text().toDouble();

                            refreshDatabaseFromNewOrder(rowCount,remain_eco,remain_bus,remain_pri,date,newOrder);

                            this->close();
                        }else{
                            qDebug()<<"用户取消改签操作";
                        }
                    });

                    connect(pri_select,&QPushButton::clicked,[=]{
                        QMessageBox message;
                        message.setWindowTitle("改签确认");
                        message.setIcon(QMessageBox::Question);
                        message.setText("确认改签该班次头等舱吗？");
                        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                        if(message.exec()==QMessageBox::Ok){
                            int remain_eco=ui->userOrderTable->item(rowCount,4)->text().toInt();
                            int remain_bus=ui->userOrderTable->item(rowCount,6)->text().toInt();
                            int remain_pri=ui->userOrderTable->item(rowCount,8)->text().toInt()-1;

                            qDebug()<<"remain pri:"<<remain_pri;

                            if(remain_pri<0){
                                QMessageBox::critical(this, "Error", "头等舱余票不足，请选择其他班次或票型");
                                return;
                            }

                            qDebug()<<"改签"<< ui->userOrderTable->item(rowCount,0)->text() <<"头等舱";

                            // 创建新订单
                            Order newOrder = current_order;
                            newOrder.order_ID = 0;  // 新订单的订单号由数据库自动生成
                            newOrder.status = 1;  // 新订单的状态为“正常”
                            newOrder.eco=0;
                            newOrder.bus=0;
                            newOrder.pri=1;
                            newOrder.flightNo=ui->userOrderTable->item(rowCount,0)->text();
                            newOrder.date=ui->dateEdit->text();
                            newOrder.price=ui->userOrderTable->item(rowCount,9)->text().toDouble();

                            refreshDatabaseFromNewOrder(rowCount,remain_eco,remain_bus,remain_pri,date,newOrder);

                            this->close();
                        }else{
                            qDebug()<<"用户取消改签操作";
                        }
                    });

                    ++rowCount;
                }else{
                    QMessageBox::information(this,"Sorry","当日无票");
                }
            }

        }else{
            has_validTickets=false;
            qDebug() << "Query failed";
        }
    }

    //表格排序
    ui->userOrderTable->setSortingEnabled(true);
    //connect(ui->userOrderTable->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(onSortByColumn(int)));

    if(!has_validTickets){
        QMessageBox::information(this,"Sorry","当日无可改签的航班");
    }
}

void customer_GaiQian::closeEvent(QCloseEvent *event)
{
    emit customer_gaiqian_closed();
    event->accept();
}

/*
void customer_GaiQian::onSortByColumn(int col)
{
    //qDebug()<<"click";
    Qt::SortOrder order = m_sortAsc ? Qt::AscendingOrder : Qt::DescendingOrder;
    ui->userOrderTable->sortItems(col, order);
    //m_sortAsc = !m_sortAsc;

    if (m_lastSortedColumn == col) {
        m_sortAsc = !m_sortAsc; // 切换排序顺序
    } else {
        m_sortAsc = true; // 如果是新的列，设置为升序
    }
    m_lastSortedColumn = col; // 更新最后一次排序的列

    qDebug()<<m_sortAsc;
}
*/

//刷新表格
void customer_GaiQian::refreshDatabaseFromNewOrder(int rowCount, int remain_eco, int remain_bus, int remain_pri, QStringList date, Order newOrder){
    // 更新原订单的状态为“改签”
    if (!openDatabase::updateStatusInDatabase(current_order.order_ID, 2)) {
        qDebug()<<"Failed to update the status in the database.";
        return;
    }

    // 插入新订单到数据库
    if (!openDatabase::insertNewOrderIntoDatabase(newOrder)) {
        qDebug()<<"Failed to insert the new order into the database.";
        return;
    }

    //更新数据库余票
    QStringList formatted_date=newOrder.date.split("-");
    openDatabase::updateTicketInDatabase(formatted_date[0]+formatted_date[1]+formatted_date[2],remain_eco,remain_bus,remain_pri,newOrder);//新选择航班的票数-1

    if(current_order.eco){
        current_eco++;
    }else if(current_order.bus){
        current_bus++;
    }else{
        current_pri++;
    }
    openDatabase::updateTicketInDatabase(date[0]+date[1]+date[2],current_eco,current_bus,current_pri,current_order);//原来航班的票数+1

    double money=newOrder.price-current_order.price+current_order.price*0.1;
    if(money>0){
        QString message="改签成功，收取您原来票价10%的手续费，您需支付差价"+QString::number(money)+"元";
        QMessageBox::information(this,"Success",message);
    }else if(money==0){
        QMessageBox::information(this,"Success","改签成功，收取您10%的手续费");
    }else{
        QString message="改签成功，收取您原来票价10%的手续费，退还您差价"+QString::number(-money)+"元";
        QMessageBox::information(this,"Success",message);
    }

}
