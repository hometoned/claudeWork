#if defined(LINUX)
    #pragma execution_character_set("utf-8")
#endif
#if defined(WINDOWS)
    #include <windows.h>
#endif
#include <UI/Application.h>
#include <UI/MainWindow.h>

#include <QtCore/QProcess>

using namespace UI;

Application::Application(int& argc, char** argv) :
    QApplication(argc, argv)
{
    QString qstrAppPath = applicationDirPath();

#if defined(LINUX)
    QProcess process;
    process.start("hidepanel.sh");
    process.waitForFinished();
    process.terminate();
#endif
}

Application::~Application()
{
#if defined(LINUX)
    QProcess process;
    process.start("showpanel.sh");
    process.waitForFinished();
    process.terminate();
#endif

}

int Application::Run()
{
    MainWindow m;
    m.ShowWindow();
    return exec();
}
