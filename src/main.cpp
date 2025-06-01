#include <iostream>
#include "gui/gui.h"
#include <imgui.h>
#include "spdlog/spdlog.h"
#include <utils/print.h>

#define APP_NAME "Cpp Sanity Template"


int main()
{
    std::cout << "Welcome to: " << APP_NAME << "\n";
    UTILS::print_os();
    GUI gui = GUI{};

    gui.add_window_definition(
        "Hello World!",
        [] {
            static float f = 0.0f;
            static int counter = 0;
            static ImVec4 test_color = {};
            static bool test_bool = true;


            ImGui::Text("This is some useful text.");
            ImGui::Checkbox("Demo Window", &test_bool);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::ColorEdit3("clear color", (float*)&test_color);

            if (ImGui::Button("Button"))
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);
        }
    );
    gui.add_window_definition(
        "Hello World2!",
        [] {
            static float f = 0.0f;
            static int counter = 0;
            static ImVec4 test_color = {};
            static bool test_bool = true;

            ImGui::Text("This is some useful text.");
            ImGui::Checkbox("Demo Window", &test_bool);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::ColorEdit3("clear color", (float*)&test_color);

            if (ImGui::Button("Button"))
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);
        }
    );
    gui.start(); // this is a blocking call
    return 0;
}
