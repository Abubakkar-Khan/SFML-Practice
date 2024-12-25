#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2i target, float speed)
    : speed(speed)
{
    shape.setSize(sf::Vector2f(2.0f, 2.0f)); // Set bullet size
    shape.setFillColor(sf::Color::Cyan); // Bullet color

    shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);  // Center the origin of the bullet
    shape.setPosition(position); // Start position

    // Calculate direction vector from the bullet's position to the target (mouse position)
    sf::Vector2f direction(target.x - position.x, target.y - position.y);

    // Normalize the direction vector (so it's a unit vector)
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0) {
        direction /= magnitude; // Normalize direction
    }

    // Calculate the angle in radians and convert it to degrees
    float angle = std::atan2(direction.y, direction.x) * 180.0f / 3.14159f;  // atan2 returns the angle in radians

    shape.setRotation(angle + 90); // Set the bullet's rotation based on the angle

    velocity = direction * speed; // Set velocity based on the normalized direction and speed
}

void Bullet::update(float deltaTime)
{
    // Move the bullet based on its velocity
    shape.move(velocity * deltaTime);
    age += deltaTime;
}

void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(shape);  // Draw the bullet on the window
}

bool Bullet::isDead() const
{
    return age >= lifetime;  // Check if the bullet's lifetime has passed
}
