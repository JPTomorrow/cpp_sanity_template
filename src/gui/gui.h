/*
 * Platform layer for GUI
 * Currently backed by Dear-IMGUI docking branch
 * Uses GLFW and OpenGL renderer backend (trying to
 * make it as cross-platform as possible)
 *
 * @AUTHOR: Justin Morrow
 */
#ifndef GUI_H
#define GUI_H

#include <GLFW/glfw3.h>
#include <vector>
#include <functional>
#include <string>

typedef std::function<void()> WindowDefinition;

typedef struct {
    std::string name;
    WindowDefinition definition;
}GuiWindow;

class GUI {
public:
    GUI();
    virtual ~GUI();
    void start() const;
    void add_window_definition(const std::string &name, const WindowDefinition &def);
private:
    GLFWwindow* m_Window;
    std::vector<GuiWindow> m_WindowsToRender;
    static void apply_style();
};


#endif //GUI_H
