/* ************************************************************************************************************* */
/*                                                                                                               */
/*     GLIP-LIB                                                                                                  */
/*     OpenGL Image Processing LIBrary                                                                           */
/*                                                                                                               */
/*     Author        : R. KERVICHE (ronan.kerviche@free.fr)                                                      */
/*     LICENSE       : GPLv3                                                                                     */
/*     Website       : http://sourceforge.net/projects/glip-lib/                                                 */
/*                                                                                                               */
/*     File          : HdlVBO.cpp                                                                                */
/*     Original Date : August 7th 2010                                                                           */
/*                                                                                                               */
/*     Description   : OpenGL Vertex Buffer Object Handle                                                        */
/*                                                                                                               */
/* ************************************************************************************************************* */

/**
 * \file    HdlVBO.cpp
 * \brief   OpenGL Vertex Buffer Object Handle
 * \author  R. KERVICHE
 * \version 0.6
 * \date    August 7th 2010
*/

#include <cstring>
#include "HdlVBO.hpp"
#include "../include/GLIPLib.hpp"


using namespace Glip::CoreGL;

// Tools
    HdlVBO::HdlVBO(int _nVert, int _dim, GLenum freq, GLfloat* _vertices, int _nElements, int _nIndPerElement, GLuint* _elements, GLenum _type, int _dimTexCoords, GLfloat* _texcoords)
     : nVert(_nVert), dim(_dim), nElements(_nElements), type(_type), nIndPerElement(_nIndPerElement), dimTexCoords(_dimTexCoords), vertices(NULL), elements(NULL)
    {
        void* ptr = NULL;

        if(dimTexCoords!=0 && _texcoords==NULL)
		throw Exception("HdlVBO::HdlVBO - attempt to create texcoords without any data", __FILE__, __LINE__);

	/*std::cout << "Creating VBO : " << std::endl;
	std::cout << "    Vertices : " << nVert << std::endl;
	std::cout << "    Dim      : " << dim << std::endl;
	std::cout << "    Elements : " << nElements << std::endl;
	std::cout << "    Index    : " << nIndPerElement << std::endl;
	std::cout << "    Type     : " << glParamName(type) << std::endl;
	std::cout << "    DimTex   : " << dimTexCoords << std::endl;*/

        // For the vertices and the texcoords :
        //std::cout << " - Vertices - " << nVert*dim << std::endl;
        if(_texcoords!=NULL)
        {
        	//std::cout << " - Texcoords - " << nVert*dimTexCoords*sizeof(GLfloat) << std::endl;
		vertices = new HdlGeBO(nVert*(dim+dimTexCoords)*sizeof(GLfloat), GL_ARRAY_BUFFER_ARB, freq);
        }
        else
		vertices = new HdlGeBO(nVert*dim*sizeof(GLfloat), GL_ARRAY_BUFFER_ARB, freq);

        vertices->subWrite(_vertices, nVert*dim*sizeof(GLfloat),0);
        //std::cout << "Vertices : "; glErrors(true, false);

        if(_texcoords!=NULL)
        {
		vertices->subWrite(_texcoords, nVert*dimTexCoords*sizeof(GLfloat), nVert*dim*sizeof(GLfloat));
		//std::cout << "Texcoords : "; glErrors(true, false);
        }

        // For the elements :
        if(_elements!=NULL)
        {
		//std::cout << " - Elements - " << nElements*nIndPerElement*sizeof(GLuint) << std::endl;
		elements = new HdlGeBO(nElements*nIndPerElement*sizeof(GLuint), GL_ELEMENT_ARRAY_BUFFER_ARB, freq);
		elements->subWrite(_elements, nElements*nIndPerElement*sizeof(GLuint), 0);
		//std::cout << "Elements : "; glErrors(true, false);
        }

	//std::cout << "Exit VBO : "; glErrors(true, false);
	HdlVBO::unbind();
    }

    HdlVBO::~HdlVBO(void)
    {
        delete vertices;
        delete elements;
    }

    int HdlVBO::getVerticesCount(void)  { return nVert; }
    int HdlVBO::getShapeDimension(void) { return dim; }
    int HdlVBO::getElementsCount(void)  { return nElements; }
    GLenum HdlVBO::getType(void)        { return type; }

	void HdlVBO::draw(void)
	{
		//std::cout << "    Rendering start : "; glErrors(true, false);

		// First, bind the data
			vertices->bind(GL_ARRAY_BUFFER_ARB);
		//std::cout << "    Binding : "; glErrors(true, false);
			glVertexPointer(dim, GL_FLOAT, 0, 0);
		//std::cout << "    Vertex description 1 : "; glErrors(true, false);
		if(dimTexCoords>0)
		{
			glTexCoordPointer(dimTexCoords, GL_FLOAT, 0, reinterpret_cast<void*>(NULL + nVert*dim*sizeof(GLfloat)));
			//std::cout << "    Texcoords description 1 : "; glErrors(true, false);
		}

		if(elements!=NULL)
		{
			elements->bind(GL_ELEMENT_ARRAY_BUFFER);
			//std::cout << "    Binding : "; glErrors(true, false);
		}

		// Enable :
		glEnableClientState(GL_VERTEX_ARRAY);
		if(dimTexCoords>0)
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		if(elements==NULL) 	glDrawArrays(GL_POINTS, 0, nVert); //Test with GL_TRIANGLE_STRIP
		else               	glDrawElements(type, nElements*nIndPerElement, GL_UNSIGNED_INT, 0);
		//std::cout << "    Drawing : "; glErrors(true, false);

					glDisableClientState(GL_VERTEX_ARRAY);
		if(dimTexCoords>0) 	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		//std::cout << "    Disabling : "; glErrors(true, false);

		HdlVBO::unbind();
		//std::cout << "    Rendering end : "; glErrors(true, false);
	}

