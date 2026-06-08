#include <UI/PluginInterface.h>

using namespace UI;

PluginInterface::PluginInterface(QObject* pParent) :
	QObject(pParent)
{
}

PluginInterface::~PluginInterface()
{
}

bool PluginInterface::Instanll()
{
	m_bInstanll = true;
	return m_bInstanll;
}

bool PluginInterface::UnInstanll()
{
	m_bInstanll = false;
	return !m_bInstanll;
}

bool PluginInterface::IsInstall()
{
	return m_bInstanll;
}

void PluginInterface::keyPressEvent(QKeyEvent* event)
{

}

void PluginInterface::keyReleaseEvent(QKeyEvent* event)
{

}

void PluginInterface::mouseDoubleClickEvent(QMouseEvent* event)
{

}

void PluginInterface::mouseMoveEvent(QMouseEvent* event)
{

}

void PluginInterface::mousePressEvent(QMouseEvent* event)
{

}

void PluginInterface::mouseReleaseEvent(QMouseEvent* event)
{

}

void PluginInterface::moveEvent(QMoveEvent* event)
{

}

void PluginInterface::resizeEvent(QResizeEvent* event)
{

}

void PluginInterface::ShowFullScreen(bool bFullScreen)
{

}