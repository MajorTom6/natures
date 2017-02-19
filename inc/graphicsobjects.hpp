#ifndef graphicsobjects_h
#define graphicsobjects_h

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "camera.hpp"


struct Transform
{
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
	{
		this->pos = pos;
		this->rot = rot;
		this->scale = scale;
	}

	inline glm::mat4 GetModel() const
	{
		glm::mat4 posMat = glm::translate(pos);
		glm::mat4 scaleMat = glm::scale(scale);
		glm::mat4 rotX = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
		glm::mat4 rotY = glm::rotate(rot.y, glm::vec3(0.0, 1.0, 0.0));
		glm::mat4 rotZ = glm::rotate(rot.z, glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 rotMat = rotX * rotY * rotZ;

		return posMat * rotMat * scaleMat;
	}

	inline glm::mat4 GetMVP(const Camera& camera) const
	{
		glm::mat4 VP = camera.GetViewProjection();
		glm::mat4 M = GetModel();

		return VP * M;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec3* GetRot() { return &rot; }
	inline glm::vec3* GetScale() { return &scale; }

	inline void SetPos(glm::vec3& pos) { this->pos = pos; }
	inline void SetRot(glm::vec3& rot) { this->rot = rot; }
	inline void SetScale(glm::vec3& scale) { this->scale = scale; }
protected:
private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
};

class GraphicsData
{
  public:

    float x;
    float y;
    float r;
    float g;
    float b;
    float sides;

    GraphicsData(){
		this->x = 0;
		this->y = 0;
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->sides = 0;
	}


    GraphicsData(float x,float y,float r,float g,float b,float sides){
		this->x = 0;
		this->y = 0;
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->sides = 0;
	}

	float getX(){
		return x;
	}
	
	float getY(){
		return y;
	}

};

#endif