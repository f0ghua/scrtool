#ifndef MAIN_H
#define MAIN_H

#include <QString>
#include <QClipboard>
#include <QApplication>
#include <QtCore>
#include <QImage>

#ifdef __cplusplus
extern "C"{
#endif

void PrScrn();

#ifdef __cplusplus
}
#endif

#include <windows.h>
#include <gdiplus.h>

using namespace std;

class Task : public QObject
{
    Q_OBJECT
public:
    Task(QObject *parent = 0) : QObject(parent) {}

public slots:
    void run();

signals:
    void finished();

private:
    void saveClipboardImage(QString path)
    {
       const QClipboard *cb = QApplication::clipboard();
       QImage img(cb->image());
       img.save(path);
    }
};

#endif // MAIN_H
