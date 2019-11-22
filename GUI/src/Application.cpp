#include "Engine.h"

int main(int argc, char** argv)
{
	try
	{
		if (!glfwInit())
		{
			Engine::printErr("Unable to initialize glfw!");
		}
	}
	catch (std::runtime_error e)
	{
		Engine::handleException(e);
		return -1;
	}

	GLFWwindow* window;
	window = glfwCreateWindow(1366, 768, "SKFB e-Library Server Application", NULL, NULL);
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}