// this file is automatically created from Rae programming language module:
///home/joonaz/2015/ohjelmointi/rae_render/src/cpp/rae/3d/Shader
#include "Shader.hpp"
; // line: 2

//@end
; // line: 8

//#include <string.h>

#include "GL/glew.hpp"



//class Shader

Shader::~Shader()
{ //-------------Rae boilerplate code-------------
	_rae_unlink_all();
	//-------------end Rae boilerplate code-------------


}

Shader::Shader()
: shaderID(0)
{ //-------------Rae boilerplate code-------------
	_rae_link_list = nullptr;
	//-------------end Rae boilerplate code-------------


}

Shader::Shader(std::string vertex_file_path, std::string fragment_file_path)
: shaderID(0)
{//-------------Rae boilerplate code-------------
	_rae_link_list = nullptr;
	//-------------end Rae boilerplate code-------------


	loadShader(vertex_file_path, fragment_file_path);
}

void Shader::use()
{
	glUseProgram(shaderID);
}

uint32_t Shader::loadShader(std::string vertex_file_path, std::string fragment_file_path)
{
	//@cpp

	// Create the shaders
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string vertexShaderCode;
	std::ifstream vertexShaderStream(vertex_file_path, std::ios::in);
	if(vertexShaderStream.is_open())
	{
		std::string Line = "";
		while(getline(vertexShaderStream, Line))
			vertexShaderCode += "\n" + Line;
		vertexShaderStream.close();
	}
	else
	{
		std::cout << "Can't open shader: "<< vertex_file_path << "\n";
		getchar();
		return shaderID = 0;
	}

	// Read the Fragment Shader code from the file
	std::string fragmentShaderCode;
	std::ifstream fragmentShaderStream(fragment_file_path, std::ios::in);
	if( fragmentShaderStream.is_open() )
	{
		std::string Line = "";
		while(getline(fragmentShaderStream, Line))
			fragmentShaderCode += "\n" + Line;
		fragmentShaderStream.close();
	}
	else
	{
		std::cout << "Can't open shader: "<< fragment_file_path << "\n";
		getchar();
		return shaderID = 0;
	}

	GLint result = GL_FALSE;
	int infoLogLength;

	// Compile Vertex Shader
	std::cout << "Compiling vertex shader: " << vertex_file_path << "\n";
	char const * vertexSourcePointer = vertexShaderCode.c_str();
	glShaderSource(vertexShaderID, 1, &vertexSourcePointer , NULL);
	glCompileShader(vertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if( infoLogLength > 1 )
	{
		std::cout<<"Error in shader: "<<vertex_file_path << " infoLogLength: " << infoLogLength <<"\n";
		std::vector<char> vertexShaderErrorMessage(infoLogLength+1);
		glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
		std::cout << &vertexShaderErrorMessage[0] << "\n";
		getchar();
		return shaderID = 0;
	}

	// Compile Fragment Shader
	std::cout << "Compiling fragment shader: " << fragment_file_path << "\n";
	char const * fragmentSourcePointer = fragmentShaderCode.c_str();
	glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer , NULL);
	glCompileShader(fragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if( infoLogLength > 1 )
	{
		std::cout<<"Error in shader: "<<fragment_file_path << "\n";
		std::vector<char> fragmentShaderErrorMessage(infoLogLength+1);
		glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
		std::cout << &fragmentShaderErrorMessage[0] << "\n";
		getchar();
		return shaderID = 0;
	}

	// Link the program
	std::cout << "Linking shader program\n";
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	// Check the program
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if( infoLogLength > 1 )
	{
		std::cout<<"Error in shader: "<<vertex_file_path << " or "<<fragment_file_path << "\n";
		std::vector<char> programErrorMessage(infoLogLength+1);
		glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
		std::cout << &programErrorMessage[0] << "\n";
		getchar();
		return shaderID = 0;
	}

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return shaderID = programID;
//@end
;
}




