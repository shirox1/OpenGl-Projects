#include <stdio.h>
#include <stdlib.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

int main()
{
  GLFWwindow* window;

  //init GLFW
  if(!glfwInit())
  {
    fprintf(stderr, "Failed to initialize GLFW");
    return -1;
  }

  /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
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

