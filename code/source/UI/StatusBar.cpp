#include <UI/StatusBar.h>

#include <UI/MainWindow.h>

using namespace UI;

StatusBar::StatusBar(QWidget* pParent) :
	QStatusBar(pParent)
{
	setMouseTracking(true);
	setFocusPolicy(Qt::StrongFocus);
	//setFocus();
}

StatusBar::~StatusBar()
{
}

void StatusBar::mouseMoveEvent(QMouseEvent* event)
{
	//long long id = Base::Global::Instance()->GetMainWindow();
	//QWidget* pWidget = QWidget::find(WId(id));
	//MainWindow* pMainWindow = static_cast<MainWindow*>(pWidget);
	//pMainWindow->SetLonLatHeiValue("-", "-", "-");
}