#pragma once
#include <iostream>
#include <exception>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Core
{
	template<typename T>
	static void printLn(const T& string);

	template<typename T>
	static void print(const T& string);

	template<typename T>
	static void printErr(const T& string);

	template<typename T>
	static void handleException(const T& exception);
}

#include "Core.tpp"