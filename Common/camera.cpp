#include <iostream>
#include "camera.h"
#include <GL/freeglut.h>
Camera::Camera()
{
	m_position = Vector3f(0.0f, 0.0f, 0.0f);
	m_target = Vector3f(0.0f, 0.0f, 1.0f);
	m_up = Vector3f(0.0f, 1.0f, 0.0f);
}

void Camera::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void Camera::OnKeyboard(unsigned char Key)
{
    switch (Key) {

    case GLUT_KEY_UP:
        m_position += (m_target * m_speed);
        break;

    case GLUT_KEY_DOWN:
        m_position -= (m_target * m_speed);
        break;

    case GLUT_KEY_LEFT:
    {
        Vector3f Left = m_target.Cross(m_up);
        Left.Normalize();
        Left *= m_speed;
        m_position += Left;
    }
    break;

    case GLUT_KEY_RIGHT:
    {
        Vector3f Right = m_up.Cross(m_target);
        Right.Normalize();
        Right *= m_speed;
        m_position += Right;
    }
    break;

    case GLUT_KEY_PAGE_UP:
        m_position.y += m_speed;
        break;

    case GLUT_KEY_PAGE_DOWN:
        m_position.y -= m_speed;
        break;

    case '+':
        m_speed += 0.1f;
        printf("Speed changed to %f\n", m_speed);
        break;

    case '-':
        m_speed -= 0.1f;
        if (m_speed < 0.1f) {
            m_speed = 0.1f;
        }
        printf("Speed changed to %f\n", m_speed);
        break;
    }
}


Matrix4f Camera::GetMatrix()
{
    Matrix4f CameraTransformation;
    CameraTransformation.InitCameraTransform(m_position, m_target, m_up);

    return CameraTransformation;
}