// Static tools
    HdlVBO* HdlVBO::generate2DStandardQuad(void)
    {
        GLfloat vertices[]  = {	-0.5,  0.5,
                                -0.5, -0.5,
                                 0.5,  0.5,
                                 0.5, -0.5};
        GLuint elements[]   = { 0, 1, 3, 2};
        GLfloat texcoords[] = {  0.0,  1.0,
                                 0.0,  0.0,
                                 1.0,  1.0,
                                 1.0,  0.0};
        return new HdlVBO(4, 2, GL_STATIC_DRAW_ARB, vertices, 1, 4, elements, GL_QUADS, 2, texcoords);
    }

    HdlVBO* HdlVBO::generate2DGrid(int w, int h, GLfloat appW, GLfloat appH, GLfloat cX, GLfloat cY)
    {
        if(w<=0 || h<=0)
        {
            std::cerr << "HdlVBO::generate2DGrid : cannot create negative sized grid" << std::endl;
            return NULL;
        }

        //Create the grid first:
        GLfloat x = appW/w,
                y = appH/h;
        cX = cX - appW/2.0;
        cY = cY - appH/2.0;

        GLfloat* data = new GLfloat[w*h*2];
        GLfloat* tex  = new GLfloat[w*h*2];
        unsigned int index = 0;

        for(unsigned int i=0; i<h; i++)
            for(unsigned int j=0; j<w; j++)
            {
                data[index + 0] = i*y + cY;
                data[index + 1] = j*x + cX;
                tex[index + 0]	= static_cast<GLfloat>(i)/static_cast<GLfloat>(h);
                tex[index + 1]	= static_cast<GLfloat>(j)/static_cast<GLfloat>(w);
                index += 2;
            }

        HdlVBO* result = new HdlVBO(w*h, 2, GL_STREAM_DRAW_ARB, data, 0, 0, NULL, GL_NONE, 2, tex);
        delete[] data;
        delete[] tex;

        return result;
    }


// Static tools
    void HdlVBO::unbind(void)
    {
        HdlGeBO::unbind(GL_ARRAY_BUFFER_ARB);
        HdlGeBO::unbind(GL_ELEMENT_ARRAY_BUFFER_ARB);
    }

    void HdlVBO::unmap(void)
    {
        HdlGeBO::unmap(GL_ARRAY_BUFFER_ARB);
        HdlGeBO::unmap(GL_ELEMENT_ARRAY_BUFFER_ARB);
    }