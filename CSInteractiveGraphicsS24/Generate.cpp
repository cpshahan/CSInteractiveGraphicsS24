#include "Generate.h"

Generate::Generate()
{
}

Generate::~Generate()
{

}

std::shared_ptr<VertexBuffer> Generate::Cuboid(float width, float height, float depth, glm::vec3 color, glm::vec2 tex)
{
	std::shared_ptr<VertexBuffer> buffer = std::make_shared<VertexBuffer>(8);

	float halfwidth = width / 2;
	float halfheight = height / 2;
	float halfdepth = depth / 2; 

	/*
	//Front Face
	buffer->AddVertexData(8, -5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //A
	buffer->AddVertexData(8, -5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f); //B
	buffer->AddVertexData(8, 5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //C
	buffer->AddVertexData(8, -5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //A
	buffer->AddVertexData(8, 5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //C
	buffer->AddVertexData(8, 5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); //D

	//Right Face
	buffer->AddVertexData(8, 5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //E
	buffer->AddVertexData(8, 5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f); //F
	buffer->AddVertexData(8, 5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //G
	buffer->AddVertexData(8, 5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //E
	buffer->AddVertexData(8, 5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //G
	buffer->AddVertexData(8, 5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); //H

	//Back Face
	buffer->AddVertexData(8, 5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //I
	buffer->AddVertexData(8, 5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f); //J
	buffer->AddVertexData(8, -5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //K
	buffer->AddVertexData(8, 5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f);  //I
	buffer->AddVertexData(8, -5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //K
	buffer->AddVertexData(8, -5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); //L

	//Left Face
	buffer->AddVertexData(8, -5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //M
	buffer->AddVertexData(8, -5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f); //N
	buffer->AddVertexData(8, -5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //O
	buffer->AddVertexData(8, -5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //M
	buffer->AddVertexData(8, -5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //O
	buffer->AddVertexData(8, -5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); //P

	//Top Face
	buffer->AddVertexData(8, -5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //Q
	buffer->AddVertexData(8, -5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f); //R
	buffer->AddVertexData(8, 5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //S
	buffer->AddVertexData(8, -5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //Q
	buffer->AddVertexData(8, 5.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //S
	buffer->AddVertexData(8, 5.0f, 5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); //T

	//Bottom Face
	buffer->AddVertexData(8, 5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //U,
	buffer->AddVertexData(8, 5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f); //V
	buffer->AddVertexData(8, -5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //W
	buffer->AddVertexData(8, 5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f); //U
	buffer->AddVertexData(8, -5.0f, -5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f); //W
	buffer->AddVertexData(8, -5.0f, -5.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); //X
	*/

	//Front Face
	buffer->AddVertexData(8, -halfwidth, halfheight , halfdepth, color.r, color.g, color.b, 0, tex.t); //A
	buffer->AddVertexData(8, -halfwidth , -halfheight, halfdepth, color.r, color.g, color.b, 0,0); //B
	buffer->AddVertexData(8, halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, tex.s, 0); //C
	buffer->AddVertexData(8, -halfwidth, halfheight, halfdepth, color.r, color.g, color.b, 0, tex.t); //A
	buffer->AddVertexData(8, halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, tex.s, 0); //C
	buffer->AddVertexData(8, halfwidth, halfheight, halfdepth, color.r, color.g, color.b, tex.s, tex.t); //D

	//Right Face
	buffer->AddVertexData(8, halfwidth, halfheight, halfdepth,   color.r, color.g, color.b, 0, tex.t); //E
	buffer->AddVertexData(8, halfwidth, -halfheight, halfdepth,  color.r, color.g, color.b, 0, 0); //F
	buffer->AddVertexData(8, halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, tex.s, 0); //G
	buffer->AddVertexData(8, halfwidth, halfheight, halfdepth,   color.r, color.g, color.b, 0, tex.t); //E
	buffer->AddVertexData(8, halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, tex.s, 0); //G
	buffer->AddVertexData(8, halfwidth, halfheight, -halfdepth,  color.r, color.g, color.b, tex.s, tex.t); //H

	//Back Face
	buffer->AddVertexData(8, halfwidth, halfheight, -halfdepth,   color.r, color.g, color.b, 0, tex.t); //I
	buffer->AddVertexData(8, halfwidth, -halfheight, -halfdepth,  color.r, color.g, color.b, 0, 0); //J
	buffer->AddVertexData(8, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, tex.s, 0); //K
	buffer->AddVertexData(8, halfwidth, halfheight, -halfdepth,   color.r, color.g, color.b, 0, tex.t);  //I
	buffer->AddVertexData(8, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, tex.s, 0); //K
	buffer->AddVertexData(8, -halfwidth, halfheight, -halfdepth,  color.r, color.g, color.b, tex.s, tex.t); //L

	//Left Face
	buffer->AddVertexData(8, -halfwidth, halfheight, -halfdepth,  color.r, color.g, color.b, 0, tex.t); //M
	buffer->AddVertexData(8, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, 0, 0); //N
	buffer->AddVertexData(8, -halfwidth, -halfheight, halfdepth,  color.r, color.g, color.b, tex.s, 0); //O
	buffer->AddVertexData(8, -halfwidth, halfheight, -halfdepth,  color.r, color.g, color.b, 0, tex.t); //M
	buffer->AddVertexData(8, -halfwidth, -halfheight, halfdepth,  color.r, color.g, color.b, tex.s, 0); //O
	buffer->AddVertexData(8, -halfwidth, halfheight, halfdepth,   color.r, color.g, color.b, tex.s, tex.t); //P

	//Top Face
	buffer->AddVertexData(8, -halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, 0, tex.t); //Q
	buffer->AddVertexData(8, -halfwidth, halfheight, halfdepth,  color.r, color.g, color.b, 0, 0); //R
	buffer->AddVertexData(8, halfwidth, halfheight, halfdepth,   color.r, color.g, color.b, tex.s, 0); //S
	buffer->AddVertexData(8, -halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, 0, tex.t); //Q
	buffer->AddVertexData(8, halfwidth, halfheight, halfdepth,   color.r, color.g, color.b, tex.s, 0); //S
	buffer->AddVertexData(8, halfwidth, halfheight, -halfdepth,  color.r, color.g, color.b, tex.s, tex.t); //T

	//Bottom Face
	buffer->AddVertexData(8, halfwidth, -halfheight, -halfdepth,  color.r, color.g, color.b, 0, tex.t); //U, 
	buffer->AddVertexData(8, halfwidth, -halfheight, halfdepth,   color.r, color.g, color.b, 0, 0); //V
	buffer->AddVertexData(8, -halfwidth, -halfheight, halfdepth,  color.r, color.g, color.b, tex.s, 0); //W
	buffer->AddVertexData(8, halfwidth, -halfheight, -halfdepth,  color.r, color.g, color.b, 0, tex.t); //U
	buffer->AddVertexData(8, -halfwidth, -halfheight, halfdepth,  color.r, color.g, color.b, tex.s, 0); //W
	buffer->AddVertexData(8, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, tex.s, tex.t); //X

	return buffer;
}

