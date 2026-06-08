#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Scene/Export.h>

namespace Scene
{
    // Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
    enum Camera_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    // An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
    class SCENE_EXPORT Camera
    {
    public:
        //Camera() = delete;
        // constructor with vectors
        Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 50.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
        // constructor with scalar values
        Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

        void SetProjectInfo(float iWidth, float iHeight, float fov);
        // returns the view matrix calculated using Euler Angles and the LookAt Matrix
        glm::mat4 GetViewMatrix();
        glm::mat4 GetProjectMatrix();

        // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
        void ProcessKeyboard(Camera_Movement direction, float deltaTime);

        // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
        void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

        // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
        void ProcessMouseScroll(float yoffset);

    private:
        // calculates the front vector from the Camera's (updated) Euler Angles
        void updateCameraVectors();

    private:
        // camera Attributes
        glm::vec3 m_position;
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;
        glm::vec3 m_worldUp;
        // euler Angles
        float m_fYaw = -90.0f;
        float m_fPitch = 0.0f;
        // camera options
        float m_fMovementSpeed = 2.5f;
        float m_fMouseSensitivity = 0.1f;
        float m_fZoom = 45.0f;
        float m_fWidth = 0.0f;
        float m_fHeight = 1.0f;
        float m_fFov = 30.0f;
    };
}

#endif
