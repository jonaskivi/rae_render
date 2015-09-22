// this file is automatically created from Rae programming language module:
///Users/joonaz/Dropbox/jonas/2015/ohjelmointi/rae_render/src/cpp/rae/3d/Engine
#include "Engine.hpp"
; // line: 2

#include "rae/3d/Entity.hpp"

#include "rae/3d/Shader.hpp"

#include "rae/3d/Mesh.hpp"

#include "GL/glew.hpp"

#include "glm/glm.hpp"


//@end
; // line: 18

// if we don't have bindings, we can just quickly use functions and classes by using the extern keyword.




//class Engine

Engine::~Engine()
{ //-------------Rae boilerplate code-------------
	_rae_unlink_all();
	//-------------end Rae boilerplate code-------------


}

Engine::Engine(GLFWwindow* set_window)
: m_isRunning(true)
, m_previousTime(0.0)
, m_currentTime(0.0)
, m_currentAngle(0.0f)
, modelViewMatrixUni(0)
, viewMatrixUni(0)
, modelMatrixUni(0)
, lightPositionUni(0)
, textureUni(0)
, m_windowWidth(640)
, m_windowHeight(480)
{//-------------Rae boilerplate code-------------
	_rae_link_list = nullptr;
	//-------------end Rae boilerplate code-------------


	m_window = set_window; // line: 40
	
	shader.loadShader("shaders/basic.vert", "shaders/basic.frag"); // line: 42
	
	modelViewMatrixUni = glGetUniformLocation(shader.shaderID, "modelViewProjectionMatrix"); // line: 44
	viewMatrixUni = glGetUniformLocation(shader.shaderID, "viewMatrix"); // line: 45
	modelMatrixUni = glGetUniformLocation(shader.shaderID, "modelMatrix"); // line: 46
	
	shader.use(); // line: 48
	
	lightPositionUni = glGetUniformLocation(shader.shaderID, "lightPosition_worldspace"); // line: 50
	textureUni = glGetUniformLocation(shader.shaderID, "textureSampler"); // line: 51
	
	mesh.generateBox(); // line: 53
	mesh.createVBOs(); // line: 54
	
	m_currentTime = glfwGetTime(); // line: 56
	m_previousTime = m_currentTime;
}

