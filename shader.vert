#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 inColour;

uniform mat4 gWVP;

out vec4 Color;

void main()
{
	gl_Position = gWVP * vec4(Position, 1.0);
	Color = vec4(inColour, 1.0);
}