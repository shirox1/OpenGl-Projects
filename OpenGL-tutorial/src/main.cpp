#include <stdio.h>
#include <stdlib.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if(key == GLFW_KEY_A && action == GLFW_PRESS)
    printf("a has been pressed\n");
  else if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
  // initialize GLFW
  if(!glfwInit())
  {
    fprintf(stderr, "Failed to initialize GLFW.\n");
    return -1;
  }

  // Create a windowed mode window and its OpenGL context
  GLFWwindow* window;
  window = glfwCreateWindow(1024, 768, "Hello World", NULL, NULL);
  if(!window)
  {
    fprintf(stderr, "Failed to open GLFW window.\n");
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window); //initialize GLEW
  glewExperimental = true; // Needed in core profile

  // initilize glew
  if(glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW.\n");
    return -1;
  }

  glfwSetKeyCallback(window, key_callback);

  /* Loop until the user closes the window */
  while(!glfwWindowShouldClose(window))
  {
    /* Render here */

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

