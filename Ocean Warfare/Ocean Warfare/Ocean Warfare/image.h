/*  Filename:       image.h
	Description:    Solution - MET4335 - image
*/

#define READ_IMAGE_FILE_SUCCESS                 0
#define READ_IMAGE_FILE_NOT_FOUND               1
#define READ_IMAGE_FILE_CANNOT_OPEN             2
#define READ_IMAGE_FILE_WIDTH_ERROR             3
#define READ_IMAGE_FILE_HEIGHT_ERROR            4
#define READ_IMAGE_FILE_BPP_ERROR               5
#define READ_IMAGE_FILE_PLANES_ERROR            6
#define READ_IMAGE_FILE_BUFFER_ERROR            7
#define READ_IMAGE_FILE_IMAGE_ERROR             8
#define READ_IMAGE_FILE_BMP_HEADER_SIZE_ERROR   9
#define READ_IMAGE_FILE_HEADER_ERROR           10
#define READ_IMAGE_FILE_OTHER_ERROR            99

#define BMP_IMAGE   1
#define TGA_IMAGE   2

/* header information for BMP files
*/
struct BmpHeader {
	GLuint width, height;       // dimension of image
	GLuint noPixels, noBytes;   // size information
	GLushort planes;            // number of planes (must be 1)
	GLushort bpp;               // 24 bits/pixel
	GLuint bytePerPixel;        // 3 bytes
	GLubyte* image;             // image
};

/* Texture class for BMP or TGA files
*/
class TextureImage {
private:
	GLuint type;                // BMP=1 or TGA=2
	GLuint width, height;       // dimension of image
	GLuint noPixels, noBytes;   // size information
	GLuint bitPerPixel;         // 24 or 32 bits/pixel
	GLuint bytePerPixel;        // 3 or 4 bytes/pixel
	GLubyte *image;             // image pointer
	GLuint textureID;           // texture ID
public:
	GLuint loadImage(const char* filename, GLuint type);
};
