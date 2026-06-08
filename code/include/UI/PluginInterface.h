/******************************************************************
* Qt插件的插件的接口类。
* 定义插件的主要接口，具体实现由子类实现
* 版本1.0
******************************************************************/
#pragma once

#include <QtGui/QKeyEvent>

#include <UI/UI_global.h>

#define PluginInterface_IID "Plugins.PluginInterface"

namespace UI
{
	/*!
	* 类名：PluginInterface
	* 定义插件的接口
	*/
	class UI_EXPORT PluginInterface : public QObject
	{
	public:
		/*!
	    * 类名：PluginInterface(QObject* pParent = nullptr)
	    * 构造函数
		* param [in] pParent父对象指针，默认为nullptr
		* return 无
	    */
		PluginInterface(QObject* pParent = nullptr);

		/*!
		* 类名：virtual ~PluginInterface()
		* 虚函数，默认析构函数
		* param 无
		* return 无
		*/
		virtual ~PluginInterface();

		/*!
		* 类名：virtual bool Instanll()
		* 虚函数，安装插件函数
		* param 无
		* return bool true表示安装成功，false表示失败
		*/
		virtual bool Instanll();

		/*!
		* 类名：virtual bool Instanll()
		* 虚函数，卸载插件函数
		* param 无
		* return bool true表示卸载成功，false表示失败
		*/
		virtual bool UnInstanll();

		/*!
		* 类名：virtual bool Instanll()
		* 虚函数，查询插件是否已安装
		* param 无
		* return bool true表示已安装，false表示未安装
		*/
		virtual bool IsInstall();

		/*!
		* 类名：virtual void keyPressEvent(QKeyEvent* event)
		* 虚函数，插件的键盘按键事件处理
		* param [in] event 键盘事件
		* return void
		*/
		virtual void keyPressEvent(QKeyEvent* event);

		/*!
		* 类名：virtual void keyReleaseEvent(QKeyEvent* event)
		* 虚函数，插件的键盘按键弹起事件处理
		* param [in] event 键盘事件
		* return void
		*/
		virtual void keyReleaseEvent(QKeyEvent* event);

		/*!
		* 类名：virtual void mouseDoubleClickEvent(QMouseEvent* event)
		* 虚函数，插件鼠标的双击事件处理
		* param [in] event 鼠标事件
		* return void
		*/
		virtual void mouseDoubleClickEvent(QMouseEvent* event);

		/*!
		* 类名：virtual void mouseMoveEvent(QMouseEvent* event)
		* 虚函数，插件鼠标的移动事件处理
		* param [in] event 鼠标事件
		* return void
		*/
		virtual void mouseMoveEvent(QMouseEvent* event);

		/*!
		* 类名：virtual void mousePressEvent(QMouseEvent* event)
		* 虚函数，插件鼠标的按键事件处理
		* param [in] event 鼠标事件
		* return void
		*/
		virtual void mousePressEvent(QMouseEvent* event);

		/*!
		* 类名：virtual void mouseReleaseEvent(QMouseEvent* event)
		* 虚函数，插件鼠标的按键弹起事件处理
		* param [in] event 鼠标事件
		* return void
		*/
		virtual void mouseReleaseEvent(QMouseEvent* event);

		/*!
		* 类名：virtual void moveEvent(QMoveEvent* event)
		* 虚函数，插件处理主窗口的移动事件
		* param [in] event 移动事件
		* return void
		*/
		virtual void moveEvent(QMoveEvent* event);

		/*!
		* 类名：virtual voidresizeEvent(QResizeEvent* event)
		* 虚函数，插件处理主窗口的尺寸变化事件
		* param [in] event 尺寸变化事件
		* return void
		*/
		virtual void resizeEvent(QResizeEvent* event);

		/*!
		* 类名：virtual void ShowFullScreen(bool bFullScreen)
		* 虚函数，插件主窗口是否全屏
		* param [in] bFullScreen true全屏,false非全屏
		* return void
		*/
		virtual void ShowFullScreen(bool bFullScreen);

	protected:
		/*!
		* 是否安装的标记
		*/
		bool m_bInstanll = false;
	};
}

/*!
* Qt插件的固定写法
*/
Q_DECLARE_INTERFACE(UI::PluginInterface, PluginInterface_IID)