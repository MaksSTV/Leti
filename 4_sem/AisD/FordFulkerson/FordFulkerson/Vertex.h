#ifndef VERTEX_H
#pragma once

#include <iostream>
#include <string>

struct Vertex {
	std::string input = "\0";
	std::string output = "\0";
	int capacity = 0;
	int in = -1;
	int out = -1;
};

#endif // !VERTEX_H