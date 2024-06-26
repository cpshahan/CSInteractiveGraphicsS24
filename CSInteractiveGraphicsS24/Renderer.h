#pragma once
#include "BaseObject.h"
#include "Shader.h"
#include "GraphicsObject.h"
#include "Scene.h"
#include <glm/glm.hpp>
#include "Camera.h"

class Renderer : public BaseObject
{
private:
	unsigned int vaoID;
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Scene> scene;
	glm::mat4 view;
	glm::mat4 projection;

public: 
	Renderer(std::shared_ptr<Shader>& shader);
	~Renderer() = default;

	inline std::shared_ptr<Shader> GetShader() const { return shader; }
	inline std::shared_ptr<Scene> GetScene() const { return scene; }

	inline void SetScene(std::shared_ptr<Scene> scene) { this->scene = scene; }
	inline void SetView(glm::mat4 view) { this->view = view; }
	inline void SetProjection(glm::mat4 projection) { this->projection = projection; }

	void AllocateVertexBuffers(const std::vector<std::shared_ptr<GraphicsObject>>& objects);
	void RenderScene(const Camera& camera);

private: 
	void RenderObject(GraphicsObject& object);
};

