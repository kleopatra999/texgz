/*
 * Copyright (c) 2011 Jeff Boody
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef texgz_tex_H
#define texgz_tex_H

// used to determine the file type and endianess
#define TEXGZ_MAGIC 0x000B00D9

// OpenGL ES type
#define TEXGZ_UNSIGNED_SHORT_4_4_4_4 0x8033
#define TEXGZ_UNSIGNED_SHORT_5_5_5_1 0x8034
#define TEXGZ_UNSIGNED_SHORT_5_6_5   0x8363
#define TEXGZ_UNSIGNED_BYTE          0x1401
#define TEXGZ_FLOAT                  0x1406

// OpenGL ES format
#define TEXGZ_RGB       0x1907
#define TEXGZ_RGBA      0x1908
#define TEXGZ_BGRA      0x80E1
#define TEXGZ_LUMINANCE 0x1909

typedef struct
{
	int width;
	int height;
	int stride;
	int vstride;
	int type;
	int format;
	unsigned char* pixels;
} texgz_tex_t;

texgz_tex_t* texgz_tex_new(int width, int height,
                           int stride, int vstride,
                           int type, int format,
                           unsigned char* pixels);
void         texgz_tex_delete(texgz_tex_t** _self);
texgz_tex_t* texgz_tex_copy(texgz_tex_t* self);
texgz_tex_t* texgz_tex_import(const char* filename);
int          texgz_tex_export(texgz_tex_t* self, const char* filename);
int          texgz_tex_convert(texgz_tex_t* self, int type, int format);
texgz_tex_t* texgz_tex_convertcopy(texgz_tex_t* self, int type, int format);
int          texgz_tex_flipvertical(texgz_tex_t* self);
texgz_tex_t* texgz_tex_flipverticalcopy(texgz_tex_t* self);
int          texgz_tex_crop(texgz_tex_t* self, int top, int left, int bottom, int right);
texgz_tex_t* texgz_tex_cropcopy(texgz_tex_t* self, int top, int left, int bottom, int right);
int          texgz_tex_pad(texgz_tex_t* self);
texgz_tex_t* texgz_tex_padcopy(texgz_tex_t* self);
int          texgz_tex_convolve(texgz_tex_t* self, float* mask, int msize, int rescale);
texgz_tex_t* texgz_tex_convolvecopy(texgz_tex_t* self, float* mask, int msize, int rescale);
int          texgz_tex_computegray(texgz_tex_t* self, texgz_tex_t* gray);
int          texgz_tex_computeedges3x3(texgz_tex_t* self, texgz_tex_t* sx, texgz_tex_t* sy);
int          texgz_tex_computeedges5x5(texgz_tex_t* self, texgz_tex_t* sx, texgz_tex_t* sy);
int          texgz_tex_bpp(texgz_tex_t* self);
int          texgz_tex_size(texgz_tex_t* self);

#endif
