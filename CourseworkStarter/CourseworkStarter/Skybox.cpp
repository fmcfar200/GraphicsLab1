#include "Skybox.h"


Skybox::Skybox()
{
}

Skybox::~Skybox()
{
	glDeleteTextures(6, &skybox[0]);
}

void Skybox::initialiseSkybox()
{
	skybox[LEFT] = loadSkyTexture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\left.bmp");
	skybox[BACK] = loadSkyTexture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\back.bmp");
	skybox[RIGHT] = loadSkyTexture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\right.bmp");
	skybox[FORWARD] = loadSkyTexture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\front.bmp");
	skybox[UP] = loadSkyTexture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\up.bmp");
	skybox[DOWN] = loadSkyTexture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\down.bmp");
}

void Skybox::drawSky(float size)
{
	bool b1 = glIsEnabled(GL_TEXTURE_2D);     //new, we left the textures turned on, if it was turned on
	glDisable(GL_LIGHTING); //turn off lighting, when making the skybox
	glDisable(GL_DEPTH_TEST);       //turn off depth texting
	glEnable(GL_TEXTURE_2D);        //and turn on texturing
	glBindTexture(GL_TEXTURE_2D, skybox[BACK]);  //use the texture we want
	glBegin(GL_QUADS);      //and draw a face
							//back face
	glTexCoord2f(0, 0);      //use the correct texture coordinate
	glVertex3f(size / 2, size / 2, size / 2);       //and a vertex
	glTexCoord2f(1, 0);      //and repeat it...
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
	glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
	glEnable(GL_DEPTH_TEST);
	if (!b1)
		glDisable(GL_TEXTURE_2D);
}

unsigned int Skybox::loadSkyTexture(const std::string& filename)
{
	unsigned int num;       //the id for the texture

	glGenTextures(1, &num);  //we generate a unique one
	SDL_Surface* img = SDL_LoadBMP(filename.c_str()); //load the bmp image

	if (img == NULL)
	{
		std::cerr << "texture load failed" << filename << std::endl;
	}


	glBindTexture(GL_TEXTURE_2D, num);       //and use the texture, we have just generated
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //same if the image bigger
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);      //we repeat the pixels in the edge of the texture, it will hide that 1px wide line at the edge of the cube, which you have seen in the video
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);      //we do it for vertically and horizontally (previous line)
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);

	SDL_FreeSurface(img);
	return num;     //and we return the id
}

