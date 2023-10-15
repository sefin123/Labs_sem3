#include "Monoblock.h"

Monoblock::Monoblock() {
	this->screenDiagonal = 0;
}

Monoblock::~Monoblock() {}

Monoblock::Monoblock(double screenDiagonalValue) {
	this->screenDiagonal = screenDiagonalValue;
}