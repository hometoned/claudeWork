/************************************************************
* 启动画面
* 版本1.0
************************************************************/
#pragma once

#include <QtWidgets/QSplashScreen>

#include <UI/UI_global.h>

namespace UI
{
	/*!
	* 类名：SplashScreen
	* 启动画面
	*/
	class SplashScreen : public QSplashScreen
	{
	public:
		/*!
		* 函数名：SplashScreen(const QPixmap& pixmap = QPixmap(), Qt::WindowFlags f = Qt::WindowFlags())
		* 构造函数，生成启动画面
		* param [in] pixmap 画面对象
		* param [in] f 窗口模式
		* return 无
		*/
		SplashScreen(const QPixmap& pixmap = QPixmap(), Qt::WindowFlags f = Qt::WindowFlags());

		/*!
		* 函数名：~SplashScreen()
		* 默认的析构函数
		* param 无
		* return 无
		*/
		~SplashScreen();

		/*!
		* 函数名：void ShowMessage(const QString& qstrMessage)
		* 显示信息
		* param [in] qstrMessage 要显示的信息
		* return void
		*/
		void ShowMessage(const QString& qstrMessage);
	};
}
