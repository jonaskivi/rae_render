// this file is automatically created from Rae programming language module:
///Users/joonaz/Dropbox/jonas/2015/ohjelmointi/rae_render/src/cpp/rae/3d/Mesh
#include "Mesh.hpp"
; // line: 2

//TODO import cpp.glm.glm
//using glm
//TODO import cpp.GL.glew

// using keyword is TODO
#include "glm/glm.hpp"
// using glm

//TODO private import:
// priv import GL.glew
#include "GL/glew.hpp"



//class Mesh

Mesh::Mesh()
: vertexBufferID(0)
, uvBufferID(0)
, normalBufferID(0)
, indexBufferID(0)
{ //-------------Rae boilerplate code-------------
	_rae_link_list = nullptr;
	//-------------end Rae boilerplate code-------------


}

Mesh::~Mesh()
{ //-------------Rae boilerplate code-------------
	_rae_unlink_all();
	//-------------end Rae boilerplate code-------------


}

void Mesh::generateBox()
{
	std::cout<<"Generating Mesh."<<"\n"; // line: 76
	
	float boxSize = 0.5f; // Actually half of the box size
	
	/* C++11 needed here:
		vertices =
		[
			glm.vec3(-boxSize,  boxSize,  boxSize), # 0
			glm.vec3( boxSize,  boxSize,  boxSize), # 1
			glm.vec3( boxSize,  boxSize, -boxSize), # 2
			glm.vec3(-boxSize,  boxSize, -boxSize), # 3

			glm.vec3(-boxSize, -boxSize,  boxSize), # 4
			glm.vec3(-boxSize, -boxSize, -boxSize), # 5
			glm.vec3( boxSize, -boxSize, -boxSize), # 6
			glm.vec3( boxSize, -boxSize,  boxSize), # 7

			glm.vec3(-boxSize, -boxSize, -boxSize), # 8
			glm.vec3(-boxSize,  boxSize, -boxSize), # 9
			glm.vec3( boxSize,  boxSize, -boxSize), # 10
			glm.vec3( boxSize, -boxSize, -boxSize), # 11
			
			glm.vec3( boxSize, -boxSize,  boxSize), # 12
			glm.vec3( boxSize,  boxSize,  boxSize), # 13
			glm.vec3(-boxSize,  boxSize,  boxSize), # 14
			glm.vec3(-boxSize, -boxSize,  boxSize), # 15

			glm.vec3(-boxSize, -boxSize,  boxSize), # 16
			glm.vec3(-boxSize,  boxSize,  boxSize), # 17
			glm.vec3(-boxSize,  boxSize, -boxSize), # 18
			glm.vec3(-boxSize, -boxSize, -boxSize), # 19
			
			glm.vec3( boxSize, -boxSize, -boxSize), # 20
			glm.vec3( boxSize,  boxSize, -boxSize), # 21
			glm.vec3( boxSize,  boxSize,  boxSize), # 22
			glm.vec3( boxSize, -boxSize,  boxSize) # 23
		]

		uvs =
		[
			glm.vec2( 1.0f,  0.0f ), # 0
			glm.vec2( 1.0f,  1.0f ), # 1
			glm.vec2( 0.0f,  1.0f ), # 2
			glm.vec2( 0.0f,  0.0f ), # 3
			
			glm.vec2( 1.0f,  0.0f ), # 0
			glm.vec2( 1.0f,  1.0f ), # 1
			glm.vec2( 0.0f,  1.0f ), # 2
			glm.vec2( 0.0f,  0.0f ), # 3

			glm.vec2( 1.0f,  0.0f ), # 0
			glm.vec2( 1.0f,  1.0f ), # 1
			glm.vec2( 0.0f,  1.0f ), # 2
			glm.vec2( 0.0f,  0.0f ), # 3

			glm.vec2( 1.0f,  0.0f ), # 0
			glm.vec2( 1.0f,  1.0f ), # 1
			glm.vec2( 0.0f,  1.0f ), # 2
			glm.vec2( 0.0f,  0.0f ), # 3

			glm.vec2( 1.0f,  0.0f ), # 0
			glm.vec2( 1.0f,  1.0f ), # 1
			glm.vec2( 0.0f,  1.0f ), # 2
			glm.vec2( 0.0f,  0.0f ), # 3

			glm.vec2( 1.0f,  0.0f ), # 0
			glm.vec2( 1.0f,  1.0f ), # 1
			glm.vec2( 0.0f,  1.0f ), # 2
			glm.vec2( 0.0f,  0.0f )  # 3
		]
		*/
	
	// *--------*
	// |\      /|
	// | *----* |
	// | |    | |
	// | *----* |
	// |/      \|
	// *--------*
	
	// 0--------1
	//  \      /
	//   3----2 
	//       
	//   5----6 
	//  /      \
	// 4--------7
	
	// 14------13
	// |        |
	// | 9---10 |
	// | |    | |
	// | 8---11 |
	// |        |
	// 15------12
	
	// 17       22
	// |\      /|
	// | 18   21|
	// | |    | |
	// | 19   20|
	// |/      \|
	// 16      23
	
	/* C++11 needed here:
		normals =
		[
			glm.vec3( 0.0f,  1.0f,  0.0f), # 0
			glm.vec3( 0.0f,  1.0f,  0.0f), # 1
			glm.vec3( 0.0f,  1.0f,  0.0f), # 2
			glm.vec3( 0.0f,  1.0f,  0.0f), # 3
			
			glm.vec3( 0.0f,  -1.0f,  0.0f), # 0
			glm.vec3( 0.0f,  -1.0f,  0.0f), # 1
			glm.vec3( 0.0f,  -1.0f,  0.0f), # 2
			glm.vec3( 0.0f,  -1.0f,  0.0f), # 3

			glm.vec3( 0.0f,  0.0f,  -1.0f), # 0
			glm.vec3( 0.0f,  0.0f,  -1.0f), # 1
			glm.vec3( 0.0f,  0.0f,  -1.0f), # 2
			glm.vec3( 0.0f,  0.0f,  -1.0f), # 3

			glm.vec3( 0.0f,  0.0f,  1.0f), # 0
			glm.vec3( 0.0f,  0.0f,  1.0f), # 1
			glm.vec3( 0.0f,  0.0f,  1.0f), # 2
			glm.vec3( 0.0f,  0.0f,  1.0f), # 3

			glm.vec3( -1.0f,  0.0f,  0.0f), # 0
			glm.vec3( -1.0f,  0.0f,  0.0f), # 1
			glm.vec3( -1.0f,  0.0f,  0.0f), # 2
			glm.vec3( -1.0f,  0.0f,  0.0f), # 3

			glm.vec3( 1.0f,  0.0f,  0.0f), # 0
			glm.vec3( 1.0f,  0.0f,  0.0f), # 1
			glm.vec3( 1.0f,  0.0f,  0.0f), # 2
			glm.vec3( 1.0f,  0.0f,  0.0f) # 3
		]

		
		
		indices =
		[
			#roof
			0, 1, 2,
			0, 2, 3,
			
			#floor
			4, 5, 6, 
			4, 6, 7, 
			
			#back
			8, 9, 10,
			8, 10, 11,

			#front
			12, 13, 14,
			12, 14, 15,

			#left
			16, 17, 18,
			16, 18, 19,

			#right
			20, 21, 22,
			20, 22, 23
		]
		*/
	
	//The visual studio 2012 version:
	
	vertices.emplace_back( - boxSize, boxSize, boxSize); // 0
	vertices.emplace_back(boxSize, boxSize, boxSize); // 1
	vertices.emplace_back(boxSize, boxSize,  - boxSize); // 2
	vertices.emplace_back( - boxSize, boxSize,  - boxSize); // 3
	vertices.emplace_back( - boxSize,  - boxSize, boxSize); // 4
	vertices.emplace_back( - boxSize,  - boxSize,  - boxSize); // 5
	vertices.emplace_back(boxSize,  - boxSize,  - boxSize); // 6
	vertices.emplace_back(boxSize,  - boxSize, boxSize); // 7
	vertices.emplace_back( - boxSize,  - boxSize,  - boxSize); // 8
	vertices.emplace_back( - boxSize, boxSize,  - boxSize); // 9
	vertices.emplace_back(boxSize, boxSize,  - boxSize); // 10
	vertices.emplace_back(boxSize,  - boxSize,  - boxSize); // 11
	vertices.emplace_back(boxSize,  - boxSize, boxSize); // 12
	vertices.emplace_back(boxSize, boxSize, boxSize); // 13
	vertices.emplace_back( - boxSize, boxSize, boxSize); // 14
	vertices.emplace_back( - boxSize,  - boxSize, boxSize); // 15
	vertices.emplace_back( - boxSize,  - boxSize, boxSize); // 16
	vertices.emplace_back( - boxSize, boxSize, boxSize); // 17
	vertices.emplace_back( - boxSize, boxSize,  - boxSize); // 18
	vertices.emplace_back( - boxSize,  - boxSize,  - boxSize); // 19
	vertices.emplace_back(boxSize,  - boxSize,  - boxSize); // 20
	vertices.emplace_back(boxSize, boxSize,  - boxSize); // 21
	vertices.emplace_back(boxSize, boxSize, boxSize); // 22
	vertices.emplace_back(boxSize,  - boxSize, boxSize); // 23
	
	uvs.emplace_back(1.0f, 0.0f); // 0
	uvs.emplace_back(1.0f, 1.0f); // 1
	uvs.emplace_back(0.0f, 1.0f); // 2
	uvs.emplace_back(0.0f, 0.0f); // 3
	uvs.emplace_back(1.0f, 0.0f); // 0
	uvs.emplace_back(1.0f, 1.0f); // 1
	uvs.emplace_back(0.0f, 1.0f); // 2
	uvs.emplace_back(0.0f, 0.0f); // 3
	uvs.emplace_back(1.0f, 0.0f); // 0
	uvs.emplace_back(1.0f, 1.0f); // 1
	uvs.emplace_back(0.0f, 1.0f); // 2
	uvs.emplace_back(0.0f, 0.0f); // 3
	uvs.emplace_back(1.0f, 0.0f); // 0
	uvs.emplace_back(1.0f, 1.0f); // 1
	uvs.emplace_back(0.0f, 1.0f); // 2
	uvs.emplace_back(0.0f, 0.0f); // 3
	uvs.emplace_back(1.0f, 0.0f); // 0
	uvs.emplace_back(1.0f, 1.0f); // 1
	uvs.emplace_back(0.0f, 1.0f); // 2
	uvs.emplace_back(0.0f, 0.0f); // 3
	uvs.emplace_back(1.0f, 0.0f); // 0
	uvs.emplace_back(1.0f, 1.0f); // 1
	uvs.emplace_back(0.0f, 1.0f); // 2
	uvs.emplace_back(0.0f, 0.0f); // 3
	
	// *--------*
	// |\      /|
	// | *----* |
	// | |    | |
	// | *----* |
	// |/      \|
	// *--------*
	
	// 0--------1
	//  \      /
	//   3----2 
	//       
	//   5----6 
	//  /      \
	// 4--------7
	
	// 14------13
	// |        |
	// | 9---10 |
	// | |    | |
	// | 8---11 |
	// |        |
	// 15------12
	
	// 17       22
	// |\      /|
	// | 18   21|
	// | |    | |
	// | 19   20|
	// |/      \|
	// 16      23
	
	normals.emplace_back(0.0f, 1.0f, 0.0f); // 0
	normals.emplace_back(0.0f, 1.0f, 0.0f); // 1
	normals.emplace_back(0.0f, 1.0f, 0.0f); // 2
	normals.emplace_back(0.0f, 1.0f, 0.0f); // 3
	normals.emplace_back(0.0f,  - 1.0f, 0.0f); // 0
	normals.emplace_back(0.0f,  - 1.0f, 0.0f); // 1
	normals.emplace_back(0.0f,  - 1.0f, 0.0f); // 2
	normals.emplace_back(0.0f,  - 1.0f, 0.0f); // 3
	normals.emplace_back(0.0f, 0.0f,  - 1.0f); // 0
	normals.emplace_back(0.0f, 0.0f,  - 1.0f); // 1
	normals.emplace_back(0.0f, 0.0f,  - 1.0f); // 2
	normals.emplace_back(0.0f, 0.0f,  - 1.0f); // 3
	normals.emplace_back(0.0f, 0.0f, 1.0f); // 0
	normals.emplace_back(0.0f, 0.0f, 1.0f); // 1
	normals.emplace_back(0.0f, 0.0f, 1.0f); // 2
	normals.emplace_back(0.0f, 0.0f, 1.0f); // 3
	normals.emplace_back( - 1.0f, 0.0f, 0.0f); // 0
	normals.emplace_back( - 1.0f, 0.0f, 0.0f); // 1
	normals.emplace_back( - 1.0f, 0.0f, 0.0f); // 2
	normals.emplace_back( - 1.0f, 0.0f, 0.0f); // 3
	normals.emplace_back(1.0f, 0.0f, 0.0f); // 0
	normals.emplace_back(1.0f, 0.0f, 0.0f); // 1
	normals.emplace_back(1.0f, 0.0f, 0.0f); // 2
	normals.emplace_back(1.0f, 0.0f, 0.0f); // 3
	
	
	//roof
	indices.push_back(0); // line: 357
	indices.push_back(1); // line: 358
	indices.push_back(2); // line: 359
	indices.push_back(0); // line: 360
	indices.push_back(2); // line: 361
	indices.push_back(3); // line: 362
	
	//floor
	indices.push_back(4); // line: 365
	indices.push_back(5); // line: 366
	indices.push_back(6); // line: 367
	indices.push_back(4); // line: 368
	indices.push_back(6); // line: 369
	indices.push_back(7); // line: 370
	
	//back
	indices.push_back(8); // line: 373
	indices.push_back(9); // line: 374
	indices.push_back(10); // line: 375
	indices.push_back(8); // line: 376
	indices.push_back(10); // line: 377
	indices.push_back(11); // line: 378
	
	//front
	indices.push_back(12); // line: 381
	indices.push_back(13); // line: 382
	indices.push_back(14); // line: 383
	indices.push_back(12); // line: 384
	indices.push_back(14); // line: 385
	indices.push_back(15); // line: 386
	
	//left
	indices.push_back(16); // line: 389
	indices.push_back(17); // line: 390
	indices.push_back(18); // line: 391
	indices.push_back(16); // line: 392
	indices.push_back(18); // line: 393
	indices.push_back(19); // line: 394
	
	//right
	indices.push_back(20); // line: 397
	indices.push_back(21); // line: 398
	indices.push_back(22); // line: 399
	indices.push_back(20); // line: 400
	indices.push_back(22); // line: 401
	indices.push_back(23); // line: 402
	
	std::cout<<"size of: vertices: "<<vertices.size()<<" size of indices: "<<indices.size()<<"\n";
}

