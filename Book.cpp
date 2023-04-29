#include "Book.h"

Shirts::Shirts()
{
}

//getters
string Shirts::getShirtID() { return ShirtID; };
string Shirts::getBrand() { return Brand; };
string Shirts::getStyle() { return Style; };
string Shirts::getSize() { return Color; };
string Shirts::getColor() { return Size; };
string Shirts::getFabric() { return Fabric; };
string Shirts::getQuantity() { return Quantity; };

// setters
void Shirts::setQuantity(string Quantity) { this->Quantity = Quantity; };

