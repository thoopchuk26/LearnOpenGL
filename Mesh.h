#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include "Shader.h"

struct Vertex {
	glm::vec3 Position;
	glm::vec2 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int ID;
	std::string type;
    std::string path;
};

class Mesh {
public:
    // mesh data
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    std::vector<Texture> Textures;

    unsigned int VAO, VBO, EBO;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    void Draw(Shader& shader);
private:
    //  render data
    

    void setupMesh();
};