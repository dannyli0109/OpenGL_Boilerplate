//These includes are specific to the way we’ve set up GLFW and GLAD.
#include "Graphics.h"
#include "GUI.h"

int main(void)
{
    GLFWwindow* window;

    //Initialise GLFW, make sure it works. Put an error message here if you like.
    if (!glfwInit())
        return -1;

    //Set resolution here, and give your window a different title.
    window = glfwCreateWindow(1280, 720, "OpenGL Boilerplate", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate(); //Again, you can put a real error message here.
        return -1;
    }

    //This tells GLFW that the window we created is the one we should render to.
    glfwMakeContextCurrent(window);


    //Tell GLAD to load all its OpenGL functions.
    if (!gladLoadGL())
        return -1;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();



    //The main ‘game’ loop.
    while (!glfwWindowShouldClose(window))
    {
        //Clear the screen – eventually do rendering code here.
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        // Make window dockable
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

        // begin imgui window
        ImGui::Begin("Imgui window");
        // draw ui element in between
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        ImGui::EndFrame();

        //Swapping the buffers – this means this frame is over.
        glfwSwapBuffers(window);

        //Tell GLFW to check if anything is going on with input, etc.
        glfwPollEvents();
    }

    //If we get to this point, the window has closed, so clean up GLFW and exit.
    glfwTerminate();
    // Cleanup GUI related
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    return 0;
}
