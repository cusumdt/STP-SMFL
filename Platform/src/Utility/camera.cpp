#include "camera.h"
static const short int velocity = 2;
Camera::Camera(){
	_pos.x = 0;
	_pos.y = 0;
	_rotation = 0;
}

Camera::~Camera(){
}

void Camera::setPosX(float posX){
	_pos.x = posX;
}
void Camera::setPosY(float posY){
	_pos.y = posY;
}
void Camera::setPos(sf::Vector2f pos){
	_pos = pos;
}
void Camera::setRotation(float rotation){
	_rotation = rotation;
}
void Camera::movementCamera(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if (Camera::CameraScreenLimiter()) {
			_pos.x += velocity;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		if (_pos.x > 0) {
			_pos.x -= velocity;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

	}
}
void Camera::shakeCamera(){
}