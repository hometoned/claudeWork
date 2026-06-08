#include <UI/PluginManager.h>
#include <UI/PluginInterface.h>

#include <QtCore/QDir>
#include <QtCore/QPluginLoader>
#include <QCoreApplication>

using namespace UI;

PluginManager* PluginManager::Instance()
{
	static PluginManager pm;
	return &pm;
}

void PluginManager::LoadPluins(SplashScreen* pSplashScree)
{
	pSplashScree->ShowMessage("Begin load plugins.");
	QString strAppPath = QCoreApplication::applicationDirPath();
	strAppPath += "/Plugins/";
	QDir dir = strAppPath;
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
	QStringList qstrList = dir.entryList();
	QString qstrAppPath = strAppPath;
	QPluginLoader loader;
	for (QString& str : qstrList)
	{
		QString strFilePath = qstrAppPath + str;
		loader.setFileName(strFilePath);
		if (loader.load())
		{
			QObject* plugin = loader.instance();
			PluginInterface* pInterface = dynamic_cast<PluginInterface*>(plugin);
			if (pInterface == nullptr)
			{
				//LOG(str.toStdString() + " dynamic_cast return null.");
				continue;
			}
			pSplashScree->ShowMessage(QString(QStringLiteral("Begin install ") + str));
			if (!pInterface->Instanll())
			{
				//LOG(str.toStdString() + " install failed.");
				continue;
			}
			m_listPlugins.push_back(pInterface);
		}
		else
		{
			//LOG(loader.errorString().toStdString() + " load failed.");
		}
	}
	pSplashScree->ShowMessage("End load plugins.");
}

void PluginManager::UnLoadPlugins()
{
	for (PluginInterface* pInterface : m_listPlugins)
	{
		pInterface->UnInstanll();
	}
}

void PluginManager::ShowFullScreen(bool bFullScreen)
{
	for (PluginInterface* pInterface : m_listPlugins)
	{
		pInterface->ShowFullScreen(bFullScreen);
	}
}

void PluginManager::KeyPressEvent(QKeyEvent* event)
{
	for (PluginInterface* pInterface : m_listPlugins)
	{
		pInterface->keyPressEvent(event);
	}
}

PluginManager::PluginManager()
{
}

PluginManager::~PluginManager()
{
}