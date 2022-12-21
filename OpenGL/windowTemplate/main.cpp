#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include "Vertex.h"

#include "Shader.h"
#include "primitives/triangle.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui.h"

#include "menu/menu.hpp"

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

const char* glsl_version = "#version 150";


uint initTexture(const std::string &path) {
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    if (!data)
        throw std::runtime_error("Failed to load texture: " + path);
    unsigned int textureID;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, // The first argument specifies the texture target; (targets GL_TEXTURE_1D or GL_TEXTURE_3D will not be affected)
        0, // mipmap level for which we want to create a texture
        GL_RGB,  // kind of format we want to store the texture
        width, 
        height, 
        0, // legacy
        GL_RGB, // loaded the image with RGB values (from RAM)
        GL_UNSIGNED_BYTE, // loaded data in ungigned 1 byte format
        data);

    stbi_image_free(data);

    return textureID;
}

uint initVAO() {
    // Generate Vertex Array Object
    unsigned int VAO;

    // Create VAO
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);

    // Generate Vertex Buffers
    unsigned int VBO, EBO;
    // Create VBO buffer
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // Make VBO buffer active


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle_indexes), triangle_indexes, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

    // Determinate vertex data in the VBO for usage in the shader program
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Determinate vertex data in the VBO for usage in the shader program
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // Determinate vertex data in the VBO for usage in the shader program
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    return VAO;
}


glm::mat4 myOwnProjectionMatrix(double near, double far, double fovy, double aspect_ratio) {
    fovy = fovy / 2.0;
    double tg = tan(fovy);
    
    double top_bottom = (tg * near);
    double right_left = (tg * near * aspect_ratio);
    
    glm::mat4 result = glm::mat4(0.0);

    result[0][0] = (double)(near / right_left);
    result[1][1] = (double)(near / top_bottom);

    result[2][2] = (double)(-1.0 * ((far + near) / (double)(far - near)));
    result[3][2] = (double)(-1.0 * near  * 2.0 * far) / (double)(far - near);
    
    result[2][3] = -1;

    return result;
}


// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;

    // check sizeof
    auto vtx_size = sizeof(Vertex);

    if (vtx_size != (sizeof(float) * 8)) {
        std::cout << "Sizes not match! vtx_size:" << vtx_size << ", sizeof(float) * 8: " << sizeof(float) * 8 << std::endl;
        exit(1); 
    }

    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);    

    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }    

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    bool show_demo_window = true;


    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);  
    glViewport(0, 0, width, height);

    auto VAO = initVAO();

    // Init shaders
    Shader vs("shaders/vs.glsl", GL_VERTEX_SHADER);
    Shader fs("shaders/fs.glsl", GL_FRAGMENT_SHADER);
    ShaderProgram shaderProgram(&vs, &fs);

    auto texture1 = initTexture("texture1.png");
    auto texture2 = initTexture("texture2.png");

    shaderProgram.use();
    glEnable(GL_DEPTH_TEST);

    glm::fvec3 rotateVec(0.0f, 0.0f, 0.0f);
    glm::fvec3 translateVec(0.0f, 0.0f, 0.0f);
    float vertex_w = 1.0f;
    // Game loop
    bool useProjectionGLM = false;
    bool useProjectionMyOwn = false;
    bool always_fixed_w = false;
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        /*
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);
        */
        translationWindow(translateVec);
        rotationWindow(rotateVec);
        vertexW_Window(vertex_w);
        projectionUsage(useProjectionGLM, useProjectionMyOwn, always_fixed_w);


        glm::mat4 rotationMatrix = glm::mat4(1.0f);
        glm::mat4 translateMatrix = glm::mat4(1.0f);

        glm::mat4 projectionMatrix = glm::mat4(1.0f);
        if (useProjectionGLM) {
            projectionMatrix = glm::perspective(45.0f, (float)width/(float)height, 0.001f, 100.0f);
        } else if (useProjectionMyOwn) { 
            projectionMatrix = myOwnProjectionMatrix(0.001, 100.0, 45., (double)width/(double)height);
        }

        rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotateVec[0]), glm::vec3(1.0, 0.0, 0.0));
        rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotateVec[1]), glm::vec3(0.0, 1.0, 0.0));
        rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotateVec[2]), glm::vec3(0.0, 0.0, 1.0));

        translateMatrix = glm::translate(translateMatrix, translateVec);

        glm::mat4 modelMatrix = translateMatrix * rotationMatrix;

        showMatrix(modelMatrix, "Model matrix");
        showMatrix(projectionMatrix, "GLM Projection matrix");

        vertexMatrixCalculation((Vertex*)triangle_vertices, modelMatrix, projectionMatrix, vertex_w);

        // Render
        // Clear the colorbuffer

        ImGui::Render();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        glBindVertexArray(VAO);
        shaderProgram.use();

        shaderProgram.setInt("texture1", 0);
        shaderProgram.setInt("texture2", 1);
        shaderProgram.setFloat("vertex_w", vertex_w);
        shaderProgram.setBool("always_fixed_w", always_fixed_w);

        shaderProgram.setMatrix4d("transform", modelMatrix);
        shaderProgram.setMatrix4d("projection", projectionMatrix);

        

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
