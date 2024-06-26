#pragma once
#include <glad/glad.h> 
#include <vector>
#include <unordered_map>
#include <string>
#include "Texture.h"

struct VertexAttribute {
	unsigned int index;
	unsigned int numberOfComponents;
	int type;
	int isNormalized;
	unsigned int bytesToNext;
	void* byteOffset; 
};

class VertexBuffer
{
protected:
	unsigned int numberOfElementsPerVertex;
	unsigned int numberOfVertices;
	unsigned int vboId;
	int primitiveType;
	int textureUnit; //Lab 4
	std::vector<float> vertexData;
	std::unordered_map<std::string, VertexAttribute> attributeMap;
	std::shared_ptr<Texture> texture; //Lab 4

public:
	VertexBuffer(unsigned int numElementsPerVertex = 3);
	~VertexBuffer();

	inline void Select() { glBindBuffer(GL_ARRAY_BUFFER, vboId); }
	inline void Deselect() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

	inline unsigned int GetNumberOfVertices() const { return numberOfVertices; }
	inline int GetPrimitiveType() const { return primitiveType; }
	inline int GetTextureUnit() const { return textureUnit; }
	inline std::shared_ptr<Texture> GetTexture() const { return texture; }

	inline void SetPrimitiveType(int primitiveType) { this->primitiveType = primitiveType; }
	inline void SetTextureUnit(int textureUnit) { this->textureUnit = textureUnit; }
	inline void setTexture(std::shared_ptr<Texture> texture) { this->texture = texture; }

	// Variadic function
	void AddVertexData(unsigned int count, ...);
	void StaticAllocate();
	void AddVertexAttribute(
		const std::string& name, unsigned int index, 
		unsigned int numberOfElements, unsigned int offsetCount=0);
	void SetUpAttributeInterpretration();
	
	//Lab 4
	bool HasTexture();
	void SelectTexture();
};

