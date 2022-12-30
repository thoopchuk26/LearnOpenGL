// LearnOpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#define STB_IMAGE_IMPLEMENTATION    
#include "stb_image.h"


float verticesTex[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

float vertices[] = {
    -0.5f, -0.5f, -0.5f,  
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,  
     0.5f,  0.5f, -0.5f, 
    -0.5f,  0.5f, -0.5f,  
    -0.5f, -0.5f, -0.5f, 

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f, 
     0.5f,  0.5f,  0.5f,  
     0.5f,  0.5f,  0.5f,  
    -0.5f,  0.5f,  0.5f,  
    -0.5f, -0.5f,  0.5f, 

    -0.5f,  0.5f,  0.5f, 
    -0.5f,  0.5f, -0.5f,  
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,  
    -0.5f, -0.5f,  0.5f, 
    -0.5f,  0.5f,  0.5f,  

     0.5f,  0.5f,  0.5f,  
     0.5f,  0.5f, -0.5f, 
     0.5f, -0.5f, -0.5f,  
     0.5f, -0.5f, -0.5f,  
     0.5f, -0.5f,  0.5f,  
     0.5f,  0.5f,  0.5f,  

    -0.5f, -0.5f, -0.5f,  
     0.5f, -0.5f, -0.5f,  
     0.5f, -0.5f,  0.5f,  
     0.5f, -0.5f,  0.5f,  
    -0.5f, -0.5f,  0.5f, 
    -0.5f, -0.5f, -0.5f,  

    -0.5f,  0.5f, -0.5f,  
     0.5f,  0.5f, -0.5f,  
     0.5f,  0.5f,  0.5f, 
     0.5f,  0.5f,  0.5f,  
    -0.5f,  0.5f,  0.5f,  
    -0.5f,  0.5f, -0.5f
};


//screen dimensions variables
int width = 1280, height = 720;

Camera camera(glm::vec3(0.0f, 10.0f, 10.0f));

//mouse camera control variables
bool firstMouse = true;
float lastX = width / 2.0f;
float lastY = height / 2.0f;

//frame timing variables
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f;
float currentFrame = 0.0f;
unsigned int counter = 0;

//window size change input
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

//keyboard input
void processInput(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyboard(RIGHT, deltaTime);
}

//mouse movement controls
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn){
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse){
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.processMouseMovement(xoffset, yoffset, GL_TRUE);
}

//scroll wheel controls
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    camera.processMouseScroll(static_cast<float>(yoffset));
}

int main(){
    //glfw setup, initialize and set context for what version and profile we're using, 3.3 and CORE
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //create a window and error check on it
    GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //load GLAD and error check on it
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //set the viewport for openGL, first two inputs are top corner of window, second two inputs are bottom right of window
    glViewport(0, 0, width, height);

    //make sure the window is resized based on the user altering it
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    stbi_set_flip_vertically_on_load(true);

    Shader asteroidShader("C:/School/C++ Projects/LearnOpenGL/vertexShader.txt", "C:/School/C++ Projects/LearnOpenGL/fragmentShader.txt");
    Shader planetShader("C:/School/C++ Projects/LearnOpenGL/planetVertexShader.txt", "C:/School/C++ Projects/LearnOpenGL/planetFragmentShader.txt");

    Model asteroid("C:/School/C++ Projects/LearnOpenGL/resources/block/block.obj");
    Model planet("C:/School/C++ Projects/LearnOpenGL/resources/planet/planet.obj");

    unsigned int chunkSize = 65536;
    glm::mat4* chunk;
    int count = 0;
    chunk = new glm::mat4[chunkSize];
    for (int y = 0; y > -256; y--){
        for (int z = -8; z < 8; z++) {
            for (int x = -8; x < 8; x++) {
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(x, y, z));
                model = glm::scale(model, glm::vec3(0.5f));
                chunk[count++] = model;
            }
        }
    }

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, chunkSize * sizeof(glm::mat4), &chunk[0], GL_STATIC_DRAW);

    // set transformation matrices as an instance vertex attribute (with divisor 1)
    // note: we're cheating a little by taking the, now publicly declared, VAO of the model's mesh(es) and adding new vertexAttribPointers
    // normally you'd want to do this in a more organized fashion, but for learning purposes this will do.
    // -----------------------------------------------------------------------------------------------------------------------------------
    for (unsigned int i = 0; i < asteroid.meshes.size(); i++){
        unsigned int VAO = asteroid.meshes[i].VAO;
        glBindVertexArray(VAO);
        // set attribute pointers for matrix (4 times vec4)
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
        glEnableVertexAttribArray(5);
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
        glEnableVertexAttribArray(6);
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));

        glVertexAttribDivisor(3, 1);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);
        glVertexAttribDivisor(6, 1);

        glBindVertexArray(0);
    }

    //main game loop, all the rendering and gameplay is happening in here
    while (!glfwWindowShouldClose(window)) {
        //frame timing
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        counter++;
        if (deltaTime >= 1.0f / 30.0f) {
            std::string fps = std::to_string((1.0f / deltaTime) * counter);
            std::string ms = std::to_string((deltaTime / counter) * 1000);
            std::string fpsCounter = "LearnOpenGL - " + fps + " FPS / " + ms + " ms";
            glfwSetWindowTitle(window, fpsCounter.c_str());
            lastFrame = currentFrame;
            counter = 0;
        }

        //basic input processing for now
        processInput(window);
        
        //clear the screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // bind textures on corresponding texture units
       /*shader.use();
        shader.setInt("texture1", 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);*/

        //asteroid stuff
        // configure transformation matrices
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 1000.0f);
        glm::mat4 view = camera.getViewMatrix();

        asteroidShader.use();
        asteroidShader.setMat4("projection", projection);
        asteroidShader.setMat4("view", view);

        /*planetShader.use();
        planetShader.setMat4("projection", projection);
        planetShader.setMat4("view", view);*/

        //// draw planet
        /*glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -3.0f, 0.0f));
        model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
        planetShader.setMat4("model", model);
        planet.Draw(planetShader);*/

        //draw meteorites
        asteroidShader.use();
        asteroidShader.setInt("texture_diffuse1", 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, asteroid.texturesLoaded[0].ID); // note: we also made the textures_loaded vector public (instead of private) from the model class.
        for (unsigned int i = 0; i < asteroid.meshes.size(); i++) {
            glBindVertexArray(asteroid.meshes[i].VAO);
            glDrawElementsInstanced(GL_TRIANGLES, static_cast<unsigned int>(asteroid.meshes[i].Indices.size()), GL_UNSIGNED_INT, 0, chunkSize);
            glBindVertexArray(0);
        }

        //swap the front and back buffers and poll for events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /*glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);*/
    glfwTerminate();

    return 0;
}
