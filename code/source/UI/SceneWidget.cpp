#include <UI/SceneWidget.h>
#include <UI/MainWindow.h>
#include <UI/PluginManager.h>

#include <QtCore/QTime>

#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include <QtGui/QGuiApplication>
#include <QtGui/QDragEnterEvent>

#include <iostream>

using namespace UI;

SceneWidget::SceneWidget(QWidget* pParent) :
	QOpenGLWidget(pParent)
{
	setFocus();
	setMouseTracking(true);
	setFocusPolicy(Qt::StrongFocus);

    QSurfaceFormat format;
    format.setVersion(4, 6);        // GLAD's version
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);

	connect(&m_qTimer, SIGNAL(timeout()), this, SLOT(Update()));
	m_qTimer.start(10);

    m_pViewer = new Scene::Viewer();
    m_pCamera = new Scene::Camera();
}

SceneWidget::~SceneWidget()
{
	m_qTimer.stop();
    delete m_pViewer;
    m_pViewer = nullptr;
    delete m_pCamera;
    m_pCamera = nullptr;
    delete m_pBox;
    m_pBox = nullptr;

    delete m_pSkyBox;
    m_pSkyBox = nullptr;
}

void SceneWidget::Update()
{
    update();
    //paintGL();
}

void SceneWidget::mouseMoveEvent(QMouseEvent* event)
{
    QOpenGLWidget::mouseMoveEvent(event);
}

void SceneWidget::keyPressEvent(QKeyEvent* event)
{
    int iKey = event->key();
    
    switch (iKey)
    {
    case Qt::Key_W:
        m_pCamera->ProcessKeyboard(Scene::FORWARD, m_dDeltaTime);
        break;
    case Qt::Key_S:
        m_pCamera->ProcessKeyboard(Scene::BACKWARD, m_dDeltaTime);
        break;
    case Qt::Key_A:
        m_pCamera->ProcessKeyboard(Scene::LEFT, m_dDeltaTime);
        break;
    case Qt::Key_D:
        m_pCamera->ProcessKeyboard(Scene::RIGHT, m_dDeltaTime);
        break;
    default:
        break;
    }
    
    QOpenGLWidget::keyPressEvent(event);
}

void SceneWidget::wheelEvent(QWheelEvent *event)
{
    m_pCamera->ProcessMouseScroll(event->delta());
}

void SceneWidget::resizeEvent(QResizeEvent* event)
{
    QOpenGLWidget::resizeEvent(event);
}

void SceneWidget::initializeGL()
{
    m_eTimer.start();
    m_pViewer->Init();

    m_pBox = new Scene::Box();
    m_pBox->Init();

    m_pSkyBox = new Scene::SkyBox();
    m_pSkyBox->Init();
    m_pSkyBox->Create();

    return;
}

void SceneWidget::resizeGL(int w, int h)
{
    m_iWidth = w;
    m_iHeight = h;
    m_pViewer->SetViewport(0, 0, w, h);
    m_pCamera->SetProjectInfo(w, h, 45.0f);
}

void SceneWidget::paintGL()
{
    double currentTime = m_eTimer.elapsed() / 1000.0;
    m_dDeltaTime = currentTime - m_dLastFrameTime;
    m_dLastFrameTime = currentTime;
    m_pViewer->Clear();

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = m_pCamera->GetViewMatrix();
    glm::mat4 projection = m_pCamera->GetProjectMatrix();

    m_pBox->SetMPVMatrix(model, view, projection);
    m_pBox->Draw();
    /*
    view = glm::mat4(glm::mat3(m_pCamera->GetViewMatrix()));
    m_pSkyBox->SetMPVMatrix(view, projection);
    m_pSkyBox->Draw();
    */
}