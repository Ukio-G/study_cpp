#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <GL/glew.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include "Shader.h"

static bool executing = true;

int main() {
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(false);
    ImGui::SFML::Init(window);
    // activate the window
    window.setActive(true);
    sf::Clock deltaClock;

    glewInit();

    // Shaders available
    // ShaderProgram shader(new Shader("vs.glsl", GL_VERTEX_SHADER), new Shader("fs.glsl", GL_FRAGMENT_SHADER));

    while (executing) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                executing = false;
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        window.clear();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::SFML::Render(window);

        /* Draw using OpenGL or SFML start here */

        window.display();
    }
    window.close();
    ImGui::SFML::Shutdown();
    return 0;
}
