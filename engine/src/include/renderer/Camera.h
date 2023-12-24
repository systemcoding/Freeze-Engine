#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/* Basic Camera System.
   This doesn't work with the mouse and keyboard controls yet, but hopefully i will make it a bit more usable later.
   Rotation is supported only in the z-axis otherwise you would see weird results!
   For now there is no Update() function and whenever you set a position / rotation manually it recalculates the view matrix which is fine.
*/

namespace Freeze {
    class Camera {
    public:

        enum class CameraDIR
        {
            NONE = 0,
            CAM_LEFT,
            CAM_RIGHT,
            CAM_UP
        };

        Camera(const glm::vec4& camPos);

        void SetPosition(const glm::vec3& position) { m_Position = position; CalculateViewMatrix(); }
        void SetRotation(float rotation) { m_Rotation = rotation; CalculateViewMatrix(); }

        const glm::vec3& GetPosition() const { return m_Position; }
        const float GetRotation() const { return m_Rotation; }

        // Required for the shader so that positions and rotation works!
        const glm::mat4 GetProjectionViewMatrix() const { return m_ProjectionViewMatrix; }

        void CalculateViewMatrix();
        void Update();

        ~Camera();
    public:
        void MoveCamera(Camera::CameraDIR cameraDirection, float camSpeed);
    private:
        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ProjectionViewMatrix;

        glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
        float m_Rotation = 0.0f;
    };
};