void Mesh::createVBOs()
{
	std::cout<<"Mesh.createVBOs"<<"\n"; // line: 409
	
	glGenBuffers(1, &vertexBufferID); // line: 411
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID); // line: 412
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3 ), &vertices[0], GL_STATIC_DRAW); // line: 413
	
	glGenBuffers(1, &uvBufferID); // line: 415
	glBindBuffer(GL_ARRAY_BUFFER, uvBufferID); // line: 416
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2 ), &uvs[0], GL_STATIC_DRAW); // line: 417
	
	glGenBuffers(1, &normalBufferID); // line: 419
	glBindBuffer(GL_ARRAY_BUFFER, normalBufferID); // line: 420
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3 ), &normals[0], GL_STATIC_DRAW); // line: 421
	
	glGenBuffers(1, &indexBufferID); // line: 423
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID); // line: 424
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint16_t ), &indices[0], GL_STATIC_DRAW); // line: 425
	
}

void Mesh::render(uint32_t set_shader_program_id)
{
	glUseProgram(set_shader_program_id); // line: 431
	
	// Get a handle for our buffers
	GLuint vertex_position_id = glGetAttribLocation(set_shader_program_id, "inPosition"); // line: 434
	GLuint vertex_uv_id = glGetAttribLocation(set_shader_program_id, "inUV"); // line: 435
	GLuint vertex_normal_id = glGetAttribLocation(set_shader_program_id, "inNormal"); // line: 436
	
	// vertices
	glEnableVertexAttribArray(vertex_position_id); // line: 439
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID); // line: 440
	glVertexAttribPointer(vertex_position_id, 3, GL_FLOAT, GL_FALSE, 0, 0); // line: 441
	
	//(void*)
	
	// UVs
	glEnableVertexAttribArray(vertex_uv_id); // line: 446
	glBindBuffer(GL_ARRAY_BUFFER, uvBufferID); // line: 447
	glVertexAttribPointer(vertex_uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0); // line: 448
	
	// normals
	glEnableVertexAttribArray(vertex_normal_id); // line: 451
	glBindBuffer(GL_ARRAY_BUFFER, normalBufferID); // line: 452
	glVertexAttribPointer(vertex_normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0); // line: 453
	
	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID); // line: 456
	
	glDrawElements(GL_TRIANGLES, (GLsizei )indices.size(), GL_UNSIGNED_SHORT, 0); // line: 458
	
	glDisableVertexAttribArray(vertex_position_id); // line: 460
	glDisableVertexAttribArray(vertex_uv_id); // line: 461
	glDisableVertexAttribArray(vertex_normal_id);
}



