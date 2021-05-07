#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "main.h"
#include "events.h"

namespace OpenGLGLFWGLADTemplateTesting
{
	TEST_CLASS(OpenGLGLFWGLADTemplateTesting)
	{
	public:

		TEST_METHOD(CreateGLFWWindow)
		{
			int window_width = 0,
				window_height = 0;

			GLFWwindow* window = create_glfw_window();
			Assert::IsNotNull(window, L"Window not created");

			glfwGetFramebufferSize(window, &window_width, &window_height);
			Assert::AreEqual(GLFW_WINDOW_WIDTH, window_width, L"Unexpected window width");
			Assert::AreEqual(GLFW_WINDOW_HEIGHT, window_height, L"Unexpected window height");

			glfwTerminate();
		}

		TEST_METHOD(InitGlad)
		{
			GLFWwindow* window = create_glfw_window();
			Assert::IsNotNull(window, L"See test: CreateGLFWWindow");

			Assert::AreEqual(0, init_glad(), L"GLAD failed to initialize");

			glfwTerminate();
		}
	};
}

