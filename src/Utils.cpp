#include "Utils.hpp"

/* GLOBAL */
Cell gaussian[SIZE_GAUSSIAN + 2][SIZE_GAUSSIAN + 2];

Vertex3D crossproduct(Vertex3D a, Vertex3D b){
	Vertex3D prod;

	prod.x = a.y * b.z - a.z * b.y;
	prod.y = a.z * b.x - a.x * b.z;
	prod.z = a.x * b.y - a.y * b.x;

	return prod;
}

Vertex3D normalize(Vertex3D p){
	Vertex3D novo;

	// Produto escalar
	GLfloat norm = (float) sqrt(p.x * p.x + p.y * p.y + p.z * p.z);

	novo.x = p.x / norm;
	novo.y = p.y / norm;
	novo.z = p.z / norm;

	return novo;
}

void calcNormal(){
	Vertex3D v1, v2, v3, vec1, vec2;

	for (int i = 1; i <= SIZE_GAUSSIAN; ++i){
		for (int j = 1; j <= SIZE_GAUSSIAN; ++j){
			v1 = gaussian[i][j].point;
			v2 = gaussian[i][j + 1].point;
			v3 = gaussian[i + 1][j].point;

			vec1.x = v2.x - v1.x;
			vec1.y = v2.y - v1.y;
			vec1.z = v2.z - v1.z;

			vec2.x = v1.x - v3.x;
			vec2.y = v1.y - v3.y;
			vec2.z = v1.z - v3.z;

			gaussian[i][j].normal = normalize(crossproduct(vec1, vec2));
		}
	}
}

void criaGaussiana(){
	int i;
	int j;

	GLfloat x;
	GLfloat z;
	GLfloat y;
	GLfloat xexp;
	GLfloat zexp;

	for (i = 0; i < SIZE_GAUSSIAN + 2; i++){
		for (j = 0; j < SIZE_GAUSSIAN + 2; j++){
			x = (4.0f * j) / ((GLfloat) SIZE_GAUSSIAN + 2) - 2.0f;
			z = (4.0f * i) / ((GLfloat) SIZE_GAUSSIAN + 2) - 2.0f;

			xexp = exp(-x * x);
			zexp = exp(-z * z);
			y = (GLfloat) xexp * zexp;

			gaussian[i][j].point.x = x;
			gaussian[i][j].point.y = y;
			gaussian[i][j].point.z = z;
		}
	}
}

GLuint bind_tex(GLuint * textureID, Mat & img){
	glGenTextures(1, textureID);
	glBindTexture(GL_TEXTURE_2D, *textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, img.ptr());;
	glBindTexture(GL_TEXTURE_2D, 0);
	cout << textureID << " : " << *textureID << endl;

	return *textureID;
}