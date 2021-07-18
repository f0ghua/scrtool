#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Task parented to the application so that it
    // will be deleted by the application.
    Task *task = new Task(&a);

    // This will cause the application to exit when
    // the task signals finished.
    QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));

    // This will run the task from the application event loop.
    QTimer::singleShot(0, task, SLOT(run()));

    return a.exec();
}

void Task::run()
{
    // Do processing here
    // prevent from command console popup
    FreeConsole();
    ULONG_PTR m_gdiplusToken;   // class member
    // InitInstance
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
    PrScrn();
    // ExitInstance
    Gdiplus::GdiplusShutdown(m_gdiplusToken);

    QStringList args = QCoreApplication::arguments();
    if (args.count() > 1) {
        const QString filePath = QCoreApplication::arguments().at(1);
        saveClipboardImage(filePath);
    }

    emit finished();
}