void Engine::run()
{
	m_isRunning = true; // line: 62
	
	for (; m_isRunning == true; )
	{
		if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			m_isRunning = false;
		}
		
		m_currentTime = glfwGetTime(); // line: 71
		double deltaTime = m_currentTime - m_previousTime; // line: 72
		m_previousTime = m_currentTime; // line: 73
		
		glViewport(0, 0, m_windowWidth, m_windowHeight); // line: 75
		
		glClearColor(0.3f, 0.3f, 0.3f, 0.0f); // line: 77
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // line: 78
		
		glDisable(GL_BLEND); // line: 80
		glEnable(GL_DEPTH_TEST); // line: 81
		
		// TODO modelmatrix
		//glm::mat4& modelMatrix = transform->modelMatrix();
		
		float m_fieldOfView = 70.0f; // line: 86
		int32_t m_windowPixelWidth = 1920; // line: 87
		int32_t m_windowPixelHeight = 1080; // line: 88
		glm::vec3 m_cameraPosition(0.0f, 0.0f, 0.0f); // line: 89
		
		float m_yawAngle = 0.0f; // line: 91
		float m_pitchAngle = 0.0f; // line: 92
		
		glm::vec3 up(0.0f, 1.0f, 0.0f); // line: 94
		glm::vec3 direction(
		cos(m_pitchAngle) * sin(m_yawAngle), 
		sin(m_pitchAngle), 
		cos(m_pitchAngle) * cos(m_yawAngle)
		); // line: 99
		
		// Right vector
		glm::vec3 right = glm::vec3 
(
		sin(m_yawAngle - 3.141f / 2.0f), 
		0, 
		cos(m_yawAngle - 3.141f / 2.0f)
		); // line: 107
		
		glm::mat4 m_projectionMatrix = glm::perspective(m_fieldOfView, static_cast<float>(m_windowPixelWidth) / static_cast<float>(m_windowPixelHeight), 0.1f, 500.0f);
		
		glm::mat4 m_viewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + direction, up); // line: 111
		
		glm::vec3 lightPos = glm::vec3 (2.0f, 0.0f, 0.0f); // line: 113
		glUniform3f(lightPositionUni, lightPos.x, lightPos.y, lightPos.z); // line: 114
		
		/*
			# Bind texture in Texture Unit 0
			if( material != nullptr )
			{
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, material->textureID());
				# Set textureSampler to use Texture Unit 0
				glUniform1i(textureUni, 0);
			}
			else glBindTexture(GL_TEXTURE_2D, 0);
			*/
		
		m_currentAngle += 10.0f * static_cast<float>(deltaTime); // line: 128
		if (m_currentAngle > 360.0f)
		m_currentAngle = 0.0f; // line: 130
		
		float x_coord =  - 9.0f;
		float y_coord =  - 4.0f;
		float z_coord = 10.0f;
		
		for (int32_t i = 0; i < 10; ++i)
		{
			for (int32_t j = 0; j < 10; ++j)
			{
				//glm.mat4 modelMatrix = glm.translate(glm.mat4(1.0f), glm.vec3(0.0f, 0.0f, 3.0f))
				//modelMatrix = glm.rotate(modelMatrix, m_currentAngle, glm.vec3(0.6f, 0.7f, 0.0f))
				glm::mat4 modelMatrix = glm::translate(glm::mat4 (1.0f), glm::vec3 (x_coord, y_coord, z_coord)); // line: 142
				modelMatrix = glm::rotate(modelMatrix, m_currentAngle, glm::vec3 (0.6f, 0.7f, 0.0f)); // line: 143
				
				// The model-view-projection matrix
				glm::mat4 combinedMatrix = m_projectionMatrix * m_viewMatrix * modelMatrix; // line: 146
				
				// TODO this will be difficult. Getting a const float* from a two dimensional array, which is actually glm::mat4
				// with operator[] overloaded.
				//glUniformMatrix4fv(modelViewMatrixUni, 1, GL_FALSE, combinedMatrix[0][0]);
				//glUniformMatrix4fv(modelMatrixUni, 1, GL_FALSE, modelMatrix[0][0]);
				//glUniformMatrix4fv(viewMatrixUni, 1, GL_FALSE, m_viewMatrix[0][0]);
				
				//@cpp_src


					glUniformMatrix4fv(modelViewMatrixUni, 1, GL_FALSE, &combinedMatrix[0][0]);
					glUniformMatrix4fv(modelMatrixUni, 1, GL_FALSE, &modelMatrix[0][0]);
					glUniformMatrix4fv(viewMatrixUni, 1, GL_FALSE, &m_viewMatrix[0][0]);

					//@end
; // line: 160
				
				mesh.render(shader.shaderID); // line: 162
				
				x_coord += 2.0f;
			}
			y_coord += 2.0f;
			x_coord =  - 9.0f;
			z_coord += 2.0f;
		}
		
		// render one more cube in the middle
		glm::mat4 modelMatrix = glm::translate(glm::mat4 (1.0f), glm::vec3 (0.0f, 0.0f, 3.0f)); // line: 172
		modelMatrix = glm::rotate(modelMatrix, m_currentAngle, glm::vec3 (0.6f, 0.7f, 0.0f)); // line: 173
		
		// The model-view-projection matrix
		glm::mat4 combinedMatrix = m_projectionMatrix * m_viewMatrix * modelMatrix; // line: 176
		
		//@cpp_src


			glUniformMatrix4fv(modelViewMatrixUni, 1, GL_FALSE, &combinedMatrix[0][0]);
			glUniformMatrix4fv(modelMatrixUni, 1, GL_FALSE, &modelMatrix[0][0]);
			glUniformMatrix4fv(viewMatrixUni, 1, GL_FALSE, &m_viewMatrix[0][0]);

			//@end
; // line: 184
		
		mesh.render(shader.shaderID); // line: 186
		
		glfwSwapBuffers(m_window); // line: 188
		glfwPollEvents();
	}
}

void Engine::update(double time, double delta_time)
{
	
}

void Engine::osEventCloseWindow()
{
	m_isRunning = false;
}

void Engine::osEventResizeWindow(int32_t width, int32_t height)
{
	std::cout<<"osEventResizeWindow TODO"<<"\n"; // line: 205
	//m_renderSystem.osEventResizeWindow(width, height)
	m_windowWidth = width; // line: 207
	m_windowHeight = height;
}

void Engine::osEventResizeWindowPixels(int32_t width, int32_t height)
{
	std::cout<<"osEventResizeWindowPixels TODO"<<"\n"; // line: 213
	//m_renderSystem.osEventResizeWindowPixels(width, height)
	m_windowWidth = width; // line: 215
	m_windowHeight = height;
}

void Engine::onMouseButtonPress(int32_t set_button, double x, double y)
{
	std::cout<<"mouse press: x: "<<x<<" y: "<<y<<"\n"; // line: 221
	
	/*TODO
		# Have to scale input on retina screens:
		x = x * m_renderSystem->screenPixelRatio();
		y = y * m_renderSystem->screenPixelRatio();
		
		unsigned char res[4];

		m_renderSystem->renderPicking( m_objectFactory.entities() );

		#glGetIntegerv(GL_VIEWPORT, viewport);
		glReadPixels((int)x, m_renderSystem->windowPixelHeight() - (int)y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &res);

		# Decode entity ID from red and green channels!
		int pickedID = res[0] + (res[1] * 256);

		#m_renderSystem->m_pickedString = std::to_string(pickedID) + " is " + std::to_string(res[0]) + " and " + std::to_string(res[1]);

		if( pickedID == 0)
		{
			# do nothing, it's the background.
		}
		else if( pickedID == 1)
		{
			createRandomCubeEntity(); # Hmm, we have no proper event handling yet, so entity 1 is the Add Object button!
		}
		else
		{
			m_objectFactory.destroyEntity( pickedID );
		}
		*/
}




