#include "Core.h"

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		Core::printErr("GLFW could not be initialized");
		return -1;
	}
	else
	{
		Core::printLn("GLFW initialized...");
	}

	GLFWwindow* window;
	window = glfwCreateWindow(1366, 768, "SKFB e-Library Server", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!glewInit())
	{
		Core::printErr("GLEW could not be initialized");
		return -1;
	}
	else
	{
		Core::printLn("GLEW initialized...");
	}

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130");
	ImGui::StyleColorsDark();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();

		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}
}