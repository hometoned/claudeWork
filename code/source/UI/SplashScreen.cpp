#include <UI/SplashScreen.h>

using namespace UI;

SplashScreen::SplashScreen(const QPixmap& pixmap, Qt::WindowFlags f) :
	QSplashScreen(pixmap, f)
{
	//
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::ShowMessage(const QString& qstrMessage)
{
	showMessage(qstrMessage);
}