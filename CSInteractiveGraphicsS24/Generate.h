#pragma once
#include "VertexBuffer.h"
#include <glad/glad.h>
#include <glm/glm.hpp>

class Generate
{
private:

public:
	Generate();
	~Generate();

	static std::shared_ptr<VertexBuffer> Cuboid(float width, float height, float depth, glm::vec3 color = { 1.0f, 1.0f, 1.0f }, glm::vec2 tex = { 1.0f, 1.0 });

	static std::shared_ptr<VertexBuffer> XZPlane(float width, float depth, glm::vec3 color = { 1.0f, 1.0f, 1.0f }, glm::vec2 tex = { 1.0f, 1.0 });

	static std::shared_ptr<VertexBuffer> XYPlane(float width, float depth, glm::vec3 color = { 1.0f, 1.0f, 1.0f }, glm::vec2 tex = { 1.0f, 1.0 });

	//Lab 7
	static std::shared_ptr<VertexBuffer> CuboidWithNormals(float width, float height, float depth, glm::vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f }, glm::vec3 normal = { 1.0f, 1.0f, 1.0f }, glm::vec2 tex = { 1.0f, 1.0 });

	static std::shared_ptr<VertexBuffer> XZPlaneWithNormals(float width, float depth, glm::vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f }, glm::vec3 normal = { 1.0f, 1.0f, 1.0f }, glm::vec2 tex = { 1.0f, 1.0 });
};

