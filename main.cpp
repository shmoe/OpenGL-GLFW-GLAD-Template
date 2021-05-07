/**
 * Griffin Nelson
 * 5/6/2021
 *
 * "main.cpp" - Contains the "main" function, the initial entry point for code execution,
 *		which uses GLFW to initialize a OpenGL context and then the standard OpenGL functions
 *		mapped by GLAD to do operations on said context.
 */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/**
 * Forward declares all functions in "main.cpp" for unit testing
 * purposes.
 */
#include "main.h"

/**
 * Contains callbacks for GLFW events.
 */
#include "events.h"

/**
 * main(int argc, char* argv[]) - Initializes the necessary libraries for ppening an OpenGL context and houses the
 *	main render loop for the created GLFW window.
 * 
 *		argc - the number of arguements used to launch this program, including the binary name
 * 
 *		argv - an ordered list of the arguements used to launch this program, starting with the binary name
 */
int main(int argc, char* argv[]) {
	GLFWwindow* window;	// Main render window

	/**
	* Initialize GLFW and create the main render window. Safely end execution
	* on failure.
	*/
	if (!(window = create_glfw_window())) {
		return -1;			// Safely end execution with a bad value
	}

	/**
	 * Bind new window to the OpenGL 3.3 context
	 */
	glfwMakeContextCurrent(window);

	/**
	 * Initialize GLAD, which manages function pointers for OpenGL and allows
	 * us to ignore ignore implementation specific details and just use the
	 * OpenGL API to utilize the OpenGL conext. If initilization fails, log to
	 * stderr and terminate.
	 */
	if (!init_glad()) {
		glfwTerminate();	// Safely terminate GLFW
		return -1;			// Safely end execution with a bad value
	}

	/**
	 * Tell the context the portion of the rendering window to draw to (in this
	 * case the full window.)
	 * 
	 * Also set clear color
	 */
	glViewport(0, 0, GLFW_WINDOW_WIDTH, GLFW_WINDOW_HEIGHT);	// Set viewport dimensions to top-left (0,0) through bottom-right (800,600) corners
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);						// Set clear color to black

	/**
	 * Set callback functions.
	 */
	glfwSetFramebufferSizeCallback(window, events::framebuffer_size_callback);

	/**
	 * Main rendering loop
	 */
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();				// Check to see if any events were triggered and call
											// the corresponding callback functions

		glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to current clear color.
		glfwSwapBuffers(window);		// Swaps front and back framebuffers (output to screen)
	}

	/**
	 * End execution
	 */
	glfwTerminate();	// Safely terminate GLFW
	return 0;			// End execution with a good value
}

/**
 * Initialize GLFW and create render window with the newly created GL context.
 * Return nullptr on failure.
 */
GLFWwindow* create_glfw_window() {
	glfwInit();	// Initialize the GLFW library

	/**
	 * Tell GLFW to open a window with OpenGL 3.3 in the Core Profile mode
	 */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, LOCAL_GL_VERSION[0]);	// Tell GLFW the major value of the OpenGL context we wish the new window to have
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, LOCAL_GL_VERSION[1]);	// Tell GLFW the minor value of the OpenGL context we wish the new window to hav
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);		// Tell GLFW to open the new window in Core Profile mode

	/**
	 * Tell GLFW to create a window with the above configuration. If window
	 * creation fails, log to stderr and terminate.
	 */
	GLFWwindow* window = glfwCreateWindow(GLFW_WINDOW_WIDTH, GLFW_WINDOW_HEIGHT, "Hellow Window", NULL, NULL);	// Create GLFW window
	if (window == NULL) {
		std::cerr << "Failed to create GLFW window" << std::endl;		// Log failure to stderr
		glfwTerminate();												// Safely terminate GLFW
		return nullptr;														// End execution with a bad value
	}

	return window;
}

/**
 * Initialize GLAD, which manages function pointers for OpenGL and allows
 * us to ignore ignore implementation specific details and just use the
 * OpenGL API to utilize the OpenGL conext. If initilization fails, log to
 * stderr and return -1.
 */
int init_glad() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {	// Bind function glfwGetProcAddress as the GLAD LoadGL Loader
		std::cerr << "Failed to initialize GLAD" << std::endl;	// Log failure to stderr
		return -1;												// Return with a bad value
	}

	return 0;	// Return with a good value
}