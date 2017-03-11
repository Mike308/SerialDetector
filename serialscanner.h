#include <QObject>

#ifndef SERIALSCANNER_H
#define SERIALSCANNER_H



class SerialScanner : public QObject
{
    Q_OBJECT
public:
    explicit SerialScanner(QObject *parent = 0);

private:

    QSerialPortInfo * serialPortInfo;

    QList<QString> updateCOMList();
    QList<QString> currentCOMList;
    QList<QString> startedCOMList;


signals:
    void scannConnected(QSet<QString> coms);



public slots:
    void scannSerialPorts();
};

#endif // SERIALSCANNER_H