std::shared_ptr<VertexBuffer> Generate::XZPlane(float width, float depth, glm::vec3 color, glm::vec2 tex)
{
	std::shared_ptr<VertexBuffer> buffer = std::make_shared<VertexBuffer>(8);

	//Top
	buffer->AddVertexData(8, -width, 0, -depth, color.r, color.g, color.b, 0, tex.t); 
	buffer->AddVertexData(8, -width, 0, depth, color.r, color.g, color.b, 0, 0); 
	buffer->AddVertexData(8, width, 0, depth, color.r, color.g, color.b, tex.s, 0); 
	buffer->AddVertexData(8, -width, 0, -depth, color.r, color.g, color.b, 0, tex.t); 
	buffer->AddVertexData(8, width, 0, depth, color.r, color.g, color.b, tex.s, 0); 
	buffer->AddVertexData(8, width, 0, -depth, color.r, color.g, color.b, tex.s, tex.t); 

	buffer->AddVertexData(8, width, 0, -depth, color.r, color.g, color.b, 0, tex.t);   
	buffer->AddVertexData(8, width, 0, depth, color.r, color.g, color.b,  0, 0); 
	buffer->AddVertexData(8, -width, 0, depth, color.r, color.g, color.b, tex.s, 0); 
	buffer->AddVertexData(8, width, 0, -depth, color.r, color.g, color.b, 0, tex.t); 
	buffer->AddVertexData(8, -width, 0, depth, color.r, color.g, color.b, tex.s, 0); 
	buffer->AddVertexData(8, -width, 0, -depth, color.r, color.g, color.b, tex.s, tex.t); 
	//Bottom

	return buffer;
}

