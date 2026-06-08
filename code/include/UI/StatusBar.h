/**************************************************************
* 状态栏
* 版本1.0
***************************************************************/
#pragma once

#include <QtWidgets/QStatusBar>

#include <QtGui/QMouseEvent>

namespace UI
{
	/*!
	* 类名：StatusBar
	* 生成状态栏
	*/
	class StatusBar : public QStatusBar
	{
	public:
		/*!
	    * 函数名：StatusBar(QWidget* pParent = nullptr)
	    * 构造函数
		* param [in] pParent父对象指针
		* return 无
	    */
		StatusBar(QWidget* pParent = nullptr);

		/*!
		* 函数名：~StatusBar()
		* 默认的析构函数
		* param 无
		* return 无
		*/
		~StatusBar();

	protected:
		/*!
		* 函数名：virtual void mouseMoveEvent(QMouseEvent* event)
		* 虚函数，鼠标的移动事件处理
		* param [in] event 鼠标事件
		* return void
		*/
		virtual void mouseMoveEvent(QMouseEvent* event);
	private:

	};
}