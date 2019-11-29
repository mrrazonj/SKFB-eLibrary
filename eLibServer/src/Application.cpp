#include "Registration.h"

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

	if (glewInit() != GLEW_OK)
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

	bool isRegistrationFormOpen = false;
	bool isDatabaseViewOpen = false;
	bool isAdminToolsOpen = false;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		
		{
			ImGui::Begin("SKFB e-Library Server Tools");
			if (ImGui::Button("Register new user", ImVec2(200.0f, 25.0f)))
			{
				isRegistrationFormOpen = true;
			}
			if (isRegistrationFormOpen)
			{
				Registration::OpenRegistrationForm(isRegistrationFormOpen);
			}

			ImGui::End();
		}


		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}