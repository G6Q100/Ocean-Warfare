/*  Filename:       image.cpp
	Description:    Solution - MET4335 - image
*/

#define _CRT_SECURE_NO_WARNINGS

#include "GL/freeglut.h"
#include <iostream>
#include "image.h"

using namespace std;

int readBmpFile(const char *filename, BmpHeader *header) {
	FILE *file;

	// open the image file
	if ((file = fopen(filename, "rb")) == NULL)
		return(READ_IMAGE_FILE_NOT_FOUND);
	else
		cout << "{" << filename << ") - ";

	// check if it is a BMP file
	char c[2];
	if (fread(c, 2, 1, file) != 1)
		return(READ_IMAGE_FILE_HEADER_ERROR);
	else if ((c[0] != 'B') || (c[1] != 'M'))
		return(READ_IMAGE_FILE_HEADER_ERROR);

	// seek through the BMP header to the width/height field
	fseek(file, 12, SEEK_CUR);

	// read the size (in bytes) of the BMP header
	GLuint byteRemain;
	if (fread(&byteRemain, sizeof(byteRemain), 1, file) != 1)
		return(READ_IMAGE_FILE_BMP_HEADER_SIZE_ERROR);
	byteRemain -= sizeof(byteRemain);

	// read the width field
	if (fread(&header->width, sizeof(header->width), 1, file) != 1)
		return(READ_IMAGE_FILE_WIDTH_ERROR);
	byteRemain -= sizeof(header->width);

	// read the height field
	if (fread(&header->height, sizeof(header->height), 1, file) != 1)
		return(READ_IMAGE_FILE_HEIGHT_ERROR);
	byteRemain -= sizeof(header->height);

	// read the planes field
	if (fread(&header->planes, sizeof(header->planes), 1, file) != 1)
		return(READ_IMAGE_FILE_PLANES_ERROR);
	else if (header->planes != 1)
		return(READ_IMAGE_FILE_PLANES_ERROR);
	byteRemain -= sizeof(header->planes);

	// read the bits/pixel field
	if (fread(&header->bpp, sizeof(header->bpp), 1, file) != 1)
		return(READ_IMAGE_FILE_BPP_ERROR);
	else if (header->bpp != 24)
		return(READ_IMAGE_FILE_BPP_ERROR);
	byteRemain -= sizeof(header->bpp);

	// seek past the rest of the BMP header
	fseek(file, byteRemain, SEEK_CUR);

	// calculate the sizes (24 bits or 3 bytes per pixel).
	header->noPixels = header->width * header->height;
	header->bytePerPixel = header->bpp / 8;
	header->noBytes = header->bytePerPixel * header->noPixels;

	// read image data
	header->image = (GLubyte*)malloc(header->noBytes);
	if (header->image == NULL)
		return(READ_IMAGE_FILE_BUFFER_ERROR);
	else if (fread(header->image, header->noBytes, 1, file) != 1)
		return(READ_IMAGE_FILE_IMAGE_ERROR);

	// convert BGR to RGB format
	for (GLuint i = 0; i < header->noBytes; i += header->bytePerPixel) {
		GLubyte blue = *(header->image + i);
		*(header->image + i) = *(header->image + i + 2);
		*(header->image + i + 2) = blue;
	}

	cout << header->width << "x" << header->height << " pixels=" << header->noPixels << " pixels, ";
	cout << header->bpp << " bit/pixel, " << header->bytePerPixel << " byte/pixel, ";
	cout << header->noBytes << " bytes" << endl;

	return(READ_IMAGE_FILE_SUCCESS);
}

GLuint TextureImage::loadImage(const char *filename, GLuint type) {
	this->type = type;

	switch (this->type) {
	case BMP_IMAGE: {
		BmpHeader header;
		if (readBmpFile(filename, &header) != READ_IMAGE_FILE_SUCCESS)
			exit(1);

		this->width = header.width;
		this->height = header.height;
		this->bitPerPixel = header.bpp;
		this->bytePerPixel = header.bytePerPixel;
		this->noPixels = header.noPixels;
		this->noBytes = header.noBytes;
		this->image = header.image;
	}
					break;
	default: break;
	}

	glGenTextures(1, &this->textureID);
	glBindTexture(GL_TEXTURE_2D, this->textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, this->width, this->height, 0,
		(this->bytePerPixel == 3) ? GL_RGB : GL_RGBA,
		GL_UNSIGNED_BYTE, this->image);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	free(this->image);
	return(this->textureID);
}