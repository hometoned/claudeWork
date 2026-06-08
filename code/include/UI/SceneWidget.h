/*************************************************************
* ��ά�����࣬������ά����
* �汾1.0
**************************************************************/
#ifndef UI_SCENEWIDGET_H
#define UI_SCENEWIDGET_H

#include <QtCore/QTimer>
#include <QtCore/QString>
#include <QtCore/QElapsedTimer>

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

#include <QtWidgets/QOpenGLWidget>

#include <Scene/Viewer.h>
#include <Scene/Camera.h>
#include <Scene/Box.h>

namespace UI
{
	/*!
	* ������SceneWidget
	* ��ά����
	*/
	class SceneWidget : public QOpenGLWidget//, protected QOpenGLFunctions
	{
		Q_OBJECT
	public:
		/*!
		* ��������SceneWidget(QWidget* pParent = nullptr)
		* ���캯��
		* param [in] pParent ������ָ��
		* return ��
		*/
		SceneWidget(QWidget* pParent = nullptr);

		/*!
		* ��������~SceneWidget()
		* ��������
		* param ��
		* return ��
		*/
		~SceneWidget();

	protected slots:
		/*!
		* ��������void Update()
		* ���´���
		* param ��
		* return void
		*/
		void Update();

	protected:

		/*!
		* ��������virtual void mouseMoveEvent(QMouseEvent* event)
		* �麯��������ƶ��¼�����
		* param [in] event ����¼�
		* return void
		*/
		virtual void mouseMoveEvent(QMouseEvent* event);

		virtual void keyPressEvent(QKeyEvent* event);

        virtual void wheelEvent(QWheelEvent *event);

        void initializeGL() override;
        void resizeGL(int w, int h) override;
        void paintGL() override;

	private:

		/*!
		* ��ʱ������ʱ���´���
		*/
		QTimer m_qTimer;
	
	protected:
		virtual void resizeEvent(QResizeEvent* event);
	
	private:
        Scene::Viewer* m_pViewer = nullptr;
        Scene::SkyBox* m_pSkyBox = nullptr;
        Scene::Camera* m_pCamera = nullptr;
        Scene::Box* m_pBox = nullptr;
        int m_iWidth = 0, m_iHeight = 1;
        double m_dDeltaTime = 0.0;
        double m_dLastFrameTime = 0.0;
        QElapsedTimer m_eTimer;
	private:
        
	};
}

#endif //UI_SCENEWIDGET_H
