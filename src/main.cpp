#include <iostream>

#include "gui/gui.h"
#include <imgui.h>

int main()
{
    std::cout << "Hello World!\n";
    GUI gui = GUI{};
    gui.add_window_definition(
        "Hello World!",
        [] {
            static float f = 0.0f;
            static int counter = 0;
            static ImVec4 test_color = {};
            static bool test_bool = true;

            ImGui::Begin("Hello, world!");
            ImGui::Text("This is some useful text.");
            ImGui::Checkbox("Demo Window", &test_bool);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::ColorEdit3("clear color", (float*)&test_color);

            if (ImGui::Button("Button"))
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::End();
        }
    );
    gui.start(); // this is a blocking function
    return 0;
}