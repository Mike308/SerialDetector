#include "serialscanner.h"
#include <QSerialPortInfo>


SerialScanner::SerialScanner(QObject *parent) : QObject(parent)
{

}

QList<QString> SerialScanner::updateCOMList(){

   serialPortInfo = new QSerialPortInfo();

   QList<QSerialPortInfo> comList = serialPortInfo->availablePorts();
   QList<QString> comNames;

   foreach (QSerialPortInfo items, comList) {

       comNames.append(items.portName());

   }

   serialPortInfo->~QSerialPortInfo();

   return comNames;


}



