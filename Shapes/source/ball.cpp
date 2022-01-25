#include "ball.h"
#include "main.h"
#include <random>

Ball::Ball(float x, float y, color_t color, int choice) {
    // this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    if (choice == 1) {
    static const GLfloat vertex_buffer_data[] = {
        
        -0.58779f, 0.80902f, 0.5f,
        -0.95106f, 0.30902f, -0.5f, 
        0.0f, 1.0f, -0.5f,

        0.0f, 1.0f, -0.5f,
        -0.58779f, 0.80902f, 0.5f,
        0.58779f, 0.80902f, 0.5f,

        0.58779f, 0.80902f, 0.5f,
        0.0f, 1.0f, -0.5f,
        0.95106f, 0.30902f, -0.5f, 

        0.58779f, 0.80902f, 0.5f,
        0.95106f, -0.30902f, 0.5f, 
        0.95106f, 0.30902f, -0.5f, 

        0.95106f, -0.30902f, 0.5f, 
        0.58779f, -0.80902f, -0.5f,
        0.95106f, 0.30902f, -0.5f, 


        0.58779f, -0.80902f, -0.5f,
        -0.0f, -1.0f, 0.5f,
        0.95106f, -0.30902f, 0.5f,

        0.58779f, -0.80902f, -0.5f,
        -0.0f, -1.0f, 0.5f,
        -0.58779f, -0.80902f, -0.5f,

        -0.58779f, -0.80902f, -0.5f,
        -0.0f, -1.0f, 0.5f,
        -0.95106f, -0.30902f, 0.5f,

        -0.95106f, -0.30902f, 0.5f,
        -0.58779f, -0.80902f, -0.5f,
        -0.95106f, 0.30902f, -0.5f,

        -0.95106f, 0.30902f, -0.5f,
        -0.58779f, 0.80902f, 0.5f,
        -0.95106f, -0.30902f, 0.5f,

        0.58779f, 0.80902f, 0.5f,
        -0.58779f, 0.80902f, 0.5f,
        -0.95106f, -0.30902f, 0.5f,

        0.58779f, 0.80902f, 0.5f,
        -0.0f, -1.0f, 0.5f,
        -0.95106f, -0.30902f, 0.5f,

        0.58779f, 0.80902f, 0.5f,
        -0.0f, -1.0f, 0.5f,
        0.95106f, -0.30902f, 0.5f,

        0.0f, 1.0f, -0.5f,
        0.95106f, 0.30902f, -0.5f,
        0.58779f, -0.80902f, -0.5f,

        0.0f, 1.0f, -0.5f,
        -0.58779f, -0.80902f, -0.5f,
        0.58779f, -0.80902f, -0.5f,

        -0.95106f, 0.30902f, -0.5f,
        -0.58779f, -0.80902f, -0.5f,
        0.0f, 1.0f, -0.5f,     

    };
    GLfloat color_buffer[16 * 3 * 3];
    for (int i =0; i<16*3*3; i++){
        color_buffer[i] = ((double) rand()) / RAND_MAX;
    }
    this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_buffer_data, color_buffer, GL_FILL);
    }


else if (choice == 2) {
    static const GLfloat vertex_buffer_data[] = {
        
        0.0f, 0.0f, 1.621f,
        1.02f, 1.02f, 0.601f,
        1.02f, -1.02f, 0.601f,

        1.02f, -1.02f, 0.601f,
        0.0f, 0.0f, 1.621f,
        -1.02f, -1.02f, 0.601f,

        0.0f, 0.0f, 1.621f,
        -1.02f, -1.02f, 0.601f,
        -1.02f, 1.02f, 0.601f,

        -1.02f, 1.02f, 0.601f,
        1.02f, 1.02f, 0.601f,
        0.0f, 0.0f, 1.621f,

        0.0f, 0.0f, -1.541f,
        -1.02f, -1.02f, -0.521f,
        -1.02f, 1.02f, -0.521f,

        0.0f, 0.0f, -1.541f,
        -1.02f, 1.02f, -0.521f,
        1.02f, 1.02f, -0.521f,

        0.0f, 0.0f, -1.541f,
        1.02f, 1.02f, -0.521f,
        1.02f, -1.02f, -0.521f,

        0.0f, 0.0f, -1.541f,
        1.02f, -1.02f, -0.521f,
        -1.02f, -1.02f, -0.521f,

        -1.02f, -1.02f, -0.521f,
        -1.02f, -1.02f, 0.601f,
        -1.02f, 1.02f, -0.521f,

        -1.02f, 1.02f, -0.521f,
        -1.02f, -1.02f, 0.601f,
        -1.02f, 1.02f, 0.601f,

        -1.02f, -1.02f, -0.521f,
        -1.02f, -1.02f, 0.601f,
        1.02f, -1.02f, 0.601f,

        1.02f, -1.02f, 0.601f,
        -1.02f, -1.02f, -0.521f,
        1.02f, -1.02f, -0.521f,

        1.02f, -1.02f, -0.521f,
        1.02f, -1.02f, 0.601f,
        1.02f, 1.02f, -0.521f,
        
        1.02f, -1.02f, 0.601f,
        1.02f, 1.02f, -0.521f,
        1.02f, 1.02f, 0.601f,

        1.02f, 1.02f, -0.521f,
        -1.02f, 1.02f, -0.521f,
        1.02f, 1.02f, 0.601f,

        -1.02f, 1.02f, -0.521f,
        1.02f, 1.02f, 0.601f,
        -1.02f, 1.02f, 0.601f,

    };
    GLfloat color_buffer[12 * 3 * 3];
    for (int i =0; i<12*3*3; i++){
        color_buffer[i] = ((double) rand()) / RAND_MAX;
    }
    this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_buffer_data, color_buffer, GL_FILL);
    }



    this->x = x, this->y = y, this->z = z;
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (glm::vec3(this->x, this->y, this->z));    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}



