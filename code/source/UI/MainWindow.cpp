#include <UI/MainWindow.h>
#include <UI/PluginManager.h>

#include <QCoreApplication>
#include <QDateTime>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QHBoxLayout>

#include <vector>

#include <Scene/Base.h>

using namespace UI;

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QMainWindow(parent, flags)
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //flags = windowFlags() | Qt::FramelessWindowHint;
    setWindowFlags(flags);
    QString str = QStringLiteral("OPenGL demo");
    setWindowTitle(str);

    std::string strAppPath = QCoreApplication::applicationDirPath().toStdString();
    Scene::Base::Instance()->SetAppPath(strAppPath);

    Init();
}

MainWindow::~MainWindow()
{
    PluginManager::Instance()->UnLoadPlugins();
    m_pSplashScreen = nullptr;
}

void MainWindow::Init()
{
    InitSplash();

    m_pSceneWidget = new SceneWidget(this);
    if (m_pSceneWidget == nullptr)
    {
        //LOG("SceneWidget create failed.");
    }
    setCentralWidget(m_pSceneWidget);
    InitLeftWidget();
    m_pStatusBar = new StatusBar(this);
    setStatusBar(m_pStatusBar);
}

void MainWindow::ShowWindow()
{
    showMaximized();
    InitScene();
    InitPlugins();
    m_pSplashScreen->finish(this);
}

void MainWindow::ShowLeftWidget()
{
    
}

void MainWindow::InitSplash()
{
    QString strAppPath = QCoreApplication::applicationDirPath();
    QPixmap pixmap(strAppPath + QString("/data/images/splash.png"));
    if (m_pSplashScreen == nullptr)
    {
        m_pSplashScreen = new SplashScreen(pixmap);
        if (m_pSplashScreen == nullptr)
        {
            //LOG("SplashScreen create failed.");
            return;
        }
    }
    m_pSplashScreen->show();

}

void MainWindow::InitScene()
{
    m_pSplashScreen->ShowMessage(QString(QStringLiteral("Begin init scene.")));
    //m_pSceneWidget->Init();
    m_pSplashScreen->ShowMessage(QString(QStringLiteral("End init scene."))); 
}

void MainWindow::InitPlugins()
{
    PluginManager::Instance()->LoadPluins(m_pSplashScreen);
}

void MainWindow::InitLeftWidget()
{
}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
    
}
