#include <Scene/Camera.h>
#include <iostream>
using namespace Scene;

Camera::Camera(glm::vec3 position, glm::vec3 up)
    : m_front(glm::vec3(0.0f, 0.0f, -1.0f))
{
    m_position = position;
    m_worldUp = up;
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
    : m_front(glm::vec3(0.0f, 0.0f, -1.0f))
{
    m_position = glm::vec3(posX, posY, posZ);
    m_worldUp = glm::vec3(upX, upY, upZ);
    m_fYaw = yaw;
    m_fPitch = pitch;
    updateCameraVectors();
}

void Camera::SetProjectInfo(float iWidth, float iHeight, float fov)
{
    m_fWidth = iWidth;
    m_fHeight = iHeight;
    m_fFov = fov;
    m_fZoom = fov;
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::mat4 Camera::GetProjectMatrix()
{
    glm::mat4 projection = glm::perspective(glm::radians(m_fZoom), m_fWidth / m_fHeight, 0.1f, 100.0f);
    return projection;
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = m_fMovementSpeed * deltaTime;
    if (direction == FORWARD)
    {
        velocity *= 2.0f;
        m_position += m_front * velocity;
    }
    if (direction == BACKWARD)
    {
        velocity *= 2.0f;
        m_position -= m_front * velocity;
    }
    if (direction == LEFT)
        //m_position -= glm::normalize(glm::cross(m_front, m_up)) * m_fMovementSpeed;
        m_position -= m_right * velocity;
    if (direction == RIGHT)
        //m_position += glm::normalize(glm::cross(m_front, m_up)) * m_fMovementSpeed;
        m_position += m_right * velocity;
    std::cout << "Position: " << m_position.x << " " << m_position.y << " " << m_position.z << std::endl;
    //glm::lookAt(m_position, m_position + m_front, m_up);
    //updateCameraVectors();
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
    xoffset *= m_fMouseSensitivity;
    yoffset *= m_fMouseSensitivity;

    m_fYaw   += xoffset;
    m_fPitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (m_fPitch > 89.0f)
            m_fPitch = 89.0f;
        if (m_fPitch < -89.0f)
            m_fPitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    m_fZoom -= (float)yoffset;
    if (m_fZoom < 1.0f)
        m_fZoom = 1.0f;
    if (m_fZoom > 45.0f)
        m_fZoom = 45.0f;
}

void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
    front.y = sin(glm::radians(m_fPitch));
    front.z = sin(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
    m_front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_up    = glm::normalize(glm::cross(m_right, m_front));
}