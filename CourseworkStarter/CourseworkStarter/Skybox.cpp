#include "Skybox.h"


Skybox::Skybox()
{
}

Skybox::~Skybox()
{
	glDeleteTextures(6, &skybox[0]); //deletes textures
}

void Skybox::initialiseSkybox()
{
	//loads all textures to skybox 
	skybox[LEFT] = loadSkyTexture("C:/Users/Fraser/Documents/Uni/Year3/B/Graphics/GraphicsLabs/CourseworkStarter/res/left.bmp");
	skybox[BACK] = loadSkyTexture("C:/Users/Fraser/Documents/Uni/Year3/B/Graphics/GraphicsLabs/CourseworkStarter/res/back.bmp");
	skybox[RIGHT] = loadSkyTexture("C:/Users/Fraser/Documents/Uni/Year3/B/Graphics/GraphicsLabs/CourseworkStarter/res/right.bmp");
	skybox[FORWARD] = loadSkyTexture("C:/Users/Fraser/Documents/Uni/Year3/B/Graphics/GraphicsLabs/CourseworkStarter/res/front.bmp");
	skybox[UP] = loadSkyTexture("C:/Users/Fraser/Documents/Uni/Year3/B/Graphics/GraphicsLabs/CourseworkStarter/res/top.bmp");
	skybox[DOWN] = loadSkyTexture("C:/Users/Fraser/Documents/Uni/Year3/B/Graphics/GraphicsLabs/CourseworkStarter/res/bottom.bmp");
	
}

void Skybox::drawSky(float size)
{
	glDisable(GL_LIGHTING); //turn off lighting for render pass
	glDisable(GL_DEPTH_TEST);       //turn off depth texting
	glEnable(GL_TEXTURE_2D);        //and turn on texturing
	glBindTexture(GL_TEXTURE_2D, skybox[BACK]);  //use the texture 
	glBegin(GL_QUADS);      //and draw a face
							//back face
	glTexCoord2f(0, 0);      //use the correct texture coordinate
	glVertex3f(size / 2, size / 2, size / 2);       //vertex
	glTexCoord2f(1, 0);								//repeats
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[LEFT]);
	glBegin(GL_QUADS);
	//left face
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[FORWARD]);
	glBegin(GL_QUADS);
	//front face
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[RIGHT]);
	glBegin(GL_QUADS);
	//right face
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[UP]);
	glBegin(GL_QUADS);                      //top face
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[DOWN]);
	glBegin(GL_QUADS);
	//bottom face
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glEnable(GL_LIGHTING);  //enables everything after render pass
	glEnable(GL_DEPTH_TEST);
}

GLuint Skybox::loadSkyTexture(const std::string& filename)
{
	GLuint num = 0;       //the id for the texture

	//width height and number of components of image
	int width;
	int height;
	int numComponents;

	//unsigned char* imageData = stbi_load((filename).c_str(), &width, &height, &numComponents, 4); //loads image 
	SDL_Surface * image = SDL_LoadBMP(filename.c_str());

	if (image == NULL)
	{
		std::cerr << "texture load failed" << filename << SDL_GetError() << std::endl; //if image dtat is null then error message is sent
	}

	glGenTextures(1, &num);   //generates the texture
	glBindTexture(GL_TEXTURE_2D, num);      //binds the texture
	glGenerateMipmap(GL_TEXTURE_2D);	//generates mipmaps
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // wrap texture outside width
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //wrap texture outside height
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);      //texture filterning for minification (texture is smaller than area)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);      //texture filtering for magnification(texture is larger than area)
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, image->pixels);  //send texture to gpu

	SDL_FreeSurface(image);
	//stbi_image_free(image); //deletes image data

	return num;     //return id
}

