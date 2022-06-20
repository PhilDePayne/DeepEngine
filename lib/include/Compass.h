#pragma once

#include "hudRect.h"

class Compass {
public:

    glm::mat4 model = glm::mat4(1.0f);

    Compass(int display_w, int display_h, Shader shader) {
        init(display_w, display_h, shader);
    }

    void init(int display_w, int display_h, Shader shader) {

        compass = new hudRect(300.0f, 300.0f, -300.0f/2.0f, -300.0f/2.0f,
                              "./res/hud/compass1.png", shader);
        arrow = new hudRect(65.0f, 39.0f, -65.0f/2.0f, -compass->h/2.0f,
                            "./res/hud/arrow.png", shader);

        compass->model = glm::translate(compass->model, glm::vec3(-display_w/2.0f + 300.0f/2.0f + 50.0f,
                                                                  -display_h/2.0f + 300.0f/2.0f + 50.0f, 0.0f));
        arrow->model = glm::translate(arrow->model, glm::vec3(-display_w/2.0f + 300.0f/2.0f + 50.0f,
                                                              -display_h/2.0f + 300.0f/2.0f + 50.0f + 213.0f, 0.0f));

        oldModel = compass->model;
        oldModelArrow = arrow->model;
        compass->model = glm::rotate(oldModel, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    }

    void Draw(Shader shader, float angle) {

        compass->model = glm::rotate(oldModel, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));

        compass->Draw(shader);
        arrow->Draw(shader);

    }


private:

    hudRect* compass;
    hudRect* arrow;

    glm::mat4 oldModel;
    glm::mat4 oldModelArrow;

};
