//
// Created by alki on 21/03/2021.
//

#include <SFML/Graphics.hpp>
#include "component/Position.h"
#include "component/Velocity.h"
#include "component/Color.h"
#include "entity/EntityManager.h"
#include "entity/Entity.h"
#include <memory>
#include <cmath>



int main() {
    sf::RenderWindow    window(sf::VideoMode(1280, 1280), "SFML works!");
    sf::CircleShape     shape(1.f);
    sf::Clock           delta;
    Core::EntityManager entityManager;

    window.setFramerateLimit(60);

    shape.setFillColor(sf::Color::Green);

    srand(time(NULL));

	float phi = M_PI * (3.0 - sqrt(5.0));
	int samples = 8000;

	for (int i = 0; i < samples; ++i) {
        float vel_x = ((float) rand() / RAND_MAX) - 0.5;
        float vel_y = ((float) rand() / RAND_MAX) - 0.5;
        auto  &e    = entityManager.Create();

		float y = 1 - ((float)i / (float)(samples - 1)) * 2;
		float radius = sqrt(1 - y * y);
		float theta = phi * (float)i;
		float x = cos(theta) * radius;
		float z = sin(theta) * radius;

        e.AddComponent(std::make_unique<Core::Component::Position>(sf::Vector2<float>(x, y)));
        e.AddComponent(std::make_unique<Core::Component::Velocity>(sf::Vector2<float>(vel_x, vel_y)));
        e.AddComponent(std::make_unique<Core::Component::Color>(
                sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255)));
    }
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if (delta.getElapsedTime() > sf::milliseconds(5)) {
            for (auto &entity: entityManager.GetEntities()) {
                try {
                    auto &position = entity->GetComponent<Core::Component::Position>().Get();
                    auto &velocity = entity->GetComponent<Core::Component::Velocity>().Get();

                    position.x += (velocity.x / 10) * delta.getElapsedTime().asMilliseconds();
                    position.y += (velocity.y / 10) * delta.getElapsedTime().asMilliseconds();

                    if (position.x >= 1280 || position.x <= 0)
                        velocity.x *= -1;
                    if (position.y >= 1280 || position.y <= 0)
                        velocity.y *= -1;
                } catch (std::exception &exception) {
                    continue;
                }
            }
            delta.restart();
        }

        // It's a """system"""
        for (auto &entity: entityManager.GetEntities()) {
            try {
                auto &position = entity->GetComponent<Core::Component::Position>().Get();
                auto &color    = entity->GetComponent<Core::Component::Color>().Get();
                shape.setPosition(position);
                shape.setFillColor(color);

                window.draw(shape);
            } catch (std::exception &exception) {
                continue;
            }
        }
        window.display();
    }
}