std::shared_ptr<VertexBuffer> Generate::XYPlane(float width, float height, glm::vec3 color, glm::vec2 tex)
{
	std::shared_ptr<VertexBuffer> buffer = std::make_shared<VertexBuffer>(8);

	//Front Face
	buffer->AddVertexData(8, -width, height, 0, color.r, color.g, color.b, 0, tex.t); //A
	buffer->AddVertexData(8, -width, -height, 0, color.r, color.g, color.b, 0, 0); //B
	buffer->AddVertexData(8, width, -height, 0, color.r, color.g, color.b, tex.s, 0); //C
	buffer->AddVertexData(8, -width, height, 0, color.r, color.g, color.b, 0, tex.t); //A
	buffer->AddVertexData(8, width, -height, 0, color.r, color.g, color.b, tex.s, 0); //C
	buffer->AddVertexData(8, width, height, 0, color.r, color.g, color.b, tex.s, tex.t); //D

	//Back Face
	buffer->AddVertexData(8, width, height, 0, color.r, color.g, color.b, 0, tex.t); //I
	buffer->AddVertexData(8, width, -height, 0, color.r, color.g, color.b, 0, 0); //J
	buffer->AddVertexData(8, -width, -height, 0, color.r, color.g, color.b, tex.s, 0); //K
	buffer->AddVertexData(8, width, height, 0, color.r, color.g, color.b, 0, tex.t);  //I
	buffer->AddVertexData(8, -width, -height, 0, color.r, color.g, color.b, tex.s, 0); //K
	buffer->AddVertexData(8, -width, height, 0, color.r, color.g, color.b, tex.s, tex.t); //L

	return buffer;
}

//Lab 7
std::shared_ptr<VertexBuffer> Generate::CuboidWithNormals(float width, float height, float depth, glm::vec4 color, glm::vec2 tex)
{
	std::shared_ptr<VertexBuffer> buffer = std::make_shared<VertexBuffer>(12);

	float halfwidth = width / 2;
	float halfheight = height / 2;
	float halfdepth = depth / 2;

	glm::vec3 front = { 0, 0, 1.0f };
	glm::vec3 back = { 0, 0, -1.0f };
	glm::vec3 left = { -1.0f, 0, 0 };
	glm::vec3 right = { 1.0f, 0, 0 };
	glm::vec3 top = { 0, 1.0f, 0 };
	glm::vec3 bottom = { 0, -1.0f, 0 };
	
	//Front Face
	buffer->AddVertexData(12, -halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, front.x, front.y, front.z, 0, tex.t); 
	buffer->AddVertexData(12, -halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, front.x, front.y, front.z, 0, 0);
	buffer->AddVertexData(12, halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, front.x, front.y, front.z, tex.s, 0);
	buffer->AddVertexData(12, -halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, front.x, front.y, front.z, 0, tex.t);
	buffer->AddVertexData(12, halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, front.x, front.y, front.z, tex.s, 0);
	buffer->AddVertexData(12, halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, front.x, front.y, front.z, tex.s, tex.t);

	//Right Face
	buffer->AddVertexData(12, halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, right.x, right.y, right.z, 0, tex.t); 
	buffer->AddVertexData(12, halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, right.x, right.y, right.z, 0, 0);
	buffer->AddVertexData(12, halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, right.x, right.y, right.z, tex.s, 0);
	buffer->AddVertexData(12, halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, right.x, right.y, right.z, 0, tex.t);
	buffer->AddVertexData(12, halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, right.x, right.y, right.z, tex.s, 0);
	buffer->AddVertexData(12, halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, right.x, right.y, right.z, tex.s, tex.t);

	//Back Face
	buffer->AddVertexData(12, halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, back.x, back.y, back.z, 0, tex.t); 
	buffer->AddVertexData(12, halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, back.x, back.y, back.z, 0, 0);
	buffer->AddVertexData(12, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, back.x, back.y, back.z, tex.s, 0);
	buffer->AddVertexData(12, halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, back.x, back.y, back.z, 0, tex.t);
	buffer->AddVertexData(12, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, back.x, back.y, back.z, tex.s, 0);
	buffer->AddVertexData(12, -halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, back.x, back.y, back.z, tex.s, tex.t);

	//Left Face
	buffer->AddVertexData(12, -halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, left.x, left.y, left.z, 0, tex.t); 
	buffer->AddVertexData(12, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, left.x, left.y, left.z, 0, 0);
	buffer->AddVertexData(12, -halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, left.x, left.y, left.z, tex.s, 0);
	buffer->AddVertexData(12, -halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, left.x, left.y, left.z, 0, tex.t);
	buffer->AddVertexData(12, -halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, left.x, left.y, left.z, tex.s, 0);
	buffer->AddVertexData(12, -halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, left.x, left.y, left.z, tex.s, tex.t);

	//Top Face
	buffer->AddVertexData(12, -halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, top.x, top.y, top.z, 0, tex.t);
	buffer->AddVertexData(12, -halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, top.x, top.y, top.z, 0, 0);
	buffer->AddVertexData(12, halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, top.x, top.y, top.z, tex.s, 0);
	buffer->AddVertexData(12, -halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, top.x, top.y, top.z, 0, tex.t);
	buffer->AddVertexData(12, halfwidth, halfheight, halfdepth, color.r, color.g, color.b, color.a, top.x, top.y, top.z, tex.s, 0);
	buffer->AddVertexData(12, halfwidth, halfheight, -halfdepth, color.r, color.g, color.b, color.a, top.x, top.y, top.z, tex.s, tex.t);

	//Bottom Face
	buffer->AddVertexData(12, halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, bottom.x, bottom.y, bottom.z, 0, tex.t);  
	buffer->AddVertexData(12, halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, bottom.x, bottom.y, bottom.z, 0, 0);
	buffer->AddVertexData(12, -halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, bottom.x, bottom.y, bottom.z, tex.s, 0);
	buffer->AddVertexData(12, halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, bottom.x, bottom.y, bottom.z, 0, tex.t);
	buffer->AddVertexData(12, -halfwidth, -halfheight, halfdepth, color.r, color.g, color.b, color.a, bottom.x, bottom.y, bottom.z, tex.s, 0);
	buffer->AddVertexData(12, -halfwidth, -halfheight, -halfdepth, color.r, color.g, color.b, color.a, bottom.x, bottom.y, bottom.z, tex.s, tex.t);

	return buffer;
}

