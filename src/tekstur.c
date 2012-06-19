/*
 * tekstur.c
 *
 *  Created on: Jun 19, 2012
 *      Author: Wyne
 */

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <glaux.h>
#include <stdio.h>
#include <math.h>


///////////////////////////////////Meload Gambar bertipe Bitmap////////////////////////////////
AUX_RGBImageRec *LoadBMP(char *Filename)
{
        FILE *File=NULL;
        if (!Filename)
        {
                return NULL;
        }
        File=fopen(Filename,"r");
        if (File)
        {
            fclose(File);
            return auxDIBImageLoad(Filename);
        }
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////Prosedur membuat tekstur///////////////////////////////////////
int LoadTextures()
{

	GLint   loop;
	GLuint  texture[14];

	int Status = FALSE;
    AUX_RGBImageRec *TextureImage[14];
    memset(TextureImage, 0, sizeof(void *)*14);
    if ( (TextureImage[0]=LoadBMP("kosmos.bmp")) &&
         (TextureImage[1]=LoadBMP("belka.bmp"))  &&
         (TextureImage[2]=LoadBMP("ziemia.bmp"))&&
		 (TextureImage[3]=LoadBMP("moon.bmp"))&&
         (TextureImage[4]=LoadBMP("fonty.bmp"))  &&
         (TextureImage[5]=LoadBMP("mars.bmp")) &&
		 (TextureImage[6]=LoadBMP("wenus.bmp")) &&
		 (TextureImage[7]=LoadBMP("merkury.bmp")) &&
		 (TextureImage[8]=LoadBMP("satelitemaska.bmp")) &&
         (TextureImage[9]=LoadBMP("satelite.bmp")) &&
		 (TextureImage[10]=LoadBMP("saturnmaska.bmp")) &&
		 (TextureImage[11]=LoadBMP("saturn.bmp")) &&
		 (TextureImage[12]=LoadBMP("space.bmp")) &&
		 (TextureImage[13]=LoadBMP("sun.bmp")))
    {
        Status=TRUE;

        glGenTextures(14, &texture[0]);
        for(loop=0;loop<14;loop++)
        {
            glBindTexture(GL_TEXTURE_2D, texture[loop]);

            gluBuild2DMipmaps(GL_TEXTURE_2D, 3,TextureImage[loop]->sizeX, TextureImage[loop]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[loop]->data);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
        }
        for(loop=0;loop<14;loop++)
        {
            if (TextureImage[loop])
            {
                if (TextureImage[loop]->data)
                    free(TextureImage[loop]->data);
            free(TextureImage[loop]);
            }
        }
    }
    return Status;
}
//////////////////////////////////////////////////////////////////////////////////////////////
