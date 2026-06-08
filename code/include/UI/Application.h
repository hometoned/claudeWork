/************************
* 创建Applicatin
* 一个应用程序有且只有一个
* 版本 1.0
*************************/
#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtWidgets/QApplication>

#include <UI/UI_global.h>

namespace UI
{
    /*!
    * 类名：Application
    * 继承于QApplication
    */
    class UI_EXPORT Application : public QApplication
    {
    public:
        /*!
        * 类名：Application(int& argc, char** argv)
        * 构造函数，参数来自于main函数。
        * param argc [in] 参数个数，默认为1
        * param argv [in] 默认为程序的完整路径名
        * return 无
        */
        Application(int& argc, char** argv);

        /*!
        * ~Application()
        * 默认的析构函数
        * return 无
        */
        ~Application();

        /*!
        * int Run()
        * 运行程序。
        * param 无
        * return 程序的执行结果，如果正常退出为0，否则为错误码
        */
        int Run();
    };
}

#endif //UI_APPLICATION_H
