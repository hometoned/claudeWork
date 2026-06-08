/****************************************
* 插件的管理类
* 版本1.0
****************************************/
#pragma once

#include <UI/SplashScreen.h>
#include <UI/PluginInterface.h>

#include <QtCore/QList>

namespace UI
{
	/*!
	* 类名：PluginManager
	* 单例类，管理插件
	*/
	class PluginManager
	{
	public:
		/*!
		* 函数名：static PluginManager* Instance()
		* 生成或获取类的单例对象指针
		* param 无
		* return static PluginManager* 静态类对象指针
		*/
		static PluginManager* Instance();

		/*!
		* 函数名：void LoadPluins(SplashScreen* pSplashScree)
		* 加载指定目录下的插件，并在启动画面上显示系统当前的操作
		* param [in] pSplashScree 启动画面指针
		* return void
		*/
		void LoadPluins(SplashScreen* pSplashScree);

		/*!
		* 函数名：void UnLoadPlugins(SplashScreen* pSplashScree)
		* 卸载指定目录下的插件，并在启动画面上显示系统当前的操作
		* param [in] pSplashScree 启动画面指针
		* return void
		*/
		void UnLoadPlugins();

		/*!
		* 函数名：void ShowFullScreen(bool bFullScreen)
		* 将是否全屏显示传递给所有已安装的插件
		* param [in] bFullScreen true 全屏显示，false 非全屏显示
		* return void
		*/
		void ShowFullScreen(bool bFullScreen);

		/*!
		* 函数名：void KeyPressEvent(QKeyEvent* event)
		* 将是否按键事件向插件传递
		* param [in] event 按键事件
		* return void
		*/
		void KeyPressEvent(QKeyEvent* event);
	protected:

		/*!
		* 函数名：PluginManager()
		* 默认构造函数
		* return 无
		*/
		PluginManager();

		/*!
		* 函数名：~PluginManager()
		* 默认析构函数
		* return 无
		*/
		~PluginManager();
	private:
		/*!
		* 插件列表
		*/
		QList<PluginInterface*> m_listPlugins;
	};
}