std::shared_ptr<VertexBuffer> Generate::XZPlaneWithNormals(float width, float depth, glm::vec4 color, glm::vec2 tex)
{
	std::shared_ptr<VertexBuffer> buffer = std::make_shared<VertexBuffer>(12);

	//Top Face
	buffer->AddVertexData(12, -width, 0.0f, -depth, color.r, color.g, color.b, color.a, 0.0f, 1.0f, 0.0f, 0.0f, tex.t);
	buffer->AddVertexData(12, -width, 0.0f, depth, color.r, color.g, color.b, color.a, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
	buffer->AddVertexData(12, width,  0.0f, depth, color.r, color.g, color.b, color.a, 0.0f, 1.0f, 0.0f, tex.s, 0.0f);
	buffer->AddVertexData(12, -width, 0.0f, -depth, color.r, color.g, color.b, color.a, 0.0f, 1.0f, 0.0f, 0.0f, tex.t);
	buffer->AddVertexData(12, width,  0.0f, depth, color.r, color.g, color.b, color.a, 0.0f, 1.0f, 0.0f, tex.s, 0.0f);
	buffer->AddVertexData(12, width,  0.0f, -depth, color.r, color.g, color.b, color.a, 0.0f, 1.0f, 0.0f, tex.s, tex.t);

	//Bottom
	buffer->AddVertexData(12, -width, 0.0f, depth, color.r, color.g, color.b, color.a,  0.0f, -1.0f, 0.0f, 0.0f, tex.t);
	buffer->AddVertexData(12, -width, 0.0f, -depth, color.r, color.g, color.b, color.a, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f);
	buffer->AddVertexData(12, width,  0.0f, -depth, color.r, color.g, color.b, color.a,  0.0f, -1.0f, 0.0f, tex.s, 0.0f);
	buffer->AddVertexData(12, -width, 0.0f, depth, color.r, color.g, color.b, color.a,  0.0f, -1.0f, 0.0f, 0.0f, tex.t);
	buffer->AddVertexData(12, width,  0.0f, -depth, color.r, color.g, color.b, color.a,  0.0f, -1.0f, 0.0f, tex.s, 0.0f);
	buffer->AddVertexData(12, width, 0.0f, depth, color.r, color.g, color.b, color.a, 0.0f, -1.0f, 0.0f, tex.s, tex.t);

	return buffer;
}

void Generate::XZLineCircle(std::shared_ptr<VertexBuffer>& buffer, float radius, glm::vec3 color, int steps)
{
	float x, z, thetaRadians;

	for (float theta = 0; theta < 360; theta += steps) {
		thetaRadians = glm::radians(theta);
		x = radius * cosf(thetaRadians);
		z = radius * sinf(thetaRadians);
		buffer->AddVertexData(6, x, 0.0f, z, color.r, color.g, color.b);
	}
}

void Generate::LineCircleIndexes(std::shared_ptr<IndexBuffer>& bufferToFill, int numberOfLineSegments, bool isClosed)
{
	unsigned short nextIndex;
	if (!isClosed)
	{
		for (unsigned short index = 0; index < numberOfLineSegments - 1; index++) {
			bufferToFill->AddIndexData(index);
			nextIndex = index + 1;
			bufferToFill->AddIndexData(nextIndex);
		}
	}
	else
	{
		for (unsigned short index = 0; index < numberOfLineSegments; index++) {
			bufferToFill->AddIndexData(index);
			nextIndex = (index + 1) % static_cast<unsigned short>(numberOfLineSegments);
			bufferToFill->AddIndexData(nextIndex);
		}
	}
}

void Generate::LineCylinder(std::shared_ptr<VertexBuffer>& buffer, float radius, float height, glm::vec3 color, int steps)
{
	float x, z, thetaRadians;
	float posHalfHeight = height / 2;
	float negHalfHeight = -posHalfHeight;

	//Bottom Circle
	for (float theta = 0; theta < 360; theta += steps) {
		thetaRadians = glm::radians(theta);
		x = radius * cosf(thetaRadians);
		z = radius * sinf(thetaRadians);
		buffer->AddVertexData(6, x, negHalfHeight, z, color.r, color.g, color.b);
	}

	//Top Circle
	for (float theta = 0; theta < 360; theta += steps) {
		thetaRadians = glm::radians(theta);
		x = radius * cosf(thetaRadians);
		z = radius * sinf(thetaRadians);
		buffer->AddVertexData(6, x, posHalfHeight, z, color.r, color.g, color.b);
	}
}

void Generate::LineCylinderIndexes(std::shared_ptr<IndexBuffer>& bufferToFill, int numberOfLineSegments)
{
	unsigned short topIndex;
	unsigned short bottomIndex;
	unsigned short nextTopIndex;
	unsigned short nextBottomIndex;
	unsigned short lineIndex;
	unsigned short nextLineIndex;

	//Bottom Circle
	for (bottomIndex = 0; bottomIndex < numberOfLineSegments; bottomIndex++) 
	{
		bufferToFill->AddIndexData(bottomIndex);
		nextBottomIndex = bottomIndex + 1;
		if (nextBottomIndex == numberOfLineSegments) { nextBottomIndex = 0; }
		bufferToFill->AddIndexData(nextBottomIndex);
	}
	//Top Circle
	for (topIndex = numberOfLineSegments; topIndex < numberOfLineSegments*2; topIndex++)
	{
		bufferToFill->AddIndexData(topIndex);
		nextTopIndex = topIndex + 1;
		if (nextTopIndex == numberOfLineSegments*2) { nextTopIndex = numberOfLineSegments; }
		bufferToFill->AddIndexData(nextTopIndex);
	}
	//Lines 
	for (lineIndex = 0; lineIndex < numberOfLineSegments; lineIndex++)
	{
		bufferToFill->AddIndexData(lineIndex);
		nextLineIndex = lineIndex + numberOfLineSegments;
		bufferToFill->AddIndexData(nextLineIndex);
	}
	//One Loop Attempt Missing Last Top Circle Segment 
	//for (bottomIndex = 0; bottomIndex < numberOfLineSegments; bottomIndex++)
	//{
	//	//Bottom Circle 
	//	bufferToFill->AddIndexData(bottomIndex);
	//	nextBottomIndex = bottomIndex + 1;
	//	if (nextBottomIndex == numberOfLineSegments) { nextBottomIndex = 0; }
	//	bufferToFill->AddIndexData(nextBottomIndex);
	//	//Top Circle 
	//	topIndex = bottomIndex + numberOfLineSegments;
	//	bufferToFill->AddIndexData(topIndex);
	//	nextTopIndex = topIndex + 1;
	//	if (nextTopIndex == numberOfLineSegments*2) { nextTopIndex = bottomIndex + numberOfLineSegments; }
	//	bufferToFill->AddIndexData(nextTopIndex);
	//	//Lines
	//	bufferToFill->AddIndexData(bottomIndex);
	//	bufferToFill->AddIndexData(topIndex);
	//}
}
