#include "Engine.h"

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		Engine::printLine("Unable to initialize glfw!");
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