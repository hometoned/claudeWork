/*!
* 程序的主窗口。
* 版本 1.0
*/
#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTreeWidget>

#include <QtCore/QMap>

#include <UI/MainWindow.h>
#include <UI/SceneWidget.h>
#include <UI/UI_global.h>
#include <UI/SplashScreen.h>
#include <UI/StatusBar.h>

namespace UI
{
    /*!
    * 类名：MainWindow
    * 主窗口，包含菜单栏、工具栏、停靠栏和状态栏
    */
    class UI_EXPORT MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        /*!
        * 函数名：MainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
        * 参数为父类所需要的，且都有默认值
        * param [in] parent 父对象指针
        * param [in] flags 窗口样式，保持默认
        * return 无
        */
        MainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

        /*!
        * 函数名：~MainWindow()
        * 默认的析构函数
        * return 无
        */
        ~MainWindow();

        /*!
        * 函数名：void Init()
        * 初始化窗口，包含主窗口、三维场景、启动画面和插件
        * param 无
        * return void
        */
        void Init();

        /*!
        * 函数名：void ShowWindow()
        * 显示主窗口
        * param 无
        * return void
        */
        void ShowWindow();

        /*!
        * 函数名：void ShowLeftWidget()
        * 显示主窗口左侧的树形列表
        * param 无
        * return void
        */
        void ShowLeftWidget();

    protected:
        /*!
        * 函数名：void InitSplash()
        * 初始化启动画面。
        * param 无
        * return void
        */
        void InitSplash();

        /*!
        * 函数名：void InitScene()
        * 初始化三维场景。
        * param 无
        * return void
        */
        void InitScene();

        /*!
        * 函数名：void InitPlugins()
        * 初始化插件。
        * param 无
        * return void
        */
        void InitPlugins();

        /*!
        * 函数名：void InitLeftWidget()
        * 初始化左侧列表
        * param 无
        * return void
        */
        void InitLeftWidget();

    public:

    protected:

    protected slots:

        protected:
             virtual void MainWindow::keyPressEvent(QKeyEvent* event);
    private:
        /*!
        * 三维窗口指针
        */
        SceneWidget *m_pSceneWidget = nullptr;

        /*!
        * 启动画面指针
        */
        SplashScreen* m_pSplashScreen = nullptr;

        /*!
        * 状态栏指针
        */
        StatusBar* m_pStatusBar = nullptr;

    };
}

#endif //UI_APPLICATION_H
