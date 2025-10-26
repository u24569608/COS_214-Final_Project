#include "../include/GreenhouseComponent.h"

#include <stdexcept>
#include "../include/GreenhouseIterator.h"
#include <utility>

GreenhouseComponent::GreenhouseComponent(std::string name) : name(std::move(name)) {
	// Initialises name in the member initialisation list
}//Constructor

GreenhouseComponent::~GreenhouseComponent() {
	// Has no attributes to clean up
}//Destructor

std::string GreenhouseComponent::getName() const {
	return name;
}//getName

std::unique_ptr<GreenhouseIterator> GreenhouseComponent::createIterator() {
	// Leaf components do not expose iteration by default.
	return nullptr;
}//createIterator

void GreenhouseComponent::add(GreenhouseComponent* /*component*/) {
	throw std::logic_error("Component does not support adding children");
}//add

void GreenhouseComponent::remove(GreenhouseComponent* /*component*/) {
	throw std::logic_error("Component does not support removing children");
}//remove
