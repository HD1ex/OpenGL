#pragma once
#include "IScene.h"
#include "StaticShader.h"

class MainScene :
	public IScene
{
public:
	MainScene();
	~MainScene();
	void update()override;
	void render()override;

	//Members
private:
	unsigned int vao;
	unsigned int vbo;
	StaticShader shader;

};

