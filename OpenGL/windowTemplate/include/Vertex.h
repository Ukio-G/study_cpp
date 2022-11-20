#ifndef VERTEX_H
#define VERTEX_H

struct alignas(sizeof(float) * 8) Vertex {
	typedef float PositionType;
	typedef float ColorType;
	typedef float UVType;

	PositionType pos[3];
	ColorType    color[3];
	UVType       textureUV[2];
};


#endif